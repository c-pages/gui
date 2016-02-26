#ifndef AFFLABEL__H
#define AFFLABEL__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Affiche.h"
#include <memory>
#include <SFML/Graphics.hpp>



namespace gui {



/////////////////////////////////////////////////
/// \brief Classe concrète d'affichage d'un simple texte.
///
/////////////////////////////////////////////////
class AffLabel : public gui::Affiche {



/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////

public:
    ///< Definir m_texte
    void setTexte( std::string val ){ m_texte = val; };

    ///< Acceder à m_texte
    std::string getTexte () const { return m_texte; };

    ///< Definir m_texteTaille
    void setTexteTaille( float val ){ m_texteTaille = val; };

    ///< Acceder à m_texteTaille
    float getTexteTaille () const { return m_texteTaille; };

    ///< Definir m_police
    void setPolice( sf::Font val ){ m_police = val; };

    ///< Acceder à m_police
    sf::Font getPolice () const { return m_police; };

public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /////////////////////////////////////////////////
    AffLabel ();

    virtual void actualiser ();

    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;

    /////////////////////////////////////////////////
    /// \brief Appliquer une police 
    ///
    /// \param police		 
    /////////////////////////////////////////////////
    void setPoliceFichier (sf::Font police);



/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:
    std::string m_texte;    ///< Le texte à afficher par le label.#S#G    
    std::shared_ptr<sf::Texte> m_texteSFML;    ///< Le shape SFML qui affiche le texte.    
    float m_texteTaille;    ///< La taille du texte à afficher par le label.#S#G    
    sf::Font m_police;    ///< La police du texte à afficher par le label.#S#G    

}; // fin class AffLabel

} // fin namespace gui

#endif
