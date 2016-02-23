#ifndef BOUTONRECT__H
#define BOUTONRECT__H

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
class BoutonRect : public gui::Bouton {



/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////

public:
public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /////////////////////////////////////////////////
    BoutonRect ();

    virtual void actualiser ( );

    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;

    void setTexte( std::string val ){ m_texte = val; actualiser(); };

/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
public:
    std::string     m_texte;            ///< Le texte à afficher par le label.
    AffRectangle    m_rectangle;
    AffLabel        m_label;

}; // fin class BoutonRect

} // fin namespace gui

#endif
