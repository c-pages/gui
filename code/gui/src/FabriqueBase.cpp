#include "FabriqueBase.h"

#include <iostream>

namespace gui{


/////////////////////////////////////////////////
std::shared_ptr<AffRectangle>    FabriqueBase::rectangle( sf::Vector2i taille )
{
    // Creation du nouveau gadget
    std::shared_ptr<AffRectangle> nouveauGadget = std::make_shared<AffRectangle>( taille );

    // Affiliation au gadget racine courant
    Gadget::ms_racineCourante->ajouter ( nouveauGadget );
    nouveauGadget->setParent ( Gadget::ms_racineCourante );

    nouveauGadget->setTaille ( taille );
    // renvois du nouveau gadget créé.
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

    // Définition du texte du label
    nouveauGadget->setTexte ( text );

    // renvois du nouveau gadget créé.
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

    // Chargement du fichier de l'image
    nouveauGadget->chargerDepuisFichier ( fichier );

    // renvois du nouveau gadget créé.
    return nouveauGadget;
}

/////////////////////////////////////////////////
std::shared_ptr<BoutonRect>    FabriqueBase::bouton( std::string texte )
{

    // Creation du nouveau gadget
    std::shared_ptr<BoutonRect> nouveauGadget = std::make_shared<BoutonRect>();

    // Affiliation au gadget racine courant
    Gadget::ms_racineCourante->ajouter ( nouveauGadget );
    nouveauGadget->setParent ( Gadget::ms_racineCourante );

    // Définition du texte du bouton
    nouveauGadget->setTexte ( texte );

    // renvois du nouveau gadget créé.
    return nouveauGadget;
}

/////////////////////////////////////////////////
std::shared_ptr<BoutonRect>    FabriqueBase::bouton( sf::Vector2i taille )
{

    // Creation du nouveau gadget
    std::shared_ptr<BoutonRect> nouveauGadget = std::make_shared<BoutonRect>();

    // Affiliation au gadget racine courant
    Gadget::ms_racineCourante->ajouter ( nouveauGadget );
    nouveauGadget->setParent ( Gadget::ms_racineCourante );

    // Définition du texte du bouton
    nouveauGadget->setTaille ( taille );

    // renvois du nouveau gadget créé.
    return nouveauGadget;
}



}; // fin namespace gui
