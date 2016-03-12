/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Fenetre.h>
#include <decorations/FenDecoDrag.h>
#include <decorations/FenDecoRedim.h>
#include <decorations/FenDecoRedimPanneau.h>

#include <Interface.h>

#include <GrpSliders.h>
#include <GrpSimple.h>


namespace gui {

/////////////////////////////////////////////////
Fenetre::Fenetre ()
: m_panneau         ( std::make_shared<GrpSliders>() )
, m_fond            ( std::make_shared<AffRectangle>() )
, m_ombre           ( std::make_shared<AffRectangle>() )
, m_titre           ( std::make_shared<AffBarreTitre>() )
, m_tailleBoutons   ( { 18 , 18 } )
{
    m_taille = { 350 , 200 };
    m_redimensionnable = true;
    m_deplacable = true;

    // les composants
    ajouterComposant( m_ombre );
    ajouterComposant( m_fond );
    ajouterComposant( m_panneau );
    ajouterComposant( m_titre );

    // les decorations
    if ( m_redimensionnable )
        ajouterDecoration ( Decorations::Retaille );
    if ( m_deplacable )
        ajouterDecoration ( Decorations::Drag );

    // les couleurs
    m_panneauFndCouleur             = sf::Color( 70,70,70, 255 );
    m_panneauFndLgnCouleur          = sf::Color( 90,90,90 );
    m_panneauFndLgnepaisseur        = 1;
    m_panneauContenantCouleur       = sf::Color( 255,255,255, 255 );
    m_panneauContenantLgnCouleur    = sf::Color( 90,90,90, 255 );
    m_panneauContenantLgnepaisseur  = 0;

    m_titreFondCouleur              = sf::Color( 55,55,55);
    m_titreFondLgnCouleur           = sf::Color( 90,90,90);
    m_titreFondLgnepaisseur         = 1;

    m_titreTextCouleur              = sf::Color( 200,200,200);
    m_titreTextStyle                = sf::Text::Style::Regular;
    m_titreTextTaille               = 10;
    m_titreTextPolice               = Interface::ms_polices.get( "Defaut" );

    m_fondCouleur                   = sf::Color( 55,55,55, 255 );
    m_fondLgnCouleur                = sf::Color( 90,90,90, 255 );
    m_fondLgnepaisseur              = 1;

    m_ombreCouleur                  = sf::Color( 0,0,0, 100 );
    m_ombreLgnCouleur               = sf::Color( 255,255,255, 255 );
    m_ombreLgnepaisseur             = 0;
}

/////////////////////////////////////////////////
void Fenetre::ajouterDecoration ( Decorations deco  )
{
    // si il est deja dans la liste on zappe.
    if ( m_decorations.find( deco ) != m_decorations.end() )
    {
        std::cout<<"Ajouter Decoration : deja present\n";
        return;
    }

    std::cout<<"Ajouter Decoration : ok\n";

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
    actualiser();
};

/////////////////////////////////////////////////
void Fenetre::chargerIcone   (std::string fichier )
{
    m_titre->setIconeImage( fichier );
}



/////////////////////////////////////////////////
void Fenetre::traiterEvenements (const sf::Event& evenement)
{
    for(auto deco : m_decorations)
        deco.second->traiterEvenements ( evenement );



    for ( auto enfant : m_enfants )
        enfant->traiterEvenements ( evenement);

    for ( auto composant : m_composants )
        composant->traiterEvenements ( evenement);
//
//    // ?!?!?
//    viderTableaux();
}


/////////////////////////////////////////////////
void Fenetre::setDefilementActif (bool val)
{

}

/////////////////////////////////////////////////
void Fenetre::ajouter ( std::shared_ptr<Gadget> enfant )
{
    m_panneau->ajouter ( enfant );
    if (m_parent != nullptr)
        m_parent->actualiserContenu();
}


/////////////////////////////////////////////////
std::shared_ptr<Gadget> Fenetre::retirer (std::shared_ptr<Gadget> enfant)
{
    m_panneau->retirer ( enfant );
}

/////////////////////////////////////////////////
void Fenetre::setParent (Gadget* parent )
{
    m_parent = parent;
    if ( parent != nullptr ){
        if ( parent->getNom() == Interface::ms_calque_fenetres->getNom() ){
            retirerDecoration ( Decorations::RetaillePanneau );
            ajouterDecoration ( Decorations::Retaille );
        } else {
            retirerDecoration ( Decorations::Retaille );
            ajouterDecoration ( Decorations::RetaillePanneau );
        }
    }
}

/////////////////////////////////////////////////
void Fenetre::actualiserGeometrie ()
{

//    // ?!?!?
//    viderTableaux();

    m_panneau->setTaille    ( { m_taille.x - 2*m_marge.x, m_taille.y - getTailleBouton().y - 2*m_marge.y } );
    m_panneau->setPosition  ( m_marge.x , getTailleBouton().y + m_marge.y );
    m_panneau->actualiser   ( );

    m_titre->setTailleX     ( m_taille.x - 2*m_marge.x );
    m_titre->setTailleY     ( getTailleBouton().y );
    m_titre->setPosition    ( m_marge.x , m_marge.y );

    m_fond->setTaille       ( m_taille );
    m_fond->setPosition     ( 0 , 0 );

    m_ombre->setPosition    ( 5,5 );
    m_ombre->setTaille      ( m_taille );

    for(auto deco : m_decorations)
        deco.second->actualiserGeometrie ();

}

/////////////////////////////////////////////////
void Fenetre::actualiserStyle ()
{

    for(auto deco : m_decorations)
        deco.second->actualiserStyle ();

    m_panneau->setFillColor            ( m_panneauFndCouleur ) ;
    m_panneau->setOutlineColor         ( m_panneauFndLgnCouleur  ) ;
    m_panneau->setOutlineThickness     ( m_panneauFndLgnepaisseur  );

    m_panneau->setContenantFillColor       ( m_panneauContenantCouleur ) ;
    m_panneau->setContenantOutlineColor    ( m_panneauContenantLgnCouleur  ) ;
    m_panneau->setContenantOutlineThickness( m_panneauContenantLgnepaisseur  );


    m_titre->setTexteTaille         ( m_titreTextTaille );
    m_titre->setTexteCouleur        ( m_titreTextCouleur );
    m_titre->setPolice              ( m_titreTextPolice );
    m_titre->setTexteStyle          ( m_titreTextStyle );
    m_titre->setFillColor           ( m_titreFondCouleur ) ;
    m_titre->setOutlineColor        ( m_titreFondLgnCouleur  ) ;
    m_titre->setOutlineThickness    ( m_titreFondLgnepaisseur  );



    m_fond->setFillColor            ( m_fondCouleur ) ;
    m_fond->setOutlineColor         ( m_fondLgnCouleur  ) ;
    m_fond->setOutlineThickness     ( m_fondLgnepaisseur  );

    m_ombre->setFillColor            ( m_ombreCouleur ) ;
    m_ombre->setOutlineColor         ( m_ombreLgnCouleur  ) ;
    m_ombre->setOutlineThickness     ( m_ombreLgnepaisseur  );

}
/////////////////////////////////////////////////
std::shared_ptr<Gadget>  Fenetre::testerSurvol ( sf::Vector2i position )
{
    // si on est dans le panneau
    if ( m_globalBounds.contains( position.x, position.y ) && estActif() )
    {
        // si on survol un gadget composant (slider)
        auto testInterfaceLocal = testerSurvolComposants( position );
        if ( testInterfaceLocal == m_panneau )
            return thisPtr();
        else if ( testInterfaceLocal != nullptr )
            // on le renvois
            return testInterfaceLocal;
        else return thisPtr();
    }
    else return nullptr;
}



} // fin namespace gui

