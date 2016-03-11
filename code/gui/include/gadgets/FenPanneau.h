#ifndef FENPANNEAU_H
#define FENPANNEAU_H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <gadgets/FenSimple.h>

namespace gui {

class FenPanneau : public FenSimple
{

/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////
public:
    FenPanneau();
    virtual ~FenPanneau();

    /////////////////////////////////////////////////
    virtual void traiterEvenements (const sf::Event& evenement);


    virtual void actualiserGeometrie();
    virtual void actualiserStyle();



    /////////////////////////////////////////////////
    void redimmensionner_bas ();
    void reduire () {
        m_reduit = true;
        m_panneau->setVisible ( false );
        m_btn_retaille->setVisible ( false );
        m_parent->actualiser();

        m_btn_reduire->setIconeIndex ( 3 );
        actualiserGeometrie();
    };
    void agrandir () {
        m_reduit = false;
        m_panneau->setVisible ( true );
        m_btn_retaille->setVisible ( true );
        m_parent->actualiser();

        m_btn_reduire->setIconeIndex ( 2 );
        actualiserGeometrie();
    };
    virtual sf::Vector2i getTaille() const
    {
        if ( m_reduit )
            return { m_taille.x, m_titre->getTaille().y + 2*m_marge.y };
        else return m_taille;
    }

    void setDrag ( bool val ) { m_drag = val;};
    bool dragEnCours(){return m_drag;};

    /////////////////////////////////////////////////
//    void traiterEvenements (const sf::Event& evenement);


    /////////////////////////////////////////////////
    void positionnerFenetre ();
protected:
private:

    /////////////////////////////////////////////////
    void corrigerTailleMinimum ();

/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////

    bool             m_redimBas          = false;
    sf::Vector2i     m_sourisPosOrigin;
    sf::Vector2i     m_tailleOrigin;
    sf::Vector2f     m_posOrigin;

    bool                            m_drag;
    sf::Vector2i                    m_decalageDragSouris;
    bool                            m_modeFenetre;

    bool                            m_reduit = false;
    std::shared_ptr<BtnRectangle>   m_btn_retaille;
    std::shared_ptr<BtnIcone>   m_btn_reduire;



};

}; // fin namespace gui


#endif // FENPANNEAU_H
