/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <BoutonRect.h>



namespace gui {

/////////////////////////////////////////////////
BoutonRect::BoutonRect ()
: m_texte ( "" )
{

}

/////////////////////////////////////////////////
void BoutonRect::actualiser ()
{
//    std::cout << "ACTUALISER BoutonRect \n";

    m_label.setSkin ( m_skin );
    m_rectangle.setSkin ( m_skin );

    m_label.setTexte( m_texte );

    if ( m_autoAjust )
        m_taille = { m_label.getTaille().x + m_marge.x*2 , m_label.getTaille().y + m_marge.y*2 } ;

    m_rectangle.setTaille ( {m_taille.x, m_taille.y} );
    m_label.setPosition( m_marge.x  , m_marge.y/2   );
/*
    // Si on a pas de skin on applique un style par defaut.
    if ( m_skin == nullptr ) {
        if ( !estSurvole () && !estPresse() )        {
            //std::cout << "Repos\n";
            m_rectangle.setFillColor        ( sf::Color ( 255, 255, 255, 100 * m_opacite ) );
            m_rectangle.setOutlineColor     ( sf::Color ( 255, 255, 255, 150 * m_opacite ) );
            m_rectangle.setOutlineThickness ( 1 );
            m_label.setSkin ( m_skin );
        } else if ( estPresse () ) {
            //std::cout << "Press\n";
            m_rectangle.setFillColor        ( sf::Color ( 255, 255, 255, 200 * m_opacite ) );
            m_rectangle.setOutlineColor     ( sf::Color ( 255, 255, 255, 150 * m_opacite ) );
            m_rectangle.setOutlineThickness ( 1 );
        } else if ( estSurvole () ) {
            //std::cout << "Survol\n";
            m_rectangle.setFillColor        ( sf::Color ( 255, 255, 255, 150 * m_opacite ) );
            m_rectangle.setOutlineColor     ( sf::Color ( 255, 255, 255, 150 * m_opacite ) );
            m_rectangle.setOutlineThickness ( 1 );
        }

    // Si on a un skin alors...
    } else {
*/
        // On choisie le style a appliquer en fonction de l'etat du bouton
        std::shared_ptr<Style> style = nullptr;
        if ( !estSurvole () && !estPresse() )
            style = m_skin->btnRepos;
        else if ( estPresse () )
            style = m_skin->btnPress;
        else if ( estSurvole () )
            style = m_skin->btnSurvol;

        // Puis on l'applique au bouton.
        m_rectangle.setFillColor        ( sf::Color (
                                          style->fnd_couleur.r
                                        , style->fnd_couleur.g
                                        , style->fnd_couleur.b
                                        , style->fnd_couleur.a * m_opacite ) ) ;

        m_rectangle.setOutlineColor     ( sf::Color (
                                          style->lgn_couleur.r
                                        , style->lgn_couleur.g
                                        , style->lgn_couleur.b
                                        , style->lgn_couleur.a * m_opacite ) ) ;

        m_rectangle.setOutlineThickness ( style->lgn_epaisseur ) ;



}

/////////////////////////////////////////////////
void BoutonRect::draw (sf::RenderTarget& target, sf::RenderStates states) const
{
    //On applique la transformation
    states.transform *= getTransform();

    // On dessine les éléments
    target.draw(m_rectangle, states);
    target.draw(m_label, states);

}


} // fin namespace gui

