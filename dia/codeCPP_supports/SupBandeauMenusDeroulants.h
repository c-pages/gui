#ifndef SUPBANDEAUMENUSDEROULANTS__H
#define SUPBANDEAUMENUSDEROULANTS__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Support.h"
#include <SFML/Graphics.hpp>
#include <memory>



namespace gui {



class SupBandeauMenusDeroulants : public gui::Support {



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

}; // fin class SupBandeauMenusDeroulants

} // fin namespace gui

#endif
