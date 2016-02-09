/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <AffLabel.h>

#include <iostream>

namespace gui {

/////////////////////////////////////////////////
AffLabel::AffLabel  ( )
: Affiche           ( )
, m_label           ( std::make_shared<sf::Text> ( ) )
, m_labelPolice     ( )
, m_labelCouleur    ( sf::Color ( 255 , 255 , 255 , 255 ))
, m_labelTaille     ( 12 )
{
    std::cout << " Creation Label\n";
    // Police par défaut

    m_labelPolice.loadFromFile( "media/polices/arial.ttf" ) ;


    std::cout << " Creation Label 1\n";
    // Actualiser
    actualiser( sf::seconds(0));
    std::cout << " Creation Label FIN\n";
}

void AffLabel::setTexte( std::string val )
{
    m_texte = val;
    m_label->setString( val );
}

/////////////////////////////////////////////////
void AffLabel::initialiser_composants ()
{

}


/////////////////////////////////////////////////
void AffLabel::actualiser ( sf::Time delta )
{

    m_label->setFont ( m_labelPolice );
    m_label->setColor ( m_labelCouleur );
    m_label->setCharacterSize  ( m_labelTaille );

}


/////////////////////////////////////////////////
void AffLabel::draw (sf::RenderTarget& target, sf::RenderStates states) const
{

    // On applique la transformation du gadget.
    states.transform *= getTransform();

    // On dessine le texte
    target.draw ( *m_label , states );

}


/////////////////////////////////////////////////
sf::Vector2f    AffLabel::getTaille() const
{
//    sf::Text popo;
    sf::FloatRect taille = m_label->getGlobalBounds( );

    return {taille.width , taille.height };
}



} // fin namespace gui

