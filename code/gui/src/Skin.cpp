/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Skin.h>

#include <Style.h>

namespace gui{
/////////////////////////////////////////////////
Skin::Skin ()
: invisible ( std::make_shared<Style> () )
, cadre     ( std::make_shared<Style> () )
, txtLog    ( std::make_shared<Style> () )
, txtCourant( std::make_shared<Style> () )
, txtTitre  ( std::make_shared<Style> () )
, fond      ( std::make_shared<Style> () )
, btnPress  ( std::make_shared<Style> () )
, btnSurvol ( std::make_shared<Style> () )
, btnRepos  ( std::make_shared<Style> () )
, imgRepos  ( std::make_shared<Style> () )
, fenetre   ( std::make_shared<Style> () )
, desactive ( std::make_shared<Style> () )
{
    //Un skin par défaut
    invisible->txt_police.loadFromFile ( "media/polices/arial.ttf" );
    invisible->txt_style        = sf::Text::Style::Regular;
    invisible->txt_taille       = 10;
    invisible->txt_couleur      = sf::Color(255, 255, 255, 0);
    invisible->lgn_epaisseur    = 0;
    invisible->lgn_couleur      = sf::Color(255, 255, 255, 0);
    invisible->fnd_couleur      = sf::Color(255, 255, 255, 0);

    cadre->txt_police.loadFromFile ( "media/polices/arial.ttf" );
    cadre->txt_style        = sf::Text::Style::Regular;
    cadre->txt_taille       = 10;
    cadre->txt_couleur      = sf::Color(255, 255, 255, 0);
    cadre->lgn_epaisseur    = 1;
    cadre->lgn_couleur      = sf::Color(255, 255, 255, 255);
    cadre->fnd_couleur      = sf::Color(255, 255, 255, 0);


    txtCourant->txt_police.loadFromFile ( "media/polices/arial.ttf" );
    txtCourant->txt_style        = sf::Text::Style::Regular;
    txtCourant->txt_taille       = 15;
    txtCourant->txt_couleur      = sf::Color(255, 255, 255, 200);
    txtCourant->lgn_epaisseur    = 0;
    txtCourant->lgn_couleur      = sf::Color(255, 255, 255, 0);
    txtCourant->fnd_couleur      = sf::Color(255, 255, 255, 0);

    txtLog->txt_police.loadFromFile ( "media/polices/arial.ttf" );
    txtLog->txt_style        = sf::Text::Style::Regular;
    txtLog->txt_taille       = 7;
    txtLog->txt_couleur      = sf::Color(255, 255, 255, 255);
    txtLog->lgn_epaisseur    = 0;
    txtLog->lgn_couleur      = sf::Color(255, 255, 255, 0);
    txtLog->fnd_couleur      = sf::Color(255, 255, 255, 0);

    txtTitre->txt_police.loadFromFile ( "media/polices/arial.ttf" );
    txtTitre->txt_style        = sf::Text::Style::Regular;
    txtTitre->txt_taille       = 7;
    txtTitre->txt_couleur      = sf::Color(255, 255, 255, 255);
    txtTitre->lgn_epaisseur    = 0;
    txtTitre->lgn_couleur      = sf::Color(255, 255, 255, 0);
    txtTitre->fnd_couleur      = sf::Color(255, 255, 255, 0);

    fond->txt_police.loadFromFile ( "media/polices/arial.ttf" );
    fond->txt_style        = sf::Text::Style::Regular;
    fond->txt_taille       = 7;
    fond->txt_couleur      = sf::Color(255, 255, 255, 250);
    fond->lgn_epaisseur    = 0;
    fond->lgn_couleur      = sf::Color(255, 255, 255, 0);
    fond->fnd_couleur      = sf::Color(0, 0, 255, 250);

    btnRepos->txt_police.loadFromFile ( "media/polices/arial.ttf" );
    btnRepos->txt_style        = sf::Text::Style::Regular;
    btnRepos->txt_taille       = 10;
    btnRepos->txt_couleur      = sf::Color(255, 255, 255, 0);
    btnRepos->lgn_epaisseur    = 5;
    btnRepos->lgn_couleur      = sf::Color(255, 255, 255, 50);
    btnRepos->fnd_couleur      = sf::Color(255, 255, 255, 20);

    btnPress->txt_police.loadFromFile ( "media/polices/arial.ttf" );
    btnPress->txt_style        = sf::Text::Style::Regular;
    btnPress->txt_taille       = 10;
    btnPress->txt_couleur      = sf::Color(255, 255, 255, 0);
    btnPress->lgn_epaisseur    = 5;
    btnPress->lgn_couleur      = sf::Color(255, 255, 255, 100);
    btnPress->fnd_couleur      = sf::Color(255, 255, 255, 100);

    btnSurvol->txt_police.loadFromFile ( "media/polices/arial.ttf" );
    btnSurvol->txt_style        = sf::Text::Style::Regular;
    btnSurvol->txt_taille       = 10;
    btnSurvol->txt_couleur      = sf::Color(255, 255, 255, 0);
    btnSurvol->lgn_epaisseur    = 5;
    btnSurvol->lgn_couleur      = sf::Color(255, 255, 255, 100);
    btnSurvol->fnd_couleur      = sf::Color(255, 255, 255, 50);

    imgRepos->txt_police.loadFromFile ( "media/polices/arial.ttf" );
    imgRepos->txt_style        = sf::Text::Style::Regular;
    imgRepos->txt_taille       = 10;
    imgRepos->txt_couleur      = sf::Color(255, 255, 255, 0);
    imgRepos->lgn_epaisseur    = 1;
    imgRepos->lgn_couleur      = sf::Color(255, 255, 255, 20);
    imgRepos->fnd_couleur      = sf::Color(255, 255, 255, 255);

    fenetre->txt_police.loadFromFile ( "media/polices/arial.ttf" );
    fenetre->txt_style        = sf::Text::Style::Regular;
    fenetre->txt_taille       = 10;
    fenetre->txt_couleur      = sf::Color(255, 255, 255, 0);
    fenetre->lgn_epaisseur    = 0;
    fenetre->lgn_couleur      = sf::Color(255, 255, 255, 0);
    fenetre->fnd_couleur      = sf::Color(255, 255, 255, 0);

    desactive->txt_police.loadFromFile ( "media/polices/arial.ttf" );
    desactive->txt_style        = sf::Text::Style::Regular;
    desactive->txt_taille       = 10;
    desactive->txt_couleur      = sf::Color(255, 255, 255, 100);
    desactive->lgn_epaisseur    = 0;
    desactive->lgn_couleur      = sf::Color(255, 255, 255, 50);
    desactive->fnd_couleur      = sf::Color(255, 255, 255, 50);

}

}; // fin namespace gui

