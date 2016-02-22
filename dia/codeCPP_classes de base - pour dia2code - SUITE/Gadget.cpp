/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Gadget.h>



namespace gui {

/////////////////////////////////////////////////
Gadget::Gadget ()
: m_actif ( true )
, m_visible ( true )
, m_focus ( false )
, m_survol ( false )
, m_presse ( false )
, m_deplacable ( false )
, friend class (  )
{
    
}


/////////////////////////////////////////////////
Gadget::~Gadget ()
{
    
}


/////////////////////////////////////////////////
Gadget::Gadget (Gadget & original)
: m_actif ( true )
, m_visible ( true )
, m_focus ( false )
, m_survol ( false )
, m_presse ( false )
, m_deplacable ( false )
, friend class (  )
{
    
}


/////////////////////////////////////////////////
Gadget& Gadget::operator= (Gadget & original)
{
    
}


/////////////////////////////////////////////////
void Gadget::actualiser (sf::Time deltaTemps)
{
    
}


/////////////////////////////////////////////////
void Gadget::traiter_events (const sf::Event& evenement)
{
    
}


/////////////////////////////////////////////////
void Gadget::actualiser ()
{
    
}


} // fin namespace gui

