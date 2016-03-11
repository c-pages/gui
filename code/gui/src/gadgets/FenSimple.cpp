/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <FenSimple.h>
#include <Interface.h>



namespace gui {

/////////////////////////////////////////////////
FenSimple::FenSimple ()
: Fenetre       ( )
, m_titre       ( std::make_shared<AffBarreTitre>() )
, m_btnFermer   ( std::make_shared<BtnIcone>() )
, m_btnDrag     ( std::make_shared<BtnRectangle>() )
, m_fermable    ( true )
, m_draggable   ( true )
, m_decalageDragSouris ( { 0, 0 } )
{
    m_taille = { 300,200 };
    m_marge = { 6 , 6 };

    ajouterComposant( m_titre );
    ajouterComposant( m_btnFermer );
    ajouterComposant( m_btnDrag );

//    // icone titre par defaut
//    chargerIcone   ( "media/img/Icone_test x16.png" );

    // icone fermer par defaut
//    m_btnFermer->chargerDepuisFichier   ( "media/img/ico_fenetreFermer.png" );


    m_btnFermer->setImage   ( &Interface::ms_icones.get( "ico_fenetre" ) );
    m_btnFermer->setIconeIndex ( 1 );

    m_btnFermer->setFix                 ( true );
    m_btnFermer->setVisible             ( m_fermable );
    m_btnDrag->setVisible               ( m_draggable );

    // Action du bouton slider
    m_btnDrag->lier ( Evenement::onBtnG_presser , [this](){

        demander_aEtre_auDessus();

        m_decalageDragSouris = sf::Vector2i ( getPosSouris().x - getPosition().x , getPosSouris().y - getPosition().y );
        setDrag( true );
        positionnerFenetre ();
//        m_necessiteActualisation = true ;
//        actualiser ();
    });
    m_btnDrag->lier ( Evenement::onBtnG_relacher , [this](){
        //demander_aEtre_auDessus();
        setDrag( false );
//        m_necessiteActualisation = false ;
//        actualiser ();
    });
    m_btnDrag->lier ( Evenement::onBtnG_relacherDehors , [this](){
        //demander_aEtre_auDessus();
        setDrag( false );
//        m_necessiteActualisation = false ;
//        actualiser ();
    });

    // Action du bouton fermer
    m_btnFermer->lier ( Evenement::onBtnG_relacher , [this](){
        demander_aEtre_supprimer ();
    });


    // Action du gadget
    this->lier ( Evenement::onBtnG_presser , [this](){
//        std::cout << "Fenetre presse\n";
        demander_aEtre_auDessus ();
    });



    m_titreFondCouleur      = sf::Color( 55,55,55);
    m_titreFondLgnCouleur   = sf::Color( 90,90,90);
    m_titreFondLgnepaisseur = 1;
    m_titreTextCouleur      = sf::Color( 200,200,200);
    m_titreTextStyle        = sf::Text::Style::Regular;
    m_titreTextTaille       = 10;
    m_titreTextPolice       = Interface::ms_polices.get( "Defaut" );

    m_btnFermerCouleurs.set       ( sf::Color( 0, 0, 0, 50 )     , Etat::desactive );
    m_btnFermerCouleurs.set       ( sf::Color( 255,255,255, 0 )  , Etat::repos );
    m_btnFermerCouleurs.set       ( sf::Color( 255,255,255, 15 ) , Etat::survol );
    m_btnFermerCouleurs.set       ( sf::Color( 255,255,255, 30 ) , Etat::press );
    m_btnFermerLgnCouleurs.set    ( sf::Color( 255,255,255, 100 ) );
    m_btnFermerLgnepaisseurs.set  ( 0 );

    actualiser();
}

/////////////////////////////////////////////////
void FenSimple::traiterEvenements (const sf::Event& evenement)
{
//   std::cout << " evt\n";
     if ( dragEnCours() )
        positionnerFenetre ();

    for ( auto enfant : m_enfants )
        enfant->traiterEvenements ( evenement);

    for ( auto composant : m_composants )
        composant->traiterEvenements ( evenement);
}






/////////////////////////////////////////////////
void FenSimple::actualiserGeometrie (){


    m_titre->setTailleX     ( m_taille.x - 2*m_marge.x );
    m_titre->setPosition    ( m_marge.x , m_marge.y );

    m_btnFermer->setTaille  ( { m_titre->getTaille().y , m_titre->getTaille().y } );
    m_btnFermer->setPosition( m_taille.x - m_btnFermer->getTaille().y - m_marge.x , m_marge.y );

    m_btnDrag->setTaille    ( { m_titre->getTaille().x - m_btnFermer->getTaille().y  , m_titre->getTaille().y } );
    m_btnDrag->setPosition  ( m_marge.x , m_marge.y );

    m_panneau->setTaille    ( { m_taille.x - 2*m_marge.x, m_taille.y - m_titre->getTaille().y - 2*m_marge.y } );
    m_panneau->setPosition  ( m_marge.x , m_titre->getTaille().y + m_marge.y );
    //m_panneau->actualiser   ( );

    m_fond->setTaille       ( m_taille );
    m_fond->setPosition     ( 0 , 0 );

    m_ombre->setPosition    ( 5,5 );
    m_ombre->setTaille      ( m_taille );

}


/////////////////////////////////////////////////
void FenSimple::actualiserStyle ()
{
    m_btnFermer->setImage   ( &Interface::ms_icones.get( "ico_fenetre" ) );

    Fenetre::actualiserStyle ();

    m_btnDragCouleurs       = sf::Color::Transparent;
    m_btnDragLgnCouleurs    = sf::Color::Transparent;
    m_btnDragLgnepaisseurs  = 0;


    m_titre->setTexteTaille         ( m_titreTextTaille );
    m_titre->setTexteCouleur        ( m_titreTextCouleur );
    m_titre->setPolice              ( m_titreTextPolice );
    m_titre->setTexteStyle          ( m_titreTextStyle );
    m_titre->setFillColor           ( m_titreFondCouleur ) ;
    m_titre->setOutlineColor        ( m_titreFondLgnCouleur  ) ;
    m_titre->setOutlineThickness    ( m_titreFondLgnepaisseur  );

    m_btnDrag->setFillColor         ( m_btnDragCouleurs ) ;
    m_btnDrag->setOutlineColor      ( m_btnDragLgnCouleurs  ) ;
    m_btnDrag->setOutlineThickness  ( m_btnDragLgnepaisseurs  );

    m_btnFermer->setFillColor         ( m_btnFermerCouleurs ) ;
    m_btnFermer->setOutlineColor      ( m_btnFermerLgnCouleurs  ) ;
    m_btnFermer->setOutlineThickness  ( m_btnFermerLgnepaisseurs  );



/*
    sf::Color      m_titreFondCouleur;
    sf::Color      m_titreFondLgnCouleur;
    float          m_titreFondLgnepaisseur;

    sf::Color              m_titreTextCouleur;
    sf::Text::Style        m_titreTextStyle;
    float                  m_titreTextTaille;
    sf::Font               m_titreTextPolice;

    Valeurs<sf::Color>      m_btnDragCouleurs;
    Valeurs<sf::Color>      m_btnDragLgnCouleurs;
    Valeurs<float>          m_btnDragLgnepaisseurs;

    Valeurs<sf::Color>      m_btnFermerCouleurs;
    Valeurs<sf::Color>      m_btnFermerLgnCouleurs;
    Valeurs<float>          m_btnFermerLgnepaisseurs;


    m_contenant->setFillColor       ( m_contenantCouleur ) ;
    m_contenant->setOutlineColor    ( m_contenantLgnCouleur  ) ;
    m_contenant->setOutlineThickness( m_contenantLgnepaisseur  );
*/

}

/*
/////////////////////////////////////////////////
void FenSimple::actualiser ()



//    m_btndrag->setStyle     ( m_skin->getStyle(Styles::invisible));
//    m_fond->setStyle        ( m_skin->getStyle(Styles::fenetre));
//    m_btnFermer->setStyle   ( m_skin->getStyle(Styles::bouton));
//    m_titre->setStyle       ( m_skin->getStyle(Styles::txtTitre));


//    m_titre->setTailleX     ( m_taille.x  );
//    m_btndrag->setTaille    ( { m_titre->getTaille().x - m_titre->getTaille().y  , m_titre->getTaille().y } );
//    m_panneau->setTaille    ( { m_taille.x , m_taille.y - m_titre->getTaille().y } );
//    m_panneau->setPosition  ( 0 , m_titre->getTaille().y );
//    m_fond->setTaille       ( { m_taille.x + 2*m_marge.x , m_taille.y + 2*m_marge.y } );
//    m_fond->setPosition     ( - m_marge.x , - m_marge.y );
//
//    m_btnFermer->setTaille  ( { m_titre->getTaille().y , m_titre->getTaille().y } );
//    m_btnFermer->setPosition( m_taille.x - m_titre->getTaille().y  , 0 );
//
//    m_btndrag->setStyle     ( m_skin->getStyle(Styles::invisible));
//    m_fond->setStyle        ( m_skin->getStyle(Styles::fenetre));
//    m_btnFermer->setStyle   ( m_skin->getStyle(Styles::bouton));
//    m_titre->setStyle       ( m_skin->getStyle(Styles::txtTitre));

}*/

std::shared_ptr<Gadget>  FenSimple::testerSurvol ( sf::Vector2i position )
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
//        else {
//            // sinon on regarde si on survol un enfant
//            auto testEnfants = testerSurvolComposite( { position.x + m_posX_texture, position.y + m_posY_texture } );
//            if ( testEnfants != nullptr )
//                return testEnfants;
//           else return thisPtr();
////             else return nullptr;
//        }
    }
    else return nullptr;
}



/////////////////////////////////////////////////
void FenSimple::chargerIcone   (std::string fichier )
{
    m_titre->setIconeImage( fichier );
}




/////////////////////////////////////////////////
void FenSimple::positionnerFenetre ()
{

    setPosition ( getPosSouris().x - m_decalageDragSouris.x  , getPosSouris().y - m_decalageDragSouris.y );

//    actualiser ();
}




} // fin namespace gui

