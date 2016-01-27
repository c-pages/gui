

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "ecrans/EcranDemo.h"

#include <iostream>
#include <Config.h>
#include <SFML/Graphics.hpp>

#include "GUI.h"
#include "Gadget.h"
//#include "test.h"

namespace app {

/////////////////////////////////////////////////
EcranDemo::EcranDemo( std::shared_ptr<Application> appli )
: Ecran         ( appli )
//, m_interface   ( std::shared_ptr<gui::Gadget>( new gui::Gadget ( ) ) )
//, m_test        ( /*std::shared_ptr<gui::test>(new gui::test())*/ )
{
//    m_test    =   std::shared_ptr<gui::Test>(new gui::Test());
    std::cout << "EcranDemo :debut\n";

//    m_interface = std::shared_ptr<gui::Gadget>( new gui::Gadget ( ) );

    // Initialisations de l'ecren
    initGUI     ();
    initScene   ();
    initVues    ();

}


/////////////////////////////////////////////////
void EcranDemo::traiter_evenements  ( const sf::Event& event )
{
    // Evenements du jeu ...


    // Evenements de l'interface
//    m_interface->traiter_evenements    ( event );



    // fermeture de la fenetre SFML
    if (event.type == sf::Event::Closed)
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
void EcranDemo::actualiser  ( sf::Time deltaT )
{
    // actualiser la fenetre du jeu ...

    // actualiser l'interface (pour animation)
   // m_interface->actualiser    ( deltaT );
}



/////////////////////////////////////////////////
void EcranDemo::dessiner ()
{
    // Dessiner la fenetre du jeu

    // Dessiner l'interface
    //    m_interface->dessiner    ();
    std::cout << "Dessiner...\n";


    m_appli->getFenetre()->setView  ( m_vueJeu );
//    m_appli->getFenetre()->draw     ( m_fond );

    m_appli->getFenetre()->draw     ( m_interface );


//    m_interface->draw( *m_appli->getFenetre() , sf::RenderStates::Default );
//    std::cout << "  Dessiner l'interface : m_test\n";
//    m_appli->getFenetre()->draw      ( *m_test );
//
//    if (m_interface != nullptr){
//        std::cout << "  PAS NUL\n";
////        if (m_interface)
//    }else
//        std::cout << "  NUL\n";

//    std::cout << "  Dessiner l'interface : m_interface\n";
//    m_appli->getFenetre()->draw      ( *m_interface );
//
//    m_appli->getFenetre()->setView   ( m_vueGUI );
////    m_appli->getFenetre()->draw      ( *m_interface );
//
//
////    if (m_interface != nullptr)
   // m_appli->getFenetre()->draw      ( *m_interface );
//
//    m_interface->draw( *m_appli->getFenetre() );


    std::cout << "  Dessiner l'interface FIN\n";



}


/////////////////////////////////////////////////
void
EcranDemo::test () { std::cout << "CECI n'EST pas UN TEST QUI ne FONCTIONNE pas.\n";  }


/////////////////////////////////////////////////
void
EcranDemo::initVues  ( )
{


    // les vues jeu et gui
    sf::Vector2f pos = sf::Vector2f( m_appli->getFenetre()->getSize() );
    m_vueJeu.setSize(pos);
    m_vueGUI.setSize(pos);
    pos *= 0.5f;
    m_vueJeu.setCenter(pos);
    m_vueGUI.setCenter(pos);

}

/////////////////////////////////////////////////
void
EcranDemo::initScene  ( )
{
    // Initialisation du fond.
    m_fond.setPosition  ( 0,0 );
    m_fond.setSize      ( sf::Vector2f ( m_appli->getFenetre()->getSize() ) );
    m_fond.setFillColor ( sf::Color (140,140,50));
//    m_gui->setSize      ( sf::Vector2f ( m_appli->getFenetre().getSize() ) );

}


/////////////////////////////////////////////////
void
EcranDemo::initGUI  ()
{
    std::cout << "initGUI :debut\n";
    //m_interface->setFenetreSFML( m_appli->getFenetre() );
//    // Creation du gestionnaire d'interface
//    m_interface = std::shared_ptr<gui::Gui>( new gui::Gui ( ) );
//    m_interface = std::shared_ptr<gui::Gui>( new gui::Gui ( m_appli->getFenetre() ) ) ;
    std::cout << "  initGUI Fin\n";
    // Creation d'un bouton
//    gui::Gadget::ptr bouton1 = m_interface->creer.bouton( );
   /* bouton1->setPosition ( { 50 , 150 } );
    bouton1->setTaille ( { 20, 100 } );*/

}   // fin init GUI




}   // fin namespace app

