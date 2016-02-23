#ifndef __GUI_H__
#define __GUI_H__


#include "Gadget.h"
#include "FabriqueBase.h"


namespace gui {

/////////////////////////////////////////////////
/// \brief Classe communes à tout les gadgets, gère affichage actualisation, etc...
///
/////////////////////////////////////////////////
class Interface : public Gadget{
public:
    Interface();

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;


public:
/////////////////////////////////////////////////
// membres
/////////////////////////////////////////////////
    FabriqueBase    creer;      ///< La fabrique de gadget de base (GOF: Fabrique)


}; // fin class gui

}; // fin namespace gui

#endif // __GUI_H__
