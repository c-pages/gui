#ifndef BOUTON__H
#define BOUTON__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Gadget.h"
#include <vector>
#include <memory>
#include "AfficheRectangle.h"



namespace gui {

class Bouton;
class Bouton;
class Bouton;


/////////////////////////////////////////////////
/// \brief Classe des boutons ( éléments interactifs de l'interface). ( Dérivé du GOf4 décoration ).
///
/////////////////////////////////////////////////
class Bouton : public gui::Gadget {


/////////////////////////////////////////////////
// Enums & typedefs
/////////////////////////////////////////////////
    /////////////////////////////////////////////////
    /// \brief (Pattern: Etat)
    /////////////////////////////////////////////////
    enum Etat {
        Repos,
        Survol,
        Presse
    };



/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////

public:
    ///< Acceder à m_etat
    Etat getEtat () const { return m_etat; };

public:
    /////////////////////////////////////////////////
    /// \brief  Fonction static pour gerer globalement les événements de l'interface.
    ///
    /////////////////////////////////////////////////
    static s_traiterEvents ();

    /////////////////////////////////////////////////
    /// \brief Redéfinie ajouter par une fonction vide( GOF4 : composite -> Feuilles)
    ///
    /////////////////////////////////////////////////
    ajouter ();

    /////////////////////////////////////////////////
    /// \brief Redéfinie retirer par une fonction vide( GOF4 : composite -> Feuilles)
    ///
    /////////////////////////////////////////////////
    retirer ();

    testerSurvol ();

    /////////////////////////////////////////////////
    /// \brief Actualise le style du gadget (après une modification, de son état par exemple).
    ///
    /////////////////////////////////////////////////
    actualiser ();

    /////////////////////////////////////////////////
    /// \brief Définie un nouvel état pour le bouton, puis actualise le style.
    ///
    /////////////////////////////////////////////////
    void setEtat ();



/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:
    static std::vector<Bouton> ms_Boutons;    ///< La liste static totale des boutons.    
    static std::shared_ptr<Bouton> ms_btnSurvole;    ///< Pointeur static vers le bouton qui à le focus du survol.    
    static std::shared_ptr<Bouton> ms_btnPresse;    ///< Pointeur static vers le bouton de l'interface qui est en train d'être pressé.    
    Etat m_etat;    ///<  L'état du bouton. (#G)    
    std::shared_ptr<gui::AfficheRectangle> m_zoneClique;

}; // fin class Bouton

} // fin namespace gui

#endif
