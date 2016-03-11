
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
//    m_interfaceParent->ms_calque_bureau->ajouter ( nouveauGadget );

//    // Application du skin de l'interface au gadget
//    nouveauGadget->setSkin ( m_interfaceParent->getSkin() );

    // renvois du nouveau gadget créé.
    return nouveauGadget;

}


/////////////////////////////////////////////////
template<typename T>
std::shared_ptr<T>  FabriqueBase::creerBureau (){

    // Creation du nouveau gadget
    std::shared_ptr<T> nouveauGadget = std::make_shared<T>( );

    // Affiliation a l'interface
    m_interfaceParent->ajouter ( nouveauGadget );
    nouveauGadget->setParent ( m_interfaceParent );
    m_interfaceParent->ms_calque_bureau->ajouter ( nouveauGadget );

//    // Application du skin de l'interface au gadget
//    nouveauGadget->setSkin ( m_interfaceParent->getSkin() );

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
    m_interfaceParent->ms_calque_fenetres->ajouter ( nouveauGadget );

    m_interfaceParent->demanderActualisation();
//    // Application du skin de l'interface au gadget
//    nouveauGadget->setSkin ( m_interfaceParent->getSkin() );

    // renvois du nouveau gadget créé.
    return nouveauGadget;

}

/////////////////////////////////////////////////
template<typename T>
std::shared_ptr<T>  FabriqueBase::creerBandeau (){

    // Creation du nouveau gadget
    std::shared_ptr<T> nouveauGadget = std::make_shared<T>( );

    // La hierarchie
    m_interfaceParent->ajouter  ( nouveauGadget );
    nouveauGadget->setParent    ( m_interfaceParent );
    m_interfaceParent->ms_calque_bandeaux->ajouter ( nouveauGadget );

    // la reference à l'interface parent.
    nouveauGadget->setInterface( m_interfaceParent );
    m_interfaceParent->demanderActualisation();

    // renvois du nouveau gadget créé.
    return nouveauGadget;

}


/////////////////////////////////////////////////
template<typename T>
std::shared_ptr<T>  FabriqueBase::creerPanneau (){

    // Creation du nouveau gadget
    std::shared_ptr<T> nouveauGadget = std::make_shared<T>( );

    // La hierarchie
    m_interfaceParent->ajouter  ( nouveauGadget );
    nouveauGadget->setParent    ( m_interfaceParent );
    m_interfaceParent->ms_calque_panneau_G->ajouter ( nouveauGadget );

    // la reference à l'interface parent.
    nouveauGadget->setInterface( m_interfaceParent );
    m_interfaceParent->demanderActualisation();

    // renvois du nouveau gadget créé.
    return nouveauGadget;

}




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////






/////////////////////////////////////////////////
std::shared_ptr<AffRectangle>    FabriqueBase::rectangle( sf::Vector2i taille )
{
    auto nouveauGadget = creerBureau<AffRectangle>( );
    nouveauGadget->setTaille ( taille );
    return nouveauGadget;
}



/////////////////////////////////////////////////
std::shared_ptr<AffLabel>    FabriqueBase::label( std::string text )
{
    auto nouveauGadget = creerBureau<AffLabel>( );
    nouveauGadget->setTexte ( text );
    return nouveauGadget;
}

/////////////////////////////////////////////////
std::shared_ptr<AffImage>    FabriqueBase::image( std::string fichier )
{
    auto nouveauGadget = creerBureau<AffImage>( );
    if ( fichier != "");
        nouveauGadget->chargerDepuisFichier ( fichier );
    return nouveauGadget;
}



/////////////////////////////////////////////////
std::shared_ptr<AffBarreTitre>    FabriqueBase::barreTitre( std::string text )
{
    auto nouveauGadget = creerBureau<AffBarreTitre>( );
    nouveauGadget->setTexte ( text );
    return nouveauGadget;
}

/*
/////////////////////////////////////////////////
std::shared_ptr<AffImage>    FabriqueBase::image( int id )
{
    auto nouveauGadget = creerBureau<AffImage>( );
//    if ( fichier != "");
//        nouveauGadget->chargerDepuisFichier ( fichier );
    return nouveauGadget;
}
*/


/////////////////////////////////////////////////
std::shared_ptr<AffIcone>    FabriqueBase::icone( std::string fichier , unsigned int id )
{
    auto nouveauGadget = creerBureau<AffIcone>( );
    if ( fichier != "");
        nouveauGadget->chargerDepuisFichier ( fichier );
    nouveauGadget->setIndex ( id );
    return nouveauGadget;
}




