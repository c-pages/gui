#ifndef COMPOSANT__H
#define COMPOSANT__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <memory>
#include <vector>



namespace gui {

class Gadget;


/////////////////////////////////////////////////
/// \brief Gestion des gadgets qui compose l'interface de ce gadget, parent (GOF4: composite)
///
/////////////////////////////////////////////////
class Composant {



/////////////////////////////////////////////////
// M�thodes
/////////////////////////////////////////////////

public:
public:
    virtual void traiterEvenementsComposants (const sf::Event& evenement);

protected:
    /////////////////////////////////////////////////
    /// \brief Ajouter un gadget � la liste de gadgets enfant.
    ///
    /// \param enfant		 L'enfant � ajouter.
    /////////////////////////////////////////////////
    virtual void ajouterComposant (std::shared_ptr<Gadget> enfant);

    /////////////////////////////////////////////////
    /// \brief Retirer un enfant de la liste des enfants de ce gadget sans le supprimer.
    ///
    /// \param enfant		 L'enfant � retirer de la liste des enfants.
    /////////////////////////////////////////////////
    virtual void retirerComposant (std::shared_ptr enfant);

    /////////////////////////////////////////////////
    /// \brief Mettre au dessus des autres gadgets ( mouvements de la liste des enfants).
    ///
    /// \param gadget		 le pointeur vers le gadget � mettre au dessus des autres parmis m_enfants.
    /////////////////////////////////////////////////
    virtual void mettre_composantAuDessus (ptr gadget);

    std::shared_ptr<Gadget> testerSurvolComposants (sf::Vector2i position);

    /////////////////////////////////////////////////
    /// \brief Dessiner les enfants du gadget.
    ///
    /// \param target		 
    /// \param states		 
    /////////////////////////////////////////////////
    void dessinerComposant (sf::RenderTarget& target, sf::RenderStates states) const;



/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:
    std::vector<std::shared_ptr<Gadget>> m_composants;    ///< Les enfants du gadget.    

}; // fin class Composant

} // fin namespace gui

#endif
