#ifndef AFFLABEL__H
#define AFFLABEL__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Affiche.h"
//#include "Style.h"
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

    virtual sf::Vector2i  getTaille() const;
//sf::Text::setColor()

//    virtual     void setStyle ( std::shared_ptr<Style> style , Etat etat = Etat::tous );


    ///< Definir m_texte
    virtual void setTexte( std::string val ){
        log("setTexte \"" + val + "\"" );
        m_texte = val;
        m_texteSFML.setString( val );
        demanderActualisation();
//        demanderActuaStyle();
//        demanderActuaGeom();
//        actualiserGeometrie();
    };
//
//    ///< Acceder à m_texte
    std::string getTexte () const { return m_texteSFML.getString( ); };
//
//    ///< Acceder à m_texte
    sf::Text     getSFTexte () const { return m_texteSFML; };


//    virtual void creerNom( std::string type  = "Label" ) {Gadget::creerNom(type);};

    ///< Definir m_texteTaille
    void setTexteTaille( float val ){
//        log ("setTexteTaille" , val);
        m_textTaille = val;
//        m_texteSFML.setCharacterSize ( val ) ;
        demanderActualisation();
        };


    ///< Definir m_police
    void setTexteCouleur( sf::Color couleur ){
//        log ("setTexteCouleur" , couleur);
        m_textCouleur = couleur;
//        m_texteSFML.setColor ( couleur );
        demanderActualisation();
    };

    ///< Definir m_police
    void setPolice( sf::Font val ){
//        log ("setPolice" , "");
        m_textPolice = val;
//        m_texteSFML.setFont    ( m_textPolice );/* actualiser();*/
        demanderActualisation();
    };

    ///< Definir m_police
    void setTexteStyle( sf::Text::Style val ){
//        log ("setTexteStyle" , val );
        m_textStyle = val;
//        m_texteSFML.setStyle    ( m_textStyle );
        demanderActualisation();
    };


    ///< Acceder à m_police
    sf::Font getPolice () const { return m_textPolice; };
public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /////////////////////////////////////////////////
    AffLabel ();

//    virtual void actualiser ();

    /////////////////////////////////////////////////
    virtual void actualiserGeometrie ();

    /////////////////////////////////////////////////
    virtual void actualiserStyle ();

//    virtual void actualiserBounds ();

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

    // les composants de l'interface du gadget
    sf::Text   m_texteSFML;        ///< Le shape SFML qui affiche le texte.

    // les proprietés graphiques
    sf::Color           m_textCouleur;
    sf::Text::Style     m_textStyle;
    float               m_textTaille;
    sf::Font            m_textPolice;

}; // fin class AffLabel

} // fin namespace gui

#endif
