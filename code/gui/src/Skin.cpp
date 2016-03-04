/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Skin.h>

#include <Style.h>
#include <Interface.h>

namespace gui{
/////////////////////////////////////////////////
Skin::Skin ()
{

    // Creation des differents style du skin
    for ( int i = 0; i != Styles::tous ; i++ )
        m_styles.insert( { i , std::make_shared<Style>() } );

    creerDefaut();
}

/////////////////////////////////////////////////
void Skin::creerDefaut(){

    std::shared_ptr<Style> style;

    style = getStyle( Styles::defaut );

    style->txt_police.set ( Interface::ms_polices.get(  "Defaut" ) );
    style->txt_style.set(sf::Text::Style::Bold ) ;
    style->txt_taille.set( 14 ) ;
    style->txt_couleur.set( sf::Color(255, 255, 255 , 255 ) ) ;
    style->lgn_epaisseur.set( 1 ) ;
    style->lgn_couleur.set ( sf::Color(255, 255, 255, 100) );
    style->fnd_couleur.set ( sf::Color(255, 255, 255, 20) );


    style = getStyle( Styles::invisible );

    style->txt_police.set ( Interface::ms_polices.get(  "Defaut" ) );
    style->txt_style.set       ( sf::Text::Style::Regular ) ;
    style->txt_taille.set       ( 10 ) ;
    style->txt_couleur.set      ( sf::Color(255, 255, 255 , 0) ) ;
    style->lgn_epaisseur.set    ( 1 ) ;
    style->lgn_couleur.set      ( sf::Color(255, 255, 255, 0) ) ;
    style->fnd_couleur.set      ( sf::Color(255, 255, 255, 0) ) ;


    style = getStyle( Styles::cadre);

    style->txt_police.set ( Interface::ms_polices.get( "Defaut" ) );
    style->txt_style.set        (sf::Text::Style::Regular ) ;
    style->txt_taille.set       ( 10 ) ;
    style->txt_couleur.set      ( sf::Color(255, 255, 255 , 0) ) ;
    style->lgn_epaisseur.set    ( 1 ) ;
    style->lgn_couleur.set      ( sf::Color(255, 255, 255, 150) ) ;
    style->lgn_couleur.desactive= sf::Color(255, 255, 255, 75);
    style->fnd_couleur.set      ( sf::Color(255, 255, 255, 100) ) ;
    style->fnd_couleur.desactive= sf::Color(255, 255, 255, 50);


    style = getStyle( Styles::txtCourant);

    style->txt_police.set      ( Interface::ms_polices.get( "Defaut" ) );
    style->txt_style.set       (sf::Text::Style::Italic ) ;
    style->txt_taille.set      ( 11 ) ;
    style->txt_couleur.set     ( sf::Color(255, 255, 255 , 255 ) ) ;
    style->lgn_epaisseur.set   ( 0 ) ;
    style->lgn_couleur.set     ( sf::Color(255, 255, 255, 0) ) ;
    style->fnd_couleur.set     ( sf::Color(255, 255, 255, 0) ) ;


    style = getStyle( Styles::txtLog);

    style->txt_police.set ( Interface::ms_polices.get( "Defaut" ) );
    style->txt_style.set(sf::Text::Style::Regular ) ;
    style->txt_taille.set( 9.5 ) ;
    style->txt_couleur.set( sf::Color(255, 255, 255 , 150 ) ) ;
    style->lgn_epaisseur.set( 0 ) ;
    style->lgn_couleur.set( sf::Color(255, 255, 255, 255) ) ;
    style->fnd_couleur.set( sf::Color(255, 255, 255, 0) ) ;


    style = getStyle( Styles::txtTitre);

    style->txt_police.set ( Interface::ms_polices.get( "Defaut" ) );
    style->txt_style.set(sf::Text::Style::Italic ) ;
    style->txt_taille.set( 25 ) ;
    style->txt_couleur.set( sf::Color(255, 255, 255 , 200 ) ) ;
    style->lgn_epaisseur.set( 0 ) ;
    style->lgn_couleur.set( sf::Color(255, 255, 255, 255) ) ;
    style->fnd_couleur.set( sf::Color(255, 255, 255, 0) ) ;


    style = getStyle( Styles::fond);

    style->txt_police.set ( Interface::ms_polices.get(  "Defaut" ) );
    style->txt_style.set(sf::Text::Style::Italic ) ;
    style->txt_taille.set( 14 ) ;
    style->txt_couleur.set( sf::Color(255, 255, 255 , 255 ) ) ;
    style->lgn_epaisseur.set( 0 ) ;
    style->lgn_couleur.set( sf::Color(255, 255, 255, 10) ) ;
//    style->fnd_couleur.set( sf::Color(0, 0, 0, 20) ) ;
    style->fnd_couleur.set( sf::Color(90, 90, 90, 255) ) ;
//    style->fnd_couleur.set( sf::Color(255, 255, 255, 10) , Etat::repos ) ;

    style = getStyle( Styles::bouton);

    style->txt_police.set ( Interface::ms_polices.get(  "Defaut" ) );
    style->txt_style.set(sf::Text::Style::Bold ) ;
    style->txt_taille.set( 13 ) ;
    style->txt_couleur.set( sf::Color( 0, 255, 255 , 255 ) ) ;
    style->txt_couleur.desactive = sf::Color( 255, 255, 255, 50 ) ;
    style->lgn_epaisseur.set( 0 ) ;
    style->lgn_couleur.set ( sf::Color( 255, 255, 255, 100 ) );
    style->lgn_couleur.desactive = sf::Color( 255, 255, 255, 0 ) ;

//    style->fnd_couleur.set ( sf::Color( 0, 0, 255, 255 ) );

    style->fnd_couleur.repos = sf::Color( 255, 255, 255, 50 ) ;
    style->fnd_couleur.survol= sf::Color( 255, 255, 255, 100 ) ;
    style->fnd_couleur.press = sf::Color( 255, 255, 255, 150 ) ;
    style->fnd_couleur.desactive = sf::Color(255, 255, 255, 10 ) ;


    style = getStyle( Styles::btnCoche);

    style->txt_police.set ( Interface::ms_polices.get(  "Defaut" ) );
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

    style->txt_police.set ( Interface::ms_polices.get(  "Defaut" )  );
    style->txt_style.set(sf::Text::Style::Italic ) ;
    style->txt_taille.set( 14 ) ;
    style->txt_couleur.set( sf::Color(255, 255, 255 , 255 ) ) ;
    style->lgn_epaisseur.set( 0 ) ;
    style->lgn_couleur.set( sf::Color(255, 255, 255, 255) ) ;
    style->fnd_couleur.set( sf::Color(255, 255, 255, 255) ) ;


    style = getStyle( Styles::menu);

    style->txt_police.set ( Interface::ms_polices.get(  "Defaut" )  );
    style->txt_style.set(sf::Text::Style::Italic ) ;
    style->txt_taille.set( 10 ) ;
    style->txt_couleur.set( sf::Color(255, 255, 255 , 255 ) ) ;
    style->lgn_epaisseur.set( 0 ) ;
    style->lgn_couleur.set( sf::Color(255, 0, 0, 255) ) ;
    style->fnd_couleur.repos = sf::Color(255, 255, 255, 30) ;
    style->fnd_couleur.survol= sf::Color(255, 255, 255, 70) ;
    style->fnd_couleur.press = sf::Color(255, 255, 255, 150) ;


    style = getStyle( Styles::fenetre);

    style->txt_police.set ( Interface::ms_polices.get(  "Defaut" )  );
    style->txt_style.set(sf::Text::Style::Italic ) ;
    style->txt_taille.set( 14 ) ;
    style->txt_couleur.set( sf::Color( 255, 255, 255 , 200 ) ) ;

    style->lgn_epaisseur.set( 0.5 ) ;
    style->lgn_couleur.set( sf::Color( 140, 140, 140, 255) ) ;

    style->fnd_couleur.set( sf::Color( 90, 90, 90, 255 ) ) ;

//    style->fnd_couleur.repos = sf::Color( 255, 255, 255, 255 ) ;
//    style->fnd_couleur.survol= sf::Color( 255, 255, 255, 255 ) ;
//    style->fnd_couleur.press = sf::Color( 255, 255, 255, 255 ) ;
//    style->fnd_couleur.desactive = sf::Color(255, 255, 255, 255 ) ;

    style = getStyle( Styles::zoneTexte);

    style->txt_police.set ( Interface::ms_polices.get(  "Defaut" ) );
    style->txt_style.set(sf::Text::Style::Italic ) ;
    style->txt_taille.set( 12 ) ;
    style->txt_couleur.set( sf::Color(255, 255, 255 , 255 ) );
    style->lgn_epaisseur.set( 0 ) ;
    style->lgn_couleur.set( sf::Color(255, 255, 255, 255) );
    style->fnd_couleur.set( sf::Color(155, 155, 155, 255) );


    style = getStyle( Styles::slider);

    style->txt_police.set ( Interface::ms_polices.get( "Defaut" ) );
    style->txt_style.set(sf::Text::Style::Italic ) ;
    style->txt_taille.set( 12 ) ;
    style->txt_couleur.set( sf::Color(255, 255, 255 , 255 ) ) ;
    style->lgn_epaisseur.set( 0 ) ;
    style->lgn_couleur.set( sf::Color(150, 150, 150, 255) ) ;
    style->fnd_couleur.repos = sf::Color(150, 150, 150, 255) ;
    style->fnd_couleur.survol= sf::Color(180, 180, 180, 255) ;
    style->fnd_couleur.press = sf::Color(200, 200, 200, 255) ;
    style->fnd_couleur.desactive = sf::Color(255, 255, 255, 10 ) ;

    style = getStyle( Styles::defilement);

    style->txt_police.set ( Interface::ms_polices.get( "Defaut" ) );
    style->txt_style.set(sf::Text::Style::Italic ) ;
    style->txt_taille.set( 12 ) ;
    style->txt_couleur.set( sf::Color(255, 255, 255 , 255 ) ) ;
    style->lgn_epaisseur.set( 0 ) ;
    style->lgn_couleur.set( sf::Color(150, 150, 150, 255) ) ;
    style->fnd_couleur.repos = sf::Color(0, 0, 255, 255) ;
    style->fnd_couleur.survol= sf::Color(0, 0, 255, 255) ;
    style->fnd_couleur.press = sf::Color(0, 0, 255, 255) ;
    style->fnd_couleur.desactive = sf::Color(255, 255, 255, 10 ) ;

}

}; // fin namespace gui

