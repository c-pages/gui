#ifndef FENSIMPLE__H
#define FENSIMPLE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Fenetre.h"
#include <memory>



namespace gui {



class FenSimple : public gui::Fenetre {



/////////////////////////////////////////////////
// M�thodes
/////////////////////////////////////////////////

public:
public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par d�faut.
    ///
    /////////////////////////////////////////////////
    FenSimple ();

    virtual void actualiser ();

    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;



/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:
    std::shared_ptr<AffBarrTitre> m_titre;    
    std::shared_ptr<BtnIcone> m_btnFermer;    
    bool m_utiliserFermer;    

}; // fin class FenSimple

} // fin namespace gui

#endif
