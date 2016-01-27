/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Gui.h>
#include <Gadget.h>
#include <Theme.h>
#include <Conteneur.h>
#include <Gadget.h>
#include <memory>


#include <iostream>

namespace gui {

/////////////////////////////////////////////////
Gui::Gui (sf::RenderTarget* cible)
: creer ( /*new gui::FabriqueGadgetBase( this  ) */ 0 )
, m_fenetre ( 0 )
, m_cible ( cible )
, m_conteneur ( std::make_shared<ConteneurGui>() )
, m_theme ( nullptr )
, m_tempsPourAfficherInfoBulle ( sf::milliseconds(500) )
, m_tempsDoubleClique ( sf::milliseconds(500) )
, m_infoBulleVisible ( nullptr )
{
    std::cout << "Creation du gui : target\n";
}


/////////////////////////////////////////////////
Gui::Gui ( sf::RenderWindow* fenetre )
: creer (  /*new gui::FabriqueGadgetBase( this  ) */ 0  )
, m_fenetre ( fenetre )
, m_cible ( 0 )
, m_conteneur ( std::make_shared<ConteneurGui>() )
, m_theme ( nullptr )
, m_tempsPourAfficherInfoBulle ( sf::milliseconds(500) )
, m_tempsDoubleClique ( sf::milliseconds(500) )
, m_infoBulleVisible ( nullptr )
{
    std::cout << "Creation du gui : fenetre\n";
    creer = new gui::FabriqueGadgetBase( this  ) ;
}

/////////////////////////////////////////////////
void Gui::actualiser ( sf::Time delta )
{
//    std::cout << "Gui::actualiser ()\n";

}


/////////////////////////////////////////////////
void Gui::dessiner ( ) const
{
//    std::cout << "Gui::dessiner ()\n";
    // Dessiner les gadgets de l'interface dans la fenêtre
    if ( m_fenetre != 0 )
        m_fenetre->draw ( *m_conteneur );

}


/////////////////////////////////////////////////
void Gui::ajouter (Gadget::ptr enfant)
{

}


/////////////////////////////////////////////////
void Gui::retirer (Gadget::ptr enfant)
{

}


/////////////////////////////////////////////////
void Gui::vider ()
{

}


} // fin namespace gui

