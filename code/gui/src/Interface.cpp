#include "Interface.h"



#include <iostream>


namespace gui {


sf::RenderWindow*                           Interface::ms_fenetreSFML = nullptr;
ResourcesMgr<sf::Font,std::string >         Interface::ms_polices = {};
ResourcesMgr<sf::Texture,   std::string >   Interface::ms_images = {};


std::shared_ptr<Calque>        Interface::ms_calque_bureau          = std::make_shared<Calque>();
std::shared_ptr<Calque>        Interface::ms_calque_fenetres        = std::make_shared<Calque>();
std::shared_ptr<Calque>        Interface::ms_calque_bandeaux        = std::make_shared<Calque>();
std::shared_ptr<Calque>        Interface::ms_calque_bandeauMenuDeroulants  = std::make_shared<Calque>();
std::shared_ptr<Calque>        Interface::ms_calque_menuDeroulants  = std::make_shared<Calque>();

/////////////////////////////////////////////////
Interface::Interface( sf::RenderWindow* fenetre )
: Gadget ()
, m_boutonSurvole   ( nullptr )
, m_boutonPresse    ( nullptr )
, m_fenetre         ( fenetre )
, creer             ( this )

//, ms_calque_bureau      ( std::make_shared<Calque>())
//, ms_calque_bandeaux    ( std::make_shared<Calque>())
//, ms_calque_fenetres    ( std::make_shared<Calque>())
{
    // la fenetre SFML
    ms_fenetreSFML = fenetre;

    // les calques
    ajouter ( ms_calque_bureau );
    ajouter ( ms_calque_bandeaux );
    ajouter ( ms_calque_bandeauMenuDeroulants );
    ajouter ( ms_calque_fenetres );
    ajouter ( ms_calque_menuDeroulants );

    // les tailles
//    m_taille = { m_fenetre->getSize().x ,m_fenetre->getSize().y };
    m_taille = { 1920 , 1080 };
    ms_calque_bureau->setTaille    ( m_taille );
    ms_calque_bandeaux->setTaille  ( m_taille );
    ms_calque_fenetres->setTaille  ( m_taille );
    ms_calque_menuDeroulants->setTaille  ( m_taille );
    ms_calque_bandeauMenuDeroulants->setTaille  ( m_taille );

    // initialiser les polices
    ms_polices.load( "Defaut"  , "media/polices/consola.ttf" );

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

    // on calcule la taille verticale des bandeaux ...
    sf::Vector2f decallage = {0,0};
    for ( auto enfant : ms_calque_bandeauMenuDeroulants->m_enfants )
    {
        enfant->setPosition (decallage.x, decallage.y);
        decallage.y += enfant->getTaille().y;
    }
    for ( auto enfant : ms_calque_bandeaux->m_enfants )
    {
        enfant->setPosition (decallage.x, decallage.y);
        decallage.y += enfant->getTaille().y;
    }

    // ... pour décaller le calque du bureau ... à voir si c'est pas le bordel
//    ms_calque_bureau->setPosition ( decallage.x , decallage.y );

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

    Gadget::traiterEvenements ( evenement);

    //////////////////////////////////////////
    // les evenements 'souris' de l'interface
    //////////////////////////////////////////
    auto boutonSurvoleBack = m_boutonSurvole;
    m_boutonSurvole = chercherGadgetSurvole ();


    switch ( evenement.type ){
        ///////// Deplacement souris /////////////////////////////////////////
        case sf::Event::MouseMoved :

            // On sort si on a pas changer de bouton survolé
            if ( m_boutonSurvole ==  boutonSurvoleBack )
                return;

            if (m_boutonPresse == nullptr )
            {

                // on gère le gadget survolé
                if (m_boutonSurvole != nullptr) {
//                        std::cout << "--------> m_boutonSurvole : " << m_boutonSurvole->getNom() << "\n";
                    m_boutonSurvole->setSurvol( true );
                    m_boutonSurvole->declencher ( Evenement::on_entrer );
                }
                // on gère le gadget anciennement survolé
                if (boutonSurvoleBack!=nullptr){
//                        std::cout << "--------> boutonSurvoleBack : " << boutonSurvoleBack->getNom() << "\n";
                    boutonSurvoleBack->setSurvol( false );
                    boutonSurvoleBack->declencher ( Evenement::on_sortir );
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
