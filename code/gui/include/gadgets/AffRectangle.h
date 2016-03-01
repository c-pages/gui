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






    void setFillColor (sf::Color couleur) {
            m_couleurFond = std::make_shared<sf::Color>( couleur );
            actualiser();
        };

    void viderFillColor ( ) {
            m_couleurFond = nullptr;
            actualiser();
        };


    void setOutlineColor (sf::Color couleur) {
            m_rectangle.setOutlineColor( couleur );
            m_couleurLignes = std::make_shared<sf::Color>( couleur );
            actualiser();
          };

    void viderOutlineColor ( ) {
            m_couleurLignes = nullptr;
            actualiser();
        };

    void setOutlineThickness (float epaisseur) {
            m_rectangle.setOutlineThickness( epaisseur );
            m_epaisseur = std::make_shared<float>( epaisseur );
            actualiser();
          };

    void viderOutlineThickness ( ) {
            m_epaisseur = nullptr;
            actualiser();
        };






protected:

/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:
    sf::RectangleShape  m_rectangle;        ///< Le rectangle sfml.

    std::shared_ptr<sf::Color>  m_couleurFond;
    std::shared_ptr<sf::Color>  m_couleurLignes;
    std::shared_ptr<float>      m_epaisseur;

}; // fin class AffRectangle

} // fin namespace gui

#endif
