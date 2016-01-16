/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Gadget.h>

#include <Theme.h>
#include <InfoBulle.h>
#include <MenuContextuel.h>
#include <Conteneur.h>
#include <Gadget.h>


namespace gui {

/////////////////////////////////////////////////
Gadget::Gadget ()
: m_focused ( false )
, m_visible ( true )
, m_actif ( true )
, m_draggable ( false )
, m_survol ( false )
, m_presse ( false )
, m_theme ( nullptr )
, m_infoBulle ( nullptr )
, m_menuContextuel ( nullptr )
, m_parent ( nullptr )
, m_gadgetRendu ( nullptr )
{
    
}


/////////////////////////////////////////////////
Gadget::Gadget (const Gadget& copy)
: m_focused ( false )
, m_visible ( true )
, m_actif ( true )
, m_draggable ( false )
, m_survol ( false )
, m_presse ( false )
, m_theme ( nullptr )
, m_infoBulle ( nullptr )
, m_menuContextuel ( nullptr )
, m_parent ( nullptr )
, m_gadgetRendu ( nullptr )
{
    
}


/////////////////////////////////////////////////
Gadget& Gadget::operator= (const Gadget& gadgetACopier)
{
    
}


/////////////////////////////////////////////////
void Gadget::supprimer ()
{
    
}


/////////////////////////////////////////////////
void Gadget::mettreAuDessus ()
{
    
}


/////////////////////////////////////////////////
void Gadget::demander_infoBulle ()
{
    
}


/////////////////////////////////////////////////
void Gadget::demander_menuContextuel ()
{
    
}


/////////////////////////////////////////////////
void Gadget::actualiser (sf::Time tempsEcoule)
{
    
}


/////////////////////////////////////////////////
void Gadget::setTexteInfoBulle (std::string texte)
{
    
}


} // fin namespace gui

