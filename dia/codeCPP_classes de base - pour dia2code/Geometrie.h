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
    ///< Definir m_taille
    void setTaille( sf::Vector2i val ){ m_taille = val; };

    ///< Acceder � m_taille
    sf::Vector2i getTaille () const { return m_taille; };

    ///< Acceder � m_localBounds
    sf::FloatRect getLocalBounds () const { return m_localBounds; };

    ///< Acceder � m_globalBounds
    sf::FloatRect getGlobalBounds () const { return m_globalBounds; };

    ///< Definir m_skin
    void setSkin( std::shared_ptr<Skin> val ){ m_skin = val; };

    ///< Ajouter un �lement dans m_composants
    void ajouterAComposants ( ptr nouvelElement ){ m_composants.push_back( nouvelElement ); };

    ///< retirer l'�lement � la position id dans m_composants
    void retirerAComposants ( int id ) { if ( id>=0 || id<m_composants.size() ) m_composants.erase( m_composants.begin() + id ); };

    ///< Accesseur � l'�l�ment de m_composants d�sign� par un id.
    ptr getComposants ( int id ) const { if ( id>=0 || id<m_composants.size() )  return m_composants.at( id ); else return 0; };

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
    sf::Vector2i m_taille;    ///< la taille permet d'organiser la disposition des �l�ments graphiques du gadget. (#S#G)    
    sf::FloatRect m_localBounds;    ///< la rectangle anglobant du gadget en coordonn�s locales. (#G)    
    sf::FloatRect m_globalBounds;    ///< la rectangle anglobant du gadget en coordonn�s globales. (#G)    
    std::shared_ptr<Skin> m_skin;    ///< pointeur vers le skin du gadget. (#S)    
protected:
    std::vector<ptr> m_composants;    ///< les differents gadgets qui composent ce gadget. (#A#R#G)    

}; // fin class Geometrie

} // fin namespace gui

#endif
