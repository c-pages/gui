/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Geometrie.h>
#include <Gadget.h>



namespace gui {

/////////////////////////////////////////////////
sf::Vector2f Geometrie::getPosAbs () const
{
    if ( m_parent != nullptr){

//    std::cout << "** a un parent ** -> pos = " << getPosition().x << ", " << getPosition().y << "\n" ;
        return getPosition() + m_parent->getPosAbs();
    }
    else{

//        std::cout << "** a PAS parent **\n" ;
        return getPosition();
    }
}


/////////////////////////////////////////////////
void Geometrie::Aligner ( std::shared_ptr<Gadget> cible, Alignement alignement, Alignement alignementCible)
{

}


/////////////////////////////////////////////////
void Geometrie::actualiser_bounds ()
{
    sf::Vector2f pos = getPosAbs ();
//    std::cout << "actualiser_bounds : " << pos.x <<", " << pos.y << "\n" ;

    m_globalBounds.left     = pos.x;
    m_globalBounds.top      = pos.y;
    m_globalBounds.width    = m_taille.x;
    m_globalBounds.height   = m_taille.y;



}


/*
/////////////////////////////////////////////////
std::shared_ptr<Gadget> Geometrie::testerSurvol (int x, int y)
{
    return testerSurvol (sf::Vector2i ( x , y));
}

/////////////////////////////////////////////////
std::shared_ptr<Gadget> Geometrie::testerSurvol (sf::Vector2i position)
{
//    if ( m_globalBounds.contains( position.x, position.y ) )
//        std::cout << "CONTIENTPOPO";

//    return m_globalBounds.contains( position.x, position.y );
   if ( m_globalBounds.contains( position.x, position.y ) )
        return thisPtr();
    else
        return nullptr;
}*/


} // fin namespace gui

