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
// M�thodes
/////////////////////////////////////////////////
public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par d�faut.
    ///
    /////////////////////////////////////////////////
    BtnTexte ();

//    virtual void actualiser ( );

    /////////////////////////////////////////////////
    virtual void actualiserGeometrie ();

    /////////////////////////////////////////////////
    virtual void actualiserStyle ();
/*
    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;
*/

//    virtual     void setStyle ( std::shared_ptr<Style> style , Etat etat = Etat::tous );

    ///< Definir m_texteTaille
    virtual void setTexte( std::string val ){
        log("setTexte \"" + val + "\"" );
        m_texte = val;
        m_label->setTexte ( val ) ;
        demanderActuaGeom();
    };

    ///< Definir m_texteTaille
    void setTexteTaille( float val ){
        m_textTaille = val;
        m_label->setTexteTaille ( val ) ;
//        demanderActuaStyle();
    };

    ///< Definir m_texteTaille
    void setTexteTaille( Valeurs<float> val ){
        m_textTaille = val;
//        m_label->setTexteTaille ( val ) ;
        demanderActuaStyle();
    };




    ///< Definir m_police
    void setTexteCouleur( sf::Color couleur ){
        m_textCouleur = couleur;
        m_label->setTexteCouleur ( couleur );
//        demanderActuaStyle();
//        actualiser ();
    };

    ///< Definir m_police
    void setTexteCouleur( Valeurs<sf::Color> couleur ){
        m_textCouleur = couleur;
//        m_label->setTexteCouleur ( couleur );
        demanderActuaStyle();
    };

    ///< Definir m_police
    void setPolice( sf::Font val ){
        m_textPolice = val;

//        m_label->setPolice    ( val );


//        demanderActuaStyle();
//        actualiserGeometrie ();
    };

    ///< Definir m_police
    void setPolice( Valeurs<sf::Font> val ){
        m_textPolice = val;
//        m_label->setPolice    ( val );
        demanderActuaStyle();
    };
    ///< Definir m_police
    void setTexteStyle( sf::Text::Style val ){
        m_textStyle = val;
        m_label->setTexteStyle    ( val );
//        demanderActuaStyle();
//        actualiserGeometrie ();
    };

    ///< Definir m_police
    void setTexteStyle( Valeurs<sf::Text::Style> val ){
        m_textStyle = val;
//        m_label->setTexteStyle    ( val );
        demanderActuaStyle();
    };
////////////////////////////////// ///////////////
// Membres
/////////////////////////////////////////////////
public:

    // les composants de l'interface du gadget
    std::shared_ptr<AffLabel>       m_label;

    // les propriet�s graphiques
    Valeurs<sf::Color>              m_textCouleur;
    Valeurs<sf::Text::Style>        m_textStyle;
    Valeurs<float>                  m_textTaille;
    Valeurs<sf::Font>               m_textPolice;



}; // fin class BtnTexte

} // fin namespace gui

#endif // BTNRECTANGLE__H
























