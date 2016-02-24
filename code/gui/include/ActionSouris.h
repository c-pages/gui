#ifndef ACTIONSOURIS__H
#define ACTIONSOURIS__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <map>
#include <functional>

#include "Gadget.h"

#include <Enums.h>

namespace gui {


/////////////////////////////////////////////////
/// \brief Classe abstraite qui gère les évenements claviers et souris
///
/////////////////////////////////////////////////
class ActionSouris : public Gadget {



/////////////////////////////////////////////////
// Enums & typedefs
/////////////////////////////////////////////////
public:
    using FctnAction = std::function<void()>;    ///< le type de fonction associé aux declenchements des evenements.


/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////
public:
    /////////////////////////////////////////////////
    /// \brief Créer une nouvelle liaison entre un evenement souris  et une fonction lambda.
    ///
    /// \param evenement		 evenement souris
    /// \param fonction		 Le fonction à déclencher.
    /////////////////////////////////////////////////
    void lier  (Evenement evenement, FctnAction fonction);

    /////////////////////////////////////////////////
    /// \brief Supprime une liaison entre un evenement souris  et une fonction lambda.
    ///
    /// \param evenement		 L'évenement à supprimer
    /////////////////////////////////////////////////
    void delier (Evenement evenement);

protected:
    /////////////////////////////////////////////////
    /// \brief Déclencher un évenement souris (les évenement claviers sont gérer.
    ///
    /// \param evenement
    /////////////////////////////////////////////////
    virtual void declencher (Evenement evenement);



/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:
    std::map < Evenement , FctnAction > m_evenementsSouris;    ///< la liste des evenements souris enregistrés.

}; // fin class ActionSouris

} // fin namespace gui

#endif
