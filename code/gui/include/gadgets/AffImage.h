#ifndef AFFIMAGE__H
#define AFFIMAGE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "AffRectangle.h"
#include <memory>
#include <SFML/Graphics.hpp>



namespace gui {



/////////////////////////////////////////////////
/// \brief Classe concr�te d'affichage d'une simple image.
///
/////////////////////////////////////////////////
class AffImage : public gui::AffRectangle {



/////////////////////////////////////////////////
// M�thodes
/////////////////////////////////////////////////
public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par d�faut.
    ///
    /////////////////////////////////////////////////
    AffImage ();

    /////////////////////////////////////////////////
    virtual void actualiserGeometrie ();

    /////////////////////////////////////////////////
    virtual void actualiserStyle ();

    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;

    void setImage ( std::string fichier );

    void setImage (  sf::Texture* texture );

    void setAjustement ( bool val );

    virtual void setTaille( sf::Vector2i val );

/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
protected:

    // les propriet�s fonctionnelles
    sf::Texture*        m_texture;
    bool                m_ajustement;       ///< true: l'image est ajust� au rectangle, false: le rectangle s'ajuste � limge (facon sprite).

}; // fin class AffImage

} // fin namespace gui

#endif
