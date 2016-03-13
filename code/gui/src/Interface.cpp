#include "Interface.h"
#include "Interface.h"


#include <iostream>


namespace gui {


sf::RenderWindow*                           Interface::ms_fenetreSFML = nullptr;
ResourcesMgr<sf::Font,std::string >         Interface::ms_polices = {};
ResourcesMgr<sf::Texture,   std::string >   Interface::ms_images = {};
ResourcesMgr<sf::Texture,   std::string >   Interface::ms_curseurs = {};
ResourcesMgr<sf::Texture,   std::string >   Interface::ms_icones = {};


std::shared_ptr<Calque>        Interface::ms_calque_bureau          = std::make_shared<Calque>();
std::shared_ptr<Calque>        Interface::ms_calque_fenetres        = std::make_shared<Calque>();
std::shared_ptr<Calque>        Interface::ms_calque_bandeaux        = std::make_shared<Calque>();
std::shared_ptr<Calque>        Interface::ms_calque_panneau_G        = std::make_shared<Calque>();
std::shared_ptr<Calque>        Interface::ms_calque_panneau_D        = std::make_shared<Calque>();
std::shared_ptr<Calque>        Interface::ms_calque_bandeauMenuDeroulants  = std::make_shared<Calque>();
std::shared_ptr<Calque>        Interface::ms_calque_menuDeroulants  = std::make_shared<Calque>();
//
std::shared_ptr<AffCurseurSouris>       Interface::ms_curseurSouris;



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

    // les tailles
//    m_taille = { m_fenetre->getSize().x ,m_fenetre->getSize().y };
    m_taille = { 1920 , 1080 };
    ms_calque_bureau->setTaille    ( m_taille );
    ms_calque_bandeaux->setTaille  ( m_taille );
    ms_calque_panneau_G->setTaille  ( m_taille );
    ms_calque_panneau_D->setTaille  ( m_taille );
    ms_calque_fenetres->setTaille  ( m_taille );
    ms_calque_menuDeroulants->setTaille  ( m_taille );
    ms_calque_bandeauMenuDeroulants->setTaille  ( m_taille );




    // initialiser les polices
    ms_polices.load( "Defaut"  , "media/polices/consola.ttf" );

    // initialiser les icones
    ms_icones.load( "ico_fenetre"  , "media/img/icones_fenetre.png" );
    ms_icones.load( "ico_fleches"  , "media/img/ico_fleches.png" );


    // initialiser les curseurs
    ms_curseurSouris = std::make_shared<AffCurseurSouris>( this );
    ms_curseurs.load( "Redimensionnement"  , "media/img/curs_redimensionnement.png" );

    m_parent = nullptr;

}

/////////////////////////////////////////////////
std::shared_ptr<Gadget> Interface::chercherGadgetSurvole ()
{
//    std::cout << "Interface : chercher Gadget Survole\n";

    sf::Vector2i posSouris = sf::Mouse::getPosition( *m_fenetre );

    for (int i=m_enfants.size()-1; i>=0; i-- )    {
            auto enfant = m_enfants[i];
//    for (auto gadget : m_enfants )    {
        std::shared_ptr<Gadget> result = enfant->testerSurvol ( posSouris );
        if ( result != nullptr )
            return result;
    }

    return nullptr;
}


