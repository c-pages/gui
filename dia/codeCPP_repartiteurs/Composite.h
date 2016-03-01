#ifndef COMPOSITE__H
#define COMPOSITE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <memory>
#include <vector>



namespace gui {

class Gadget;
class Gadget;


/////////////////////////////////////////////////
/// \brief Gestion des enfants, parent (GOF4: composite)
///
/////////////////////////////////////////////////
class Composite {



/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////

public:
    ///< Definir m_parent
    void setParent( Gadget* val ){ m_parent = val; };

    ///< Acceder à m_parent
    Gadget* getParent () const { return m_parent; };

protected:
    /////////////////////////////////////////////////
    /// \brief Ajouter un gadget à la liste de gadgets enfant.
    ///
    /// \param enfant		 L'enfant à ajouter.
    /////////////////////////////////////////////////
    virtual void ajouter (std::shared_ptr<Gadget> enfant);

    /////////////////////////////////////////////////
    /// \brief Retirer un enfant de la liste des enfants de ce gadget sans le supprimer.
    ///
    /// \param enfant		 L'enfant à retirer de la liste des enfants.
    /////////////////////////////////////////////////
    virtual void retirer (std::shared_ptr enfant);

    /////////////////////////////////////////////////
    /// \brief Demander au parent de nous supprimer.
    ///
    /////////////////////////////////////////////////
    virtual void demander_aEtre_supprimer () = 0;

    /////////////////////////////////////////////////
    /// \brief Supprimer un gadget.
    ///
    /// \param enfant		 L'enfant à supprimer.
    /////////////////////////////////////////////////
    virtual void supprimer (std::shared_ptr<Gadget> enfant);

    /////////////////////////////////////////////////
    /// \brief Demander au parent d'être mis au dessus des autres gadgets ( mouvements de la liste des enfants).
    ///
    /////////////////////////////////////////////////
    void demander_aEtre_auDessus () const;

    /////////////////////////////////////////////////
    /// \brief Mettre au dessus des autres gadgets ( mouvements de la liste des enfants).
    ///
    /// \param gadget		 le pointeur vers le gadget à mettre au dessus des autres parmis m_enfants.
    /////////////////////////////////////////////////
    virtual void mettre_auDessus (ptr gadget);

    /////////////////////////////////////////////////
    /// \brief Dessiner les enfants du gadget.
    ///
    /// \param target		 
    /// \param states		 
    /////////////////////////////////////////////////
    void dessinerEnfants (sf::RenderTarget& target, sf::RenderStates states) const;



/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:
    std::vector<std::shared_ptr<Gadget>> m_enfants;    ///< Les enfants du gadget.    
    Gadget* m_parent;    ///< Le gadget parent.#G#S    

}; // fin class Composite

} // fin namespace gui

#endif
