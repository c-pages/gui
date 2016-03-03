/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <FenSimple.h>



namespace gui {

/////////////////////////////////////////////////
FenSimple::FenSimple ()
: Fenetre       ( )
, m_titre       ( std::make_shared<AffBarreTitre>() )
, m_btnFermer   ( std::make_shared<BtnIcone>() )
, m_btndrag     ( std::make_shared<BtnRectangle>() )
, m_fermable    ( true )
, m_draggable   ( true )
, m_decalageDragSouris ( { 0, 0 } )
{
    m_taille = { 300,200 };
    m_marge =  { 3 , 3 };

    ajouterComposant( m_btnFermer );
    ajouterComposant( m_titre );
    ajouterComposant( m_btndrag );

    // icone titre par defaut
    chargerIcone   ( "media/img/Icone_test x16.png" );

    // icone fermer par defaut
    m_btnFermer->chargerDepuisFichier   ( "media/img/ico_fenetreFermer.png" );
    m_btnFermer->setFix                 ( true );
    m_btnFermer->setVisible             ( m_fermable );

    m_btndrag->setVisible             ( m_draggable );

    // Action du bouton slider
    m_btndrag->lier ( Evenement::onBtnG_presser , [this](){

        demander_aEtre_auDessus();

        m_decalageDragSouris = sf::Vector2i ( getPosSouris().x - getPosition().x , getPosSouris().y - getPosition().y );
        setDrag( true );
        positionnerFenetre ();
//        m_necessiteActualisation = true ;
        actualiser ();
    });
    m_btndrag->lier ( Evenement::onBtnG_relacher , [this](){
        //demander_aEtre_auDessus();
        setDrag( false );
//        m_necessiteActualisation = false ;
        actualiser ();
    });
    m_btndrag->lier ( Evenement::onBtnG_relacherDehors , [this](){
        //demander_aEtre_auDessus();
        setDrag( false );
//        m_necessiteActualisation = false ;
        actualiser ();
    });


    // Action du bouton fermer
    m_btnFermer->lier ( Evenement::onBtnG_relacher , [this](){
        demander_aEtre_supprimer ();
    });


    // Action du gadget
    this->lier ( Evenement::onBtnG_presser , [this](){
        std::cout << "Fenetre presse\n";
        demander_aEtre_auDessus ();
    });

}

/////////////////////////////////////////////////
void FenSimple::traiterEvenements (const sf::Event& evenement)
{
//std::cout << "FenSimple::traiterEvenements\n";
//   std::cout << " evt\n";
     if ( dragEnCours() )
        positionnerFenetre ();

    for ( auto enfant : m_enfants )
        enfant->traiterEvenements ( evenement);

    for ( auto composant : m_composants )
        composant->traiterEvenements ( evenement);
}
/*
void FenSimple::draw (sf::RenderTarget& target, sf::RenderStates states) const
{
    if ( dragEnCours() )
        positionnerFenetre ();
}
*/
/*
/////////////////////////////////////////////////
void FenSimple::actualiser ( sf::Time delta )
{
//   std::cout << " actualiser Delta\n";
//    if ( dragEnCours() )
//        positionnerFenetre ();
}
*/



/////////////////////////////////////////////////
void FenSimple::actualiser ()
{
    if ( ! m_necessiteActualisation )
        return;


//std::cout << "FenSimple::actualiser\n";
    m_titre->setTailleX     ( m_taille.x - 2*m_marge.x );
    m_titre->setPosition    ( m_marge.x , m_marge.y );

    m_btnFermer->setTaille  ( { m_titre->getTaille().y , m_titre->getTaille().y } );
    m_btnFermer->setPosition( m_taille.x - m_btnFermer->getTaille().y - m_marge.x , m_marge.y );

    m_btndrag->setTaille    ( { m_titre->getTaille().x - m_btnFermer->getTaille().y  , m_titre->getTaille().y } );
    m_btndrag->setPosition  ( m_marge.x , m_marge.y );

    m_panneau->setTaille    ( { m_taille.x - 2*m_marge.x, m_taille.y - m_titre->getTaille().y - 2*m_marge.y } );
    m_panneau->setPosition  ( m_marge.x , m_titre->getTaille().y + m_marge.y );

    m_fond->setTaille       ( m_taille );
    m_fond->setPosition     ( 0 , 0 );

    m_ombre->setTaille       ( m_taille );




    m_btndrag->setStyle     ( m_skin->getStyle(Styles::invisible));
    m_fond->setStyle        ( m_skin->getStyle(Styles::fenetre));
    m_btnFermer->setStyle   ( m_skin->getStyle(Styles::bouton));
    m_titre->setStyle       ( m_skin->getStyle(Styles::txtTitre));

    m_necessiteActualisation = false;
/*
    m_titre->setTailleX     ( m_taille.x  );
    m_btndrag->setTaille    ( { m_titre->getTaille().x - m_titre->getTaille().y  , m_titre->getTaille().y } );
    m_panneau->setTaille    ( { m_taille.x , m_taille.y - m_titre->getTaille().y } );
    m_panneau->setPosition  ( 0 , m_titre->getTaille().y );
    m_fond->setTaille       ( { m_taille.x + 2*m_marge.x , m_taille.y + 2*m_marge.y } );
    m_fond->setPosition     ( - m_marge.x , - m_marge.y );

    m_btnFermer->setTaille  ( { m_titre->getTaille().y , m_titre->getTaille().y } );
    m_btnFermer->setPosition( m_taille.x - m_titre->getTaille().y  , 0 );

    m_btndrag->setStyle     ( m_skin->getStyle(Styles::invisible));
    m_fond->setStyle        ( m_skin->getStyle(Styles::fenetre));
    m_btnFermer->setStyle   ( m_skin->getStyle(Styles::bouton));
    m_titre->setStyle       ( m_skin->getStyle(Styles::txtTitre));
*/
}

std::shared_ptr<Gadget>  FenSimple::testerSurvol ( sf::Vector2i position )
{
    // si on est dans le panneau
    if ( m_globalBounds.contains( position.x, position.y ) && estActif() )
    {
        // si on survol un gadget composant (slider)
        auto testInterfaceLocal = testerSurvolComposants( position );
        if ( testInterfaceLocal == m_panneau )
            return thisPtr();
        else if ( testInterfaceLocal != nullptr )
            // on le renvois
            return testInterfaceLocal;
        else return thisPtr();
//        else {
//            // sinon on regarde si on survol un enfant
//            auto testEnfants = testerSurvolComposite( { position.x + m_posX_texture, position.y + m_posY_texture } );
//            if ( testEnfants != nullptr )
//                return testEnfants;
//           else return thisPtr();
////             else return nullptr;
//        }
    }
    else return nullptr;
}



/////////////////////////////////////////////////
void FenSimple::chargerIcone   (std::string fichier )
{
    m_titre->setIconeImage( fichier );
}




/////////////////////////////////////////////////
void FenSimple::positionnerFenetre ()
{

    setPosition ( getPosSouris().x - m_decalageDragSouris.x  , getPosSouris().y - m_decalageDragSouris.y );

//    actualiser ();
}




} // fin namespace gui

