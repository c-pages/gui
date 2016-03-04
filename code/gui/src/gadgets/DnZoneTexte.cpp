/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <DnZoneTexte.h>



namespace gui {

/////////////////////////////////////////////////
DnZoneTexte::DnZoneTexte ()
: m_bouton  ( std::make_shared<BtnRectangle>() )
, m_curseur ( std::make_shared<AffRectangle>() )
, m_label   ( std::make_shared<AffLabel>() )
, m_ecritureActive ( false )
{
    // initialiser
    m_taille.x = 180;
    m_taille.y = 20;

    m_marge.x = 5;
    m_marge.y = 5;

    m_label->setTexte   ( m_texte );
    m_curseur->setTaille( { 2, 15 });
    m_bouton->setTaille ( m_taille );



    fn_valider = [this](){
        if ( m_ecritureActive ){
            setModeEcritureActif ( false );
            m_texte = m_valeur = m_label->getSFTexte()->getString() ;
            actualiser ();
        }
    };

    fn_sortir = [this](){
        if ( m_ecritureActive ){
            setModeEcritureActif ( false );
            m_label->setTexte ( m_texte );
            actualiser ();
        }
    };

    // Action du bouton
    m_bouton->lier ( Evenement::onBtnG_relacher , [this](){

        std::cout << "Clique zone de texte\n";

        if ( m_ecritureActive ){}

            // on place le curseur là où on a cliqué.(todo)


        else {

            // on active la saisie clavier
            setModeEcritureActif ( true ) ;

//    m_bouton->lier ( Evenement::onBtnG_relacherDehors , fn_valider );
//    m_bouton->lier ( Evenement::onBtnD_relacherDehors , fn_sortir );

            actualiser ();
        }

    });



    m_bouton->lier ( Evenement::onBtnG_relacherDehors , fn_valider );
    m_bouton->lier ( Evenement::onBtnD_relacherDehors , fn_sortir );

    actualiser ();

}

/////////////////////////////////////////////////
std::shared_ptr<Gadget>  DnZoneTexte::testerSurvol ( sf::Vector2i position )
{
    if ( m_globalBounds.contains( { position.x , position.y } ) )
        return m_bouton;

    return nullptr;
}

/////////////////////////////////////////////////
void DnZoneTexte::actualiserGeometrie ()
{
    m_label->setPosition    ( m_marge.x , m_marge.y/2);

//    sf::Vector2f pos = m_label->getSFTexte()->findCharacterPos 	(  m_label->getTexte().size() ) ;
    sf::Vector2f pos = m_label->getSFTexte()->findCharacterPos 	(  m_label->getSFTexte()->getString().getSize() ) ;

    m_curseur->setPosition ( pos.x , pos.y );
    m_curseur->move( 5 , m_marge.y/2 );

    // actualiser
    if ( m_parent != nullptr ) m_parent->actualiserContenu();
}


/////////////////////////////////////////////////
void DnZoneTexte::actualiserStyle ()
{
    // le bouton
//    m_bouton->setSkin       ( m_skin );

//    if ( !m_ecritureActive ) {
//        m_bouton->setStyle      ( m_skin->getStyle( Styles::bouton ) );
//    } else {
//        m_bouton->setStyle      ( m_skin->getStyle( Styles::zoneTexte ) );
//    }
//
//    // le label
//    m_label->setStyle       ( m_skin->getStyle( Styles::zoneTexte ) );
//    m_label->setSkin        ( m_skin );
//
//    // le curseur
//    // m_curseur->setPosition  ( , m_marge.y/2);
//    m_curseur->setSkin      ( m_skin );
//    m_curseur->setStyle     ( m_skin->getStyle ( Styles::bouton ) );
//    m_curseur->setFillColor ( sf::Color::White );
//    m_curseur->setOutlineThickness ( 0 );


    if ( m_parent != nullptr ) m_parent->actualiserContenu();
}



/////////////////////////////////////////////////
void DnZoneTexte::traiterEvenements(const sf::Event& evenement ){

    // gestion de la saisie de texte
    if ( m_ecritureActive
    and  evenement.type == sf::Event::TextEntered
        /* and  event.text.unicode < 128*/ ) {



        // le texte avant modif dans le label
        std::string txt = m_label->getTexte() ;

        // touche Retour arriere : effacer arriere  //////////////////////////////
        if ( evenement.text.unicode == 8 )  {
            // si le champ est vide on retourne.
            if ( txt.size()==0 ) return;

            // sinon on retire une lettre et on declenche l'action
            txt.erase ( txt.size()-1 , 1);
            m_label->setTexte( txt  );
           // declencher( onCha_ChangeValeur );
        }

        // touche Entrée : Valider  //////////////////////////////
        else if ( evenement.text.unicode == 13 )  {
          //  declencher( onCha_ValideValeur );
//            m_btn->setCoche( false);
            setModeEcritureActif ( false ) ;
            m_texte = txt;
            m_label->setTexte       ( m_texte ) ;
        }

        // touche Echappe : Annuler  //////////////////////////////
        else if ( evenement.text.unicode == 27 )  {
//            m_label->setTexte( m_texteBack  );
//            m_btn->setCoche( false);
            setModeEcritureActif ( false ) ;
            m_label->setTexte    ( m_texte ) ;
        }

        // les autres touches  //////////////////////////////
        else {

            std::cout << " (event.text.unicode)  : " << (evenement.text.unicode)  << "\n";

            m_label->setTexte( txt + static_cast<char>(evenement.text.unicode)  );
            // s'il ne reste plus de place pour ecrire on retourne
//            float largeurTexte = m_label->getSFTexte()->findCharacterPos 	(  m_label->getTexte().size() ).x;
//            if ( largeurTexte > m_btn->getSize().x - 1 )
//                m_label->setTexte( txt );


            // on déclenche et on ecrit.
//            declencher( onCha_ChangeValeur );
        }
actualiser ();
/*
        // clock pour clignotements du curseur
        m_timerClignot.restart();
        m_clignot = true;

        // et on demande une mise a jour du gadget.
        demanderActualisation();*/
    }


}






/////////////////////////////////////////////////
void DnZoneTexte::draw (sf::RenderTarget& target, sf::RenderStates states) const
{
    //On applique la transformation
    states.transform *= getTransform();

    // On dessine les éléments
    target.draw( *m_bouton, states );
    target.draw( *m_label, states );

    if ( m_ecritureActive )
        target.draw( *m_curseur, states );


}


} // fin namespace gui

