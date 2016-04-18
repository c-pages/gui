

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

//    initGUI_tests ();

    // les tests

    initGUI_MenuPanneaux ();
    initGUI_test_Affichages();
    initGUI_test_Boutons ();
    initGUI_test_Donnees();


    initScene   ();

    // definition des positions et tailles des vues jeu et gui
    sf::Vector2f pos = sf::Vector2f( m_appli->getFenetre()->getSize() );
    m_vueJeu.setSize(pos);
    m_vueGUI.setSize(pos);
    pos *= 0.5f;
    m_vueJeu.setCenter(pos);
    m_vueGUI.setCenter(pos);


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
EcranDemo::initGUI_MenuPanneaux ()
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



    auto fct_toggleFenetreAff = [this](){
        m_fenetreAffichage->setVisible( ! m_fenetreAffichage->estVisible() ) ;
    };

    auto fct_toggleFenetreBtn = [this](){
        m_fenetreBoutons->setVisible( ! m_fenetreBoutons->estVisible() ) ;
    };

    auto fct_toggleFenetreDonnee = [this](){
        m_fenetreDonnees->setVisible( ! m_fenetreDonnees->estVisible() ) ;
    };



    menuFichier->ajouterElement   ( "Nouveau"             , fct_nouveau );
    menuFichier->ajouterElement   ( "Ouvrir"              , fct_ouvrir );
    menuFichier->ajouterElement   ( "Sauvegarder"         , fct_sauvegarder );
    menuFichier->ajouterElement   ( "Sauvegadger sous"    , fct_sauvegarderSous );
    menuFichier->ajouterEspace    ( );
    menuFichier->ajouterElement   ( "Quitter"             , fct_quitter );


    // Menu AFFICHAGE
    menusDeroulants->ajouterMenu    ("Fenêtre");
    menusDeroulants->ajouterElement ("Affichages", fct_toggleFenetreAff );
    menusDeroulants->ajouterElement ("Boutons simples", fct_toggleFenetreBtn );
    menusDeroulants->ajouterElement ("Boutons données", fct_toggleFenetreDonnee );

    // Menu AIDE
    menusDeroulants->ajouterMenu    ("Aide");
    menusDeroulants->ajouterElement ("Aide");
    menusDeroulants->ajouterElement ("A propos");

    m_tailleFenetre1 = {200,200};
    m_posFenetre1 = {150,150};


//    // les panneaux lateraux
//    auto panneauD = m_interface->creer.supportPanneaux();
//    panneauD->setCote ( gui::Cote::Droite );
//    auto panneauG = m_interface->creer.supportPanneaux();

//    // liste
//    auto listeDeroul = m_interface->creer.liste();
//    listeDeroul->ajouterElement("popo 1");
//    listeDeroul->ajouterElement("popo 2");

//    auto label = m_interface->creer.label( "bon bah on a un label.");
}






