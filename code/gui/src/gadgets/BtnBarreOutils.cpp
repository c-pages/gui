/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <BtnBarreOutils.h>
#include "GrpSimple.h"
#include "Interface.h"



namespace gui {

/////////////////////////////////////////////////
BtnBarreOutils::BtnBarreOutils ( )
: m_fond    ( std::make_shared<AffRectangle>() )
, m_ombre   ( std::make_shared<AffRectangle>() )
, m_modeFenetre(false)
{
    m_taille  = { 10, 26 };
    m_marge  = { 2,2 };
    m_tailleBouton = { m_taille.y - 2*m_marge.y , m_taille.y - 2*m_marge.y };
    m_largeurDrag = 5 ;

    ajouterComposant( m_ombre );
    ajouterComposant( m_fond );
    m_ombre->setVisible ( false );
    m_ombre->setPosition ( 5,5);
//    ajouterComposant( m_panneau );



    m_fndCouleur        = sf::Color( 60, 60, 60 );
    m_fndLgnCouleur     = sf::Color( 90,90,90 );
    m_fndLgnEpaisseur   = 1 ;

    m_ombreCouleur                  = sf::Color( 0,0,0, 100 );
    m_ombreLgnCouleur               = sf::Color( 255,255,255, 255 );
    m_ombreLgnepaisseur             = 0;






    lier ( Evenement::onBtnG_presser , [this](){
        auto posBack = getPosAbs();

        m_decalageDragSouris = sf::Vector2i ( getPosSouris().x - posBack.x , getPosSouris().y - posBack.y );
        Interface::ms_calque_fenetres->ajouter( thisPtr() );
        setDrag( true );
        positionnerFenetre ();

        m_ombre->setVisible ( true );

    });

    lier ( Evenement::onBtnG_relacher , [this](){

        if ( dragEnCours() ){
            bool survolBandeau = false;
            for ( auto bandeau : Interface::ms_calque_bandeaux->getEnfants() )
            {
                if ( bandeau->testerSurvol( getPosSouris() ) != nullptr) {
                    bandeau->ajouter ( thisPtr() );
                    survolBandeau = true;
                }
                bandeau->setAbsorbable( false );
            }
            if ( survolBandeau )            {
                m_ombre->setVisible ( false );
            }
            Interface::ms_calque_bandeaux->actualiser();

            setDrag( false );
         }
    });
    lier ( Evenement::onBtnG_relacherDehors , [this](){
        if ( dragEnCours() ){
            bool survolBandeau = false;
            for ( auto bandeau : Interface::ms_calque_bandeaux->getEnfants() )
                if ( bandeau->testerSurvol( getPosSouris() ) != nullptr) {
                    bandeau->ajouter ( thisPtr() );
                    survolBandeau = true;
                    bandeau->setAbsorbable( false );
                }
            if ( survolBandeau )            {
                m_ombre->setVisible ( false );
            }
            Interface::ms_calque_bandeaux->actualiser();
            setDrag( false );
         }
    });


}

/////////////////////////////////////////////////
void BtnBarreOutils::traiterEvenements (const sf::Event& evenement)
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
void BtnBarreOutils::ajouterElement (std::string nom, std::string fichierIcone, FctnAction action )
{

    ElementOutil *    nouvelElement = new ElementOutil ();


    std::shared_ptr<BtnIcone>     bouton = std::make_shared<BtnIcone>( );

    bouton->setMarge            ( { 5 , 2 } );
    bouton->chargerDepuisFichier ( fichierIcone );
    bouton->setIconeIndex       ( m_elements.size() +1 );
    bouton->setAutoAjuster      ( false );
    bouton->setTaille           ( m_tailleBouton );
    bouton->setMarge            ({0,0});

    bouton->lier                ( Evenement::onBtnG_relacher , action );

    ajouter           ( bouton );
//    m_panneau->ajouter( bouton );

    nouvelElement->nom      = nom;
    nouvelElement->fonction = action;
    nouvelElement->bouton   = bouton;

    m_elements.push_back( nouvelElement );

    actualiser ();
}


/////////////////////////////////////////////////
void BtnBarreOutils::positionnerFenetre ()
{
    setPosition ( getPosSouris().x - m_decalageDragSouris.x  , getPosSouris().y - m_decalageDragSouris.y );

    bool survolBandeau = false;

    for ( auto bandeau : Interface::ms_calque_bandeaux->getEnfants() )
        if ( bandeau->testerSurvol( getPosSouris() ) != nullptr) {
                bandeau->setAbsorbable( true );
        } else
                bandeau->setAbsorbable( false );

//    Interface::ms_calque_bandeaux->actualiser();
//    for ( auto bandeau : Interface::ms_calque_bandeaux->getEnfants() )
//        if ( bandeau->testerSurvol( getPosSouris() ) != nullptr)
//            bandeau->

}


/////////////////////////////////////////////////
std::shared_ptr<Gadget>  BtnBarreOutils::testerSurvol ( sf::Vector2i position )
{
    // pour gerer le survol d'un bandeau quand on drag, on renvois false pour qu'il continue la recherche (en dessous).
     if ( dragEnCours() ) return false;

//    std::cout << "Bouton : Tester survol : " << Gadget::testerSurvol ( position ) << "\n";
    return Gadget::testerSurvol ( position );
}




/////////////////////////////////////////////////
void BtnBarreOutils::supprimerElement (unsigned int id)
{

}
/*
/////////////////////////////////////////////////
void BtnBarreOutils::actualiserContenu ()
{
    m_panneau->actualiserContenu ();


};*/

/////////////////////////////////////////////////
void BtnBarreOutils::actualiserGeometrie ()
{
//    std::cout << "Actualiser la barre d'outils\n";

    m_taille.x =  m_largeurDrag + m_tailleBouton.x * m_elements.size() + 2*m_marge.x;
    m_fond->setTaille ( m_taille );
    m_ombre->setTaille ( m_taille );
//    m_panneau->setTaille ( { m_taille.x - 2*m_marge.x, m_taille.y - 2*m_marge.y } );
//    m_panneau->setPosition ( m_marge.x, m_marge.y  );

    int index = 0;
    for ( auto element : m_elements ) {

        element->bouton->setPosition    (  m_largeurDrag + m_marge.x + index * ( m_tailleBouton.x ) , m_marge.y );

        index++;
    }

    actualiserBounds ();

}
/*
/////////////////////////////////////////////////
void BtnBarreOutils::actualiserBounds ()
{
    sf::Vector2f pos = getPosAbs ();

    m_globalBounds.left     = pos.x;
    m_globalBounds.top      = pos.y;
    m_globalBounds.width    = getTaille().x;
    m_globalBounds.height   = getTaille().y;

    m_localBounds.left      = getPosition().x;
    m_localBounds.top       = getPosition().y;
    m_localBounds.width     = getTaille().x;
    m_localBounds.height    = getTaille().y;



}*/


/////////////////////////////////////////////////
void BtnBarreOutils::actualiserStyle ()
{
    m_fond->setFillColor (m_fndCouleur);
    m_fond->setOutlineColor (m_fndLgnCouleur);
    m_fond->setOutlineThickness (m_fndLgnEpaisseur);

    m_ombre->setFillColor (m_ombreCouleur);
    m_ombre->setOutlineColor (m_ombreLgnCouleur);
    m_ombre->setOutlineThickness (m_ombreLgnepaisseur);

}

/*
/////////////////////////////////////////////////
void BtnBarreOutils::draw (sf::RenderTarget& target, sf::RenderStates states) const
{

}*/


} // fin namespace gui

