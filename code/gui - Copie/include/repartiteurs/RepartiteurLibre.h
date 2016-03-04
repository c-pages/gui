#ifndef REPARTITEURLIBRE__H
#define REPARTITEURLIBRE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Repartiteur.h"



namespace gui {



class RepartiteurLibre : public gui::Repartiteur {



/////////////////////////////////////////////////
// M�thodes
/////////////////////////////////////////////////
public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par d�faut.
    ///
    /// \param racine		 
    /////////////////////////////////////////////////
    RepartiteurLibre (Gadget* racine);

    virtual void repartir (std::vector<std::shared_ptr<Gadget>> groupe);


}; // fin class RepartiteurLibre

} // fin namespace gui

#endif