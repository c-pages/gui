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



/////////////////////////////////////////////////
std::shared_ptr<Gadget> Composite::retirer ( std::shared_ptr<Gadget> gadget )
{
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

} // fin namespace gui

