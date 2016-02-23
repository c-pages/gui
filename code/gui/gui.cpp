#include "gui.h"


#include <iostream>


namespace gui {

/////////////////////////////////////////////////
// Initialisation des membre static
/////////////////////////////////////////////////
Gadget * Gadget::ms_racineCourante = nullptr;


/////////////////////////////////////////////////
Interface::Interface( sf::RenderWindow* fenetre )
:Gadget ()
, m_boutonSurvole   ( nullptr )
, m_boutonPresse    ( nullptr )
{
    std::cout << "Interface : creation AVEC fenetre en param.\n";
    m_fenetre = fenetre;
    Gadget::ms_racineCourante = this;
}

/////////////////////////////////////////////////
std::shared_ptr<Gadget> Interface::chercherGadgetSurvole ()
{
//    std::cout << "Interface : chercher Gadget Survole\n";
    std::shared_ptr<Gadget> resultat = nullptr;
    for (auto enfant : m_enfants )
    {
        if ( enfant->testerSurvol ( sf::Mouse::getPosition( *m_fenetre ) ))
            resultat = enfant;
    }


    return resultat;

}

/////////////////////////////////////////////////
void Interface::traiterEvenements( sf::Event evenement )
{
    //std::cout << "Interface : traitement de evenements\n";

    // les evenements 'clavier' de l'interface
    traiterEvenementsClavier ( evenement );

    // les evenements 'souris' de l'interface
    auto boutonSurvoleBack = m_boutonSurvole;
    m_boutonSurvole = chercherGadgetSurvole ();

//    if ( m_boutonSurvole != nullptr )
//            std::cout << "Interface : on a un SURVOL\n";


    // en fonction du type d'événement...
    switch ( evenement.type ){

        ///////// Deplacement souris /////////////////////////////////////////
        case sf::Event::MouseMoved :

            // On sort si on a changer bouton survolé
            if ( m_boutonSurvole ==  boutonSurvoleBack )
                return;

            //
            if (m_boutonSurvole!=nullptr) {
                m_boutonSurvole->setSurvol( true );
                m_boutonSurvole->declencher ( Evenement::on_entrer );
            }
            if (boutonSurvoleBack!=nullptr){
                boutonSurvoleBack->setSurvol( false );
                boutonSurvoleBack->declencher ( Evenement::on_sortir );
            }
        break;

        ///////// Presser bouton souris /////////////////////////////////////////
        case sf::Event::MouseButtonPressed:
            // On sort si on a pas de bouton survolé
            if ( m_boutonSurvole ==  nullptr )
                return;

            //
            m_boutonPresse = m_boutonSurvole;
            m_boutonPresse->setPresse( true );
        break;

        ///////// Relacher bouton souris /////////////////////////////////////////
        case sf::Event::MouseButtonReleased:

            if ( m_boutonPresse ==  nullptr )
                return;

            // On sort si on a pas de bouton survolé
            if ( m_boutonSurvole ==  nullptr ){
                if ( m_boutonPresse != nullptr ) {
                    m_boutonPresse->setPresse ( false );
                    m_boutonPresse = nullptr;
                }
                return;
            }

            // Si on est plus sur le bouton cliqué
            if ( m_boutonPresse != m_boutonSurvole ){
                // on declenche l'action
                m_boutonPresse->declencher ( Evenement::onBtnG_relacherDehors );
                // et on sort
                return;
            }
//
//            std::cout << "Interface : declencher\n";
            //On déclenche l'action
            m_boutonPresse->declencher ( Evenement::onBtnG_relacher );
            m_boutonPresse->setPresse( false );
            m_boutonPresse = nullptr;
        break;

        ///////// on ne traite pas les autres types d'évènements /////////////////////////////////////////
        default: break;

    }

    /*
    for (auto enfant : m_enfants )
    {
        target.draw(*enfant, states);
    }
    */
}


/////////////////////////////////////////////////
void Interface::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (auto enfant : m_enfants )
    {
        target.draw(*enfant, states);
    }
}


} // fin namespace
