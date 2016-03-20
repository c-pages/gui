#ifndef BTNTEXTE__H
#define BTNTEXTE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "BtnRectangle.h"

#include "gadgets_interfaces/composants/CmpTexte.h"

#include "gadgets\AffRectangle.h"
#include "gadgets\AffLabel.h"
#include <SFML/Graphics.hpp>



namespace gui {


/////////////////////////////////////////////////
/// \brief Un simple bouton rectangulaire
///
/////////////////////////////////////////////////
class BtnTexte : public BtnRectangle , public CmpTexte {



/////////////////////////////////////////////////
// M�thodes
/////////////////////////////////////////////////
public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par d�faut.
    ///
    /////////////////////////////////////////////////
    BtnTexte ();

    /////////////////////////////////////////////////
    virtual void actualiserGeometrie ();

    /////////////////////////////////////////////////
    virtual void actualiserStyle ();

}; // fin class BtnTexte

} // fin namespace gui

#endif // BTNRECTANGLE__H
























