/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <AffLabel.h>

#include <iostream>

namespace gui {

/////////////////////////////////////////////////
AffLabel::AffLabel  ( )
: Affiche           ( )
, m_label           ( )
//, m_label           ( new sf::Text())
, m_labelPolice     ( )
, m_labelCouleur    ( sf::Color ( 255 , 255 , 255 , 255 ) )
, m_labelTaille     ( 12 )
{
    std::cout << "Creation AffLabel\n";
    // Police par défaut

//    m_labelPolice.loadFromFile( "media/polices/arial.ttf" ) ;

    if (!m_labelPolice.loadFromFile( "media/polices/arial.ttf"))
    {
        std::cout << " ### Probleme de chargement de police. ###" << std::endl;
        std::exit(-1);
    } else {
        std::cout << " ### Chargement de police : OK. ###" << std::endl;

    }

    // Actualiser
    actualiser( sf::seconds(0));

}

void AffLabel::setTexte( std::string val )
{
    std::cout << "Labele : setTexte ... : ''" << val << "''\n";

    m_texte = val;

    m_label.setString( val );

    getProp();
}

/////////////////////////////////////////////////
void AffLabel::initialiser_composants ()
{

}


/////////////////////////////////////////////////
void AffLabel::actualiser ( sf::Time delta )
{

    m_label.setFont ( m_labelPolice );
    m_label.setColor ( m_labelCouleur );
    m_label.setCharacterSize  ( m_labelTaille );

}


/////////////////////////////////////////////////
void AffLabel::draw (sf::RenderTarget& target, sf::RenderStates states) const
{

    // On applique la transformation du gadget.
    states.transform *= getTransform();

    // On dessine le texte
    target.draw ( m_label , states );

}


/////////////////////////////////////////////////
sf::Vector2f    AffLabel::getTaille() const
{
//    sf::Text popo;
    sf::FloatRect taille = m_label.getGlobalBounds( );

    return { taille.width , taille.height };
}



} // fin namespace gui

