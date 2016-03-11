#ifndef GEOMETRIE__H
#define GEOMETRIE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Composite.h"
#include <SFML/Graphics.hpp>
#include <iostream>



namespace gui {

/////////////////////////////////////////////////
/// \brief Concerne la partie geometrique des gadgets, comme la taille, contient, position absolue...
///
/////////////////////////////////////////////////
class Geometrie : public sf::Transformable, public gui::Composite {


/////////////////////////////////////////////////
// Enums & typedefs
/////////////////////////////////////////////////

    /////////////////////////////////////////////////
    /// \brief les 9 endroits d'alignement entre gadgets
    /////////////////////////////////////////////////
    enum class Alignement {
        Centre,
        Gauche,
        Droite,
        Haut,
        Bas,
        GaucheHaut,
        GaucheBas,
        DroiteHaut,
        DroiteBas
    };

/////////////////////////////////////////////////
// M�thodes
/////////////////////////////////////////////////

public:
    ///< Definir m_taille
    virtual void setTaille( float x, float y ){ m_taille = {x,y}; actualiser(); };
    virtual void setTaille( sf::Vector2i val ){ m_taille = val; actualiser(); };
    virtual void setTailleX( float val ){ m_taille.x = val; actualiser(); };
    virtual void setTailleY( float val ){ m_taille.y = val; actualiser(); };

    ///< Acceder � m_taille
    virtual sf::Vector2i getTaille () const { return m_taille;  };

    ///< Acceder � m_localBounds
    sf::FloatRect getLocalBounds () const { return m_localBounds; };

    ///< Acceder � m_globalBounds
    sf::FloatRect getGlobalBounds () const { return m_globalBounds; };

    ///< Definir m_opacite
    void setOpacite( double val ){ m_opacite = val; actualiserStyle();  };

    ///< Acceder � m_taille
    double getOpacite () const { return m_opacite; };

    ///< reDefinir setPosition
    virtual     void setPosition( float x , float y );

    /////////////////////////////////////////////////
    /// \brief Calculer la position absolue du gadget.
    ///
    /////////////////////////////////////////////////
    sf::Vector2f getPosAbs () const;

    /////////////////////////////////////////////////
    /// \brief S'aligner sur un autre gadget.
    ///
    /// \param cible		 gadget cible sur lequel s'aligner.
    /// \param alignement		 L'endroit du gadget � aligner sur la cible.
    /// \param alignementCible		 L'endroit de la cible sur lequel aligner le gadget.
    /////////////////////////////////////////////////
    void Aligner ( std::shared_ptr<Gadget> cible, Alignement alignement, Alignement alignementCible );

    /////////////////////////////////////////////////
    /// \brief Actualiser .
    ///
    /////////////////////////////////////////////////
    virtual void actualiser (){std::cout << "ACTUALISER GEOMETRIE_H\n";};

    /////////////////////////////////////////////////
    virtual void actualiserGeometrie (){};

    /////////////////////////////////////////////////
    virtual void actualiserStyle (){};

    /////////////////////////////////////////////////
    /// \brief Actualiser les membres bounds local et global.
    ///
    /////////////////////////////////////////////////
    virtual void actualiserBounds ();

/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
protected:
    sf::Vector2i    m_taille;           ///< la taille permet d'organiser la disposition des �l�ments graphiques du gadget.
    sf::FloatRect   m_localBounds;      ///< la rectangle englobant du gadget en coordonn�s locales.
    sf::FloatRect   m_globalBounds;     ///< la rectangle englobant du gadget en coordonn�s globales.
    double          m_opacite = 1;      ///< L'opacit� du gadget ( entre 0 et 1 )


}; // fin class Geometrie

} // fin namespace gui

#endif
