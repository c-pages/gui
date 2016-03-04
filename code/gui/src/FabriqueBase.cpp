
#include "FabriqueBase.h"
#include "Interface.h"


#include <iostream>


namespace gui{

/////////////////////////////////////////////////
FabriqueBase::FabriqueBase ( Interface* interfaceParent )
: m_interfaceParent ( interfaceParent )
{}



/////////////////////////////////////////////////
template<typename T>
std::shared_ptr<T>  FabriqueBase::creerGadget (){

    // Creation du nouveau gadget
    std::shared_ptr<T> nouveauGadget = std::make_shared<T>( );

    // Affiliation a l'interface
    m_interfaceParent->ajouter ( nouveauGadget );
    nouveauGadget->setParent ( m_interfaceParent );
    m_interfaceParent->m_calque_bureau->ajouter ( nouveauGadget );

    // Application du skin de l'interface au gadget
    nouveauGadget->setSkin ( m_interfaceParent->getSkin() );

    // renvois du nouveau gadget créé.
    return nouveauGadget;

}



/////////////////////////////////////////////////
template<typename T>
std::shared_ptr<T>  FabriqueBase::creerFenetre (){

    // Creation du nouveau gadget
    std::shared_ptr<T> nouveauGadget = std::make_shared<T>( );

    m_interfaceParent->ajouter ( nouveauGadget );
    nouveauGadget->setParent ( m_interfaceParent );
    m_interfaceParent->m_calque_fenetres->ajouter ( nouveauGadget );

    // Application du skin de l'interface au gadget
    nouveauGadget->setSkin ( m_interfaceParent->getSkin() );

    // renvois du nouveau gadget créé.
    return nouveauGadget;

}




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////






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



/////////////////////////////////////////////////
std::shared_ptr<AffBarreTitre>    FabriqueBase::barreTitre( std::string text )
{
    auto nouveauGadget = creerGadget<AffBarreTitre>( );
    nouveauGadget->setTexte ( text );
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


/////////////////////////////////////////////////
std::shared_ptr<FenSimple>        FabriqueBase::fenetre( std::string titre )
{
    auto nouveauGadget = creerFenetre<FenSimple>( );
    nouveauGadget->setTexte (titre);
    return nouveauGadget;
}


/////////////////////////////////////////////////

std::shared_ptr<FenRedim>        FabriqueBase::fenetreRedim( std::string titre  )
{
    auto nouveauGadget = creerFenetre<FenRedim>( );
    nouveauGadget->setTexte (titre);
    return nouveauGadget;
}

}; // fin namespace gui















