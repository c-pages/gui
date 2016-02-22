/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Interaction.h>



namespace gui {

/////////////////////////////////////////////////
void Interaction::lier  (Evenement evenement, FctnAction fonction)
{
    m_evenementsSouris.insert( { evenement , fonction } );
}


/////////////////////////////////////////////////
void Interaction::lier ( sf::Keyboard::Key  touche, FctnAction fonction)
{
    m_evenementsClavier.insert( { touche  , fonction } );
}


/////////////////////////////////////////////////
void Interaction::delier (Evenement evenement)
{

}


/////////////////////////////////////////////////
void Interaction::delier ( sf::Keyboard::Key  touche)
{

}


/////////////////////////////////////////////////
void Interaction::declencher (Evenement evenement)
{

}

/////////////////////////////////////////////////
void Interaction::traiter_evenements_clavier   (const sf::Event& event)
{
    if ( event.type == sf::Event::KeyReleased )
        for ( auto evt : m_evenementsClavier )
            if (event.key.code == evt.first)
                evt.second();
}

} // fin namespace gui

