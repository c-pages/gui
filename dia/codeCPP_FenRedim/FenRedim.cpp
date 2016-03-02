/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <FenRedim.h>

#include <FenSimple.h>


namespace gui {

/////////////////////////////////////////////////
FenRedim::FenRedim ()
: m_btn_gauche ( std::make_shared<BtnRectangle>() )
, m_btn_droite ( std::make_shared<BtnRectangle>() )
, m_btn_hautGauche ( std::make_shared<BtnRectangle>() )
, m_btn_hautDroite ( std::make_shared<BtnRectangle>() )
, m_btn_basGauche ( std::make_shared<BtnRectangle>() )
, m_btn_basDroite ( std::make_shared<BtnRectangle> )
, m_btn_haut ( std::make_shared<BtnRectangle>() )
, m_btn_bas ( std::make_shared<BtnRectangle>() )
{
    
}


/////////////////////////////////////////////////
void FenRedim::draw (sf::RenderTarget& target, sf::RenderStates states) const
{
    
}


} // fin namespace gui

