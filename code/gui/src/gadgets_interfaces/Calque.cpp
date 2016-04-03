#include "gadgets_interfaces/Calque.h"

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

    // On test le survol des enfants
    auto testEnfants = testerSurvolEnfants( position );
    if ( testEnfants != nullptr )
        return testEnfants;
    else  return nullptr;

}


}
//
