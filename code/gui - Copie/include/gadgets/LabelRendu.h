#ifndef LABELRENDU__H
#define LABELRENDU__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "GadgetRendu.h"
#include <SFML/Graphics.hpp>



namespace gui {



/////////////////////////////////////////////////
/// \brief Le rendu de base d'un label.
///
/////////////////////////////////////////////////
class LabelRendu : public gui::GadgetRendu {



/////////////////////////////////////////////////
// M�thodes
/////////////////////////////////////////////////

public:
    ///< Definir m_texteCouleur
    void setTexteCouleur( sf::Color val ){ m_texteCouleur = val; };

    ///< Acceder � m_texteCouleur
    sf::Color getTexteCouleur () const { return m_texteCouleur; };

public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par d�faut.
    ///
    /// \param label		 Le label reference.
    /////////////////////////////////////////////////
    LabelRendu (Gadget::ptr label);

    void draw (sf::RenderTarget& target, sf::RenderStates states) const;



/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:
    sf::Color m_texteCouleur;    ///< #G#S
    sf::Text m_label;

}; // fin class LabelRendu

} // fin namespace gui

#endif
