/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <iostream>

#include <Gadget.h>
#include <Skin.h>


namespace gui {

/////////////////////////////////////////////////
Gadget::Gadget ()
: m_visible     ( true )
, m_actif       ( true )
, m_focus       ( false )
, m_survol      ( false )
, m_presse      ( false )
, m_deplacable  ( false )
, m_skin        ( nullptr )
{
//    std::cout << "Creation d'un gadget\n    ";
}


/////////////////////////////////////////////////
Gadget::~Gadget ()
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
    ActionClavier::traiterEvenementsClavier( evenement );
}


/////////////////////////////////////////////////
bool Gadget::estActif () const
{
    return m_actif;
}


/////////////////////////////////////////////////
bool Gadget::estVisible () const
{
    return m_visible;
}


/////////////////////////////////////////////////
bool Gadget::aLeFocus () const
{
    return m_focus;
}


/////////////////////////////////////////////////
bool Gadget::estSurvole () const
{
    return m_survol;
}


/////////////////////////////////////////////////
bool Gadget::estPresse () const
{
    return m_presse;
}


/////////////////////////////////////////////////
bool Gadget::estDeplacable () const
{
    return m_deplacable;
}


} // fin namespace gui

