#ifndef STYLE__H
#define STYLE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <SFML/Graphics.hpp>


namespace gui{


enum class Etat {
    repos,
    survol,
    press
};
/////////////////////////////////////////////////
/// \brief Un style regroupe un ensemble de caractéristiques de base des gadgets.
///
/////////////////////////////////////////////////
template <typename T>
struct Valeurs {
    void set ( T val )    {
        repos = survol = press = val;
    };
    T get ( Etat etat ){
         switch ( etat ){
            case Etat::repos :
                return repos; break;
            case Etat::survol :
                return survol; break;
            case Etat::press :
                return press; break;
        }
    };
    T repos;
    T survol;
    T press;
};



/////////////////////////////////////////////////
/// \brief Un style regroupe un ensemble de caractéristiques de base des gadgets.
///
/////////////////////////////////////////////////
class Style {


/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////
public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /////////////////////////////////////////////////
    Style();

    sf::Font        getTxt_police       ( Etat etat ){ return txt_police.get    (etat); };

    sf::Text::Style getTxt_style        ( Etat etat ){ return txt_style.get     (etat); };
    float           getTxtTaille        ( Etat etat ){ return txt_taille.get    (etat); };
    sf::Color       getTxt_couleur      ( Etat etat ){ return txt_couleur.get   (etat); };

    float           getLgn_epaisseur    ( Etat etat ){ return lgn_epaisseur.get  (etat); };
    sf::Color       getLgn_couleur      ( Etat etat ){ return lgn_couleur.get    (etat); };

    sf::Color       getFnd_couleur      ( Etat etat ){ return fnd_couleur.get    (etat); };
    sf::Texture     getFnd_texture      ( Etat etat ){ return fnd_texture.get    (etat); };



/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
public:

    Valeurs<sf::Font>          txt_police;     ///< Police du texte.
    Valeurs<sf::Text::Style>   txt_style;      ///< Style SFML du texte (Regular, Italic, ... ).
    Valeurs<float>             txt_taille;     ///< Taille du texte.
    Valeurs<sf::Color>         txt_couleur;    ///< Couleur du texte.

    Valeurs<float>             lgn_epaisseur;  ///< Epaisseur des lignes.
    Valeurs<sf::Color>         lgn_couleur;    ///< Couleur des lignes.

    Valeurs<sf::Color>         fnd_couleur;    ///< Couleur du fond.
    Valeurs<sf::Texture>       fnd_texture;    ///< Texture du fond au repos.


}; // fin class Style

}; // fin namespace gui

#endif
