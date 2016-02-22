/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <AffRectangle.h>

#include <iostream>

namespace gui {

/////////////////////////////////////////////////
AffRectangle::AffRectangle ()
: Affiche()
//, m_rectangle   ( )
, m_couleur     (  )
, m_cadreEpaisseur ( 1. )
, m_cadreCouleur( sf::Color ( 255 , 255 , 255 , 200 ) )
{

    std::cout << "Creation AffRectangle ( )\n";
//    m_rectangle = new sf::RectangleShape  ( );
    m_cadreEpaisseur = 1;
    // Actualiser
    actualiser( sf::seconds(0));
    std::cout << " Rectangle cree OK.\n";

}


/////////////////////////////////////////////////
void AffRectangle::actualiser( sf::Time delta )
{
//    m_cadreEpaisseur = 1;

    std::cout << "AffRectangle::m_cadreEpaisseur : " << m_cadreEpaisseur << "\n";
  //  std::cout << "  Rectangle  NOM : " << getNom() << "\n";
//
//    m_rectangle->setSize (  m_taille );
//    m_rectangle->setFillColor ( m_couleur );
//    m_rectangle->setOutlineColor ( m_cadreCouleur );
//    m_rectangle->setOutlineThickness ( 1 );

}


/////////////////////////////////////////////////
void AffRectangle::initialiser_composants ()
{

}


/////////////////////////////////////////////////
void AffRectangle::draw (sf::RenderTarget& target, sf::RenderStates states) const
{
//    std::cout << "Rectangle : dessiner\n";

    // On applique la transformation du gadget.
    states.transform *= getTransform();

    // On dessine le rectangle
//    target.draw( *m_rectangle , states );

}


} // fin namespace gui

