/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <AffLabel.h>



namespace gui {

/////////////////////////////////////////////////
AffLabel::AffLabel ()
: m_texte       ( "Label" )
, m_texteSFML   ( std::make_shared<sf::Text> () )
, m_texteTaille ( 10 )
, m_police      ( )
{
    actualiser ();
}

/////////////////////////////////////////////////
void AffLabel::actualiser ()
{

    if ( m_skin == nullptr ) {

        m_police.loadFromFile           ( "media/polices/arial.ttf" );
        m_texteSFML->setColor           ( sf::Color ( 250 , 250 , 250 , 150 ) );
        m_texteSFML->setCharacterSize   ( 20 );


    } else {

        auto style = m_skin->txtCourant;
        m_police = style->txt_police ;
        m_texteSFML->setColor           ( style->txt_couleur );
        m_texteSFML->setCharacterSize   ( style->txt_taille );

    }

    m_texteSFML->setFont    ( m_police );
    m_texteSFML->setString  ( m_texte );
}


/////////////////////////////////////////////////
void AffLabel::draw (sf::RenderTarget& target, sf::RenderStates states) const
{
    //On applique la transformation
    states.transform *= getTransform();

    // On dessine le texte
    target.draw( *m_texteSFML, states);
}


/////////////////////////////////////////////////
void AffLabel::setPoliceFichier (sf::Font police)
{

}


} // fin namespace gui

