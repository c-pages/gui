#ifndef SKIN__H
#define SKIN__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <memory>
#include "Style.h"


namespace gui{


/////////////////////////////////////////////////
/// \brief Un skin regroupe un ensemble de style pour composer tout les éléments d'une interface.
///
/////////////////////////////////////////////////
class Skin {



/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////
public:
    /////////////////////////////////////////////////
    /// \brief Createur par défaut
    ///
    /////////////////////////////////////////////////
    Skin ();



/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
    std::shared_ptr<Style> invisible;
    std::shared_ptr<Style> desactive;

    std::shared_ptr<Style> cadre;

    std::shared_ptr<Style> txtCourant;
    std::shared_ptr<Style> txtLog;
    std::shared_ptr<Style> txtTitre;

    std::shared_ptr<Style> fond;

    std::shared_ptr<Style> bouton;

    std::shared_ptr<Style> img;

    std::shared_ptr<Style> menu;

    std::shared_ptr<Style> fenetre;

}; // fin class Skin

}; // fin namespace gui

#endif
