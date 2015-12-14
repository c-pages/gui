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
/// \brief Classe des boutons ( �l�ments interactifs de l'interface). ( D�riv� du GOf4 d�coration ).
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
// M�thodes
/////////////////////////////////////////////////

public:
    ///< Acceder � m_etat
    Etat getEtat () const { return m_etat; };

public:
    /////////////////////////////////////////////////
    /// \brief  Fonction static pour gerer globalement les �v�nements de l'interface.
    ///
    /////////////////////////////////////////////////
    static s_traiterEvents ();

    /////////////////////////////////////////////////
    /// \brief Red�finie ajouter par une fonction vide( GOF4 : composite -> Feuilles)
    ///
    /////////////////////////////////////////////////
    ajouter ();

    /////////////////////////////////////////////////
    /// \brief Red�finie retirer par une fonction vide( GOF4 : composite -> Feuilles)
    ///
    /////////////////////////////////////////////////
    retirer ();

    testerSurvol ();

    /////////////////////////////////////////////////
    /// \brief Actualise le style du gadget (apr�s une modification, de son �tat par exemple).
    ///
    /////////////////////////////////////////////////
    actualiser ();

    /////////////////////////////////////////////////
    /// \brief D�finie un nouvel �tat pour le bouton, puis actualise le style.
    ///
    /////////////////////////////////////////////////
    void setEtat ();



/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:
    static std::vector<Bouton> ms_Boutons;    ///< La liste static totale des boutons.    
    static std::shared_ptr<Bouton> ms_btnSurvole;    ///< Pointeur static vers le bouton qui � le focus du survol.    
    static std::shared_ptr<Bouton> ms_btnPresse;    ///< Pointeur static vers le bouton de l'interface qui est en train d'�tre press�.    
    Etat m_etat;    ///<  L'�tat du bouton. (#G)    
    std::shared_ptr<gui::AfficheRectangle> m_zoneClique;

}; // fin class Bouton

} // fin namespace gui

#endif
