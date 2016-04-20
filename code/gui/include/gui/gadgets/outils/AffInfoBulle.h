#ifndef AFFINFOBULLE__H
#define AFFINFOBULLE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////

#include "interfaces/gadgets/Affiche.h"


#include <memory>
#include <iostream>
#include <SFML/Graphics.hpp>


#include "interfaces/composants/CmpTexte.h"
#include "interfaces/composants/CmpFond.h"
#include "interfaces/composants/CmpOmbre.h"

namespace gui {



/////////////////////////////////////////////////
/// \brief Classe concr�te d'affichage d'un simple texte.
///
/////////////////////////////////////////////////
class AffInfoBulle :  public Affiche
                    , public CmpTexte
                    , public CmpFond
                    , public CmpOmbre
{


/////////////////////////////////////////////////
// M�thodes
/////////////////////////////////////////////////

public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par d�faut.
    ///
    /////////////////////////////////////////////////
    AffInfoBulle ();

    /////////////////////////////////////////////////
    virtual void actualiserGeometrie ();

    /////////////////////////////////////////////////
    virtual void actualiserStyle ();



/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:



}; // fin class AffInfoBulle

} // fin namespace gui

#endif