/////////////////////////////////////////////////
void
EcranDemo::initGUI_tests ()
{

    sf::Vector2i pos = { 0,0 };


    // Label
    auto label = m_interface->creer.label("là on a un label");
    label->setPosition(pos.x + 20, pos.y + 20);
    label->setTexteCouleur ( sf::Color::Yellow );
    label->setLogActif( true );



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


/////////////////////////////////////////////////
void
EcranDemo::initGUI_test_Affichages ()
{

    sf::Vector2i pos = { 0,0 };

    // la fenetre
    m_fenetreAffichage = m_interface->creer.fenetre("Les gadgets d'affichage de base.");
//    m_fenetreAffichage->setLogActif ( true , true );
    m_fenetreAffichage->setPosition ( {100,100} );


    // Label
    auto label = m_interface->creer.label("là on a un labellà on a un labellà on a un labellà on a un labellà on a un labellà on a un labellà on a un labellà on a un labellà on a un labellà on a un labellà on a un labellà on a un labellà on a un labellà on a un labellà on a un labellà on a un labellà on a un labellà on a un labellà on a un labellà on a un labellà on a un labellà on a un labellà on a un labellà on a un labellà on a un labellà on a un labellà on a un labellà on a un labellà on a un labellà on a un labellà on a un labellà on a un labellà on a un labellà on a un labellà on a un labellà on a un label");
    label->setPosition(pos.x + 20, pos.y + 20);
    label->setTexteCouleur ( sf::Color::Yellow );
//    label->setLogActif( true );
    m_fenetreAffichage->ajouter ( label );

    // simple rectangle
    auto rectangle = m_interface->creer.rectangle( 20,20);
    rectangle->setPosition(pos.x + 20, pos.y + 50);
    rectangle->setFondCouleur(sf::Color::Green);
    rectangle->setFondLigneCouleur(sf::Color::Red);
    rectangle->setFondLigneEpaisseur( 10);

    // Image
    auto image = m_interface->creer.image("media/img/senseidoigt.png");
    image->setPosition(pos.x + 20, pos.y + 90);

    // Icone
    auto icone = m_interface->creer.icone("media/img/ico_fenetre.png");
    icone->setPosition(pos.x + 100, pos.y + 40);




    m_fenetreAffichage->ajouter ( rectangle );
    m_fenetreAffichage->ajouter ( image );
    m_fenetreAffichage->ajouter ( icone );

}

/////////////////////////////////////////////////
void
EcranDemo::initGUI_test_Boutons  ()
{
    sf::Vector2i pos = { 0,0 };

    // la fenetre
    m_fenetreBoutons = m_interface->creer.fenetre("Les boutons simples.");
    m_fenetreBoutons->setPosition ( {150,150} );
    m_fenetreBoutons->setInfo ("gui::Fenetre()\ngui::Interface::creer.fenetre( string titre )");



    // Bouton simple rectangulaire
    auto btnRect = m_interface->creer.boutonRect( 50, 50 );
    btnRect->setPosition (pos.x + 20,  pos.y + 20);
    btnRect->lier (gui::Evenement::onBtnG_relacher, [](){ printf ("Clique sur bouton rectangulaire.\n");});
    btnRect->setInfo ("gui::BtnRectangle()\ngui::Interface::creer.boutonRect( float largeur, float hauteur )\ngui::Interface::creer.boutonRect( sf::Vector2i rectangle )");

    // Bouton texte
    auto btnTexte = m_interface->creer.boutonTexte( "Bouton texte" );
    btnTexte->setPosition (pos.x + 80,  pos.y + 20);
    btnTexte->lier (gui::Evenement::onBtnG_relacher, [](){ printf ("Clique sur bouton texte.\n");});
    btnTexte->setInfo ("gui::BtnTexte()\ngui::Interface::creer.boutonTexte( string texte )");

    // Bouton icone
    auto btnIcone = m_interface->creer.boutonIcone( &gui::Interface::ms_icones.get( "ico_fichiers" ) );
    btnIcone->setIndex (1);
    btnIcone->setFix   ( );
    btnIcone->setPosition (pos.x + 200,  pos.y + 20);
    btnIcone->lier (gui::Evenement::onBtnG_relacher, [](){ printf ("Clique sur bouton icone.\n");});
    btnIcone->setInfo ("gui::BtnIcone()\ngui::Interface::creer.boutonIcone( ssf::Texture texture )\ngui::Interface::creer.boutonIcone( string cheminImage )");


    m_fenetreBoutons->ajouter ( btnRect );
    m_fenetreBoutons->ajouter ( btnTexte );
    m_fenetreBoutons->ajouter ( btnIcone );

//
//    m_fenetreBoutons->ajouter ( m_fenetreAffichage );

}

/////////////////////////////////////////////////
void
EcranDemo::initGUI_test_Donnees ()
{
    sf::Vector2i pos = { 0,0 };

    // la fenetre
    m_fenetreDonnees= m_interface->creer.fenetre("Les gadgets gérant des données.");
    m_fenetreDonnees->setPosition ( {200,200} );
    m_fenetreDonnees->setInfo ("gui::Fenetre()\ngui::Interface::creer.fenetre( string titre )");


    // bouton boolean
    auto btnBool = m_interface->creer.btnACocher( "Bouton à cocher" );
    btnBool->setPosition ( pos.x + 20, pos.y + 10);
    btnBool->setInfo ("gui::BtnCoche()\ngui::Interface::creer.btnACocher( string texte, bool coche = true )");

    // liste
    auto liste = m_interface->creer.liste();
    liste->ajouterElement("Machin");
    liste->ajouterElement("Truc");
    liste->ajouterElement( "Bidule" );
    liste->setPosition ( pos.x + 20, pos.y + 67 );
    liste->setInfo ("gui::LstSimple()\ngui::Interface::creer.liste(  )");


    // liste deroulante
    auto listeDeroul = m_interface->creer.listeDeroulante();
    listeDeroul->ajouterElement("element 1");
    listeDeroul->ajouterElement("element 2");
    listeDeroul->ajouterElement("element 3");
    listeDeroul->ajouterElement("element 4");
    listeDeroul->setPosition (pos.x + 20, pos.y + 30 );
    listeDeroul->setInfo ("gui::LstDeroulante()\ngui::Interface::creer.listeDeroulante( )");

    // zone de texte
    auto zoneTexte = m_interface->creer.zoneTexte( "zone de texte" );
    zoneTexte->setPosition ( pos.x + 20, pos.y + 120 );

    // zone de nombre
    auto zoneNum = m_interface->creer.zoneNum( 1234 );
    zoneNum->setPosition ( pos.x + 20, pos.y + 150 );





    m_fenetreDonnees->ajouter ( btnBool );
    m_fenetreDonnees->ajouter ( liste );
    m_fenetreDonnees->ajouter ( listeDeroul );
    m_fenetreDonnees->ajouter ( zoneTexte );
    m_fenetreDonnees->ajouter ( zoneNum );


//    m_fenetreDonnees->ajouter ( m_fenetreBoutons );

}


}   // fin namespace app































