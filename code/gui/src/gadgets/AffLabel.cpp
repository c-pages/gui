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

    //m_texteTaille

    // On choisi le style
    std::shared_ptr<Style> style = nullptr;

    if ( m_style != nullptr )
    {
//        std::cout << " ->Style 1\n";
        style = m_style;
    }
    else if ( m_skin != nullptr )
    {
//        std::cout << " ->Style 2\n";
        style = m_skin->txtCourant;
    }
    else {
        // par defaut
        style = std::make_shared<Style>();
        style->txt_police.loadFromFile           ( "media/polices/consola.ttf" );
        style->txt_couleur =  sf::Color ( 250 , 250 , 250 , 150 ) ;
    }

    style->txt_taille  = m_texteTaille;

    // on l'applique
    m_police = style->txt_police ;
    m_texteSFML->setColor           ( style->txt_couleur );
    m_texteSFML->setCharacterSize   ( m_texteTaille );


    m_texteSFML->setFont    ( m_police );
    m_texteSFML->setString  ( m_texte );
}

/////////////////////////////////////////////////
sf::Vector2i  AffLabel::getTaille() const
{
    return { m_texteSFML->getGlobalBounds().width , m_texteSFML->getGlobalBounds().height};
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

