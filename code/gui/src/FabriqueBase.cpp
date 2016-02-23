#include "FabriqueBase.h"

#include <iostream>

namespace gui{


/////////////////////////////////////////////////
std::shared_ptr<AffRectangle>    FabriqueBase::rectangle( sf::Vector2i taille )
{
    // Creation du nouveau gadget
    std::shared_ptr<AffRectangle> nouveauGadget = std::make_shared<AffRectangle>();

    // Affiliation au gadget racine courant
    Gadget::ms_racineCourante->ajouter ( nouveauGadget );
    nouveauGadget->setParent ( Gadget::ms_racineCourante );

    // renvois du nouveau gadget cr��.
    return nouveauGadget;
}



/////////////////////////////////////////////////
std::shared_ptr<AffLabel>    FabriqueBase::label( std::string text )
{
    // Creation du nouveau gadget
    std::shared_ptr<AffLabel> nouveauGadget = std::make_shared<AffLabel>();

    // Affiliation au gadget racine courant
    Gadget::ms_racineCourante->ajouter ( nouveauGadget );
    nouveauGadget->setParent ( Gadget::ms_racineCourante );

    // D�finition du texte du label
    nouveauGadget->setTexte ( text );

    // renvois du nouveau gadget cr��.
    return nouveauGadget;
}

/////////////////////////////////////////////////
std::shared_ptr<AffImage>    FabriqueBase::image( std::string fichier )
{

    // Creation du nouveau gadget
    std::shared_ptr<AffImage> nouveauGadget = std::make_shared<AffImage>();

    // Affiliation au gadget racine courant
    Gadget::ms_racineCourante->ajouter ( nouveauGadget );
    nouveauGadget->setParent ( Gadget::ms_racineCourante );

    // D�finition du fichier de l'image
    if ( fichier != "" )
        nouveauGadget->chargerDepuisFichier ( fichier );

    // renvois du nouveau gadget cr��.
    return nouveauGadget;
}

}; // fin namespace gui
