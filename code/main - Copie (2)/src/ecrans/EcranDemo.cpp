

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "ecrans/EcranDemo.h"
#include <iostream>
#include <Config.h>



namespace app {

/////////////////////////////////////////////////
EcranDemo::EcranDemo( Application*  appli )
: Ecran             ( appli )
, m_interface       ( nullptr )
{
    // Initialisation de l'interface graphique.
    initGUI     ();

    // les tests
//    initGUI_test_Affichages ();
//    initGUI_test_Boutons    ();
//    initGUI_test_Donnees    ();
//    initGUI_test_Panneaux   ();
//    initGUI_test_Fenetres   ();

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

//        m_fond.setSize      ( pos );
//        m_vueJeu.setSize    (event.size.width, event.size.height);
//        m_vueGUI.setSize    (event.size.width, event.size.height);

        m_appli->getFenetre()->setView(m_vueGUI);
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


    std::string val;
    if ( m_interface->m_boutonSurvole != nullptr ){
        val =  "Survole : " + m_interface->m_boutonSurvole->getNom();
    } else val = "Survole : nullptr";
    m_labelRetour->setTexte ( val );



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
EcranDemo::initGUI ()
{

    using namespace gui;

    // Creation de l'interface qui g�re un ensemble de gadget.
    m_interface = std::make_shared<Interface>( m_appli->getFenetre() );
    m_skin      = std::make_shared<Skin>();


    /////// Interactions clavier ///////
//    m_interface->lier ( sf::Keyboard::Escape , [this]() {
//            std::cout << " touche : Escape  Fermer.\n";
//            m_appli->getFenetre()->close();
//        } );

    /////// Label retour ///////
    m_labelRetour = m_interface->creer.label( "Retour :" );
    m_labelRetour->setPosition    ( 20 , 5 );
    m_labelRetour->setStyle       ( m_skin->getStyle (  gui::Styles::txtLog ) );

}


/////////////////////////////////////////////////
void
EcranDemo::initGUI_test_Fenetres  ()
{
    sf::Vector2f posRoot = { 420 , 300 };

    std::cout << "\n---------------------------------------\n";
    std::cout << "      Test des gadgets : Fenetres";
    std::cout << "\n---------------------------------------\n\n";


    /////// TITRE Label ///////
    m_labelTitre_4 = m_interface->creer.label( "Fenetres" );
    m_labelTitre_4->setPosition    ( posRoot.x , posRoot.y - 40 );
    m_labelTitre_4->setStyle       ( m_skin->getStyle ( gui::Styles::txtTitre ) );


    //// creation d'une fenetre
    auto m_fenetre = m_interface->creer.fenetre( );
    m_fenetre->setPosition  ( posRoot.x , posRoot.y );
    m_fenetre->setTaille    ( { 300 , 100 } );
//    m_fenetre->setStyle     ( m_skin->getStyle ( gui::Styles::txtTitre ) );

    //// contenu de la fenetre
//    auto m_textePourFenetre = m_interface->creer.label( "Nihil est enim virtute amabilius, nihil quod magis adliciat ad diligendum, quippe\n cum propter virtutem et probitatem \netiam eos, quos numquam vidimus, quodam modo \ndiligamus. Quis est qui C. Fabrici, M'. Curi non cum caritate\n aliqua benevola memoriam usurpet, quos\n numquam viderit? quis autem est, qui \nTarquinium Superbum, qui Sp. Cassium, Sp. Maelium non \noderit? Cum duobus ducibus de imperio in Italia \nest decertatum, Pyrrho et Hannibale; ab altero propter \nprobitatem eius non nimis alienos animos habemus, alterum propter crudelitatem \nsemper haec civitas oderit." );
//    m_textePourFenetre->setStyle       ( m_skin->getStyle ( gui::Styles::txtCourant ) );
//
//    m_fenetre->ajouter ( m_textePourFenetre );


    auto  m_boutonPourPanneau_2 = m_interface->creer.boutonTexte( "Bouton" );
    m_boutonPourPanneau_2->setStyle       ( m_skin->getStyle ( gui::Styles::bouton ) );
    m_boutonPourPanneau_2->setPosition (115,20);
    m_fenetre->ajouter ( m_boutonPourPanneau_2 );
/*
    auto  m_bouton2PourPanneau_2 = m_interface->creer.boutonTexte( "Bouton\nBouton\nBouton\nBouton\nBouton\nBouton\nBouton" );
    m_bouton2PourPanneau_2->setStyle       ( m_skin->getStyle ( gui::Styles::bouton ) );
    m_bouton2PourPanneau_2->setPosition (50,50);
    m_fenetre->ajouter ( m_bouton2PourPanneau_2 );
//
    auto  m_bouton3PourPanneau_2 = m_interface->creer.boutonTexte( "BoutonBoutonBoutonBoutonBoutonBouton" );
    m_bouton3PourPanneau_2->setStyle       ( m_skin->getStyle ( gui::Styles::bouton ) );
    m_bouton3PourPanneau_2->setPosition (120,146);
    m_fenetre->ajouter ( m_bouton3PourPanneau_2 );
*/


    //// creation d'une fenetre
    auto m_fenetre2 = m_interface->creer.fenetreRedim(  );
    m_fenetre2->setPosition  ( posRoot.x , posRoot.y + 120 );
    m_fenetre2->setTaille    ( { 300 , 100 });
//    m_fenetre2->setStyle     ( m_skin->getStyle ( gui::Styles::txtTitre ) );

//    m_panneau->setTaille    ( { 200 , 100 } );

    //// contenu de la fenetre
    auto m_texteCPourFenetre = m_interface->creer.label( "Nihil est enim virtute amabilius, nihil quod magis adliciat ad diligendum, quippe\n cum propter virtutem et probitatem \netiam eos, quos numquam vidimus, quodam modo \ndiligamus. Quis est qui C. Fabrici, M'. Curi non cum caritate\n aliqua benevola memoriam usurpet, quos\n numquam viderit? quis autem est, qui \nTarquinium Superbum, qui Sp. Cassium, Sp. Maelium non \noderit? Cum duobus ducibus de imperio in Italia \nest decertatum, Pyrrho et Hannibale; ab altero propter \nprobitatem eius non nimis alienos animos habemus, alterum propter crudelitatem \nsemper haec civitas oderit." );
    m_texteCPourFenetre->setStyle       ( m_skin->getStyle ( gui::Styles::txtCourant ) );
    m_texteCPourFenetre->setPosition ( 5,5);
    m_fenetre2->ajouter ( m_texteCPourFenetre );
}

/////////////////////////////////////////////////
void
EcranDemo::initGUI_test_Panneaux  ()
{

    sf::Vector2f posRoot = { 20 , 300 };

    std::cout << "\n---------------------------------------\n";
    std::cout << "      Test des gadgets : Panneaux";
    std::cout << "\n---------------------------------------\n\n";


    /////// TITRE Label ///////
    m_labelTitre_3 = m_interface->creer.label( "Panneaux" );
    m_labelTitre_3->setPosition    ( posRoot.x , posRoot.y - 40 );
    m_labelTitre_3->setStyle       ( m_skin->getStyle ( gui::Styles::txtTitre ) );

    //// creation d'un panneau
    auto m_panneau = m_interface->creer.panneau(  );
    m_panneau->setPosition  ( posRoot.x , posRoot.y  );
    m_panneau->setStyle     ( m_skin->getStyle ( gui::Styles::txtTitre ) );
//    m_panneau->setTaille    ( { 600 , 100 } ); // ok
//    m_panneau->setTaille    ( { 300 , 200 } ); // ok
    m_panneau->setTaille    ( { 200 , 100 } );

    //// contenu du panneau
    m_textePourPanneau = m_interface->creer.label( "Nihil est enim virtute amabilius, nihil quod magis adliciat ad diligendum, quippe\n cum propter virtutem et probitatem \netiam eos, quos numquam vidimus, quodam modo \ndiligamus. Quis est qui C. Fabrici, M'. Curi non cum caritate\n aliqua benevola memoriam usurpet, quos\n numquam viderit? quis autem est, qui \nTarquinium Superbum, qui Sp. Cassium, Sp. Maelium non \noderit? Cum duobus ducibus de imperio in Italia \nest decertatum, Pyrrho et Hannibale; ab altero propter \nprobitatem eius non nimis alienos animos habemus, alterum propter crudelitatem \nsemper haec civitas oderit." );
    m_textePourPanneau->setStyle       ( m_skin->getStyle ( gui::Styles::txtCourant ) );

    m_panneau->ajouter ( m_textePourPanneau );

    /////// autre Label ///////
    m_label_13 = m_interface->creer.label( "<---  Panneau simple" );
    m_label_13->setPosition    ( 220 + posRoot.x , posRoot.y  +  35 );
    m_label_13->setStyle       ( m_skin->getStyle (  gui::Styles::txtLog ) );






    //// creation d'un autre panneau
    auto m_panneau_2 = m_interface->creer.panneauSliders(  );
    m_panneau_2->setPosition  ( posRoot.x , posRoot.y + 120 );
//    m_panneau_2->setPosition  ( 0 , 0 );
    m_panneau_2->setStyle     ( m_skin->getStyle ( gui::Styles::txtTitre ) );
//    m_panneau->setTaille    ( { 600 , 100 } ); // ok
//    m_panneau->setTaille    ( { 300 , 200 } ); // ok
    m_panneau_2->setTaille    ( { 200 , 100 } );

    //// contenu du panneau
    auto m_texteBPourPanneau = m_interface->creer.label( "Nihil est enim virtute amabilius, nihil quod magis adliciat ad diligendum, quippe\n cum propter virtutem et probitatem \netiam eos, quos numquam vidimus, quodam modo \ndiligamus. Quis est qui C. Fabrici, M'. Curi non cum caritate\n aliqua benevola memoriam usurpet, quos\n numquam viderit? quis autem est, qui \nTarquinium Superbum, qui Sp. Cassium, Sp. Maelium non \noderit? Cum duobus ducibus de imperio in Italia \nest decertatum, Pyrrho et Hannibale; ab altero propter \nprobitatem eius non nimis alienos animos habemus, alterum propter crudelitatem \nsemper haec civitas oderit." );
    m_texteBPourPanneau->setStyle       ( m_skin->getStyle ( gui::Styles::txtCourant ) );
    m_panneau_2->ajouter ( m_texteBPourPanneau );

    //// contenu du panneau
//
//    auto  m_boutonPourPanneau_2 = m_interface->creer.boutonTexte( "BoutonBoutonBoutonBoutonBoutonBouton" );
//    m_boutonPourPanneau_2->setStyle       ( m_skin->getStyle ( gui::Styles::bouton ) );
//    m_boutonPourPanneau_2->setPosition (50,20);
//    m_panneau_2->ajouter ( m_boutonPourPanneau_2 );
////
//    auto  m_bouton2PourPanneau_2 = m_interface->creer.boutonTexte( "Bouton\nBouton\nBouton\nBouton\nBouton\nBouton\nBouton" );
//    m_bouton2PourPanneau_2->setStyle       ( m_skin->getStyle ( gui::Styles::bouton ) );
//    m_bouton2PourPanneau_2->setPosition (50,50);
//    m_panneau_2->ajouter ( m_bouton2PourPanneau_2 );
////
//    auto  m_bouton3PourPanneau_2 = m_interface->creer.boutonTexte( "BoutonBoutonBoutonBoutonBoutonBouton" );
//    m_bouton3PourPanneau_2->setStyle       ( m_skin->getStyle ( gui::Styles::bouton ) );
//    m_bouton3PourPanneau_2->setPosition (120,146);
//    m_panneau_2->ajouter ( m_bouton3PourPanneau_2 );

/*

//    auto  m_textePourPanneau_2 = m_interface->creer.label( "Nihil est enim virtute amabilius, nihil quod magis adliciat ad diligendum, quippe\n cum propter virtutem et probitatem \netiam eos, quos numquam vidimus, quodam modo \ndiligamus. Quis est qui C. Fabrici, M'. Curi non cum caritate\n aliqua benevola memoriam usurpet, quos\n numquam viderit? quis autem est, qui \nTarquinium Superbum, qui Sp. Cassium, Sp. Maelium non \noderit? Cum duobus ducibus de imperio in Italia \nest decertatum, Pyrrho et Hannibale; ab altero propter \nprobitatem eius non nimis alienos animos habemus, alterum propter crudelitatem \nsemper haec civitas oderit." );
//    m_textePourPanneau_2->setStyle       ( m_skin->getStyle ( gui::Styles::txtCourant ) );
//    m_panneau_2->ajouter ( m_textePourPanneau_2 );


    auto  m_boutonPourPanneau_2 = m_interface->creer.boutonTexte( "BoutonBoutonBoutonBoutonBoutonBouton" );
    m_boutonPourPanneau_2->setStyle       ( m_skin->getStyle ( gui::Styles::bouton ) );
    m_boutonPourPanneau_2->setPosition (50,20);
    m_panneau_2->ajouter ( m_boutonPourPanneau_2 );
//
    auto  m_bouton2PourPanneau_2 = m_interface->creer.boutonTexte( "BoutonBoutonBoutonBoutonBoutonBouton" );
    m_bouton2PourPanneau_2->setStyle       ( m_skin->getStyle ( gui::Styles::bouton ) );
    m_bouton2PourPanneau_2->setPosition (50,50);
    m_panneau_2->ajouter ( m_bouton2PourPanneau_2 );
//
    auto  m_bouton3PourPanneau_2 = m_interface->creer.boutonTexte( "BoutonBoutonBoutonBoutonBoutonBouton" );
    m_bouton3PourPanneau_2->setStyle       ( m_skin->getStyle ( gui::Styles::bouton ) );
    m_bouton3PourPanneau_2->setPosition (50,180);
    m_panneau_2->ajouter ( m_bouton3PourPanneau_2 );
*/


    /////// autre Label ///////
    m_label_13 = m_interface->creer.label( "<---  PanneauSliders \n(avec barres de d�filemement)" );
    m_label_13->setPosition    ( 220 + posRoot.x , posRoot.y  +  155 );
    m_label_13->setStyle       ( m_skin->getStyle (  gui::Styles::txtLog ) );
}




/////////////////////////////////////////////////
void
EcranDemo::initGUI_test_Donnees  ()
{

    sf::Vector2f posRoot = { 820 , 60 };

    std::cout << "\n---------------------------------------\n";
    std::cout << "      Test des gadgets : DONNEES";
    std::cout << "\n---------------------------------------\n\n";


    /////// TITRE Label ///////
    m_labelTitre_0 = m_interface->creer.label( "Donn�es" );
    m_labelTitre_0->setPosition    ( posRoot.x , posRoot.y - 40 );
    m_labelTitre_0->setStyle       ( m_skin->getStyle ( gui::Styles::txtTitre ) );



    /////// Bouton � cocher ///////
    m_boutonCoche = m_interface->creer.btnACocher( );
    m_boutonCoche->setPosition    ( posRoot.x , posRoot.y  +  0 );
    m_boutonCoche->setStyle       ( m_skin->getStyle ( gui::Styles::txtLog ) );
    m_boutonCoche->setTexte       ( "'Machiner'" );
    m_boutonCoche->setValeur      ( true );

    m_boutonCoche->lier ( gui::Evenement::on_changerValeur , [this](){
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
    m_label_7 = m_interface->creer.label( "<---  Bouton Boole�n, interrupteur ... ('Tab')" );
    m_label_7->setPosition    ( 190 + posRoot.x , posRoot.y  +  2 );
    m_label_7->setStyle       ( m_skin->getStyle (  gui::Styles::txtLog ) );



    /////// Zone de texte ///////
    m_zoneTexte = m_interface->creer.zoneTexte( "Zone de texte" );
    m_zoneTexte->setPosition    ( posRoot.x , posRoot.y  +  28 );
    m_zoneTexte->setStyle       ( m_skin->getStyle (  gui::Styles::txtLog ) );


    /////// autre Label ///////
    m_label_8 = m_interface->creer.label( "<---  Zone de texte (simple pour l'instant)." );
    m_label_8->setPosition    ( 190 + posRoot.x , posRoot.y  +  30 );
    m_label_8->setStyle       ( m_skin->getStyle (  gui::Styles::txtLog ) );




    ///////slider ///////
    m_slider = m_interface->creer.slider( );
    m_slider->setPosition    ( posRoot.x , posRoot.y  +  68 );
    m_slider->setStyle       ( m_skin->getStyle (  gui::Styles::bouton ) );
//    m_slider->setLongCurseur ( 50 );

    //m_slider->setVertical();

    m_slider->lier ( gui::Evenement::on_changerValeur , [this](){
        std::cout << "ACTION - Valeur : " << m_slider->getValeur() << "\n";
    });


    /////// autre Label ///////
    m_label_9 = m_interface->creer.label( "<---  Slider pour controler valeur de 0.0 � 1.0" );
    m_label_9->setPosition    ( 190 + posRoot.x , posRoot.y  +  70 );
    m_label_9->setStyle       ( m_skin->getStyle (  gui::Styles::txtLog ) );

/*

    ///////barreDefilement ///////
    m_barreDefil = m_interface->creer.barreDefilement( );
    m_barreDefil->setPosition    ( posRoot.x , posRoot.y  +  98 );
    m_barreDefil->setStyle       ( m_skin->getStyle (  gui::Styles::bouton ) );

    m_barreDefil->setLongueurCurseur ( 50 );

    /////// autre Label ///////
    m_label_10 = m_interface->creer.label( "<---  Barre de d�filement" );
    m_label_10->setPosition    ( 190 + posRoot.x , posRoot.y  +  100 );
    m_label_10->setStyle       ( m_skin->getStyle (  gui::Styles::txtLog ) );

*/


}
/////////////////////////////////////////////////
void
EcranDemo::initGUI_test_Boutons  ()
{

    sf::Vector2f posRoot = { 420 , 60 };

    std::cout << "\n---------------------------------------\n";
    std::cout << "      Test des gadgets : BOUTONS";
    std::cout << "\n---------------------------------------\n\n";

    /////// TITRE Label ///////
    m_labelTitre_1 = m_interface->creer.label( "Boutons" );
    m_labelTitre_1->setPosition    ( posRoot.x , posRoot.y - 40 );
    m_labelTitre_1->setStyle       ( m_skin->getStyle (  gui::Styles::txtTitre ) );




    using namespace gui;



//    /////// Simple bouton rectangulaire ///////
    m_boutonTexte = m_interface->creer.boutonTexte( "Machiner" );
    m_boutonTexte->setAutoAjuster ( true );
//    m_boutonTexte->setSkin        ( m_skin );
    m_boutonTexte->setStyle       ( m_skin->getStyle ( gui::Styles::bouton ) );

    m_boutonTexte->setPosition    ( posRoot.x , posRoot.y );

     lierMachiner ();

    /////// Interactions clavier ///////
    // On ajoute une liaison � la touche Espace pour changer le style du rectangle
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
    m_label_5->setStyle       ( m_skin->getStyle (  gui::Styles::txtLog ) );





    /////// Simple bouton rectangulaire ///////
    m_boutonIcone = m_interface->creer.boutonIcone( "media/img/Icone_test.png" );
    m_boutonIcone->setAutoAjuster ( true );
    m_boutonIcone->setStyle       ( m_skin->getStyle ( gui::Styles::bouton ) );
//    m_boutonIcone->setSkin        ( m_skin );
    m_boutonIcone->setFix         ( true );
    m_boutonIcone->setPosition    ( posRoot.x , posRoot.y +35 );


    /////// autre Label ///////
    m_label_12 = m_interface->creer.label( "<---  Simple bouton icone." );
    m_label_12->setPosition    ( 160 + posRoot.x , posRoot.y + 43 );
    m_label_12->setStyle       ( m_skin->getStyle (  gui::Styles::txtLog ) );




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
    m_label_6 = m_interface->creer.label( "<---  Menu (d�roulant, contextuel, ...)." );
    m_label_6->setPosition    ( 160 + posRoot.x , posRoot.y  +  110 );
    m_label_6->setStyle       ( m_skin->getStyle (  gui::Styles::txtLog ) );













}   // fin init GUI



/////////////////////////////////////////////////
void EcranDemo::lierMachiner ()
{

    m_boutonTexte->lier ( gui::Evenement::onBtnG_relacher , [this](){
                        std::cout << "MACHINER: souris gauche relache : Faire un machin : " << m_zoneTexte->getValeur() <<"\n";
/*
                        if (  m_boutonCoche->estVisible() ){
                            m_boutonCoche->setVisible ( false );
                        } else {
                            m_boutonCoche->setVisible ( true );
                        }
                        */
                        std::cout << "-> slider : " << m_slider->getValeur() <<"\n";
                    });
    m_boutonTexte->lier ( gui::Evenement::onBtnG_presser , [this](){
                        std::cout << "MACHINER: souris gauche presse\n";
                        });
    m_boutonTexte->lier ( gui::Evenement::onBtnD_presser , [this](){
                        std::cout << "MACHINER: souris droite presse\n";
                        });
    m_boutonTexte->lier ( gui::Evenement::onBtnM_presser , [this](){
                        std::cout << "MACHINER: souris milieu presse\n";
                        });

    m_boutonTexte->lier ( gui::Evenement::onBtnG_relacherDehors  , [this](){
                        std::cout << "MACHINER: souris gauche relacherDehors\n";
                        });
    m_boutonTexte->lier ( gui::Evenement::onBtnG_relacher , [this](){
                        std::cout << "MACHINER: souris gauche relacher\n";
                        });
    m_boutonTexte->lier ( gui::Evenement::onBtnD_relacherDehors  , [this](){
                        std::cout << "MACHINER: souris droite relacherDehors\n";
                        });
    m_boutonTexte->lier ( gui::Evenement::onBtnD_relacher , [this](){
                        std::cout << "MACHINER: souris droite relacher\n";
                        });
    m_boutonTexte->lier ( gui::Evenement::onBtnM_relacherDehors  , [this](){
                        std::cout << "MACHINER: souris milieu relacherDehors\n";
                        });
    m_boutonTexte->lier ( gui::Evenement::onBtnM_relacher , [this](){
                        std::cout << "MACHINER: souris milieu relacher\n";
                        });

    m_boutonTexte->lier ( gui::Evenement::onBtnM_roulerHaut  , [this](){
                        std::cout << "MACHINER: souris milieu ROULETTE PLUS\n";
                        });
    m_boutonTexte->lier ( gui::Evenement::onBtnM_roulerBas , [this](){
                        std::cout << "MACHINER: souris milieu ROULETTE MOINS\n";
                        });
}



/////////////////////////////////////////////////
void EcranDemo::delierMachiner ()
{

    m_boutonTexte->delier ( gui::Evenement::onBtnG_relacher);
    m_boutonTexte->delier ( gui::Evenement::onBtnG_presser);
    m_boutonTexte->delier ( gui::Evenement::onBtnD_presser);
    m_boutonTexte->delier ( gui::Evenement::onBtnM_presser );

    m_boutonTexte->delier ( gui::Evenement::onBtnG_relacherDehors );
    m_boutonTexte->delier ( gui::Evenement::onBtnG_relacher);
    m_boutonTexte->delier ( gui::Evenement::onBtnD_relacherDehors );
    m_boutonTexte->delier ( gui::Evenement::onBtnD_relacher );
    m_boutonTexte->delier ( gui::Evenement::onBtnM_relacherDehors );
    m_boutonTexte->delier ( gui::Evenement::onBtnM_relacher );

    m_boutonTexte->delier ( gui::Evenement::onBtnM_roulerHaut);
    m_boutonTexte->delier ( gui::Evenement::onBtnM_roulerBas );

}

/////////////////////////////////////////////////
void
EcranDemo::initGUI_test_Affichages  ()
{
    std::cout << "\n---------------------------------------\n";
    std::cout << "      Test des gadgets : AFFICHAGES";
    std::cout << "\n---------------------------------------\n\n";

    sf::Vector2f posRoot = { 20 , 60 };

    /////// TITRE Label ///////
    m_labelTitre_1 = m_interface->creer.label( "Affichages" );
    m_labelTitre_1->setPosition    ( posRoot.x , posRoot.y - 40 );
    m_labelTitre_1->setStyle       ( m_skin->getStyle (  gui::Styles::txtTitre ) );


    using namespace gui;

    /////// Simple rectangle ///////
    m_rectangle = m_interface->creer.rectangle( {20,20} );
    m_rectangle->setPosition    ( posRoot.x , posRoot.y );
    m_rectangle->setStyle       ( m_skin->getStyle (  gui::Styles::bouton ) );


    /////// Un Label ///////
    m_label = m_interface->creer.label( "<---  simple rectangle." );
    m_label->setPosition    ( 70 + posRoot.x , posRoot.y + 5 );
    m_label->setStyle       ( m_skin->getStyle (  gui::Styles::txtLog ) );


    /////// Une image ///////
    m_image = m_interface->creer.image( "media/img/Image_defaut.png" );
//    m_image->setTaille      ( { 500 , 500 } );
    m_image->setPosition    (  posRoot.x , posRoot.y + 30 );


    /////// autre Label ///////
    m_label_2 = m_interface->creer.label( "<---  simple image. ('media/img/IconeVide.png')" );
    m_label_2->setPosition    (70 + posRoot.x , posRoot.y + 35 );
    m_label_2->setStyle       ( m_skin->getStyle (  gui::Styles::txtLog ) );



    /////// Un Label ///////
    m_label_3 = m_interface->creer.label( "LABEL" );
    m_label_3->setPosition    (  posRoot.x , posRoot.y + 60 );
    m_label_3->setTexteTaille ( 20 );

    /////// autre Label ///////
    m_label_4 = m_interface->creer.label( "<---  simple label. (comme �a ici l�)" );
    m_label_4->setPosition    ( 70 + posRoot.x , posRoot.y + 65 );
    m_label_4->setStyle       ( m_skin->getStyle (  gui::Styles::txtLog ) );






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
    m_label_11->setStyle       ( m_skin->getStyle (  gui::Styles::txtLog ) );


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






