/////////////////////////////////////////////////
std::shared_ptr<BtnRectangle>    FabriqueBase::boutonRect( sf::Vector2i taille )
{
    auto nouveauGadget = creerBureau<BtnRectangle>( );
    nouveauGadget->setTaille ( taille );
    return nouveauGadget;
}



/////////////////////////////////////////////////
std::shared_ptr<BtnTexte>    FabriqueBase::boutonTexte( std::string texte )
{
    auto nouveauGadget = creerBureau<BtnTexte>( );
    nouveauGadget->setTexte ( texte );
    return nouveauGadget;
}


/////////////////////////////////////////////////
std::shared_ptr<BtnIcone>    FabriqueBase::boutonIcone( std::string fichier )
{
    auto nouveauGadget = creerBureau<BtnIcone>( );
    if ( fichier != "");
        nouveauGadget->chargerDepuisFichier ( fichier );
    return nouveauGadget;

}




/*
/////////////////////////////////////////////////
std::shared_ptr<BtnRectangle>    FabriqueBase::bouton( sf::Vector2i taille )
{
    auto nouveauGadget = creerBureau<BtnRectangle>( );
    nouveauGadget->setTaille ( taille );
    return nouveauGadget;
}*/

/////////////////////////////////////////////////
std::shared_ptr<BtnMenu>   FabriqueBase::menu( )
{
    return creerBureau<BtnMenu>( );
}


/////////////////////////////////////////////////
std::shared_ptr<DnCaseACocher>        FabriqueBase::btnACocher( bool val )
{
    auto nouveauGadget = creerBureau<DnCaseACocher>( );
    nouveauGadget->setValeur ( val );
    return nouveauGadget;
}


/////////////////////////////////////////////////
std::shared_ptr<DnZoneTexte>        FabriqueBase::zoneTexte( std::string texte )
{
    auto nouveauGadget = creerBureau<DnZoneTexte>( );
    nouveauGadget->setTexte ( texte );
    return nouveauGadget;
}

/////////////////////////////////////////////////
std::shared_ptr<DnSlider>        FabriqueBase::slider( )
{
    auto nouveauGadget = creerBureau<DnSlider>( );
    return nouveauGadget;
}


/////////////////////////////////////////////////
std::shared_ptr<DnBarreDefilement>        FabriqueBase::barreDefilement( )
{
    auto nouveauGadget = creerBureau<DnBarreDefilement>( );
    return nouveauGadget;
}

/////////////////////////////////////////////////
std::shared_ptr<BtnBarreOutils>    FabriqueBase::barreOutils(  )
{
    auto nouveauGadget = creerGadget<BtnBarreOutils>( );
    return nouveauGadget;
}




/////////////////////////////////////////////////
std::shared_ptr<GrpSimple>        FabriqueBase::groupe( )
{
    auto nouveauGadget = creerBureau<GrpSimple>( );
    return nouveauGadget;
}

/////////////////////////////////////////////////
std::shared_ptr<GrpSliders>        FabriqueBase::groupeSliders( )
{
    auto nouveauGadget = creerBureau<GrpSliders>( );
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



/////////////////////////////////////////////////
std::shared_ptr<FenPanneau>    FabriqueBase::panneau( std::string titre  )
{
    auto nouveauGadget = creerGadget<FenPanneau>( );
    nouveauGadget->setTexte (titre);
    return nouveauGadget;
}




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////
std::shared_ptr<SupBandeau>    FabriqueBase::bandeau(  )
{
    auto nouveauGadget = creerBandeau<SupBandeau>( );
    return nouveauGadget;
}


/////////////////////////////////////////////////
std::shared_ptr<SupBandeauMenusDeroulants>    FabriqueBase::menusDeroulants(  )
{
//    auto nouveauGadget = creerBandeau<SupBandeauMenusDeroulants>( );

    std::shared_ptr<SupBandeauMenusDeroulants> nouveauGadget = std::make_shared<SupBandeauMenusDeroulants>( );

    // La hierarchie
    m_interfaceParent->ms_calque_bandeauMenuDeroulants->ajouter ( nouveauGadget );

    // la reference à l'interface parent.
    nouveauGadget->setInterface( m_interfaceParent );



    return nouveauGadget;
}



/////////////////////////////////////////////////
std::shared_ptr<SupPanneau>    FabriqueBase::supportPanneaux(  )
{
    auto nouveauGadget = creerPanneau<SupPanneau>( );
    return nouveauGadget;
}


}; // fin namespace gui















