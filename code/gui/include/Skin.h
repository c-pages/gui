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
    std::shared_ptr<Style> cadre;

    std::shared_ptr<Style> txtLog;
    std::shared_ptr<Style> txtCourant;
    std::shared_ptr<Style> txtTitre;

    std::shared_ptr<Style> fond;

    std::shared_ptr<Style> btnPress;
    std::shared_ptr<Style> btnSurvol;
    std::shared_ptr<Style> btnRepos;

    std::shared_ptr<Style> imgRepos;

    std::shared_ptr<Style> fenetre;
    std::shared_ptr<Style> desactive;

}; // fin class Skin

}; // fin namespace gui

#endif
