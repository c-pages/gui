/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <gadgets/BtnBarreFonctions.h>
//#include "CntSimple.h"
#include "gui.h"



namespace gui {

/////////////////////////////////////////////////
BtnBarreFonctions::BtnBarreFonctions ( )
: m_modeFenetre(false)
{
    creerNomUnique ("BarreFonctions");

    //debug
//    m_mute = false;

    // initialiser les composants herités
    CmpOmbre::initialiserComposants ( this );
    CmpFond::initialiserComposants ( this );

    m_taille  = { 10, 26 };
    m_marge  = { 2,2 };
    m_tailleBouton = { m_taille.y - 2*m_marge.y , m_taille.y - 2*m_marge.y };
    m_largeurDrag = 5 ;

//    ajouterComposant( m_ombre );
//    ajouterComposant( m_fond );

//    m_ombre->setVisible ( false );
//    m_ombre->setPosition ( 5,5);
//    ajouterComposant( m_panneau );



    m_fondCouleur        = sf::Color( 60, 60, 60 );
    m_fondLgnCouleur     = sf::Color( 90,90,90 );
    m_fondLgnEpaisseur   = 1 ;
//
//    m_ombreCouleur      = sf::Color( 0,0,0, 100 );
//    m_ombreLgnCouleur   = sf::Color( 255,255,255, 255 );
//    m_ombreLgnepaisseur = 0;






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
void BtnBarreFonctions::traiterEvenements (const sf::Event& evenement)
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
std::shared_ptr<BtnIcone>  BtnBarreFonctions::ajouterElement (std::string nom, std::string fichierIcone, FctnAction action )
{

    ElementOutil *    nouvelElement = new ElementOutil ();


    std::shared_ptr<BtnIcone>     bouton = std::make_shared<BtnIcone>( );

    bouton->setMarge            ( { 5 , 2 } );
    bouton->setImage            ( fichierIcone );
    bouton->setFix();
    bouton->setIndex            ( m_elements.size() + 1 );
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

    demanderActualisation();
//    actualiser ();

    return bouton;
}



/////////////////////////////////////////////////
std::shared_ptr<BtnIcone>     BtnBarreFonctions::ajouterElement (std::string nom, sf::Texture icone, FctnAction action)
{

    ElementOutil *    nouvelElement = new ElementOutil ();


    std::shared_ptr<BtnIcone>   bouton = std::make_shared<BtnIcone>( );

    bouton->setMarge            ( { 5 , 2 } );
    bouton->setImage            ( &icone );
    bouton->setFix();
    bouton->setIndex            ( m_elements.size() + 1 );
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

    demanderActualisation();
//    actualiser ();

    return bouton;
}


/////////////////////////////////////////////////
void BtnBarreFonctions::positionnerFenetre ()
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
std::shared_ptr<Gadget>  BtnBarreFonctions::testerSurvol ( sf::Vector2i position )
{
    // pour gerer le survol d'un bandeau quand on drag, on renvoie false pour qu'il continue la recherche (en dessous).
     if ( dragEnCours() ) return false;

//    std::cout << "Bouton : Tester survol : " << Gadget::testerSurvol ( position ) << "\n";
    return Gadget::testerSurvol ( position );
}




/////////////////////////////////////////////////
void BtnBarreFonctions::supprimerElement (unsigned int id)
{

}
/*
/////////////////////////////////////////////////
void BtnBarreFonctions::actualiserContenu ()
{
    m_panneau->actualiserContenu ();


};*/

/////////////////////////////////////////////////
void BtnBarreFonctions::actualiserGeometrie ()
{
    std::cout << "Actualiser la barre d'outils\n";

    // si on est dans un calque (nom commence par '_'), on est libre, alors on ombre
    if (m_parent->getNom()[0] == '_') {
    std::cout << "Dans Calque\n";
        setOmbreActive();
    }
    else {
    std::cout << " PAS Dans Calque\n";
            setOmbreActive ( false );

    }


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

    demanderActuaBounds();
}



/////////////////////////////////////////////////
void BtnBarreFonctions::actualiserStyle ()
{
    // on applique le style correspondant à l'état
    CmpFond::appliquerEtat( this->etat() );

}




} // fin namespace gui

