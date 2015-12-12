#ifndef GEOMETRIE__H
#define GEOMETRIE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>



namespace gui {

class Skin;
class Gadget;


/////////////////////////////////////////////////
/// \brief Concerne la partie geometrique des gadgets, comme la taille, collision...
///
/////////////////////////////////////////////////
class Geometrie {


/////////////////////////////////////////////////
// Enums & typedefs
/////////////////////////////////////////////////
    typedef std::shared_ptr<Gadget> ptr;    ///< Pointeur vers un gadget.


/////////////////////////////////////////////////
// M�thodes
/////////////////////////////////////////////////

public:
public:
    /////////////////////////////////////////////////
    /// \brief Acceder � la position absolue du gadget.
    ///
    /////////////////////////////////////////////////
    sf::Vector2f getPosAbs () const;

    /////////////////////////////////////////////////
    /// \brief D�finir la taille du gadget (m_taille, qui sert de cadre pour dessiner le gadget.)
    ///
    /// \param taille		 
    /////////////////////////////////////////////////
    void setSize (sf::Vector2i taille);

    /////////////////////////////////////////////////
    /// \brief Acceder � la taille du gadget (m_taille).
    ///
    /////////////////////////////////////////////////
    sf::Vector2i getSize () const;

    /////////////////////////////////////////////////
    /// \brief Acceder � la BB du gadget en coordonn�es local (m_localBounds)..
    ///
    /////////////////////////////////////////////////
    sf::FloatRect getLocalBounds () const;

    /////////////////////////////////////////////////
    /// \brief  Acceder � la BB du gadget en coordonn�es global (m_globalBounds).
    ///
    /////////////////////////////////////////////////
    sf::FloatRect getGlobalBounds () const;

    /////////////////////////////////////////////////
    /// \brief D�finir le skin courant du gadget.
    ///
    /// \param skin		 le nouveau skin
    /////////////////////////////////////////////////
    void setSkin (std::shared_ptr<Skin> skin);

    /////////////////////////////////////////////////
    /// \brief S'aligner sur un autre gadget.
    ///
    /// \param cible		 gadget sur lequel s'aligner.
    /////////////////////////////////////////////////
    void Aligner (ptr cible);

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
private:
    sf::Vector2i m_taille;    ///< la taille permet d'organiser la disposition des �l�ments graphiques du gadget.    
    sf::FloatRect m_localBounds;    ///< la rectangle anglobant du gadget en coordonn�s locales.    
    sf::FloatRect m_globalBounds;    ///< la rectangle anglobant du gadget en coordonn�s globales.    
    std::shared_ptr<Skin> m_skin;    ///< pointeur vers le skin du gadget    
protected:
    std::vector<ptr> m_composants;    ///< les differents gadgets qui composent ce gadget.    

}; // fin class Geometrie

} // fin namespace gui

#endif
