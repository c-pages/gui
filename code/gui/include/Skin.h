#ifndef SKIN__H
#define SKIN__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <memory>
#include "Style.h"


namespace gui{


/////////////////////////////////////////////////
/// \brief Un skin regroupe un ensemble de style pour composer tout les éléments d'une interface.
///
/////////////////////////////////////////////////
class Skin {


public:
enum Styles{

    defaut,

    invisible,
    cadre,
    txtCourant,
    txtLog,
    txtTitre,
    fond,
    bouton,
    btnCoche,
    img,
    menu,
    fenetre,
    zoneTexte,
    slider,

    tous
};


/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////
public:
    /////////////////////////////////////////////////
    /// \brief Createur par défaut
    ///
    /////////////////////////////////////////////////
    Skin ();

    void creerDefaut();

    /////////////////////////////////////////////////
    /// \brief Acceder à un style du skin.
    ///
    /// \param Le style rechercher
    /// \return Le style
    /////////////////////////////////////////////////
    std::shared_ptr<Style> getStyle( Skin::Styles style = defaut)
    {
        return m_styles.at ( style );
    };


/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
public:
    std::map< int , std::shared_ptr<Style> > m_styles;

}; // fin class Skin

}; // fin namespace gui

#endif
