#ifndef CONTENEUR__H
#define CONTENEUR__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Gadget.h"
#include "Repartiteur.h"

#include <vector>
#include <memory>



namespace gui {

class Gadget;
class Conteneur;


/////////////////////////////////////////////////
/// \brief Permet de contenir plusieur gadgets.
///
/////////////////////////////////////////////////
class Conteneur : public gui::Gadget {


/////////////////////////////////////////////////
// Enums & typedefs
/////////////////////////////////////////////////
public:
    typedef std::shared_ptr<Conteneur> ptr;    ///< Pointeur vers un conteneur.


/////////////////////////////////////////////////
// M�thodes
/////////////////////////////////////////////////

public:
    ///< Ajouter un �lement dans m_enfants
    void ajouterAEnfants ( Gadget::ptr nouvelElement ){ m_enfants.push_back( nouvelElement ); };

    ///< retirer l'�lement � la position id dans m_enfants
    void retirerAEnfants ( int id ) { if ( id>=0 || id<m_enfants.size() ) m_enfants.erase( m_enfants.begin() + id ); };

    ///< Vider m_enfants
    void viderEnfants () { m_enfants.clear(); };

public:
    /////////////////////////////////////////////////
    /// \brief Supprime un gadget enfant.
    ///
    /// \param enfant		 Le gadget � supprimer.
    /////////////////////////////////////////////////
    void supprimerEnfant (Gadget::ptr enfant);

    /////////////////////////////////////////////////
    /// \brief Place l'enfant au dessus des autres.
    ///
    /// \param enfant		 L'enfant � placer au dessus.
    /////////////////////////////////////////////////
    void mettreAuDessusEnfant (Gadget::ptr enfant);

    /////////////////////////////////////////////////
    /// \brief Donne le focus � un gadget enfant.
    ///
    /// \param enfant
    /////////////////////////////////////////////////
    void focus (const Gadget::ptr& enfant);

    /////////////////////////////////////////////////
    /// \brief Donne le focus � l'enfant suivant.
    ///
    /////////////////////////////////////////////////
    void focus_EnfantSuivant ();

    /////////////////////////////////////////////////
    /// \brief Donne le focus � l'enfant pr�c�dant.
    ///
    /////////////////////////////////////////////////
    void focus_enfantPrecedant ();

    /////////////////////////////////////////////////
    /// \brief Retire le focus � tout les gadgets enfants.
    ///
    /////////////////////////////////////////////////
    void focus_aucunEnfant ();

    /////////////////////////////////////////////////
    /// \brief D�cocher tout les boutons radio des enfants du conteneur.
    ///
    /////////////////////////////////////////////////
    void decocherBoutonsRadio ();

    /////////////////////////////////////////////////
    /// \brief Demander � tout les enfants du conteneur de se dessiner.
    ///
    /// \param target
    /// \param states
    /////////////////////////////////////////////////
    void draw_enfants (sf::RenderTarget& target, sf::RenderStates states) const;

    /////////////////////////////////////////////////
    /// \brief Dessiner le conteneur et son contenu.
    ///
    /// \param target
    /// \param states
    /////////////////////////////////////////////////
    void draw (sf::RenderTarget& target, sf::RenderStates states) const;



/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
protected:
    std::vector<Gadget::ptr> m_enfants;    ///< Les gadgets enfants de conteneur.#A#R#V
    unsigned int m_focusEnfant;    ///< L'id de l'enfant qui � le focus (0: Pas de focus).
    Repartiteur m_repartiteur;    ///< Le repartiteur organise la disposition des gadgets. (null : organisation libre)
    friend class Gadget;

}; // fin class Conteneur

} // fin namespace gui

#endif
