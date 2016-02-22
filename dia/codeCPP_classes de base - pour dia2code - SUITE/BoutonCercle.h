#ifndef BOUTONCERCLE__H
#define BOUTONCERCLE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Bouton.h"
#include <SFML/Graphics.hpp>



namespace gui {



/////////////////////////////////////////////////
/// \brief Un simple bouton circulaire.
///
/////////////////////////////////////////////////
class BoutonCercle : public gui::Bouton {



/////////////////////////////////////////////////
// M�thodes
/////////////////////////////////////////////////

public:
public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par d�faut.
    ///
    /////////////////////////////////////////////////
    Bouton ();

    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;



/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
public:
    sf::CircleShape m_cercle;    
    sf::Text m_label;    

}; // fin class BoutonCercle

} // fin namespace gui

#endif
