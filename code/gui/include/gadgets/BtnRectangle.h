#ifndef BTNRECTANGLE__H
#define BTNRECTANGLE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Bouton.h"
#include "Valeurs.h"
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

    /////////////////////////////////////////////////
    virtual void actualiserGeometrie ();

    /////////////////////////////////////////////////
    virtual void actualiserStyle ();

    void setFondCouleur (sf::Color couleur , Etat etat = Etat::tous );

    void setLigneCouleur (sf::Color couleur , Etat etat = Etat::tous );

    void setLigneEpaisseur (float epaisseur , Etat etat = Etat::tous );

    void setFondCouleur ( Valeurs<sf::Color> couleurs  );

    void setLigneCouleur ( Valeurs<sf::Color> couleurs  );

    void setLigneEpaisseur ( Valeurs<float> epaisseur );

////////////////////////////////// ///////////////
// Membres
/////////////////////////////////////////////////
public:

    // les composants de l'interface du gadget
    std::shared_ptr<AffRectangle>    m_rectangle;

    // les proprietés graphiques
    Valeurs<sf::Color>      m_couleurFond;
    Valeurs<sf::Color>      m_couleurLignes;
    Valeurs<float>          m_epaisseur;

    sf::Color               m_couleurFocus;
    float                   m_epaisseurFocus;

}; // fin class BtnRectangle

} // fin namespace gui

#endif // BTNRECTANGLE__H
