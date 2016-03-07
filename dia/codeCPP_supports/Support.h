#ifndef SUPPORT__H
#define SUPPORT__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Gadget.h"
#include <memory>
#include <map>



namespace gui {



class Support : public gui::Gadget {



/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////

public:
public:
    void ajouter ();



/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
public:
    Repartiteur m_repartiteur;    
protected:
    std::map<std::string, std::shared_ptr<Panneau>> m_panneau;    
    std::shared_ptr<Panneau> m_fond;    

}; // fin class Support

} // fin namespace gui

#endif
