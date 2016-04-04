/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Fenetre.h"
#include "decorations/FenDecoDrag.h"
#include "decorations/FenDecoRedim.h"
#include "decorations/FenDecoRedimPanneau.h"

#include <Interface.h>

#include "gadgets_outils/CntSliders.h"
//#include <CntSimple.h>


namespace gui {

/////////////////////////////////////////////////
Fenetre::Fenetre ()
: m_contenant       ( std::make_shared<CntSliders>() )
//, m_titre           ( std::make_shared<AffBarreTitre>() )
, m_tailleBoutons   ( { 18 , 18 } )
{
    creerNomUnique ( "Fenetre");


    // initialiser les composants herités
    CmpOmbre::initialiserComposants ( this );
    CmpFond::initialiserComposants ( this );
    CmpBarreTitre::initialiserComposants ( this );

    // les composants
    ajouterComposant( m_contenant );

    m_taille = { 350 , 200 };
    m_redimensionnable = true;
    m_deplacable = true;

    // les decorations
    if ( m_redimensionnable )
        ajouterDecoration ( Decorations::Retaille );
    if ( m_deplacable )
        ajouterDecoration ( Decorations::Drag );

    // les couleurs
    m_contenantFndCouleur             = sf::Color( 70,70,70, 255 );
    m_contenantFndLgnCouleur          = sf::Color( 90,90,90 );
    m_contenantFndLgnepaisseur        = 1;
    m_contenantContenantCouleur       = sf::Color( 255,255,255, 255 );
    m_contenantContenantLgnCouleur    = sf::Color( 90,90,90, 255 );
    m_contenantContenantLgnepaisseur  = 0;
//
//    m_titreFondCouleur              = sf::Color( 55,55,55);
//    m_titreFondLgnCouleur           = sf::Color( 90,90,90);
//    m_titreFondLgnepaisseur         = 1;
//
//    m_titreTextCouleur              = sf::Color( 255,255,255);
//    m_titreTextStyle                = sf::Text::Style::Regular;
//    m_titreTextTaille               = 10;
//    m_titreTextPolice               = Interface::ms_polices.get( "Defaut" );
//
    m_fondCouleur                   = sf::Color( 60,60,60, 255 );
    m_fondLgnCouleur                = sf::Color( 90,90,90, 255 );
    m_fondLgnEpaisseur              = 1;
//
//    m_ombreCouleur                  = sf::Color( 0,0,0, 100 );

}

/////////////////////////////////////////////////
void Fenetre::ajouterDecoration ( Decorations deco  )
{
    // si il est deja dans la liste on zappe.
    if ( m_decorations.find( deco ) != m_decorations.end() )
    {
//        std::cout<<"Ajouter Decoration : deja present\n";
        return;
    }

//    std::cout<<"Ajouter Decoration : ok\n";

    switch ( deco )    {
        case Decorations::Drag:
            m_decorations.insert( { deco , std::make_shared<FenDecoDrag> ( this ) } );
            break;
        case Decorations::Retaille:
            m_decorations.insert( { deco , std::make_shared<FenDecoRedim> ( this ) } );
            break;
        case Decorations::RetaillePanneau:
            m_decorations.insert( { deco , std::make_shared<FenDecoRedimPanneau> ( this ) } );
            break;
        default:break;
    }
    demanderActualisation();
};

///////////////////////////////////////////////////
//void Fenetre::chargerIcone   (std::string fichier )
//{
////    m_titre->setIconeImage( fichier );
//}



/////////////////////////////////////////////////
void Fenetre::traiterEvenements (const sf::Event& evenement)
{
    for(auto deco : m_decorations)
        deco.second->traiterEvenements ( evenement );

    for ( auto enfant : m_enfants )
        enfant->traiterEvenements ( evenement);

    for ( auto composant : m_composants )
        composant->traiterEvenements ( evenement);

}


/////////////////////////////////////////////////
void Fenetre::setDefilementActif (bool val)
{

}

/////////////////////////////////////////////////
void Fenetre::ajouter ( std::shared_ptr<Gadget>  enfant )
{
    m_contenant->ajouter ( enfant );
    if (m_parent != nullptr)
        m_parent->actualiserContenu();
}


/////////////////////////////////////////////////
std::shared_ptr<Gadget> Fenetre::retirer (std::shared_ptr<Gadget> enfant)
{
    m_contenant->retirer ( enfant );
}



/////////////////////////////////////////////////
void Fenetre::actualiserEtatDeco ( )
{
    if ( m_parent != nullptr ){
        // si on est dans le calque fenetres on redimmenssione des 4 cotés
        if ( m_parent->getNom() == Interface::ms_calque_fenetres->getNom() ){
            retirerDecoration ( Decorations::RetaillePanneau );
            ajouterDecoration ( Decorations::Retaille );
        // sinon on est dans le calque panneau on redimmenssione par le bas
        } else {
            retirerDecoration ( Decorations::Retaille );
            ajouterDecoration ( Decorations::RetaillePanneau );
        }
    }
}
/////////////////////////////////////////////////
void Fenetre::actualiserGeometrie ()
{

    for(auto deco : m_decorations)
        deco.second->actualiserGeometrie ();

    // on actualise le titre
    CmpBarreTitre::actualiserGeometrie();


    m_contenant->setTaille    ( { m_taille.x - 2*m_marge.x, m_taille.y - m_titreFond->getTaille().y - 2*m_marge.y } );
    m_contenant->setPosition  ( m_marge.x , m_titreFond->getTaille().y + m_marge.y );


    m_fond->setTaille       ( m_taille );
    m_fond->setPosition     ( 0 , 0 );

    m_ombre->setTaille      ( m_taille );

    demanderActuaBounds();
}

/////////////////////////////////////////////////
void Fenetre::actualiserStyle ()
{

    for(auto deco : m_decorations)
        deco.second->actualiserStyle ();

    m_contenant->setFondCouleur            ( m_contenantFndCouleur ) ;
    m_contenant->setFondLigneCouleur         ( m_contenantFndLgnCouleur  ) ;
    m_contenant->setFondLigneEpaisseur     ( m_contenantFndLgnepaisseur  );

    m_contenant->setContenantFillColor       ( m_contenantContenantCouleur ) ;
    m_contenant->setContenantOutlineColor    ( m_contenantContenantLgnCouleur  ) ;
    m_contenant->setContenantOutlineThickness( m_contenantContenantLgnepaisseur  );


    // on actualise le titre
    CmpBarreTitre::actualiserStyle();

    // on actualise le fond
    m_fond->setFondCouleur          ( m_fondCouleur.repos );
    m_fond->setFondLigneCouleur     ( m_fondLgnCouleur.repos );
    m_fond->setFondLigneEpaisseur   ( m_fondLgnEpaisseur.repos );

}

/*
/////////////////////////////////////////////////
std::shared_ptr<Gadget>  Fenetre::testerSurvol ( sf::Vector2i position )
{
    // si on est dans le panneau
    if ( m_globalBounds.contains( position.x, position.y ) && estActif() )
    {
        // si on survol un gadget composant (slider)
        auto testInterfaceLocal = testerSurvolComposants( position );
        if ( testInterfaceLocal == m_contenant )
            return thisPtr();
        else if ( testInterfaceLocal != nullptr )
            // on le renvois
            return testInterfaceLocal;
        else return thisPtr();
    }
    else return nullptr;
}
*/


} // fin namespace gui

