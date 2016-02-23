

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
    m_interface->traiterEvenements    ( event );


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
    m_interface->actualiser    (  );
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


    /////// Interface globale ///////

    // Creation de l'interface qui gère un ensemble de gadget.
    m_interface = std::make_shared<Interface>();
    m_skin      = std::make_shared<Skin>();



    /////// Simple rectangle ///////
    m_rectangle = m_interface->creer.rectangle( {20,20} );
    m_rectangle->setPosition    ( 20 , 20 );
    m_rectangle->setOpacite     ( 0.2 );
    m_rectangle->setSkin ( m_skin );





    /////// Un Label ///////
    m_label = m_interface->creer.label( "Un label de base." );
    m_label->setPosition( 200 , 200 );


    /////// Une image ///////
    m_image = m_interface->creer.image( "media/img/IconeVide.png" );
    m_image->setTaille      ( { 500 , 500 } );
    m_image->setPosition    ( 220 , 20 );



    /////// Interactions clavier "globales" ///////

    // On ajoute une liaison à la touche Escape à l'interface global
    m_interface->lier ( sf::Keyboard::Escape , [this]() {
            std::cout << " touche : Escape  Fermer.\n";
            m_appli->getFenetre().close();
        } );

    // On ajoute une liaison à la touche Espace pour changer le style du rectangle
    m_interface->lier ( sf::Keyboard::Space , [this]() {
            std::cout << " touche : Espace ";
            if ( m_rectangle->getSkin () != nullptr)
            {
                std::cout << "( on retire le skin => rendu par defaut. ) \n";
                m_rectangle->setSkin    ( nullptr );
                m_label->setSkin        ( m_skin );
            }
            else
            {
                std::cout << "( on associe le skin (m_skin) => rendu par le skin. ) \n";
                m_rectangle->setSkin    ( m_skin );
                m_label->setSkin        ( nullptr );
            }
        } );

    // On associe des fonctions aux fleches pour faire bouger le label
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







}   // fin init GUI




}   // fin namespace app































