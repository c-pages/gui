#ifndef BTNTEXTE__H
#define BTNTEXTE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Bouton.h"
#include "gadgets\AffRectangle.h"
#include "gadgets\AffLabel.h"
#include <SFML/Graphics.hpp>



namespace gui {


/////////////////////////////////////////////////
/// \brief Un simple bouton rectangulaire
///
/////////////////////////////////////////////////
class BtnTexte : public gui::Bouton {



/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////
public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /////////////////////////////////////////////////
    BtnTexte ();

    virtual void actualiser ( );
/*
    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;
*/
    virtual void setTexte( std::string val ){
        m_texte = val;
        m_label->setTexte(m_texte);
        demander_actualisation ();
    };

////////////////////////////////// ///////////////
// Membres
/////////////////////////////////////////////////
public:
    std::shared_ptr<AffRectangle>    m_rectangle;
    std::shared_ptr<AffLabel>        m_label;

}; // fin class BtnTexte

} // fin namespace gui

#endif // BTNRECTANGLE__H
