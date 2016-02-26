/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Geometrie.h>
#include <Gadget.h>



namespace gui {

/////////////////////////////////////////////////
sf::Vector2f Geometrie::getPosAbs () const
{
    if ( m_parent != nullptr)
        return getPosition() + m_parent->getPosAbs();
    else
        return getPosition();
}


/////////////////////////////////////////////////
void Geometrie::Aligner ( std::shared_ptr<Gadget> cible, Alignement alignement, Alignement alignementCible)
{

}


/////////////////////////////////////////////////
void Geometrie::actualiser_bounds ()
{
    sf::Vector2f pos = getPosAbs ();

    m_globalBounds.left     = pos.x;
    m_globalBounds.top      = pos.y;
    m_globalBounds.width    = m_taille.x;
    m_globalBounds.height   = m_taille.y;

    m_localBounds.left      = getPosition().x;
    m_localBounds.top       = getPosition().y;
    m_localBounds.width     = m_taille.x;
    m_localBounds.height    = m_taille.y;
}



} // fin namespace gui

