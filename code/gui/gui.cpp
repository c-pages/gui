#include "gui.h"


#include <iostream>


namespace gui {

/////////////////////////////////////////////////
// Initialisation des membre static
/////////////////////////////////////////////////
Gadget * Gadget::ms_racineCourante = nullptr;



/////////////////////////////////////////////////
Interface::Interface()
{
    Gadget::ms_racineCourante = this;
}

/////////////////////////////////////////////////
void Interface::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (auto enfant : m_enfants )
    {
        target.draw(*enfant, states);
    }
}


} // fin namespace
