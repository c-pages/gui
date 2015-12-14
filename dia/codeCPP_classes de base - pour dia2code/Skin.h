#ifndef SKIN__H
#define SKIN__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <memory>
#include "Style.h"



namespace gui {



/////////////////////////////////////////////////
/// \brief Un skin regroupe un ensemble de style pour composer tout les �l�ments d'une interface.
///
/////////////////////////////////////////////////
class Skin {



/////////////////////////////////////////////////
// M�thodes
/////////////////////////////////////////////////

public:
public:
    /////////////////////////////////////////////////
    /// \brief Createur par d�faut
    ///
    /////////////////////////////////////////////////
    Skin ();



/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
    std::shared_ptr<gui::Style> invisible;
    std::shared_ptr<gui::Style> cadre;
    std::shared_ptr<gui::Style> txtLog;
    std::shared_ptr<gui::Style> txtCourant;
    std::shared_ptr<gui::Style> txtTitre;
    std::shared_ptr<gui::Style> btnPress;
    std::shared_ptr<gui::Style> btnSurvol;
    std::shared_ptr<gui::Style> btnRepos;
    std::shared_ptr<gui::Style> fenetre;
    std::shared_ptr<gui::Style> desactive;

}; // fin class Skin

} // fin namespace gui

#endif
