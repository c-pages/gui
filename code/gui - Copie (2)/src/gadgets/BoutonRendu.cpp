/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <BoutonRendu.h>

#include <Label.h>


namespace gui {

/////////////////////////////////////////////////
BoutonRendu::BoutonRendu (Bouton::ptr bouton)
: GadgetRendu( bouton )
, m_label (  )
, m_rectangle (  )
, m_texteCouleurNormal ( sf::Color (255,255,255) )
, m_texteCouleurSurvole ( sf::Color (255,255,255) )
, m_texteCouleurPresse ( sf::Color (255,255,255) )
, m_fondCouleurNormal ( sf::Color (255,255,255) )
, m_fondCouleurSurvole ( sf::Color (255,255,255) )
, m_fondCouleurPresse ( sf::Color (255,255,255) )
, m_textureNormal ( nullptr )
, m_textureSurvol ( nullptr )
, m_texturePresse ( nullptr )
{

}


/////////////////////////////////////////////////
void BoutonRendu::draw (sf::RenderTarget& target, sf::RenderStates states) const
{

}


} // fin namespace gui

