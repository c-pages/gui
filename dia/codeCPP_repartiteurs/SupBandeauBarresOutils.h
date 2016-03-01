#ifndef SUPBANDEAUBARRESOUTILS__H
#define SUPBANDEAUBARRESOUTILS__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Support.h"
#include <SFML/Graphics.hpp>
#include <memory>



namespace gui {



class SupBandeauBarresOutils : public gui::Support {



/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////

public:
public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /////////////////////////////////////////////////
    GrpFenetre ();

    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;



/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:
    AffRect m_rectangle;    
    sf::Text m_label;    
    std::shared_ptr<Panneau> m_panneau;    

}; // fin class SupBandeauBarresOutils

} // fin namespace gui

#endif
