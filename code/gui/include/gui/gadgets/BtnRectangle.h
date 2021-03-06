#ifndef BTNRECTANGLE__H
#define BTNRECTANGLE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////

#include "interfaces/gadgets/Bouton.h"
#include "interfaces/composants/CmpFond.h"

#include "Valeurs.h"
#include "gadgets\AffRectangle.h"
#include "gadgets\AffLabel.h"

#include <SFML/Graphics.hpp>



namespace gui {


/////////////////////////////////////////////////
/// \brief Un simple bouton rectangulaire
///
/////////////////////////////////////////////////
class BtnRectangle  : public Bouton
                    , public CmpFond
                    {


/////////////////////////////////////////////////
// M�thodes
/////////////////////////////////////////////////
public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par d�faut.
    ///
    /////////////////////////////////////////////////
    BtnRectangle ();

    /////////////////////////////////////////////////
    virtual void actualiserGeometrie ();

    /////////////////////////////////////////////////
    virtual void actualiserStyle ();



}; // fin class BtnRectangle

} // fin namespace gui

#endif // BTNRECTANGLE__H





















