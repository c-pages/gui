#include "FenPanneau.h"
#include <Interface.h>

namespace gui {

/////////////////////////////////////////////////
FenPanneau::FenPanneau()
: FenSimple ()
, m_btn_retaille    ( std::make_shared<BtnRectangle>() )
, m_btn_reduire     ( std::make_shared<BtnIcone>() )
{
    m_marge = { 4, 4};
    ajouterComposant ( m_btn_retaille );
    ajouterComposant ( m_btn_reduire );

    m_titre->setTailleY ( 16 );

    m_btn_reduire->lier ( Evenement::onBtnG_relacher , [this](){
                         if ( m_reduit )    agrandir();
                         else               reduire();
                        });
    m_draggable = false;

    m_btn_reduire->setImage   ( &Interface::ms_icones.get( "ico_fenetre" ) );
    m_btn_reduire->setIconeIndex ( 2 );


    m_btn_reduire->setFix                 ( true );

    auto fct_redimStartB = [this](){
            m_sourisPosOrigin = getPosSouris();
            m_tailleOrigin = m_taille;
            m_posOrigin = getPosition();
            m_redimBas = true;
        };
    auto fct_redimStopB = [this](){ m_redimBas = false; actualiserBounds(); };

    m_btn_retaille->lier (Evenement::onBtnG_presser , fct_redimStartB );
    m_btn_retaille->lier (Evenement::onBtnG_relacher, fct_redimStopB );
    m_btn_retaille->lier (Evenement::onBtnG_relacherDehors, fct_redimStopB );

    // delier des actions de drag heritées ... pas terrible mais bon ...
    m_btnDrag->delier ( Evenement::onBtnG_presser );
    m_btnDrag->delier ( Evenement::onBtnG_relacher );
    m_btnDrag->delier ( Evenement::onBtnG_relacherDehors );
    this->delier ( Evenement::onBtnG_presser );
    m_ombre->setVisible ( false );



    m_btnDrag->lier ( Evenement::onBtnG_presser , [this](){
        auto posBack = getPosAbs();

        m_decalageDragSouris = sf::Vector2i ( getPosSouris().x - posBack.x , getPosSouris().y - posBack.y );
        Interface::ms_calque_fenetres->ajouter( thisPtr() );
        setDrag( true );
        positionnerFenetre ();

        m_ombre->setVisible ( true );

    });
    auto ftn_relacher = [this](){

        if ( dragEnCours() ){
            bool survolPanneau = false;
            for ( auto panneau : Interface::ms_calque_panneau_D->getEnfants() )
            {
                if ( panneau->testerSurvol( getPosSouris() ) != nullptr) {
                    panneau->ajouter ( thisPtr() , getPosSouris() );
                    survolPanneau = true;
                }
                panneau->setAbsorbable( false );
            }
            for ( auto panneau : Interface::ms_calque_panneau_G->getEnfants() )
            {
                if ( panneau->testerSurvol( getPosSouris() ) != nullptr) {
                    panneau->ajouter ( thisPtr() , getPosSouris());
                    survolPanneau = true;
                }
                panneau->setAbsorbable( false );
            }
            if ( survolPanneau )            {
                m_ombre->setVisible ( false );
            }
            Interface::ms_calque_panneau_D->actualiser();
            Interface::ms_calque_panneau_G->actualiser();

            setDrag( false );
         }
    };
    m_btnDrag->lier ( Evenement::onBtnG_relacher , ftn_relacher );
    m_btnDrag->lier ( Evenement::onBtnG_relacherDehors , ftn_relacher );

}

/////////////////////////////////////////////////
void FenPanneau::traiterEvenements (const sf::Event& evenement)
{
//   std::cout << " evt\n";
     if ( dragEnCours() )
        positionnerFenetre ();

    if ( m_redimBas )   { redimmensionner_bas (); }

    for ( auto enfant : m_enfants )
        enfant->traiterEvenements ( evenement);

    for ( auto composant : m_composants )
        composant->traiterEvenements ( evenement);


//    FenSimple::traiterEvenements (evenement);
}


/////////////////////////////////////////////////
void FenPanneau::positionnerFenetre ()
{
    setPosition ( getPosSouris().x - m_decalageDragSouris.x  , getPosSouris().y - m_decalageDragSouris.y );

    for ( auto panneau : Interface::ms_calque_panneau_D->getEnfants() )
    {
        if ( panneau->testerSurvol( getPosSouris() ) != nullptr)
                panneau->setAbsorbable( true );
        else    panneau->setAbsorbable( false );
    }
    for ( auto panneau : Interface::ms_calque_panneau_G->getEnfants() )
    {
        if ( panneau->testerSurvol( getPosSouris() ) != nullptr)
                panneau->setAbsorbable( true );
        else    panneau->setAbsorbable( false );
    }


}
/////////////////////////////////////////////////
void FenPanneau::actualiserGeometrie()
{
//    std::cout << "par ici là : " << m_btnFermer->getTaille().x << ", " << m_btnFermer->getTaille().y << "\n";
    FenSimple::actualiserGeometrie();
    if ( m_reduit )
    {
        m_fond->setTaille       ( { m_taille.x, m_titre->getTaille().y + 2*m_marge.y } ) ;
        m_fond->setPosition     ( 0 , 0 );

        m_ombre->setPosition    ( 5,5 );
        m_ombre->setTaille      ( m_fond->getTaille() );
//        return;
    }


    m_btn_reduire->setTaille ( m_btnFermer->getTaille() );
    if ( ! m_fermable )
            m_btn_reduire->setPosition  ( m_taille.x -  m_btnFermer->getTaille().x - m_marge.x
                                        , m_marge.y );
    else    m_btn_reduire->setPosition  ( m_taille.x -  2* m_btnFermer->getTaille().x - m_marge.x
                                        , m_marge.y );
    m_btn_retaille->setTaille    ( {m_taille.x , m_marge.y } );
    m_btn_retaille->setPosition    ( 0  , m_taille.y - m_marge.y );


}


///////////////////////////////////////////////////
//void FenPanneau::traiterEvenements (const sf::Event& evenement)
//{
//    if ( m_redimBas )   { redimmensionner_bas (); }
//
//    FenSimple::traiterEvenements (evenement);
//}


/////////////////////////////////////////////////
void FenPanneau::redimmensionner_bas ()
{
    auto posSouris = getPosSouris();
    m_taille = { m_taille.x , m_tailleOrigin.y + ( posSouris.y - m_sourisPosOrigin.y  ) };

//    demander_aEtre_auDessus();
    corrigerTailleMinimum ();

    if ( m_taille.y == m_titre->getTaille().y + m_marge.y*2 )
    {
        m_panneau->setVisible (false);
    } else m_panneau->setVisible (true );


    actualiserGeometrie();
//    m_parent->actualiserGeometrie();
    m_parent->actualiserEnfants();
}



/////////////////////////////////////////////////
void FenPanneau::corrigerTailleMinimum ()
{
    if ( m_taille.y < m_titre->getTaille().y + m_marge.y*2 )
        m_taille.y = m_titre->getTaille().y + m_marge.y*2;


}


/////////////////////////////////////////////////
void FenPanneau::actualiserStyle()
{

}

FenPanneau::~FenPanneau()
{

}


} // fin namespace gui
