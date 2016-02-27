/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <DnBarreDefilement.h>



namespace gui {

/////////////////////////////////////////////////
DnBarreDefilement::DnBarreDefilement ()
: m_horizontal (  )
, m_slider ( std::make_shared<DnSlider> )
, m_btnPlus ( std::make_shared<BtnRectangle> )
, m_btnMoins ( std::make_shared<BtnRectangle> )
{
    
}


/////////////////////////////////////////////////
void DnBarreDefilement::actualiser ()
{
    
}


/////////////////////////////////////////////////
void DnBarreDefilement::draw (sf::RenderTarget& target, sf::RenderStates states) const
{
    
}


} // fin namespace gui

