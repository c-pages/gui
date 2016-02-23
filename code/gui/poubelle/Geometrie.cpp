/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Geometrie.h>
#include <iostream>
#include <memory>



namespace gui {

///////////////////////////////////////////////////
//sf::Vector2f Geometrie::getPosAbs () const
//{
////    if ( m_parent != nullptr )
////        std::cout << " Il a un parent\n";
////    else
////        std::cout << " Il a PAAAAAS de parent\n";
//}


/////////////////////////////////////////////////
void Geometrie::Aligner (std::shared_ptr<Gadget> cible)
{

}


/////////////////////////////////////////////////
bool Geometrie::testerSurvol (int x, int y) const
{

}


/////////////////////////////////////////////////
void Geometrie::actualiser_bounds ()
{
    // les bounds en local
    m_localBounds.width     = m_taille.x;
    m_localBounds.height    = m_taille.y;
    m_localBounds.left      = getPosition().x;
    m_localBounds.top       = getPosition().y;


    // les bounds en Global
    m_globalBounds.width    = m_taille.x;
    m_globalBounds.height   = m_taille.y;
//    m_globalBounds.left     = getPosAbs().x;
//    m_globalBounds.top      = getPosAbs().y;
}




} // fin namespace gui

