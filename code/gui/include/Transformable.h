#ifndef TRANSFORMABLE__H
#define TRANSFORMABLE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Vec2.h"


namespace gui {
//
//class Vec2;
//class Vec2;


/////////////////////////////////////////////////
/// \brief Classe de base de transfomation des gadgets.
///
/////////////////////////////////////////////////
class Transformable {



/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////

public:
    ///< Definir m_position
    void setPosition( Vec2 val ){ m_position = val; };

    ///< Acceder à m_position
    Vec2 getPosition () const { return m_position; };

    ///< Definir m_profondeur
    void setProfondeur( int val ){ m_profondeur = val; };

    ///< Acceder à m_profondeur
    int getProfondeur () const { return m_profondeur; };

    ///< Acceder à m_taille
    Vec2 getTaille () const { return m_taille; };

public:
    /////////////////////////////////////////////////
    /// \brief Renvois la position absolue du gadget.
    ///
    /////////////////////////////////////////////////
    Vec2 getPosAbs () const;

    virtual void setTaille (Vec2 taille){m_taille = taille;};



/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:
    Vec2 m_position;    ///< La position du gadget dans le fanetre.
    int m_profondeur;    ///< La profondeur du gadget. (0: fond)
    Vec2 m_taille;    ///< La taille du gadget (en pixel).
    float m_opacite;    ///< L'opacité du gadget (peut etre utile si animations) (0.0->1.0).

}; // fin class Transformable

} // fin namespace gui

#endif
