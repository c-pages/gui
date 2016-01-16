#ifndef INFOBULLERENDU__H
#define INFOBULLERENDU__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "GadgetRendu.h"
#include <SFML/Graphics.hpp>



namespace gui {



/////////////////////////////////////////////////
/// \brief Le rendu de base d'une infoBulle.
///
/////////////////////////////////////////////////
class InfoBulleRendu : public gui::GadgetRendu {



/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////

public:
    ///< Definir m_texteCouleur
    void setTexteCouleur( sf::Color val ){ m_texteCouleur = val; };

    ///< Acceder à m_texteCouleur
    sf::Color getTexteCouleur () const { return m_texteCouleur; };

public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /// \param label		 Le label reference.
    /////////////////////////////////////////////////
    InfoBulleRendu (Gadget::ptr InfoBulle);

    void draw (sf::RenderTarget& target, sf::RenderStates states) const;



/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:
    sf::Color m_texteCouleur;    ///< #G#S
    sf::Text m_label;

}; // fin class InfoBulleRendu

} // fin namespace gui

#endif
