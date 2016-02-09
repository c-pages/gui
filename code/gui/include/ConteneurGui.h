#ifndef CONTENEURGUI_H_INCLUDED
#define CONTENEURGUI_H_INCLUDED


/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Gadget.h"


namespace gui {



class ConteneurGui : public Gadget {



/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////
public:

    ConteneurGui();

    virtual void actualiser (sf::Time delta);

    virtual void traiter_evenements( const sf::Event evenement );

    virtual void draw (sf::RenderTarget& target, sf::RenderStates states ) const;


}; // fin class Affiche

}; // fin namespace gui

#endif // CONTENEURGUI_H_INCLUDED
