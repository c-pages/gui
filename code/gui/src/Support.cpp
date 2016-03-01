/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Support.h>
#include <PanSliders.h>
#include <PanSimple.h>



namespace gui {

/////////////////////////////////////////////////
Support::Support ()
: m_panneau ( std::make_shared<PanSliders>() )
, m_fond ( std::make_shared<AffRectangle>() )
{
    ajouterComposant( m_fond );
    ajouterComposant( m_panneau );
}

/////////////////////////////////////////////////
void Support::setDefilementActif (bool val)
{

}

/////////////////////////////////////////////////
void Support::ajouter (std::shared_ptr<Gadget> enfant)
{
    m_panneau->ajouter ( enfant );
}


/////////////////////////////////////////////////
std::shared_ptr<Gadget> Support::retirer (std::shared_ptr<Gadget> enfant)
{
    m_panneau->retirer ( enfant );
}

} // fin namespace gui

