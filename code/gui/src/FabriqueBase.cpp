#include "FabriqueBase.h"

#include <iostream>

namespace gui{


/////////////////////////////////////////////////
template<typename T>
std::shared_ptr<T>  FabriqueBase::creerGadget (){
    // Creation du nouveau gadget
    std::shared_ptr<T> nouveauGadget = std::make_shared<T>( );

    // Affiliation au gadget racine courant
    Gadget::ms_racineCourante->ajouter ( nouveauGadget );
    nouveauGadget->setParent ( Gadget::ms_racineCourante );

    // renvois du nouveau gadget créé.
    return nouveauGadget;

}



/////////////////////////////////////////////////
std::shared_ptr<AffRectangle>    FabriqueBase::rectangle( sf::Vector2i taille )
{
    auto nouveauGadget = creerGadget<AffRectangle>( );
    nouveauGadget->setTaille ( taille );
    return nouveauGadget;
}



/////////////////////////////////////////////////
std::shared_ptr<AffLabel>    FabriqueBase::label( std::string text )
{
    auto nouveauGadget = creerGadget<AffLabel>( );
    nouveauGadget->setTexte ( text );
    return nouveauGadget;
}

/////////////////////////////////////////////////
std::shared_ptr<AffImage>    FabriqueBase::image( std::string fichier )
{
    auto nouveauGadget = creerGadget<AffImage>( );
    if ( fichier != "");
        nouveauGadget->chargerDepuisFichier ( fichier );
    return nouveauGadget;
}
/*
/////////////////////////////////////////////////
std::shared_ptr<AffImage>    FabriqueBase::image( int id )
{
    auto nouveauGadget = creerGadget<AffImage>( );
//    if ( fichier != "");
//        nouveauGadget->chargerDepuisFichier ( fichier );
    return nouveauGadget;
}
*/


/////////////////////////////////////////////////
std::shared_ptr<AffIcone>    FabriqueBase::icone( std::string fichier , unsigned int id )
{
    auto nouveauGadget = creerGadget<AffIcone>( );
    if ( fichier != "");
        nouveauGadget->chargerDepuisFichier ( fichier );
    nouveauGadget->setIndex ( id );
    return nouveauGadget;
}




/////////////////////////////////////////////////
std::shared_ptr<BtnRectangle>    FabriqueBase::boutonRect( sf::Vector2i taille )
{
    auto nouveauGadget = creerGadget<BtnRectangle>( );
    nouveauGadget->setTaille ( taille );
    return nouveauGadget;
}



/////////////////////////////////////////////////
std::shared_ptr<BtnTexte>    FabriqueBase::boutonTexte( std::string texte )
{
    auto nouveauGadget = creerGadget<BtnTexte>( );
    nouveauGadget->setTexte ( texte );
    return nouveauGadget;
}


/////////////////////////////////////////////////
std::shared_ptr<BtnIcone>    FabriqueBase::boutonIcone( std::string fichier )
{
    auto nouveauGadget = creerGadget<BtnIcone>( );
    if ( fichier != "");
        nouveauGadget->chargerDepuisFichier ( fichier );
    return nouveauGadget;

}




/*
/////////////////////////////////////////////////
std::shared_ptr<BtnRectangle>    FabriqueBase::bouton( sf::Vector2i taille )
{
    auto nouveauGadget = creerGadget<BtnRectangle>( );
    nouveauGadget->setTaille ( taille );
    return nouveauGadget;
}*/

/////////////////////////////////////////////////
std::shared_ptr<BtnMenu>   FabriqueBase::menu( )
{
    return creerGadget<BtnMenu>( );
}


/////////////////////////////////////////////////
std::shared_ptr<DnCaseACocher>        FabriqueBase::btnACocher( bool val )
{
    auto nouveauGadget = creerGadget<DnCaseACocher>( );
    nouveauGadget->setValeur ( val );
    return nouveauGadget;
}


/////////////////////////////////////////////////
std::shared_ptr<DnZoneTexte>        FabriqueBase::zoneTexte( std::string texte )
{
    auto nouveauGadget = creerGadget<DnZoneTexte>( );
    nouveauGadget->setTexte ( texte );
    return nouveauGadget;
}

/////////////////////////////////////////////////
std::shared_ptr<DnSlider>        FabriqueBase::slider( )
{
    auto nouveauGadget = creerGadget<DnSlider>( );
    return nouveauGadget;
}


/////////////////////////////////////////////////
std::shared_ptr<DnBarreDefilement>        FabriqueBase::barreDefilement( )
{
    auto nouveauGadget = creerGadget<DnBarreDefilement>( );
    return nouveauGadget;
}


/////////////////////////////////////////////////
std::shared_ptr<PanSimple>        FabriqueBase::panneau( )
{
    auto nouveauGadget = creerGadget<PanSimple>( );
    return nouveauGadget;
}

/////////////////////////////////////////////////
std::shared_ptr<PanSliders>        FabriqueBase::panneauSliders( )
{
    auto nouveauGadget = creerGadget<PanSliders>( );
    return nouveauGadget;
}

}; // fin namespace gui
