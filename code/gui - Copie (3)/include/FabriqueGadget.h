#ifndef FABRIQUEGADGET__H
#define FABRIQUEGADGET__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
//#include "Gui.h"
#include "Gadget.h"
#include <memory>


namespace gui {

class Gui;


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
    FabriqueGadget ( std::shared_ptr<Gui> gui );
    FabriqueGadget (  );

    Gadget::ptr texte ();

    Gadget::ptr image ();

    Gadget::ptr bouton ( std::string texte = "Bouton" );

private:
    std::shared_ptr<Gui>   m_gui;
}; // fin class FabriqueGadget

} // fin namespace gui

#endif
