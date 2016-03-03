/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <PanSimple.h>
#include <Enums.h>



namespace gui {

/////////////////////////////////////////////////
PanSimple::PanSimple ()
: Panneau ()
{
    m_taille = { 400 , 200 };
    actualiser ();
}


/////////////////////////////////////////////////
void PanSimple::actualiser ()
{

    if ( ! m_necessiteActualisation )
        return;


    m_fond->setTaille(m_taille);
    m_contenant->setSize({ m_taille.x , m_taille.y });

    m_fond->setStyle ( m_skin->getStyle ( Styles::fond ) );

    actualiserContenu();

    actualiser_bounds ();

    if ( m_parent != nullptr ) m_parent->actualiserContenu();
    m_necessiteActualisation = false;
}


/////////////////////////////////////////////////
void PanSimple::draw (sf::RenderTarget& target, sf::RenderStates states) const
{

    if ( estVisible() ) {

        //On applique la transformation
        states.transform *= getTransform();

        target.draw( *m_fond , states );
        target.draw( *m_contenant , states );

    }

}


} // fin namespace gui

