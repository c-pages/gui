#ifndef SUPPANNEAU__H
#define SUPPANNEAU__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Support.h"

#include "BtnRectangle.h"
#include "CntSliders.h"
#include <SFML/Graphics.hpp>
#include <memory>



namespace gui {



class SupPanneau : public gui::Support {

//class CntSliders;




/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////


public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /////////////////////////////////////////////////
    SupPanneau ();
    void setCote ( Cote cote );
    Cote getCote ( ) { return m_cote; };
    /////////////////////////////////////////////////
    virtual void actualiserGeometrie ();

//    virtual void actualiserEnfants();

    /////////////////////////////////////////////////

    virtual sf::Vector2i     getTaille () const;

    /////////////////////////////////////////////////
//    virtual void actualiserStyle ();
//    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;

    /////////////////////////////////////////////////
    void traiterEvenements (const sf::Event& evenement);

//    virtual std::shared_ptr<Gadget>  testerSurvol ( sf::Vector2i position );

 //   virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;

    virtual void ajouter ( std::shared_ptr<Gadget> gadget, sf::Vector2i positionEcran );
    virtual void ajouter ( std::shared_ptr<Gadget> gadget)
        { m_contenant->ajouter ( gadget ); };

private:

    void redimmensionner_gauche ();
    void redimmensionner_droite ();

    /////////////////////////////////////////////////
    void corrigerTailleMinimum ();

/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:
    // les proprietés fonctionnelles
    bool            m_redimGauche = false;
    bool            m_redimDroite = false;

    float           m_largeurBtnTaille;

    Cote            m_cote;

    sf::Vector2i     m_sourisPosOrigin;
    sf::Vector2i     m_tailleOrigin;
    sf::Vector2f     m_posOrigin;

    std::shared_ptr<BtnRectangle>   m_btn_gauche;
    std::shared_ptr<BtnRectangle>   m_btn_droite;
    std::shared_ptr<CntSliders>     m_contenant;


}; // fin class SupPanneau

} // fin namespace gui

#endif
