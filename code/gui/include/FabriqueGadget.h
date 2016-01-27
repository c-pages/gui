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
// Méthodes
/////////////////////////////////////////////////
public:
    FabriqueGadget ( std::shared_ptr<Interface> gui );
    FabriqueGadget (  );

    Gadget::ptr texte ();

    Gadget::ptr image ();

    Gadget::ptr bouton ( std::string texte = "Bouton" );

private:
    std::shared_ptr<Interface>   m_interface;
}; // fin class FabriqueGadget

} // fin namespace gui

#endif
