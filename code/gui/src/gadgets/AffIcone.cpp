/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <AffIcone.h>



namespace gui {

/////////////////////////////////////////////////
AffIcone::AffIcone ()
: AffImage ()
, m_index ( 1 )
{

}




/////////////////////////////////////////////////
void AffIcone::actualiser ()
{

    int longueurTotal = m_texture->getSize().x;
    int largeur = m_texture->getSize().y;
    m_taille = { largeur , largeur };

    m_rectangle.setTextureRect ( { ( m_index-1) * largeur
                                 , 0
                                 , largeur
                                 , largeur } );

    m_rectangle.setTexture( m_texture );
    m_rectangle.setSize ( { largeur , largeur } );

    if ( m_skin == nullptr ) {

        m_rectangle.setFillColor        ( sf::Color ( 255, 255, 255, 255 * m_opacite ) );
        m_rectangle.setOutlineColor     ( sf::Color ( 255, 255, 255, 255 * m_opacite ) );
        m_rectangle.setOutlineThickness ( 0 );

    } else {

        auto style = m_skin->getStyle( Skin::Styles::img );

        m_rectangle.setFillColor        ( sf::Color (
                                          style->fnd_couleur.repos.r
                                        , style->fnd_couleur.repos.g
                                        , style->fnd_couleur.repos.b
                                        , style->fnd_couleur.repos.a * m_opacite ) );

        m_rectangle.setOutlineColor     ( sf::Color (
                                          style->lgn_couleur.repos.r
                                        , style->lgn_couleur.repos.g
                                        , style->lgn_couleur.repos.b
                                        , style->lgn_couleur.repos.a * m_opacite ) );

        m_rectangle.setOutlineThickness ( style->lgn_epaisseur.repos ) ;

    }
    actualiser_bounds();
}


} // fin namespace gui

