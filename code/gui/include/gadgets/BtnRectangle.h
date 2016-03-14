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

    //    virtual void actualiser ( );

    /////////////////////////////////////////////////
    virtual void actualiserGeometrie ();

    /////////////////////////////////////////////////
    virtual void actualiserStyle ();

    void setFillColor (sf::Color couleur , Etat etat = Etat::tous ) {
            m_couleurFond.set ( couleur , etat );
            m_rectangle->setFillColor( couleur );
        };
    void setOutlineColor (sf::Color couleur , Etat etat = Etat::tous ) {
            m_couleurLignes.set ( couleur , etat );
            m_rectangle->setOutlineColor( couleur );
        };
    void setOutlineThickness (float epaisseur , Etat etat = Etat::tous ) {
            m_epaisseur.set ( epaisseur , etat );
            m_rectangle->setOutlineThickness( epaisseur );
        };

    void setFillColor ( Valeurs<sf::Color> couleurs  ) {
            m_couleurFond = couleurs;
            actualiserStyle();
//            m_rectangle->setFillColor( couleur );
        };
    void setOutlineColor ( Valeurs<sf::Color> couleurs  ) {
            m_couleurLignes = couleurs;
            actualiserStyle();
//            m_rectangle->setOutlineColor( couleur );
        };
    void setOutlineThickness ( Valeurs<float> epaisseur ) {
            m_epaisseur =  epaisseur;
            actualiserStyle();
//            m_rectangle->setOutlineThickness( epaisseur );
        };
//    virtual     void setStyle ( std::shared_ptr<Style> style , Etat etat = Etat::tous );



////////////////////////////////// ///////////////
// Membres
/////////////////////////////////////////////////
public:

    // les composants de l'interface du gadget
    std::shared_ptr<AffRectangle>    m_rectangle;
//    std::shared_ptr<AffRectangle>    m_focus;

    // les proprietés graphiques
    Valeurs<sf::Color>      m_couleurFond;
    Valeurs<sf::Color>      m_couleurLignes;
    Valeurs<float>          m_epaisseur;

    sf::Color               m_couleurFocus;
    float                   m_epaisseurFocus;

}; // fin class BtnRectangle

} // fin namespace gui

#endif // BTNRECTANGLE__H
