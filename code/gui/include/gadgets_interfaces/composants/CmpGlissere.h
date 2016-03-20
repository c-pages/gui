#ifndef CMPGLISSERE_H
#define CMPGLISSERE_H

#include "Composant.h"
#include "Valeurs.h"

#include "gadgets/AffRectangle.h"
#include "gadgets/BtnRectangle.h"

namespace gui {

class CmpGlissere : public Composant
{
public:

    CmpGlissere();


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

    // dimensionnement
    void setLongueurCurseur( float pourcentage );
    void setLongueur( float longueur );
    void setLargeur( float largeur );

    void setHorizontal (  );
    void setVertical (  );

protected :
    /////////////////////////////////////////////////
    virtual void initialiserComposants ( Gadget*     base );


/////////////////////////////////////////////////
// les membres
/////////////////////////////////////////////////
protected:
  // les proprietés fonctionnelles
    bool                            m_horizontal;   ///< l'orientation,  true: bouton horizontal, false: bouton vertical.
    float                           m_valeurMax;    ///<
    float                           m_valeurMin;    ///<
    float                           m_longueur;     ///<
    float                           m_largeur;      ///<

    // les composants de l'interface du gadget
    std::shared_ptr<BtnRectangle>   m_boutonFond;
    std::shared_ptr<BtnRectangle>   m_slider;
    std::shared_ptr<AffRectangle>   m_fond;


    Valeurs<sf::Color>      m_btnCouleurs;
    Valeurs<sf::Color>      m_btnLgnCouleurs;
    Valeurs<float>          m_btnLgnepaisseurs;

    Valeurs<sf::Color>      m_slideCouleurs;
    Valeurs<sf::Color>      m_slideLgnCouleurs;
    Valeurs<float>          m_slideLgnepaisseurs;

    sf::Color               m_fndCouleur;
    sf::Color               m_fndLgnCouleur;
    float                   m_fndLgnepaisseur;
private:
};

};

#endif // CMPGLISSERE_H
