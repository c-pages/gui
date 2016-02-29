#ifndef SKIN__H
#define SKIN__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <memory>
#include "Style.h"


namespace gui{


/////////////////////////////////////////////////
/// \brief Un skin regroupe un ensemble de style pour composer tout les �l�ments d'une interface.
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
// M�thodes
/////////////////////////////////////////////////
public:
    /////////////////////////////////////////////////
    /// \brief Createur par d�faut
    ///
    /////////////////////////////////////////////////
    Skin ();

    void creerDefaut();

    /////////////////////////////////////////////////
    /// \brief Acceder � un style du skin.
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
