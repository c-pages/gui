/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Fenetre.h>
#include <PanSliders.h>
#include <PanSimple.h>



namespace gui {

/////////////////////////////////////////////////
Fenetre::Fenetre ()
: m_panneau ( std::make_shared<PanSliders>() )
, m_fond ( std::make_shared<AffRectangle>() )
, m_ombre ( std::make_shared<AffRectangle>() )
{
    ajouterComposant( m_ombre );
    ajouterComposant( m_fond );
    ajouterComposant( m_panneau );
    m_ombre->setFillColor ( sf::Color ( 0,0,0,50 ) );
    m_ombre->setPosition  ( 5,5 );
}

/////////////////////////////////////////////////
void Fenetre::setDefilementActif (bool val)
{

}

/////////////////////////////////////////////////
void Fenetre::ajouter (std::shared_ptr<Gadget> enfant)
{
    m_panneau->ajouter ( enfant );
}


/////////////////////////////////////////////////
std::shared_ptr<Gadget> Fenetre::retirer (std::shared_ptr<Gadget> enfant)
{
    m_panneau->retirer ( enfant );
}

} // fin namespace gui

