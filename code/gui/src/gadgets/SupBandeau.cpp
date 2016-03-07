/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Interface.h>
#include <SupBandeau.h>
#include <PanSliders.h>



namespace gui {

/////////////////////////////////////////////////
SupBandeau::SupBandeau (){
    m_marge = { 3 , 2 };
    m_taille = { 150 , 30 };
}


/////////////////////////////////////////////////
void SupBandeau::actualiserGeometrie ()
{
    Support::actualiserGeometrie();
    int posX = m_marge.x;
    for (auto enfant : m_enfants )
    {
        enfant->setPosition    ( posX ,  m_marge.y );
        posX += enfant->getTaille().x + m_marge.x;
    }

//    int index = 0;
//    for ( auto element : m_elements ) {
//
//        element->bouton->setPosition    ( index * ( m_tailleMenu.x + m_ecart ) + m_marge.x ,  m_marge.y );
//        element->bouton->setTexte       ( element->nom );
//
//        index++;
//    }
    actualiserBounds ();

    /*    std::cout << " BAH IL PASS PAR ICI ON DIRAIT BIEN\n";
    if (m_interface != nullptr)
    {
        auto tailleFenetre = m_interface->getFenetre()->getSize();
        m_taille = {tailleFenetre.x , 27};
    }
    m_fond->setTaille ( m_taille );*/
}




/////////////////////////////////////////////////
void SupBandeau::actualiserStyle ()
{
    Support::actualiserStyle();

}



/*
/////////////////////////////////////////////////
void SupBandeau::draw (sf::RenderTarget& target, sf::RenderStates states) const
{

}
*/

} // fin namespace gui

