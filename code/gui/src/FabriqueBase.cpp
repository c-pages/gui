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

    // Chargement du fichier de l'image
    nouveauGadget->chargerDepuisFichier ( fichier );

    // renvois du nouveau gadget cr��.
    return nouveauGadget;
}

/////////////////////////////////////////////////
std::shared_ptr<BtnRectangle>    FabriqueBase::bouton( std::string texte )
{

    // Creation du nouveau gadget
    std::shared_ptr<BtnRectangle> nouveauGadget = std::make_shared<BtnRectangle>();

//    // on l'ajoute � la liste static des boutons
//    Bouton::ms_boutons.push_back( nouveauGadget );

    // Affiliation au gadget racine courant
    Gadget::ms_racineCourante->ajouter ( nouveauGadget );
    nouveauGadget->setParent ( Gadget::ms_racineCourante );

    // D�finition du texte du bouton
    nouveauGadget->setTexte ( texte );

    // renvois du nouveau gadget cr��.
    return nouveauGadget;
}

/////////////////////////////////////////////////
std::shared_ptr<BtnRectangle>    FabriqueBase::bouton( sf::Vector2i taille )
{

    // Creation du nouveau gadget
    std::shared_ptr<BtnRectangle> nouveauGadget = std::make_shared<BtnRectangle>();

//    // on l'ajoute � la liste static des boutons
//    Bouton::ms_boutons.push_back( nouveauGadget );

    // Affiliation au gadget racine courant
    Gadget::ms_racineCourante->ajouter ( nouveauGadget );
    nouveauGadget->setParent ( Gadget::ms_racineCourante );

    // D�finition du texte du bouton
    nouveauGadget->setTaille ( taille );

    // renvois du nouveau gadget cr��.
    return nouveauGadget;
}

/////////////////////////////////////////////////
std::shared_ptr<BtnMenu>   FabriqueBase::menu( )
{

    // Creation du nouveau gadget
    std::shared_ptr<BtnMenu> nouveauGadget = std::make_shared<BtnMenu>();

//    // on l'ajoute � la liste static des boutons
//    Bouton::ms_boutons.push_back( nouveauGadget );

    // Affiliation au gadget racine courant
    Gadget::ms_racineCourante->ajouter ( nouveauGadget );
    nouveauGadget->setParent ( Gadget::ms_racineCourante );

    // renvois du nouveau gadget cr��.
    return nouveauGadget;
}


/////////////////////////////////////////////////
std::shared_ptr<DnCaseACocher>        FabriqueBase::btnACocher( bool val )
{
    // Creation du nouveau gadget
    std::shared_ptr<DnCaseACocher> nouveauGadget = std::make_shared<DnCaseACocher>();

//    // on l'ajoute � la liste static des boutons
//    Bouton::ms_boutons.push_back( nouveauGadget );

    // Affiliation au gadget racine courant
    Gadget::ms_racineCourante->ajouter ( nouveauGadget );
    nouveauGadget->setParent ( Gadget::ms_racineCourante );

    // renvois du nouveau gadget cr��.
    return nouveauGadget;
}


/////////////////////////////////////////////////
std::shared_ptr<DnZoneTexte>        FabriqueBase::zoneTexte( std::string texte )
{
    // Creation du nouveau gadget
    std::shared_ptr<DnZoneTexte> nouveauGadget = std::make_shared<DnZoneTexte>();

//    // on l'ajoute � la liste static des boutons
//    Bouton::ms_boutons.push_back( nouveauGadget );

    // Affiliation au gadget racine courant
    Gadget::ms_racineCourante->ajouter ( nouveauGadget );
    nouveauGadget->setParent ( Gadget::ms_racineCourante );

    // D�finition du texte du bouton
    nouveauGadget->setTexte ( texte );

    // renvois du nouveau gadget cr��.
    return nouveauGadget;
}

/////////////////////////////////////////////////
std::shared_ptr<DnSlider>        FabriqueBase::slider( )
{
    // Creation du nouveau gadget
    std::shared_ptr<DnSlider> nouveauGadget = std::make_shared<DnSlider>();


    // Affiliation au gadget racine courant
    Gadget::ms_racineCourante->ajouter ( nouveauGadget );
    nouveauGadget->setParent ( Gadget::ms_racineCourante );

    // renvois du nouveau gadget cr��.
    return nouveauGadget;
}




}; // fin namespace gui
