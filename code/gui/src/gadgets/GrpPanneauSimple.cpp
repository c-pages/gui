/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <GrpPanneauSimple.h>
#include <Enums.h>



namespace gui {

/////////////////////////////////////////////////
GrpPanneauSimple::GrpPanneauSimple ()
: Groupement ()
{
    m_taille = { 400 , 200 };
    actualiser ();
}


/////////////////////////////////////////////////
void GrpPanneauSimple::actualiser ()
{

    m_fond->setTaille(m_taille);
    m_contenant->setSize({ m_taille.x , m_taille.y });

    m_fond->setStyle ( m_skin->getStyle ( Styles::fond ) );

    actualiserContenu();

    actualiser_bounds ();

}


/////////////////////////////////////////////////
void GrpPanneauSimple::draw (sf::RenderTarget& target, sf::RenderStates states) const
{

    if ( estVisible() ) {

        //On applique la transformation
        states.transform *= getTransform();

        target.draw( *m_fond , states );
        target.draw( *m_contenant , states );

    }

}


} // fin namespace gui

