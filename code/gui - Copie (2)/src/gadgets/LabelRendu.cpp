/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <LabelRendu.h>



namespace gui {

/////////////////////////////////////////////////
LabelRendu::LabelRendu (Gadget::ptr label)
: GadgetRendu ( label )
, m_texteCouleur ( sf::Color (255,255,255) )
//, m_label (  )
{

}


/////////////////////////////////////////////////
void LabelRendu::draw (sf::RenderTarget& target, sf::RenderStates states) const
{

}


} // fin namespace gui

