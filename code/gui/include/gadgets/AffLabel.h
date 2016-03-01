#ifndef AFFLABEL__H
#define AFFLABEL__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Affiche.h"
#include "Style.h"
#include <memory>
#include <iostream>
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

    sf::Vector2f  getTaille() const;
//sf::Text::setColor()

    virtual     void setStyle ( std::shared_ptr<Style> style , Etat etat = Etat::tous );


    ///< Definir m_texte
    void setTexte( std::string val ){
        m_texte = val;
        actualiser();
    };

    ///< Acceder à m_texte
    std::string getTexte () const { return m_texte; };

    ///< Acceder à m_texte
    std::shared_ptr<sf::Text> getSFTexte () const { return m_texteSFML; };

    ///< Definir m_texteTaille
    void setTexteTaille( float val ){ /*m_texteTaille = val;*/ m_texteSFML->setCharacterSize ( val ) ;  };


    ///< Definir m_police
    void setTexteCouleur( sf::Color couleur ){ m_texteSFML->setColor ( couleur );/* actualiser();*/ };

    ///< Definir m_police
    void setPolice( sf::Font val ){
        m_police = val;
        m_texteSFML->setFont    ( m_police );/* actualiser();*/
    };


    ///< Acceder à m_police
    sf::Font getPolice () const { return m_police; };

public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /////////////////////////////////////////////////
    AffLabel ();

    virtual void actualiser ();

//    virtual void actualiser_bounds ();

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
    std::string                 m_texte;            ///< Le texte à afficher par le label.#S#G
    std::shared_ptr<sf::Text>   m_texteSFML;        ///< Le shape SFML qui affiche le texte.
    sf::Font                    m_police;           ///< La police du texte à afficher par le label.#S#G
}; // fin class AffLabel

} // fin namespace gui

#endif
