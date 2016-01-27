/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Gadget.h>


#include <Geometrie.h>
#include <iostream>


namespace gui {

/////////////////////////////////////////////////
Gadget::Gadget ()
: m_actif       ( true )
, m_visible     ( true )
, m_focus       ( false )
, m_survol      ( false )
, m_presse      ( false )
, m_deplacable  ( false )

, m_enfants     ( std::vector<ptr> () )
, m_composants  ( std::vector<ptr> () )

{
    std::cout << "Creation du Gadget ()\n";

    // parametre par défaut.
    //m_taille = { 25 , 25 };
   // actualiser( sf::seconds(0));
//    setPosition ( { 0 , 0 }) ;

}


void Gadget::setTaille( sf::Vector2f val )
{
    m_taille = val;
    actualiser( sf::seconds( 0));
}

/////////////////////////////////////////////////
Gadget::Gadget (Gadget & original)
: m_actif ( true )
, m_visible ( true )
, m_focus ( false )
, m_survol ( false )
, m_presse ( false )
, m_deplacable ( false )
{

}


/////////////////////////////////////////////////
Gadget& Gadget::operator= (Gadget & original)
{

}


/////////////////////////////////////////////////
void Gadget::initialiser ()
{

}

/////////////////////////////////////////////////
void Gadget::actualiser( sf::Time delta )
{

    std::cout << "Gadget::actualiser()\n";

    // On actualise les composants
    for (auto composant : m_composants )
        composant->actualiser ( delta );

    // On actualise les enfants
    for (auto enfant : m_enfants )
        enfant->actualiser ( delta );

}


/////////////////////////////////////////////////
void Gadget::dessinerEnfants (sf::RenderTarget& target, sf::RenderStates states) const
{
    // On applique la transformation du gadget.
    states.transform *= getTransform();

    // pour chaque enfants
    for (auto enfant : m_enfants )
        enfant->draw ( target , states );
}


/////////////////////////////////////////////////
void Gadget::demander_aEtre_supprimer ()
{

}


/////////////////////////////////////////////////
void Gadget::demander_aEtre_auDessus () const
{

}


/////////////////////////////////////////////////
void Gadget::mettre_auDessus (std::shared_ptr<Gadget> gadget)
{

}

/////////////////////////////////////////////////
void Gadget::setParent( ptr  val )
{

    std::cout <<"Set parent\n";

    m_parent = val;
    m_parent->ajouterAEnfants ( getThisPtr() );
    std::cout <<"   Set parent Fin\n";

}


void Gadget::draw (sf::RenderTarget& target, sf::RenderStates states) const
{
    std::cout << "Gadget draw\n";

    // On applique la transformation du gadget.
    states.transform *= getTransform();

    //dessiner les composants
    dessinerComposants( target, states );

    //dessiner les enfants
    dessinerEnfants( target, states );

}


/////////////////////////////////////////////////
void Gadget::dessinerComposants (sf::RenderTarget& target, sf::RenderStates states) const
{

    // On dessine chaques composants
    for (auto composant : m_composants )
        composant->draw ( target , states );

}


} // fin namespace gui

