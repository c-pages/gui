/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Skin.h>

#include <Style.h>

namespace gui{
/////////////////////////////////////////////////
Skin::Skin ()
: invisible     ( std::make_shared<Style> () )
, cadre         ( std::make_shared<Style> () )
, txtCourant    ( std::make_shared<Style> () )
, txtLog        ( std::make_shared<Style> () )
, txtTitre      ( std::make_shared<Style> () )
, fond          ( std::make_shared<Style> () )
, bouton        ( std::make_shared<Style> () )
, btnCoche      ( std::make_shared<Style> () )
, img           ( std::make_shared<Style> () )
, menu          ( std::make_shared<Style> () )
, fenetre       ( std::make_shared<Style> () )
, zoneTexte     ( std::make_shared<Style> () )
, Slider        ( std::make_shared<Style> () )
{
    //Un skin par défaut



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

    cadre->txt_style.set        (sf::Text::Style::Regular ) ;
    cadre->txt_taille.set       ( 10 ) ;
    cadre->txt_couleur.set      ( sf::Color(255, 255, 255 , 0) ) ;
    cadre->lgn_epaisseur.set    ( 1 ) ;
    cadre->lgn_couleur.set      ( sf::Color(255, 255, 255, 150) ) ;
    cadre->lgn_couleur.desactive= sf::Color(255, 255, 255, 75);
    cadre->fnd_couleur.set      ( sf::Color(255, 255, 255, 100) ) ;
    cadre->fnd_couleur.desactive= sf::Color(255, 255, 255, 50);

    txtCourant->txt_police.repos.loadFromFile  ( "media/polices/arial.ttf" );
    txtCourant->txt_police.press.loadFromFile  ( "media/polices/arial.ttf" );
    txtCourant->txt_police.survol.loadFromFile ( "media/polices/arial.ttf" );
    txtCourant->txt_police.desactive.loadFromFile( "media/polices/arial.ttf" );

    txtCourant->txt_style.set       (sf::Text::Style::Regular ) ;
    txtCourant->txt_taille.set      ( 5 ) ;
    txtCourant->txt_couleur.set     ( sf::Color(255, 255, 255 , 255 ) ) ;
    txtCourant->lgn_epaisseur.set   ( 0 ) ;
    txtCourant->lgn_couleur.set     ( sf::Color(255, 255, 255, 0) ) ;
    txtCourant->fnd_couleur.set     ( sf::Color(255, 255, 255, 0) ) ;


    txtLog->txt_police.repos.loadFromFile ( "media/polices/arial.ttf" );
    txtLog->txt_police.press.loadFromFile ( "media/polices/arial.ttf" );
    txtLog->txt_police.survol.loadFromFile( "media/polices/arial.ttf" );
    txtLog->txt_police.desactive.loadFromFile( "media/polices/arial.ttf" );

    txtLog->txt_style.set(sf::Text::Style::Regular ) ;
    txtLog->txt_taille.set( 10 ) ;
    txtLog->txt_couleur.set( sf::Color(255, 255, 255 , 150 ) ) ;
    txtLog->lgn_epaisseur.set( 0 ) ;
    txtLog->lgn_couleur.set( sf::Color(255, 255, 255, 255) ) ;
    txtLog->fnd_couleur.set( sf::Color(255, 255, 255, 0) ) ;


    txtTitre->txt_police.repos.loadFromFile ( "media/polices/arial.ttf" );
    txtTitre->txt_police.press.loadFromFile ( "media/polices/arial.ttf" );
    txtTitre->txt_police.survol.loadFromFile( "media/polices/arial.ttf" );
    txtTitre->txt_police.desactive.loadFromFile( "media/polices/arial.ttf" );

    txtTitre->txt_style.set(sf::Text::Style::Bold ) ;
    txtTitre->txt_taille.set( 21 ) ;
    txtTitre->txt_couleur.set( sf::Color(255, 255, 255 , 200 ) ) ;
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
    fond->lgn_couleur.set( sf::Color(255, 255, 255, 100) ) ;
    fond->fnd_couleur.set( sf::Color(255, 255, 255, 10) ) ;



    bouton->txt_police.repos.loadFromFile ( "media/polices/arial.ttf" );
    bouton->txt_police.press.loadFromFile ( "media/polices/arial.ttf" );
    bouton->txt_police.survol.loadFromFile( "media/polices/arial.ttf" );
    bouton->txt_police.desactive.loadFromFile( "media/polices/arial.ttf" );

    bouton->txt_style.set(sf::Text::Style::Bold ) ;
    bouton->txt_taille.set( 14 ) ;
    bouton->txt_couleur.set( sf::Color(255, 255, 255 , 255 ) ) ;
    bouton->txt_couleur.desactive = sf::Color(255, 255, 255, 50 ) ;
    bouton->lgn_epaisseur.set( 1 ) ;
    bouton->lgn_couleur.set ( sf::Color(255, 255, 255, 100) );
    bouton->lgn_couleur.desactive = sf::Color(255, 255, 255, 30 ) ;
    bouton->fnd_couleur.repos = sf::Color(255, 255, 255, 20) ;
    bouton->fnd_couleur.survol= sf::Color(255, 255, 255, 50) ;
    bouton->fnd_couleur.press = sf::Color(255, 255, 255, 100) ;
    bouton->fnd_couleur.desactive = sf::Color(255, 255, 255, 10 ) ;



    btnCoche->txt_police.repos.loadFromFile ( "media/polices/arial.ttf" );
    btnCoche->txt_police.press.loadFromFile ( "media/polices/arial.ttf" );
    btnCoche->txt_police.survol.loadFromFile( "media/polices/arial.ttf" );
    btnCoche->txt_police.desactive.loadFromFile( "media/polices/arial.ttf" );

    btnCoche->txt_style.set(sf::Text::Style::Regular ) ;
    btnCoche->txt_taille.set( 11 ) ;
    btnCoche->txt_couleur.set( sf::Color(255, 255, 255 , 255 ) ) ;
    btnCoche->txt_couleur.desactive = sf::Color(255, 255, 255, 50 ) ;
    btnCoche->lgn_epaisseur.set( 1 ) ;
    btnCoche->lgn_couleur.set ( sf::Color(255, 255, 255, 100) );
    btnCoche->lgn_couleur.desactive = sf::Color(255, 255, 255, 50 ) ;
    btnCoche->fnd_couleur.set ( sf::Color(255, 255, 255, 150) );



    img->txt_style.set(sf::Text::Style::Italic ) ;
    img->txt_taille.set( 14 ) ;
    img->txt_couleur.set( sf::Color(255, 255, 255 , 255 ) ) ;
    img->lgn_epaisseur.set( 0 ) ;
    img->lgn_couleur.set( sf::Color(255, 255, 255, 255) ) ;
    img->fnd_couleur.set( sf::Color(255, 255, 255, 255) ) ;

    menu->txt_police.repos.loadFromFile ( "media/polices/consola.ttf" );
    menu->txt_police.press.loadFromFile ( "media/polices/consola.ttf" );
    menu->txt_police.survol.loadFromFile( "media/polices/consola.ttf" );
    menu->txt_police.desactive.loadFromFile( "media/polices/consola.ttf" );

    menu->txt_style.set(sf::Text::Style::Italic ) ;
    menu->txt_taille.set( 10 ) ;
    menu->txt_couleur.set( sf::Color(255, 255, 255 , 255 ) ) ;
    menu->lgn_epaisseur.set( 0 ) ;
    menu->lgn_couleur.set( sf::Color(255, 0, 0, 255) ) ;
    menu->fnd_couleur.repos = sf::Color(255, 255, 255, 20) ;
    menu->fnd_couleur.survol= sf::Color(255, 255, 255, 50) ;
    menu->fnd_couleur.press = sf::Color(255, 255, 255, 100) ;

    fenetre->txt_police.repos.loadFromFile ( "media/polices/arial.ttf" );
    fenetre->txt_police.press.loadFromFile ( "media/polices/consola.ttf" );
    fenetre->txt_police.survol.loadFromFile( "media/polices/arial.ttf" );
    fenetre->txt_police.desactive.loadFromFile( "media/polices/consola.ttf" );
    fenetre->txt_style.set(sf::Text::Style::Italic ) ;
    fenetre->txt_taille.set( 14 ) ;
    fenetre->txt_couleur.set( sf::Color(255, 255, 255 , 255 ) ) ;
    fenetre->lgn_epaisseur.set( 0 ) ;
    fenetre->lgn_couleur.set( sf::Color(255, 255, 255, 255) ) ;
    fenetre->fnd_couleur.set( sf::Color(255, 255, 255, 0) ) ;

    zoneTexte->txt_police.repos.loadFromFile ( "media/polices/arial.ttf" );
    zoneTexte->txt_police.press.loadFromFile ( "media/polices/consola.ttf" );
    zoneTexte->txt_police.survol.loadFromFile( "media/polices/arial.ttf" );
    zoneTexte->txt_police.desactive.loadFromFile( "media/polices/consola.ttf" );
    zoneTexte->txt_style.set(sf::Text::Style::Italic ) ;
    zoneTexte->txt_taille.set( 12 ) ;
    zoneTexte->txt_couleur.set( sf::Color(255, 255, 255 , 255 ) ) ;
    zoneTexte->lgn_epaisseur.set( 1 ) ;
    zoneTexte->lgn_couleur.set( sf::Color(255, 255, 255, 255) ) ;
    zoneTexte->fnd_couleur.set( sf::Color(155, 155, 155, 255) ) ;


//    Slider->txt_police.repos.loadFromFile ( "media/polices/arial.ttf" );
//    Slider->txt_police.press.loadFromFile ( "media/polices/consola.ttf" );
//    Slider->txt_police.survol.loadFromFile( "media/polices/arial.ttf" );
//    Slider->txt_police.desactive.loadFromFile( "media/polices/consola.ttf" );
    Slider->txt_style.set(sf::Text::Style::Italic ) ;
    Slider->txt_taille.set( 12 ) ;
    Slider->txt_couleur.set( sf::Color(255, 255, 255 , 255 ) ) ;
    Slider->lgn_epaisseur.set( 1 ) ;
    Slider->lgn_couleur.set( sf::Color(150, 150, 150, 255) ) ;
    Slider->fnd_couleur.repos = sf::Color(255, 255, 255, 100) ;
    Slider->fnd_couleur.survol= sf::Color(255, 255, 255, 150) ;
    Slider->fnd_couleur.press = sf::Color(255, 255, 255, 200) ;
    Slider->fnd_couleur.desactive = sf::Color(255, 255, 255, 10 ) ;
};

}; // fin namespace gui

