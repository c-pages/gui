/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Style.h>

namespace gui {
Style::Style()
: txt_police    ( )
, txt_style     ( sf::Text::Style::Regular )
, txt_taille    ( 10 )
, txt_couleur   ( sf::Color(255, 255, 255))
, lgn_epaisseur ( 3 )
, lgn_couleur   ( sf::Color(255, 255, 255))
, fnd_couleur   ( sf::Color(255, 255, 255))
, fnd_texture   ( )
{
    txt_police.loadFromFile ( "media/polices/consola.ttf" );

}



}; // fin namespace gui
