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

    /////////////////////////////////////////////////
    virtual void actualiserGeometrie ();

    /////////////////////////////////////////////////
    virtual void actualiserStyle ();



    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;


//    virtual void creerNom( std::string type  = "Rectangle" ) {Gadget::creerNom(type);};


    void setFillColor (sf::Color couleur) {
            m_couleurFond = couleur ;
            m_rectangle.setFillColor( couleur );
        };
    void setOutlineColor (sf::Color couleur) {
            m_couleurLignes =  couleur;
            m_rectangle.setOutlineColor( couleur );
        };
    void setOutlineThickness (float epaisseur) {
            m_epaisseur = epaisseur;
            m_rectangle.setOutlineThickness( epaisseur );
        };






/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
protected:

    // les composants de l'interface du gadget
    sf::RectangleShape  m_rectangle;        ///< Le rectangle sfml.

    // les proprietés graphiques
    sf::Color  m_couleurFond;
    sf::Color  m_couleurLignes;
    float      m_epaisseur;

//    std::string     m_type  = "Rectangle" ;

}; // fin class AffRectangle

} // fin namespace gui

#endif
