/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <iostream>
#include <sstream>

#include <Gadget.h>
#include <Skin.h>


namespace gui {

/////////////////////////////////////////////////
// Initialisation des membre static
/////////////////////////////////////////////////
Gadget *    Gadget::ms_racineCourante   = nullptr;
int         Gadget::ms_CompteurGadgets  = 0;


/////////////////////////////////////////////////
Gadget::Gadget ()
: m_texte       ( "" )
, m_visible     ( true )
, m_actif       ( true )
, m_focus       ( false )
, m_survol      ( false )
, m_presse      ( false )
, m_deplacable  ( false )
//, m_skin        ( std::make_shared<Skin>() )
, m_skin        ( nullptr )
, m_style       ( nullptr )
{

    if ( ms_racineCourante != nullptr )
        m_skin = ms_racineCourante->getSkin();
    else
        m_skin = std::make_shared<Skin>() ;

    // Mise a jour du nombre de gadget
    ms_CompteurGadgets++;

    // Creation du nom unique du gadget
    std::stringstream ss;
    ss << getNombreGadgets();
    m_nom = "Gadget_" + ss.str();

}


/////////////////////////////////////////////////
Gadget::~Gadget ()
{
    ms_CompteurGadgets--;
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


/////////////////////////////////////////////////
std::shared_ptr<Gadget>  Gadget::testerSurvol ( sf::Vector2i position ) {

//    std::cout << "Gadget : Tester survol\n";
    if ( m_globalBounds.contains( position.x, position.y ) && estActif() )
        return thisPtr();
    else
        return nullptr;

};
} // fin namespace gui

