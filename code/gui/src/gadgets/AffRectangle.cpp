/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <AffRectangle.h>
#include <Skin.h>



namespace gui {

/////////////////////////////////////////////////
AffRectangle::AffRectangle ( sf::Vector2i taille )
: m_rectangle()
, m_couleurFond(nullptr)
, m_couleurLignes(nullptr)
, m_epaisseur(nullptr)
{
    m_taille = taille;
    actualiser ();
}


/////////////////////////////////////////////////
void AffRectangle::actualiser ()
{
//    std::cout << "ACTUALISER AFFRECTANGLE_H\n";

    m_rectangle.setSize ( { m_taille.x, m_taille.y } );

    // On choisi le style adéquate ...

    std::shared_ptr<Style> style = nullptr;
    if ( m_style != nullptr )
        style = m_style;
    else
        style = m_skin->getStyle ( Styles::fond );

    if ( m_couleurFond == nullptr)
        m_rectangle.setFillColor    ( sf::Color (
                                      style->fnd_couleur.repos.r
                                    , style->fnd_couleur.repos.g
                                    , style->fnd_couleur.repos.b
                                    , style->fnd_couleur.repos.a * m_opacite ) );
    else m_rectangle.setFillColor    ( *m_couleurFond );

    if ( m_couleurLignes == nullptr)
        m_rectangle.setOutlineColor ( sf::Color (
                                      style->lgn_couleur.repos.r
                                    , style->lgn_couleur.repos.g
                                    , style->lgn_couleur.repos.b
                                    , style->lgn_couleur.repos.a * m_opacite ) );
    else m_rectangle.setOutlineColor    ( *m_couleurLignes );

    if ( m_epaisseur == nullptr)
        m_rectangle.setOutlineThickness ( style->lgn_epaisseur.repos );
    else m_rectangle.setOutlineThickness    ( *m_epaisseur );

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

