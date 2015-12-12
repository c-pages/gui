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
// M�thodes
/////////////////////////////////////////////////

public:
    ///< Definir m_parent
    void setParent( ptr val ){ m_parent = val; };

    ///< Acceder � m_parent
    ptr getParent () const { return m_parent; };

    ///< Ajouter un �lement dans m_enfants
    void ajouterEnfant ( ptr nouvelElement ){ m_enfants.push_back( nouvelElement ); };

    ///< retirer l'�lement � la position id dans m_enfants
    void retirerEnfant ( int id ) { if ( id>=0 || id<m_enfants.size() ) m_enfants.erase( m_enfants.begin() + id ); };

    ///< Vider m_enfants
    void viderEnfant () { m_enfants.clear(); };

    ///< Accesseur � l'�l�ment de m_enfants d�sign� par un id.
    ptr getEnfant ( int id ) const { if ( id>=0 || id<m_enfants.size() )  return m_enfants.at( id ); else return 0; };

protected:
    /////////////////////////////////////////////////
    /// \brief Demander au parent de nous supprimer.
    ///
    /////////////////////////////////////////////////
    void demander_aEtre_supprimer ();

    /////////////////////////////////////////////////
    /// \brief Demander au parent d'�tre mis au dessus des autres gadgets ( mouvements de la liste des enfants).
    ///
    /////////////////////////////////////////////////
    void demander_aEtre_auDessus () const;

    /////////////////////////////////////////////////
    /// \brief  Demander au parent d'�tre mis au dessus des autres gadgets ( mouvements de la liste des enfants).
    ///
    /// \param gadget		 le pointeur vers le gadget � mettre au dessus des autres parmis m_enfants.
    /////////////////////////////////////////////////
    void mettre_auDessus (ptr gadget);



/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
protected:
    ptr m_parent;     ///< Pointeur vers un gadget.#G#S
    std::vector<ptr>  m_enfants;     ///< Pointeur vers un gadget.#A#R#V#G

}; // fin class Composite

} // fin namespace gui

#endif
