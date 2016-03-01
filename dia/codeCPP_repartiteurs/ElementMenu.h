#ifndef ELEMENTMENU__H
#define ELEMENTMENU__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <memory>
#include <functional>



namespace gui {

class Gadget;


struct ElementMenu {
    std::string nom;
    FctnAction fonction;
    std::shared_ptr<Gadget> bouton;
};

} // fin namespace gui

#endif
