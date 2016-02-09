/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Bouton.h>
#include <AffLabel.h>
#include <AffImage.h>
#include <AffRectangle.h>

#include <iostream>

namespace gui {

/////////////////////////////////////////////////
Bouton::Bouton  ( )
: Cliquable     ( )
, m_label       ( std::make_shared<AffLabel> ( ) )
, m_icone       ( std::make_shared<AffImage> ( ) )
, m_rectangle   ( std::make_shared<AffRectangle> ( ) )
, m_marge       ( { 15, 5 } )
{
    std::cout << "Creation bouton ( )\n";
    initialiser_composants ();
}


/////////////////////////////////////////////////
Bouton::Bouton ( ptr parent )
//: m_label ( std::shared_ptr<AffLabel> ( new AffLabel () ) )
//, m_icone ( std::shared_ptr<AffImage> ( new AffImage () ) )
//, m_rectangle ( std::shared_ptr<AffRectangle> ( new AffRectangle () ) )
{
    std::cout << "Creation bouton ( ptr parent )\n";

    setParent( parent );
    initialiser_composants ();

}


/////////////////////////////////////////////////
void Bouton::initialiser_composants ()
{

    ajouterAComposants ( m_rectangle->thisPtr() );
    ajouterAComposants ( m_icone->thisPtr() );
    ajouterAComposants ( m_label->thisPtr() );

    // taille par défaut ... a voir ...
    m_taille = { 20 , 20 };
    m_rectangle->setTaille ( m_taille );

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

    // Si on a un label, on redefinie le texte du label
    if ( m_label != nullptr )
        m_label->setTexte ( val );

    // On ajuste le rectangle au texte (A voir si on le laisse ici)
    ajusterRectangleAuTexte ();


}

/////////////////////////////////////////////////
void Bouton::actualiser( sf::Time delta )
{

    std::cout << "Gadget::actualiser()\n";

    // On actualise les composants
    for (auto composant : m_composants )
        composant->actualiser ( delta );

}


/////////////////////////////////////////////////
void Bouton::ajusterRectangleAuTexte ()
{

    // Si on a pas de label, on quite
    if ( m_label == nullptr ) return;


    // On ajuste le rectangle a la taille du texte en tenant compte de la marge
    m_rectangle->setTaille ( { m_label->getTaille().x + m_marge.x*2 , m_label->getTaille().y + m_marge.y*2 } );

    // on deplace le label de la distance  de la marge
    m_label->setPosition ( m_marge );

}


} // fin namespace gui

