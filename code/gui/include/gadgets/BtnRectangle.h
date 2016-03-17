#ifndef BTNRECTANGLE__H
#define BTNRECTANGLE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "gadgets_interfaces/Bouton.h"
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
// M�thodes
/////////////////////////////////////////////////
public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par d�faut.
    ///
    /////////////////////////////////////////////////
    BtnRectangle ();

    /////////////////////////////////////////////////
    virtual void actualiserGeometrie ();

    /////////////////////////////////////////////////
    virtual void actualiserStyle ();

    void setFondCouleur (sf::Color couleur , Etat etat = Etat::tous );

    void setFondLigneCouleur (sf::Color couleur , Etat etat = Etat::tous );

    void setFondLigneEpaisseur (float epaisseur , Etat etat = Etat::tous );

    void setFondCouleur ( Valeurs<sf::Color> couleurs  );

    void setFondLigneCouleur ( Valeurs<sf::Color> couleurs  );

    void setFondLigneEpaisseur ( Valeurs<float> epaisseur );

////////////////////////////////// ///////////////
// Membres
/////////////////////////////////////////////////
public:

    // les composants de l'interface du gadget
    std::shared_ptr<AffRectangle>    m_rectangle;

    // les propriet�s graphiques
    Valeurs<sf::Color>      m_couleurFond;
    Valeurs<sf::Color>      m_couleurLignes;
    Valeurs<float>          m_epaisseur;

    sf::Color               m_couleurFocus;
    float                   m_epaisseurFocus;

}; // fin class BtnRectangle

} // fin namespace gui

#endif // BTNRECTANGLE__H
