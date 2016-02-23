

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Application.h"
#include "Config.h"
#include "ecrans/EcranDemo.h"
#include <SFML/System.hpp>

namespace app
{
/////////////////////////////////////////////////
Application::Application()
: m_fenetre ( new sf::RenderWindow() )
{

    //   Initialisation de la Configuration ( ensembles des ressources ...)
    Config::init();

    //   Creation de la fen�tre SFML.
    sf::ContextSettings 	contextFenetre  ( 	0,  //  depth
                                                0,  //  stencil
                                                0,  //  antialiasing
                                                2,  //  major
                                                0); //  minor
    m_fenetre->create(sf::VideoMode(800, 600), "Appli de base" , sf::Style::Default , contextFenetre );

    // La synchronisation verticale pour des histoire de bugs de chqrgement de police bidule truc
    m_fenetre->setVerticalSyncEnabled(true);

    //   Ajout du premier �cran.
    m_ecrans.ajouter( new EcranDemo( this ) );

}


/////////////////////////////////////////////////
Application::~Application()
{
    // vider la pile.
    m_ecrans.vider();
}


/////////////////////////////////////////////////
void    Application::executer()
{

    sf::Clock   horloge;
    sf::Time    tempsDepuisMAJ = sf::Time::Zero;

//sf::sleep( sf::seconds(0.005f)) ;

    while ( m_fenetre->isOpen() )
    {
        traiter_evenements();
        tempsDepuisMAJ += horloge.restart();
        while (tempsDepuisMAJ > Config::getDureeImage())
        {
            tempsDepuisMAJ -= Config::getDureeImage();

            // Traitement des �venements.
            traiter_evenements();

            // Actualisation des �l�ments des �crans.
            actualiser( Config::getDureeImage().asSeconds() );

            // si la pile d'�crans est vide, on ferme.
            if ( m_ecrans.estVide() )
                m_fenetre->close();
        }

        // Dessiner les �crans actifs.
        dessiner();
    }
}


/////////////////////////////////////////////////
sf::RenderWindow*    Application::getFenetre()
{
    return m_fenetre;
}



/////////////////////////////////////////////////
void Application::traiter_evenements()
{
    sf::Event event;
    while (m_fenetre->pollEvent(event)){

        m_ecrans.traiter_evenements ( event );



    }
}


/////////////////////////////////////////////////
void Application::actualiser ( float deltaT )
{
    m_ecrans.actualiser ( deltaT );
}


/////////////////////////////////////////////////
void Application::dessiner ( )
{

    /// > Vider la fenetre.
    m_fenetre->clear(sf::Color::Black);

    /// > Rendu des ecrans courants.
    m_ecrans.dessiner();

    /// > Afficher la fen�tre.
    m_fenetre->display();

}


} // namespace app
