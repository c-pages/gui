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
    sf::Color m_texteCouleur;    ///<
    sf::Color m_fondCouleur;    ///<
    std::shared_ptr<sf::Texture> m_texture;    ///<
    std::shared_ptr<sf::Font> m_police;    ///<
    float m_taillePolice;    ///<
    sf::Color m_cadreCouleur;    ///<
    float m_cadreTaille;    ///<

}; // fin class Style

} // fin namespace gui

#endif
