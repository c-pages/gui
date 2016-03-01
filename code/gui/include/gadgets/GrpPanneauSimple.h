#ifndef GRPPANNEAUSIMPLE__H
#define GRPPANNEAUSIMPLE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Groupement.h"
#include "AffRectangle.h"

#include "Groupement.h"

#include "repartiteurs/Repartiteur.h"
#include "repartiteurs/RepartiteurGrille.h"
#include "repartiteurs/RepartiteurHorizontal.h"
#include "repartiteurs/RepartiteurLibre.h"
#include "repartiteurs/RepartiteurVerticale.h"
#include "Enums.h"

#include <memory>
#include <SFML/Graphics.hpp>



namespace gui {



class GrpPanneauSimple : public gui::Groupement {


/////////////////////////////////////////////////
// Enums & typedefs
/////////////////////////////////////////////////





/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////


public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /////////////////////////////////////////////////
    GrpPanneauSimple ();

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
//    std::shared_ptr<AffRectangle>       m_fond;

}; // fin class GrpPanneauSimple

} // fin namespace gui

#endif
