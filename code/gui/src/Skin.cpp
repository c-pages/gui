/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Skin.h>

#include <Style.h>

namespace gui{
/////////////////////////////////////////////////
Skin::Skin ()
{

    for ( int i = 0; i != static_cast<int>( Styles::tous ); i++ )    {
        auto nouveauStyle = std::make_pair<Styles,std::shared_ptr<Style>> ( static_cast<Styles>(i) , std::make_shared<Style>());
        m_styles.insert( nouveauStyle );
        /*
    //        nouveauStyle.second();


    //    invisible->txt_police.repos.loadFromFile ( "media/polices/arial.ttf" );
    //    invisible->txt_police.press.loadFromFile ( "media/polices/arial.ttf" );
    //    invisible->txt_police.survol.loadFromFile( "media/polices/arial.ttf" );
        // VAL
        nouveauStyle.second->txt_style.set       ( sf::Text::Style::Regular ) ;
        nouveauStyle.second->txt_taille.set       ( 10 ) ;
        nouveauStyle.second->txt_couleur.set      ( sf::Color(255, 255, 255 , 200) ) ;
        nouveauStyle.second->lgn_epaisseur.set    ( 1 ) ;
        nouveauStyle.second->lgn_couleur.set      ( sf::Color(255, 255, 255, 100) ) ;
        nouveauStyle.second->fnd_couleur.set      ( sf::Color(255, 255, 255, 100) ) ;


*/

    }

    std::shared_ptr<Style> style;

    style = getStyle( Styles::invisible );
//    style->txt_police.repos.loadFromFile ( "media/polices/arial.ttf" );
//    style->txt_police.press.loadFromFile ( "media/polices/arial.ttf" );
//    style->txt_police.survol.loadFromFile( "media/polices/arial.ttf" );

    style->txt_style.set       ( sf::Text::Style::Regular ) ;
    style->txt_taille.set       ( 10 ) ;
    style->txt_couleur.set      ( sf::Color(255, 255, 255 , 0) ) ;
    style->lgn_epaisseur.set    ( 1 ) ;
    style->lgn_couleur.set      ( sf::Color(255, 255, 255, 0) ) ;
    style->fnd_couleur.set      ( sf::Color(255, 255, 255, 0) ) ;

    //getStyle(invisible)->fnd_texture;

//    getStyle(getStyle(cadre))->txt_police.repos.loadFromFile ( "media/polices/arial.ttf" );
//    getStyle(getStyle(cadre))->txt_police.press.loadFromFile ( "media/polices/arial.ttf" );
//    getStyle(cadre)->txt_police.survol.loadFromFile( "media/polices/arial.ttf" );

    style = getStyle( Styles::cadre);
    style->txt_style.set        (sf::Text::Style::Regular ) ;
    style->txt_taille.set       ( 10 ) ;
    style->txt_couleur.set      ( sf::Color(255, 255, 255 , 0) ) ;
    style->lgn_epaisseur.set    ( 1 ) ;
    style->lgn_couleur.set      ( sf::Color(255, 255, 255, 150) ) ;
    style->lgn_couleur.desactive= sf::Color(255, 255, 255, 75);
    style->fnd_couleur.set      ( sf::Color(255, 255, 255, 100) ) ;
    style->fnd_couleur.desactive= sf::Color(255, 255, 255, 50);

    style = getStyle( Styles::txtCourant);
    style->txt_police.repos.loadFromFile  ( "media/polices/arial.ttf" );
    style->txt_police.press.loadFromFile  ( "media/polices/arial.ttf" );
    style->txt_police.survol.loadFromFile ( "media/polices/arial.ttf" );
    style->txt_police.desactive.loadFromFile( "media/polices/arial.ttf" );

    style->txt_style.set       (sf::Text::Style::Regular ) ;
    style->txt_taille.set      ( 5 ) ;
    style->txt_couleur.set     ( sf::Color(255, 255, 255 , 255 ) ) ;
    style->lgn_epaisseur.set   ( 0 ) ;
    style->lgn_couleur.set     ( sf::Color(255, 255, 255, 0) ) ;
    style->fnd_couleur.set     ( sf::Color(255, 255, 255, 0) ) ;

    style = getStyle( Styles::txtLog);
    style->txt_police.repos.loadFromFile ( "media/polices/arial.ttf" );
    style->txt_police.press.loadFromFile ( "media/polices/arial.ttf" );
    style->txt_police.survol.loadFromFile( "media/polices/arial.ttf" );
    style->txt_police.desactive.loadFromFile( "media/polices/arial.ttf" );

    style->txt_style.set(sf::Text::Style::Regular ) ;
    style->txt_taille.set( 10 ) ;
    style->txt_couleur.set( sf::Color(255, 255, 255 , 150 ) ) ;
    style->lgn_epaisseur.set( 0 ) ;
    style->lgn_couleur.set( sf::Color(255, 255, 255, 255) ) ;
    style->fnd_couleur.set( sf::Color(255, 255, 255, 0) ) ;

    style = getStyle( Styles::txtTitre);
    style->txt_police.repos.loadFromFile ( "media/polices/arial.ttf" );
    style->txt_police.press.loadFromFile ( "media/polices/arial.ttf" );
    style->txt_police.survol.loadFromFile( "media/polices/arial.ttf" );
    style->txt_police.desactive.loadFromFile( "media/polices/arial.ttf" );

    style->txt_style.set(sf::Text::Style::Bold ) ;
    style->txt_taille.set( 21 ) ;
    style->txt_couleur.set( sf::Color(255, 255, 255 , 200 ) ) ;
    style->lgn_epaisseur.set( 0 ) ;
    style->lgn_couleur.set( sf::Color(255, 255, 255, 255) ) ;
    style->fnd_couleur.set( sf::Color(255, 255, 255, 0) ) ;

    style = getStyle( Styles::fond);
//    style->txt_police.repos.loadFromFile ( "media/polices/arial.ttf" );
//    style->txt_police.press.loadFromFile ( "media/polices/arial.ttf" );
//    style->txt_police.survol.loadFromFile( "media/polices/arial.ttf" );

    style->txt_style.set(sf::Text::Style::Italic ) ;
    style->txt_taille.set( 14 ) ;
    style->txt_couleur.set( sf::Color(255, 255, 255 , 255 ) ) ;
    style->lgn_epaisseur.set( 1 ) ;
    style->lgn_couleur.set( sf::Color(255, 255, 255, 100) ) ;
    style->fnd_couleur.set( sf::Color(255, 255, 255, 10) ) ;

    style = getStyle( Styles::bouton);
    style->txt_police.repos.loadFromFile ( "media/polices/arial.ttf" );
    style->txt_police.press.loadFromFile ( "media/polices/arial.ttf" );
    style->txt_police.survol.loadFromFile( "media/polices/arial.ttf" );
    style->txt_police.desactive.loadFromFile( "media/polices/arial.ttf" );

    style->txt_style.set(sf::Text::Style::Bold ) ;
    style->txt_taille.set( 14 ) ;
    style->txt_couleur.set( sf::Color(255, 255, 255 , 255 ) ) ;
    style->txt_couleur.desactive = sf::Color(255, 255, 255, 50 ) ;
    style->lgn_epaisseur.set( 1 ) ;
    style->lgn_couleur.set ( sf::Color(255, 255, 255, 100) );
    style->lgn_couleur.desactive = sf::Color(255, 255, 255, 30 ) ;
    style->fnd_couleur.repos = sf::Color(255, 255, 255, 20) ;
    style->fnd_couleur.survol= sf::Color(255, 255, 255, 50) ;
    style->fnd_couleur.press = sf::Color(255, 255, 255, 100) ;
    style->fnd_couleur.desactive = sf::Color(255, 255, 255, 10 ) ;


    style = getStyle( Styles::btnCoche);
    style->txt_police.repos.loadFromFile ( "media/polices/arial.ttf" );
    style->txt_police.press.loadFromFile ( "media/polices/arial.ttf" );
    style->txt_police.survol.loadFromFile( "media/polices/arial.ttf" );
    style->txt_police.desactive.loadFromFile( "media/polices/arial.ttf" );

    style->txt_style.set(sf::Text::Style::Regular ) ;
    style->txt_taille.set( 11 ) ;
    style->txt_couleur.set( sf::Color(255, 255, 255 , 255 ) ) ;
    style->txt_couleur.desactive = sf::Color(255, 255, 255, 50 ) ;
    style->lgn_epaisseur.set( 1 ) ;
    style->lgn_couleur.set ( sf::Color(255, 255, 255, 100) );
    style->lgn_couleur.desactive = sf::Color(255, 255, 255, 50 ) ;
    style->fnd_couleur.set ( sf::Color(255, 255, 255, 50) );
    style->fnd_couleur.set ( sf::Color(255, 255, 255, 200) , Etat::press );



    style = getStyle( Styles::img);
    style->txt_style.set(sf::Text::Style::Italic ) ;
    style->txt_taille.set( 14 ) ;
    style->txt_couleur.set( sf::Color(255, 255, 255 , 255 ) ) ;
    style->lgn_epaisseur.set( 0 ) ;
    style->lgn_couleur.set( sf::Color(255, 255, 255, 255) ) ;
    style->fnd_couleur.set( sf::Color(255, 255, 255, 255) ) ;

    style = getStyle( Styles::menu);
    style->txt_police.repos.loadFromFile ( "media/polices/consola.ttf" );
    style->txt_police.press.loadFromFile ( "media/polices/consola.ttf" );
    style->txt_police.survol.loadFromFile( "media/polices/consola.ttf" );
    style->txt_police.desactive.loadFromFile( "media/polices/consola.ttf" );

    style->txt_style.set(sf::Text::Style::Italic ) ;
    style->txt_taille.set( 10 ) ;
    style->txt_couleur.set( sf::Color(255, 255, 255 , 255 ) ) ;
    style->lgn_epaisseur.set( 0 ) ;
    style->lgn_couleur.set( sf::Color(255, 0, 0, 255) ) ;
    style->fnd_couleur.repos = sf::Color(255, 255, 255, 20) ;
    style->fnd_couleur.survol= sf::Color(255, 255, 255, 50) ;
    style->fnd_couleur.press = sf::Color(255, 255, 255, 100) ;

    style = getStyle( Styles::fenetre);
    style->txt_police.repos.loadFromFile ( "media/polices/arial.ttf" );
    style->txt_police.press.loadFromFile ( "media/polices/consola.ttf" );
    style->txt_police.survol.loadFromFile( "media/polices/arial.ttf" );
    style->txt_police.desactive.loadFromFile( "media/polices/consola.ttf" );
    style->txt_style.set(sf::Text::Style::Italic ) ;
    style->txt_taille.set( 14 ) ;
    style->txt_couleur.set( sf::Color(255, 255, 255 , 255 ) ) ;
    style->lgn_epaisseur.set( 0 ) ;
    style->lgn_couleur.set( sf::Color(255, 255, 255, 255) ) ;
    style->fnd_couleur.set( sf::Color(255, 255, 255, 0) ) ;

    style = getStyle( Styles::zoneTexte);
    style->txt_police.repos.loadFromFile ( "media/polices/arial.ttf" );
    style->txt_police.press.loadFromFile ( "media/polices/consola.ttf" );
    style->txt_police.survol.loadFromFile( "media/polices/arial.ttf" );
    style->txt_police.desactive.loadFromFile( "media/polices/consola.ttf" );
    style->txt_style.set(sf::Text::Style::Italic ) ;
    style->txt_taille.set( 12 ) ;
    style->txt_couleur.set( sf::Color(255, 255, 255 , 255 ) ) ;
    style->lgn_epaisseur.set( 1 ) ;
    style->lgn_couleur.set( sf::Color(255, 255, 255, 255) ) ;
    style->fnd_couleur.set( sf::Color(155, 155, 155, 255) ) ;


    style = getStyle( Styles::slider);
//    style->txt_police.repos.loadFromFile ( "media/polices/arial.ttf" );
//    style->txt_police.press.loadFromFile ( "media/polices/consola.ttf" );
//    style->txt_police.survol.loadFromFile( "media/polices/arial.ttf" );
//    style->txt_police.desactive.loadFromFile( "media/polices/consola.ttf" );
    style->txt_style.set(sf::Text::Style::Italic ) ;
    style->txt_taille.set( 12 ) ;
    style->txt_couleur.set( sf::Color(255, 255, 255 , 255 ) ) ;
    style->lgn_epaisseur.set( 1 ) ;
    style->lgn_couleur.set( sf::Color(150, 150, 150, 255) ) ;
    style->fnd_couleur.repos = sf::Color(255, 255, 255, 100) ;
    style->fnd_couleur.survol= sf::Color(255, 255, 255, 150) ;
    style->fnd_couleur.press = sf::Color(255, 255, 255, 200) ;
    style->fnd_couleur.desactive = sf::Color(255, 255, 255, 10 ) ;
}

}; // fin namespace gui

