#ifndef BTNBARREOUTILS__H
#define BTNBARREOUTILS__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Bouton.h"



namespace gui {



/////////////////////////////////////////////////
/// \brief Une barre d'outils, permet de déclencher des fonctions.
///
/////////////////////////////////////////////////
class BtnBarreOutils : public gui::Bouton {



/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////
public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /////////////////////////////////////////////////
    BtnBarreOutils ();

    void ajouterElement (std::string nom, std::string fichierIcone, FctnAction action);

    void supprimerElement (unsigned int id);

    void actualiserGeometrie ();

    virtual void actualiserStyle ();

    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;


}; // fin class BtnBarreOutils

} // fin namespace gui

#endif
