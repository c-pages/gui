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

    void setAjustement ( bool val ) { m_ajustement = val; };

    virtual void setTaille( sf::Vector2i val ){

        if ( m_ajustement )
            m_taille = val;
        else
            m_taille = sf::Vector2i(m_texture->getSize().x , m_texture->getSize().y );

        actualiser();
    };

/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:
    sf::RectangleShape  m_rectangle;
    sf::Texture*        m_texture;
    bool                m_ajustement;       ///< true: l'image est ajusté au rectangle, false: le rectangle s'ajuste à limge (facon sprite).
}; // fin class AffImage

} // fin namespace gui

#endif
