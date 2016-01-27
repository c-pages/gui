/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Conteneur.h>

#include <Gadget.h>
#include <Repartiteur.h>
#include <iostream>

namespace gui {

/////////////////////////////////////////////////
void Conteneur::supprimerEnfant (Gadget::ptr enfant)
{

}


/////////////////////////////////////////////////
void Conteneur::mettreAuDessusEnfant (Gadget::ptr enfant)
{

}


/////////////////////////////////////////////////
void Conteneur::focus (const Gadget::ptr& enfant)
{

}


/////////////////////////////////////////////////
void Conteneur::focus_EnfantSuivant ()
{

}


/////////////////////////////////////////////////
void Conteneur::focus_enfantPrecedant ()
{

}


/////////////////////////////////////////////////
void Conteneur::focus_aucunEnfant ()
{

}


/////////////////////////////////////////////////
void Conteneur::decocherBoutonsRadio ()
{

}


/////////////////////////////////////////////////
void Conteneur::draw_enfants (sf::RenderTarget& target, sf::RenderStates states) const
{
    // Dessiner chacun des enfants
    for ( Gadget::ptr enfant : m_enfants )
        enfant->draw ( target, states );
}


/////////////////////////////////////////////////
void Conteneur::draw (sf::RenderTarget& target, sf::RenderStates states) const
{
//    std::cout << "Conteneur::draw()\n";
    // Dessiner les enfants du conteneur
    draw_enfants ( target , states ) ;
}


} // fin namespace gui

