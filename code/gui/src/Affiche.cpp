/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Affiche.h>

#include <iostream>

namespace gui {




/////////////////////////////////////////////////
void Affiche::ajouter (std::shared_ptr<Gadget> gadget)
{
    // Ne fait rien.
}


/////////////////////////////////////////////////
std::shared_ptr<Gadget> Affiche::retirer (std::shared_ptr<Gadget> enfant)
{
    // Ne fait rien.
}


/////////////////////////////////////////////////
std::shared_ptr<Gadget> Affiche::testerSurvol ( sf::Vector2i position )
{
//    std::cout << "Affiche::testerSurvol ()\n";
    // N'interagie pas avec la souris donc renvois toujours false.
    return nullptr;
}


} // fin namespace gui

