/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Composite.h>

#include <Gadget.h>


namespace gui {

/////////////////////////////////////////////////
void Composite::ajouter (std::shared_ptr<Gadget> enfant)
{
        std::cout << "Composite::ajouter\n";
    // si l'enfant avait un parent on le retire de sa liste des enfants
    auto parentBack = enfant->getParent();
    if ( parentBack != nullptr ){
        parentBack->retirer ( enfant );
        std::cout << "POR LOOOOOOOOOOOOOOOooooooooooooooooooo.................\n";
    }

    m_enfants.push_back( enfant );
    enfant->setParent ( static_cast<Gadget*>(this) );
    static_cast<Gadget*>(this)->actualiser();
    enfant->actualiser();
//    actualiser();
}



/////////////////////////////////////////////////
std::shared_ptr<Gadget> Composite::retirer ( std::shared_ptr<Gadget> gadget )
{
        std::cout << "Composite::retirer\n";
    int i = 0;
    for ( auto enfant : m_enfants ){
        if ( enfant == gadget ) {
            m_enfants.erase( m_enfants.begin()+i );
            return enfant;
        }
        i++;
    }
}

/////////////////////////////////////////////////
void Composite::demander_aEtre_supprimer (){
    m_parent->supprimer ( thisPtr() );
}



/////////////////////////////////////////////////
void Composite::supprimer (std::shared_ptr<Gadget> gadget ){

    int i = 0;
    for ( auto enfant : m_enfants ){
        if ( enfant == gadget ) {
            m_enfants.erase( m_enfants.begin()+i );
            return;
        }
        i++;
    }

}


/////////////////////////////////////////////////
void Composite::dessinerEnfants (sf::RenderTarget& target, sf::RenderStates states) const
{

    for ( auto enfant : m_enfants )
        target.draw( *enfant , states);
}


} // fin namespace gui

