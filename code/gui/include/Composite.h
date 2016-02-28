#ifndef COMPOSITE__H
#define COMPOSITE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "SFML/Graphics.hpp"
#include <memory>
#include <vector>
#include <iostream>



namespace gui {

class Gadget;


/////////////////////////////////////////////////
/// \brief Gestion des enfants, parent (GOF4: composite)
///
/////////////////////////////////////////////////
class Composite {



/////////////////////////////////////////////////
// M�thodes
/////////////////////////////////////////////////

public:
    ///< Definir m_parent
    void setParent( Gadget* val ){ m_parent = val; };

    ///< Acceder � m_parent
    Gadget* getParent () const { return m_parent; };

    virtual std::shared_ptr<Gadget> thisPtr(){
        std::cout << "DEMANDE DE thisPtr PROBLEMATIQUE\n";
        return nullptr;
    };

protected:
    /////////////////////////////////////////////////
    /// \brief Ajouter un gadget � la liste de gadgets enfant.
    ///
    /// \param enfant		 L'enfant � ajouter.
    /////////////////////////////////////////////////
    virtual void ajouter (std::shared_ptr<Gadget> enfant);

    /////////////////////////////////////////////////
    /// \brief Retirer un enfant de la liste des enfants de ce gadget sans le supprimer.
    ///
    /// \param enfant		 L'enfant � retirer de la liste des enfants.
    /// \return L'enfant supprimer des enfants.
    /////////////////////////////////////////////////
    virtual std::shared_ptr<Gadget> retirer (std::shared_ptr<Gadget> enfant);

    /////////////////////////////////////////////////
    /// \brief Demander au parent de nous supprimer.
    ///
    /////////////////////////////////////////////////
    virtual void demander_aEtre_supprimer ();

    /////////////////////////////////////////////////
    /// \brief Supprimer un gadget.
    ///
    /// \param enfant		 L'enfant � supprimer.
    /////////////////////////////////////////////////
    virtual void supprimer (std::shared_ptr<Gadget> enfant);

    /////////////////////////////////////////////////
    /// \brief Demander au parent d'�tre mis au dessus des autres gadgets ( mouvements de la liste des enfants).
    ///
    /////////////////////////////////////////////////
    void demander_aEtre_auDessus () const {};

    /////////////////////////////////////////////////
    /// \brief Mettre au dessus des autres gadgets ( mouvements de la liste des enfants).
    ///
    /// \param gadget		 le pointeur vers le gadget � mettre au dessus des autres parmis m_enfants.
    /////////////////////////////////////////////////
    virtual void mettre_auDessus ( std::shared_ptr<Gadget> gadget) {};

    /////////////////////////////////////////////////
    /// \brief Dessiner les enfants du gadget.
    ///
    /// \param target
    /// \param states
    /////////////////////////////////////////////////
    void dessinerEnfants (sf::RenderTarget& target, sf::RenderStates states) const {};


/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
protected:
    std::vector<std::shared_ptr<Gadget>>    m_enfants;          ///< Les enfants du gadget.
    Gadget*                                 m_parent = nullptr; ///< Le gadget parent.

}; // fin class Composite

} // fin namespace gui

#endif
