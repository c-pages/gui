#ifndef GRPPANNEAUSLIDERS__H
#define GRPPANNEAUSLIDERS__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Groupe.h"
#include "AffRectangle.h"
#include "AffImage.h"
#include "DnSlider.h"
#include "Groupe.h"
#include "repartiteurs/Repartiteur.h"
#include "repartiteurs/RepartiteurGrille.h"
#include "repartiteurs/RepartiteurHorizontal.h"
#include "repartiteurs/RepartiteurLibre.h"
#include "repartiteurs/RepartiteurVerticale.h"
#include "Enums.h"
#include "Valeurs.h"
#include <memory>
#include <SFML/Graphics.hpp>

namespace gui {



class GrpSliders : public gui::Groupe {


/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////

public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /////////////////////////////////////////////////
    GrpSliders ();

//    /////////////////////////////////////////////////
//    /// \brief Actualise le repartiteur puis les gadgets enfant contenus.
//    ///
//    /////////////////////////////////////////////////
//    virtual void actualiser ();


    void setSliderFillColor ( Valeurs<sf::Color> couleurs  ) {
            m_btnCouleurs = couleurs;
            actualiserStyle();
//            m_rectangle->setFillColor( couleur );
        };
    void setSliderOutlineColor ( Valeurs<sf::Color> couleurs  ) {
            m_btnLgnCouleurs = couleurs;
            actualiserStyle();
//            m_rectangle->setOutlineColor( couleur );
        };
    void setSliderOutlineThickness ( Valeurs<float> epaisseur ) {
            m_btnLgnepaisseurs =  epaisseur;
            actualiserStyle();
//            m_rectangle->setOutlineThickness( epaisseur );
        };


    /////////////////////////////////////////////////
    void replacerContenu ();

    /////////////////////////////////////////////////
    virtual void actualiserGeometrie ();

    /////////////////////////////////////////////////
    virtual void actualiserStyle ();

    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;

private:

//    virtual sf::Vector2f    deplMaxContenu();

/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:

    float                   m_largeurSliders;

    // les composants de l'interface du gadget
    std::shared_ptr<DnSlider>  m_slider_V;
    std::shared_ptr<DnSlider>  m_slider_H;

    // les proprietés graphiques
    Valeurs<sf::Color>      m_btnCouleurs;
    Valeurs<sf::Color>      m_btnLgnCouleurs;
    Valeurs<float>          m_btnLgnepaisseurs;

    Valeurs<sf::Color>      m_btnBtnCouleurs;
    Valeurs<sf::Color>      m_btnBtnLgnCouleurs;
    Valeurs<float>          m_btnBtnLgnepaisseurs;

    Valeurs<sf::Color>      m_btnSlideCouleurs;
    Valeurs<sf::Color>      m_btnSlideLgnCouleurs;
    Valeurs<float>          m_btnSlideLgnepaisseurs;

    sf::Color               m_btnFndCouleur;
    sf::Color               m_btnFndLgnCouleur;
    float                   m_btnFndLgnepaisseur;

}; // fin class GrpSliders

} // fin namespace gui

#endif
