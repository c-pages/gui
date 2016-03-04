/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Style.h>
#include <Interface.h>

namespace gui {
/////////////////////////////////////////////////
Style::Style()
{

    // initialiser les polices
    ms_polices.load( "Defaut" , "media/polices/consola.ttf" );

    txt_police.set ( ms_polices.get( "Defaut" ) );

    txt_style.set(sf::Text::Style::Regular ) ;
    txt_taille.set( 9.5 ) ;
    txt_couleur.set( sf::Color(200, 200, 200)) ;
    txt_couleur.set( sf::Color(200, 200, 200,50), Etat::desactive ) ;

    lgn_epaisseur.set( 1 ) ;
    lgn_couleur.set( sf::Color(150, 150, 150 ) ) ;
    lgn_couleur.set( sf::Color(150, 150, 150,100), Etat::desactive ) ;

    fnd_couleur.set( sf::Color(100, 100, 100,50), Etat::desactive ) ;
    fnd_couleur.set( sf::Color(200, 200, 200), Etat::press ) ;
    fnd_couleur.set( sf::Color(100, 100, 100), Etat::repos ) ;
    fnd_couleur.set( sf::Color(120, 120, 120), Etat::survol ) ;


//    fnd_texture;
}
/*
/////////////////////////////////////////////////
void Style::ajouterPropriete ( Proprietes propriete , Types type )
{
    switch ( type ){
        case Types::Color:
            m_proprietes.insert( { propriete , std::make_shared<Valeurs<sf::Color>>()} );
            break;
        case Types::Float:
            m_proprietes.insert( { propriete , std::make_shared<Valeurs<float>>()} );
            break;
        case Types::Font:
            m_proprietes.insert( { propriete , std::make_shared<Valeurs<sf::Font>>()} );
            break;
        case Types::TextStyle:
            m_proprietes.insert( { propriete , std::make_shared<Valeurs<sf::Text::Style>>()} );
            break;
        case Types::Texture:
            m_proprietes.insert( { propriete , std::make_shared<Valeurs<sf::Text::Style>>()} );
            break;

    }


}
*/

}; // fin namespace gui
