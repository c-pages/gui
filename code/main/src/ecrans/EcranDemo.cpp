

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "ecrans/EcranDemo.h"
#include <iostream>
#include <Config.h>
//#include "GUI.h"

namespace app {

/////////////////////////////////////////////////
EcranDemo::EcranDemo( Application*  appli )
: Ecran             ( appli )
//, m_gui             ( new gui::Groupe() )
{
   // m_gui = std::shared_ptr<gui::Groupe>  ( new gui::Groupe()  );
    // Initialisation de l'interface graphique.
    initGUI     ();
    initScene   ();

    // les vues jeu et gui
    sf::Vector2f pos = sf::Vector2f( m_appli->getFenetre().getSize() );
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
//    m_gui->traiter_evenements    ( event );



    // fermeture de la fenetre SFML
    if (event.type == sf::Event::Closed)
        m_appli->getFenetre().close();


    // Resize the window
    if (event.type ==  sf::Event::Resized)
    {

        m_vueJeu.setSize    (event.size.width, event.size.height);
        m_vueGUI.setSize    (event.size.width, event.size.height);

        m_appli->getFenetre().setView(m_vueGUI);
    }

}



/////////////////////////////////////////////////
void EcranDemo::actualiser  ( float deltaT )
{
    // actualiser la fenetre du jeu ...

    // actualiser l'interface
//    m_gui->actualiser    ( deltaT );
}



/////////////////////////////////////////////////
void EcranDemo::dessiner ()
{
    // Dessiner la fenetre du jeu

    // Dessiner l'interface
//    m_appli->getFenetre().draw ( *m_gui);



    m_appli->getFenetre().setView   ( m_vueJeu);
    m_appli->getFenetre().draw      ( m_fond );

    m_appli->getFenetre().setView   ( m_vueGUI );
//    m_appli->getFenetre().draw      ( *m_gui );




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
    m_fond.setSize      ( sf::Vector2f ( m_appli->getFenetre().getSize() ) );
    m_fond.setFillColor ( sf::Color (40,40,50));
//    m_gui->setSize      ( sf::Vector2f ( m_appli->getFenetre().getSize() ) );

}


/////////////////////////////////////////////////
void
EcranDemo::initGUI  ()
{




}   // fin init GUI




}   // fin namespace app































