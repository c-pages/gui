

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
    initGUI_test_Affichages();
    initGUI_test_Boutons();


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

        m_vueJeu.setSize    (event.size.width, event.size.height);
        m_vueGUI.setSize    (event.size.width, event.size.height);

        m_appli->getFenetre()->setView(m_vueGUI);
    }

}



/////////////////////////////////////////////////
void EcranDemo::actualiser  ( float deltaT )
{
    // actualiser la fenetre du jeu ...

    // actualiser l'interface
    m_interface->actualiser    ( );


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
    m_fond.setSize      ( sf::Vector2f ( m_appli->getFenetre()->getSize() ) );
    m_fond.setFillColor ( sf::Color (70,70,70) );

}

/////////////////////////////////////////////////
void
EcranDemo::initGUI ()
{

    using namespace gui;

    // Creation de l'interface qui gère un ensemble de gadget.
    m_interface = std::make_shared<Interface>( m_appli->getFenetre() );
    m_skin      = std::make_shared<Skin>();


    /////// Interactions clavier ///////
    m_interface->lier ( sf::Keyboard::Escape , [this]() {
            std::cout << " touche : Escape  Fermer.\n";
            m_appli->getFenetre()->close();
        } );

    /////// Label retour ///////
    m_labelRetour = m_interface->creer.label( "Retour :" );
    m_labelRetour->setPosition    ( 20 , 5 );
    m_labelRetour->setStyle       ( m_skin->txtLog );


    /////// Interactions clavier ///////
    // On ajoute une liaison à la touche Espace pour changer le style du rectangle
    m_interface->lier ( sf::Keyboard::Space , [this]() {
            std::cout << "Interface - Action : touche 'Espace'\n";
        } );
}



/////////////////////////////////////////////////
void
EcranDemo::initGUI_test_Boutons  ()
{

    std::cout << "\n---------------------------------------\n";
    std::cout << "      Test des gadgets : BOUTONS";
    std::cout << "\n---------------------------------------\n\n";

    sf::Vector2f posRoot = { 340 , 30 };
    using namespace gui;

    /////// Simple bouton rectangulaire ///////
    m_boutonRect = m_interface->creer.bouton( sf::Vector2i (20,20) );
    m_boutonRect->setTexte ( "Machiner" );
    m_boutonRect->setAutoAjuster ( true );
    m_boutonRect->setSkin        ( m_skin );

    m_boutonRect->setPosition    ( posRoot.x , posRoot.y );
    m_boutonRect->lier ( gui::Evenement::onBtnG_relacher , [this](){
                        std::cout << "ACTION souris gauche relache : Faire un machin...\n";
                        });
    m_boutonRect->lier ( gui::Evenement::onBtnG_presser , [this](){
                        std::cout << "ACTION souris gauche presse\n";
                        });
    m_boutonRect->lier ( gui::Evenement::onBtnD_presser , [this](){
                        std::cout << "ACTION souris droite presse\n";
                        });
    m_boutonRect->lier ( gui::Evenement::onBtnM_presser , [this](){
                        std::cout << "ACTION souris milieu presse\n";
                        });

    m_boutonRect->lier ( gui::Evenement::onBtnG_relacherDehors  , [this](){
                        std::cout << "ACTION souris gauche relacherDehors\n";
                        });
    m_boutonRect->lier ( gui::Evenement::onBtnG_relacher , [this](){
                        std::cout << "ACTION souris gauche relacher\n";
                        });
    m_boutonRect->lier ( gui::Evenement::onBtnD_relacherDehors  , [this](){
                        std::cout << "ACTION souris droite relacherDehors\n";
                        });
    m_boutonRect->lier ( gui::Evenement::onBtnD_relacher , [this](){
                        std::cout << "ACTION souris droite relacher\n";
                        });
    m_boutonRect->lier ( gui::Evenement::onBtnM_relacherDehors  , [this](){
                        std::cout << "ACTION souris milieu relacherDehors\n";
                        });
    m_boutonRect->lier ( gui::Evenement::onBtnM_relacher , [this](){
                        std::cout << "ACTION souris milieu relacher\n";
                        });

    m_boutonRect->lier ( gui::Evenement::onBtnM_roulerHaut  , [this](){
                        std::cout << "ACTION souris milieu ROULETTE PLUS\n";
                        });
    m_boutonRect->lier ( gui::Evenement::onBtnM_roulerBas , [this](){
                        std::cout << "ACTION souris milieu ROULETTE MOINS\n";
                        });

    /////// Interactions clavier ///////
    // On ajoute une liaison à la touche Espace pour changer le style du rectangle
    m_interface->lier ( sf::Keyboard::Tab , [this]() {
            std::cout << "Interface - Action : touche 'Tab'\n";
            std::cout << "      -> toggle l'activite du bouton\n";
            if (  m_boutonRect->estActif() )
                m_boutonRect->setActif( false );
            else
                m_boutonRect->setActif( true );
            m_boutonCoche->setValeur ( m_boutonRect->estActif() );
        } );


    /////// autre Label ///////
    m_label_5 = m_interface->creer.label( "<---  Simple bouton rectangulaire.\n       (avec toute les interr-ACTIONs souris en sortie.)" );
    m_label_5->setPosition    ( 190 + posRoot.x , posRoot.y + 3 );
//    m_label_5->setSkin        ( m_skin );
    m_label_5->setStyle       ( m_skin->txtLog );





    /////// Menu ///////
    m_boutonMenu = m_interface->creer.menu( );

//    m_boutonMenu->setSkin        ( m_skin );

    m_boutonMenu->setPosition    ( posRoot.x , posRoot.y  + 40 );
    m_boutonMenu->ajouter ( "Faire un truc" , [this](){
                        std::cout << "ACTION fait un truc.\n";
                        });
    m_boutonMenu->ajouter ( "Bidouiller" , [this](){
                        std::cout << "ACTION bidouille.\n";
                        });

    m_boutonMenu->ajouter ( "Faire autre chose" , [this](){
                        std::cout << "ACTION fait autre chose.\n";
                        });

    m_boutonMenu->ajouter ( "Buller" , [this](){
                        std::cout << "ACTION ne fait rien.\n";
                        });

    /////// autre Label ///////
    m_label_6 = m_interface->creer.label( "<---  Menu (menu déroulant, menu contextuel, ...)" );
    m_label_6->setPosition    ( 190 + posRoot.x , posRoot.y  +  65 );
    m_label_6->setStyle       ( m_skin->txtLog );








    m_boutonCoche = m_interface->creer.btnACocher( );
    m_boutonCoche->setPosition    ( posRoot.x , posRoot.y  +  120 );
    m_boutonCoche->setStyle       ( m_skin->txtLog );
    m_boutonCoche->setTexte       ( "Activer / Désactiver 'Machiner'" );

    m_boutonCoche->lier ( gui::Evenement::onBool_changerValeur , [this](){
                        std::cout << "ACTION Bool : changer Valeur\n";
                        if (  m_boutonRect->estActif() )
                            m_boutonRect->setActif( false );
                        else
                            m_boutonRect->setActif( true );
                        });
    m_boutonCoche->lier ( gui::Evenement::onBool_allume , [this](){
                        std::cout << "ACTION Bool : allume\n";
                        });
    m_boutonCoche->lier ( gui::Evenement::onBool_eteind , [this](){
                        std::cout << "ACTION Bool : eteind\n";
                        });

    /////// autre Label ///////
    m_label_7 = m_interface->creer.label( "<---  Bouton Booleén, interupteur ... ('Tab')" );
    m_label_7->setPosition    ( 190 + posRoot.x , posRoot.y  +  122 );
    m_label_7->setStyle       ( m_skin->txtLog );

}   // fin init GUI



