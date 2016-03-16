#ifndef DNSLIDER__H
#define DNSLIDER__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Donnee.h"
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

    /////////////////////////////////////////////////
    virtual float getValeur();

    /////////////////////////////////////////////////
    void setLongueurCurseur( float pourcentage );

    // le slider
    void setSliderFillColor         ( Valeurs<sf::Color> couleurs  );
    void setSliderOutlineColor      ( Valeurs<sf::Color> couleurs  );
    void setSliderOutlineThickness  ( Valeurs<float> epaisseur );

    // le bouton
    void setBoutonFillColor         ( Valeurs<sf::Color> couleurs  );
    void setBoutonOutlineColor      ( Valeurs<sf::Color> couleurs  );
    void setBoutonOutlineThickness  ( Valeurs<float> epaisseur );

    // le fond
    void setFondCouleur             ( sf::Color couleurs  );
    void setLigneCouleur            ( sf::Color couleurs  );
    void setLigneEpaisseur          ( float epaisseur );

public:
    ///< Definir m_valeurMax
    void setValeurMax( float val );

    ///< Acceder à m_valeurMax
    float getValeurMax ( ) const ;

    ///< Definir m_valeurMin
    void setValeurMin( float val );

    ///< Acceder à m_valeurMin
    float getValeurMin ( ) const ;

    ///< Definir m_taille
    void setLongueur( float longueur );

    void setLargeur( float largeur );

    void setHorizontal (  );

    void setVertical (  );

    void incrementer( float increment = 5 );

    void decrementer( float increment = 5 );

    bool dragEnCours( ) ;

    void setDrag (bool val );
private:
    void positionnerCurseurSurSouris ();
    void corrigerPositionCurseur();

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

















