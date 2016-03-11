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


void Geometrie::setPosition( float x , float y ){
     sf::Transformable::setPosition( int ( x )  , int ( y ) );
     actualiserBounds();
     for ( auto enfant : m_enfants )
        enfant->actualiserBounds();
};

/////////////////////////////////////////////////
void Geometrie::Aligner ( std::shared_ptr<Gadget> cible, Alignement alignement, Alignement alignementCible)
{

}


/////////////////////////////////////////////////
void Geometrie::actualiserBounds ()
{
    sf::Vector2f pos = getPosAbs ();

    m_globalBounds.left     = pos.x;
    m_globalBounds.top      = pos.y;
    m_globalBounds.width    = getTaille().x;
    m_globalBounds.height   = getTaille().y;

    m_localBounds.left      = getPosition().x;
    m_localBounds.top       = getPosition().y;
    m_localBounds.width     = getTaille().x;
    m_localBounds.height    = getTaille().y;
    /*
    for ( auto enfant : m_enfants )
        actualiserBounds ();*/
}



} // fin namespace gui

