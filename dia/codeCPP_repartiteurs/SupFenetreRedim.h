#ifndef SUPFENETREREDIM__H
#define SUPFENETREREDIM__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "SupFenetre.h"
#include <memory>



namespace gui {

class BtnRectangle;
class BtnRectangle;
class BtnRectangle;
class BtnRectangle;
class BtnRectangle;
class BtnRectangle;
class BtnRectangle;
class BtnRectangle;


class SupFenetreRedim : public gui::SupFenetre {



/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////

public:
public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /////////////////////////////////////////////////
    GrpFenetreRedim ();

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

}; // fin class SupFenetreRedim

} // fin namespace gui

#endif
