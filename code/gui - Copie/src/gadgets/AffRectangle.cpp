/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <AffRectangle.h>
#include <Skin.h>



namespace gui {

/////////////////////////////////////////////////
AffRectangle::AffRectangle ( sf::Vector2i taille )
: m_rectangle       ( std::make_shared<sf::RectangleShape>() )
, m_couleurFond     ( sf::Color(0,0,255,255) )
, m_couleurLignes   ( sf::Color(0,0,255,60) )
, m_epaisseur       ( 1 )
{
    m_taille = taille;
    actualiser ();
}

/////////////////////////////////////////////////
void AffRectangle::actualiser_geometrie ()
{
    m_rectangle->setSize ( { m_taille.x, m_taille.y } );
}

/////////////////////////////////////////////////
void AffRectangle::actualiser_style ()
{
    m_rectangle->setFillColor    ( m_couleurFond );
    m_rectangle->setOutlineColor ( m_couleurLignes );
    m_rectangle->setOutlineColor ( m_couleurLignes );
}


/////////////////////////////////////////////////
void AffRectangle::draw (sf::RenderTarget& target, sf::RenderStates states) const
{
    //On applique la transformation
    states.transform *= getTransform();

    // On dessine le rectangle
    target.draw( *m_rectangle, states);
}




} // fin namespace gui

