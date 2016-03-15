

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

/*
    // les FPS
    m_compteurFrameFPS++;
    if ( m_chronoFPS.getElapsedTime().asSeconds() >= 1 )    {
        m_FPS = m_compteurFrameFPS;
        m_chronoFPS.restart();
        m_compteurFrameFPS = 0;
    }
    std::string val=  "FPS : " + patch::to_string( m_FPS ) + "  - Survole : ";
    if ( m_interface->m_boutonSurvole != nullptr ){
        val +=   m_interface->m_boutonSurvole->getNom() ;
    } else val += "nullptr";
    m_labelRetour->setTexte ( val );
*/


//    std::string val =  "Retour : " + m_interface->m_boutonSurvole->getNom();
//    if ( m_interface->m_boutonSurvole == nullptr )
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

//    auto label = m_interface->creer.label( "bon alors ca marche ti?!?" );
//    label->setPosition ( 50, 50 );
//    label->setStyle ( sf::Text::Italic );
//    label->setPolice ( gui::Interface::ms_polices.get( "swisse" ));
//
////
//    auto rectangle = m_interface->creer.rectangle( 400 , 12 );
//    rectangle->setPosition ( 50, 100 );
//    rectangle->setFillColor ( sf::Color::Yellow );
//    rectangle->setOutlineColor ( sf::Color::Blue );
//    rectangle->setOutlineThickness ( 12 );
//
//    std::shared_ptr<gui::AffImage> image = m_interface->creer.image();
//    image->setPosition ( 50, 150 );
//    image->setImage( "media/img/ico_fichiers.png" );

    auto icone = m_interface->creer.icone("media/img/ico_fichiers.png"  );
    icone->setPosition ( 50, 50);
    icone->setIndex (2);

//    auto bouton = m_interface->creer.boutonRect( 200, 15 );
//    bouton->setPosition ( 50, 50);


    /*
    auto liste = m_interface->creer.liste();
    liste->setPosition ( 50, 50);
    liste->ajouterElement ( "Premier" );
    liste->ajouterElement ( "Second" );
    liste->ajouterElement ( "Troisieme" );
    liste->ajouterElement ( "Quatrieme" );
    liste->ajouterElement ( "Cinquieme" );
    liste->ajouterElement ( "Sixieme" );
    liste->ajouterElement ( "Septieme" );
    liste->ajouterElement ( "Huitieme" );
    liste->ajouterElement ( "Neuvieme" );
    liste->ajouterElement ( "Dixieme" );
    liste->setAjustement(true);

    auto listeDeroulante = m_interface->creer.listeDeroulante();
    listeDeroulante->setPosition ( 250, 50);
    listeDeroulante->ajouterElement ( "Premier" );
    listeDeroulante->ajouterElement ( "Second" );
    listeDeroulante->ajouterElement ( "Troisieme" );
    listeDeroulante->ajouterElement ( "Quatrieme" );
    listeDeroulante->ajouterElement ( "Cinquieme" );
    listeDeroulante->ajouterElement ( "Sixieme" );
    listeDeroulante->ajouterElement ( "Septieme" );
    listeDeroulante->ajouterElement ( "Huitieme" );
    listeDeroulante->ajouterElement ( "Neuvieme" );
    listeDeroulante->ajouterElement ( "Dixieme" );
*/
}

