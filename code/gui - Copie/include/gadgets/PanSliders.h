#ifndef GRPPANNEAUSLIDERS__H
#define GRPPANNEAUSLIDERS__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Panneau.h"
#include "AffRectangle.h"
#include "AffImage.h"
#include "DnBarreDefilement.h"
#include "Panneau.h"
#include "repartiteurs/Repartiteur.h"
#include "repartiteurs/RepartiteurGrille.h"
#include "repartiteurs/RepartiteurHorizontal.h"
#include "repartiteurs/RepartiteurLibre.h"
#include "repartiteurs/RepartiteurVerticale.h"
#include "Enums.h"
#include <memory>
#include <SFML/Graphics.hpp>



namespace gui {



class PanSliders : public gui::Panneau {


/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////

public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /////////////////////////////////////////////////
    PanSliders ();

    /////////////////////////////////////////////////
    /// \brief Actualise le repartiteur puis les gadgets enfant contenus.
    ///
    /////////////////////////////////////////////////
    virtual void actualiser ();

    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;

private:

//    virtual sf::Vector2f    deplMaxContenu();

/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:

    std::shared_ptr<DnBarreDefilement>  m_slider_V;
    std::shared_ptr<DnBarreDefilement>  m_slider_H;

}; // fin class PanSliders

} // fin namespace gui

#endif
