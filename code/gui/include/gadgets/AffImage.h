#ifndef AFFIMAGE__H
#define AFFIMAGE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Affiche.h"
#include <memory>
#include <SFML/Graphics.hpp>



namespace gui {



/////////////////////////////////////////////////
/// \brief Classe concrète d'affichage d'une simple image.
///
/////////////////////////////////////////////////
class AffImage : public gui::Affiche {



/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////
public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /////////////////////////////////////////////////
    AffImage ();

    virtual void actualiser ();

    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;

    void chargerDepuisFichier ( std::string fichier );


/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
public:
//    std::shared_ptr<sf::RectangleShape>   m_rectangle;
//    std::shared_ptr<sf::Texture>          m_texture;

    sf::Sprite      m_sprite;
    sf::Texture     m_texture;
}; // fin class AffImage

} // fin namespace gui

#endif
