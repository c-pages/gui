#ifndef AFFBARRETITRE__H
#define AFFBARRETITRE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <memory>

#include "gadgets/AffRectangle.h"
#include "gadgets/AffLabel.h"
#include "gadgets/AffIcone.h"
#include "gadgets_interfaces/Affiche.h"




namespace gui {


/////////////////////////////////////////////////
/// \brief Classe concrète d'affichage d'une barre de titre
///
/////////////////////////////////////////////////
class AffBarreTitre : public Affiche {


/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////
public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /////////////////////////////////////////////////
    AffBarreTitre ();

    void setIconeImage ( sf::Texture* texture  );

    void setIconeImage ( std::string texture  );

    void setIconeIndex (int index);

    ///< Definir m_texteTaille
    void setTexteTaille( float val ){
        m_textTaille = val;
        m_titre->setTexteTaille ( val ) ;
        };


    ///< Definir m_police
    void setCouleur( sf::Color couleur ){
        m_textCouleur = couleur;
        m_titre->setTexteCouleur ( couleur );
    };

    ///< Definir m_police
    void setTextePolice( sf::Font val ){
        m_textPolice = val;
        m_titre->setTextePolice    ( m_textPolice );/* actualiser();*/
    };

    ///< Definir m_police
    void setTexteStyle( sf::Text::Style val ){
        m_textStyle = val;
        m_titre->setTexteStyle    ( m_textStyle );
    };
    void setFondCouleur (sf::Color couleur) {
            m_fndCouleur = couleur ;
            m_fond->setFondCouleur( couleur );
        };
    void setFondLigneCouleur (sf::Color couleur) {
            m_fndLignesCouleur =  couleur;
            m_fond->setFondLigneCouleur( couleur );
        };
    void setFondLigneEpaisseur (float epaisseur) {
            m_fndLignesEpaisseur = epaisseur;
            m_fond->setFondLigneEpaisseur( epaisseur );
        };



    /////////////////////////////////////////////////
    virtual void actualiserGeometrie ();

    /////////////////////////////////////////////////
    virtual void actualiserStyle ();

//    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;


/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:

    // les composants de l'interface du gadget
    std::shared_ptr<AffRectangle>   m_fond;
    std::shared_ptr<AffLabel>       m_titre;
    std::shared_ptr<AffIcone>       m_icone;

    // les proprietés graphiques
    sf::Color           m_textCouleur;
    sf::Text::Style     m_textStyle;
    float               m_textTaille;
    sf::Font            m_textPolice;

    sf::Color           m_fndCouleur;
    sf::Color           m_fndLignesCouleur;
    float               m_fndLignesEpaisseur;

}; // fin class AffBarreTitre

} // fin namespace gui

#endif