/////////////////////////////////////////////////
void
EcranDemo::initGUI ()
{

    using namespace gui;

    // Creation de l'interface qui gère un ensemble de gadget.
    m_interface = std::make_shared<Interface>( m_appli->getFenetre() );

//    m_interface->logTitre("\n    Debut initialisation |--->\n");


//    m_skin      = std::make_shared<Skin>();


    ///// Interactions clavier ///////
    m_interface->lier ( sf::Keyboard::Escape , [this]() {
            system("cls");
        } );

//    m_interface->logTitre("--- fin init -------------------------");

    /////// Label retour ///////
//    m_labelRetour = m_interface->creer.label( "Retour :" );
//    m_labelRetour->setPosition    ( 5 , 5 );
//    m_labelRetour->setStyle       ( m_skin->getStyle (  gui::Styles::txtLog ) );

/*

    /////// Bandeau ///////
//    auto bandeau = m_interface->creer.bandeau( );
    auto menusDeroulants = m_interface->creer.menusDeroulants( );
    menusDeroulants->ajouterMenu ( "Fichier" );
    menusDeroulants->ajouterElement ("Nouveau", [this](){std::cout << "Nouveau fichier...\n";});
    menusDeroulants->ajouterElement ("Ouvrir", [this](){std::cout << "Ouvrir fichier...\n";});
    menusDeroulants->ajouterElement ("Enregistrer", [this](){std::cout << "Enregistrer fichier...\n";});
    menusDeroulants->ajouterElement ("Enregistrer sous", [this](){std::cout << "Enregistrer fichier sous...\n";});

    menusDeroulants->ajouterMenu ( "Edition" );
    menusDeroulants->ajouterElement ( "Annuler", [this](){std::cout << "Annuler...\n";});
    menusDeroulants->ajouterElement ( "Rétablir", [this](){std::cout << "Rétablir...\n";});
    menusDeroulants->ajouterElement ( "" );
    menusDeroulants->ajouterElement ( "Copier", [this](){std::cout << "Copier...\n";});
    menusDeroulants->ajouterElement ( "Couper", [this](){std::cout << "Couper...\n";});
    menusDeroulants->ajouterElement ( "Coller", [this](){std::cout << "Coller...\n";});

    menusDeroulants->ajouterMenu ( "Aide" );
    menusDeroulants->ajouterElement ("A propos", [this](){std::cout << "A propos...\n";

            //// creation d'une fenetre
            auto m_fenetre3 = m_interface->creer.fenetre(  );
            m_fenetre3->setPosition  ( 400 , 400 );
            m_fenetre3->setTaille    ( { 300 , 100 });
            m_fenetre3->setTexte ( "A propos");
            //// contenu de la fenetre
            auto m_texteCPourFenetre = m_interface->creer.label( "A propos ");
            auto m_texteDPourFenetre = m_interface->creer.label( "blablabla\nblablablablabla\nblablablablablablabla\nblabla");
                                                                //Nihil est enim virtute amabilius, nihil quod magis adliciat ad diligendum, quippe\n cum propter virtutem et probitatem \netiam eos, quos numquam vidimus, quodam modo \ndiligamus. Quis est qui C. Fabrici, M'. Curi non cum caritate\n aliqua benevola memoriam usurpet, quos\n numquam viderit? quis autem est, qui \nTarquinium Superbum, qui Sp. Cassium, Sp. Maelium non \noderit? Cum duobus ducibus de imperio in Italia \nest decertatum, Pyrrho et Hannibale; ab altero propter \nprobitatem eius non nimis alienos animos habemus, alterum propter crudelitatem \nsemper haec civitas oderit." );
        //    m_texteCPourFenetre->setStyle       ( m_skin->getStyle ( gui::Styles::txtCourant ) );
            m_texteCPourFenetre->setPosition ( 5,5);
            m_texteCPourFenetre->setTailleCharac ( 20 );
            m_fenetre3->ajouter ( m_texteCPourFenetre );

            m_texteDPourFenetre->setPosition ( 5,30 );
            m_texteDPourFenetre->setTailleCharac ( 12 );
            m_fenetre3->ajouter ( m_texteDPourFenetre );

        });
    menusDeroulants->ajouterElement ("Version", [this](){std::cout << "Version...\n";});





    auto bandeau2 = m_interface->creer.bandeau( );

    auto barreOutil = m_interface->creer.barreFonctions( );
    bandeau2->ajouter( barreOutil );

    barreOutil->ajouterElement ("Nouveau", "media/img/ico_fichiers.png" , [this](){std::cout << "Execute la fonction de creation d'un nouveau fichier.\n";} );
    barreOutil->ajouterElement ("Ouvrir", "media/img/ico_fichiers.png" , [this](){std::cout << "Execute la fonction d'ouverture de fichier.\n";} );
    barreOutil->ajouterElement ("Sauvegarder", "media/img/ico_fichiers.png" , [this](){std::cout << "Execute la fonction de sauvegarde du fichier.\n";} );
    barreOutil->ajouterElement ("Sauvegarder sous", "media/img/ico_fichiers.png" , [this](){std::cout << "Execute la fonction de sauvegarde sous du fichier.\n";} );

    auto bandeau3 = m_interface->creer.bandeau( );
    auto barreOutil2 = m_interface->creer.barreFonctions( );
    bandeau3->ajouter( barreOutil2 );

    barreOutil2->ajouterElement ("Lecture", "media/img/ico_lecteur.png" , [this](){std::cout << "Execute la fonction Lecture\n";} );
    barreOutil2->ajouterElement ("Pause", "media/img/ico_lecteur.png" , [this](){std::cout << "Execute la fonction Pause\n";} );
    barreOutil2->ajouterElement ("Arret", "media/img/ico_lecteur.png" , [this](){std::cout << "Execute la fonction Arret\n";} );
    barreOutil2->ajouterElement ("Enregistrer", "media/img/ico_lecteur.png" , [this](){std::cout << "Execute la fonction Enregistrer\n";} );



    auto panneau_G = m_interface->creer.supportPanneaux();
    panneau_G->setCote ( gui::Cote::Droite );

//    auto panneau_G2 = m_interface->creer.supportPanneaux();
//    panneau_G->setCote ( gui::Cote::Droite );

    auto fenetrePanneauD_1 = m_interface->creer.fenetre("Test 1");
    fenetrePanneauD_1->setTaille( {500,500});
    panneau_G->ajouter ( fenetrePanneauD_1 );

    auto m_textePourFenetrePanneauD_1 = m_interface->creer.label( "Nihil est enim virtute amabilius, nihil quod magis adliciat ad diligendum, quippe\n cum propter virtutem et probitatem \netiam eos, quos numquam vidimus, quodam modo \ndiligamus. Quis est qui C. Fabrici, M'. Curi non cum caritate\n aliqua benevola memoriam usurpet, quos\n numquam viderit? quis autem est, qui \nTarquinium Superbum, qui Sp. Cassium, Sp. Maelium non \noderit? Cum duobus ducibus de imperio in Italia \nest decertatum, Pyrrho et Hannibale; ab altero propter \nprobitatem eius non nimis alienos animos habemus, alterum propter crudelitatem \nsemper haec civitas oderit." );
    fenetrePanneauD_1->ajouter ( m_textePourFenetrePanneauD_1 );



    auto panneau_D = m_interface->creer.supportPanneaux();

    auto fenetrePanneau_1 = m_interface->creer.fenetre("Test 1");
    panneau_D->ajouter ( fenetrePanneau_1 );
//    fenetrePanneau_1->reduire();

    auto fenetrePanneau_2 = m_interface->creer.fenetre("Test 2");
    panneau_D->ajouter ( fenetrePanneau_2 );
//    fenetrePanneau_2->reduire();

    auto fenetrePanneau_3 = m_interface->creer.fenetre("Test 3");
    panneau_D->ajouter ( fenetrePanneau_3 );
//    fenetrePanneau_3->reduire();
*/
}


