/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <iostream>
#include <sstream>

#include <Gadget.h>
//#include <Skin.h>
#include <Interface.h>
#include <../GUI.h>



namespace gui {






/////////////////////////////////////////////////
// Initialisation des membre static
/////////////////////////////////////////////////
//Gadget *    Gadget::ms_racineCourante   = nullptr;
int         Gadget::ms_CompteurGadgets  = 0;
std::string Gadget::ms_logNomGadgetBack = "";

/////////////////////////////////////////////////
Gadget::Gadget ()
: m_texte       ( "" )
, m_visible     ( true )
, m_actif       ( true )
, m_focus       ( false )
, m_survol      ( false )
, m_presse      ( false )
, m_deplacable  ( false )
, m_redimensionnable ( false )

, m_aBesoinActualisation    ( true )
, m_aBesoinActuaGeom        ( true )
, m_aBesoinActuaStyle       ( true )
, m_aBesoinActuaContenu     ( true )

//, m_skin        ( std::make_shared<Skin>() )
//, m_skin        ( nullptr )
//, m_style       ( std::make_shared<Style>() )
//, m_style       ( nullptr )
//, m_demanderActualisation ( false )
, m_etat        ( Etat::repos )
{

    // Si on a une racine active, on utilise son skin
//    if ( ms_racineCourante != nullptr )
//        m_skin = ms_racineCourante->getSkin();
//    else
//        m_skin = std::make_shared<Skin>() ;

    // Mise a jour du nombre de gadgets.
    ms_CompteurGadgets++;

    // Creation du nom unique du gadget
    creerNom( "Gadget" );
//    std::stringstream ss;
//    ss << getNombreGadgets();
//    m_nom = "Gadget_" + ss.str();
}


/////////////////////////////////////////////////
void Gadget::creerNom( std::string type  ) {
    // Creation du nom unique du gadget
    std::stringstream ss;
    ss << getNombreGadgets();
    m_nom = type + "_" + ss.str();
};


/////////////////////////////////////////////////
void Gadget::demanderActualisation() {
    m_aBesoinActualisation = true ;
    m_aBesoinActuaGeom = true ;
    m_aBesoinActuaStyle = true ;
    m_aBesoinActualisation = true ;
    Interface::aBesoinActualisation();
};

/////////////////////////////////////////////////
void Gadget::demanderActuaGeom() {
    m_aBesoinActualisation = true ;
    m_aBesoinActuaGeom = true ;
    Interface::aBesoinActualisation();
};
/////////////////////////////////////////////////
void Gadget::demanderActuaStyle() {
    m_aBesoinActualisation = true ;
    m_aBesoinActuaStyle = true ;
    Interface::aBesoinActualisation();
};
/////////////////////////////////////////////////
void Gadget::demanderActuaContenu() {
    m_aBesoinActualisation = true ;
    m_aBesoinActuaContenu = true ;
    Interface::aBesoinActualisation();
};
/////////////////////////////////////////////////
Gadget::~Gadget ()
{
    // Mise a jour du nombre de gadgets.
    ms_CompteurGadgets--;
}

/*
/////////////////////////////////////////////////
int Gadget::log_getCurseurPosX ( )
{
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbiInfo);
    return csbiInfo.dwCursorPosition.Y;


//
//    COORD coord;
//
//    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
//    if (console == INVALID_HANDLE_VALUE)
//    {
//        printf("GetStdHandle failed with %d\n", GetLastError());
//        return {0,0};
//    }
//    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
//    if (  GetConsoleScreenBufferInfo(console, &csbiInfo) )
//    {
//        coord = csbiInfo.dwCursorPosition;
//        int x = coord.X;
//        return {0,0};
////        log ("POS CURSEUR" );
////        sf::Vector2f pos = {csbiInfo.dwCursorPosition.X , csbiInfo.dwCursorPosition.Y };
////        log ("POS CURSEUR", pos );
//    }
////        log ("POS CURSEUR", sf::Vector2f( csbiInfo.dwCursorPosition.X , csbiInfo.dwCursorPosition.Y ) );
//
////    return { coord.X , coord.Y };
////    log ("POS CURSEUR", pos );
//

}*/








/////////////////////////////////////////////////
void Gadget::actualiser ()
{



    // si on a pas besoin d'actualiser
    if ( ! m_aBesoinActualisation )
    {
        // on envois le message aux enfants
        actualiserEnfants();
        // on envois le message aux composants
        actualiserComposants();
        return;
    }

    logTitre ( "Actualiser"  );

    // on actualise le style si besoin
    if ( m_aBesoinActuaStyle )  {
        actualiserStyle ();
        m_aBesoinActuaStyle = false;
    }
    // on actualise les geometrie si besoin
    if ( m_aBesoinActuaGeom )   {
        actualiserGeometrie ();
        m_aBesoinActuaGeom = false;
    }
    // on actualise le contenu si besoin
    if ( m_aBesoinActuaContenu )  {
        actualiserContenu ();
        m_aBesoinActuaContenu = false;
    }

    // on envois le message aux enfants
    actualiserEnfants();
    // on envois le message aux composants
    actualiserComposants();

    actualiserBounds();

    m_aBesoinActualisation = false;

}


/////////////////////////////////////////////////
void Gadget::actualiser (sf::Time deltaTemps)
{

    if ( m_aBesoinActualisation )
    {
        actualiser();
    }

    for ( auto enfant : m_enfants )
        enfant->actualiser (deltaTemps);

}


/////////////////////////////////////////////////
void Gadget::traiterEvenements (const sf::Event& evenement)
{
    // les evenement claviers
    ActionClavier::traiterEvenementsClavier( evenement );

    // Les evenements des composants l'interface local
    traiterEvenementsComposants( evenement );

    //
    actualiserListes ( );

    // la meme chose pour les enfants
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
    ///<\todo... a voir si on peut se passer de faire l'actualisation a chaque fois ...(pour l'instant sans ca, ca pose problème a bouton dans fenentre)
//    actualiserBounds();

    // Si on survol le gadget
    if ( m_globalBounds.contains( position.x, position.y ) && estActif() )
    {
        // On test le survol des composants
        auto testInterfaceLocal = testerSurvolComposants( position );
        if ( testInterfaceLocal != nullptr )
            return testInterfaceLocal;
        // On test le survol des enfants
        else
        {
            auto testEnfants = testerSurvolEnfants( position );
            if ( testEnfants != nullptr )
                return testEnfants;
            else  return thisPtr();
        }
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

