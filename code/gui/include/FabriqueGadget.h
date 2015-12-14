#ifndef FABRIQUEGADGET__H
#define FABRIQUEGADGET__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <memory>



namespace gui {

class Gadget;
/////////////////////////////////////////////////
// Enums & typedefs
/////////////////////////////////////////////////
    typedef std::shared_ptr<Gadget> ptr;    ///< Pointeur vers un gadget.


/////////////////////////////////////////////////
/// \brief Fonctions de creation des gadgets.
///
/////////////////////////////////////////////////
class FabriqueGadget {




/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////

public:
public:
    ptr texte ();

    ptr image ();

    ptr info ();

    ptr log ();

    ptr fenetre ();

    ptr infobulle ();

    ptr bouton ();

    ptr bouton_icone ();

    ptr bouton_interrupteur ();

    ptr saisie_texte ();

    ptr saisie_num ();

    ptr saisie_curseur ();

    ptr groupe ();

    ptr agenceur ();

    ptr panneau ();

    ptr panneau_deroulant ();

    ptr panneau_flattant ();

    ptr panneau_integre ();



/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////

}; // fin class FabriqueGadget

} // fin namespace gui

#endif
