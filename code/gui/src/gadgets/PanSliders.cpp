/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <PanSliders.h>
#include <Enums.h>



namespace gui {

/////////////////////////////////////////////////
PanSliders::PanSliders ()
: Panneau ()
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
void PanSliders::actualiser ()
{

    m_fond->setTaille(m_taille);

    sf::Vector2f longueurs = deplMaxContenu();

    m_slider_H->setVisible ( longueurs.x > 0 );
    m_slider_V->setVisible ( longueurs.y > 0 );

    m_contenant->setSize({ m_taille.x -  m_slider_V->getTaille().x , m_taille.y -  m_slider_H->getTaille().y});

    // si le contenu est plus grand que le contenant
    if ( m_slider_H->estVisible() ) {
        float coef                  = (  m_slider_H->getValeur() ) / 100;

        m_posX_texture              = coef * longueurs.x;

        float longueurCursH = m_taille.x/ float( boundgingB_enfants().width )* 100 ;
        m_slider_H->setLongueurCurseur(longueurCursH);
        m_slider_H->setLongueur( m_taille.x -  m_slider_V->getTaille().x );
        m_slider_H->setPosition( 0 , m_taille.y - m_slider_H->getTaille().y);
        m_slider_H->setStyle       ( m_skin->getStyle (  gui::Styles::bouton ) );

    // si le contenu est plus petit, on cache le slider
    } else {
        m_posX_texture      = 0;
    }

    // si contenu plus grand, on a le slider vert
    if (  m_slider_V->estVisible() ) {  // si contenu plus grand, on a le slider
        float coef                  = ( 100 - m_slider_V->getValeur() ) / 100;
        m_posY_texture              = coef * longueurs.y;


        float longueurCursV = m_taille.y /float( boundgingB_enfants().height )* 100 ;
        m_slider_V->setLongueurCurseur( longueurCursV );
        m_slider_V->setLongueur ( m_taille.y - m_slider_H->getTaille().y );
        m_slider_V->setPosition ( m_taille.x - m_slider_V->getTaille().x , 0 );
        m_slider_V->setStyle    ( m_skin->getStyle (  gui::Styles::bouton ) );

    // si le contenu est plus petit, on cache le slider
    } else {
        m_posY_texture      = 0;
    }


    m_fond->setStyle ( m_skin->getStyle ( Styles::fond ) );

    actualiserContenu();

    if ( m_parent != nullptr ) m_parent->actualiserContenu();

    actualiserBounds ();

}




/////////////////////////////////////////////////
void PanSliders::draw (sf::RenderTarget& target, sf::RenderStates states) const
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

