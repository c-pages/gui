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
// Méthodes
/////////////////////////////////////////////////

public:
    /*
    ///< Definir m_position
    void setPosition( sf::Vector2f val ){ m_position = val; };

    ///< Acceder à m_position
    sf::Vector2f getPosition () const { return m_position; };*/

    ///< Definir m_taille
    virtual void setTaille( sf::Vector2f val ){ m_taille = val; actualiser_bounds(); };

    ///< Acceder à m_taille
    virtual sf::Vector2f getTaille () const { return m_taille; };

    ///< Acceder à m_localBounds
    virtual sf::FloatRect getLocalBounds () const { return m_localBounds; };

    ///< Acceder à m_globalBounds
    virtual sf::FloatRect getGlobalBounds () const { return m_globalBounds; };


public:
//    /////////////////////////////////////////////////
//    /// \brief Acceder à la position absolue du gadget.
//    ///
//    /////////////////////////////////////////////////
//    sf::Vector2f getPosAbs () const;

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
    //sf::Vector2f    m_position;         ///< La position relative (parent) du gadget.
    sf::Vector2f    m_taille;           ///< la taille permet d'organiser la disposition des éléments graphiques du gadget.
    sf::FloatRect   m_localBounds;      ///< la rectangle englobant du gadget en coordonnés locales.
    sf::FloatRect   m_globalBounds;     ///< la rectangle englobant du gadget en coordonnés globales.


}; // fin class Geometrie

} // fin namespace gui

#endif
