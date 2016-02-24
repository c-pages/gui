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
    /// \brief les 9 endroits d'alignement entre gadget
    /////////////////////////////////////////////////
    enum Alignement {
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
// Méthodes
/////////////////////////////////////////////////

public:
    ///< Definir m_taille
    virtual void setTaille( sf::Vector2i val ){ m_taille = val; actualiser_bounds(); actualiser(); };

    ///< Acceder à m_taille
    sf::Vector2i getTaille () const { return m_taille; };

    ///< Acceder à m_localBounds
    sf::FloatRect getLocalBounds () const { return m_localBounds; };

    ///< Acceder à m_globalBounds
    sf::FloatRect getGlobalBounds () const { return m_globalBounds; };

    ///< Definir m_opacite
    void setOpacite( double val ){ m_opacite = val; actualiser();  };

    ///< Acceder à m_taille
    double getOpacite () const { return m_opacite; };

    ///< reDefinir setPosition
    virtual     void setPosition( float x , float y ){ sf::Transformable::setPosition( x , y ); actualiser_bounds(); };

//    ///< Acceder à m_taille
//    double getOpacite () const { return m_opacite; };
protected:
    /////////////////////////////////////////////////
    /// \brief Calculer la position absolue du gadget.
    ///
    /////////////////////////////////////////////////
    sf::Vector2f getPosAbs () const;

    /////////////////////////////////////////////////
    /// \brief S'aligner sur un autre gadget.
    ///
    /// \param cible		 gadget cible sur lequel s'aligner.
    /// \param alignement		 L'endroit du gadget à aligner sur la cible.
    /// \param alignementCible		 L'endroit de la cible sur lequel aligner le gadget.
    /////////////////////////////////////////////////
    void Aligner ( std::shared_ptr<Gadget> cible, Alignement alignement, Alignement alignementCible );

    /////////////////////////////////////////////////
    /// \brief Actualiser .
    ///
    /////////////////////////////////////////////////
    virtual void actualiser (){std::cout << "ACTUALISER GEOMETRIE_H\n";};


    /////////////////////////////////////////////////
    /// \brief Actualiser les membres bounds local et global.
    ///
    /////////////////////////////////////////////////
    virtual void actualiser_bounds ();
/*
    /////////////////////////////////////////////////
    /// \brief Test si la souris survole le gadget.
    ///
    /// \param x		 La position sur l'axe horizontal de la souris.
    /// \param y		 La position sur l'axe vertical de la souris.
    /////////////////////////////////////////////////
    virtual std::shared_ptr<Gadget> testerSurvol (int x, int y);

    /////////////////////////////////////////////////
    /// \brief Test si la souris survole le gadget.
    ///
    /// \param position		 Le vecteur position de la souris.
    /////////////////////////////////////////////////
    virtual std::shared_ptr<Gadget> testerSurvol (sf::Vector2i position);
*/


/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
protected:
    sf::Vector2i    m_taille;           ///< la taille permet d'organiser la disposition des éléments graphiques du gadget.
    sf::FloatRect   m_localBounds;      ///< la rectangle anglobant du gadget en coordonnés locales.
    sf::FloatRect   m_globalBounds;     ///< la rectangle anglobant du gadget en coordonnés globales.
    double          m_opacite = 1;      ///< L'opacité du gadget ( entre 0 et 1 )

friend class Interface;

}; // fin class Geometrie

} // fin namespace gui

#endif
