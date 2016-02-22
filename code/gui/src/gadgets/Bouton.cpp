/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Bouton.h>

#include <iostream>

namespace gui {

/////////////////////////////////////////////////
Bouton::Bouton  ( )
: Cliquable     ( )
, m_marge       ( { 34 , 56 } )
, m_rectangle ( new AffRectangle() )
, m_couleurRepos  ( sf::Color ( 200 , 200 , 200 , 150 ) )
, m_couleurSurvol ( sf::Color ( 200 , 200 , 200 , 250 ) )
, m_couleurFocus  ( sf::Color ( 255 , 255 , 255 , 250 ) )
{
    std::cout << "Creation bouton ( )\n";
    initialiser_composants ();
}

//
///////////////////////////////////////////////////
//Bouton::Bouton ( ptr parent )
////: m_label ( std::shared_ptr<AffLabel> ( new AffLabel () ) )
////, m_icone ( std::shared_ptr<AffImage> ( new AffImage () ) )
////, m_rectangle ( std::shared_ptr<AffRectangle> ( new AffRectangle () ) )
//{
//    std::cout << "Creation bouton ( ptr parent )\n";
//    parent->ajouterAEnfants
//    setParent( parent );
////    initialiser_composants ();
//
//}


/////////////////////////////////////////////////
void Bouton::initialiser_composants ()
{
    std::cout << "Bouton::initialiser_composants () ... \n";

//    m_icone       = new AffImage () ;
//    m_rectangle   = std::make_shared< AffRectangle > () ;
//    m_label       = new AffLabel ();
//
    ajouterAComposants ( m_rectangle );
//    ajouterAComposants ( m_icone );
//    ajouterAComposants ( m_label );

//    m_rectangle->setNom ( "REctangle pourri" );
    m_rectangle->setFillColor   ( m_couleurRepos );
    m_rectangle->setTaille      ( m_taille );

    std::cout << "  initialiser_composants  OK\n";

}


///////////////////////////////////////////////////
//void Bouton::draw (sf::RenderTarget& target, sf::RenderStates states) const
//{
//    std::cout << "Bouton::draw()\n";
//
//    dessinerComposants ( target, states );
//
//}

/////////////////////////////////////////////////
void Bouton::setTexte( std::string val )
{

    // Redefinition de m_texte
    m_texte = val;

    // PROVISOIRE
    std::string textTmp;
    if (getSurvol())    textTmp = val + " True";
    else                textTmp = val + " False";

    // On redefinie le texte du label
//    m_label->setTexte ( textTmp );

    // On ajuste le rectangle au texte (A voir si on le laisse ici)
    ajusterAuTexte ();

    // PROVISOIRE
    if (getSurvol())
        m_rectangle->setFillColor ( m_couleurSurvol );
    else
        m_rectangle->setFillColor ( m_couleurRepos );

}

/////////////////////////////////////////////////
void Bouton::actualiser( sf::Time delta )
{

    // On actualise les composants
    for (auto composant : m_composants )
        composant->actualiser ( delta );

}


/////////////////////////////////////////////////
void Bouton::ajusterAuTexte ()
{


    std::cout << "AJUSTER AU TEXTE :    ";

    // Si on a pas de texte , on quite
    if ( m_texte == "" ) return;

    // On ajuste le rectangle a la taille du texte en tenant compte de la marge
//    m_rectangle->setTaille ( { m_label->getTaille().x + m_marge.x*2 , m_label->getTaille().y + m_marge.y*2 } );

    // La nouvelle taille du gadget
    m_taille = m_rectangle->getTaille();

    std::cout << "m_taille : " << m_taille.x << " , " << m_taille.y << "\n";

    // on deplace le label de la distance de la marge
//    m_label->setPosition ( m_marge );

    // mise à jour des bounds
    actualiser_bounds();

}


} // fin namespace gui

