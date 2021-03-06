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
class AffRectangle : public gui::Affiche {



/////////////////////////////////////////////////
// M�thodes
/////////////////////////////////////////////////

public:
public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par d�faut.
    ///
    /////////////////////////////////////////////////
    AffRectangle ();

    virtual void actualiser ();

    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;

protected:
    void setCouleurFond (sf::Color couleur);

    void setCouleurBord (sf::Color couleur);

    void setEpaisseurBord (float epaisseur);



/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:
    sf::RectangleShape m_rectangle;    ///< Le rectangle sfml.    

}; // fin class AffRectangle

} // fin namespace gui

#endif
