#ifndef GRPPANNEAUSIMPLE__H
#define GRPPANNEAUSIMPLE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Panneau.h"
#include "AffRectangle.h"

#include "repartiteurs/Repartiteur.h"
#include "repartiteurs/RepartiteurGrille.h"
#include "repartiteurs/RepartiteurHorizontal.h"
#include "repartiteurs/RepartiteurLibre.h"
#include "repartiteurs/RepartiteurVerticale.h"
#include "Enums.h"

#include <memory>
#include <SFML/Graphics.hpp>



namespace gui {



class PanSimple : public gui::Panneau {


/////////////////////////////////////////////////
// Enums & typedefs
/////////////////////////////////////////////////


/////////////////////////////////////////////////
// M�thodes
/////////////////////////////////////////////////


public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par d�faut.
    ///
    /////////////////////////////////////////////////
    PanSimple ();

    /////////////////////////////////////////////////
    /// \brief Actualise le repartiteur puis les gadgets enfant contenus.
    ///
    /////////////////////////////////////////////////
    virtual void actualiser ();

    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;

}; // fin class PanSimple

} // fin namespace gui

#endif
