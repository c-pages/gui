/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "gadgets_interfaces/Bouton.h"



namespace gui {

std::vector<Gadget*>     Bouton::ms_boutons = {};


/////////////////////////////////////////////////
Bouton::Bouton ()
: m_autoAjust   ( true )
{
    m_marge       = { 5 , 5 } ;

    // on l'ajoute à la liste static des boutons
    ms_boutons.push_back( this );
}

/////////////////////////////////////////////////
Bouton::~Bouton ()
{
    // on le retire de la liste static des boutons
    int i = 0;
    for ( auto bouton : ms_boutons ){
        if ( bouton == this ){
            ms_boutons.erase( ms_boutons.begin()+ i );
            return;
        }
        i++;
    }
}


/////////////////////////////////////////////////
std::shared_ptr<Gadget>  Bouton::testerSurvol ( sf::Vector2i position )
{
//    log( "Tester survol" );
//    log( "survol" , Gadget::testerSurvol ( position ) != nullptr );

    return Gadget::testerSurvol ( position );
}


} // fin namespace gui