/////////////////////////////////////////////////
void
EcranDemo::initGUI_test_Affichages  ()
{
    std::cout << "\n---------------------------------------\n";
    std::cout << "      Test des gadgets : AFFICHAGES";
    std::cout << "\n---------------------------------------\n\n";

    sf::Vector2f posRoot = { 20 , 30 };

    using namespace gui;

    /////// Simple rectangle ///////
    m_rectangle = m_interface->creer.rectangle( {20,20} );
    m_rectangle->setPosition    ( posRoot.x , posRoot.y );


    /////// Un Label ///////
    m_label = m_interface->creer.label( "<---  simple rectangle." );
    m_label->setPosition    ( 70 + posRoot.x , posRoot.y + 5 );
    m_label->setStyle       ( m_skin->txtLog );


    /////// Une image ///////
    m_image = m_interface->creer.image( "media/img/IconeVide.png" );
    m_image->setTaille      ( { 500 , 500 } );
    m_image->setPosition    (  posRoot.x , posRoot.y + 30 );


    /////// autre Label ///////
    m_label_2 = m_interface->creer.label( "<---  simple image. ('media/img/IconeVide.png')" );
    m_label_2->setPosition    (70 + posRoot.x , posRoot.y + 35 );
    m_label_2->setStyle       ( m_skin->txtLog );



    /////// Un Label ///////
    m_label_3 = m_interface->creer.label( "LABEL" );
    m_label_3->setPosition    (  posRoot.x , posRoot.y + 60 );
    m_label_3->setTexteTaille ( 20 );

    /////// autre Label ///////
    m_label_4 = m_interface->creer.label( "<---  simple label. (comme ça ici là)" );
    m_label_4->setPosition    ( 70 + posRoot.x , posRoot.y + 65 );
    m_label_4->setStyle       ( m_skin->txtLog );




    // On associe des fonctions aux fleches pour faire bouger le label
    /*
    m_interface->lier ( sf::Keyboard::Left , [this]() {
            std::cout << " touche : Left\n";
            m_label->move ( -3,0);
        } );
    m_interface->lier ( sf::Keyboard::Right , [this]() {
            std::cout << " touche : Right\n";
            m_label->move ( 3,0);
        } );
    m_interface->lier ( sf::Keyboard::Up , [this]() {
            std::cout << " touche : Up\n";
            m_label->move ( 0,-3);
        } );
    m_interface->lier ( sf::Keyboard::Down , [this]() {
            std::cout << " touche : Down\n";
            m_label->move ( 0,3);
        } );
    */






}   // fin init GUI




}   // fin namespace app































