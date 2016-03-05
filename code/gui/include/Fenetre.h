#ifndef FENETRE__H
#define FENETRE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "ActionEvenement.h"
#include <memory>
#include <Panneau.h>


namespace gui {


class Fenetre : public ActionEvenement {


/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////
public:
    Fenetre();
    /////////////////////////////////////////////////
    /// \brief Bascule entre un panneau simple (false) et un panneau slider (true).
    ///
    /// \param val
    /////////////////////////////////////////////////
    virtual void setDefilementActif (bool val);


    /////////////////////////////////////////////////
    virtual void ajouter (std::shared_ptr<Gadget> enfant);


    /////////////////////////////////////////////////
    virtual std::shared_ptr<Gadget> retirer (std::shared_ptr<Gadget> enfant);

    /////////////////////////////////////////////////
    void actualiserGeometrie ();

    /////////////////////////////////////////////////
    void actualiserStyle ();

/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
protected:
    std::shared_ptr<Panneau>        m_panneau;
    std::shared_ptr<AffRectangle>   m_fond;
    std::shared_ptr<AffRectangle>   m_ombre;

    sf::Color               m_panneauFndCouleur;
    sf::Color               m_panneauFndLgnCouleur;
    float                   m_panneauFndLgnepaisseur;
    sf::Color               m_panneauContenantCouleur;
    sf::Color               m_panneauContenantLgnCouleur;
    float                   m_panneauContenantLgnepaisseur;

    sf::Color               m_fondCouleur;
    sf::Color               m_fondLgnCouleur;
    float                   m_fondLgnepaisseur;

    sf::Color               m_ombreCouleur;
    sf::Color               m_ombreLgnCouleur;
    float                   m_ombreLgnepaisseur;

}; // fin class Fenetre


} // fin namespace gui

#endif
