/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <SupPanneau.h>
#include <Interface.h>
//#include <GrpSliders.h>



namespace gui {

/////////////////////////////////////////////////
SupPanneau::SupPanneau ()
: m_cote        ( Cote::Gauche )
, m_btn_gauche  ( std::make_shared<BtnRectangle>() )
, m_btn_droite  ( std::make_shared<BtnRectangle>() )
, m_groupe      ( std::make_shared<GrpSliders>() )
, m_largeurBtnTaille ( 5 )
{
    m_marge = { m_largeurBtnTaille , m_largeurBtnTaille };

    ajouterComposant ( m_btn_gauche );
    ajouterComposant ( m_btn_droite );
    ajouterComposant ( m_groupe );

    m_groupe->setRepartition ( Repartitions::Verticale );


    auto fct_redimStartG = [this](){
//            demander_aEtre_auDessus();
            m_sourisPosOrigin = getPosSouris();
            m_tailleOrigin = m_taille;
            m_posOrigin = getPosition();
            m_redimGauche = true;
            m_interface->demanderActualisation();
        };
    auto fct_redimStopG = [this](){
            m_redimGauche = false;
            actualiserBounds();
            m_interface->demanderActualisation();
        };
    auto fct_redimStartD = [this](){
//            demander_aEtre_auDessus();
            m_sourisPosOrigin = getPosSouris();
            m_tailleOrigin = m_taille;
            m_posOrigin = getPosition();
            m_redimDroite = true;
            m_interface->demanderActualisation();
        };
    auto fct_redimStopD = [this](){
            m_redimDroite = false;
            actualiserBounds();
            m_interface->demanderActualisation();
        };

    m_btn_gauche->lier (Evenement::onBtnG_presser , fct_redimStartG );
    m_btn_gauche->lier (Evenement::onBtnG_relacher, fct_redimStopG );
    m_btn_gauche->lier (Evenement::onBtnG_relacherDehors, fct_redimStopG );

    m_btn_droite->lier (Evenement::onBtnG_presser , fct_redimStartD );
    m_btn_droite->lier (Evenement::onBtnG_relacher, fct_redimStopD);
    m_btn_droite->lier (Evenement::onBtnG_relacherDehors, fct_redimStopD);

    m_btn_gauche->setPosition ( 0,0 );
}


/////////////////////////////////////////////////
void    SupPanneau::setCote ( Cote cote ) {
    m_cote = cote;
    switch ( m_cote ){
        case Cote::Droite:
            m_interface->ms_calque_panneau_D->ajouter ( thisPtr());
            break;
        case Cote::Gauche:
            m_interface->ms_calque_panneau_G->ajouter ( thisPtr());
            break;
    }
    m_interface->demanderActualisation();
};


/////////////////////////////////////////////////
void SupPanneau::corrigerTailleMinimum ()
{
    if ( m_taille.x < 150 +  m_marge.x*2 )
    {
        switch ( m_cote ) {
            case Cote::Droite:
                m_taille.x = 150 + m_marge.x*2;
                setPosition ( m_interface->getFenetre()->getSize().x - m_taille.x,  getPosition().y );
                break;
            case Cote::Gauche:
                m_taille.x = 150 + m_marge.x*2;
                break;
        }

    }

}

/////////////////////////////////////////////////
void    SupPanneau::ajouter ( std::shared_ptr<Gadget> gadget, sf::Vector2i positionEcran )
{
    std::cout << "Ajouter avec position ...\n";

   int i = 0;
    for ( auto enfant : m_groupe->getEnfants() )
    {
//        std::cout << "  ... on test ...\n";
        if ( gadget->getPosAbs().y  < enfant->getPosAbs().y  )
        {
            m_groupe->ajouter ( gadget , i );
//    m_interface->demanderActualisation();
//            m_groupe->actualiserContenu (  );

            std::cout << "  ... reussi.\n";
            return;
        }
        i++;
    }
    std::cout << "  ... rate, on le met a la fin.\n";
    m_groupe->ajouter ( gadget );

//    m_interface->demanderActualisation();

//    Composite::ajouter( gadget );
};


/////////////////////////////////////////////////
sf::Vector2i     SupPanneau::getTaille () const {
    if ( m_groupe->getEnfants().size() == 0)
        return { 10, m_taille.y};
    else return m_taille;
}

/////////////////////////////////////////////////
void    SupPanneau::actualiserGeometrie ()
{
//    std::cout << "Actualiser PANNEAU\n";

    auto tailleTmp = m_taille;

    if ( m_groupe->getEnfants().size() == 0)    {
        tailleTmp.x = 10;
        switch ( m_cote ) {
            case Cote::Droite:
                m_btn_gauche->setVisible ( false );
                break;
            case Cote::Gauche:
                m_btn_droite->setVisible ( false );
                break;
        }
        if ( m_interface !=nullptr)
            m_interface->demanderActualisation();
    }
   else switch ( m_cote ) {
        case Cote::Droite:
            m_btn_gauche->setVisible ( true );
            m_btn_droite->setVisible ( false );
            break;
        case Cote::Gauche:
            m_btn_gauche->setVisible ( false );
            m_btn_droite->setVisible ( true );
            break;
    }

    m_fond->setTaille ( tailleTmp );

    m_btn_droite->setPosition ( tailleTmp.x - m_btn_droite->getTaille().x, 0 );
    m_btn_gauche->setTaille ( m_largeurBtnTaille , tailleTmp.y );
    m_btn_droite->setTaille ( m_largeurBtnTaille , tailleTmp.y );

    m_groupe->setTaille ( { tailleTmp.x - 2*m_marge.x , tailleTmp.y - 2*m_marge.y });
    m_groupe->setPosition ( m_marge.x , m_marge.y );

//    actualiserBounds();
//    actualiserEnfants();
//    if (m_interface != nullptr)
//    {
//        auto tailleFenetre = m_interface->getFenetre()->getSize();
//        m_taille = {tailleFenetre.x , m_taille.y};
//    }
//    m_fond->setTaille ( m_taille );
}


/*
/////////////////////////////////////////////////
void SupPanneau::actualiserEnfants()
{
    sf::Vector2i pos;
    switch ( m_cote ) {
        case Cote::Droite:
            pos = { m_largeurBtnTaille  ,  m_marge.y };
            break;
        case Cote::Gauche:
            pos = { m_marge.x ,  m_marge.y };
            break;
    }
    for ( auto enfant : m_groupe->getEnfants() )
    {

//        if ( enfant->getPosition ().x !=  pos.x && enfant->getPosition().y !=  pos.y )
        enfant->setPosition( pos.x , pos.y );
        if ( enfant->getTaille().x != m_taille.x - m_largeurBtnTaille - 4*m_marge.x )
            enfant->setTailleX( m_taille.x - m_largeurBtnTaille - 4*m_marge.x );

        pos.y += enfant->getTaille().y;
    }
}*/



/////////////////////////////////////////////////
void SupPanneau::traiterEvenements (const sf::Event& evenement)
{


    if ( m_redimGauche ){ redimmensionner_gauche (); return; }
    if ( m_redimDroite ){ redimmensionner_droite (); return; }

    Support::traiterEvenements (evenement);

//     if ( redimEnCours () )
//        positionnerFenetre ();

}
/////////////////////////////////////////////////
void SupPanneau::redimmensionner_gauche ()
{
    auto posSouris = getPosSouris();
    m_taille = { m_tailleOrigin.x - ( posSouris.x - m_sourisPosOrigin.x  ) , m_taille.y };

//    demander_aEtre_auDessus();
    setPosition ( m_posOrigin.x + ( posSouris.x - m_sourisPosOrigin.x  ),  getPosition().y );
    corrigerTailleMinimum ();

    actualiserGeometrie();

//    actualiserEnfants();
//    m_interface->demanderActualisation();
}

/////////////////////////////////////////////////
void SupPanneau::redimmensionner_droite ()
{
    auto posSouris = getPosSouris();
    m_taille = { m_tailleOrigin.x + ( posSouris.x - m_sourisPosOrigin.x  ) , m_taille.y };
    corrigerTailleMinimum ();
//    demander_aEtre_auDessus();
    actualiserGeometrie();
//    actualiserEnfants();
//    m_interface->demanderActualisation();
}

/*

/////////////////////////////////////////////////
std::shared_ptr<Gadget>   SupPanneau::testerSurvol ( sf::Vector2i position )
{
    if (! estVisible() )
        return nullptr;

  ///<\todo... a voir si on peut se passer de faire l'actualisation a chaque fois ...(pour l'instant sans ca, ca pose problème a bouton dans fenentre)
    actualiserBounds();

    // Si on survol le gadget
    if ( m_globalBounds.contains( position.x, position.y ) && estActif() )
    {
//        std::cout << "TESTER SURVOL\n";
        // On test le survol des composants
        auto testInterfaceLocal = testerSurvolComposants( position );
        if ( testInterfaceLocal != nullptr )
            return testInterfaceLocal;
        // On test le survol des enfants
        else
        {
            auto testEnfants = testerSurvolEnfants( position );
            if ( testEnfants != nullptr )
                return testEnfants;
            else  return thisPtr();
        }
    }
    else
        return nullptr;

}
*/

/*
/////////////////////////////////////////////////
void SupPanneau::draw (sf::RenderTarget& target, sf::RenderStates states) const
{
    if (! estVisible() )
        return;


    //On applique la transformation
    states.transform *= getTransform();

    // on dessine les composants
    dessinerComposant ( target, states);

    // On dessine les enfants (du groupe)
    for ( auto enfant : m_groupe->getEnfants() )
        target.draw ( *enfant , states ) ;

}
*/

} // fin namespace gui



















