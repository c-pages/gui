#ifndef STYLE__H
#define STYLE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
#include <memory>



namespace gui {

class ptr;


/////////////////////////////////////////////////
/// \brief Un style regroupe les charactéristiques graphique d'un état d'un gadget.
///
/////////////////////////////////////////////////
class Style {


/////////////////////////////////////////////////
// Enums & typedefs
/////////////////////////////////////////////////
public:
    typedef std::shared_ptr<Style> ptr;    ///< Pointeur vers un Theme.


/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
public:
    sf::Color m_texteCouleur;    ///< #G#S
    sf::Color m_fondCouleur;    ///< #G#S
    std::shared_ptr<sf::Texture> m_texture;    ///< #G#S
    std::shared_ptr<sf::Font> m_police;    ///< #G#S
    float m_taillePolice;    ///< #G#S
    sf::Color m_cadreCouleur;    ///< #G#S
    float m_cadreTaille;    ///< #G#S

}; // fin class Style

} // fin namespace gui

#endif
