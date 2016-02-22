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
    setParent( nullptr );

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
    // dessiner tout les enfants
    for ( auto enfant : m_enfants)
        enfant->draw ( target, states );

}

/////////////////////////////////////////////////
void ConteneurGui::traiter_evenements( const sf::Event evenement )
{
    // dessiner tout les enfants
    for ( auto enfant : m_enfants)
        enfant->traiter_evenements( evenement );

}

} // fin namespace gui
