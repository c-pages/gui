/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Composite.h>

#include <Gadget.h>
#include <Gadget.h>


namespace gui {

/////////////////////////////////////////////////
void Composite::ajouter (std::shared_ptr<Gadget> enfant)
{
    m_enfants.push_back( enfant );
}

/*
/////////////////////////////////////////////////
std::shared_ptr<Gadget> Composite::chercherEnfantSurvole ( sf::Vector2i pos )
{
    for (auto enfant : m_enfants )
        if ( enfant->testerSurvol ( pos ) ) {
            if ( enfant->aDesEnfants() ) {
                std::shared_ptr<Gadget> result;
                result = enfant->chercherEnfantSurvole( pos );
                if ( result != nullptr )
                     return result;
                else return enfant;
            } else return enfant;
        }
    return nullptr;
}
*/


/////////////////////////////////////////////////
void Composite::retirer (std::shared_ptr<Gadget> enfant)
{

}


} // fin namespace gui

