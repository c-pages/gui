/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <AffLabel.h>



namespace gui {

/////////////////////////////////////////////////
AffLabel::AffLabel ()
: m_texte       ( "Label" )
, m_texteSFML   ( std::make_shared<sf::Text> () )
//, m_texteTaille ( 0 )
//, m_police      ( nullptr )
, m_police      (  )
{
    m_texteSFML->setString  ( m_texte );
    m_police.loadFromFile( "media/polices/arial.ttf");

    m_texteSFML->setFont    ( m_police );

    actualiser ();
}

/////////////////////////////////////////////////
void AffLabel::setStyle ( std::shared_ptr<Style> style , Etat etat ){
/*
    m_style = style;

    m_texteSFML->setColor           ( m_style->txt_couleur.get(etat) );

//    m_texteSFML->setStyle           ( m_style->txt_style.get(etat) );

    m_texteSFML->setFont            ( m_style->txt_police.get(etat) );
    if ( m_texteTaille != 0 )
        m_texteSFML->setCharacterSize   ( m_texteTaille );
    else
        m_texteSFML->setCharacterSize   ( style->txt_taille.get(etat) );

        */
        m_style = style;
        m_police = style->txt_police.get(etat);

        m_texteSFML->setColor           ( style->txt_couleur.get(etat) );
        m_texteSFML->setStyle           ( style->txt_style.get(etat) );
        m_texteSFML->setFont            ( style->txt_police.get(etat) );
//        if ( m_texteTaille != 0 )
//            m_texteSFML->setCharacterSize   ( m_texteTaille );
//        else
        m_texteSFML->setCharacterSize   ( style->txt_taille.get(etat) );

        m_texteSFML->setFont    ( m_police );
        m_texteSFML->setString  ( m_texte );
}



/////////////////////////////////////////////////
void AffLabel::actualiser ()
{
    m_texteSFML = std::make_shared<sf::Text> ();

    if( m_style != nullptr)
    {
        m_police = m_style->txt_police.get(Etat::repos);
        m_texteSFML->setColor           ( m_style->txt_couleur.get(Etat::repos) );
        m_texteSFML->setStyle           ( m_style->txt_style.get(Etat::repos) );
        m_texteSFML->setFont            ( m_style->txt_police.get(Etat::repos) );

        m_texteSFML->setCharacterSize   ( m_style->txt_taille.get(Etat::repos) );

    }

    m_texteSFML->setFont    ( m_police );
    m_texteSFML->setString  ( m_texte );
}

/////////////////////////////////////////////////
sf::Vector2f  AffLabel::getTaille() const
{
    return { m_texteSFML->getGlobalBounds().width , m_texteSFML->getGlobalBounds().height};
}




/////////////////////////////////////////////////
void AffLabel::draw (sf::RenderTarget& target, sf::RenderStates states) const
{
//    std::cout << "DEssiner LABEL : " << m_texte << "\n";

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

