#ifndef AFFBARRETITRE__H
#define AFFBARRETITRE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Affiche.h"
#include "AffRectangle.h"
#include "AffLabel.h"
#include "AffIcone.h"
#include <memory>



namespace gui {


/////////////////////////////////////////////////
/// \brief Classe concr�te d'affichage d'une barre de titre
///
/////////////////////////////////////////////////
class AffBarreTitre : public Affiche {


/////////////////////////////////////////////////
// M�thodes
/////////////////////////////////////////////////
public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par d�faut.
    ///
    /////////////////////////////////////////////////
    AffBarreTitre ();

    void setIconeImage ( sf::Texture* texture  );

    void setIconeImage ( std::string texture  );

    void setIconeIndex (int index);

    ///< Definir m_texteTaille
    void setTailleCharac( float val ){
        m_textTaille = val;
        m_titre->setTailleCharac ( val ) ;
        };


    ///< Definir m_police
    void setCouleur( sf::Color couleur ){
        m_textCouleur = couleur;
        m_titre->setCouleur ( couleur );
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
    void setLigneCouleur (sf::Color couleur) {
            m_fndLignesCouleur =  couleur;
            m_fond->setLigneCouleur( couleur );
        };
    void setLigneEpaisseur (float epaisseur) {
            m_fndLignesEpaisseur = epaisseur;
            m_fond->setLigneEpaisseur( epaisseur );
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

    // les propriet�s graphiques
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
