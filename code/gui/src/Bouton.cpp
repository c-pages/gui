/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Bouton.h>



namespace gui {

/////////////////////////////////////////////////
Bouton::Bouton ()
: m_autoAjust   ( false )
, m_marge       ( { 5 , 5 })
{

}


/////////////////////////////////////////////////
std::shared_ptr<Gadget>  Bouton::testerSurvol ( sf::Vector2i position )
{
//    std::cout << "Bouton : Tester survol\n";
    return Gadget::testerSurvol ( position );
}


} // fin namespace gui

