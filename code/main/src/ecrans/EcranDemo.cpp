

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "ecrans/EcranDemo.h"
#include <iostream>
#include <Config.h>
#include <gui.h>

#include <cstdlib>

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

        //////////////////////////////////////////////////////////////////////
        ////    Fenetre de confirmation de fermeture
        //////////////////////////////////////////////////////////////////////

        // le bouton au fond qui occulte le reste de l'interface
        m_cache = m_interface->creer.boutonRect( m_appli->getFenetre()->getSize().x, m_appli->getFenetre()->getSize().y );
        gui::Interface::ms_calque_fenetres->ajouter (m_cache);
        m_cache->setFondCouleur (sf::Color(0,0,0,100));

        // la fenetre
        auto fenetreQuitter = m_interface->creer.fenetre("Quitter ?");
        fenetreQuitter->setTitreIcone ( &gui::Interface::ms_icones.get("ico_fenetreDefaut"));
        fenetreQuitter->alignerSur ( m_interface, gui::Alignement::Centre, gui::Alignement::Centre );
        fenetreQuitter->lier (gui::Evenement::onFen_fermer, [this](){ m_cache->demander_aEtre_supprimer(); });
        fenetreQuitter->setTaille( 275 , 95 );

        // le label
        auto label =  m_interface->creer.label("Etes-vous sûr de vouloir quitter ?");
        label->setPosition ( 5,2 );
        label->setTexteTaille(11);

        // boutons
        auto boutonOui = m_interface->creer.boutonTexte("Oui");
        boutonOui->setPosition ( 00,00 );
        boutonOui->lier (gui::Evenement::onBtnG_relacher, [this](){ m_appli->getFenetre()->close(); });
        auto boutonNon = m_interface->creer.boutonTexte("Non");
        boutonNon->setPosition ( 120,00 );
        boutonNon->lier (gui::Evenement::onBtnG_relacher, [this, fenetreQuitter ](){ fenetreQuitter->fermer(); });

        // le groupe des boutons pour les aligner
        std::shared_ptr<gui::Groupe> grpTmp = std::make_shared<gui::Groupe>();
        grpTmp->ajouter ( boutonOui );
        grpTmp->ajouter ( boutonNon );

        // on ajoute tout ça à la fenetre
        fenetreQuitter->ajouter (label);
        fenetreQuitter->ajouter (grpTmp);

        // et on place tout bien à l'interieur de la fenetre
        label->alignerSur  ( fenetreQuitter, gui::Alignement::Centre, gui::Alignement::Centre );
        label->move(0,-5);
        grpTmp->alignerSur ( fenetreQuitter, gui::Alignement::Centre, gui::Alignement::Centre );
        grpTmp->move(0,20);

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

            auto bouton = m_interface->creer.boutonTexte( "BOUTON TEST" );
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
    menusDeroulants->ajouterElement ("Fenetre Démo", fct_toggleFenetre1 );

    // Menu AIDE
    menusDeroulants->ajouterMenu    ("Aide");
    menusDeroulants->ajouterElement ("Aide");
    menusDeroulants->ajouterElement ("A propos");

    m_tailleFenetre1 = {200,200};
    m_posFenetre1 = {150,150};
    fct_toggleFenetre1();


    auto panneauD = m_interface->creer.supportPanneaux();
    panneauD->setCote ( gui::Cote::Droite );

    auto panneauG = m_interface->creer.supportPanneaux();




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































