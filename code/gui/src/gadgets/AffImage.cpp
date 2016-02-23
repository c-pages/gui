/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <AffImage.h>

#include <iostream>

namespace gui {

/////////////////////////////////////////////////
AffImage::AffImage ()
: m_sprite   ( )
, m_texture     ( )
//: m_rectangle   ( std::make_shared<sf::RectangleShape> )
//, m_texture     ( std::make_shared<sf::Texture> )
{
    m_texture.setRepeated( true );
}

/////////////////////////////////////////////////
void AffImage::chargerDepuisFichier ( std::string fichier )
{

    if ( ! m_texture.loadFromFile ( fichier ) )
        std::cout << "\n ! ATTENTION ! - Image: Impossible de charger '" << fichier << "' - ! ATTENTION !\n\n";

}

/////////////////////////////////////////////////
void AffImage::actualiser ()
{

    m_texture.setRepeated( true );
    m_sprite.setTexture( m_texture );
//    auto texture = m_sprite.getTexture();
//    m_sprite.
    //texture->setRepeated( true );

     if ( m_skin == nullptr ) {
        m_sprite.setColor        ( sf::Color ( 255, 255, 255, 255 * m_opacite ) );
    } else {
        auto style = m_skin->imgRepos;
        m_sprite.setColor   ( sf::Color ( style->fnd_couleur.r
                                        , style->fnd_couleur.g
                                        , style->fnd_couleur.b
                                        , style->fnd_couleur.a * m_opacite ) ) ;
    }
}


/////////////////////////////////////////////////
void AffImage::draw (sf::RenderTarget& target, sf::RenderStates states) const
{
    //On applique la transformation
    states.transform *= getTransform();

    // On dessine l'image
    target.draw( m_sprite, states);
}


} // fin namespace gui

