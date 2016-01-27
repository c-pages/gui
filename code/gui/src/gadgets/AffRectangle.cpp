/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <AffRectangle.h>

#include <iostream>

namespace gui {

/////////////////////////////////////////////////
AffRectangle::AffRectangle ()
: Affiche()
, m_rectangle   ( std::shared_ptr<sf::RectangleShape> (new sf::RectangleShape ( )) )
, m_couleur     ( sf::Color ( 200 , 100 , 100 , 150 ) )
, m_cadreTaille ( 1 )
, m_cadreCouleur( sf::Color ( 255 , 255 , 255 , 200 ) )
{

    // Actualiser
    actualiser( sf::seconds(0));

}


/////////////////////////////////////////////////
void AffRectangle::actualiser( sf::Time delta )
{

    std::cout << "AffRectangle::actualiser()\n";

    m_rectangle->setSize (  m_taille );
    m_rectangle->setFillColor ( m_couleur );
    m_rectangle->setOutlineColor ( m_cadreCouleur );
    m_rectangle->setOutlineThickness ( m_cadreTaille );
}


/////////////////////////////////////////////////
void AffRectangle::initialiser_composants ()
{

}


/////////////////////////////////////////////////
void AffRectangle::draw (sf::RenderTarget& target, sf::RenderStates states) const
{

    // On applique la transformation du gadget.
    states.transform *= getTransform();

    // On dessine le rectangle
    target.draw( *m_rectangle , states );

}


} // fin namespace gui

