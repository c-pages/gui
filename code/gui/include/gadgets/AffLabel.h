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
/// \brief Classe concr�te d'affichage d'un simple texte.
///
/////////////////////////////////////////////////
class AffLabel : public Affiche {



/////////////////////////////////////////////////
// M�thodes
/////////////////////////////////////////////////

public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par d�faut.
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
