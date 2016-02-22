/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Cliquable.h>
#include <Bouton.h>

#include <iostream>

namespace gui {


/////////////////////////////////////////////////
// Initialisation des statics
/////////////////////////////////////////////////
//std::vector<Cliquable::clickPtr>    Cliquable::ms_Boutons;
//Cliquable::clickPtr                 Cliquable::ms_btnSurvole = nullptr;
//Cliquable::clickPtr                 Cliquable::ms_btnPresse = nullptr;

/////////////////////////////////////////////////
/*void Cliquable::s_traiterEvents ()
{

}*/


/////////////////////////////////////////////////
bool Cliquable::testerSurvol ( sf::Vector2i position )
{
//    std::cout << "pos souris : " << position.x << " , " << position.y << "\n";
//    std::cout << "pos gadget : " << getPosition().x << " , " << getPosition().y << "\n";
//    std::cout << "taille gadget : " << m_taille.x << " , " << m_taille.y << "\n";

    if ( m_globalBounds.contains( position.x , position.y ) )
        return true;
    else
        return false;


}


///////////////////////////////////////////////////
//void Cliquable::actualiser ()
//{
//    std::cout << "Cliquable::actualiser()\n";
//}


/////////////////////////////////////////////////
void Cliquable::setEtat ()
{

}


} // fin namespace gui

