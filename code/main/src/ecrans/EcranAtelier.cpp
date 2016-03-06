

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "ecrans/EcranAtelier.h"
#include <iostream>
#include <Config.h>



namespace app {

/////////////////////////////////////////////////
EcranAtelier::EcranAtelier( Application*  appli )
: Ecran             ( appli )
, m_interface       ( nullptr )
{
    // Initialisation de l'interface graphique.
    initGUI     ();


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
void EcranAtelier::traiter_evenements  ( const sf::Event& event )
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
        sf::Vector2f pos = sf::Vector2f( m_appli->getFenetre()->getSize() );
        m_vueJeu.setSize(pos);
        m_vueGUI.setSize(pos);
        pos *= 0.5f;
        m_vueJeu.setCenter(pos);
        m_vueGUI.setCenter(pos);

//        m_fond.setSize      ( pos );
//        m_vueJeu.setSize    (event.size.width, event.size.height);
//        m_vueGUI.setSize    (event.size.width, event.size.height);

        m_appli->getFenetre()->setView(m_vueGUI);
    }

}



/////////////////////////////////////////////////
void EcranAtelier::actualiser  ( float deltaT )
{
    // actualiser la fenetre du jeu ...

    // actualiser l'interface
    m_interface->actualiser    ( );

    ///<\todo actualiser les animations de l'interface
//    m_interface->actualiser    ( sf::seconds( deltaT ) ) ;




//    std::string val =  "Retour : " + m_interface->m_boutonSurvole->getNom();
//    if ( m_interface->m_boutonSurvole == nullptr )
//        val = "Retour : nullptr";

//

}



/////////////////////////////////////////////////
void EcranAtelier::dessiner ()
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
EcranAtelier::test () { std::cout << "CECI n'EST pas UN TEST QUI ne FONCTIONNE pas.\n";  }




/////////////////////////////////////////////////
void
EcranAtelier::initScene  ( )
{
    // Initialisation du fond.
    m_fond.setPosition  ( 0,0 );
//    m_fond.setSize      ( sf::Vector2f ( m_appli->getFenetre()->getSize() ) );
    m_fond.setSize      ( sf::Vector2f ( 1920 ,1080 ) );
    m_fond.setFillColor ( sf::Color (70,70,70) );

}



/////////////////////////////////////////////////
void
EcranAtelier::initGUI ()
{

    using namespace gui;
    sf::Vector2i posRoot = {0,0};

    // Creation de l'interface qui gère un ensemble de gadget.
    m_interface = std::make_shared<Interface>( m_appli->getFenetre() );


    /////// TITRE Label ///////
    auto m_labelTitre_1 = m_interface->creer.label( "Affichages" );
    m_labelTitre_1->setPosition    ( posRoot.x +20, posRoot.y + 40 );
    m_labelTitre_1->setTexteTaille ( 20 );



    using namespace gui;

    /////// Simple rectangle ///////
    auto m_rectangle = m_interface->creer.rectangle( {20,20} );
    m_rectangle->setPosition    ( posRoot.x , posRoot.y );


}


}   // fin namespace app































