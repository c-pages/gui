/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <AffImage.h>

#include <iostream>


namespace gui {

/////////////////////////////////////////////////
AffImage::AffImage ()
: Affiche()
//, m_rectangle   ( std::make_shared<sf::RectangleShape> ( new sf::RectangleShape ( {0,0 }) ))
//, m_texture     ( std::make_shared<sf::Texture> ( new sf::Texture () ) )
{

    std::cout << "Creation AffImage ( )\n";
    // Actualiser
    actualiser( sf::seconds(0));

}


/////////////////////////////////////////////////
void AffImage::actualiser( sf::Time delta )
{
    std::cout << "AffImage::actualiser()\n";

//    m_rectangle->setSize (  m_taille );
}


/////////////////////////////////////////////////
void AffImage::initialiser_composants ()
{

}


/////////////////////////////////////////////////
void AffImage::draw (sf::RenderTarget& target, sf::RenderStates states) const
{

    // On applique la transformation du gadget.
    states.transform *= getTransform();

    // Ondessine le rectangle s'il à une texture
    if ( m_texture!=nullptr )
        target.draw( *m_rectangle , states );

}


} // fin namespace gui

