/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <SppFenetre.h>



namespace gui {

/////////////////////////////////////////////////
SppFenetre::SppFenetre ()
: Support       ( )
, m_titre       ( std::make_shared<AffBarreTitre>() )
, m_btnFermer   ( std::make_shared<BtnIcone>() )
, m_btndrag     ( std::make_shared<BtnRectangle>() )
, m_fermable    ( true )
, m_draggable   ( true )
, m_decalageDragSouris ( { 0, 0 })
{
    m_taille = {300,200};

    ajouterComposant( m_btnFermer );
    ajouterComposant( m_titre );
    ajouterComposant( m_btndrag );


    chargerIcone   ( "media/img/ico_fenetre.png" );


//    std::string fichier = "media/img/ico_fenetreFermer.png";
    m_btnFermer->chargerDepuisFichier   ( "media/img/ico_fenetreFermer.png" );
    m_btnFermer->setFix                 ( true );
    m_btnFermer->setVisible             ( m_fermable );


    // Action du slider
    m_btndrag->lier ( Evenement::onBtnG_presser , [this](){
        m_decalageDragSouris = sf::Vector2i ( getPosSouris().x - getPosition().x , getPosSouris().y - getPosition().y );
        setDrag( true );
        positionnerFenetre ();
        m_necessiteActualisation = true ;
        actualiser ();
    });
    m_btndrag->lier ( Evenement::onBtnG_relacher , [this](){
        setDrag( false );
        m_necessiteActualisation = false ;
        actualiser ();
    });
    m_btndrag->lier ( Evenement::onBtnG_relacherDehors , [this](){
        setDrag( false );
        m_necessiteActualisation = false ;
        actualiser ();
    });


    m_btnFermer->lier ( Evenement::onBtnG_relacher , [this](){
        demander_aEtre_supprimer ();
    });


//
//
//    // Action du slider
//    lier ( Evenement::onBtnG_presser , [this](){
//        m_decalageDragSouris = sf::Vector2i ( getPosSouris().x - getPosition().x , getPosSouris().y - getPosition().y );
//        setDrag( true );
//        positionnerFenetre ();
////        m_necessiteActualisation = true ;
//        actualiser ();
//    });
//    lier ( Evenement::onBtnG_relacher , [this](){
//        setDrag( false );
////        m_necessiteActualisation = false ;
//        actualiser ();
//    });
//    lier ( Evenement::onBtnG_relacherDehors , [this](){
//        setDrag( false );
////        m_necessiteActualisation = false ;
//        actualiser ();
//    });
}

/////////////////////////////////////////////////
void SppFenetre::traiterEvenements (const sf::Event& evenement)
{
//   std::cout << " evt\n";
  /*   if ( dragEnCours() )
        positionnerFenetre ();*/

    for ( auto enfant : m_enfants )
        enfant->traiterEvenements ( evenement);

    for ( auto composant : m_composants )
        composant->traiterEvenements ( evenement);
}
/*
void SppFenetre::draw (sf::RenderTarget& target, sf::RenderStates states) const
{
    if ( dragEnCours() )
        positionnerFenetre ();
}
*/
/**/
/////////////////////////////////////////////////
void SppFenetre::actualiser ( sf::Time delta )
{
//   std::cout << " actualiser Delta\n";
    if ( dragEnCours() )
        positionnerFenetre ();
}




/////////////////////////////////////////////////
void SppFenetre::actualiser ()
{

    m_titre->setTailleX     ( m_taille.x  );
    m_btndrag->setTaille    ( { m_titre->getTaille().x - m_titre->getTaille().y  , m_titre->getTaille().y } );
    m_panneau->setTaille    ( { m_taille.x , m_taille.y - m_titre->getTaille().y } );
    m_panneau->setPosition  ( 0 , m_titre->getTaille().y );
    m_fond->setTaille       ( m_taille );
    m_btnFermer->setTaille  ( { m_titre->getTaille().y , m_titre->getTaille().y } );
    m_btnFermer->setPosition( m_taille.x - m_titre->getTaille().y  , 0 );

    m_btndrag->setStyle     ( m_skin->getStyle(Styles::invisible));
    m_fond->setStyle        ( m_skin->getStyle(Styles::fenetre));
    m_btnFermer->setStyle   ( m_skin->getStyle(Styles::bouton));
    m_titre->setStyle       ( m_skin->getStyle(Styles::txtTitre));

}

std::shared_ptr<Gadget>  SppFenetre::testerSurvol ( sf::Vector2i position )
{
    // si on est dans le panneau
    if ( m_globalBounds.contains( position.x, position.y ) && estActif() )
    {
        // si on survol un gadget composant (slider)
        auto testInterfaceLocal = testerSurvolComposants( position );
        if ( testInterfaceLocal != nullptr )
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
void SppFenetre::chargerIcone   (std::string fichier )
{
    m_titre->setIconeImage( fichier );
}




/////////////////////////////////////////////////
void SppFenetre::positionnerFenetre ()
{

    setPosition ( getPosSouris().x - m_decalageDragSouris.x  , getPosSouris().y - m_decalageDragSouris.y );

   // actualiser ();
}




} // fin namespace gui

