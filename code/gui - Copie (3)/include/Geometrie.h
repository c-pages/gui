#ifndef GEOMETRIE__H
#define GEOMETRIE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>




namespace gui {

class Gadget;

/////////////////////////////////////////////////
/// \brief Concerne la partie geometrique des gadgets, comme la taille, collision...
///
/////////////////////////////////////////////////
class Geometrie : public sf::Transformable {

//class ptr;

/////////////////////////////////////////////////
// Enums & typedefs
/////////////////////////////////////////////////
//    typedef std::shared_ptr<Gadget> ptr;    ///< Pointeur vers un gadget.


/////////////////////////////////////////////////
// M�thodes
/////////////////////////////////////////////////

public:
    /*
    ///< Definir m_position
    void setPosition( sf::Vector2f val ){ m_position = val; };

    ///< Acceder � m_position
    sf::Vector2f getPosition () const { return m_position; };*/

    ///< Definir m_taille
    virtual void setTaille( sf::Vector2f val ){ m_taille = val; };

    ///< Acceder � m_taille
    sf::Vector2f getTaille () const { return m_taille; };

    ///< Acceder � m_localBounds
    sf::FloatRect getLocalBounds () const { return m_localBounds; };

    ///< Acceder � m_globalBounds
    sf::FloatRect getGlobalBounds () const { return m_globalBounds; };


public:
    /////////////////////////////////////////////////
    /// \brief Acceder � la position absolue du gadget.
    ///
    /////////////////////////////////////////////////
    sf::Vector2f getPosAbs () const;

    /////////////////////////////////////////////////
    /// \brief S'aligner sur un autre gadget.
    ///
    /// \param cible		 gadget sur lequel s'aligner.
    /////////////////////////////////////////////////
    void Aligner (std::shared_ptr<Gadget> cible);

    /////////////////////////////////////////////////
    /// \brief  Test pour savoir si le point (x,y) survol le gadget.
    ///
    /// \param x
    /// \param y
    /////////////////////////////////////////////////
    bool testerSurvol (float x, float y) const;

    /////////////////////////////////////////////////
    /// \brief Actualiser les membres bounds local et global.
    ///
    /////////////////////////////////////////////////
    virtual void actualiser_bounds ();




/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
protected:
    //sf::Vector2f    m_position;         ///< La position relative (parent) du gadget.#G#S
    sf::Vector2f    m_taille;           ///< la taille permet d'organiser la disposition des �l�ments graphiques du gadget. #S#G
    sf::FloatRect   m_localBounds;      ///< la rectangle anglobant du gadget en coordonn�s locales. #G
    sf::FloatRect   m_globalBounds;     ///< la rectangle anglobant du gadget en coordonn�s globales. #G


}; // fin class Geometrie

} // fin namespace gui

#endif