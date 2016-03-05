/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <BtnIcone.h>



namespace gui {

/////////////////////////////////////////////////
BtnIcone::BtnIcone ()
: /*m_rectangle   ( std::make_shared<AffRectangle>())
, */
  m_icone       ( std::make_shared<AffIcone>())
, m_fix    ( false )
{
    m_marge       = { 1 , 1} ;

    ajouterComposant( m_icone );

    m_icone->setIndex ( 1 );
    actualiser ();
//    m_icone->setStyle ( m_skin->getStyle( Styles::bouton ) , Etat::repos );
}


/////////////////////////////////////////////////
void BtnIcone::actualiserGeometrie ()
{

    if ( m_autoAjust )
        m_taille = { m_icone->getTaille().x + m_marge.x*2 , m_icone->getTaille().y + m_marge.y*2 } ;

    m_icone->setPosition( m_marge.x  , m_marge.y/3 );

    BtnRectangle::actualiserGeometrie();

}

/////////////////////////////////////////////////
void BtnIcone::actualiserStyle ()
{

    m_icone->setFillColor    ( sf::Color (
                                      255
                                    , 255
                                    , 255
                                    , 255 * m_opacite ) ) ;

    m_icone->setOutlineThickness ( 0 ) ;

    BtnRectangle::actualiserStyle();

}
/*
/////////////////////////////////////////////////
void BtnIcone::actualiser ()
{

    // On choisie le style a appliquer (du style s'il en a un sinon du skin)
/*    std::shared_ptr<Style> style;
    if ( m_style == nullptr )
        style = m_skin->getStyle( Styles::bouton );
    else
        style = m_style;

    Etat etatBouton;
    if ( ! estActif() )
        etatBouton = Etat::desactive;
    else if ( !estSurvole () && !estPresse() )
        etatBouton = Etat::repos;
    else if ( estPresse () )
        etatBouton = Etat::press;
    else if ( estSurvole () )
        etatBouton = Etat::survol;

    if ( ! m_fix ){
        m_icone->setStyle ( style, etatBouton );
        m_icone->setIndex ( int( etatBouton ) +1 );
    } else {
        m_icone->setStyle ( style);
    }


    if ( m_autoAjust )
        m_taille = { m_icone->getTaille().x + m_marge.x*2 , m_icone->getTaille().y + m_marge.y*2 } ;

    m_rectangle->setTaille ( {m_taille.x, m_taille.y} );
    m_icone->setPosition( m_marge.x  , m_marge.y   );



    m_rectangle->setFillColor    ( sf::Color (
                                      style->fnd_couleur.get(etatBouton).r
                                    , style->fnd_couleur.get(etatBouton).g
                                    , style->fnd_couleur.get(etatBouton).b
                                    , style->fnd_couleur.get(etatBouton).a * m_opacite ) ) ;

    m_rectangle->setOutlineColor     ( sf::Color (
                                      style->lgn_couleur.get(etatBouton).r
                                    , style->lgn_couleur.get(etatBouton).g
                                    , style->lgn_couleur.get(etatBouton).b
                                    , style->lgn_couleur.get(etatBouton).a * m_opacite ) ) ;

    m_rectangle->setOutlineThickness ( style->lgn_epaisseur.get(etatBouton) ) ;

    actualiserBounds();

    if ( m_parent != nullptr ) m_parent->actualiserContenu();

}
*/



} // fin namespace gui

