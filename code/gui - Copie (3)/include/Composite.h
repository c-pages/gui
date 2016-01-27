#ifndef COMPOSITE__H
#define COMPOSITE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>



namespace gui {


class Gadget;
//class ptr;

/////////////////////////////////////////////////
/// \brief Gestion des enfants, parent (GOF4: composite)
///
/////////////////////////////////////////////////
class Composite {




/////////////////////////////////////////////////
// Enums & typedefs
/////////////////////////////////////////////////
  //  typedef std::shared_ptr<Gadget> ptr;    ///< Pointeur vers un gadget.

/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////

public:
    ///< Ajouter un élement dans m_enfants
    void ajouterAEnfants ( std::shared_ptr<Gadget> nouvelElement ){ m_enfants.push_back( nouvelElement ); };

    ///< retirer l'élement à la position id dans m_enfants
    void retirerAEnfants ( int id ) { if ( id>=0 || id<m_enfants.size() ) m_enfants.erase( m_enfants.begin() + id ); };

    ///< Vider m_enfants
    void viderEnfants () { m_enfants.clear(); };

    ///< Accesseur à l'élément de m_enfants désigné par un id.
    std::shared_ptr<Gadget> getEnfants ( int id ) const { if ( id>=0 || id<m_enfants.size() )  return m_enfants.at( id ); else return 0; };

    ///< Definir m_parent
    void setParent( std::shared_ptr<Gadget>  val );

    ///< Acceder à m_parent
    std::shared_ptr<Gadget>  getParent () const { return m_parent; };

public:
    void dessinerEnfants (sf::RenderTarget& target, sf::RenderStates states) const;

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
    /// \brief Mettre au dessus des autres gadgets ( mouvements de la liste des enfants).
    ///
    /// \param gadget		 le pointeur vers le gadget à mettre au dessus des autres parmis m_enfants.
    /////////////////////////////////////////////////
    void mettre_auDessus (std::shared_ptr<Gadget> gadget);



/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
public:
    std::vector<std::shared_ptr<Gadget>>    m_enfants;      ///< Les enfants du gadget.#A#R#V#G
    std::shared_ptr<Gadget>                 m_parent;       ///< #G#S

}; // fin class Composite

} // fin namespace gui

#endif
