#ifndef BOUTONINV__H
#define BOUTONINV__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Bouton.h"



namespace gui {



/////////////////////////////////////////////////
/// \brief Un simple bouton rectangulaire invisible.
///
/////////////////////////////////////////////////
class BoutonInv : public gui::Bouton {



/////////////////////////////////////////////////
// M�thodes
/////////////////////////////////////////////////
public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par d�faut.
    ///
    /////////////////////////////////////////////////
    BoutonInv ();

    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;


}; // fin class BoutonInv

} // fin namespace gui

#endif
