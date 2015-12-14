#ifndef COMPOSITE__H
#define COMPOSITE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <memory>
#include <vector>



namespace gui {

class Gadget;


/////////////////////////////////////////////////
/// \brief Gestion des enfants, parent (GOF4: composite)
///
/////////////////////////////////////////////////
class Composite {


/////////////////////////////////////////////////
// Enums & typedefs
/////////////////////////////////////////////////
    typedef std::shared_ptr<Gadget> ptr;    ///< Pointeur vers un gadget.


/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////

public:
    ///< Definir m_parent
    void setParent( ptr val ){ m_parent = val; };

    ///< Acceder à m_parent
    ptr getParent () const { return m_parent; };

public:
    /////////////////////////////////////////////////
    /// \brief Ajouter un gadget dans la liste des enfants.
    ///
    /// \param enfant		 le gadget à ajouter.
    /////////////////////////////////////////////////
    virtual void ajouter (ptr enfant);

    /////////////////////////////////////////////////
    /// \brief Retirer un enfant de la liste des enfants.
    ///
    /// \param enfant		 L'enfant à retirer.
    /////////////////////////////////////////////////
    virtual void retirer (ptr enfant);

protected:
    /////////////////////////////////////////////////
    /// \brief Demander au parent de nous supprimer.
    ///
    /////////////////////////////////////////////////
    void demander_aEtre_supprimer ();

    /////////////////////////////////////////////////
    /// \brief Demander au parent d'être mis au dessus des autres gadgets ( mouvements de la liste des enfants).
    ///
    /////////////////////////////////////////////////
    void demander_aEtre_auDessus () const;

    /////////////////////////////////////////////////
    /// \brief  Demander au parent d'être mis au dessus des autres gadgets ( mouvements de la liste des enfants).
    ///
    /// \param gadget		 le pointeur vers le gadget à mettre au dessus des autres parmis m_enfants.
    /////////////////////////////////////////////////
    void mettre_auDessus (ptr gadget);



/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
protected:
    ptr m_parent;     ///< Pointeur vers un gadget.#G#S
    std::vector<ptr>  m_enfants;     ///< Pointeur vers un gadget.

}; // fin class Composite

} // fin namespace gui

#endif
