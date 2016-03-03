/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <AffIcone.h>
#include <cmath>



namespace gui {

/////////////////////////////////////////////////
AffIcone::AffIcone ()
: AffImage ()
, m_index ( 1 )
, m_nbrIcones (0)
{

}




/////////////////////////////////////////////////
void AffIcone::actualiser ()
{
    if ( ! m_necessiteActualisation )
        return;

    int longueurTotal = m_texture->getSize().x;
    int largeur = m_texture->getSize().y;

//    if (largeur!=0)
//    m_nbrIcones = std::trunc (longueurTotal / largeur );

//    if ( m_index > m_nbrIcones )
//        m_index = m_nbrIcones;

    m_taille = { largeur , largeur };
//    std::cout << "AffIcone::actualiser : " << getNom() << "  m_index : " <<  m_index << "\n";
    m_rectangle.setTextureRect ( { ( m_index-1) * largeur
                                 , 0
                                 , largeur
                                 , largeur } );

    m_rectangle.setTexture( m_texture );
    m_rectangle.setSize ( { largeur , largeur } );

    if ( m_skin == nullptr ) {

        m_rectangle.setFillColor        ( sf::Color ( 255, 255, 255, 255 * m_opacite ) );
//        m_rectangle.setOutlineColor     ( sf::Color ( 255, 255, 255, 255 * m_opacite ) );
        m_rectangle.setOutlineThickness ( 0 );

    } else {

        auto style = m_skin->getStyle( Styles::img );

        m_rectangle.setFillColor        ( sf::Color (
                                          style->fnd_couleur.repos.r
                                        , style->fnd_couleur.repos.g
                                        , style->fnd_couleur.repos.b
                                        , style->fnd_couleur.repos.a * m_opacite ) );

//        m_rectangle.setOutlineColor     ( sf::Color (
//                                          style->lgn_couleur.repos.r
//                                        , style->lgn_couleur.repos.g
//                                        , style->lgn_couleur.repos.b
//                                        , style->lgn_couleur.repos.a * m_opacite ) );

//        m_rectangle.setOutlineThickness ( style->lgn_epaisseur.repos ) ;
        m_rectangle.setOutlineThickness ( 0 );

    }
    //actualiser_bounds();
    m_necessiteActualisation = false;
}


} // fin namespace gui

