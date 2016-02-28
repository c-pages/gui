/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Style.h>

namespace gui {
Style::Style()
/*: txt_police    ( )
, txt_style     ( sf::Text::Style::Regular )
, txt_taille    ( 10 )
, txt_couleur   ( sf::Color(255, 255, 255))
, lgn_epaisseur ( 3 )
, lgn_couleur   ( sf::Color(255, 255, 255))
, fnd_couleur   ( sf::Color(255, 255, 255))
, fnd_texture   ( )*/
{
    txt_police.press.loadFromFile ( "media/polices/consola.ttf" );
    txt_police.repos.loadFromFile ( "media/polices/consola.ttf" );
    txt_police.survol.loadFromFile( "media/polices/consola.ttf" );
    txt_police.desactive.loadFromFile( "media/polices/consola.ttf" );

    txt_style.set(sf::Text::Style::Regular ) ;
    txt_taille.set( 9.5 ) ;

    txt_couleur.set( sf::Color(200, 200, 200)) ;
    txt_couleur.set( sf::Color(200, 200, 200,50), Etat::desactive ) ;

    lgn_epaisseur.set( 1 ) ;
    lgn_couleur.set( sf::Color(150, 150, 150 ) ) ;
    lgn_couleur.set( sf::Color(150, 150, 150,100), Etat::desactive ) ;
//    fnd_couleur.set( sf::Color(100, 100, 100) ) ;
    fnd_couleur.set( sf::Color(100, 100, 100,50), Etat::desactive ) ;
    fnd_couleur.set( sf::Color(200, 200, 200), Etat::press ) ;
    fnd_couleur.set( sf::Color(100, 100, 100), Etat::repos ) ;
    fnd_couleur.set( sf::Color(120, 120, 120), Etat::survol ) ;


//    fnd_texture;
}



}; // fin namespace gui
