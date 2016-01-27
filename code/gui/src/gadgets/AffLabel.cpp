/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <AffLabel.h>

#include <iostream>

namespace gui {

/////////////////////////////////////////////////
AffLabel::AffLabel ()
: Affiche()
, m_texte       ( std::shared_ptr<sf::Text> ( new sf::Text () ) )
, m_police      ( sf::Font ())
, m_couleur     ( sf::Color ( 255 , 255 , 255 , 255 ))
, m_taille      ( 12 )
{
    std::cout << " Creation Label\n";
    // Police par défaut
    m_police.loadFromFile( "media/polices/arial.ttf" ) ;


    std::cout << " Creation Label 1\n";
    // Actualiser
    actualiser( sf::seconds(0));
    std::cout << " Creation Label FIN\n";
}

void AffLabel::setTexte( std::string val )
{
    m_texte->setString( val );
}

/////////////////////////////////////////////////
void AffLabel::initialiser_composants ()
{

}


/////////////////////////////////////////////////
void AffLabel::actualiser ( sf::Time delta )
{

    std::cout << "AffLabel::actualiser()\n";
/*
    m_texte->setFont ( m_police );
    m_texte->setColor ( m_couleur );
    m_texte->setCharacterSize  ( m_taille );*/
}


/////////////////////////////////////////////////
void AffLabel::draw (sf::RenderTarget& target, sf::RenderStates states) const
{
    // On applique la transformation du gadget.
    states.transform *= getTransform();

    // On dessine le texte
    target.draw ( *m_texte , states );

}


} // fin namespace gui

