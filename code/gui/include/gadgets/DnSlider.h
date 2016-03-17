#ifndef DNSLIDER__H
#define DNSLIDER__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "gadgets_interfaces/Donnee.h"
#include "BtnRectangle.h"



namespace gui {



/////////////////////////////////////////////////
/// \brief Un slider permet de controler une valeur numerique.
///
/////////////////////////////////////////////////
class DnSlider : public gui::Donnee<float> {


/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////

public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /////////////////////////////////////////////////
    DnSlider ( );

    /////////////////////////////////////////////////
    virtual void actualiserGeometrie ();

    /////////////////////////////////////////////////
    virtual void actualiserStyle ();

    /////////////////////////////////////////////////
    virtual void traiterEvenements (const sf::Event& evenement);

    // le slider
    void setSliderCouleur           ( Valeurs<sf::Color> couleurs );
    void setSliderLigneCouleur      ( Valeurs<sf::Color> couleurs );
    void setSliderLigneEpaisseur    ( Valeurs<float> epaisseur );

    // le bouton
    void setBoutonCouleur           ( Valeurs<sf::Color> couleurs );
    void setBoutonLigneCouleur      ( Valeurs<sf::Color> couleurs );
    void setBoutonLigneEpaisseur    ( Valeurs<float> epaisseur );

    // le fond
    void setFondCouleur             ( sf::Color couleurs );
    void setFondLigneCouleur        ( sf::Color couleurs );
    void setFondLigneEpaisseur      ( float epaisseur );

public:

    /////////////////////////////////////////////////
    virtual float getValeur();

    ///< Definir m_valeurMax
    void setValeurMax( float val );

    ///< Acceder à m_valeurMax
    float getValeurMax ( ) const ;

    ///< Definir m_valeurMin
    void setValeurMin( float val );

    ///< Acceder à m_valeurMin
    float getValeurMin ( ) const ;

    /////////////////////////////////////////////////
    void setLongueurCurseur( float pourcentage );

    ///< Definir m_taille
    void setLongueur( float longueur );

    void setLargeur( float largeur );

    void setHorizontal (  );

    void setVertical (  );

    void incrementer( float increment = 20 );

    void decrementer( float increment = 20 );

    bool dragEnCours( ) ;

    void setDrag (bool val );

private:
    void deplacerSlider ();

    /////////////////////////////////////////////////
    /// \brief  Corriger la position pour la garder dans ses limites
    ///
    /////////////////////////////////////////////////
    void corrigerPositionSlider();

/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:

    // les proprietés fonctionnelles
    bool                            m_horizontal;   ///< l'orientation,  true: bouton horizontal, false: bouton vertical.
    float                           m_valeurMax;    ///<
    float                           m_valeurMin;    ///<
    float                           m_longueur;     ///<
    float                           m_largeur;      ///<
    bool                            m_drag;
    sf::Vector2i                    m_decalageDragSouris;

    // les composants de l'interface du gadget
    std::shared_ptr<BtnRectangle>   m_boutonFond;
    std::shared_ptr<BtnRectangle>   m_slider;
    std::shared_ptr<AffRectangle>   m_fond;

    // Les actions pour le fonctionnement
    FctnAction     fct_cliqueBtnFond;
    FctnAction     fct_dragStart;
    FctnAction     fct_dragStop;
    FctnAction     fct_rouletteH;
    FctnAction     fct_rouletteB;

    Valeurs<sf::Color>      m_btnCouleurs;
    Valeurs<sf::Color>      m_btnLgnCouleurs;
    Valeurs<float>          m_btnLgnepaisseurs;

    Valeurs<sf::Color>      m_slideCouleurs;
    Valeurs<sf::Color>      m_slideLgnCouleurs;
    Valeurs<float>          m_slideLgnepaisseurs;

    sf::Color               m_fndCouleur;
    sf::Color               m_fndLgnCouleur;
    float                   m_fndLgnepaisseur;


}; // fin class DnSlider

} // fin namespace gui

#endif

















