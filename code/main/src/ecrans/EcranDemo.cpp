

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
    m_interface = std::make_shared<Interface>( m_appli->getFenetre()  );
    m_skin      = std::make_shared<Skin>();


    /////// Interactions clavier ///////
    m_interface->lier ( sf::Keyboard::Escape , [this]() {
            std::cout << " touche : Escape  Fermer.\n";
            m_appli->getFenetre()->close();
        } );

    /////// Label retour ///////
    m_labelRetour = m_interface->creer.label( "Retour :" );
    m_labelRetour->setPosition    ( 20 , 5 );
    m_labelRetour->setStyle       ( m_skin->txtLog );


    /////// Interactions clavier ///////
    // On ajoute une liaison à la touche Espace pour changer le style du rectangle
    m_interface->lier ( sf::Keyboard::Space , [this]() {
            std::cout << "Interface - Action : touche 'Espace'\n";
        } );
}



/////////////////////////////////////////////////
void
EcranDemo::initGUI_test_Boutons  ()
{

    std::cout << "\n---------------------------------------\n";
    std::cout << "      Test des gadgets : BOUTONS";
    std::cout << "\n---------------------------------------\n\n";

    sf::Vector2f posRoot = { 320 , 30 };
    using namespace gui;

    /////// Simple bouton rectangulaire ///////
    m_boutonRect = m_interface->creer.bouton( sf::Vector2i (20,20) );
    m_boutonRect->setTexte ( "Bouton" );
    m_boutonRect->setAutoAjuster ( true );
    m_boutonRect->setSkin        ( m_skin );

    m_boutonRect->setPosition    ( posRoot.x , posRoot.y );
    m_boutonRect->lier ( gui::Evenement::onBtnG_relacher , [this](){
                        std::cout << "ACTION RELACHER le bouton\n";
                        });

    /////// autre Label ///////
    m_label_5 = m_interface->creer.label( "<---  Simple bouton rectangulaire (ayant néanmoins du gui::Style)." );
    m_label_5->setPosition    ( 80 + posRoot.x , posRoot.y + 3 );
//    m_label_5->setSkin        ( m_skin );
    m_label_5->setStyle       ( m_skin->txtLog );





    /////// Menu ///////
    m_boutonMenu = m_interface->creer.menu( );

//    m_boutonMenu->setSkin        ( m_skin );

    m_boutonMenu->setPosition    ( posRoot.x , posRoot.y  + 40 );
    m_boutonMenu->ajouter ( "Action 1" , [this](){
                        std::cout << "ACTION 1\n";
                        });
    m_boutonMenu->ajouter ( "Action 2" , [this](){
                        std::cout << "ACTION 2\n";
                        });

    m_boutonMenu->ajouter ( "Action 3" , [this](){
                        std::cout << "ACTION 3\n";
                        });


    /////// autre Label ///////
    m_label_6 = m_interface->creer.label( "<---  Menu (menu déroulant, menu contextuel, ...)" );
    m_label_6->setPosition    ( 170 + posRoot.x , posRoot.y  +  65 );
    m_label_6->setStyle       ( m_skin->txtLog );


}   // fin init GUI



/////////////////////////////////////////////////
void
EcranDemo::initGUI_test_Affichages  ()
{
    std::cout << "\n---------------------------------------\n";
    std::cout << "      Test des gadgets : AFFICHAGES";
    std::cout << "\n---------------------------------------\n\n";

    sf::Vector2f posRoot = { 20 , 30 };

    using namespace gui;

    /////// Simple rectangle ///////
    m_rectangle = m_interface->creer.rectangle( {20,20} );
    m_rectangle->setPosition    ( posRoot.x , posRoot.y );


    /////// Un Label ///////
    m_label = m_interface->creer.label( "<---  simple rectangle." );
    m_label->setPosition    ( 30 + posRoot.x , posRoot.y + 5 );
    m_label->setStyle       ( m_skin->txtLog );


    /////// Une image ///////
    m_image = m_interface->creer.image( "media/img/IconeVide.png" );
    m_image->setTaille      ( { 500 , 500 } );
    m_image->setPosition    (  posRoot.x , posRoot.y + 30 );


    /////// autre Label ///////
    m_label_2 = m_interface->creer.label( "<---  simple image. ('media/img/IconeVide.png')" );
    m_label_2->setPosition    (55 + posRoot.x , posRoot.y + 35 );
    m_label_2->setStyle       ( m_skin->txtLog );



    /////// Un Label ///////
    m_label_3 = m_interface->creer.label( "LABEL" );
    m_label_3->setPosition    (  posRoot.x , posRoot.y + 60 );
    m_label_3->setTexteTaille ( 20 );

    /////// autre Label ///////
    m_label_4 = m_interface->creer.label( "<---  simple label. (comme ça ici là)" );
    m_label_4->setPosition    ( 70 + posRoot.x , posRoot.y + 65 );
    m_label_4->setStyle       ( m_skin->txtLog );




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































