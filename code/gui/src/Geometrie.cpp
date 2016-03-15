/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Geometrie.h>
#include <Gadget.h>
#include <..\Patch.h>



namespace gui {

/////////////////////////////////////////////////
void Geometrie::setPosAbs (sf::Vector2f posAbsDest )
{
    sf::Vector2f posAbsParent = {0,0};
    if (m_parent != nullptr)
        posAbsParent = m_parent->getPosAbs();
    setPosition( posAbsDest.x -  posAbsParent.x , posAbsDest.y -  posAbsParent.y ) ;
}

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

};

/////////////////////////////////////////////////
void Geometrie::Aligner ( std::shared_ptr<Gadget> cible, Alignement alignement, Alignement alignementCible)
{

}


/////////////////////////////////////////////////
void Geometrie::actualiserBounds ()
{
    static_cast<Gadget*>(this)->log ( "ActualiserBounds  ");
//    log ( "m_taille" + patch::to_string(m_taille.x) + ", " + patch::to_string(m_taille.y) );
    static_cast<Gadget*>(this)->log (  "taille" , getTaille() );

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

