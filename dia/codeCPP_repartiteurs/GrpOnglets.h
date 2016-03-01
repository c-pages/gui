#ifndef GRPONGLETS__H
#define GRPONGLETS__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Groupement.h"
#include <SFML/Graphics.hpp>



namespace gui {

class BtnRectangle;


class GrpOnglets : public gui::Groupement {



/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////

public:
public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /////////////////////////////////////////////////
    GrpOnglets ();

    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;



/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:
    AffRect m_rectangle;    
    sf::Text m_label;    
    std::pair<std::string , panneau> m_panneaux;    
    std::pair<std::string , BtnRectangle> m_onglets;    
    unsigned int m_ongletActif;    

}; // fin class GrpOnglets

} // fin namespace gui

#endif
