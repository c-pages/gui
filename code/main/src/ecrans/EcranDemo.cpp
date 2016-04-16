

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "ecrans/EcranDemo.h"
#include <iostream>
#include <Config.h>
#include <Interface.h>

#include<cstdlib>

namespace app {

/////////////////////////////////////////////////
EcranDemo::EcranDemo( Application*  appli )
: Ecran             ( appli )
, m_interface       ( nullptr )
{
    // Initialisation de l'interface graphique.
    initGUI     ();

    // les tests
    initGUI_tests ();
//    initGUI_test_Affichages ();
//    initGUI_test_Boutons    ();
//    initGUI_test_Donnees    ();
//    initGUI_test_Contenantx   ();
//    initGUI_test_Fenetres   ();

    initScene   ();

    // definition des positions et tailles des vues jeu et gui
    sf::Vector2f pos = sf::Vector2f( m_appli->getFenetre()->getSize() );
    m_vueJeu.setSize(pos);
    m_vueGUI.setSize(pos);
    pos *= 0.5f;
    m_vueJeu.setCenter(pos);
    m_vueGUI.setCenter(pos);


//    m_interface->logTitre("\n    ---->| Fin initialisation\n");
}


/////////////////////////////////////////////////
void EcranDemo::traiter_evenements  ( const sf::Event& event )
{
    // Evenements du jeu ...

    // Evenements de l'interface
    m_interface->traiterEvenements    ( event );


    // fermeture de la fenetre SFML
    if ( event.type == sf::Event::Closed )
        m_appli->getFenetre()->close();


    // Resize the window
    if (event.type ==  sf::Event::Resized)
    {
        sf::Vector2f pos = sf::Vector2f( m_appli->getFenetre()->getSize() );
        m_vueJeu.setSize(pos);
        m_vueGUI.setSize(pos);
        pos *= 0.5f;
        m_vueJeu.setCenter(pos);
        m_vueGUI.setCenter(pos);

//        m_fond.setSize      ( pos );
//        m_vueJeu.setSize    (event.size.width, event.size.height);
//        m_vueGUI.setSize    (event.size.width, event.size.height);

        m_appli->getFenetre()->setView(m_vueGUI);
        m_interface->demanderActualisation();
    }
}



/////////////////////////////////////////////////
void EcranDemo::actualiser  ( float deltaT )
{

    // actualiser la fenetre du jeu ...

    // actualiser l'interface
    m_interface->actualiser    ( );

    ///<\todo actualiser les animations de l'interface
//    m_interface->actualiser    ( sf::seconds( deltaT ) ) ;


    // les FPS
//    m_compteurFrameFPS++;
//    if ( m_chronoFPS.getElapsedTime().asSeconds() >= 1 )    {
//        m_FPS = m_compteurFrameFPS;
//        m_chronoFPS.restart();
//        m_compteurFrameFPS = 0;
//    }
//    std::string val=  "FPS : " + patch::to_string( m_FPS ) + "  - Survole : ";
//    if ( m_interface->ms_boutonSurvole != nullptr ){
//        val +=   m_interface->ms_boutonSurvole->getNom() ;
//    } else val += "nullptr";
//    m_labelRetour->setTexte ( val );



//    std::string val =  "Retour : " + m_interface->ms_boutonSurvole->getNom();
//    if ( m_interface->ms_boutonSurvole == nullptr )
//        val = "Retour : nullptr";

//

}



/////////////////////////////////////////////////
void EcranDemo::dessiner ()
{
    sf::RenderWindow* fenetre = m_appli->getFenetre();
    // Dessiner la fenetre du jeu
    fenetre->setView   ( m_vueJeu);
    fenetre->draw      ( m_fond );

    // Dessiner l'interface
    fenetre->setView   ( m_vueGUI );
    fenetre->draw      ( *m_interface );

}



/////////////////////////////////////////////////
void
EcranDemo::test () { std::cout << "CECI n'EST pas UN TEST QUI ne FONCTIONNE pas.\n";  }




/////////////////////////////////////////////////
void
EcranDemo::initScene  ( )
{
    // Initialisation du fond.
    m_fond.setPosition  ( 0,0 );
//    m_fond.setSize      ( sf::Vector2f ( m_appli->getFenetre()->getSize() ) );
    m_fond.setSize      ( sf::Vector2f ( 1920 ,1080 ) );
    m_fond.setFillColor ( sf::Color (70,70,70) );

}


/////////////////////////////////////////////////
void
EcranDemo::initGUI_tests ()
{
/*

    // AFFICHAGE
    auto label = m_interface->creer.label( "bon" );
    label->setPosition ( 50, 50 );
    label->setTexteStyle ( sf::Text::Italic );
    label->setTextePolice ( gui::Interface::ms_polices.get( "swisse" ));

    auto rectangle = m_interface->creer.rectangle( 25 , 25 );
    rectangle->setPosition ( 50, 100 );
    rectangle->setFondCouleur ( sf::Color::Yellow );
    rectangle->setFondLigneCouleur ( sf::Color::Blue );
    rectangle->setFondLigneEpaisseur ( 2 );

    auto image = m_interface->creer.image();
    image->setPosition ( 50, 150 );
    image->setImage( "media/img/ico_fichiers.png" );

    auto icone = m_interface->creer.icone("media/img/ico_fichiers.png"  );
    icone->setPosition ( 50, 200);
    icone->setIndex (2);


//     BOUTONS

    auto bouton = m_interface->creer.boutonRect( 200, 15 );
//    bouton->setLogActif ( true );
    bouton->setPosition ( 200, 50);
//    bouton->setFondCouleur ( sf::Color ( 255,0,0) );
//    bouton->setFondCouleur ( sf::Color ( 0,255,0), gui::Etat::survol );

    auto boutonTexte = m_interface->creer.boutonTexte( "Ceci est un bouton texte" );
//    boutonTexte->setLogActif ( true );
    boutonTexte->setPosition ( 200, 100);
//    boutonTexte->setTexteCouleur ( sf::Color ( 255,0,0) );
//    boutonTexte->setTexteCouleur ( sf::Color ( 0,255, 0), gui::Etat::survol );
//    boutonTexte->setTexteCouleur ( sf::Color ( 0,0,255 ), gui::Etat::press );

    auto boutonIcone = m_interface->creer.boutonIcone( "media/img/ico_fichiers.png" );
    boutonIcone->setPosition ( 200, 150);
//    boutonIcone->setLogActif ( true );
    boutonIcone->setFix ( true );
    boutonIcone->setIndex ( 3 );



    // DONNEES

    auto slide = m_interface->creer.slider( );
    slide->setPosition  ( 200, 200);
//    slide->setLogActif  ( true );
//    slide->setLargeur   ( 60 );
    slide->setMarge     ( 3 , 3 );

    auto boutonCoche = m_interface->creer.btnACocher( );
//    boutonCoche->setLogActif  ( true  );
    boutonCoche->setPosition  ( 200, 250);
//    boutonCoche->setValeur    ( true );
    boutonCoche->setTexte     ( "Bouton booleen" );

    auto zoneTexte = m_interface->creer.zoneTexte( "Zone de texte" );
    zoneTexte->setLogActif  ( true  );
    zoneTexte->setPosition  ( 200, 300 );

    auto zoneNum = m_interface->creer.zoneNum(  );
//    zoneNum->setLogActif  ( true , true );
    zoneNum->setPosition  ( 200, 350 );
*/

    ////////////////////////////////////////////////////////////////////////
    ////// les menus deroulants  ///////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
    auto menusDeroulants = m_interface->creer.menusDeroulants( );

    // menu FICHIER
    auto menuFichier = menusDeroulants->ajouterMenu("Fichier");

    auto fct_nouveau = [this](){
        std::cout << "nouveau\n";
    };
    auto fct_ouvrir = [this](){
        std::cout << "Ouvrir\n";
    };
    auto fct_sauvegarder = [this](){
        std::cout << "Sauvegarder\n";
    };
    auto fct_sauvegarderSous = [this](){
        std::cout << "Sauvegarder sous\n";
    };
    auto fct_quitter = [this](){
        std::cout << "Quitter\n";

        auto fenetreQuitter = m_interface->creer.fenetre("Quitter ?");
        fenetreQuitter->setTitreIcone ( &gui::Interface::ms_icones.get("ico_fenetreDefaut"));
        fenetreQuitter->setPosition ( 350, 250  );
        fenetreQuitter->setTaille( 225 , 75);

        auto label =  m_interface->creer.label("Etes-vous sûr de vouloir quitter ?");
        label->setPosition ( 5,2 );
        label->setTexteTaille(11);

        auto boutonOui = m_interface->creer.boutonTexte("Oui");
        boutonOui->setPosition ( 20,20 );
        boutonOui->lier (gui::Evenement::onBtnG_relacher, [this, fenetreQuitter ](){ m_appli->getFenetre()->close(); fenetreQuitter->fermer();});

        auto boutonNon = m_interface->creer.boutonTexte("Non");
        boutonNon->setPosition ( 150,20 );
        boutonNon->lier (gui::Evenement::onBtnG_relacher, [this, fenetreQuitter ](){ fenetreQuitter->fermer();});

        fenetreQuitter->ajouter (label);
        fenetreQuitter->ajouter (boutonOui);
        fenetreQuitter->ajouter (boutonNon);

    };

    auto fct_toggleFenetre1 = [this](){

        printf ("fct_ouvrirFenetre1\n");

        if ( m_fenetre1 == nullptr ) {

            m_fenetre1 = m_interface->creer.fenetre("Fenetre Démo");
            m_fenetre1->setTitreIcone ( &gui::Interface::ms_icones.get("ico_fenetreDefaut"));
            m_fenetre1->setPosition ( m_posFenetre1.x, m_posFenetre1.y  );
            m_fenetre1->setTaille( 512 , 512 );
            m_fenetre1->setTaille( m_tailleFenetre1 );
            m_fenetre1->lier ( gui::Evenement::onFen_fermer,[this](){ m_fenetre1=nullptr; });
            m_fenetre1->lier ( gui::Evenement::onFen_bouge, [this](){ m_posFenetre1 = m_fenetre1->getPosition(); });
            m_fenetre1->lier ( gui::Evenement::onFen_redim, [this](){ m_posFenetre1 = m_fenetre1->getPosition(); m_tailleFenetre1 = m_fenetre1->getTaille(); });

            auto bouton = m_interface->creer.boutonTexte("BOUTON TEST");
            bouton->setPosition ( 0,0 );
            bouton->lier (gui::Evenement::onBtnG_relacher, [this](){ printf("popo\n");});


            m_fenetre1->ajouter ( bouton );

        } else m_fenetre1->fermer();

    };




    menuFichier->ajouterElement   ( "Nouveau"             , fct_nouveau );
    menuFichier->ajouterElement   ( "Ouvrir"              , fct_ouvrir );
    menuFichier->ajouterElement   ( "Sauvegarder"         , fct_sauvegarder );
    menuFichier->ajouterElement   ( "Sauvegadger sous"    , fct_sauvegarderSous );
    menuFichier->ajouterEspace    ( );
    menuFichier->ajouterElement   ( "Quitter"             , fct_quitter );


    // Menu AFFICHAGE
    menusDeroulants->ajouterMenu    ("Affichage");
    menusDeroulants->ajouterElement ("Fenetre 1", fct_toggleFenetre1 );

    // Menu AIDE
    menusDeroulants->ajouterMenu    ("Aide");
    menusDeroulants->ajouterElement ("Aide");
    menusDeroulants->ajouterElement ("A propos");

    m_tailleFenetre1 = {200,200};
    m_posFenetre1 = {150,150};
    fct_toggleFenetre1();


    auto boutonpopo = m_interface->creer.boutonTexte("BOUTON TEST");
    boutonpopo->setPosition ( 50,50);

boutonpopo->lier (gui::Evenement::onBtnG_relacher, [this](){ printf("popo\n");});
/*
    ////////////////////////////////////////////////////////////////////////
    ////// les fenetres  ///////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
    m_fenetre1 = m_interface->creer.fenetre("Fenetre Démo");
    m_fenetre1->setTitreIcone ( &gui::Interface::ms_icones.get("ico_fenetreDefaut"));
//    fenetre->setPosition ( 300,300);
//    fenetre->setLogActif (true);

//    std::shared_ptr<gui::AffRectangle> rect = m_interface->creer.rectangle(300 , 300);
//    rect->setFondCouleur( sf::Color::Yellow );
//    fenetre->ajouter ( rect );


    std::shared_ptr<gui::AffLabel> labelTmp = m_interface->creer.label("Ceci est un label Ceci est un label Ceci est un label Ceci est un label Ceci est un label Ceci est un label Ceci est un label Ceci est un label Ceci est un label ");
    labelTmp->setTexteCouleur( sf::Color::Black );
    m_fenetre1->ajouter ( labelTmp );
    m_fenetre1->setTaille( 512 , 512);


    auto bouton = m_interface->creer.boutonTexte("BOUTON TEST");
    bouton->setPosition ( 50,50);
    m_fenetre1->ajouter ( bouton );

*/

}

/////////////////////////////////////////////////
void
EcranDemo::initGUI ()
{

    using namespace gui;

    // Creation de l'interface qui gère un ensemble de gadget.
    m_interface = std::make_shared<Interface>( m_appli->getFenetre() );
    m_interface->setAfficherFPS ( true );

    ///// Interactions clavier ///////
    m_interface->lier ( sf::Keyboard::Escape , [this]() {
            system("cls");
            m_interface->resetLog ();
        } );

}




}   // fin namespace app































