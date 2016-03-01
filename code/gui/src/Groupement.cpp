/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Groupement.h>



namespace gui {

/////////////////////////////////////////////////
Groupement::Groupement ()
: m_contenant ( std::make_shared<sf::RectangleShape>() )
, m_posX_texture(0)
, m_posY_texture(0)
, m_fond ( std::make_shared<AffRectangle>() )
{
    m_renderTexture.create( 1200, 900 );

    ajouterComposant( m_fond );
}

/////////////////////////////////////////////////
void Groupement::actualiserContenu ()
{

    // Render to texture des enfants
    m_renderTexture.clear( m_skin->getStyle ( Styles::fond )->fnd_couleur.repos );

    for (auto enfant : m_enfants)
        m_renderTexture.draw( *enfant );
    m_renderTexture.display();


//    m_contenant->setSize({ m_taille.x , m_taille.y });
    m_contenant->setTexture( &m_renderTexture.getTexture() );
    m_contenant->setTextureRect(    { m_posX_texture
                                    , m_posY_texture
                                    , m_contenant->getSize().x
                                    , m_contenant->getSize().y });

};


/////////////////////////////////////////////////
sf::Vector2f    Groupement::deplMaxContenu(){

    sf::Vector2f result;

    float longueurContenu       = float( boundgingB_enfants().width ) + 2;  //+  m_slider_V->getTaille().x;
    float longueurContenant     = m_contenant->getSize().x;
    float longueurDeplacement   = longueurContenu - longueurContenant;

    result.x =  longueurDeplacement;

    longueurContenu       = float( boundgingB_enfants().height ) + 2; // m_slider_H->getTaille().y;
    longueurContenant     = m_contenant->getSize().y;
    longueurDeplacement   = longueurContenu - longueurContenant;

    result.y =  longueurDeplacement;

    return result;

}



} // fin namespace gui