/////////////////////////////////////////////////
void
EcranDemo::initGUI_test_Fenetres  ()
{
    sf::Vector2f posRoot = { 420 , 390 };

    std::cout << "\n---------------------------------------\n";
    std::cout << "      Test des gadgets : Fenetres";
    std::cout << "\n---------------------------------------\n\n";


    /////// TITRE Label ///////
    m_labelTitre_4 = m_interface->creer.label( "Fenetres" );
    m_labelTitre_4->setPosition    ( posRoot.x , posRoot.y - 40 );
    m_labelTitre_4->setTailleCharac (20);
//    m_labelTitre_4->setStyle       ( m_skin->getStyle ( gui::Styles::txtTitre ) );


    //// creation d'une fenetre
    auto m_fenetre = m_interface->creer.fenetre(  );
    m_fenetre->setPosition  ( posRoot.x , posRoot.y  );
    m_fenetre->setTaille    ( { 300 , 100 } );
    m_fenetre->chargerIcone   ( "media/img/Icone_test x16.png" );

//    m_fenetre->setStyle     ( m_skin->getStyle ( gui::Styles::txtTitre ) );

    //// contenu de la fenetre
//    auto m_textePourFenetre = m_interface->creer.label( "Nihil est enim virtute amabilius, nihil quod magis adliciat ad diligendum, quippe\n cum propter virtutem et probitatem \netiam eos, quos numquam vidimus, quodam modo \ndiligamus. Quis est qui C. Fabrici, M'. Curi non cum caritate\n aliqua benevola memoriam usurpet, quos\n numquam viderit? quis autem est, qui \nTarquinium Superbum, qui Sp. Cassium, Sp. Maelium non \noderit? Cum duobus ducibus de imperio in Italia \nest decertatum, Pyrrho et Hannibale; ab altero propter \nprobitatem eius non nimis alienos animos habemus, alterum propter crudelitatem \nsemper haec civitas oderit." );
//    m_textePourFenetre->setStyle       ( m_skin->getStyle ( gui::Styles::txtCourant ) );
//
//    m_fenetre->ajouter ( m_textePourFenetre );


    auto  m_boutonPourContenant_2 = m_interface->creer.boutonTexte( "Bouton" );
//    m_boutonPourContenant_2->setStyle       ( m_skin->getStyle ( gui::Styles::bouton ) );
    m_boutonPourContenant_2->setPosition (115,20);
    m_fenetre->ajouter ( m_boutonPourContenant_2 );
    m_boutonPourContenant_2->lier(gui::Evenement::onBtnG_relacher, [this](){
                               std::cout << "Bouton\n";
                               });
/*
    auto  m_bouton2PourContenant_2 = m_interface->creer.boutonTexte( "Bouton\nBouton\nBouton\nBouton\nBouton\nBouton\nBouton" );
    m_bouton2PourContenant_2->setStyle       ( m_skin->getStyle ( gui::Styles::bouton ) );
    m_bouton2PourContenant_2->setPosition (50,50);
    m_fenetre->ajouter ( m_bouton2PourContenant_2 );
//
    auto  m_bouton3PourContenant_2 = m_interface->creer.boutonTexte( "BoutonBoutonBoutonBoutonBoutonBouton" );
    m_bouton3PourContenant_2->setStyle       ( m_skin->getStyle ( gui::Styles::bouton ) );
    m_bouton3PourContenant_2->setPosition (120,146);
    m_fenetre->ajouter ( m_bouton3PourContenant_2 );
*/


    //// creation d'une fenetre
    auto m_fenetre2 = m_interface->creer.fenetre(  );
    m_fenetre2->setPosition  ( m_fenetre->getPosition().x + 40 , m_fenetre->getPosition().y + 40 );
    m_fenetre2->setTaille    ( { 300 , 100 });
//    m_fenetre2->setStyle     ( m_skin->getStyle ( gui::Styles::txtTitre ) );
//    m_panneau->setTaille    ( { 200 , 100 } );

    //// contenu de la fenetre
    auto m_texteCPourFenetre = m_interface->creer.label( "Nihil est enim virtute amabilius, nihil quod magis adliciat ad diligendum, quippe\n cum propter virtutem et probitatem \netiam eos, quos numquam vidimus, quodam modo \ndiligamus. Quis est qui C. Fabrici, M'. Curi non cum caritate\n aliqua benevola memoriam usurpet, quos\n numquam viderit? quis autem est, qui \nTarquinium Superbum, qui Sp. Cassium, Sp. Maelium non \noderit? Cum duobus ducibus de imperio in Italia \nest decertatum, Pyrrho et Hannibale; ab altero propter \nprobitatem eius non nimis alienos animos habemus, alterum propter crudelitatem \nsemper haec civitas oderit." );
//    m_texteCPourFenetre->setStyle       ( m_skin->getStyle ( gui::Styles::txtCourant ) );
    m_texteCPourFenetre->setPosition ( 5,5);
    m_fenetre2->ajouter ( m_texteCPourFenetre );
}

