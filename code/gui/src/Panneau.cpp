/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Panneau.h>



namespace gui {

/////////////////////////////////////////////////
Panneau::Panneau ()
: m_contenant ( std::make_shared<sf::RectangleShape>() )
, m_posX_texture(0)
, m_posY_texture(0)
, m_fond ( std::make_shared<AffRectangle>() )
{
    m_renderTexture.create( 1200, 900 );

    ajouterComposant( m_fond );
}

/////////////////////////////////////////////////
void Panneau::actualiserContenu ()
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

std::shared_ptr<Gadget>  Panneau::testerSurvol ( sf::Vector2i position )
{
    // si on est dans le panneau
    if ( m_globalBounds.contains( position.x, position.y ) && estActif() )
    {
        // si on survol un gadget composant (slider)
        auto testInterfaceLocal = testerSurvolComposants( position );
        if ( testInterfaceLocal != nullptr )
            // on le renvois
            return testInterfaceLocal;
        else {
            // sinon on regarde si on survol un enfant
            auto testEnfants = testerSurvolComposite( { position.x + m_posX_texture, position.y + m_posY_texture } );
            if ( testEnfants != nullptr )
                return testEnfants;
           else return thisPtr();
//             else return nullptr;
        }
    }
    else return nullptr;
}

/////////////////////////////////////////////////
sf::Vector2f    Panneau::deplMaxContenu(){

    sf::Vector2f result;

    float longueurContenu       = float( boundgingB_enfants().left + boundgingB_enfants().width ) + 25;  //+  m_slider_V->getTaille().x;
    float longueurContenant     = m_taille.x;
    float longueurDeplacement   = longueurContenu - longueurContenant;

    result.x =  longueurDeplacement;

    longueurContenu       = float( boundgingB_enfants().top + boundgingB_enfants().height ) + 25; // m_slider_H->getTaille().y;
    longueurContenant     = m_taille.y;
    longueurDeplacement   = longueurContenu - longueurContenant;

    result.y =  longueurDeplacement;
//
//    float longueurContenu       = float( boundgingB_enfants().left + boundgingB_enfants().width ) + 2;  //+  m_slider_V->getTaille().x;
//    float longueurContenant     = m_contenant->getSize().x;
//    float longueurDeplacement   = longueurContenu - longueurContenant;
//
//    result.x =  longueurDeplacement;
//
//    longueurContenu       = float( boundgingB_enfants().top + boundgingB_enfants().height ) + 2; // m_slider_H->getTaille().y;
//    longueurContenant     = m_contenant->getSize().y;
//    longueurDeplacement   = longueurContenu - longueurContenant;
//
//    result.y =  longueurDeplacement;
    std::cout << "result : " << result.x << ", " << result.y << "\n";
    return result;

}



} // fin namespace gui

