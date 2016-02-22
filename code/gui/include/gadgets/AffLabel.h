#ifndef AFFLABEL__H
#define AFFLABEL__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Affiche.h"
#include <memory>
#include <SFML/Graphics.hpp>



namespace gui {



/////////////////////////////////////////////////
/// \brief Classe concrète d'affichage d'un simple texte.
///
/////////////////////////////////////////////////
class AffLabel : public Affiche {



/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////

public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /////////////////////////////////////////////////
    AffLabel ();

    void setTexte( std::string val );


    void initialiser_composants ();

    virtual void actualiser ( sf::Time delta );

    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;

    /////////////////////////////////////////////////
    /// \brief Surcharge du l'acceur de la taille pour tenir compte du texte SFML
    ///
    /// \return la taille du texte en pixels.
    ///
    /////////////////////////////////////////////////
    virtual sf::Vector2f    getTaille() const;

    void getProp() {
        std::cout << "\n--------------------------------------\n";
        std::cout << "      m_label : " << std::string ( m_label.getString() ) << "\n";
        std::cout << "      m_labelCouleur : " << int ( m_label.getColor().r )
                                        << " " << int ( m_label.getColor().g )
                                        << " " << int ( m_label.getColor().b )
                                        << "\n";
        std::cout << "      m_labelTaille : " << int ( m_label.getCharacterSize() ) << "\n";
        std::cout << "      Bounds : "  << int ( m_label.getGlobalBounds( ).width )
                                        << " " << int ( m_label.getGlobalBounds( ).height )
                                        << "\n";
        std::cout << "      m_labelPolice : " << float ( m_labelPolice.getLineSpacing( 1 ) ) << "\n";

        std::cout << "--------------------------------------\n\n";

    }

/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
public:
    sf::Text    m_label;

    sf::Font    m_labelPolice;
    sf::Color   m_labelCouleur;
    float       m_labelTaille;

}; // fin class AffLabel

} // fin namespace gui

#endif
