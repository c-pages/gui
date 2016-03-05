/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <BtnTexte.h>
#include <Interface.h>



namespace gui {

/////////////////////////////////////////////////
BtnTexte::BtnTexte ()
: BtnRectangle ()
, m_label       ( std::make_shared<AffLabel>())
{
    m_marge = { 5, 5 };
    m_autoAjust = true;
    m_texte = "";

    // valeurs par defaut
    m_textCouleur.set( sf::Color::White );
    m_textCouleur.set( sf::Color( 100,100,100 ) , Etat::desactive );
    m_textTaille.set ( 12 ) ;
    m_textPolice.set ( Interface::ms_polices.get( "Defaut" ) ) ;
    m_textStyle.set  ( sf::Text::Style::Regular ) ;

    ajouterComposant( m_label );

    actualiser ();

}

/////////////////////////////////////////////////
void BtnTexte::actualiserGeometrie ()
{
    m_label->setTexte ( m_texte );

    if ( m_autoAjust )
        m_taille = { m_label->getTaille().x + m_marge.x*2 , m_label->getTaille().y + m_marge.y*2 } ;

    BtnRectangle::actualiserGeometrie();

    m_label->setPosition( m_marge.x  , m_marge.y/3 );

}

/////////////////////////////////////////////////
void BtnTexte::actualiserStyle ()
{
    BtnRectangle::actualiserStyle ();
    m_label->setTexteCouleur    ( sf::Color (
                                      m_textCouleur.get( this->etat() ).r
                                    , m_textCouleur.get( this->etat() ).g
                                    , m_textCouleur.get( this->etat() ).b
                                    , m_textCouleur.get( this->etat() ).a * m_opacite ) ) ;

    m_label->setTexteTaille     ( m_textTaille.get( this->etat() ) ) ;

    m_label->setPolice          ( m_textPolice.get( this->etat() ) ) ;

    m_label->setTexteStyle      ( m_textStyle.get( this->etat() ) ) ;

}
/*

/////////////////////////////////////////////////
void BtnTexte::setStyle ( std::shared_ptr<Style> style , Etat etat )
{
    std::cout << "BtnTexte::setStyle : " << style << "\n";


    m_textCouleur   = style->txt_couleur;
    m_textStyle     = style->txt_style;
    m_textTaille    = style->txt_taille;
    m_textPolice    = style->txt_police;

    BtnRectangle::setStyle ( style , etat );

}

*/



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

    actualiserBounds();

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

