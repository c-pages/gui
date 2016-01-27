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
/// \brief Classe des boutons ( �l�ments interactifs de l'interface). ( D�riv� du GOf4 d�coration ).
///
/////////////////////////////////////////////////
class Cliquable : public Gadget {



/////////////////////////////////////////////////
// Enums & typedefs
/////////////////////////////////////////////////
    typedef std::shared_ptr<Cliquable> clickPtr;    ///< Pointeur vers un gadget.


/////////////////////////////////////////////////
// M�thodes
/////////////////////////////////////////////////

public:
    /*
    /////////////////////////////////////////////////
    /// \brief  Fonction static pour gerer globalement les �v�nements de l'interface.
    ///
    /////////////////////////////////////////////////
    void static s_traiterEvents ();
    */

    /////////////////////////////////////////////////
    /// \brief Red�finie ajouter par une fonction vide( GOF4 : composite -> Feuilles)
    ///
    /////////////////////////////////////////////////
    virtual void ajouter (){};

    /////////////////////////////////////////////////
    /// \brief Red�finie retirer par une fonction vide( GOF4 : composite -> Feuilles)
    ///
    /////////////////////////////////////////////////
    virtual void retirer (){};

    virtual void testerSurvol ();

    /////////////////////////////////////////////////
    /// \brief Actualise le style du gadget (apr�s une modification, de son �tat par exemple).
    ///
    /////////////////////////////////////////////////
    void actualiser ();

    /////////////////////////////////////////////////
    /// \brief D�finie un nouvel �tat pour le bouton, puis actualise le style.
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
//    static clickPtr                 ms_btnSurvole;      ///< Pointeur static vers le bouton qui � le focus du survol.
//    static clickPtr                 ms_btnPresse;       ///< Pointeur static vers le bouton de l'interface qui est en train d'�tre press�.

}; // fin class Cliquable

} // fin namespace gui

#endif
