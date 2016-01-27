#ifndef CLIQUABLE__H
#define CLIQUABLE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Gadget.h"
#include <vector>
#include <memory>



namespace gui {



/////////////////////////////////////////////////
/// \brief Classe des boutons ( éléments interactifs de l'interface). ( Dérivé du GOf4 décoration ).
///
/////////////////////////////////////////////////
class Cliquable : public Gadget {



/////////////////////////////////////////////////
// Enums & typedefs
/////////////////////////////////////////////////
    typedef std::shared_ptr<Cliquable> clickPtr;    ///< Pointeur vers un gadget.


/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////

public:
    /*
    /////////////////////////////////////////////////
    /// \brief  Fonction static pour gerer globalement les événements de l'interface.
    ///
    /////////////////////////////////////////////////
    void static s_traiterEvents ();
    */

    /////////////////////////////////////////////////
    /// \brief Redéfinie ajouter par une fonction vide( GOF4 : composite -> Feuilles)
    ///
    /////////////////////////////////////////////////
    virtual void ajouter (){};

    /////////////////////////////////////////////////
    /// \brief Redéfinie retirer par une fonction vide( GOF4 : composite -> Feuilles)
    ///
    /////////////////////////////////////////////////
    virtual void retirer (){};

    virtual void testerSurvol ();

    /////////////////////////////////////////////////
    /// \brief Actualise le style du gadget (après une modification, de son état par exemple).
    ///
    /////////////////////////////////////////////////
    void actualiser ();

    /////////////////////////////////////////////////
    /// \brief Définie un nouvel état pour le bouton, puis actualise le style.
    ///
    /////////////////////////////////////////////////
    void setEtat ();

    /////////////////////////////////////////////////
    /// \brief Dessiner le gadget => dessiner ses enfants.
    ///
    /// \param target
    /// \param states
    /////////////////////////////////////////////////
    //virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const {};


/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
//private:
//    static std::vector<clickPtr>    ms_Boutons;         ///< La liste static totale des boutons.
//    static clickPtr                 ms_btnSurvole;      ///< Pointeur static vers le bouton qui à le focus du survol.
//    static clickPtr                 ms_btnPresse;       ///< Pointeur static vers le bouton de l'interface qui est en train d'être pressé.

}; // fin class Cliquable

} // fin namespace gui

#endif
