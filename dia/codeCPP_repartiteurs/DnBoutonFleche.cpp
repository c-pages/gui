/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <DnBoutonFleche.h>

#include <DnZoneTexte.h>
#include <BtnRectangle.h>
#include <BtnRectangle.h>


namespace gui {

/////////////////////////////////////////////////
DnBoutonFleche::DnBoutonFleche ()
: m_zoneTexte ( std::make_shared<DnZoneTexte>() )
, m_btnHaut (  )
, m_btnBas (  )
, m_minimum ( 0 )
, m_maximum ( 100 )
, m_courant ( 10 )
{
    
}


/////////////////////////////////////////////////
void DnBoutonFleche::actualiser ()
{
    
}


/////////////////////////////////////////////////
void DnBoutonFleche::draw (sf::RenderTarget& target, sf::RenderStates states) const
{
    
}


} // fin namespace gui

