#ifndef BTNTEXTE__H
#define BTNTEXTE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "BtnRectangle.h"
#include "gadgets\AffRectangle.h"
#include "gadgets\AffLabel.h"
#include <SFML/Graphics.hpp>



namespace gui {


/////////////////////////////////////////////////
/// \brief Un simple bouton rectangulaire
///
/////////////////////////////////////////////////
class BtnTexte : public BtnRectangle {



/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////
public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /////////////////////////////////////////////////
    BtnTexte ();

    /////////////////////////////////////////////////
    virtual void actualiserGeometrie ();

    /////////////////////////////////////////////////
    virtual void actualiserStyle ();

    ///< Definir m_texte
    virtual void setTexte( std::string val );

    ///< Definir m_texteTaille
    void setTailleCharac( float val , Etat etat = Etat::tous );

    ///< Definir m_texteTaille
    void setTailleCharac( Valeurs<float> val );

    ///< Definir m_police
    void setTexteCouleur( sf::Color couleur , Etat etat = Etat::tous);

    ///< Definir m_police
    void setTexteCouleur( Valeurs<sf::Color> couleur  );

    ///< Definir m_police
    void setTextePolice( sf::Font val , Etat etat = Etat::tous);

    ///< Definir m_police
    void setTextePolice( Valeurs<sf::Font> val  );

    ///< Definir m_police
    void setTexteStyle( sf::Text::Style val , Etat etat = Etat::tous);

    ///< Definir m_police
    void setTexteStyle( Valeurs<sf::Text::Style> val  );

////////////////////////////////// ///////////////
// Membres
/////////////////////////////////////////////////
public:

    // les composants de l'interface du gadget
    std::shared_ptr<AffLabel>       m_label;

    // les proprietés graphiques
    Valeurs<sf::Color>              m_textCouleur;
    Valeurs<sf::Text::Style>        m_textStyle;
    Valeurs<float>                  m_textTaille;
    Valeurs<sf::Font>               m_textPolice;



}; // fin class BtnTexte

} // fin namespace gui

#endif // BTNRECTANGLE__H
























