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

//    virtual void actualiser ();

    /////////////////////////////////////////////////
    virtual void actualiserGeometrie ();

    /////////////////////////////////////////////////
    virtual void actualiserStyle ();


    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;

    void chargerDepuisFichier ( std::string fichier );

    void setImage ( const sf::Texture* texture )
    {
        m_rectangle.setTexture( texture );
    };

    void setAjustement ( bool val ) { m_ajustement = val; };

    virtual void setTaille( sf::Vector2i val ){

//        m_taille = val;

        actualiserGeometrie();
    };

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
