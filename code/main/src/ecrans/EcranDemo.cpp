

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "ecrans/EcranDemo.h"
#include <iostream>
#include <Config.h>



namespace app {

/////////////////////////////////////////////////
EcranDemo::EcranDemo( Application*  appli )
: Ecran             ( appli )
, m_interface       ( nullptr )
{
    // Initialisation de l'interface graphique.
    initGUI     ();


    // les tests
    initGUI_test_Affichages();
    initGUI_test_Boutons();
    initGUI_test_Donnees  ();

    initScene   ();


    // definition des positions et tailles des vues jeu et gui
    sf::Vector2f pos = sf::Vector2f( m_appli->getFenetre()->getSize() );
    m_vueJeu.setSize(pos);
    m_vueGUI.setSize(pos);
    pos *= 0.5f;
    m_vueJeu.setCenter(pos);
    m_vueGUI.setCenter(pos);

}


/////////////////////////////////////////////////
void EcranDemo::traiter_evenements  ( const sf::Event& event )
{
    // Evenements du jeu ...


    // Evenements de l'interface
    m_interface->traiterEvenements    ( event );


    // fermeture de la fenetre SFML
    if ( event.type == sf::Event::Closed )
        m_appli->getFenetre()->close();


    // Resize the window
    if (event.type ==  sf::Event::Resized)
    {

        m_vueJeu.setSize    (event.size.width, event.size.height);
        m_vueGUI.setSize    (event.size.width, event.size.height);

        m_appli->getFenetre()->setView(m_vueGUI);
    }

}



/////////////////////////////////////////////////
void EcranDemo::actualiser  ( float deltaT )
{
    // actualiser la fenetre du jeu ...

    // actualiser l'interface
    m_interface->actualiser    ( );


    std::string val;
    if ( m_interface->m_boutonSurvole != nullptr ){
        val =  "Survole : " + m_interface->m_boutonSurvole->getNom();
    } else val = "Survole : nullptr";

    m_labelRetour->setTexte ( val );



//    std::string val =  "Retour : " + m_interface->m_boutonSurvole->getNom();
//    if ( m_interface->m_boutonSurvole == nullptr )
//        val = "Retour : nullptr";

//

}



/////////////////////////////////////////////////
void EcranDemo::dessiner ()
{
    sf::RenderWindow* fenetre = m_appli->getFenetre();
    // Dessiner la fenetre du jeu
    fenetre->setView   ( m_vueJeu);
    fenetre->draw      ( m_fond );

    // Dessiner l'interface
    fenetre->setView   ( m_vueGUI );
    fenetre->draw      ( *m_interface );

}


/////////////////////////////////////////////////
void
EcranDemo::test () { std::cout << "CECI n'EST pas UN TEST QUI ne FONCTIONNE pas.\n";  }


/////////////////////////////////////////////////
void
EcranDemo::initScene  ( )
{
    // Initialisation du fond.
    m_fond.setPosition  ( 0,0 );
    m_fond.setSize      ( sf::Vector2f ( m_appli->getFenetre()->getSize() ) );
    m_fond.setFillColor ( sf::Color (70,70,70) );

}

/////////////////////////////////////////////////
void
EcranDemo::initGUI ()
{

    using namespace gui;

    // Creation de l'interface qui gère un ensemble de gadget.
    m_interface = std::make_shared<Interface>( m_appli->getFenetre() );
    m_skin      = std::make_shared<Skin>();


    /////// Interactions clavier ///////
//    m_interface->lier ( sf::Keyboard::Escape , [this]() {
//            std::cout << " touche : Escape  Fermer.\n";
//            m_appli->getFenetre()->close();
//        } );

    /////// Label retour ///////
    m_labelRetour = m_interface->creer.label( "Retour :" );
    m_labelRetour->setPosition    ( 20 , 5 );
    m_labelRetour->setStyle       ( m_skin->getStyle (  gui::Skin::Styles::txtLog ) );


    /////// Interactions clavier ///////
    // On ajoute une liaison à la touche Espace pour changer le style du rectangle
    m_interface->lier ( sf::Keyboard::Space , [this]() {
            std::cout << "Interface - Action : touche 'Espace'\n";
        } );
}


/////////////////////////////////////////////////
void
EcranDemo::initGUI_test_Donnees  ()
{

    sf::Vector2f posRoot = { 820 , 60 };

    std::cout << "\n---------------------------------------\n";
    std::cout << "      Test des gadgets : DONNEES";
    std::cout << "\n---------------------------------------\n\n";


    /////// TITRE Label ///////
    m_labelTitre_0 = m_interface->creer.label( "Données" );
    m_labelTitre_0->setPosition    ( posRoot.x , posRoot.y - 40 );
    m_labelTitre_0->setStyle       ( m_skin->getStyle ( gui::Skin::Styles::txtTitre ) );



    /////// Bouton à cocher ///////
    m_boutonCoche = m_interface->creer.btnACocher( );
    m_boutonCoche->setPosition    ( posRoot.x , posRoot.y  +  0 );
    m_boutonCoche->setStyle       ( m_skin->getStyle ( gui::Skin::Styles::txtLog ) );
    m_boutonCoche->setTexte       ( "'Machiner'" );
    m_boutonCoche->setValeur      ( true );

    m_boutonCoche->lier ( gui::Evenement::on_changerValeur , [this](){
                        std::cout << "ACTION Bool : changer Valeur\n";
                        if (  m_boutonTexte->estActif() ){
                            delierMachiner ();
                            m_boutonTexte->setActif( false );
                        } else {
                            lierMachiner ();
                            m_boutonTexte->setActif( true );
                        } });
    m_boutonCoche->lier ( gui::Evenement::onBool_allume , [this](){
                        std::cout << "ACTION Bool : allume\n";
                        });
    m_boutonCoche->lier ( gui::Evenement::onBool_eteind , [this](){
                        std::cout << "ACTION Bool : eteind\n";
                        });

    /////// autre Label ///////
    m_label_7 = m_interface->creer.label( "<---  Bouton Booleén, interrupteur ... ('Tab')" );
    m_label_7->setPosition    ( 190 + posRoot.x , posRoot.y  +  2 );
    m_label_7->setStyle       ( m_skin->getStyle (  gui::Skin::Styles::txtLog ) );



    /////// Zone de texte ///////
    m_zoneTexte = m_interface->creer.zoneTexte( "Zone de texte" );
    m_zoneTexte->setPosition    ( posRoot.x , posRoot.y  +  28 );
    m_zoneTexte->setStyle       ( m_skin->getStyle (  gui::Skin::Styles::txtLog ) );


    /////// autre Label ///////
    m_label_8 = m_interface->creer.label( "<---  Zone de texte (simple pour l'instant)." );
    m_label_8->setPosition    ( 190 + posRoot.x , posRoot.y  +  30 );
    m_label_8->setStyle       ( m_skin->getStyle (  gui::Skin::Styles::txtLog ) );




    ///////slider ///////
    m_slider = m_interface->creer.slider( );
    m_slider->setPosition    ( posRoot.x , posRoot.y  +  68 );
    m_slider->setStyle       ( m_skin->getStyle (  gui::Skin::Styles::bouton ) );
//    m_slider->setLongCurseur ( 50 );

    //m_slider->setVertical();

    m_slider->lier ( gui::Evenement::on_changerValeur , [this](){
        std::cout << "ACTION - Valeur : " << m_slider->getValeur() << "\n";
    });


    /////// autre Label ///////
    m_label_9 = m_interface->creer.label( "<---  Slider pour controler valeur de 0.0 à 1.0" );
    m_label_9->setPosition    ( 190 + posRoot.x , posRoot.y  +  70 );
    m_label_9->setStyle       ( m_skin->getStyle (  gui::Skin::Styles::txtLog ) );



    ///////barreDefilement ///////
    m_barreDefil = m_interface->creer.barreDefilement( );
    m_barreDefil->setPosition    ( posRoot.x , posRoot.y  +  98 );
    m_barreDefil->setStyle       ( m_skin->getStyle (  gui::Skin::Styles::bouton ) );

    m_barreDefil->setLongueurCurseur ( 50 );

    /////// autre Label ///////
    m_label_10 = m_interface->creer.label( "<---  Barre de défilement" );
    m_label_10->setPosition    ( 190 + posRoot.x , posRoot.y  +  100 );
    m_label_10->setStyle       ( m_skin->getStyle (  gui::Skin::Styles::txtLog ) );




}
/////////////////////////////////////////////////
void
EcranDemo::initGUI_test_Boutons  ()
{

    sf::Vector2f posRoot = { 420 , 60 };

    std::cout << "\n---------------------------------------\n";
    std::cout << "      Test des gadgets : BOUTONS";
    std::cout << "\n---------------------------------------\n\n";

    /////// TITRE Label ///////
    m_labelTitre_1 = m_interface->creer.label( "Boutons" );
    m_labelTitre_1->setPosition    ( posRoot.x , posRoot.y - 40 );
    m_labelTitre_1->setStyle       ( m_skin->getStyle (  gui::Skin::Styles::txtTitre ) );




    using namespace gui;

    /////// Simple bouton rectangulaire ///////
    m_boutonTexte = m_interface->creer.boutonTexte( "Machiner" );
    m_boutonTexte->setAutoAjuster ( true );
    m_boutonTexte->setSkin        ( m_skin );

    m_boutonTexte->setPosition    ( posRoot.x , posRoot.y );

     lierMachiner ();

    /////// Interactions clavier ///////
    // On ajoute une liaison à la touche Espace pour changer le style du rectangle
    m_interface->lier ( sf::Keyboard::Tab , [this]() {
            std::cout << "Interface - Action : touche 'Tab'\n";
            std::cout << "      -> toggle l'activite du bouton\n";
            if (  m_boutonTexte->estActif() ){
                delierMachiner ();
                m_boutonTexte->setActif( false );
            }else {
                lierMachiner ();
                m_boutonTexte->setActif( true );
            }
            m_boutonCoche->setValeur ( m_boutonTexte->estActif() );
        } );


    /////// autre Label ///////
    m_label_5 = m_interface->creer.label( "<---  Simple bouton texte.\n (toute les interr-ACTIONs souris en console.)" );
    m_label_5->setPosition    ( 160 + posRoot.x , posRoot.y + 3 );
//    m_label_5->setSkin        ( m_skin );
    m_label_5->setStyle       ( m_skin->getStyle (  gui::Skin::Styles::txtLog ) );





    /////// Simple bouton rectangulaire ///////
    m_boutonIcone = m_interface->creer.boutonIcone( "media/img/Icone_test.png" );
    m_boutonIcone->setAutoAjuster ( true );
    m_boutonIcone->setSkin        ( m_skin );
    m_boutonIcone->setFix         ( true );
    m_boutonIcone->setPosition    ( posRoot.x , posRoot.y +35 );


    /////// autre Label ///////
    m_label_12 = m_interface->creer.label( "<---  Simple bouton icone." );
    m_label_12->setPosition    ( 160 + posRoot.x , posRoot.y + 43 );
    m_label_12->setStyle       ( m_skin->getStyle (  gui::Skin::Styles::txtLog ) );




    /////// Menu ///////
    m_boutonMenu = m_interface->creer.menu( );

    m_boutonMenu->setPosition    ( posRoot.x , posRoot.y  + 85 );
    m_boutonMenu->ajouter ( "Faire un truc" , [this](){
                        std::cout << "ACTION fait un truc.\n";
                        });
    m_boutonMenu->ajouter ( "Bidouiller" , [this](){
                        std::cout << "ACTION bidouille.\n";
                        });

    m_boutonMenu->ajouter ( "Faire autre chose" , [this](){
                        std::cout << "ACTION fait autre chose.\n";
                        });

    m_boutonMenu->ajouter ( "Buller" , [this](){
                        std::cout << "ACTION ne fait rien.\n";
                        });

    /////// autre Label ///////
    m_label_6 = m_interface->creer.label( "<---  Menu (déroulant, contextuel, ...)." );
    m_label_6->setPosition    ( 160 + posRoot.x , posRoot.y  +  110 );
    m_label_6->setStyle       ( m_skin->getStyle (  gui::Skin::Styles::txtLog ) );













}   // fin init GUI



/////////////////////////////////////////////////
void EcranDemo::lierMachiner ()
{

    m_boutonTexte->lier ( gui::Evenement::onBtnG_relacher , [this](){
                        std::cout << "MACHINER: souris gauche relache : Faire un machin : " << m_zoneTexte->getValeur() <<"\n";
/*
                        if (  m_boutonCoche->estVisible() ){
                            m_boutonCoche->setVisible ( false );
                        } else {
                            m_boutonCoche->setVisible ( true );
                        }
                        */
                        std::cout << "-> slider : " << m_slider->getValeur() <<"\n";
                    });
    m_boutonTexte->lier ( gui::Evenement::onBtnG_presser , [this](){
                        std::cout << "MACHINER: souris gauche presse\n";
                        });
    m_boutonTexte->lier ( gui::Evenement::onBtnD_presser , [this](){
                        std::cout << "MACHINER: souris droite presse\n";
                        });
    m_boutonTexte->lier ( gui::Evenement::onBtnM_presser , [this](){
                        std::cout << "MACHINER: souris milieu presse\n";
                        });

    m_boutonTexte->lier ( gui::Evenement::onBtnG_relacherDehors  , [this](){
                        std::cout << "MACHINER: souris gauche relacherDehors\n";
                        });
    m_boutonTexte->lier ( gui::Evenement::onBtnG_relacher , [this](){
                        std::cout << "MACHINER: souris gauche relacher\n";
                        });
    m_boutonTexte->lier ( gui::Evenement::onBtnD_relacherDehors  , [this](){
                        std::cout << "MACHINER: souris droite relacherDehors\n";
                        });
    m_boutonTexte->lier ( gui::Evenement::onBtnD_relacher , [this](){
                        std::cout << "MACHINER: souris droite relacher\n";
                        });
    m_boutonTexte->lier ( gui::Evenement::onBtnM_relacherDehors  , [this](){
                        std::cout << "MACHINER: souris milieu relacherDehors\n";
                        });
    m_boutonTexte->lier ( gui::Evenement::onBtnM_relacher , [this](){
                        std::cout << "MACHINER: souris milieu relacher\n";
                        });

    m_boutonTexte->lier ( gui::Evenement::onBtnM_roulerHaut  , [this](){
                        std::cout << "MACHINER: souris milieu ROULETTE PLUS\n";
                        });
    m_boutonTexte->lier ( gui::Evenement::onBtnM_roulerBas , [this](){
                        std::cout << "MACHINER: souris milieu ROULETTE MOINS\n";
                        });
}



/////////////////////////////////////////////////
void EcranDemo::delierMachiner ()
{

    m_boutonTexte->delier ( gui::Evenement::onBtnG_relacher);
    m_boutonTexte->delier ( gui::Evenement::onBtnG_presser);
    m_boutonTexte->delier ( gui::Evenement::onBtnD_presser);
    m_boutonTexte->delier ( gui::Evenement::onBtnM_presser );

    m_boutonTexte->delier ( gui::Evenement::onBtnG_relacherDehors );
    m_boutonTexte->delier ( gui::Evenement::onBtnG_relacher);
    m_boutonTexte->delier ( gui::Evenement::onBtnD_relacherDehors );
    m_boutonTexte->delier ( gui::Evenement::onBtnD_relacher );
    m_boutonTexte->delier ( gui::Evenement::onBtnM_relacherDehors );
    m_boutonTexte->delier ( gui::Evenement::onBtnM_relacher );

    m_boutonTexte->delier ( gui::Evenement::onBtnM_roulerHaut);
    m_boutonTexte->delier ( gui::Evenement::onBtnM_roulerBas );

}

/////////////////////////////////////////////////
void
EcranDemo::initGUI_test_Affichages  ()
{
    std::cout << "\n---------------------------------------\n";
    std::cout << "      Test des gadgets : AFFICHAGES";
    std::cout << "\n---------------------------------------\n\n";

    sf::Vector2f posRoot = { 20 , 60 };

    /////// TITRE Label ///////
    m_labelTitre_1 = m_interface->creer.label( "Affichages" );
    m_labelTitre_1->setPosition    ( posRoot.x , posRoot.y - 40 );
    m_labelTitre_1->setStyle       ( m_skin->getStyle (  gui::Skin::Styles::txtTitre ) );


    using namespace gui;

    /////// Simple rectangle ///////
    m_rectangle = m_interface->creer.rectangle( {20,20} );
    m_rectangle->setPosition    ( posRoot.x , posRoot.y );


    /////// Un Label ///////
    m_label = m_interface->creer.label( "<---  simple rectangle." );
    m_label->setPosition    ( 70 + posRoot.x , posRoot.y + 5 );
    m_label->setStyle       ( m_skin->getStyle (  gui::Skin::Styles::txtLog ) );


    /////// Une image ///////
    m_image = m_interface->creer.image( "media/img/Image_defaut.png" );
//    m_image->setTaille      ( { 500 , 500 } );
    m_image->setPosition    (  posRoot.x , posRoot.y + 30 );


    /////// autre Label ///////
    m_label_2 = m_interface->creer.label( "<---  simple image. ('media/img/IconeVide.png')" );
    m_label_2->setPosition    (70 + posRoot.x , posRoot.y + 35 );
    m_label_2->setStyle       ( m_skin->getStyle (  gui::Skin::Styles::txtLog ) );



    /////// Un Label ///////
    m_label_3 = m_interface->creer.label( "LABEL" );
    m_label_3->setPosition    (  posRoot.x , posRoot.y + 60 );
    m_label_3->setTexteTaille ( 20 );

    /////// autre Label ///////
    m_label_4 = m_interface->creer.label( "<---  simple label. (comme ça ici là)" );
    m_label_4->setPosition    ( 70 + posRoot.x , posRoot.y + 65 );
    m_label_4->setStyle       ( m_skin->getStyle (  gui::Skin::Styles::txtLog ) );






    /////// Une icone ///////
    m_icone = m_interface->creer.icone( "media/img/ico_fleches.png" , 4);
    m_icone->setPosition    (  posRoot.x , posRoot.y + 90 );

    m_interface->lier ( sf::Keyboard::Num1 , [this](){
                       m_icone->setIndex ( 1 );
                       });

    m_interface->lier ( sf::Keyboard::Num2 , [this](){
                       m_icone->setIndex ( 2 );
                       });
    m_interface->lier ( sf::Keyboard::Num3 , [this](){
                       m_icone->setIndex ( 3 );
                       });
    m_interface->lier ( sf::Keyboard::Num4 , [this](){
                       m_icone->setIndex ( 4 );
                       });


    /////// autre Label ///////
    m_label_11 = m_interface->creer.label( "<---  icone. ('1', '2', '3', '4' pour changer index de l'icone)" );
    m_label_11->setPosition    ( 70 + posRoot.x , posRoot.y + 95 );
    m_label_11->setStyle       ( m_skin->getStyle (  gui::Skin::Styles::txtLog ) );


    // On associe des fonctions aux fleches pour faire bouger le label
    /*
    m_interface->lier ( sf::Keyboard::Left , [this]() {
            std::cout << " touche : Left\n";
            m_label->move ( -3,0);
        } );
    m_interface->lier ( sf::Keyboard::Right , [this]() {
            std::cout << " touche : Right\n";
            m_label->move ( 3,0);
        } );
    m_interface->lier ( sf::Keyboard::Up , [this]() {
            std::cout << " touche : Up\n";
            m_label->move ( 0,-3);
        } );
    m_interface->lier ( sf::Keyboard::Down , [this]() {
            std::cout << " touche : Down\n";
            m_label->move ( 0,3);
        } );
    */






}   // fin init GUI



}   // fin namespace app































