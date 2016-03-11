#ifndef SUPPORT__H
#define SUPPORT__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Gadget.h"
#include "Groupe.h"
#include "repartiteurs/Repartiteur.h"
#include <memory>
#include <map>



namespace gui {



class Support : public gui::Gadget {



/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////
public:
    Support(  );
//    void ajouter ();

//    virtual void ajouter (std::shared_ptr<Gadget> enfant);
    /////////////////////////////////////////////////
    virtual void actualiserGeometrie ();

    /////////////////////////////////////////////////
    virtual void actualiserStyle ();
    virtual bool estAbsorbable(){return m_absorbable; };
    virtual void setAbsorbable ( bool val ) {m_absorbable = val; actualiserStyle ();};

    void setInterface ( Interface *     interface )    {
        m_interface = interface;
        actualiser();
    }

/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
public:
    Repartiteur m_repartiteur;
protected:
    std::shared_ptr<AffRectangle>      m_fond;
    std::shared_ptr<Groupe>            m_panneaux;
    bool                               m_absorbable = false;

    Interface *     m_interface;

    sf::Color   m_fndCouleur;
    sf::Color   m_fndCouleurSurvol;
    sf::Color   m_fndLgnCouleur;
    float       m_fndLgnEpaisseur;

}; // fin class Support

} // fin namespace gui

#endif
