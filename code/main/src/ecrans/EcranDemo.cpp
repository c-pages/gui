

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
, m_interface       ( new gui::Interface( ) )
{

    // Initialisation de l'interface graphique.
    initGUI     ();
    initScene   ();

    // definition des positions et tailles des vues jeu et gui
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
    m_interface->traiter_evenements    ( event );


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
//    m_interface->actualiser    ( deltaT );
}



/////////////////////////////////////////////////
void EcranDemo::dessiner ()
{

    // Dessiner la fenetre du jeu
    m_appli->getFenetre().setView   ( m_vueJeu);
    m_appli->getFenetre().draw      ( m_fond );

    // Dessiner l'interface
    m_appli->getFenetre().setView   ( m_vueGUI );
    m_appli->getFenetre().draw      ( *m_interface );

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
    m_fond.setFillColor ( sf::Color (40,40,50) );

}


/////////////////////////////////////////////////
void
EcranDemo::initGUI  ()
{
    using namespace gui;

    // Creation d'un bouton
    std::shared_ptr<Gadget> bouton = m_interface->creer.bouton( "Bouton Test" );
    bouton->setPosition ( 50,50 );
    bouton->lier ( sf::Keyboard::Escape , [this](){
                   m_appli->getFenetre().close();
       // gui::Log::print (  "Texte : " + m_champ->getTexte() );
    } );

}   // fin init GUI




}   // fin namespace app































