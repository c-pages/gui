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
//        actualiser_bounds();
//        actualiser(); };
    ///< Definir m_taille
    void setLongueur( float longueur ){
        m_longueur = longueur;
        actualiser_bounds();
        actualiser();
    };

    void setLargeur( float largeur ){
        m_largeur = largeur;
        actualiser_bounds();
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

    virtual void actualiser ( );

    void setLongCurseur( float pourcentage );
//    void setLong    ( float pixels );

private:
    void positionnerCurseurSurSouris ();
    void corrigerPositionCurseur();

/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:
    bool                            m_horizontal;   ///< Orientation : true bouton

    std::shared_ptr<BtnRectangle>   m_boutonFond;
    std::shared_ptr<BtnRectangle>   m_slider;
    std::shared_ptr<AffRectangle>   m_fond;

    float                           m_valeurMax;    ///<
    float                           m_valeurMin;    ///<

    float                           m_longueur;     ///<
    float                           m_largeur;      ///<

    bool                            m_drag;
    sf::Vector2i                    m_decalageDragSouris;

}; // fin class DnSlider

} // fin namespace gui

#endif
