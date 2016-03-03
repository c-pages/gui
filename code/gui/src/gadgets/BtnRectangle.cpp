/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <BtnRectangle.h>



namespace gui {

/////////////////////////////////////////////////
BtnRectangle::BtnRectangle ()
: m_rectangle   ( std::make_shared<AffRectangle>())
{
    m_couleurFond.set( sf::Color( 255,0,0, 10 )  , Etat::desactive );
    m_couleurFond.set( sf::Color( 255,0,0, 50 )  , Etat::repos );
    m_couleurFond.set( sf::Color( 255,0,0, 100 ) , Etat::survol );
    m_couleurFond.set( sf::Color( 255,0,0, 150 ) , Etat::press );

    m_couleurLignes.set( sf::Color( 0,255,0, 255 ) );

    m_epaisseur.set     ( 1 );

    ajouterComposant( m_rectangle );
}

/////////////////////////////////////////////////
void BtnRectangle::setStyle ( std::shared_ptr<Style> style , Etat etat )
{

    m_couleurFond.set   ( style->fnd_couleur , etat );
    m_couleurLignes.set ( style->lgn_couleur , etat );
    m_epaisseur.set     ( style->lgn_epaisseur , etat );

}


/////////////////////////////////////////////////
void BtnRectangle::actualiserGeometrie ()
{
    m_rectangle->setTaille ( {m_taille.x, m_taille.y} );
    actualiser_bounds();
}

/////////////////////////////////////////////////
void BtnRectangle::actualiserStyle ()
{

    // On analyse l'etat du bouton
    Etat etatBouton;
    if ( ! estActif() )
        etatBouton = Etat::desactive;
    else if ( !estSurvole () && !estPresse() )
        etatBouton = Etat::repos;
    else if ( estPresse () )
        etatBouton = Etat::press;
    else if ( estSurvole () )
        etatBouton = Etat::survol;

    // on applique le style correspondant à l'état
    m_rectangle->setFillColor    ( sf::Color (
                                      m_couleurFond.get(etatBouton).r
                                    , m_couleurFond.get(etatBouton).g
                                    , m_couleurFond.get(etatBouton).b
                                    , m_couleurFond.get(etatBouton).a * m_opacite ) ) ;
    m_rectangle->setOutlineColor     ( sf::Color (
                                      m_couleurLignes.get(etatBouton).r
                                    , m_couleurLignes.get(etatBouton).g
                                    , m_couleurLignes.get(etatBouton).b
                                    , m_couleurLignes.get(etatBouton).a * m_opacite ) ) ;
    m_rectangle->setOutlineThickness ( m_epaisseur.get(etatBouton) ) ;

}


} // fin namespace gui

