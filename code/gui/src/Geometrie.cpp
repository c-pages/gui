/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Geometrie.h>
#include <Gadget.h>
#include <..\Patch.h>



namespace gui {

/////////////////////////////////////////////////
void Geometrie::setTaille( float x, float y ){
    setTaille( sf::Vector2i ( x, y ) );
};

/////////////////////////////////////////////////
void Geometrie::setTaille( sf::Vector2i val ){
    if ( m_taille == val ) return;
    m_taille = val;
    static_cast<Gadget*>(this)->demanderActuaGeom();
};



/////////////////////////////////////////////////
void Geometrie::setTailleX( float val ){
    if ( m_taille.x == val ) return;
    m_taille.x = val;
    static_cast<Gadget*>(this)->demanderActuaGeom();
};



/////////////////////////////////////////////////
void Geometrie::setTailleY( float val ){
    if ( m_taille.y == val ) return;
    m_taille.y = val;
    static_cast<Gadget*>(this)->demanderActuaGeom();
};


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

}



} // fin namespace gui

