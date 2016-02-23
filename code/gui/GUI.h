#ifndef __GUI_H__
#define __GUI_H__

#include "SFML/Graphics.hpp"
#include "Gadget.h"
#include "FabriqueBase.h"


namespace gui {

/////////////////////////////////////////////////
/// \brief Classe communes à tout les gadgets, gère affichage actualisation, etc...
///
/////////////////////////////////////////////////
class Interface : public Gadget{

public:
    Interface( sf::RenderWindow* fenetre );

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    virtual void traiterEvenements( sf::Event evenement );

private:
    std::shared_ptr<Gadget> chercherGadgetSurvole ();

public:
/////////////////////////////////////////////////
// membres
/////////////////////////////////////////////////
    FabriqueBase    creer;      ///< La fabrique de gadget de base (GOF: Fabrique)

private:
    std::shared_ptr<Gadget>     m_boutonSurvole;    ///< Le bouton survolé actuelement par la souris.
    std::shared_ptr<Gadget>     m_boutonPresse;     ///< Le bouton pressé actuelement par la souris.
    sf::RenderWindow*           m_fenetre;          ///< La fenetyre SFML;

}; // fin class gui

}; // fin namespace gui

#endif // __GUI_H__
