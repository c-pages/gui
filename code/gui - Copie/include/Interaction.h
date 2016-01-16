#ifndef INTERACTION__H
#define INTERACTION__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <map>
#include <SFML/Graphics.hpp>
#include <functional>



namespace gui {



/////////////////////////////////////////////////
/// \brief Classe abstraite qui g�re les �venements claviers et souris
///
/////////////////////////////////////////////////
class Interaction {


/////////////////////////////////////////////////
// Enums & typedefs
/////////////////////////////////////////////////
    /////////////////////////////////////////////////
    /// \brief les evenements de la souris qui d�clenchent une fonction lambda associ�e.
    /////////////////////////////////////////////////
    enum Evenement {
        on_entrer,            ///< Survol
        on_sortir,            ///< Quitte le survol.
        on_BtnG_dblCliquer,            ///< Double clique gauche
        on_BtnG_relacher,            ///< Relache le bouton gauche de la souris.
        on_BtnG_relacherDehors,            ///< Relache a cot� du gadget avec le bouton gauche de la souris apr�s avoir press� dedans.
        on_BtnG_presser,            ///< Presse le bouton gauche de la souris.
        on_BtnG_presserDehors,            ///< Presse a cot� du gadget avec le bouton gauche de la souris.
        on_BtnD_relacher,            ///< Relache le bouton droit de la souris.
        on_BtnD_relacherDehors,            ///< Relache le bouton droit de la souris.
        on_BtnD_presser,            ///< Presse le bouton droit de la souris.
        on_BtnM_relacher,            ///< Relache le bouton du milieu de la souris.
        on_BtnM_relacherDehors,            ///< Relache le bouton du milieu de la souris.
        on_BtnM_presser,            ///< Presse le bouton du milieu de la souris.
        on_BtnM_roulerHaut,            ///< Roule vers le haut le bouton du milieu de la souris.
        on_BtnM_roulerBas,            ///< Roule vers le bas le bouton du milieu de la souris.
        on_Bool_changerValeur            ///< Quand on change la valeur d'un champ de saisie de texte.
    };

    using FctnAction = std::function<void()>;    ///< le type de fonction associ� aux declenchements des evenements.


/////////////////////////////////////////////////
// M�thodes
/////////////////////////////////////////////////

public:
public:
    /////////////////////////////////////////////////
    /// \brief Cr�er une nouvelle liaison entre un evenement souris  et une fonction lambda.
    ///
    /// \param evenement		 evenement souris
    /// \param fonction		 Le fonction � d�clencher.
    /////////////////////////////////////////////////
    void lier  (Evenement evenement, FctnAction fonction);

    /////////////////////////////////////////////////
    /// \brief Cr�er une nouvelle liaison entre un evenement clavier  et une fonction lambda.
    ///
    /// \param touche		 la touche du clavier.
    /// \param fonction		 Le fonction � d�clencher.
    /////////////////////////////////////////////////
    void lier ( sf::Keyboard  touche, FctnAction fonction);

    /////////////////////////////////////////////////
    /// \brief Supprime une liaison entre un evenement souris  et une fonction lambda.
    ///
    /// \param evenement		 L'�venement � supprimer
    /////////////////////////////////////////////////
    void delier (Evenement evenement);

    /////////////////////////////////////////////////
    /// \brief Supprime une liaison entre un evenement clavier  et une fonction lambda.
    ///
    /// \param touche		 
    /////////////////////////////////////////////////
    void delier ( sf::Keyboard  touche);

    /////////////////////////////////////////////////
    /// \brief D�clencher un �venement souris (les �venement claviers sont g�rer.
    ///
    /// \param evenement		 
    /////////////////////////////////////////////////
    void declencher (Evenement evenement);



/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:
    std::map < Evenement , FctnAction > m_evenementsSouris;    ///< la liste des evenements souris enregistr�s.    
    std::map < sf::Keyboard  , FctnAction > m_evenementsClavier;    ///<  la liste des evenements claviers enregistr�s.    

}; // fin class Interaction

} // fin namespace gui

#endif
