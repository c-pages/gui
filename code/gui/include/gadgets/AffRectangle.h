#ifndef AFFRECTANGLE__H
#define AFFRECTANGLE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Affiche.h"
#include <SFML/Graphics.hpp>



namespace gui {



/////////////////////////////////////////////////
/// \brief Classe concrète d'affichage d'un simple rectangle.
///
/////////////////////////////////////////////////
class AffRectangle : public Affiche/*, public sf::RectangleShape*/ {



/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////

public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /////////////////////////////////////////////////
    AffRectangle ( sf::Vector2i taille = {10,10} );

    virtual void actualiser ();

    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;

    void setFillColor (sf::Color couleur)
        { m_rectangle.setFillColor( couleur ); };

    void setOutlineColor (sf::Color couleur)
        { m_rectangle.setOutlineColor( couleur ); };

    void setOutlineThickness (float epaisseur)
        { m_rectangle.setOutlineThickness( epaisseur ); };


protected:

/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:
    sf::RectangleShape      m_rectangle;    ///< Le rectangle sfml.

}; // fin class AffRectangle

} // fin namespace gui

#endif
