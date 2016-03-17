/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <iostream>
#include <sstream>

#include <Gadget.h>
#include <Interface.h>
#include <../GUI.h>

namespace gui {

/////////////////////////////////////////////////
// Initialisation des membre static
/////////////////////////////////////////////////

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
, m_aBesoinActuaBounds      ( true )

, m_etat        ( Etat::repos )
{

    // Mise a jour du nombre de gadgets.
    ms_CompteurGadgets++;

    // l'ID unique du gadget
    m_id = ms_CompteurGadgets;

    // Creation du nom unique du gadget
    creerNomUnique( "Gadget" );

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

    // on actualise les bounds si besoin
    if ( m_aBesoinActuaBounds )  {
        actualiserBounds ();
        m_aBesoinActuaBounds = false;
    }

    // on envois le message aux enfants
    actualiserEnfants();

    // on envois le message aux composants
    actualiserComposants();

    // on s'occupe des trucs a supprimer des listes a vider pis tous
    actualiserListes ( );

    // on a plus besoin d'actualisation
    m_aBesoinActualisation = false;
}


/////////////////////////////////////////////////
void Gadget::actualiser ( sf::Time deltaTemps )
{
    if ( m_aBesoinActualisation )
        actualiser();

    actualiserEnfants ( deltaTemps );
}


/////////////////////////////////////////////////
void Gadget::traiterEvenements (const sf::Event& evenement)
{
    // les evenement claviers
    ActionClavier::traiterEvenementsClavier( evenement );

    // Les evenements des composants l'interface local
    traiterEvenementsComposants( evenement );

    // la meme chose pour les enfants
    for (auto enfant : m_enfants)
        enfant->traiterEvenements ( evenement );
}



/////////////////////////////////////////////////
std::shared_ptr<Gadget>  Gadget::testerSurvol ( sf::Vector2i position )
{
    // Si on survol pas le gadget on sort
    if ( ! m_globalBounds.contains( position.x, position.y ) && estActif() ) return nullptr;

    // On test le survol des composants
    auto testInterfaceLocal = testerSurvolComposants( position );
    if ( testInterfaceLocal != nullptr )
        return testInterfaceLocal;

    // On test le survol des enfants
    auto testEnfants = testerSurvolEnfants( position );
    if ( testEnfants != nullptr )
        return testEnfants;

    // si on a rien survolé on renvois nous-même
    else  return thisPtr();
}

/////////////////////////////////////////////////
void Gadget::draw (sf::RenderTarget& target, sf::RenderStates states) const
{
    if ( ! estVisible() ) return;

    //On applique la transformation
    states.transform *= getTransform();

    dessinerComposant   ( target, states );
    dessinerEnfants     ( target, states );
};





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
// les demandes d'actualisations
/////////////////////////////////////////////////

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
    m_aBesoinActuaBounds = true ;
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
void Gadget::demanderActuaBounds() {
    m_aBesoinActualisation = true ;
    m_aBesoinActuaBounds = true ;
    Interface::aBesoinActualisation();
};





/////////////////////////////////////////////////
// les accesseurs et mutateurs
/////////////////////////////////////////////////

/////////////////////////////////////////////////
void Gadget::setVisible( bool val ) {
//    log("setVisible");
//    log("m_visible", val);
    m_visible = val;
};


/////////////////////////////////////////////////
void Gadget::setActif( bool val ){
    if ( m_actif == val ) return;

//    log("setActif");
//    log("m_actif", val);

    m_actif = val;
    actualiserEtat ();
    demanderActuaStyle();
};


/////////////////////////////////////////////////
void Gadget::setFocus( bool val ) {
    if ( m_focus == val ) return;

//    log("setFocus");
//    log("m_focus", val);

    m_focus = val;
    actualiserEtat ();
    demanderActuaStyle();
};


/////////////////////////////////////////////////
void Gadget::setSurvol( bool val ) {
    if ( m_survol == val ) return;

//    log("setSurvol");
//    log("m_survol", val);

    m_survol = val;
    actualiserEtat ();
    demanderActuaStyle();
};


/////////////////////////////////////////////////
void Gadget::setPresse( bool val ){
    if ( m_presse == val ) return;
//    log("setPresse");
//    log("m_presse", val);
    m_presse = val;
    actualiserEtat ();
    demanderActuaStyle();
};


/////////////////////////////////////////////////
void Gadget::setDeplacable( bool val ){
    m_deplacable = val;
};


/////////////////////////////////////////////////
void Gadget::creerNomUnique( std::string type  ) {
    // Creation du nom unique du gadget
    std::stringstream ss;
    ss << m_id;
    m_nom = type + "_" + ss.str();
};


/////////////////////////////////////////////////
bool Gadget::estActif () const{
    return m_actif;
}


/////////////////////////////////////////////////
bool Gadget::estVisible () const{
    return m_visible;
}


/////////////////////////////////////////////////
bool Gadget::aLeFocus () const{
    return m_focus;
}


/////////////////////////////////////////////////
bool Gadget::estSurvole () const{
    return m_survol;
}


/////////////////////////////////////////////////
bool Gadget::estPresse () const{
    return m_presse;
}


/////////////////////////////////////////////////
bool Gadget::estDeplacable () const{
    return m_deplacable;
}


/////////////////////////////////////////////////
std::string Gadget::getNom() const {
    return m_nom;
}

/////////////////////////////////////////////////
void        Gadget::setNom( std::string nom ) {
    m_nom = nom;
}

/////////////////////////////////////////////////
unsigned int Gadget::getID() const {
    return m_id;
}

/////////////////////////////////////////////////
int          Gadget::getNombreGadgets () const{ return ms_CompteurGadgets; };

/////////////////////////////////////////////////
void        Gadget::setTexte( std::string val ){
    log("setTexte \"" + val + "\"" );
    m_texte = val;
    demanderActuaGeom();
};

/////////////////////////////////////////////////
std::string  Gadget::getTexte( ) const{
    return m_texte;
};

/////////////////////////////////////////////////
void            Gadget::setMarge ( sf::Vector2f marge ){
    m_marge = marge;
    demanderActuaGeom();
};

/////////////////////////////////////////////////
void            Gadget::setMarge ( float val ){
    m_marge = { val , val };
    demanderActuaGeom();
};

/////////////////////////////////////////////////
void            Gadget::setMarge ( float x , float y ){
    m_marge = { x , y };
    demanderActuaGeom();
};
/////////////////////////////////////////////////
sf::Vector2f    Gadget::getMarge(){
    return m_marge;
};



} // fin namespace gui






















