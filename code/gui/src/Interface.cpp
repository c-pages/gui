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
: m_fenetreSFML ( nullptr )
, m_skin        ( nullptr )
, creer         ( FabriqueGadget ( this ) )
//, m_conteneur   ( std::make_shared<ConteneurGui> ( ) )
, m_gdgtSurvole ( nullptr )
, m_gdgtPresse  ( nullptr )
{
    std::cout << "Creation Interface ()\n";
}

/////////////////////////////////////////////////
Interface::Interface ( sf::RenderWindow* fenetreSFML )
: m_fenetreSFML ( fenetreSFML )
, m_skin        ( nullptr )
, creer         ( FabriqueGadget ( this ) )
//, m_conteneur   ( std::make_shared<ConteneurGui> ( ) )
, m_gdgtSurvole ( nullptr )
, m_gdgtPresse  ( nullptr )
{
    std::cout << "Creation Interface ( sf::RenderWindow* fenetreSFML )\n";
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
    std::cout << "...EVT...\n";
    //////// les evenements claviers de l'interface ////////
    traiter_evenements_clavier( evenement );

    //////// les evenements souris des gadgets ////////
    // On cherche un gadget survolé
    Gadget::ptr     gdgtSurvole     = chercherSurvol();


    if ( gdgtSurvole != nullptr  ) {
//        std::cout << "SURVOL!!!!!\n";
        gdgtSurvole->setSurvol ( true );
        if ( m_gdgtSurvole != gdgtSurvole &&  m_gdgtSurvole != nullptr )
            m_gdgtSurvole->setSurvol ( false );
    } else {
//        std::cout << "RIEN\n";
        if ( m_gdgtSurvole != nullptr )
            m_gdgtSurvole->setSurvol ( false );
    }

    // On actualise le ptr vers le bouton survolé
    m_gdgtSurvole = gdgtSurvole;

}

/////////////////////////////////////////////////
Interface::~Interface ()
{

}


/////////////////////////////////////////////////
Gadget::ptr Interface::chercherSurvol ()
{

    sf::Vector2i    positionSouris  = sf::Mouse::getPosition( *getFenetreSFML () );
    Gadget::ptr     result          = nullptr;

    for ( auto gadget : m_conteneur->getEnfants () )
        if ( gadget->testerSurvol ( positionSouris ) )
            result = gadget;

    return result;

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
//   std::cout << " Interface::draw\n";

    // On dessine chaques composants
    m_conteneur->draw ( target , states );

}


} // fin namespace gui

