#ifndef LSTDEROULANTE__H
#define LSTDEROULANTE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Liste.h"
#include <memory>



namespace gui {



class LstDeroulante : public gui::Liste {



/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////

public:
public:
    virtual void actualiserGeometrie ();

    virtual void actualiserStyle ();

    void draw (sf::RenderTarget target, sf::RenderStates states) const;



/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:
    std::shared_ptr<BtnMenu> m_menu;    
    std::shared_ptr<BtnTexte> m_boutonLabel;    
    std::shared_ptr<AffIcone> m_fleche;    

}; // fin class LstDeroulante

} // fin namespace gui

#endif
