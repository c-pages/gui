#ifndef FENREDIM__H
#define FENREDIM__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "FenSimple.h"
#include <memory>
#include "FenSimple.h"



namespace gui {



class FenRedim : public gui::FenSimple {



/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////
public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /////////////////////////////////////////////////
    FenRedim ();

 //   virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;

    virtual void actualiser ();

    virtual void traiterEvenements (const sf::Event& evenement);

    /////////////////////////////////////////////////
    void actualiser ( sf::Time delta );

    bool redimEnCours () {
        if ( m_redimGauche || m_redimDroite || m_redimHaut || m_redimBas )
            return true;
        else false;
    };

private:
    void redimmensionner_haut ();
    void redimmensionner_bas ();
    void redimmensionner_gauche ();
    void redimmensionner_droite ();

    void redimmensionner ();


/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:
    std::shared_ptr<BtnRectangle> m_btn_gauche;
    std::shared_ptr<BtnRectangle> m_btn_droite;

    std::shared_ptr<BtnRectangle> m_btn_hautGauche;
    std::shared_ptr<BtnRectangle> m_btn_hautDroite;

    std::shared_ptr<BtnRectangle> m_btn_basGauche;
    std::shared_ptr<BtnRectangle> m_btn_basDroite;

    std::shared_ptr<BtnRectangle> m_btn_haut;
    std::shared_ptr<BtnRectangle> m_btn_bas;

    bool    m_redimGauche = false;
    bool    m_redimDroite = false;
    bool    m_redimHaut = false;
    bool    m_redimBas = false;
    bool    m_redimmensionner = false;

    sf::Vector2i     m_sourisPosOrigin;
    sf::Vector2i     m_tailleOrigin;
    sf::Vector2f     m_posOrigin;


//    std::shared_ptr<FenSimple> m_fenetre;

}; // fin class FenRedim

} // fin namespace gui

#endif
