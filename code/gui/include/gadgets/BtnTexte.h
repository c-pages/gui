#ifndef BTNTEXTE__H
#define BTNTEXTE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "BtnRectangle.h"
#include "gadgets\AffRectangle.h"
#include "gadgets\AffLabel.h"
#include <SFML/Graphics.hpp>



namespace gui {


/////////////////////////////////////////////////
/// \brief Un simple bouton rectangulaire
///
/////////////////////////////////////////////////
class BtnTexte : public gui::BtnRectangle {



/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////
public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /////////////////////////////////////////////////
    BtnTexte ();

//    virtual void actualiser ( );

    /////////////////////////////////////////////////
    virtual void actualiserGeometrie ();

    /////////////////////////////////////////////////
    virtual void actualiserStyle ();
/*
    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;
*/

    virtual     void setStyle ( std::shared_ptr<Style> style , Etat etat = Etat::tous );

    ///< Definir m_texteTaille
    void setTexteTaille( float val ){
        m_label->setTexteTaille ( val ) ;
        actualiserGeometrie ();
    };


    ///< Definir m_police
    void setTexteCouleur( sf::Color couleur ){
        m_label->setTexteCouleur ( couleur );
    };

    ///< Definir m_police
    void setPolice( sf::Font val ){
        m_label->setPolice    ( val );
        actualiserGeometrie ();
    };

////////////////////////////////// ///////////////
// Membres
/////////////////////////////////////////////////
public:

    std::shared_ptr<AffLabel>        m_label;

}; // fin class BtnTexte

} // fin namespace gui

#endif // BTNRECTANGLE__H
