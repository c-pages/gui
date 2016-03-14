#ifndef LSTSIMPLE__H
#define LSTSIMPLE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Liste.h"
#include <memory>



namespace gui {



class LstSimple : public gui::Liste {



/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////

public:
public:
    virtual void actualiserGeometrie ();

    virtual void actualiserStyle ();

    void draw (sf::RenderTarget& target, sf::RenderStates states) const;



/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:
    std::shared_ptr<BtnMenu> m_menu;    

}; // fin class LstSimple

} // fin namespace gui

#endif
