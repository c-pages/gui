/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Interface.h>
#include <ConteneurGui.h>
#include <Gadget.h>

#include <iostream>


namespace gui {


/////////////////////////////////////////////////
// Initialisation des statics
/////////////////////////////////////////////////
//Interface  Interface::m_instance;

/*
/////////////////////////////////////////////////
std::shared_ptr<Interface> Interface::instance ()
{

}
*/

/////////////////////////////////////////////////
void Interface::actualiser ( sf::Time delta )
{
    std::cout << " Interface::actualiser\n";
//    m_conteneur->actualiser (delta);
}

/*
/////////////////////////////////////////////////
void Interface::traiter_evenements (const sf::Event&  evenement)
{
    std::cout << " Interface::traiter_evenements\n";
    Gadget::ptr boutonSurvolBack = m_btnSurvole;
    m_btnSurvole = chercherSurvol ();



//    m_conteneur->traiter_evenements ( evenement );
}*/

/*
/////////////////////////////////////////////////
void Interface::draw (sf::RenderTarget& target, sf::RenderStates states) const
{

}
*/

/////////////////////////////////////////////////
Interface::Interface (  )
: m_fenetreSFML ( 0 )
, m_skin        ( 0 )
, creer         ( FabriqueGadget ( /*shared_from_this() */ ) )
//, m_conteneur   ( std::shared_ptr<Gadget> ( new ConteneurInterface () ) )
{
    std::cout << "Creation Interface ()\n";

}

/////////////////////////////////////////////////
Interface::Interface ( sf::RenderWindow* fenetreSFML )
: m_fenetreSFML ( fenetreSFML )
, m_skin ( 0 )
, creer ( FabriqueGadget ( shared_from_this() ) )
//, m_conteneur (  Gadget::ptr ( new ConteneurInterface () ) )
{
    std::cout << "Creation Interface ( sf::RenderWindow* fenetreSFML )\n";
//    m_conteneur =  Gadget::ptr ( new ConteneurInterface () );

}

/*
/////////////////////////////////////////////////
Interface::Interface (const Interface& original)
: m_fenetreSFML (  )
, m_skin (  )
{

}*/

/////////////////////////////////////////////////
void Interface::traiter_evenements ( const sf::Event&  evenement )
{
    std::cout << "Interface : traiter evenemnts\n";
}

/////////////////////////////////////////////////
Interface::~Interface ()
{

}


/////////////////////////////////////////////////
Gadget::ptr Interface::chercherSurvol ()
{
//    for
}

/*
/////////////////////////////////////////////////
void Interface::dessiner ( ) const
{
    // Dessiner le conteneur
    m_fenetreSFML->draw( *m_conteneur );

}*/

/////////////////////////////////////////////////
void Interface::draw (sf::RenderTarget& target, sf::RenderStates states) const
{
    std::cout << " Interface::draw\n";

    // On dessine chaques composants
    //m_conteneur->draw ( target , states );

}


} // fin namespace gui

