#ifndef GEOMETRIE__H
#define GEOMETRIE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Transformable.h"
#include "Composite.h"
#include <SFML/Graphics.hpp>



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
// M�thodes
/////////////////////////////////////////////////

public:
    ///< Definir m_taille
    void setTaille( sf::Vector2i val ){ m_taille = val; };

    ///< Acceder � m_taille
    sf::Vector2i getTaille () const { return m_taille; };

    ///< Acceder � m_localBounds
    sf::FloatRect getLocalBounds () const { return m_localBounds; };

    ///< Acceder � m_globalBounds
    sf::FloatRect getGlobalBounds () const { return m_globalBounds; };

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
    /// \param alignement		 L'endroit du gadget � aligner sur la cible.
    /// \param alignementCible		 L'endroit de la cible sur lequel aligner le gadget.
    /////////////////////////////////////////////////
    void Aligner (ptr cible, Alignement alignement, Alignement alignementCible);

    /////////////////////////////////////////////////
    /// \brief Actualiser les membres bounds local et global.
    ///
    /////////////////////////////////////////////////
    virtual void actualiser_bounds ();

    /////////////////////////////////////////////////
    /// \brief Test si la souris survole le gadget.
    ///
    /// \param x		 La position sur l'axe horizontal de la souris.
    /// \param y		 La position sur l'axe vertical de la souris.
    /////////////////////////////////////////////////
    bool testerSurvol (int x, int y);

    /////////////////////////////////////////////////
    /// \brief Test si la souris survole le gadget.
    ///
    /// \param position		 La position de la souris.
    /////////////////////////////////////////////////
    bool testerSurvol (sf::Vector2i position);



/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
protected:
    sf::Vector2i m_taille;    ///< la taille permet d'organiser la disposition des �l�ments graphiques du gadget. #S#G    
    sf::FloatRect m_localBounds;    ///< la rectangle anglobant du gadget en coordonn�s locales. #G    
    sf::FloatRect m_globalBounds;    ///< la rectangle anglobant du gadget en coordonn�s globales. #G    

}; // fin class Geometrie

} // fin namespace gui

#endif
