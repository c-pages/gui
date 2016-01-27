

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Application.h"
#include "Config.h"
#include "ecrans/EcranDemo.h"



#include <iostream>
#include <SFML/System.hpp>

namespace app
{
/////////////////////////////////////////////////
Application::Application()
//:  m_fenetre ( new sf::RenderWindow() )
{

    std::cout << "Creation application\n";
    //   Initialisation de la Configuration ( ensembles des ressources ...)
    Config::init();

    std::cout << "  Creation application 1\n";
    //   Creation de la fenêtre SFML.
    sf::ContextSettings 	contextFenetre  ( 	0,  //  depth
                                                0,  //  stencil
                                                0,  //  antialiasing
                                                2,  //  major
                                                0); //  minor

    std::cout << "  Creation application 2\n";

    m_fenetre.create(sf::VideoMode(800, 600), "Appli de base" , sf::Style::Default , contextFenetre );

    std::cout << "  Creation application 3\n";
    //   Ajout du premier écran.
    m_ecrans.ajouter( new EcranDemo( shared_from_this () ) );

    std::cout << "  Creation application Fin\n";
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

    std::cout << "Application::executer()\n";
    sf::Clock   horloge;
    sf::Time    tempsDepuisMAJ = sf::Time::Zero;

//sf::sleep( sf::seconds(0.005f)) ;

    while ( m_fenetre.isOpen() )
    {
        traiter_evenements();
        tempsDepuisMAJ += horloge.restart();
        while (tempsDepuisMAJ > Config::getDureeImage())
        {
            tempsDepuisMAJ -= Config::getDureeImage();

            // Traitement des évenements.
            traiter_evenements();

            // Actualisation des éléments des écrans.
            actualiser( Config::getDureeImage() );

            // si la pile d'écrans est vide, on ferme.
            if ( m_ecrans.estVide() )
                m_fenetre.close();
        }

        // Dessiner les écrans actifs.
        dessiner();
    }
}


/////////////////////////////////////////////////
sf::RenderWindow*    Application::getFenetre()
{
    return &m_fenetre;
}



/////////////////////////////////////////////////
void Application::traiter_evenements()
{
    sf::Event event;
    while (m_fenetre.pollEvent(event)){

        m_ecrans.traiter_evenements ( event );



    }
}


/////////////////////////////////////////////////
void Application::actualiser ( sf::Time deltaT )
{
    m_ecrans.actualiser ( deltaT );
}


/////////////////////////////////////////////////
void Application::dessiner ( )
{

    /// > Vider la fenetre.
    m_fenetre.clear(sf::Color::Black);

    /// > Rendu des ecrans courants.
    m_ecrans.dessiner();

    /// > Afficher la fenêtre.
    m_fenetre.display();


}
} // namespace app
