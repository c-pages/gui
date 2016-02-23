/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <BoutonRect.h>



namespace gui {

/////////////////////////////////////////////////
BoutonRect::BoutonRect ()
{

}

/////////////////////////////////////////////////
void BoutonRect::actualiser ()
{
    //std::cout << "ACTUALISER AFFRECTANGLE : opacité = "<< m_opacite << ". ";

    m_rectangle.setTaille ( {m_taille.x, m_taille.y} );

    if ( m_skin == nullptr ) {
        if ( !estSurvole () && !estPresse() )        {
            //std::cout << "Repos\n";
            m_rectangle.setFillColor        ( sf::Color ( 255, 255, 255, 100 * m_opacite ) );
            m_rectangle.setOutlineColor     ( sf::Color ( 255, 255, 255, 150 * m_opacite ) );
            m_rectangle.setOutlineThickness ( 1 );
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

    } else {

        // On choisie le styla a appliquer en fonction de l'etat du bouton
        std::shared_ptr<Style> style = nullptr;
        if ( !estSurvole () && !estPresse() )
            style = m_skin->fondRepos;
        else if ( estSurvole () )
            style = m_skin->fondSurvol;
        else if ( estPresse () )
            style = m_skin->fondPress;

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

}

/////////////////////////////////////////////////
void BoutonRect::draw (sf::RenderTarget& target, sf::RenderStates states) const
{
    //On applique la transformation
    states.transform *= getTransform();

    // On dessine le rectangle
    target.draw(m_rectangle, states);

}


} // fin namespace gui

