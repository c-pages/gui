#ifndef AFFRECTANGLE__H
#define AFFRECTANGLE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Affiche.h"
#include <SFML/Graphics.hpp>



namespace gui {



/////////////////////////////////////////////////
/// \brief Classe concr�te d'affichage d'un simple rectangle.
///
/////////////////////////////////////////////////
class AffRectangle : public Affiche/*, public sf::RectangleShape*/ {



/////////////////////////////////////////////////
// M�thodes
/////////////////////////////////////////////////

public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par d�faut.
    ///
    /////////////////////////////////////////////////
    AffRectangle ( sf::Vector2i taille = {100,100} );

    virtual void actualiser ();

    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;

    void setCouleurFond (sf::Color couleur)
        { m_rectangle.setFillColor( couleur ); };

    void setCouleurBord (sf::Color couleur)
        { m_rectangle.setOutlineColor( couleur ); };

    void setEpaisseurBord (float epaisseur)
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
