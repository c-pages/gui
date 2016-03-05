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
    ///< Definir m_valeurMax
    void setValeurMax( float val ){ m_valeurMax = val; };

    ///< Acceder à m_valeurMax
    float getValeurMax ( ) const { return m_valeurMax; };

    ///< Definir m_valeurMin
    void setValeurMin( float val ){ m_valeurMin = val; };

    ///< Acceder à m_valeurMin
    float getValeurMin ( ) const { return m_valeurMin; };

//    ///< Definir m_taille
//    virtual void setTaille( sf::Vector2i val ){
////        m_taille = val;
////        m_longueur = val.x;
////        m_largeur = val.y;
//
//        actualiserBounds();
//        actualiser(); };
    ///< Definir m_taille
    void setLongueur( float longueur ){
        m_longueur = longueur;
        actualiserBounds();
        actualiser();
    };

    void setLargeur( float largeur ){
        m_largeur = largeur;
        actualiserBounds();
        actualiser();
    };

    void setHorizontal (  ){ m_horizontal = true;actualiser (); };

    void setVertical (  ){ m_horizontal = false; actualiser ();}

    void incrementer( float increment = 5 );

    void decrementer( float increment = 5 );

    bool dragEnCours( ) {return m_drag;};

    void setDrag (bool val ){m_drag = val;};

public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /////////////////////////////////////////////////
    DnSlider ( );


    virtual void traiterEvenements (const sf::Event& evenement);

    virtual float getValeur();

    //    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;


    //    virtual std::shared_ptr<Gadget>  testerSurvol ( sf::Vector2i position );

    //    virtual void actualiser ( );

    /////////////////////////////////////////////////
    virtual void actualiserGeometrie ();

    /////////////////////////////////////////////////
    virtual void actualiserStyle ();

/*
    void setLongueurCurseur( float pourcentage ) {
        m_slider->setLongCurseur( pourcentage );
        actualiser();
    };*/
    void setLongueurCurseur( float pourcentage );
//    void setLong    ( float pixels );

//    virtual void setSkin( std::shared_ptr<Skin> skin );

//    virtual void setStyle ( std::shared_ptr<Style> style , Etat etat = Etat::tous );
/*
    void setStyleBtnFond( std::shared_ptr<Style> style )
        { m_styleBtnFond = style;
          m_boutonFond->setStyle  ( m_styleBtnFond ); };

    void setStyleBtnRectangle( std::shared_ptr<Style> style )
        { m_styleBtnSlider = style;
          m_slider->setStyle      ( m_styleBtnSlider );};

    void setStyleFond( std::shared_ptr<Style> style )
        { m_styleFond = style;
          m_fond->setStyle        ( m_styleFond );};
*/
    // le slider
    void setSliderFillColor ( Valeurs<sf::Color> couleurs  ) {
            m_slideCouleurs = couleurs;
            actualiserStyle();
        };
    void setSliderOutlineColor ( Valeurs<sf::Color> couleurs  ) {
            m_slideLgnCouleurs = couleurs;
            actualiserStyle();
        };
    void setSliderOutlineThickness ( Valeurs<float> epaisseur ) {
            m_slideLgnepaisseurs =  epaisseur;
            actualiserStyle();
        };

    // le bouton
    void setBoutonFillColor ( Valeurs<sf::Color> couleurs  ) {
            m_btnCouleurs = couleurs;
            actualiserStyle();
        };
    void setBoutonOutlineColor ( Valeurs<sf::Color> couleurs  ) {
            m_btnLgnCouleurs = couleurs;
            actualiserStyle();
        };
    void setBoutonOutlineThickness ( Valeurs<float> epaisseur ) {
            m_btnLgnepaisseurs =  epaisseur;
            actualiserStyle();
        };

    // le fond
    void setFillColor ( sf::Color couleurs  ) {
            m_fndCouleur = couleurs;
            actualiserStyle();
        };
    void setOutlineColor ( sf::Color couleurs  ) {
            m_fndLgnCouleur = couleurs;
            actualiserStyle();
        };
    void setOutlineThickness ( float epaisseur ) {
            m_fndLgnepaisseur =  epaisseur;
            actualiserStyle();
        };
private:
    void positionnerCurseurSurSouris ();
    void corrigerPositionCurseur();




/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:

    // les proprietés fonctionnelles
    bool                            m_horizontal;   ///< Orientation : true bouton
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
