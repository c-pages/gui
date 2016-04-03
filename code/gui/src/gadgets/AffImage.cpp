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
, m_ajustement  ( false )
{
    m_taille = { 150,150 };
    creerNomUnique ( "Image");

    m_texture->setRepeated  ( true );
    m_texture->setSmooth    ( true );

    m_fondCouleur   = sf::Color::White ;
    m_fondLgnCouleur = sf::Color::White ;

    m_fondLgnEpaisseur     = 0 ;

    m_rectangle.setTexture( m_texture);
}

/////////////////////////////////////////////////
void AffImage::actualiserGeometrie ()
{
    // Debuggage
    log ("actualiserGeometrie");

    if ( m_ajustement )
        m_rectangle.setSize ( { m_taille.x , m_taille.y } );
    else
        m_rectangle.setSize ( { m_texture->getSize().x , m_texture->getSize().y } );

    demanderActuaBounds();

}
/////////////////////////////////////////////////
void AffImage::actualiserStyle ()
{
    // Debuggage
    log ("actualiserStyle");

    m_rectangle.setFillColor        ( m_fondCouleur );
    m_rectangle.setOutlineColor     ( m_fondLgnCouleur );
    m_rectangle.setOutlineThickness ( m_fondLgnEpaisseur );

    m_rectangle.setTexture( m_texture );
}

/////////////////////////////////////////////////
void AffImage::setImage (  sf::Texture* texture ) {
    m_texture = texture;
    demanderActualisation() ;
};


/////////////////////////////////////////////////
void AffImage::setAjustement ( bool val ) {
    m_ajustement = val;
}


/////////////////////////////////////////////////
void AffImage::setTaille( sf::Vector2i val ){
    demanderActuaGeom();
};


/////////////////////////////////////////////////
void AffImage::setImage ( std::string fichier )
{
    log ( "setImage"  );
    log ( "fichier" , fichier );

    std::string nomUniqueImage = Interface::ms_images.nomDefautSuivant();

    Interface::ms_images.load ( nomUniqueImage , fichier );

    m_texture = &Interface::ms_images.get ( nomUniqueImage );

    m_rectangle.setTexture( m_texture );

    m_rectangle.setTextureRect ( { 0
                                 , 0
                                 , m_texture->getSize().x
                                 , m_texture->getSize().y });

    demanderActuaGeom() ;
}


/////////////////////////////////////////////////
void AffImage::draw (sf::RenderTarget& target, sf::RenderStates states) const
{
    if (! estVisible() ) return;

    //On applique la transformation
    states.transform *= getTransform();

    // On dessine l'image
    target.draw( m_rectangle, states);
}


} // fin namespace gui

