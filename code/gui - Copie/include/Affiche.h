#ifndef AFFICHE__H
#define AFFICHE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Gadget.h"



namespace gui {



/////////////////////////////////////////////////
/// \brief Classe abstraire des �l�ment d'affichage simple sans interactivit�.
///
/////////////////////////////////////////////////
class Affiche : public gui::Gadget {



/////////////////////////////////////////////////
// M�thodes
/////////////////////////////////////////////////
public:
    /////////////////////////////////////////////////
    /// \brief Red�finie ajouter par une fonction vide( GOF4 : composite -> Feuilles)
    ///
    /// \param gadget
    /////////////////////////////////////////////////
    virtual void ajouter (std::shared_ptr<Gadget> gadget);

    /////////////////////////////////////////////////
    /// \brief  Red�finie retirer par une fonction vide( GOF4 : composite -> Feuilles)
    ///
    /// \param enfant
    /////////////////////////////////////////////////
    virtual std::shared_ptr<Gadget> retirer (std::shared_ptr<Gadget> enfant);

protected:
    /////////////////////////////////////////////////
    /// \brief Renvois false.
    ///
    /// \param position
    /////////////////////////////////////////////////
    virtual std::shared_ptr<Gadget> testerSurvol (sf::Vector2i position);


}; // fin class Affiche

} // fin namespace gui

#endif