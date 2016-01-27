/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <ConteneurGui.h>

#include <iostream>


namespace gui {


/////////////////////////////////////////////////
ConteneurGui::ConteneurGui()
: Gadget()
{
    std::cout << "Creation ConteneurGui\n";

}


/////////////////////////////////////////////////
void ConteneurGui::actualiser( sf::Time delta )
{
    for ( auto enfant : m_enfants)
        enfant->actualiser(delta);
}

/////////////////////////////////////////////////
void ConteneurGui::draw (sf::RenderTarget& target, sf::RenderStates states ) const
{
    std::cout << "ConteneurGui draw\n";

    for ( auto enfant : m_enfants)
        enfant->draw ( target, states );
}


} // fin namespace gui
