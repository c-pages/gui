/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <AffRectangle.h>
#include <../GUI.h>



namespace gui {

/////////////////////////////////////////////////
AffRectangle::AffRectangle ( sf::Vector2i taille )
: m_rectangle       ( )
, m_couleurFond     ( sf::Color(0,0,255,255) )
, m_couleurLignes   ( sf::Color(0,0,255,200) )
, m_epaisseur       ( 1 )
{
    creerNomUnique ( "Rectangle");

    m_taille = taille;

}


/////////////////////////////////////////////////
void AffRectangle::actualiserGeometrie ()
{
    // Debuggage
    log ("actualiserGeometrie  ");

    m_rectangle.setSize ( { m_taille.x, m_taille.y } );

}


/////////////////////////////////////////////////
void AffRectangle::actualiserStyle ()
{
    // Debuggage
    log ("actualiserStyle  ");

    m_rectangle.setFillColor        ( m_couleurFond );
    m_rectangle.setOutlineColor     ( m_couleurLignes );
    m_rectangle.setOutlineThickness ( m_epaisseur );

}


/////////////////////////////////////////////////
void AffRectangle::setFillColor (sf::Color couleur) {
    m_couleurFond = couleur ;
    m_rectangle.setFillColor( couleur );
};


/////////////////////////////////////////////////
void AffRectangle::setOutlineColor (sf::Color couleur) {
    m_couleurLignes =  couleur;
    m_rectangle.setOutlineColor( couleur );
};


/////////////////////////////////////////////////
void AffRectangle::setOutlineThickness (float epaisseur) {
    m_epaisseur = epaisseur;
    m_rectangle.setOutlineThickness( epaisseur );
};


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




















