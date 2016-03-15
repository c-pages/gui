#include "Interface.h"
#include "Interface.h"





#include <iostream>


namespace gui {


sf::RenderWindow*                           Interface::ms_fenetreSFML = nullptr;
ResourcesMgr<sf::Font,std::string >         Interface::ms_polices = {};
ResourcesMgr<sf::Texture,   std::string >   Interface::ms_images = {};
ResourcesMgr<sf::Texture,   std::string >   Interface::ms_curseurs = {};
ResourcesMgr<sf::Texture,   std::string >   Interface::ms_icones = {};

std::shared_ptr<Calque>        Interface::ms_calque_bureau                  = std::make_shared<Calque>("_Bureau");
std::shared_ptr<Calque>        Interface::ms_calque_fenetres                = std::make_shared<Calque>("_Fenetres");
std::shared_ptr<Calque>        Interface::ms_calque_bandeaux                = std::make_shared<Calque>("_Bandeaux");
std::shared_ptr<Calque>        Interface::ms_calque_panneau_G               = std::make_shared<Calque>("_PanneauG");
std::shared_ptr<Calque>        Interface::ms_calque_panneau_D               = std::make_shared<Calque>("_PanneauD");
std::shared_ptr<Calque>        Interface::ms_calque_bandeauMenuDeroulants   = std::make_shared<Calque>("_BandeauMD");
std::shared_ptr<Calque>        Interface::ms_calque_menuDeroulants          = std::make_shared<Calque>("_Menus");
std::shared_ptr<Calque>        Interface::ms_calque_infos                   = std::make_shared<Calque>("_Infos");
std::shared_ptr<Calque>        Interface::ms_calque_souris                  = std::make_shared<Calque>("_Souris");

std::shared_ptr<AffCurseurSouris>       Interface::ms_curseurSouris;
bool                                    Interface::ms_aBesoinActualisation = false;

//bool                                    Interface::ms_debugLog = true;


/////////////////////////////////////////////////
Interface::Interface( sf::RenderWindow* fenetre )
: Gadget ()
, m_boutonSurvole   ( nullptr )
, m_boutonPresse    ( nullptr )
, m_fenetre         ( fenetre )
, creer             ( this )
//, m_curseurSouris   ( std::make_shared<AffCurseurSouris>()  )


//, ms_calque_bureau      ( std::make_shared<Calque>())
//, ms_calque_bandeaux    ( std::make_shared<Calque>())
//, ms_calque_fenetres    ( std::make_shared<Calque>())
{
    m_nom = "GUI";

//    logTitre("Creation");

    // la fenetre SFML
    ms_fenetreSFML = fenetre;

    // les calques
    ajouter ( ms_calque_bureau );
    ajouter ( ms_calque_panneau_G );
    ajouter ( ms_calque_panneau_D );
    ajouter ( ms_calque_bandeaux );
    ajouter ( ms_calque_bandeauMenuDeroulants );
    ajouter ( ms_calque_fenetres );
    ajouter ( ms_calque_menuDeroulants );
    ajouter ( ms_calque_infos );
    ajouter ( ms_calque_souris );


    // reset du nombre de gadgets
    ms_CompteurGadgets = 0;



    // les tailles
//    m_taille = { m_fenetre->getSize().x ,m_fenetre->getSize().y };
    m_taille = { 1920 , 1080 };
//    ms_calque_bureau->setTaille    ( m_taille );
//    ms_calque_bandeaux->setTaille  ( m_taille );
//    ms_calque_panneau_G->setTaille  ( m_taille );
//    ms_calque_panneau_D->setTaille  ( m_taille );
//    ms_calque_fenetres->setTaille  ( m_taille );
//    ms_calque_menuDeroulants->setTaille  ( m_taille );
//    ms_calque_bandeauMenuDeroulants->setTaille  ( m_taille );
//    ms_calque_souris->setTaille  ( m_taille );




    // initialiser les polices
    ms_polices.load( "Defaut"  , "media/polices/consola.ttf" );
    ms_polices.load( "arial"  , "media/polices/arial.ttf" );
    ms_polices.load( "swisse"  , "media/polices/swisse.ttf" );
    ms_polices.load( "syastro"  , "media/polices/syastro_.ttf" );

    // initialiser les icones
    ms_icones.load( "ico_fenetre"  , "media/img/icones_fenetre.png" );
    ms_icones.load( "ico_fleches"  , "media/img/ico_fleches.png" );


    // initialiser les curseurs
//    ms_curseurSouris = std::make_shared<AffCurseurSouris>( this );
//    ms_calque_souris->ajouter(ms_curseurSouris);
//    ms_curseurs.load( "Redimensionnement"  , "media/img/curs_redimensionnement.png" );

    m_parent = nullptr;

}

/////////////////////////////////////////////////
std::shared_ptr<Gadget> Interface::chercherGadgetSurvole ()
{
//    log ("chercherGadgetSurvole");
    sf::Vector2i posSouris = sf::Mouse::getPosition( *m_fenetre );

    for (int i=m_enfants.size()-1; i>=0; i-- )    {
        auto enfant = m_enfants[i];
        std::shared_ptr<Gadget> result = enfant->testerSurvol ( posSouris );
        if ( result != nullptr ) return result;
    }

    return nullptr;
}


/////////////////////////////////////////////////
void Interface::actualiser ()
{

//    log ( "aBesoinActualisation ",  ms_aBesoinActualisation  );

    if ( ! ms_aBesoinActualisation ) return;


    // debut de la frame, on saute des lignes
    logOut (  "\n\n" );

    logTitre ( "Actualiser");

    // on actualise les enfants ( donc les calques)
//    log ( "actualiserEnfants");
    actualiserEnfants();

    // on calcule la taille verticale des bandeaux ...
    sf::Vector2f decallage = {0,0};
    for ( auto MenuDeroulant : ms_calque_bandeauMenuDeroulants->getEnfants() )
    {
        MenuDeroulant->setPosition (decallage.x, decallage.y);
        MenuDeroulant->setTailleX ( m_fenetre->getSize().x );
        decallage.y += MenuDeroulant->getTaille().y;
    }
    for ( auto bandeau : ms_calque_bandeaux->getEnfants() )
    {
        bandeau->setPosition (decallage.x, decallage.y);
        bandeau->setTailleX ( m_fenetre->getSize().x );
        decallage.y += bandeau->getTaille().y;
    }

    for ( std::shared_ptr<Gadget> panneau : ms_calque_panneau_G->getEnfants() )
    {

        panneau->setPosition ( decallage.x , decallage.y );
        //panneau->setTailleX ( 250 );
        panneau->setTailleY ( m_fenetre->getSize().y - decallage.y );
        decallage.x += panneau->getTaille().x;

    }
    // ... pour décaller le calque du bureau ... à voir si c'est pas le bordel
    ms_calque_bureau->setPosition ( decallage.x , decallage.y );
    decallage.x = 0;
    for ( std::shared_ptr<Gadget> panneau : ms_calque_panneau_D->getEnfants() )
    {

        decallage.x += panneau->getTaille().x;
        panneau->setPosition ( m_fenetre->getSize().x -  decallage.x , decallage.y );
        //panneau->setTailleX ( 250 );
        panneau->setTailleY ( m_fenetre->getSize().y - decallage.y );

    }


//    logTitre ( "fin d'Actualisastion.");


    ms_aBesoinActualisation = false;
}

///////////////////////////////////////////////////
//void Interface::actualiser (sf::Time delta)
//{
//    for ( auto enfant : m_enfants )
//        enfant->actualiser( delta );
//}



/////////////////////////////////////////////////
void Interface::traiterEvenements( sf::Event evenement )
{
//    std::cout << "EVENEMTN--------------\n";
//    log ("Traiter les evenements");

    Gadget::traiterEvenements ( evenement);

    //////////////////////////////////////////
    // les evenements 'souris' de l'interface
    //////////////////////////////////////////
    auto boutonSurvoleBack = m_boutonSurvole;
    m_boutonSurvole = chercherGadgetSurvole ();



    switch ( evenement.type ){
        ///////// Deplacement souris /////////////////////////////////////////
        case sf::Event::MouseMoved :
//            log ("  ... la souris bouge ...");

//            // On gere le cureur souris
//            if (ms_curseurSouris->estVisible())
//                ms_curseurSouris->traiterEvenements( evenement );

            // On sort si on a pas changé de bouton survolé
            if ( m_boutonSurvole ==  boutonSurvoleBack )
                return;

            log ("  ... on survol un bouton ...");

            if (m_boutonPresse == nullptr )
            {

                // on gère le gadget anciennement survolé
                if (boutonSurvoleBack!=nullptr){
//                        std::cout << "--------> boutonSurvoleBack : " << boutonSurvoleBack->getNom() << "\n";
                    boutonSurvoleBack->setSurvol( false );
                    boutonSurvoleBack->declencher ( Evenement::on_sortir );
                }
                // on gère le gadget survolé
                if (m_boutonSurvole != nullptr) {

                    log ("on survole un truc");
//                        std::cout << "--------> m_boutonSurvole : " << m_boutonSurvole->getNom() << "\n";
                    m_boutonSurvole->setSurvol( true );
                    m_boutonSurvole->declencher ( Evenement::on_entrer );
                }
            } else {
                // on gère le gadget survolé
                /*if (m_boutonSurvole==nullptr){
                    boutonSurvoleBack->setSurvol( false );
                    boutonSurvoleBack->declencher ( Evenement::on_sortir );
                }*/
                /*if (m_boutonSurvole != m_boutonPresse ) {
                }*/
                // on gère le gadget anciennement survolé*/

            }
        break;

        ///////// Presser bouton souris /////////////////////////////////////////
        case sf::Event::MouseButtonPressed:

            // On sort si on a pas de bouton survolé
            if ( m_boutonSurvole ==  nullptr )
                return;

            // on definie le bouton presssé
            m_boutonPresse = m_boutonSurvole;

            // On déclenche l'action en fonction du bouton de la souris
            if ( evenement.mouseButton.button == sf::Mouse::Left ) {
                m_boutonPresse->declencher ( Evenement::onBtnG_presser );
                m_boutonPresse->setPresse ( true );
            } else if ( evenement.mouseButton.button == sf::Mouse::Right ) {
                m_boutonSurvole->declencher ( Evenement::onBtnD_presser );
            } else if ( evenement.mouseButton.button == sf::Mouse::Middle ) {
                m_boutonSurvole->declencher ( Evenement::onBtnM_presser );
            }

        break;

        ///////// Relacher bouton souris /////////////////////////////////////////
        case sf::Event::MouseButtonReleased:

            // On ne survol pas de bouton
            if ( m_boutonSurvole ==  nullptr ){
                if ( evenement.mouseButton.button == sf::Mouse::Left )
                    declencherToutBoutons ( Evenement::onBtnG_relacherDehors  );
                else if ( evenement.mouseButton.button == sf::Mouse::Right )
                    declencherToutBoutons ( Evenement::onBtnD_relacherDehors  );
                else if ( evenement.mouseButton.button == sf::Mouse::Middle )
                    declencherToutBoutons ( Evenement::onBtnM_relacherDehors  );

                // on reset le bouton pressé
                if ( m_boutonPresse !=  nullptr ){
                    m_boutonPresse->setSurvol( false );
                    m_boutonPresse->setPresse( false );
                    m_boutonPresse = nullptr;
                }

                // On sort.
                return;
            }

            // on survol un autre bouton que celui pressé.
            if ( m_boutonPresse != m_boutonSurvole )
            {
                // on declenche l'action
                if ( evenement.mouseButton.button == sf::Mouse::Left )
                    declencherToutBoutons ( Evenement::onBtnG_relacherDehors  , m_boutonSurvole );
                else if ( evenement.mouseButton.button == sf::Mouse::Right )
                    declencherToutBoutons ( Evenement::onBtnD_relacherDehors   , m_boutonSurvole );
                else if ( evenement.mouseButton.button == sf::Mouse::Middle )
                    declencherToutBoutons ( Evenement::onBtnM_relacherDehors   , m_boutonSurvole );

/*
                if ( evenement.mouseButton.button == sf::Mouse::Left )
                    m_boutonSurvole->declencher  ( Evenement::onBtnG_relacher );
                else if ( evenement.mouseButton.button == sf::Mouse::Right )
                    m_boutonSurvole->declencher  ( Evenement::onBtnD_relacher );
                else if ( evenement.mouseButton.button == sf::Mouse::Middle )
                    m_boutonSurvole->declencher  ( Evenement::onBtnM_relacher );
*/

                // on reset le bouton pressé
                if ( m_boutonPresse !=  nullptr ){
                    m_boutonPresse->setSurvol( false );
                    m_boutonPresse->setPresse( false );
                    m_boutonPresse = nullptr;
                }
                // On sort.
                return;
            }


            // On survol le bouton qu'on à pressé.
            // => On déclenche l'action 'relacher'
            if ( evenement.mouseButton.button == sf::Mouse::Left )
                m_boutonPresse->declencher ( Evenement::onBtnG_relacher );
            else if ( evenement.mouseButton.button == sf::Mouse::Right )
                m_boutonPresse->declencher ( Evenement::onBtnD_relacher );
            else if ( evenement.mouseButton.button == sf::Mouse::Middle )
                m_boutonPresse->declencher ( Evenement::onBtnM_relacher );

            // On declenche pour tout les autre boutons 'relacherDehors'
            if ( evenement.mouseButton.button == sf::Mouse::Left )
                declencherToutBoutons ( Evenement::onBtnG_relacherDehors  , m_boutonSurvole );
            else if ( evenement.mouseButton.button == sf::Mouse::Right )
                declencherToutBoutons ( Evenement::onBtnD_relacherDehors  , m_boutonSurvole );
            else if ( evenement.mouseButton.button == sf::Mouse::Middle )
                declencherToutBoutons ( Evenement::onBtnM_relacherDehors  , m_boutonSurvole );


            // on reset m_boutonPressé
            m_boutonPresse->setPresse( false );
            m_boutonPresse = nullptr;

        break;

        ///////// Presser roulette souris /////////////////////////////////////////
        case sf::Event::MouseWheelMoved :

            // Si on survole un bouton
            if ( m_boutonSurvole != nullptr ){

                // On déclenche l'action en fonction
                if ( evenement.mouseWheel.delta > 0 )
                    m_boutonSurvole->declencher ( Evenement::onBtnM_roulerHaut );
                else
                    m_boutonSurvole->declencher ( Evenement::onBtnM_roulerBas );
            }

        break;

        ///////// on ne traite pas les autres types d'évènements /////////////////////////////////////////
        default: break;
    }

}
/*
/////////////////////////////////////////////////
void Interface::nouvellePolice( std::string fichier )
{

    m_textures->load( fichier );

}*/





/////////////////////////////////////////////////
void Interface::declencherToutBoutons ( Evenement evenement , std::shared_ptr<Gadget> saufGadget )
{
    if ( saufGadget != nullptr ){
        for ( auto bouton : Bouton::ms_boutons )
            if ( bouton->getNom() != saufGadget->getNom() )
                bouton->declencher( evenement );
    } else for ( auto bouton : Bouton::ms_boutons )
        bouton->declencher( evenement );

}

/////////////////////////////////////////////////
void Interface::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

    // On dessine le gadgets de l'interface
    for (auto enfant : m_enfants )
        target.draw(*enfant, states);

//    // on dessine la souris (si besoin)
//    if (ms_curseurSouris->estVisible() )
//        target.draw(*ms_curseurSouris, states);

        /*
        target.draw(*m_bureau, states);
        target.draw(*m_supports, states);
        target.draw(*m_fenetres, states);
*/


    /*
     // On dessine le gadgets de l'interface
    for (auto enfant : m_bureau )
        target.draw(*enfant, states);
            // On dessine le gadgets de l'interface
//    for (auto enfant : m_supports )
//        target.draw(*enfant, states);
            // On dessine le gadgets de l'interface
    for (auto enfant : m_fenetres )
        target.draw(*enfant, states);
*/




}


} // fin namespace
