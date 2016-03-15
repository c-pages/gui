#include "Calque.h"

namespace gui {

Calque::Calque( std::string nom )
{
    //creerNomUnique( "Calque");
    m_nom = nom;
    //ctor
}

Calque::~Calque()
{
    //dtor
}

/////////////////////////////////////////////////
void Calque::actualiser ()
{
    actualiserEnfants();
}

/////////////////////////////////////////////////
std::shared_ptr<Gadget>  Calque::testerSurvol ( sf::Vector2i position )
{

/*
    std::cout << "m_globalBounds : "    << m_globalBounds.left << ", "
                                        << m_globalBounds.top << ", "
                                        << m_globalBounds.width << ", "
                                        << m_globalBounds.height << "\n";*/
//    // Si on survol le gadget
//    if ( m_globalBounds.contains( position.x, position.y ) && estActif() )
//    {
        // On test le survol des enfants
        auto testEnfants = testerSurvolEnfants( position );
        if ( testEnfants != nullptr )
            return testEnfants;
        else  return nullptr;
//    }
//    else
//        return nullptr;

}


}
//