/////////////////////////////////////////////////
void
EcranDemo::initGUI_test_Contenantx  ()
{

    sf::Vector2f posRoot = { 20 , 390 };

    std::cout << "\n---------------------------------------\n";
    std::cout << "      Test des gadgets : Contenants";
    std::cout << "\n---------------------------------------\n\n";


    /////// TITRE Label ///////
    m_labelTitre_3 = m_interface->creer.label( "Contenants" );
    m_labelTitre_3->setPosition    ( posRoot.x , posRoot.y - 40 );
    m_labelTitre_3->setTailleCharac (20);
//    m_labelTitre_3->setStyle       ( m_skin->getStyle ( gui::Styles::txtTitre ) );

    //// creation d'un panneau
    auto m_panneau = m_interface->creer.contenant(  );
    m_panneau->setPosition  ( posRoot.x , posRoot.y  );
//    m_panneau->setStyle     ( m_skin->getStyle ( gui::Styles::txtTitre ) );
//    m_panneau->setTaille    ( { 600 , 100 } ); // ok
//    m_panneau->setTaille    ( { 300 , 200 } ); // ok
    m_panneau->setTaille    ( { 200 , 100 } );

    //// contenu du panneau
    m_textePourContenant = m_interface->creer.label( "Nihil est enim virtute amabilius, nihil quod magis adliciat ad diligendum, quippe\n cum propter virtutem et probitatem \netiam eos, quos numquam vidimus, quodam modo \ndiligamus. Quis est qui C. Fabrici, M'. Curi non cum caritate\n aliqua benevola memoriam usurpet, quos\n numquam viderit? quis autem est, qui \nTarquinium Superbum, qui Sp. Cassium, Sp. Maelium non \noderit? Cum duobus ducibus de imperio in Italia \nest decertatum, Pyrrho et Hannibale; ab altero propter \nprobitatem eius non nimis alienos animos habemus, alterum propter crudelitatem \nsemper haec civitas oderit." );
//    m_textePourContenant->setStyle       ( m_skin->getStyle ( gui::Styles::txtCourant ) );

    m_panneau->ajouter ( m_textePourContenant );

    /////// autre Label ///////
    m_label_13 = m_interface->creer.label( "<---  Contenant simple" );
    m_label_13->setPosition    ( 220 + posRoot.x , posRoot.y  +  35 );
//    m_label_13->setStyle       ( m_skin->getStyle (  gui::Styles::txtLog ) );






    //// creation d'un autre panneau
    auto m_panneau_2 = m_interface->creer.groupeSliders(  );
    m_panneau_2->setPosition  ( posRoot.x , posRoot.y + 120 );
//    m_panneau_2->setPosition  ( 0 , 0 );
//    m_panneau_2->setStyle     ( m_skin->getStyle ( gui::Styles::txtTitre ) );
//    m_panneau->setTaille    ( { 600 , 100 } ); // ok
//    m_panneau->setTaille    ( { 300 , 200 } ); // ok
    m_panneau_2->setTaille    ( { 200 , 100 } );

    //// contenu du panneau
    auto m_texteBPourContenant = m_interface->creer.label( "Nihil est enim virtute amabilius, nihil quod magis adliciat ad diligendum, quippe\n cum propter virtutem et probitatem \netiam eos, quos numquam vidimus, quodam modo \ndiligamus. Quis est qui C. Fabrici, M'. Curi non cum caritate\n aliqua benevola memoriam usurpet, quos\n numquam viderit? quis autem est, qui \nTarquinium Superbum, qui Sp. Cassium, Sp. Maelium non \noderit? Cum duobus ducibus de imperio in Italia \nest decertatum, Pyrrho et Hannibale; ab altero propter \nprobitatem eius non nimis alienos animos habemus, alterum propter crudelitatem \nsemper haec civitas oderit." );
//    m_texteBPourContenant->setStyle       ( m_skin->getStyle ( gui::Styles::txtCourant ) );
    m_panneau_2->ajouter ( m_texteBPourContenant );

    //// contenu du panneau
//
//    auto  m_boutonPourContenant_2 = m_interface->creer.boutonTexte( "BoutonBoutonBoutonBoutonBoutonBouton" );
//    m_boutonPourContenant_2->setStyle       ( m_skin->getStyle ( gui::Styles::bouton ) );
//    m_boutonPourContenant_2->setPosition (50,20);
//    m_panneau_2->ajouter ( m_boutonPourContenant_2 );
////
//    auto  m_bouton2PourContenant_2 = m_interface->creer.boutonTexte( "Bouton\nBouton\nBouton\nBouton\nBouton\nBouton\nBouton" );
//    m_bouton2PourContenant_2->setStyle       ( m_skin->getStyle ( gui::Styles::bouton ) );
//    m_bouton2PourContenant_2->setPosition (50,50);
//    m_panneau_2->ajouter ( m_bouton2PourContenant_2 );
////
//    auto  m_bouton3PourContenant_2 = m_interface->creer.boutonTexte( "BoutonBoutonBoutonBoutonBoutonBouton" );
//    m_bouton3PourContenant_2->setStyle       ( m_skin->getStyle ( gui::Styles::bouton ) );
//    m_bouton3PourContenant_2->setPosition (120,146);
//    m_panneau_2->ajouter ( m_bouton3PourContenant_2 );

/*

//    auto  m_textePourContenant_2 = m_interface->creer.label( "Nihil est enim virtute amabilius, nihil quod magis adliciat ad diligendum, quippe\n cum propter virtutem et probitatem \netiam eos, quos numquam vidimus, quodam modo \ndiligamus. Quis est qui C. Fabrici, M'. Curi non cum caritate\n aliqua benevola memoriam usurpet, quos\n numquam viderit? quis autem est, qui \nTarquinium Superbum, qui Sp. Cassium, Sp. Maelium non \noderit? Cum duobus ducibus de imperio in Italia \nest decertatum, Pyrrho et Hannibale; ab altero propter \nprobitatem eius non nimis alienos animos habemus, alterum propter crudelitatem \nsemper haec civitas oderit." );
//    m_textePourContenant_2->setStyle       ( m_skin->getStyle ( gui::Styles::txtCourant ) );
//    m_panneau_2->ajouter ( m_textePourContenant_2 );


    auto  m_boutonPourContenant_2 = m_interface->creer.boutonTexte( "BoutonBoutonBoutonBoutonBoutonBouton" );
    m_boutonPourContenant_2->setStyle       ( m_skin->getStyle ( gui::Styles::bouton ) );
    m_boutonPourContenant_2->setPosition (50,20);
    m_panneau_2->ajouter ( m_boutonPourContenant_2 );
//
    auto  m_bouton2PourContenant_2 = m_interface->creer.boutonTexte( "BoutonBoutonBoutonBoutonBoutonBouton" );
    m_bouton2PourContenant_2->setStyle       ( m_skin->getStyle ( gui::Styles::bouton ) );
    m_bouton2PourContenant_2->setPosition (50,50);
    m_panneau_2->ajouter ( m_bouton2PourContenant_2 );
//
    auto  m_bouton3PourContenant_2 = m_interface->creer.boutonTexte( "BoutonBoutonBoutonBoutonBoutonBouton" );
    m_bouton3PourContenant_2->setStyle       ( m_skin->getStyle ( gui::Styles::bouton ) );
    m_bouton3PourContenant_2->setPosition (50,180);
    m_panneau_2->ajouter ( m_bouton3PourContenant_2 );
*/


    /////// autre Label ///////
    m_label_13 = m_interface->creer.label( "<---  ContenantSliders \n(avec barres de défilemement)" );
    m_label_13->setPosition    ( 220 + posRoot.x , posRoot.y  +  155 );
//    m_label_13->setStyle       ( m_skin->getStyle (  gui::Styles::txtLog ) );
}




