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

    virtual void actualiser ();

    virtual void actualiser_bounds();

    virtual std::shared_ptr<Gadget>  testerSurvol ( sf::Vector2i position );


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
