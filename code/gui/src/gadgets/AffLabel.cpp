/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <AffLabel.h>



namespace gui {

/////////////////////////////////////////////////
AffLabel::AffLabel ()
: m_texteSFML   ( std::make_shared<sf::Text> () )
, m_textCouleur ( sf::Color::White )
, m_textStyle   ( sf::Text::Style::Regular )
, m_textTaille  ( 9 )
, m_textPolice  ( )
{
    m_texte       = "Label" ;

    ///<\todo gerer la police par defaut facon RAII
    // ?!? Police par defaut ?!?
    m_textPolice.loadFromFile("media/polices/arial.ttf");

    m_texteSFML->setFont ( m_textPolice );

    actualiser ();
}
/*
/////////////////////////////////////////////////
void AffLabel::setStyle ( std::shared_ptr<Style> style , Etat etat ){

//    std::cout << "AffLabel::setStyle " << style->txt_taille.get( etat ) << " / " <<  int(etat) << "\n";

    m_textCouleur   =   style->txt_couleur.get( etat );
    m_textStyle     =   style->txt_style.get( etat );
    m_textTaille    =   style->txt_taille.get( etat );
    m_textPolice    =   style->txt_police.get( etat );

    actualiser ();

}
*/

/////////////////////////////////////////////////
void AffLabel::actualiserGeometrie ()
{
    m_texteSFML->setString  ( m_texte );
//    m_texteSFML->setPosition ( -m_texteSFML->getGlobalBounds().left , -m_texteSFML->getGlobalBounds().top );


    actualiserBounds();
}

/////////////////////////////////////////////////
void AffLabel::actualiserStyle ()
{
    m_texteSFML->setColor           ( m_textCouleur );
    m_texteSFML->setStyle           ( m_textStyle );
    m_texteSFML->setCharacterSize   ( m_textTaille );
    m_texteSFML->setFont            ( m_textPolice );
}

/////////////////////////////////////////////////
sf::Vector2i  AffLabel::getTaille() const
{
    return { m_texteSFML->getGlobalBounds().width , m_texteSFML->getGlobalBounds().height };
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

