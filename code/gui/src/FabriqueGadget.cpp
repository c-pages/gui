/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Interface.h>
#include <Gadget.h>
#include <Bouton.h>
#include <FabriqueGadget.h>

#include <iostream>



namespace gui {

/////////////////////////////////////////////////
FabriqueGadget::FabriqueGadget ( Interface* gui )
: m_interface ( gui )
{

}

/////////////////////////////////////////////////
FabriqueGadget::FabriqueGadget (  )
: m_interface ( nullptr )
{

}

/////////////////////////////////////////////////
Gadget::ptr FabriqueGadget::texte ()
{

}


/////////////////////////////////////////////////
Gadget::ptr FabriqueGadget::image ()
{

}


/////////////////////////////////////////////////
Gadget::ptr FabriqueGadget::bouton ( std::string texte  )
{
    std::cout << "Fabriquer un bouton.\n";

    // Creation du bouton
    Gadget::ptr bouton = std::make_shared<Bouton>(  );


//m_interface->m_conteneur->popo();
    // Assignation du parent, le conteneur du gui ici.
    bouton->setParent(  m_interface->m_conteneur );

    std::cout << "Fabriquer un bouton :2\n";

    // Si texte d�finie, on l'applique au bouton.
    if ( texte != "" )
        bouton->setTexte(  texte );

    std::cout << "Fabriquer un bouton :fin\n";

    // Renvois du bouton cr��.
    return bouton;

}


} // fin namespace gui
