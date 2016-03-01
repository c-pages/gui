#ifndef REPARTITEURGRILLE__H
#define REPARTITEURGRILLE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Repartiteur.h"



namespace gui {



class RepartiteurGrille : public gui::Repartiteur {



/////////////////////////////////////////////////
// M�thodes
/////////////////////////////////////////////////
public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par d�faut.
    ///
    /// \param racine		 
    /////////////////////////////////////////////////
    RepartiteurGrille (Gadget* racine);

    virtual void repartir (std::vector<std::shared_ptr<Gadget>> groupe);


}; // fin class RepartiteurGrille

} // fin namespace gui

#endif
