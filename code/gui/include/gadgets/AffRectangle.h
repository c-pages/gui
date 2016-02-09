#ifndef AFFRECTANGLE__H
#define AFFRECTANGLE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Affiche.h"

#include <memory>
#include <SFML/Graphics.hpp>



namespace gui {



/////////////////////////////////////////////////
/// \brief Classe concr�te d'affichage d'un simple rectangle.
///
/////////////////////////////////////////////////
class AffRectangle : public Affiche {



/////////////////////////////////////////////////
// M�thodes
/////////////////////////////////////////////////
public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par d�faut.
    ///
    /////////////////////////////////////////////////
    AffRectangle ();

    void initialiser_composants ();

    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;

    virtual void actualiser( sf::Time delta );


/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:
    std::shared_ptr<sf::RectangleShape> m_rectangle;    ///< Le rectangle sfml.
    sf::Color                           m_couleur;
    float                               m_cadreTaille;
    sf::Color                           m_cadreCouleur;

}; // fin class AffRectangle

} // fin namespace gui

#endif
