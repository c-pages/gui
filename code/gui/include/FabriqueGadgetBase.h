#ifndef FABRIQUEGADGETBASE__H
#define FABRIQUEGADGETBASE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Gadget.h"


namespace gui {



/////////////////////////////////////////////////
/// \brief la fabrique de gadget (GOF4)
///
/////////////////////////////////////////////////
class FabriqueGadgetBase {



/////////////////////////////////////////////////
// M�thodes
/////////////////////////////////////////////////
public:
    /////////////////////////////////////////////////
    /// \brief Creer un bouton.
    ///
    /// \param texte		 Le texte du bouton.
    /////////////////////////////////////////////////
    Gadget::ptr bouton (std::string texte = "");

    /////////////////////////////////////////////////
    /// \brief Creer un label.
    ///
    /// \param texte		 Le texte du label
    /////////////////////////////////////////////////
    Gadget::ptr label (std::string texte = "Label");

    /////////////////////////////////////////////////
    /// \brief Creer une image. (� voir si on peut gerer direct le fichier par l'intermediaire du ressourceMgr)
    ///
    /// \param fichier		 Le fichier image
    /////////////////////////////////////////////////
    Gadget::ptr image (std::string fichier);


}; // fin class FabriqueGadgetBase

} // fin namespace gui

#endif
