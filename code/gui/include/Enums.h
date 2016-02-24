#ifndef ENUMS_H_INCLUDED
#define ENUMS_H_INCLUDED


namespace gui {
/////////////////////////////////////////////////
/// \brief les evenements de la souris qui d�clenchent une fonction lambda associ�e.
/////////////////////////////////////////////////
enum class Evenement {
    onBtnG_dblCliquer,      ///< Double clique gauche
    onBtnG_relacher,        ///< Relache le bouton gauche de la souris.
    onBtnG_relacherDehors,  ///< Relache a cot� du gadget avec le bouton gauche de la souris apr�s avoir press� dedans.
    onBtnG_presser,         ///< Presse le bouton gauche de la souris.
    onBtnG_presserDehors,   ///< Presse a cot� du gadget avec le bouton gauche de la souris.
    onBtnD_relacher,        ///< Relache le bouton droit de la souris.
    onBtnD_relacherDehors,  ///< Relache le bouton droit de la souris.
    onBtnD_presser,         ///< Presse le bouton droit de la souris.
    onBtnM_relacher,        ///< Relache le bouton du milieu de la souris.
    onBtnM_relacherDehors,  ///< Relache le bouton du milieu de la souris.
    onBtnM_presser,         ///< Presse le bouton du milieu de la souris.
    onBtnM_roulerHaut,      ///< Roule vers le haut le bouton du milieu de la souris.
    onBtnM_roulerBas,       ///< Roule vers le bas le bouton du milieu de la souris.
    on_entrer,              ///< Survol
    on_sortir,              ///< Quitte le survol.
    onBtn_changerEtat,      ///< quand BoutonACocher change d'�tat
    onFen_fermer,           ///< Quand on ferme une fenetre.
    onFen_ouvrir,           ///< Quand on ferme une fenetre.
    onBool_changerValeur,   ///< Quand on change la valeur d'un champ de saisie de texte.
    onBool_validerValeur    ///< Quand on valide la valeur d'un champ de saisie de texte.
};




}; // fin namespace gui

#endif // ENUMS_H_INCLUDED
