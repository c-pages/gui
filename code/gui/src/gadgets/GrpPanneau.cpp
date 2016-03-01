/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <GrpPanneau.h>
#include <Enums.h>



namespace gui {

/////////////////////////////////////////////////
GrpPanneau::GrpPanneau ()
: m_fond ( std::make_shared<AffRectangle>() )
, m_slider_V ( std::make_shared<DnBarreDefilement>() )
, m_slider_H ( std::make_shared<DnBarreDefilement>() )
//, m_contenant ( std::make_shared<AffImage>() )
, m_contenant ( std::make_shared<sf::RectangleShape>() )
, m_contenu (  )
//, m_afficherSlider_V ( true )
//, m_afficherSlider_H ( true )
, m_repartiteur (  )
, m_posX_texture(0)
, m_posY_texture(0)
{
    m_taille = { 400 , 200 };

    m_renderTexture.create( 1200, 900 );

    ajouterComposant( m_fond );
    ajouterComposant( m_slider_V );
    ajouterComposant( m_slider_H );

    m_slider_V->setVertical();

    m_slider_V->lier ( Evenement::on_changerValeur , [this](){
        actualiser ();
    });

    m_slider_H->lier ( Evenement::on_changerValeur , [this](){
        actualiser ();
    });

    actualiser ();
}

sf::Vector2f    GrpPanneau::deplMaxContenu(){

    sf::Vector2f result;

    float longueurContenu       = float( boundgingB_enfants().width ) + 2;  //+  m_slider_V->getTaille().x;
    float longueurContenant     = m_taille.x - m_slider_V->getTaille().x;
    float longueurDeplacement   = longueurContenu - longueurContenant;

    result.x =  longueurDeplacement;

    longueurContenu       = float( boundgingB_enfants().height ) + 2; // m_slider_H->getTaille().y;
    longueurContenant     = m_taille.y - m_slider_H->getTaille().y;
    longueurDeplacement   = longueurContenu - longueurContenant;

    result.y =  longueurDeplacement;

    return result;

}


/////////////////////////////////////////////////
void GrpPanneau::actualiser ()
{
    m_fond->setTaille(m_taille);

    sf::Vector2f longueurs = deplMaxContenu();

    // si contenu plus grand, on a le slider Horiz
    if ( longueurs.x > 0 ) {
        m_slider_H->setVisible ( true );
        float coef                  = (  m_slider_H->getValeur() ) / 100;

        m_posX_texture              = coef * longueurs.x;

        float longueurCursH = m_taille.x/ float( boundgingB_enfants().width )* 100 ;
        m_slider_H->setLongueurCurseur(longueurCursH);
        m_slider_H->setLongueur( m_taille.x -  m_slider_V->getTaille().x );
        m_slider_H->setPosition( 0 , m_taille.y - m_slider_H->getTaille().y);
        m_slider_H->setStyle       ( m_skin->getStyle (  gui::Styles::bouton ) );

    // si contenu plus petit, on cache le slider
    } else {
        m_slider_H->setVisible ( false );
        m_posX_texture      = 0;
    }


    // si contenu plus grand, on a le slider vert
    if (  longueurs.y > 0 ) {  // si contenu plus grand, on a le slider
        m_slider_V->setVisible ( true );
        float coef                  = ( 100 - m_slider_V->getValeur() ) / 100;
        m_posY_texture              = coef * longueurs.y;


        float longueurCursV = m_taille.y /float( boundgingB_enfants().height )* 100 ;
        m_slider_V->setLongueurCurseur(longueurCursV);
        m_slider_V->setLongueur( m_taille.y -  m_slider_H->getTaille().y );
        m_slider_V->setPosition( m_taille.x - m_slider_V->getTaille().x , 0 );
        m_slider_V->setStyle       ( m_skin->getStyle (  gui::Styles::bouton ) );

    } else { // si contenu plus petit, on cache le slider
        m_slider_V->setVisible ( false );
        m_posY_texture      = 0;
    }





    m_fond->setStyle ( m_skin->getStyle ( Styles::fond ));

    actualiserContenu();

    actualiser_bounds ();

}

/////////////////////////////////////////////////
sf::IntRect  GrpPanneau::boundgingB_enfants()
{
        sf::IntRect result;
        if ( m_enfants.size() == 0 )
            return result;

        int minX = 90000;
        int minY = 90000;
        int maxX = -90000;
        int maxY = -90000;

        for ( auto enfant : m_enfants )
        {
            sf::FloatRect LB = enfant->getLocalBounds();

            if (LB.left < minX) minX = LB.left;
            if (LB.top  < minY) minY = LB.top;
            if (LB.left+LB.width > maxX) maxX = LB.left + LB.width;
            if (LB.top+LB.height > maxY) maxY = LB.top + LB.height;
        }

        result.left     = minX;
        result.top      = minY;
        result.width    = maxX - minX;
        result.height   = maxY - minY;

        return result;
}



/////////////////////////////////////////////////
void GrpPanneau::actualiserContenu ()
{

    // Render to texture des enfants
    m_renderTexture.clear(sf::Color(0,0,255,25));
    for (auto enfant : m_enfants)
        m_renderTexture.draw( *enfant );
    m_renderTexture.display();
    int largeur = m_taille.x -  m_slider_V->getTaille().x;
    int hauteur = m_taille.y -  m_slider_H->getTaille().y;
    m_contenant->setSize({ largeur , hauteur });
    m_contenant->setTexture( &m_renderTexture.getTexture() );
    m_contenant->setTextureRect(    { m_posX_texture
                                    , m_posY_texture
                                    , largeur
                                    , hauteur });

};



/////////////////////////////////////////////////
void GrpPanneau::draw (sf::RenderTarget& target, sf::RenderStates states) const
{

    if ( estVisible() ) {

        //On applique la transformation
        states.transform *= getTransform();

        target.draw( *m_fond , states );
        target.draw( *m_slider_V , states );
        target.draw( *m_slider_H , states );

//        dessinerComposant   ( target, states );
        target.draw( *m_contenant , states );

    }
}


} // fin namespace gui

