#ifndef DNCASEACOCHER__H
#define DNCASEACOCHER__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Donnee.h"

#include "BtnRectangle.h"
#include "AffRectangle.h"


namespace gui {

/*
class BtnRectangle;
class AffRectangle;*/

/////////////////////////////////////////////////
/// \brief Une case à cocher pour controler une valeur booléene.
///
/////////////////////////////////////////////////
class DnCaseACocher : public gui::Donnee<bool> {

/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////

public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /////////////////////////////////////////////////
    DnCaseACocher ();

//    virtual void actualiser ();
    virtual void actualiserGeometrie ();
    virtual void actualiserStyle ();

    virtual void actualiserBounds();

    virtual std::shared_ptr<Gadget>  testerSurvol ( sf::Vector2i position );

/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:
    // les composants de l'interface du gadget
    std::shared_ptr<BtnRectangle>    m_bouton;
    std::shared_ptr<AffRectangle>    m_coche;
    std::shared_ptr<AffLabel>        m_label;

    // Les actions pour le fonctionnement
    FctnAction     fn_basculerValeur;

    Valeurs<sf::Color>      m_btnCouleurs;
    Valeurs<sf::Color>      m_btnLgnCouleurs;
    Valeurs<float>          m_btnLgnepaisseurs;

    Valeurs<sf::Color>      m_cocheCouleurs;
    Valeurs<sf::Color>      m_cocheLgnCouleurs;
    Valeurs<float>          m_cocheLgnepaisseurs;

    sf::Color               m_textCouleur;
    float                   m_textTaille;
    sf::Font                m_textPolice;
    sf::Text::Style         m_textStyle;

}; // fin class DnCaseACocher

} // fin namespace gui

#endif
