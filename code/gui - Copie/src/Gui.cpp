/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Gui.h>

#include <Gadget.h>
#include <Theme.h>
#include <Conteneur.h>
#include <Gadget.h>


namespace gui {

/////////////////////////////////////////////////
Gui::Gui (sf::RenderTarget* fenetre)
: creer (  )
, m_theme ( nullptr )
, m_fenetre ( 0 )
, m_conteneur ( std::make_shared<ConteneurGui>() )
, m_tempsPourAfficherInfoBulle ( sf::milliseconds(500) )
, m_tempsDoubleClique ( sf::milliseconds(500) )
, m_infoBulleVisible ( nullptr )
{

}


/////////////////////////////////////////////////
void Gui::actualiser ()
{

}


/////////////////////////////////////////////////
void Gui::draw (sf::RenderTarget& target, sf::RenderStates states) const
{

}


/////////////////////////////////////////////////
void Gui::ajouter (Gadget::ptr enfant)
{

}


/////////////////////////////////////////////////
void Gui::retirer (Gadget::ptr enfant)
{

}


/////////////////////////////////////////////////
void Gui::vider ()
{

}


} // fin namespace gui

