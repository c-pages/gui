/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <BtnRectangle.h>



namespace gui {

/////////////////////////////////////////////////
BtnRectangle::BtnRectangle ()
: m_rectangle   ( std::make_shared<AffRectangle>())
{
    setTexte("");
    ajouterComposant( m_rectangle );
}

/////////////////////////////////////////////////
void BtnRectangle::actualiser ()
{

    m_rectangle->setTaille ( {m_taille.x, m_taille.y} );

    // On choisie le style a appliquer (du style s'il en a un sinon du skin)
    std::shared_ptr<Style> style;
    if ( m_style == nullptr )
        style = m_skin->getStyle( Styles::bouton );
    else
        style = m_style;

    // On analyse dans quel etat est le bouton
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

    // on actualise le contenat parent si besoin
    if ( m_parent != nullptr ) m_parent->actualiserContenu();

    actualiser_bounds();

}


} // fin namespace gui

