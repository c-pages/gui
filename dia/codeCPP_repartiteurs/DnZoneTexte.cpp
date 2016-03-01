/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <DnZoneTexte.h>

#include <BtnRectangle.h>
#include <AffLabel.h>


namespace gui {

/////////////////////////////////////////////////
DnZoneTexte::DnZoneTexte ()
: m_bouton ( std::make_shared<BtnRectangle>() )
, m_label ( std::make_shared<AffLabel>() )
, m_ecritureActive ( false )
{
    
}


/////////////////////////////////////////////////
void DnZoneTexte::actualiser ()
{
    
}


/////////////////////////////////////////////////
void DnZoneTexte::draw (sf::RenderTarget& target, sf::RenderStates states) const
{
    
}


} // fin namespace gui

