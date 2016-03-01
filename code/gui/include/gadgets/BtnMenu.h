#ifndef BTNMENU__H
#define BTNMENU__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Bouton.h"
#include "AffRectangle.h"
#include "BtnTexte.h"
#include <vector>
#include <memory>



namespace gui {



/////////////////////////////////////////////////
/// \brief Un menu, permet de déclencher un action parmis d'autres.
///
/////////////////////////////////////////////////
class BtnMenu : public gui::Bouton {



/////////////////////////////////////////////////
// struct
/////////////////////////////////////////////////
struct ElementMenu {
    std::string             nom;
    FctnAction              fonction;
    std::shared_ptr<Bouton> bouton;
};



/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////

public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /////////////////////////////////////////////////
    BtnMenu ();

    void ajouterElement (std::string nom, FctnAction fonction);

    /////////////////////////////////////////////////
    /// \brief
    ///
    /// \param id
    /////////////////////////////////////////////////
    void supprimerElement (unsigned int id);

    virtual void actualiser ();
    virtual void actualiser_bounds ();

    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;

    virtual std::shared_ptr<Gadget>  testerSurvol ( sf::Vector2i position );

/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
public:
    std::vector <ElementMenu*>      m_elements;
    std::shared_ptr<AffRectangle>   m_fond;
    sf::Vector2i                    m_tailleMenu;   ///< La taille d'un bouton du menu
    float                           m_ecart;

}; // fin class BtnMenu

} // fin namespace gui

#endif
