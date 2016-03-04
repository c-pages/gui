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
, m_rectangle   ( )
, m_ajustement  ( false )
{
    m_texture->setRepeated  ( true );
    m_texture->setSmooth    ( true );

    m_rectangle.setTexture( m_texture );
}

/*
/////////////////////////////////////////////////
void AffImage::charger ( int id )
{
    m_texture = &ms_images.get( id  );

    m_rectangle.setTexture( m_texture );
    m_rectangle.setTextureRect ( { 0
                                 , 0
                                 , m_texture->getSize().x
                                 , m_texture->getSize().y });
    actualiser ();

}
*/


/////////////////////////////////////////////////
void AffImage::chargerDepuisFichier ( std::string fichier )
{
//    std::cout << "AffImage : chargerDepuisFichier\n";
    std::string nomUniqueImage = ms_images.nomDefautSuivant();

    ms_images.load ( nomUniqueImage , fichier );

    m_texture = &ms_images.get ( nomUniqueImage );

    m_rectangle.setTexture( m_texture );

    m_rectangle.setTextureRect ( { 0
                                 , 0
                                 , m_texture->getSize().x
                                 , m_texture->getSize().y });

//    std::cout << "AffImage : taille image : " << m_texture->getSize().x << " "<< m_texture->getSize().y << "\n";

    actualiser ();

}


/////////////////////////////////////////////////
void AffImage::actualiser ()
{
    if ( ! m_necessiteActualisation )
        return;

    m_rectangle.setTexture( m_texture );

    if ( m_ajustement )
        m_rectangle.setSize ( { m_taille.x , m_taille.y } );
    else
        m_rectangle.setSize ( { m_texture->getSize().x , m_texture->getSize().y } );
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

    m_necessiteActualisation = false;
}


/////////////////////////////////////////////////
void AffImage::draw (sf::RenderTarget& target, sf::RenderStates states) const
{
    //On applique la transformation
    states.transform *= getTransform();

    // On dessine l'image
    target.draw( m_rectangle, states);
}


} // fin namespace gui
