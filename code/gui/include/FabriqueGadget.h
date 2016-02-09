#ifndef FABRIQUEGADGET__H
#define FABRIQUEGADGET__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
//#include "Gui.h"
#include "Gadget.h"
#include <memory>


namespace gui {

class Interface;


/////////////////////////////////////////////////
/// \brief Fonctions de creation des gadgets.
///
/////////////////////////////////////////////////
class FabriqueGadget {

//class Gadget;



/////////////////////////////////////////////////
// M�thodes
/////////////////////////////////////////////////
public:
    FabriqueGadget ( Interface* gui );
    FabriqueGadget (  );

    void setInterface ( Interface* interface ){
        m_interface = interface;
    };

    Gadget::ptr texte ();

    Gadget::ptr image ();

    Gadget::ptr bouton ( std::string texte = "Bouton" );

private:
    Interface*   m_interface;
}; // fin class FabriqueGadget

} // fin namespace gui

#endif
