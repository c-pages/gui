/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <AffImage.h>
#include <Interface.h>

#include <iostream>

namespace gui {

/////////////////////////////////////////////////
AffImage::AffImage ()
: m_texture     ( new sf::Texture() )
//, m_rectangle   ( )
, m_ajustement  ( false )
{
    m_texture->setRepeated  ( true );
    m_texture->setSmooth    ( true );

    m_couleurFond   = sf::Color::White ;
    m_couleurLignes = sf::Color::White ;

    m_epaisseur     = 0 ;

    m_rectangle.setTexture( m_texture );
    actualiser();
}



/////////////////////////////////////////////////
void AffImage::chargerDepuisFichier ( std::string fichier )
{
    std::cout << "AffImage : chargerDepuisFichier : " << fichier << "\n";
    std::string nomUniqueImage = Interface::ms_images.nomDefautSuivant();

    Interface::ms_images.load ( nomUniqueImage , fichier );

    m_texture = &Interface::ms_images.get ( nomUniqueImage );

    m_rectangle.setTexture( m_texture );

    m_rectangle.setTextureRect ( { 0
                                 , 0
                                 , m_texture->getSize().x
                                 , m_texture->getSize().y });
    actualiserGeometrie ();
}

/////////////////////////////////////////////////
void AffImage::actualiserGeometrie ()
{
    if ( m_ajustement )
        m_rectangle.setSize ( { m_taille.x , m_taille.y } );
    else
        m_rectangle.setSize ( { m_texture->getSize().x , m_texture->getSize().y } );

    actualiserBounds();
}
/////////////////////////////////////////////////
void AffImage::actualiserStyle ()
{
    AffRectangle::actualiserStyle();
    m_rectangle.setTexture( m_texture );
}
/*
/////////////////////////////////////////////////
void AffImage::actualiser ()
{
    m_rectangle.setTexture( m_texture );

//        m_taille = sf::Vector2i(m_texture->getSize().x , m_texture->getSize().y );


    if ( m_skin == nullptr ) {

        m_rectangle.setFillColor        ( sf::Color ( 255, 255, 255, 255 * m_opacite ) );
        m_rectangle.setOutlineColor     ( sf::Color ( 255, 255, 255, 255 * m_opacite ) );
        m_rectangle.setOutlineThickness ( 0 );

    } else {

        auto style = m_skin->getStyle( Styles::img );

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

}

*/
/////////////////////////////////////////////////
void AffImage::draw (sf::RenderTarget& target, sf::RenderStates states) const
{
    //On applique la transformation
    states.transform *= getTransform();

    // On dessine l'image
    target.draw( m_rectangle, states);
}


} // fin namespace gui

