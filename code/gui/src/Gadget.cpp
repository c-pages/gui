/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <iostream>
#include <sstream>

#include <Gadget.h>
#include <Skin.h>
#include <Interface.h>


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
    // Si on a une racine active, on utilise son skin
    if ( ms_racineCourante != nullptr )
        m_skin = ms_racineCourante->getSkin();
    else
        m_skin = std::make_shared<Skin>() ;

    // Mise a jour du nombre de gadgets.
    ms_CompteurGadgets++;

    // Creation du nom unique du gadget
    std::stringstream ss;
    ss << getNombreGadgets();
    m_nom = "Gadget_" + ss.str();

}


/////////////////////////////////////////////////
Gadget::~Gadget ()
{
    // Mise a jour du nombre de gadgets.
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
    // les evenement claviers
    ActionClavier::traiterEvenementsClavier( evenement );

    // Les evenements des composants l'interface local
    traiterEvenementsComposants( evenement );

    // les evenements des enfants
    for (auto enfant : m_enfants)
        enfant->traiterEvenements ( evenement );

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
std::shared_ptr<Gadget>  Gadget::testerSurvol ( sf::Vector2i position )
{

    if ( m_globalBounds.contains( position.x, position.y ) && estActif() )
    {
        auto testInterfaceLocal = testerSurvolComposants( position );
        if ( testInterfaceLocal != nullptr )
            return testInterfaceLocal;
        else
            return thisPtr();
    }
    else
        return nullptr;

}

/////////////////////////////////////////////////
sf::Vector2i Gadget::getPosSouris ( ) {
    return Interface::getPosSouris();
};

/////////////////////////////////////////////////
sf::Vector2i Gadget::getLocalPosSouris ( ) {
    sf::Vector2i result = Interface::getPosSouris();
    result.x -= getPosAbs().x;
    result.y -= getPosAbs().y;
    return result;
};

/////////////////////////////////////////////////
void Gadget::draw (sf::RenderTarget& target, sf::RenderStates states) const
{
    if ( estVisible() ) {

        //On applique la transformation
        states.transform *= getTransform();

        dessinerComposant   ( target, states );
        dessinerEnfants     ( target, states );
    }
};

} // fin namespace gui