/////////////////////////////////////////////////
void Interface::actualiser ()
{
    if ( ! m_aBesoinActualisation ) return;

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
    // ... pour d�caller le calque du bureau ... � voir si c'est pas le bordel
    ms_calque_bureau->setPosition ( decallage.x , decallage.y );
    decallage.x = 0;
    for ( std::shared_ptr<Gadget> panneau : ms_calque_panneau_D->getEnfants() )
    {

        decallage.x += panneau->getTaille().x;
        panneau->setPosition ( m_fenetre->getSize().x -  decallage.x , decallage.y );
        //panneau->setTailleX ( 250 );
        panneau->setTailleY ( m_fenetre->getSize().y - decallage.y );

    }
    m_aBesoinActualisation = false;
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

    Gadget::traiterEvenements ( evenement);

    //////////////////////////////////////////
    // les evenements 'souris' de l'interface
    //////////////////////////////////////////
    auto boutonSurvoleBack = m_boutonSurvole;
    m_boutonSurvole = chercherGadgetSurvole ();



//    auto posSouris = sf::Mouse::getPosition();
//
//    sf::FloatRect  BBFenetre = sf::FloatRect ( m_fenetre->getPosition().x , m_fenetre->getPosition().y , m_fenetre->getSize().x , m_fenetre->getSize().y );
//        std::cout << " BBFenetre : "  <<  BBFenetre.left << ", " << BBFenetre.top << ", " << BBFenetre.width <<", " << BBFenetre.height << "\n";
//        std::cout << " posSouris : "  <<  posSouris.x << ", " << posSouris.y << "\n";
//
//    if ( ! BBFenetre.contains( posSouris.x , posSouris.y ) )
//    {
//        std::cout << " O N S O R T D E L A F E N E T R E \n";
//        declencherToutBoutons ( Evenement::onBtnD_relacherDehors );
//        declencherToutBoutons ( Evenement::onBtnG_relacherDehors );
//        return;
//    }




    switch ( evenement.type ){
        ///////// Deplacement souris /////////////////////////////////////////
        case sf::Event::MouseMoved :

            // On gere le cureur souris
            if (ms_curseurSouris->estVisible())
                ms_curseurSouris->traiterEvenements( evenement );

            // On sort si on a pas changer de bouton survol�
            if ( m_boutonSurvole ==  boutonSurvoleBack )
                return;

            if (m_boutonPresse == nullptr )
            {

                // on g�re le gadget anciennement survol�
                if (boutonSurvoleBack!=nullptr){
//                        std::cout << "--------> boutonSurvoleBack : " << boutonSurvoleBack->getNom() << "\n";
                    boutonSurvoleBack->setSurvol( false );
                    boutonSurvoleBack->declencher ( Evenement::on_sortir );
                }
                // on g�re le gadget survol�
                if (m_boutonSurvole != nullptr) {
//                        std::cout << "--------> m_boutonSurvole : " << m_boutonSurvole->getNom() << "\n";
                    m_boutonSurvole->setSurvol( true );
                    m_boutonSurvole->declencher ( Evenement::on_entrer );
                }
            } else {
                // on g�re le gadget survol�
                /*if (m_boutonSurvole==nullptr){
                    boutonSurvoleBack->setSurvol( false );
                    boutonSurvoleBack->declencher ( Evenement::on_sortir );
                }*/
                /*if (m_boutonSurvole != m_boutonPresse ) {
                }*/
                // on g�re le gadget anciennement survol�*/

            }
        break;

        ///////// Presser bouton souris /////////////////////////////////////////
        case sf::Event::MouseButtonPressed:

            // On sort si on a pas de bouton survol�
            if ( m_boutonSurvole ==  nullptr )
                return;

            // on definie le bouton presss�
            m_boutonPresse = m_boutonSurvole;

            // On d�clenche l'action en fonction du bouton de la souris
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

                // on reset le bouton press�
                if ( m_boutonPresse !=  nullptr ){
                    m_boutonPresse->setSurvol( false );
                    m_boutonPresse->setPresse( false );
                    m_boutonPresse = nullptr;
                }

                // On sort.
                return;
            }

            // on survol un autre bouton que celui press�.
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

                // on reset le bouton press�
                if ( m_boutonPresse !=  nullptr ){
                    m_boutonPresse->setSurvol( false );
                    m_boutonPresse->setPresse( false );
                    m_boutonPresse = nullptr;
                }
                // On sort.
                return;
            }


            // On survol le bouton qu'on � press�.
            // => On d�clenche l'action 'relacher'
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


            // on reset m_boutonPress�
            m_boutonPresse->setPresse( false );
            m_boutonPresse = nullptr;

        break;

        ///////// Presser roulette souris /////////////////////////////////////////
        case sf::Event::MouseWheelMoved :

            // Si on survole un bouton
            if ( m_boutonSurvole != nullptr ){

                // On d�clenche l'action en fonction
                if ( evenement.mouseWheel.delta > 0 )
                    m_boutonSurvole->declencher ( Evenement::onBtnM_roulerHaut );
                else
                    m_boutonSurvole->declencher ( Evenement::onBtnM_roulerBas );
            }

        break;

        ///////// on ne traite pas les autres types d'�v�nements /////////////////////////////////////////
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

    // on dessine la souris (si besoin)
    if (ms_curseurSouris->estVisible() )
        target.draw(*ms_curseurSouris, states);

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
