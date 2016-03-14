#ifndef LISTE__H
#define LISTE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "ActionEvenement.h"
#include <vector>



namespace gui {



template <typename T>
class Liste : public gui::ActionEvenement {



/////////////////////////////////////////////////
// M�thodes
/////////////////////////////////////////////////

public:
    ///< Ajouter un �lement dans m_elements
    void ajouterAElements ( (null) nouvelElement ){ m_elements.push_back( nouvelElement ); };

    ///< retirer l'�lement � la position id dans m_elements
    void retirerAElements ( int id ) { if ( id>=0 || id<m_elements.size() ) m_elements.erase( m_elements.begin() + id ); };

    ///< Accesseur � l'�l�ment de m_elements d�sign� par un id.
    (null) getElements ( int id ) const { if ( id>=0 || id<m_elements.size() )  return m_elements.at( id ); else return 0; };

    ///< Definir m_selection
    void setSelection( int val ){ m_selection = val; };

    ///< Acceder � m_selection
    int getSelection () const { return m_selection; };

public:
    Liste ();



/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:
    std::vector<T> m_elements;    ///< #A#R#G#R    
    int m_selection;    ///< Renvois -1 si aucune selection. #G#S    

}; // fin class Liste

} // fin namespace gui

#endif
