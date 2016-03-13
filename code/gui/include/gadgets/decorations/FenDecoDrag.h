#ifndef FENDECODRAG_H
#define FENDECODRAG_H

#include <decorations/FenDecoration.h>
#include <Fenetre.h>
#include <BtnRectangle.h>


namespace gui{

class FenDecoDrag : public FenDecoration
{
public:
    ///< Default constructor */
    FenDecoDrag( Fenetre* fenetre );

    ~FenDecoDrag( );

    // Fonctions du templates decoration
    /////////////////////////////////////////////////
    virtual void traiterEvenements (const sf::Event& evenement);


    /////////////////////////////////////////////////
    virtual void actualiserGeometrie();


    // Fonctions locales
    /////////////////////////////////////////////////
    bool dragEnCours( ) { return m_drag; };

    /////////////////////////////////////////////////
    void setDrag ( bool val ){m_drag = val;};

    /////////////////////////////////////////////////
    void positionnerFenetre ();



    void sortDuPanneau ();

    void entreDansPanneau ();


protected:
private:

    std::shared_ptr<BtnRectangle>   m_btnDrag;

    bool                            m_draggable;
    bool                            m_drag;
    sf::Vector2i                    m_decalageDragSouris;

    sf::Color               m_btnDragCouleurs;
    sf::Color               m_btnDragLgnCouleurs;
    float                   m_btnDragLgnepaisseurs;

};

}; // fin namespace gui

#endif // FENDECODRAG_H
