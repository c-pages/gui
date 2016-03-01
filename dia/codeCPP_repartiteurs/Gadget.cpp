/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Gadget.h>

#include <Skin.h>


namespace gui {

/////////////////////////////////////////////////
Gadget::Gadget ()
: m_visible ( true )
, m_actif ( true )
, m_focus ( false )
, m_survol ( false )
, m_presse ( false )
, m_deplacable ( false )
, m_skin ( std::make_shared<Skin>() )
{
    
}


/////////////////////////////////////////////////
Gadget::~Gadget ()
{
    
}


/////////////////////////////////////////////////
Gadget::Gadget (Gadget & original)
: m_visible ( true )
, m_actif ( true )
, m_focus ( false )
, m_survol ( false )
, m_presse ( false )
, m_deplacable ( false )
, m_skin ( std::make_shared<Skin>() )
{
    
}


/////////////////////////////////////////////////
Gadget& Gadget::operator= (Gadget & original)
{
    
}


/////////////////////////////////////////////////
void Gadget::actualiser ()
{
    
}


/////////////////////////////////////////////////
void Gadget::actualiser (sf::Time deltaTemps)
{
    
}


/////////////////////////////////////////////////
void Gadget::traiterEvenements (const sf::Event& evenement)
{
    
}


/////////////////////////////////////////////////
bool Gadget::estActif () const
{
    
}


/////////////////////////////////////////////////
bool Gadget::estVisible () const
{
    
}


/////////////////////////////////////////////////
bool Gadget::aLeFocus () const
{
    
}


/////////////////////////////////////////////////
bool Gadget::estSurvole () const
{
    
}


/////////////////////////////////////////////////
bool Gadget::estPresse () const
{
    
}


/////////////////////////////////////////////////
bool Gadget::estDeplacable () const
{
    
}


} // fin namespace gui

