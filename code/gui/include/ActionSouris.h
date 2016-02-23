#ifndef ACTIONSOURIS__H
#define ACTIONSOURIS__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <map>
#include <functional>



namespace gui {



/////////////////////////////////////////////////
/// \brief Classe abstraite qui gère les évenements claviers et souris
///
/////////////////////////////////////////////////
class ActionSouris {


/////////////////////////////////////////////////
// Enums & typedefs
/////////////////////////////////////////////////
    /////////////////////////////////////////////////
    /// \brief les evenements de la souris qui déclenchent une fonction lambda associée.
    /////////////////////////////////////////////////
    enum Evenement {
        onBtnG_dblCliquer,            ///< Double clique gauche
        onBtnG_relacher,            ///< Relache le bouton gauche de la souris.
        onBtnG_relacherDehors,            ///< Relache a coté du gadget avec le bouton gauche de la souris après avoir pressé dedans.
        onBtnG_presser,            ///< Presse le bouton gauche de la souris.
        onBtnG_presserDehors,            ///< Presse a coté du gadget avec le bouton gauche de la souris.
        onBtnD_relacher,            ///< Relache le bouton droit de la souris.
        onBtnD_relacherDehors,            ///< Relache le bouton droit de la souris.
        onBtnD_presser,            ///< Presse le bouton droit de la souris.
        onBtnM_relacher,            ///< Relache le bouton du milieu de la souris.
        onBtnM_relacherDehors,            ///< Relache le bouton du milieu de la souris.
        onBtnM_presser,            ///< Presse le bouton du milieu de la souris.
        onBtnM_roulerHaut,            ///< Roule vers le haut le bouton du milieu de la souris.
        onBtnM_roulerBas,            ///< Roule vers le bas le bouton du milieu de la souris.
        onBtn_entrer,            ///< Survol
        onBtn_sortir,            ///< Quitte le survol.
        onBtn_changerEtat,            ///< quand BoutonACocher change d'état
        onFen_fermer,            ///< Quand on ferme une fenetre.
        onFen_ouvrir,            ///< Quand on ferme une fenetre.
        onBool_changerValeur,            ///< Quand on change la valeur d'un champ de saisie de texte.
        onBool_validerValeur            ///< Quand on valide la valeur d'un champ de saisie de texte.
    };

    using FctnAction = std::function<void()>;    ///< le type de fonction associé aux declenchements des evenements.


/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////

public:
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
    void declencher (Evenement evenement);



/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:
    std::map < Evenement , FctnAction > m_evenementsSouris;    ///< la liste des evenements souris enregistrés.    

}; // fin class ActionSouris

} // fin namespace gui

#endif
