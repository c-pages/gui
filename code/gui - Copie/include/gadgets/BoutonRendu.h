#ifndef BOUTONRENDU__H
#define BOUTONRENDU__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "GadgetRendu.h"
#include "Bouton.h"
#include <memory>
#include <SFML/Graphics.hpp>



namespace gui {

class Label;


/////////////////////////////////////////////////
/// \brief Le rendu de base d'un bouton.
///
/////////////////////////////////////////////////
class BoutonRendu : public gui::GadgetRendu {



/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////

public:
    ///< Definir m_texteCouleurNormal
    void setTexteCouleurNormal( sf::Color val ){ m_texteCouleurNormal = val; };

    ///< Acceder à m_texteCouleurNormal
    sf::Color getTexteCouleurNormal () const { return m_texteCouleurNormal; };

    ///< Definir m_texteCouleurSurvole
    void setTexteCouleurSurvole( sf::Color val ){ m_texteCouleurSurvole = val; };

    ///< Acceder à m_texteCouleurSurvole
    sf::Color getTexteCouleurSurvole () const { return m_texteCouleurSurvole; };

    ///< Definir m_texteCouleurPresse
    void setTexteCouleurPresse( sf::Color val ){ m_texteCouleurPresse = val; };

    ///< Acceder à m_texteCouleurPresse
    sf::Color getTexteCouleurPresse () const { return m_texteCouleurPresse; };

    ///< Definir m_fondCouleurNormal
    void setFondCouleurNormal( sf::Color val ){ m_fondCouleurNormal = val; };

    ///< Acceder à m_fondCouleurNormal
    sf::Color getFondCouleurNormal () const { return m_fondCouleurNormal; };

    ///< Definir m_fondCouleurSurvole
    void setFondCouleurSurvole( sf::Color val ){ m_fondCouleurSurvole = val; };

    ///< Acceder à m_fondCouleurSurvole
    sf::Color getFondCouleurSurvole () const { return m_fondCouleurSurvole; };

    ///< Definir m_fondCouleurPresse
    void setFondCouleurPresse( sf::Color val ){ m_fondCouleurPresse = val; };

    ///< Acceder à m_fondCouleurPresse
    sf::Color getFondCouleurPresse () const { return m_fondCouleurPresse; };

    ///< Definir m_textureNormal
    void setTextureNormal( std::shared_ptr<sf::Texture> val ){ m_textureNormal = val; };

    ///< Acceder à m_textureNormal
    std::shared_ptr<sf::Texture> getTextureNormal () const { return m_textureNormal; };

    ///< Definir m_textureSurvol
    void setTextureSurvol( std::shared_ptr<sf::Texture> val ){ m_textureSurvol = val; };

    ///< Acceder à m_textureSurvol
    std::shared_ptr<sf::Texture> getTextureSurvol () const { return m_textureSurvol; };

    ///< Definir m_texturePresse
    void setTexturePresse( std::shared_ptr<sf::Texture> val ){ m_texturePresse = val; };

    ///< Acceder à m_texturePresse
    std::shared_ptr<sf::Texture> getTexturePresse () const { return m_texturePresse; };

public:
    /////////////////////////////////////////////////
    /// \brief Contructeur par défaut.
    ///
    /// \param bouton		 le bouton reference.
    /////////////////////////////////////////////////
    BoutonRendu (Bouton::ptr bouton);

    void draw (sf::RenderTarget& target, sf::RenderStates states) const;



/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
public:
    std::shared_ptr<Label> m_label;
private:
    sf::RectangleShape m_rectangle;
    sf::Color m_texteCouleurNormal;    ///< #G#S
    sf::Color m_texteCouleurSurvole;    ///< #G#S
    sf::Color m_texteCouleurPresse;    ///< #G#S
    sf::Color m_fondCouleurNormal;    ///< #G#S
    sf::Color m_fondCouleurSurvole;    ///< #G#S
    sf::Color m_fondCouleurPresse;    ///< #G#S
    std::shared_ptr<sf::Texture> m_textureNormal;    ///< #G#S
    std::shared_ptr<sf::Texture> m_textureSurvol;    ///< #G#S
    std::shared_ptr<sf::Texture> m_texturePresse;    ///< #G#S

}; // fin class BoutonRendu

} // fin namespace gui

#endif
