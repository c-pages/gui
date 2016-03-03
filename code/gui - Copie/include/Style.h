#ifndef STYLE__H
#define STYLE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
#include <Enums.h>
#include <memory>


namespace gui{





/////////////////////////////////////////////////
/// \brief Valeurs porte les valeurs pour une proprieté du style correspondants aux états possible du gadgets.
///
/////////////////////////////////////////////////
template <typename T>
struct Valeurs {
    /////////////////////////////////////////////////
    void set ( T val , Etat etat = Etat::tous )    {
        if ( etat == Etat::tous)
            repos = survol = press = desactive = val;
        else switch ( etat ){
            case Etat::repos :
                repos = val; break;
            case Etat::survol :
                survol = val; break;
            case Etat::press :
                press = val; break;
            case Etat::desactive :
                desactive = val; break;
            default : break;
        }
    };
    /////////////////////////////////////////////////
    T get ( Etat etat ){
         switch ( etat ){
            case Etat::repos :
                return repos; break;
            case Etat::survol :
                return survol; break;
            case Etat::press :
                return press; break;
            case Etat::desactive :
                return desactive; break;
            case Etat::tous :
                return repos; break;
            default : break;
        }
    };
    /////////////////////////////////////////////////
    T repos;
    T survol;
    T press;
    T desactive;
};

/////////////////////////////////////////////////
/// \brief Un style regroupe un ensemble de caractéristiques de base des gadgets.
///
/////////////////////////////////////////////////
class Style {

public:

/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////
public:

    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /////////////////////////////////////////////////
    Style();
/*
    /////////////////////////////////////////////////
    /// \brief Definir une police
    ///
    /// \param valeur la valeur à appliquer
    /// \param style Le style à redefinir (par defaut tous)
    /// \param etat L'etat à redefinir (par defaut tous)
    /////////////////////////////////////////////////
    template<typename T>
    void set (  T                   valeur
              , Style::Proprietes   propriete
              , Etat                etat        = Etat::tous )
    {
         switch ( propriete ){
            case Proprietes::txt_police :
                txt_police.set( valeur, etat ) ; break;
            case Proprietes::txt_style :
                txt_style.set( valeur, etat ) ; break;
            case Proprietes::txt_taille :
                txt_taille.set( valeur, etat ) ; break;
            case Proprietes::txt_couleur :
                txt_couleur.set( valeur, etat ) ; break;
            case Proprietes::lgn_epaisseur :
                lgn_epaisseur.set( valeur, etat ) ; break;
            case Proprietes::lgn_couleur :
                lgn_couleur.set( valeur, etat ) ; break;
            case Proprietes::fnd_couleur :
                fnd_couleur.set( valeur, etat ) ; break;
            case Proprietes::fnd_texture :
                fnd_texture.set( valeur, etat ) ; break;
        }

    };*/

    /////////////////////////////////////////////////
    /// \brief Les accesseurs aux propriétés.
    ///
    /////////////////////////////////////////////////
    sf::Font        getTxt_police       ( Etat etat ){ return txt_police.get    (etat); };

    sf::Text::Style getTxt_style        ( Etat etat ){ return txt_style.get     (etat); };
    float           getTxt_taille       ( Etat etat ){ return txt_taille.get    (etat); };
    sf::Color       getTxt_couleur      ( Etat etat ){ return txt_couleur.get   (etat); };

    float           getLgn_epaisseur    ( Etat etat ){ return lgn_epaisseur.get  (etat); };
    sf::Color       getLgn_couleur      ( Etat etat ){ return lgn_couleur.get    (etat); };

    sf::Color       getFnd_couleur      ( Etat etat ){ return fnd_couleur.get    (etat); };
//    sf::Texture     getFnd_texture      ( Etat etat ){ return fnd_texture.get    (etat); };


/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
public:

//    std::map<Proprietes , std::shared_ptr<void> >      m_proprietes;


    Valeurs<sf::Font>          txt_police;     ///< Police du texte.
    Valeurs<sf::Text::Style>   txt_style;      ///< Style SFML du texte (Regular, Italic, ... ).
    Valeurs<float>             txt_taille;     ///< Taille du texte.
    Valeurs<sf::Color>         txt_couleur;    ///< Couleur du texte.

    Valeurs<float>             lgn_epaisseur;  ///< Epaisseur des lignes.
    Valeurs<sf::Color>         lgn_couleur;    ///< Couleur des lignes.

    Valeurs<sf::Color>         fnd_couleur;    ///< Couleur du fond.
//    Valeurs<sf::Texture>       fnd_texture;    ///< Texture du fond au repos.


}; // fin class Style

}; // fin namespace gui

#endif
