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

//    virtual void actualiser ();
    /////////////////////////////////////////////////
    virtual void actualiserGeometrie ();

    /////////////////////////////////////////////////
    virtual void actualiserStyle ();

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

    void corrigerTailleMinimum ();



/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:

    // les proprietés fonctionnelles
    bool    m_redimGauche = false;
    bool    m_redimDroite = false;
    bool    m_redimHaut = false;
    bool    m_redimBas = false;
    bool    m_redimmensionner = false;

    sf::Vector2i     m_sourisPosOrigin;
    sf::Vector2i     m_tailleOrigin;
    sf::Vector2f     m_posOrigin;


    // les composants de l'interface du gadget
    std::shared_ptr<BtnRectangle> m_btn_gauche;
    std::shared_ptr<BtnRectangle> m_btn_droite;
    std::shared_ptr<BtnRectangle> m_btn_hautGauche;
    std::shared_ptr<BtnRectangle> m_btn_hautDroite;
    std::shared_ptr<BtnRectangle> m_btn_basGauche;
    std::shared_ptr<BtnRectangle> m_btn_basDroite;
    std::shared_ptr<BtnRectangle> m_btn_haut;
    std::shared_ptr<BtnRectangle> m_btn_bas;

    // les proprietés graphiques
    Valeurs<sf::Color>      m_btnDragCouleurs;
    Valeurs<sf::Color>      m_btnDragLgnCouleurs;
    Valeurs<float>          m_btnDragLgnepaisseurs;

    Valeurs<sf::Color>      m_btnDragSlideCouleurs;
    Valeurs<sf::Color>      m_btnDragSlideLgnCouleurs;
    Valeurs<float>          m_btnDragSlideLgnepaisseurs;

    sf::Color               m_btnDragFndCouleur;
    sf::Color               m_btnDragFndLgnCouleur;
    float                   m_btnDragFndLgnepaisseur;

    // Les actions pour le fonctionnement
    FctnAction     fct_redimStartG;
    FctnAction     fct_redimStopG;
    FctnAction     fct_redimStartD;
    FctnAction     fct_redimStopD;
    FctnAction     fct_redimStartH;
    FctnAction     fct_redimStopH;
    FctnAction     fct_redimStartB;
    FctnAction     fct_redimStopB;

}; // fin class FenRedim

} // fin namespace gui

#endif
