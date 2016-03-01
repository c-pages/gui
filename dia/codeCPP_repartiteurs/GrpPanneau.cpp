/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <GrpPanneau.h>

#include <AffRectangle.h>
#include <AffRectangle.h>
#include <Repartiteur.h>


namespace gui {

/////////////////////////////////////////////////
GrpPanneau::GrpPanneau ()
: m_fond ( std::make_shared_ptr<AffRectangle>() )
, m_slider_V ( std::make_shared<BtnBarreDefilement> )
, m_slider_H ( std::make_shared<BtnBarreDefilement> )
, m_contenant ( std::make_shared_ptr<AffRectangle>() )
, m_contenu (  )
, m_repartiteur (  )
, m_afficherSlider_V ( true )
, m_afficherSlider_H ( true )
{
    
}


/////////////////////////////////////////////////
GrpPanneau::setRepart (Repartition repartition)
{
    
}


/////////////////////////////////////////////////
void GrpPanneau::actualiser ()
{
    
}


/////////////////////////////////////////////////
void GrpPanneau::draw (sf::RenderTarget& target, sf::RenderStates states) const
{
    
}


} // fin namespace gui

