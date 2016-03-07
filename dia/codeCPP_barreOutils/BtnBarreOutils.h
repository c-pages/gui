#ifndef BTNBARREOUTILS__H
#define BTNBARREOUTILS__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Bouton.h"



namespace gui {



/////////////////////////////////////////////////
/// \brief Une barre d'outils, permet de d�clencher des fonctions.
///
/////////////////////////////////////////////////
class BtnBarreOutils : public gui::Bouton {



/////////////////////////////////////////////////
// M�thodes
/////////////////////////////////////////////////
public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par d�faut.
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
