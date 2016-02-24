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

    /////////////////////////////////////////////////
    /// \brief
    ///
    /////////////////////////////////////////////////
    void setValeur ( bool val) { m_valeur = val; };

    /////////////////////////////////////////////////
    /// \brief
    ///
    /////////////////////////////////////////////////
    bool getValeur () const;

    virtual void actualiser ();

    virtual void actualiser_bounds();

    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;

    virtual std::shared_ptr<Gadget>  testerSurvol ( sf::Vector2i position );

//    virtual getGlobalBounds() const

/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:
    std::shared_ptr<BtnRectangle>    m_bouton;
    std::shared_ptr<AffRectangle>    m_coche;
    std::shared_ptr<AffLabel>        m_label;

}; // fin class DnCaseACocher

} // fin namespace gui

#endif
