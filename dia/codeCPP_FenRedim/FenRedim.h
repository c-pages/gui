#ifndef FENREDIM__H
#define FENREDIM__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Fenetre.h"
#include <memory>
#include "FenSimple.h"



namespace gui {



class FenRedim : public gui::Fenetre {



/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////

public:
public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /////////////////////////////////////////////////
    FenRedim ();

    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;



/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
public:
    std::shared_ptr<BtnRectangle> m_btn_gauche;    
    std::shared_ptr<BtnRectangle> m_btn_droite;    
    std::shared_ptr<BtnRectangle> m_btn_hautGauche;    
    std::shared_ptr<BtnRectangle> m_btn_hautDroite;    
    std::shared_ptr<BtnRectangle> m_btn_basGauche;    
    std::shared_ptr<BtnRectangle> m_btn_basDroite;    
private:
    std::shared_ptr<BtnRectangle> m_btn_haut;    
    std::shared_ptr<BtnRectangle> m_btn_bas;    
    std::shared_ptr<gui::FenSimple> m_fenetre;

}; // fin class FenRedim

} // fin namespace gui

#endif
