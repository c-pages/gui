/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <AffImage.h>

#include <iostream>

namespace gui {

/////////////////////////////////////////////////
AffImage::AffImage ()
: m_texture     ( new sf::Texture() )
, m_rectangle   ( )
, m_ajustement  ( false )
{
    m_texture->setRepeated  ( true );
    m_texture->setSmooth    ( true );

    m_rectangle.setTexture( m_texture );
}

/////////////////////////////////////////////////
void AffImage::chargerDepuisFichier ( std::string fichier )
{

    if ( ! m_texture->loadFromFile ( fichier ) )
            std::cout << "\n ! ATTENTION ! - Image: Impossible de charger '" << fichier << "' !\n\n";
//    else    std::cout << "Image: Chargement de '" << fichier << "' reussi.\n";

    m_rectangle.setTexture( m_texture );
//    m_taille = { m_texture->getSize().x , m_texture->getSize().y };
    m_rectangle.setTextureRect ( { 0
                                 , 0
                                 , m_texture->getSize().x
                                 , m_texture->getSize().y });
    actualiser ();

}

/////////////////////////////////////////////////
void AffImage::actualiser ()
{
//    std::cout << "Tmage: Texture -> " << m_rectangle.getTextureRect().width << "\n";
//
//    m_texture->setRepeated( true );
//m_rectangle.getTextureRect()
    m_rectangle.setSize ( { m_taille.x , m_taille.y } );
    m_rectangle.setTexture( m_texture );

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


//    auto texture = m_sprite.getTexture();
//    m_sprite.
    //texture->setRepeated( true );

//     if ( m_skin == nullptr ) {
//        m_sprite.setColor        ( sf::Color ( 255, 255, 255, 255 * m_opacite ) );
//    } else {
//        auto style = m_skin->imgRepos;
//        m_sprite.setColor   ( sf::Color ( style->fnd_couleur.r
//                                        , style->fnd_couleur.g
//                                        , style->fnd_couleur.b
//                                        , style->fnd_couleur.a * m_opacite ) ) ;
//    }
}


/////////////////////////////////////////////////
void AffImage::draw (sf::RenderTarget& target, sf::RenderStates states) const
{
    //On applique la transformation
    states.transform *= getTransform();

    // On dessine l'image
//    target.draw( m_sprite, states);
    target.draw( m_rectangle, states);
}


} // fin namespace gui