/////////////////////////////////////////////////
void
EcranDemo::initGUI_test_Donnees  ()
{

    sf::Vector2f posRoot = { 820 , 150 };

    std::cout << "\n---------------------------------------\n";
    std::cout << "      Test des gadgets : DONNEES";
    std::cout << "\n---------------------------------------\n\n";


    /////// TITRE Label ///////
    m_labelTitre_0 = m_interface->creer.label( "Données" );
    m_labelTitre_0->setPosition    ( posRoot.x , posRoot.y - 40 );
    m_labelTitre_0->setTailleCharac (20);
//    m_labelTitre_0->setStyle       ( m_skin->getStyle ( gui::Styles::txtTitre ) );



    /////// Bouton à cocher ///////
    m_boutonCoche = m_interface->creer.btnACocher( );
    m_boutonCoche->setPosition    ( posRoot.x , posRoot.y  +  0 );
//    m_boutonCoche->setStyle       ( m_skin->getStyle ( gui::Styles::txtLog ) );
    m_boutonCoche->setTexte       ( "'Machiner'" );
    m_boutonCoche->setValeur      ( true );

    m_boutonCoche->lier ( gui::Evenement::on_valeurChange , [this](){
                        std::cout << "ACTION Bool : changer Valeur\n";
                        if (  m_boutonTexte->estActif() ){
                            delierMachiner ();
                            m_boutonTexte->setActif( false );
                        } else {
                            lierMachiner ();
                            m_boutonTexte->setActif( true );
                        } });
    m_boutonCoche->lier ( gui::Evenement::onBool_allume , [this](){
                        std::cout << "ACTION Bool : allume\n";
                        });
    m_boutonCoche->lier ( gui::Evenement::onBool_eteind , [this](){
                        std::cout << "ACTION Bool : eteind\n";
                        });

    /////// autre Label ///////
    m_label_7 = m_interface->creer.label( "<---  Bouton Booleén, interrupteur ... ('Tab')" );
    m_label_7->setPosition    ( 190 + posRoot.x , posRoot.y  +  2 );
//    m_label_7->setStyle       ( m_skin->getStyle (  gui::Styles::txtLog ) );



    /////// Zone de texte ///////
    m_zoneTexte = m_interface->creer.zoneTexte( "Zone de texte" );
    m_zoneTexte->setPosition    ( posRoot.x , posRoot.y  +  28 );
//    m_zoneTexte->setStyle       ( m_skin->getStyle (  gui::Styles::txtLog ) );


    /////// autre Label ///////
    m_label_8 = m_interface->creer.label( "<---  Zone de texte (simple pour l'instant)." );
    m_label_8->setPosition    ( 190 + posRoot.x , posRoot.y  +  30 );
//    m_label_8->setStyle       ( m_skin->getStyle (  gui::Styles::txtLog ) );




    ///////slider ///////
    m_slider = m_interface->creer.slider( );
    m_slider->setPosition    ( posRoot.x , posRoot.y  +  68 );
//    m_slider->setStyle       ( m_skin->getStyle (  gui::Styles::bouton ) );
//    m_slider->setLongCurseur ( 50 );

    //m_slider->setVertical();

    m_slider->lier ( gui::Evenement::on_valeurChange , [this](){
        std::cout << "ACTION - Valeur : " << m_slider->getValeur() << "\n";
    });


    /////// autre Label ///////
    m_label_9 = m_interface->creer.label( "<---  Slider pour controler valeur de 0.0 à 1.0" );
    m_label_9->setPosition    ( 190 + posRoot.x , posRoot.y  +  70 );
//    m_label_9->setStyle       ( m_skin->getStyle (  gui::Styles::txtLog ) );

    auto zoneNum = m_interface->creer.zoneNum ( );
    zoneNum->setPosition    ( posRoot.x , posRoot.y  +  108 );
    zoneNum->setPas ( .1);
}
/////////////////////////////////////////////////
void
EcranDemo::initGUI_test_Boutons  ()
{

    sf::Vector2f posRoot = { 420 , 150 };

    std::cout << "\n---------------------------------------\n";
    std::cout << "      Test des gadgets : BOUTONS";
    std::cout << "\n---------------------------------------\n\n";

    /////// TITRE Label ///////
    m_labelTitre_1 = m_interface->creer.label( "Boutons" );
    m_labelTitre_1->setPosition    ( posRoot.x , posRoot.y - 40 );
    m_labelTitre_1->setTailleCharac (20);
//    m_labelTitre_1->setStyle       ( m_skin->getStyle (  gui::Styles::txtTitre ) );




    using namespace gui;

    /////// Simple bouton rectangulaire ///////
    m_boutonTexte = m_interface->creer.boutonTexte( "Machiner" );
    m_boutonTexte->setAutoAjuster ( true );
//    m_boutonTexte->setSkin        ( m_skin );
//    m_boutonTexte->setStyle       ( m_skin->getStyle (  gui::Styles::bouton ) );

    m_boutonTexte->setPosition    ( posRoot.x , posRoot.y );

     lierMachiner ();

    /////// Interactions clavier ///////
    // On ajoute une liaison à la touche Espace pour changer le style du rectangle
    m_interface->lier ( sf::Keyboard::Tab , [this]() {
            std::cout << "Interface - Action : touche 'Tab'\n";
            std::cout << "      -> toggle l'activite du bouton\n";
            if (  m_boutonTexte->estActif() ){
                delierMachiner ();
                m_boutonTexte->setActif( false );
            }else {
                lierMachiner ();
                m_boutonTexte->setActif( true );
            }
            m_boutonCoche->setValeur ( m_boutonTexte->estActif() );
        } );


    /////// autre Label ///////
    m_label_5 = m_interface->creer.label( "<---  Simple bouton texte.\n (ACTIONs souris en console.)" );
    m_label_5->setPosition    ( 160 + posRoot.x , posRoot.y + 3 );
//    m_label_5->setSkin        ( m_skin );
//    m_label_5->setStyle       ( m_skin->getStyle (  gui::Styles::txtLog ) );





    /////// Simple bouton rectangulaire ///////
    m_boutonIcone = m_interface->creer.boutonIcone( "media/img/Icone_test.png" );
    m_boutonIcone->setAutoAjuster ( true );
//    m_boutonIcone->setSkin        ( m_skin );
    m_boutonIcone->setFix         ( true );
    m_boutonIcone->setPosition    ( posRoot.x , posRoot.y +35 );


    /////// autre Label ///////
    m_label_12 = m_interface->creer.label( "<---  Simple bouton icone." );
    m_label_12->setPosition    ( 160 + posRoot.x , posRoot.y + 43 );
//    m_label_12->setStyle       ( m_skin->getStyle (  gui::Styles::txtLog ) );




    /////// Menu ///////
    m_boutonMenu = m_interface->creer.menu( );

    m_boutonMenu->setPosition    ( posRoot.x , posRoot.y  + 85 );
    m_boutonMenu->ajouterElement ( "Faire un truc" , [this](){
                        std::cout << "ACTION fait un truc.\n";
                        });
    m_boutonMenu->ajouterElement ( "Bidouiller" , [this](){
                        std::cout << "ACTION bidouille.\n";
                        });

    m_boutonMenu->ajouterElement ( "Faire autre chose" , [this](){
                        std::cout << "ACTION fait autre chose.\n";
                        });

    m_boutonMenu->ajouterElement ( "Buller" , [this](){
                        std::cout << "ACTION ne fait rien.\n";
                        });

    /////// autre Label ///////
    m_label_6 = m_interface->creer.label( "<---  Menu (déroulant, contextuel, ...)." );
    m_label_6->setPosition    ( 160 + posRoot.x , posRoot.y  +  110 );
//    m_label_6->setStyle       ( m_skin->getStyle (  gui::Styles::txtLog ) );












}   // fin init GUI



