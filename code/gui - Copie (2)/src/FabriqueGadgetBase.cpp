/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <FabriqueGadgetBase.h>
#include <Bouton.h>
#include <Gui.h>

#include <iostream>


namespace gui {

/////////////////////////////////////////////////
FabriqueGadgetBase::FabriqueGadgetBase ( gui::Gui* interface )
{
    m_gui = interface ;
}



/////////////////////////////////////////////////
Gadget::ptr FabriqueGadgetBase::bouton (std::string texte)
{
    std::cout << "Creer bouton : " <<  texte << "\n";

    // Creation du bouton
    std::shared_ptr<Bouton> bouton = std::shared_ptr<Bouton> ( new Bouton( ) );

    // Definition du texte du boutn
    bouton->setTexte( texte);

    // Renvois d'un bouton
    return bouton;


}


/////////////////////////////////////////////////
Gadget::ptr FabriqueGadgetBase::label (std::string texte)
{
    std::cout << "Creer label : " <<  texte << "\n";

}


/////////////////////////////////////////////////
Gadget::ptr FabriqueGadgetBase::image (std::string fichier)
{
    std::cout << "Creer image : " <<  fichier << "\n";

}


} // fin namespace gui

