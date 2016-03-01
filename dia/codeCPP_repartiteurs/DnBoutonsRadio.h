#ifndef DNBOUTONSRADIO__H
#define DNBOUTONSRADIO__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Donnee.h"
#include <vector>
#include <memory>
#include "ElementMenu.h"



namespace gui {

class ElementMenu;


class DnBoutonsRadio : public gui::Donnee {



/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////

public:
public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /////////////////////////////////////////////////
    DnBoutonsRadio ();

    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;



/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
public:
    std::vector < ElementMenu > m_elements;    
    std::shared_ptr<gui::ElementMenu> ;

}; // fin class DnBoutonsRadio

} // fin namespace gui

#endif
