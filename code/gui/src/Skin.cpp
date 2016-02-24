/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Skin.h>

#include <Style.h>

namespace gui{
/////////////////////////////////////////////////
Skin::Skin ()
: invisible     ( std::make_shared<Style> () )
, desactive     ( std::make_shared<Style> () )
, cadre         ( std::make_shared<Style> () )
, txtCourant    ( std::make_shared<Style> () )
, txtLog        ( std::make_shared<Style> () )
, txtTitre      ( std::make_shared<Style> () )
, fond          ( std::make_shared<Style> () )
, bouton        ( std::make_shared<Style> () )
, img           ( std::make_shared<Style> () )
, menu          ( std::make_shared<Style> () )
, fenetre       ( std::make_shared<Style> () )
{
    //Un skin par défaut

//    desactive->txt_police.repos.loadFromFile ( "media/polices/arial.ttf" );
//    desactive->txt_police.press.loadFromFile ( "media/polices/arial.ttf" );
//    desactive->txt_police.survol.loadFromFile( "media/polices/arial.ttf" );

    desactive->txt_style.set       ( sf::Text::Style::Regular ) ;
    desactive->txt_taille.set       ( 10 ) ;
    desactive->txt_couleur.set      ( sf::Color(255, 255, 255 , 0) ) ;
    desactive->lgn_epaisseur.set    ( 1 ) ;
    desactive->lgn_couleur.set      ( sf::Color(255, 255, 255, 50) ) ;
    desactive->fnd_couleur.set      ( sf::Color(255, 255, 255, 20) ) ;


//    invisible->txt_police.repos.loadFromFile ( "media/polices/arial.ttf" );
//    invisible->txt_police.press.loadFromFile ( "media/polices/arial.ttf" );
//    invisible->txt_police.survol.loadFromFile( "media/polices/arial.ttf" );
    invisible->txt_style.set       ( sf::Text::Style::Regular ) ;
    invisible->txt_taille.set       ( 10 ) ;
    invisible->txt_couleur.set      ( sf::Color(255, 255, 255 , 0) ) ;
    invisible->lgn_epaisseur.set    ( 1 ) ;
    invisible->lgn_couleur.set      ( sf::Color(255, 255, 255, 0) ) ;
    invisible->fnd_couleur.set      ( sf::Color(255, 255, 255, 0) ) ;
    //invisible->fnd_texture;

//    cadre->txt_police.repos.loadFromFile ( "media/polices/arial.ttf" );
//    cadre->txt_police.press.loadFromFile ( "media/polices/arial.ttf" );
//    cadre->txt_police.survol.loadFromFile( "media/polices/arial.ttf" );

    cadre->txt_style.set       (sf::Text::Style::Regular ) ;
    cadre->txt_taille.set       ( 10 ) ;
    cadre->txt_couleur.set      ( sf::Color(255, 255, 255 , 0) ) ;
    cadre->lgn_epaisseur.set    ( 1 ) ;
    cadre->lgn_couleur.set      ( sf::Color(255, 255, 255, 255) ) ;
    cadre->fnd_couleur.set      ( sf::Color(255, 255, 255, 0) ) ;

    txtCourant->txt_police.repos.loadFromFile  ( "media/polices/arial.ttf" );
    txtCourant->txt_police.press.loadFromFile  ( "media/polices/arial.ttf" );
    txtCourant->txt_police.survol.loadFromFile ( "media/polices/arial.ttf" );

    txtCourant->txt_style.set      (sf::Text::Style::Regular ) ;
    txtCourant->txt_taille.set      ( 12 ) ;
    txtCourant->txt_couleur.set     ( sf::Color(255, 255, 255 , 255 ) ) ;
    txtCourant->lgn_epaisseur.set   ( 0 ) ;
    txtCourant->lgn_couleur.set     ( sf::Color(255, 255, 255, 255) ) ;
    txtCourant->fnd_couleur.set     ( sf::Color(255, 255, 255, 0) ) ;


    txtLog->txt_police.repos.loadFromFile ( "media/polices/arial.ttf" );
    txtLog->txt_police.press.loadFromFile ( "media/polices/arial.ttf" );
    txtLog->txt_police.survol.loadFromFile( "media/polices/arial.ttf" );

    txtLog->txt_style.set(sf::Text::Style::Regular ) ;
    txtLog->txt_taille.set( 10 ) ;
    txtLog->txt_couleur.set( sf::Color(255, 255, 255 , 255 ) ) ;
    txtLog->lgn_epaisseur.set( 0 ) ;
    txtLog->lgn_couleur.set( sf::Color(255, 255, 255, 255) ) ;
    txtLog->fnd_couleur.set( sf::Color(255, 255, 255, 0) ) ;


    txtTitre->txt_police.repos.loadFromFile ( "media/polices/arial.ttf" );
    txtTitre->txt_police.press.loadFromFile ( "media/polices/arial.ttf" );
    txtTitre->txt_police.survol.loadFromFile( "media/polices/arial.ttf" );

    txtTitre->txt_style.set(sf::Text::Style::Italic ) ;
    txtTitre->txt_taille.set( 14 ) ;
    txtTitre->txt_couleur.set( sf::Color(255, 255, 255 , 255 ) ) ;
    txtTitre->lgn_epaisseur.set( 0 ) ;
    txtTitre->lgn_couleur.set( sf::Color(255, 255, 255, 255) ) ;
    txtTitre->fnd_couleur.set( sf::Color(255, 255, 255, 0) ) ;

//    fond->txt_police.repos.loadFromFile ( "media/polices/arial.ttf" );
//    fond->txt_police.press.loadFromFile ( "media/polices/arial.ttf" );
//    fond->txt_police.survol.loadFromFile( "media/polices/arial.ttf" );

    fond->txt_style.set(sf::Text::Style::Italic ) ;
    fond->txt_taille.set( 14 ) ;
    fond->txt_couleur.set( sf::Color(255, 255, 255 , 255 ) ) ;
    fond->lgn_epaisseur.set( 1 ) ;
    fond->lgn_couleur.set( sf::Color(255, 255, 255, 50) ) ;
    fond->fnd_couleur.set( sf::Color(255, 255, 255, 10) ) ;



    bouton->txt_police.repos.loadFromFile ( "media/polices/arial.ttf" );
    bouton->txt_police.press.loadFromFile ( "media/polices/arial.ttf" );
    bouton->txt_police.survol.loadFromFile( "media/polices/arial.ttf" );

    bouton->txt_style.set(sf::Text::Style::Regular ) ;
    bouton->txt_taille.set( 14 ) ;
    bouton->txt_couleur.set( sf::Color(255, 255, 255 , 255 ) ) ;
    bouton->lgn_epaisseur.set( 1 ) ;
    bouton->lgn_couleur.set ( sf::Color(255, 255, 255, 50) );
    bouton->fnd_couleur.repos = sf::Color(255, 255, 255, 20) ;
    bouton->fnd_couleur.survol= sf::Color(255, 255, 255, 50) ;
    bouton->fnd_couleur.press = sf::Color(255, 255, 255, 100) ;

    img->txt_style.set(sf::Text::Style::Italic ) ;
    img->txt_taille.set( 14 ) ;
    img->txt_couleur.set( sf::Color(255, 255, 255 , 255 ) ) ;
    img->lgn_epaisseur.set( 0 ) ;
    img->lgn_couleur.set( sf::Color(255, 255, 255, 255) ) ;
    img->fnd_couleur.set( sf::Color(255, 255, 255, 255) ) ;

    menu->txt_police.repos.loadFromFile ( "media/polices/arial.ttf" );
    menu->txt_police.press.loadFromFile ( "media/polices/arial.ttf" );
    menu->txt_police.survol.loadFromFile( "media/polices/arial.ttf" );

    menu->txt_style.set(sf::Text::Style::Italic ) ;
    menu->txt_taille.set( 11 ) ;
    menu->txt_couleur.set( sf::Color(255, 255, 255 , 255 ) ) ;
    menu->lgn_epaisseur.set( 0 ) ;
    menu->lgn_couleur.set( sf::Color(255, 0, 0, 255) ) ;
    menu->fnd_couleur.repos = sf::Color(255, 255, 255, 20) ;
    menu->fnd_couleur.survol= sf::Color(255, 255, 255, 50) ;
    menu->fnd_couleur.press = sf::Color(255, 255, 255, 100) ;

    fenetre->txt_police.repos.loadFromFile ( "media/polices/arial.ttf" );
    fenetre->txt_police.press.loadFromFile ( "media/polices/arial.ttf" );
    fenetre->txt_police.survol.loadFromFile( "media/polices/arial.ttf" );
    fenetre->txt_style.set(sf::Text::Style::Italic ) ;
    fenetre->txt_taille.set( 14 ) ;
    fenetre->txt_couleur.set( sf::Color(255, 255, 255 , 255 ) ) ;
    fenetre->lgn_epaisseur.set( 0 ) ;
    fenetre->lgn_couleur.set( sf::Color(255, 255, 255, 255) ) ;
    fenetre->fnd_couleur.set( sf::Color(255, 255, 255, 0) ) ;

};

}; // fin namespace gui

