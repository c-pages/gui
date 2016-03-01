/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Bouton.h>



namespace gui {

//std::vector<std::shared_ptr<Gadget>>     Bouton::ms_boutons = {};
std::vector<Gadget*>     Bouton::ms_boutons = {};


/////////////////////////////////////////////////
Bouton::Bouton ()
: m_autoAjust   ( false )
{
    m_marge       = { 5 , 5 } ;
//
//    // on l'ajoute à la liste static des boutons

    ms_boutons.push_back( this );
//
//    std::cout << "AJouter un bouton à la liste glbal : "<< ms_boutons.size() << "\n";
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
//    std::cout << "Bouton : Tester survol : " << Gadget::testerSurvol ( position ) << "\n";
    return Gadget::testerSurvol ( position );
}


} // fin namespace gui

