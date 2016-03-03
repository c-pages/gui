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

//    virtual void actualiser ();

    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;



    virtual void actualiser_geometrie ();
    virtual void actualiser_style ();


    void setFillColor (sf::Color couleur) {
            m_couleurFond   = couleur ;
            m_rectangle->setFillColor ( couleur );
//            demander_actualisation();
        };


    void setOutlineColor (sf::Color couleur) {
            m_couleurLignes = couleur;
            m_rectangle->setOutlineColor ( couleur );
//            demander_actualisation();
          };

    void setOutlineThickness (float epaisseur) {
            m_epaisseur = epaisseur;
            m_rectangle->setOutlineThickness ( epaisseur );
//            demander_actualisation();
          };







protected:

/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:
    std::shared_ptr<sf::RectangleShape>  m_rectangle;        ///< Le rectangle sfml.
//
//    std::shared_ptr<sf::Color>  m_couleurFond;
//    std::shared_ptr<sf::Color>  m_couleurLignes;
//    std::shared_ptr<float>      m_epaisseur;

    sf::Color   m_couleurFond;
    sf::Color   m_couleurLignes;
    float       m_epaisseur;

}; // fin class AffRectangle

} // fin namespace gui

#endif
