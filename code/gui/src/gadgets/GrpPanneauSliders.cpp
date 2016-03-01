/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <GrpPanneauSliders.h>
#include <Enums.h>



namespace gui {

/////////////////////////////////////////////////
GrpPanneauSliders::GrpPanneauSliders ()
: Groupement ()
, m_slider_V ( std::make_shared<DnBarreDefilement>() )
, m_slider_H ( std::make_shared<DnBarreDefilement>() )
{
    m_taille = { 400 , 200 };

    m_renderTexture.create( 1200, 900 );

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




/////////////////////////////////////////////////
void GrpPanneauSliders::actualiser ()
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



    m_contenant->setSize({ m_taille.x -  m_slider_V->getTaille().x , m_taille.y -  m_slider_H->getTaille().y});

    m_fond->setStyle ( m_skin->getStyle ( Styles::fond ) );

    actualiserContenu();

    actualiser_bounds ();

}

//
///////////////////////////////////////////////////
//sf::Vector2f    GrpPanneauSliders::deplMaxContenu(){
//
//    sf::Vector2f result;
//
//    float longueurContenu       = float( boundgingB_enfants().width ) + 2;  //+  m_slider_V->getTaille().x;
//    float longueurContenant     = m_taille.x - m_slider_V->getTaille().x;
//    float longueurDeplacement   = longueurContenu - longueurContenant;
//
//    result.x =  longueurDeplacement;
//
//    longueurContenu       = float( boundgingB_enfants().height ) + 2; // m_slider_H->getTaille().y;
//    longueurContenant     = m_taille.y - m_slider_H->getTaille().y;
//    longueurDeplacement   = longueurContenu - longueurContenant;
//
//    result.y =  longueurDeplacement;
//
//    return result;
//
//}



/////////////////////////////////////////////////
void GrpPanneauSliders::draw (sf::RenderTarget& target, sf::RenderStates states) const
{

    if ( estVisible() ) {

        //On applique la transformation
        states.transform *= getTransform();

        target.draw( *m_fond , states );
        target.draw( *m_slider_V , states );
        target.draw( *m_slider_H , states );
        target.draw( *m_contenant , states );

    }

}


} // fin namespace gui

