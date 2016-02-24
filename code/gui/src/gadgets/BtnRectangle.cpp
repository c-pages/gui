/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <BtnRectangle.h>



namespace gui {

/////////////////////////////////////////////////
BtnRectangle::BtnRectangle ()
: m_texte ( "" )
{

}

/////////////////////////////////////////////////
void BtnRectangle::actualiser ()
{
    //    std::cout << "ACTUALISER BtnRectangle \n";

   /* m_rectangle.setSkin ( m_skin );
    m_label.setSkin     ( m_skin );*/




    // On choisie le style a appliquer en fonction de l'etat du bouton
    std::shared_ptr<Style> style;

    if ( m_style == nullptr )
        style = m_skin->bouton;
    else
        style = m_style;

    Etat etatBouton;
    if ( !estSurvole () && !estPresse() )
        etatBouton = Etat::repos;
    else if ( estPresse () )
        etatBouton = Etat::press;
    else if ( estSurvole () )
        etatBouton = Etat::survol;
//
//    if ( !estSurvole () && !estPresse() )
//        style = m_skin->btnRepos;
//    else if ( estPresse () )
//        style = m_skin->btnPress;
//    else if ( estSurvole () )
//        style = m_skin->btnSurvol;

    // Puis on l'applique au bouton.
//    m_label.setStyle( style );

    m_rectangle.setStyle( style );
    m_label.setStyle    ( style );

    if ( m_autoAjust )
        m_taille = { m_label.getTaille().x + m_marge.x*2 , m_label.getTaille().y + m_marge.y*2 } ;

    m_rectangle.setTaille ( {m_taille.x, m_taille.y} );
//    m_rectangle.setStyle  ( style );


    m_label.setPosition( m_marge.x  , m_marge.y/2   );

    m_label.setPolice( style->txt_police.repos );

    m_label.setTexteTaille( style->txt_taille.repos );


    m_rectangle.setFillColor    ( sf::Color (
                                      style->fnd_couleur.get(etatBouton).r
                                    , style->fnd_couleur.get(etatBouton).g
                                    , style->fnd_couleur.get(etatBouton).b
                                    , style->fnd_couleur.get(etatBouton).a * m_opacite ) ) ;

    m_rectangle.setOutlineColor     ( sf::Color (
                                      style->lgn_couleur.get(etatBouton).r
                                    , style->lgn_couleur.get(etatBouton).g
                                    , style->lgn_couleur.get(etatBouton).b
                                    , style->lgn_couleur.get(etatBouton).a * m_opacite ) ) ;

    m_rectangle.setOutlineThickness ( style->lgn_epaisseur.get(etatBouton) ) ;

    actualiser_bounds();
}

/////////////////////////////////////////////////
void BtnRectangle::draw (sf::RenderTarget& target, sf::RenderStates states) const
{
    //On applique la transformation
    states.transform *= getTransform();

    // On dessine les éléments
    target.draw(m_rectangle, states);
    target.draw(m_label, states);

}


} // fin namespace gui

