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

    void setHorizontal ( bool val ){ m_horizontal = val; }

    void incrementer();

    void decrementer();

    bool dragEnCours( ) {return m_drag;};

    void setDrag (bool val ){m_drag = val;};

public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /////////////////////////////////////////////////
    DnSlider ( );

    void actualiser ( );

    virtual void traiterEvenements (const sf::Event& evenement);

    virtual float getValeur();

    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;

    void positionnerCurseurSurSouris ();

    virtual std::shared_ptr<Gadget>  testerSurvol ( sf::Vector2i position );

/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:
    bool                            m_horizontal;  ///< Orientation : true bouton
    std::shared_ptr<BtnRectangle>   m_boutonFond;
    std::shared_ptr<BtnRectangle>   m_slider;
    float                           m_valeurMax;    ///<
    float                           m_valeurMin;    ///<
    float                           m_inc;
    bool                            m_drag;

}; // fin class DnSlider

} // fin namespace gui

#endif