/////////////////////////////////////////////////
void EcranDemo::lierMachiner ()
{

    m_boutonTexte->lier ( gui::Evenement::onBtnG_relacher , [this](){
                        std::cout << "MACHINER: souris gauche relache : Faire un machin : " ;
//                        std::cout << m_zoneTexte->getValeur() <<"\n";
/*
                        if (  m_boutonCoche->estVisible() ){
                            m_boutonCoche->setVisible ( false );
                        } else {
                            m_boutonCoche->setVisible ( true );
                        }
                        */
//                        std::cout << "-> slider : " << m_slider->getValeur() <<"\n";
                    });
//    m_boutonTexte->lier ( gui::Evenement::onBtnG_presser , [this](){
//                        std::cout << "MACHINER: souris gauche presse\n";
//                        });
//    m_boutonTexte->lier ( gui::Evenement::onBtnD_presser , [this](){
//                        std::cout << "MACHINER: souris droite presse\n";
//                        });
//    m_boutonTexte->lier ( gui::Evenement::onBtnM_presser , [this](){
//                        std::cout << "MACHINER: souris milieu presse\n";
//                        });
//
//    m_boutonTexte->lier ( gui::Evenement::onBtnG_relacherDehors  , [this](){
//                        std::cout << "MACHINER: souris gauche relacherDehors\n";
//                        });
//    m_boutonTexte->lier ( gui::Evenement::onBtnG_relacher , [this](){
//                        std::cout << "MACHINER: souris gauche relacher\n";
//                        });
//    m_boutonTexte->lier ( gui::Evenement::onBtnD_relacherDehors  , [this](){
//                        std::cout << "MACHINER: souris droite relacherDehors\n";
//                        });
//    m_boutonTexte->lier ( gui::Evenement::onBtnD_relacher , [this](){
//                        std::cout << "MACHINER: souris droite relacher\n";
//                        });
//    m_boutonTexte->lier ( gui::Evenement::onBtnM_relacherDehors  , [this](){
//                        std::cout << "MACHINER: souris milieu relacherDehors\n";
//                        });
//    m_boutonTexte->lier ( gui::Evenement::onBtnM_relacher , [this](){
//                        std::cout << "MACHINER: souris milieu relacher\n";
//                        });
//
//    m_boutonTexte->lier ( gui::Evenement::onBtnM_roulerHaut  , [this](){
//                        std::cout << "MACHINER: souris milieu ROULETTE PLUS\n";
//                        });
//    m_boutonTexte->lier ( gui::Evenement::onBtnM_roulerBas , [this](){
//                        std::cout << "MACHINER: souris milieu ROULETTE MOINS\n";
//                        });
}



