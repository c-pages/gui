/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <SupFenetre.h>



namespace gui {

/////////////////////////////////////////////////
SupFenetre::SupFenetre ()
: m_titre ( std::make_shared<AffBarrTitre>() )
, m_btnFermer ( std::make_shared<BtnIcone>() )
, m_utiliserFermer ( true )
{
    
}


/////////////////////////////////////////////////
void SupFenetre::actualiser ()
{
    
}


/////////////////////////////////////////////////
void SupFenetre::draw (sf::RenderTarget& target, sf::RenderStates states) const
{
    
}


} // fin namespace gui

