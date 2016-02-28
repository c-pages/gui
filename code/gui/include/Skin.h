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
enum class Styles{

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
enum class Polices {
    Police_1,
//    Police_2,
    fin
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
    /// \brief Definir une police
    ///
    /// \param valeur la valeur à appliquer
    /// \param style Le style à redefinir (par defaut tous)
    /// \param etat L'etat à redefinir (par defaut tous)
    /////////////////////////////////////////////////
    template<typename T>
    void set ( T valeur
              , Style::Proprietes propriete = Style::Proprietes::tous
              , Styles            style     = Styles::tous
              , Etat              etat      = Etat::tous )
    {
        if ( style == Styles::tous)
            for ( int i = 0; i != static_cast<int>(Styles::tous); i++ )
                m_styles.at( static_cast<Styles>(i) )->set (valeur , propriete, etat) ;
        else
                m_styles.at( style )->set (valeur , propriete, etat) ;
    };

    /////////////////////////////////////////////////
    /// \brief Definir une police
    ///
    /// \param police la police à appliquer
    /// \param style Le style à redefinir (par defaut tous)
    /// \param etat L'etat à redefinir (par defaut tous)
    /////////////////////////////////////////////////
    std::shared_ptr<Style> getStyle( Skin::Styles style )
    {
        return m_styles.at ( style );
    };


/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
public:
    std::map< Styles , std::shared_ptr<Style> > m_styles;
}; // fin class Skin

}; // fin namespace gui

#endif
