/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <AffRectangle.h>
#include <Skin.h>



namespace gui {

/////////////////////////////////////////////////
AffRectangle::AffRectangle ( sf::Vector2i taille )
: m_rectangle()
{
    m_taille = taille;
    actualiser ();
}


/////////////////////////////////////////////////
void AffRectangle::actualiser ()
{
    m_rectangle.setSize ( {m_taille.x, m_taille.y} );

    if ( m_skin == nullptr ) {
        m_rectangle.setFillColor        ( sf::Color (   0,   0, 255, 150 * m_opacite ) );
        m_rectangle.setOutlineColor     ( sf::Color ( 255, 255, 255, 255 * m_opacite ) );
        m_rectangle.setOutlineThickness ( 1 );
    } else {

        auto style = m_skin->fondRepos;

        m_rectangle.setFillColor        ( sf::Color (
                                          style->fnd_couleur.r
                                        , style->fnd_couleur.g
                                        , style->fnd_couleur.b
                                        , style->fnd_couleur.a * m_opacite ) ) ;

        m_rectangle.setOutlineColor     ( sf::Color (
                                          style->lgn_couleur.r
                                        , style->lgn_couleur.g
                                        , style->lgn_couleur.b
                                        , style->lgn_couleur.a * m_opacite ) ) ;

        m_rectangle.setOutlineThickness ( style->lgn_epaisseur ) ;

    }

}

/////////////////////////////////////////////////
void AffRectangle::draw (sf::RenderTarget& target, sf::RenderStates states) const
{
    //On applique la transformation
    states.transform *= getTransform();

    // On dessine le rectangle
    target.draw(m_rectangle, states);
}




} // fin namespace gui

