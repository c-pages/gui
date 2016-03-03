/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <BtnTexte.h>



namespace gui {

/////////////////////////////////////////////////
BtnTexte::BtnTexte ()
: m_rectangle   ( std::make_shared<AffRectangle>())
, m_label       ( std::make_shared<AffLabel>())
{
    m_autoAjust = true;
    setTexte("");
    ajouterComposant( m_rectangle );
    ajouterComposant( m_label );
    actualiser ();
}

/////////////////////////////////////////////////
void BtnTexte::actualiserGeometrie ()
{
    if ( m_autoAjust )
        m_taille = { m_label->getTaille().x + m_marge.x*2 , m_label->getTaille().y + m_marge.y*2 } ;

    m_rectangle->setTaille ( {m_taille.x, m_taille.y} );
    m_label->setPosition( m_marge.x  , m_marge.y/2   );
}

/////////////////////////////////////////////////
void BtnTexte::actualiserStyle ()
{

}
/*
/////////////////////////////////////////////////
void BtnTexte::actualiser ()
{

    // On choisie le style a appliquer (du style s'il en a un sinon du skin)
    std::shared_ptr<Style> style;
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




    m_label->setStyle ( style, etatBouton );

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

    actualiser_bounds();

    if ( m_parent != nullptr ) {
//            std::cout << "parent : " << m_parent->getNom() << "\n";
            m_parent->actualiserContenu();
    }

}
*/
/*
/////////////////////////////////////////////////
void BtnTexte::draw (sf::RenderTarget& target, sf::RenderStates states) const
{
    //On applique la transformation
    states.transform *= getTransform();

    // On dessine les éléments
    target.draw(m_rectangle, states);
    target.draw(m_label, states);

}
*/

} // fin namespace gui

