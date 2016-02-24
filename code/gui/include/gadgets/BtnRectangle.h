#ifndef BTNRECTANGLE__H
#define BTNRECTANGLE__H

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
class BtnRectangle : public gui::Bouton {



/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////
public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /////////////////////////////////////////////////
    BtnRectangle ();

    virtual void actualiser ( );

    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;

    virtual void setTexte( std::string val ){ m_texte = val; m_label.setTexte(m_texte); actualiser(); };

////////////////////////////////// ///////////////
// Membres
/////////////////////////////////////////////////
public:
    std::string     m_texte;            ///< Le texte à afficher par le label.
    AffRectangle    m_rectangle;
    AffLabel        m_label;

}; // fin class BtnRectangle

} // fin namespace gui

#endif // BTNRECTANGLE__H
