#ifndef INTERFACE_H
#define INTERFACE_H


#include "SFML/Graphics.hpp"
#include "Gadget.h"
#include "FabriqueBase.h"

namespace gui {

/////////////////////////////////////////////////
/// \brief Classe communes � tout les gadgets, g�re affichage actualisation, etc...
///
/////////////////////////////////////////////////
class Interface : public Gadget{

public:
    Interface( sf::RenderWindow* fenetre );

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    virtual void traiterEvenements( sf::Event evenement );

private:
    std::shared_ptr<Gadget> chercherGadgetSurvole ();

    /////////////////////////////////////////////////
    /// \brief D�clenche un �v�nement pour tout les boutons (ms_boutons)
    ///
    /// \param evenement    L'�v�nement � d�clencher.
    /// \param saufGadget   L'�v�nement ne sera pas d�clencher pour ce gadget.    ///
    /////////////////////////////////////////////////
    void declencherToutBoutons ( Evenement evenement , std::shared_ptr<Gadget> saufGadget = nullptr );

public:
/////////////////////////////////////////////////
// membres
/////////////////////////////////////////////////
    static sf::Vector2i getPosSouris(){
        sf::Vector2i result = {-1,-1};
        result = sf::Mouse::getPosition( *ms_fenetre );
        return result;

    };
    static sf::RenderWindow*           ms_fenetre;          ///< La fenetyre SFML;


    FabriqueBase    creer;                          ///< La fabrique de gadget de base (GOF: Fabrique)

    std::shared_ptr<Gadget>     m_boutonSurvole;    ///< Le bouton survol� actuelement par la souris.
private:
    std::shared_ptr<Gadget>     m_boutonPresse;     ///< Le bouton press� actuelement par la souris.
    sf::RenderWindow*           m_fenetre;          ///< La fenetyre SFML;

}; // fin class gui

}; // fin namespace gui

#endif // INTERFACE_H
