/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <AffRectangle.h>
//#include <Skin.h>



namespace gui {

/////////////////////////////////////////////////
AffRectangle::AffRectangle ( sf::Vector2i taille )
: m_rectangle       ( )
, m_couleurFond     ( sf::Color(0,0,255,255) )
, m_couleurLignes   ( sf::Color(0,0,255,200) )
, m_epaisseur       ( 1 )
{
    m_taille = taille;
    actualiser ();
}
/*
/////////////////////////////////////////////////
void AffRectangle::setStyle ( std::shared_ptr<Style> style , Etat etat )
{
    m_couleurFond       = style->fnd_couleur.get( etat );
    m_couleurLignes     = style->lgn_couleur.get( etat );
    m_epaisseur         = style->lgn_epaisseur.get( etat );

    actualiserStyle ();
}
*/


/////////////////////////////////////////////////
void AffRectangle::actualiserGeometrie ()
{
    m_rectangle.setSize ( { m_taille.x, m_taille.y } );
}

/////////////////////////////////////////////////
void AffRectangle::actualiserStyle ()
{
    m_rectangle.setFillColor        ( m_couleurFond );
    m_rectangle.setOutlineColor     ( m_couleurLignes );
    m_rectangle.setOutlineThickness ( m_epaisseur );
}


/////////////////////////////////////////////////
void AffRectangle::draw (sf::RenderTarget& target, sf::RenderStates states) const
{
    //On applique la transformation
    states.transform *= getTransform();

    // On dessine le rectangle
    if (estVisible())
        target.draw(m_rectangle, states);
}




} // fin namespace gui