/////////////////////////////////////////////////
void EcranDemo::delierMachiner ()
{

    m_boutonTexte->delier ( gui::Evenement::onBtnG_relacher);
//    m_boutonTexte->delier ( gui::Evenement::onBtnG_presser);
//    m_boutonTexte->delier ( gui::Evenement::onBtnD_presser);
//    m_boutonTexte->delier ( gui::Evenement::onBtnM_presser );
//
//    m_boutonTexte->delier ( gui::Evenement::onBtnG_relacherDehors );
//    m_boutonTexte->delier ( gui::Evenement::onBtnG_relacher);
//    m_boutonTexte->delier ( gui::Evenement::onBtnD_relacherDehors );
//    m_boutonTexte->delier ( gui::Evenement::onBtnD_relacher );
//    m_boutonTexte->delier ( gui::Evenement::onBtnM_relacherDehors );
//    m_boutonTexte->delier ( gui::Evenement::onBtnM_relacher );
//
//    m_boutonTexte->delier ( gui::Evenement::onBtnM_roulerHaut);
//    m_boutonTexte->delier ( gui::Evenement::onBtnM_roulerBas );

}

/////////////////////////////////////////////////
void
EcranDemo::initGUI_test_Affichages  ()
{
    std::cout << "\n---------------------------------------\n";
    std::cout << "      Test des gadgets : AFFICHAGES";
    std::cout << "\n---------------------------------------\n\n";

    sf::Vector2f posRoot = { 20 , 150 };

    /////// TITRE Label ///////
    m_labelTitre_1 = m_interface->creer.label( "Affichages" );
    m_labelTitre_1->setPosition    ( posRoot.x , posRoot.y - 40 );
    m_labelTitre_1->setTailleCharac ( 20 );
//    m_labelTitre_1->setStyle       ( m_skin->getStyle (  gui::Styles::txtTitre ) );


    using namespace gui;

    /////// Simple rectangle ///////
    m_rectangle = m_interface->creer.rectangle( {20,20} );
    m_rectangle->setPosition    ( posRoot.x , posRoot.y );
//    m_rectangle->setStyle       ( m_skin->getStyle (  gui::Styles::bouton ) );


    /////// Un Label ///////
    m_label = m_interface->creer.label( "<---  simple rectangle." );
    m_label->setPosition    ( 70 + posRoot.x , posRoot.y + 5 );
//    m_label->setStyle       ( m_skin->getStyle (  gui::Styles::txtLog ) );


    /////// Une image ///////
    m_image = m_interface->creer.image( "media/img/Image_defaut.png" );
//    m_image->setTaille      ( { 500 , 500 } );
    m_image->setPosition    (  posRoot.x , posRoot.y + 30 );


    /////// autre Label ///////
    m_label_2 = m_interface->creer.label( "<---  simple image. ('media/img/IconeVide.png')" );
    m_label_2->setPosition    (70 + posRoot.x , posRoot.y + 35 );
//    m_label_2->setStyle       ( m_skin->getStyle (  gui::Styles::txtLog ) );



    /////// Un Label ///////
    m_label_3 = m_interface->creer.label( "LABEL" );
    m_label_3->setPosition    (  posRoot.x , posRoot.y + 60 );
    m_label_3->setTailleCharac ( 20 );

    /////// autre Label ///////
    m_label_4 = m_interface->creer.label( "<---  simple label. (comme ça ici là)" );
    m_label_4->setPosition    ( 70 + posRoot.x , posRoot.y + 65 );
//    m_label_4->setStyle       ( m_skin->getStyle (  gui::Styles::txtLog ) );






    /////// Une icone ///////
    m_icone = m_interface->creer.icone( "media/img/ico_fleches.png" , 4);
    m_icone->setPosition    (  posRoot.x , posRoot.y + 90 );

    m_interface->lier ( sf::Keyboard::Num1 , [this](){
                       m_icone->setIndex ( 1 );
                       });

    m_interface->lier ( sf::Keyboard::Num2 , [this](){
                       m_icone->setIndex ( 2 );
                       });
    m_interface->lier ( sf::Keyboard::Num3 , [this](){
                       m_icone->setIndex ( 3 );
                       });
    m_interface->lier ( sf::Keyboard::Num4 , [this](){
                       m_icone->setIndex ( 4 );
                       });


    /////// autre Label ///////
    m_label_11 = m_interface->creer.label( "<---  icone. ('1', '2', '3', '4' pour changer index de l'icone)" );
    m_label_11->setPosition    ( 70 + posRoot.x , posRoot.y + 95 );
//    m_label_11->setStyle       ( m_skin->getStyle (  gui::Styles::txtLog ) );


/*

    ///////barre de titre ///////
    auto m_barreTitre = m_interface->creer.barreTitre( "Titre" );
    m_barreTitre->setPosition    ( posRoot.x , posRoot.y  +  128 );
    m_barreTitre->setStyle       ( m_skin->getStyle (  gui::Styles::bouton ) );
    m_barreTitre->setIconeImage  ( "media/img/icone_titre.png" );

    /////// autre Label ///////
    auto m_label_14 = m_interface->creer.label( "<---  Barre de titre" );
    m_label_14->setPosition    ( 220 + posRoot.x , posRoot.y  +  132 );
    m_label_14->setStyle       ( m_skin->getStyle (  gui::Styles::txtLog ) );

*/



}   // fin init GUI



}   // fin namespace app































