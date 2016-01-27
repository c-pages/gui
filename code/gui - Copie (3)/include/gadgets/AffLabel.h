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
// Membres
/////////////////////////////////////////////////
public:
    std::shared_ptr<sf::Text>   m_texte;

    sf::Font                    m_police;
    sf::Color                   m_couleur;
    float                       m_taille;

}; // fin class AffLabel

} // fin namespace gui

#endif
