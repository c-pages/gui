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
/// \brief Classe concrète d'affichage d'un simple rectangle.
///
/////////////////////////////////////////////////
class AffRectangle : public Affiche {



/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////
public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /////////////////////////////////////////////////
    AffRectangle ();

    void initialiser_composants ();

    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;

    virtual void actualiser ( sf::Time delta );

    void    setFillColor    ( sf::Color  val ) {
        m_couleur = val;
//        m_rectangle->setFillColor ( val );
//        std::cout << "\n--------------------------------------\n";
//        std::cout << "      m_labelCouleur : " << int ( m_rectangle->getFillColor().r )
//                                        << " " << int ( m_rectangle->getFillColor().g )
//                                        << " " << int ( m_rectangle->getFillColor().b )
//                                        << "\n";
//
//        std::cout << "--------------------------------------\n\n";
    };

    void  setOutlineColor ( sf::Color val ) {
        m_cadreCouleur = val;
//        m_rectangle->setOutlineColor ( val );
    };

    void setOutlineThickness ( float val) {
        m_cadreEpaisseur = val;
//        m_rectangle->setOutlineThickness( val );
    };

/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:
    std::shared_ptr<sf::RectangleShape>     m_rectangle = std::make_shared<sf::RectangleShape>  ( );    ///< Le rectangle sfml.
    sf::Color               m_couleur;
    float                   m_cadreEpaisseur;
    sf::Color               m_cadreCouleur;

}; // fin class AffRectangle

} // fin namespace gui

#endif
