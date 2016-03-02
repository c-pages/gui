/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <FenSimple.h>



namespace gui {

/////////////////////////////////////////////////
FenSimple::FenSimple ()
: m_titre ( std::make_shared<AffBarrTitre>() )
, m_btnFermer ( std::make_shared<BtnIcone>() )
, m_utiliserFermer ( true )
{
    
}


/////////////////////////////////////////////////
void FenSimple::actualiser ()
{
    
}


/////////////////////////////////////////////////
void FenSimple::draw (sf::RenderTarget& target, sf::RenderStates states) const
{
    
}


} // fin namespace gui

