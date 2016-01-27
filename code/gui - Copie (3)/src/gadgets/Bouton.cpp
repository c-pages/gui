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
Bouton::Bouton ( )
: m_label ( nullptr )
, m_icone ( nullptr )
, m_rectangle ( nullptr )
//: m_label ( std::shared_ptr<AffLabel> ( new AffLabel () ) )
//, m_icone ( std::shared_ptr<AffImage> ( new AffImage () ) )
//, m_rectangle ( std::shared_ptr<AffRectangle> ( new AffRectangle () ) )
{
    std::cout << "Creation bouton ( )\n";
    initialiser_composants ();
}


/////////////////////////////////////////////////
Bouton::Bouton ( ptr parent )
: m_label ( std::shared_ptr<AffLabel> ( new AffLabel () ) )
, m_icone ( std::shared_ptr<AffImage> ( new AffImage () ) )
, m_rectangle ( std::shared_ptr<AffRectangle> ( new AffRectangle () ) )
{
    std::cout << "Creation bouton ( ptr parent )\n";

    setParent( parent );
    initialiser_composants ();
}


/////////////////////////////////////////////////
void Bouton::initialiser_composants ()
{


    std::cout << "Bouton::initialiser_composants \n";
    m_label = std::shared_ptr<AffLabel> ( new AffLabel () ) ;
    m_icone = std::shared_ptr<AffImage> ( new AffImage () ) ;
    m_rectangle = std::shared_ptr<AffRectangle> ( new AffRectangle () ) ;
    std::cout << "  Bouton::initialiser_composants 1\n";

    ajouterAComposants ( m_label->getThisPtr() );
    ajouterAComposants ( m_icone->getThisPtr() );
    ajouterAComposants ( m_rectangle->getThisPtr() );
    std::cout << "  Bouton::initialiser_composants FIN\n";
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

}

/////////////////////////////////////////////////
void Bouton::actualiser( sf::Time delta )
{

    std::cout << "Gadget::actualiser()\n";

    // On actualise les composants
    for (auto composant : m_composants )
        composant->actualiser ( delta );

}


} // fin namespace gui

