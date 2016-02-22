/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Interface.h>
#include <iostream>

#include <Gadget.h>
#include <Bouton.h>
#include <FabriqueGadget.h>




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

    std::cout << "###########################################\n";
    std::cout << "Fabriquer un bouton...    \n";

    // Creation du bouton
    Gadget::ptr bouton = std::make_shared<Bouton> (  );

    // On ajoute le bouton � la racine de l'interface
    m_interface->ajouter ( bouton );

//    bouton->setSurvol ( false );
    // Si texte d�finie, on l'applique au bouton.
    if ( texte != "" ) {
        bouton->setTexte ( texte );
        bouton->ajusterAuTexte ();
    }

    std::cout << "... Bouton fabrique : OK\n";

    std::cout << "###########################################\n\n";
    // Renvois du bouton cr��.
    return bouton;

}


} // fin namespace gui

