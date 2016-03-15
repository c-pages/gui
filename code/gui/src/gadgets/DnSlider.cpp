/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <DnSlider.h>
#include <Interface.h>



namespace gui {

/////////////////////////////////////////////////
DnSlider::DnSlider ()
: m_boutonFond  ( std::make_shared<BtnRectangle>() )
, m_slider      ( std::make_shared<BtnRectangle>() )
, m_fond        ( std::make_shared<AffRectangle>() )

//, m_styleBtnFond    ( std::make_shared<Style>() )
//, m_styleBtnSlider  ( std::make_shared<Style>() )
//, m_styleFond       ( std::make_shared<Style>() )

, m_valeurMax   ( 100 )
, m_valeurMin   ( 0 )
, m_horizontal  ( true )
, m_drag        ( false )
, m_longueur    ( 180 )
, m_largeur     ( 15 )
, m_decalageDragSouris ({0,0})
{
    m_marge.x = 0;
    m_marge.y = 0;

    // Ajouter les composant
    ajouterComposant( m_fond );
    ajouterComposant( m_boutonFond );
    ajouterComposant( m_slider );

    // valeurs par defaut
    m_btnCouleurs.set       ( sf::Color( 0, 0, 0, 50 )     , Etat::desactive );
    m_btnCouleurs.set       ( sf::Color( 255,255,255, 0 ) , Etat::repos );
    m_btnCouleurs.set       ( sf::Color( 255,255,255, 20 ) , Etat::survol );
    m_btnCouleurs.set       ( sf::Color( 255,255,255, 25 ) , Etat::press );
    m_btnLgnCouleurs.set    ( sf::Color( 255,255,255, 20 ) );
    m_btnLgnepaisseurs.set  ( 0 );

    m_slideCouleurs.set       ( sf::Color( 0, 0, 0, 50 )     , Etat::desactive );
    m_slideCouleurs.set       ( sf::Color( 255,255,255, 40 ) , Etat::repos );
    m_slideCouleurs.set       ( sf::Color( 255,255,255, 60 ) , Etat::survol );
    m_slideCouleurs.set       ( sf::Color( 255,255,255, 80 ) , Etat::press );
    m_slideLgnCouleurs.set    ( sf::Color( 255,255,255, 20 ) );
    m_slideLgnepaisseurs.set  ( 0 );

    m_fndCouleur            = sf::Color::Transparent;
    m_fndLgnCouleur         = sf::Color( 255,255,255, 20 );
    m_fndLgnepaisseur       = 1;


    // Declaration des fonctions de fonctionnement de l'interface interne du gadget.
    fct_cliqueBtnFond = [this](){
        if ( m_horizontal ) {
            if ( getLocalPosSouris().x > m_marge.x + m_slider->getTaille().x/2 + m_slider->getPosition().x ){
                incrementer ( 20 );
                if ( m_slider->getPosition().x + ( m_slider->getTaille().x/2  ) > getLocalPosSouris().x )
                    positionnerCurseurSurSouris ();
            } else {
                decrementer ( 20 );
                if ( m_slider->getPosition().x + ( m_slider->getTaille().x/2  ) < getLocalPosSouris().x )
                    positionnerCurseurSurSouris ();
            }
        } else {
            if ( getLocalPosSouris().y > m_marge.y + m_slider->getTaille().y/2 + m_slider->getPosition().y ){
                incrementer ( 20 );
                if ( m_slider->getPosition().y - ( m_slider->getTaille().y/2 + m_marge.y )  > getLocalPosSouris().y )
                    positionnerCurseurSurSouris ();
            } else {
                decrementer ( 20 );
                if ( m_slider->getPosition().y - ( m_slider->getTaille().y/2 + m_marge.y )  < getLocalPosSouris().y )
                    positionnerCurseurSurSouris ();
            }
        }
    };
    fct_dragStart = [this](){
        m_decalageDragSouris = sf::Vector2i ( getLocalPosSouris().x - m_slider->getPosition().x , getLocalPosSouris().y - m_slider->getPosition().y );
        setDrag( true );
        actualiser ();
    };
    fct_dragStop = [this](){
        setDrag( false );
        actualiser ();
    };
    fct_rouletteH  = [this](){
        if ( m_horizontal )
                incrementer();
        else    decrementer();
        actualiser ();
    };
    fct_rouletteB  = [this](){
        if ( m_horizontal )
                decrementer();
        else    incrementer();
        actualiser ();
    };

    // Actions du bouton
    m_boutonFond->lier ( Evenement::onBtnG_presser          , fct_cliqueBtnFond );
    m_boutonFond->lier ( Evenement::onBtnG_relacher         , fct_dragStop );
    m_boutonFond->lier ( Evenement::onBtnG_relacherDehors   , fct_dragStop );
    m_boutonFond->lier ( Evenement::onBtnM_roulerHaut       , fct_rouletteH );
    m_boutonFond->lier ( Evenement::onBtnM_roulerBas        , fct_rouletteB );


    // Actions du slider
    m_slider->lier ( Evenement::onBtnG_presser          , fct_dragStart );
    m_slider->lier ( Evenement::onBtnG_relacher         , fct_dragStop );
    m_slider->lier ( Evenement::onBtnG_relacherDehors   , fct_dragStop );
    m_slider->lier ( Evenement::onBtnM_roulerHaut       , fct_rouletteH );
    m_slider->lier ( Evenement::onBtnM_roulerBas        , fct_rouletteB );


    // Initialisation du slider
    m_slider->setPosition ( m_marge.x, m_marge.y );
    m_slider->setTaille ( { m_largeur - 2*m_marge.x  , m_largeur - 2*m_marge.y });
//    m_slider->setTexteStyle ( m_skin->getStyle( Styles::slider ) );

    actualiser();

}

/////////////////////////////////////////////////
void DnSlider::incrementer( float inc )
{
    declencher ( Evenement::on_valeurChange );
    if ( m_horizontal )
        m_slider->setPosition ( m_slider->getPosition ( ).x + inc , m_slider->getPosition ( ).y );
    else
        m_slider->setPosition ( m_slider->getPosition ( ).x  , m_slider->getPosition ( ).y + inc);

    corrigerPositionCurseur();

}

/////////////////////////////////////////////////
void DnSlider::decrementer( float inc )
{
    declencher ( Evenement::on_valeurChange );
    if ( m_horizontal )
        m_slider->setPosition ( m_slider->getPosition ( ).x - inc , m_slider->getPosition ( ).y );
    else
        m_slider->setPosition ( m_slider->getPosition ( ).x , m_slider->getPosition ( ).y - inc );

    corrigerPositionCurseur();
}



/////////////////////////////////////////////////
void DnSlider::traiterEvenements (const sf::Event& evenement)
{
    if ( dragEnCours() )
        positionnerCurseurSurSouris ();
}




/////////////////////////////////////////////////
void DnSlider::positionnerCurseurSurSouris ()
{

    declencher ( Evenement::on_valeurChange );

    // Definir la nouvelle position avec les coords souris
    if ( m_horizontal )
        m_slider->setPosition ( getLocalPosSouris().x - m_decalageDragSouris.x - m_marge.x , m_marge.y );
    else
        m_slider->setPosition (  m_marge.x , getLocalPosSouris().y - m_marge.y  - m_decalageDragSouris.y );

    // Corriger la position pour la garder dans ses limites
    corrigerPositionCurseur();

    actualiserGeometrie ();
}



/////////////////////////////////////////////////
void DnSlider::setLongueurCurseur( float pourcentage )
{
    if ( pourcentage > 100 )    pourcentage = 100;
    if ( pourcentage < 0 )      pourcentage = 0;

    if ( m_horizontal ){
        m_slider->setTailleX( m_longueur * pourcentage/100- 2*m_marge.x );
        m_slider->setTailleY( m_largeur - 2*m_marge.y );

    }else{
        m_slider->setTailleX( m_largeur - 2*m_marge.y);
        m_slider->setTailleY( m_longueur * pourcentage/100- 2*m_marge.x);
    }

//    actualiserGeometrie();

}

/////////////////////////////////////////////////
void DnSlider::actualiserGeometrie ()
{
    if ( m_horizontal )
        m_taille = { m_longueur,  m_largeur};
     else
        m_taille = { m_largeur ,  m_longueur};

    m_fond->setTaille ( m_taille );
    m_boutonFond->setTaille ( m_taille );

    actualiserBounds();
    m_boutonFond->actualiserBounds();
    m_slider->actualiserBounds();
}

/////////////////////////////////////////////////
void DnSlider::actualiserStyle ()
{


    m_boutonFond->setFondCouleur (    m_btnCouleurs ) ;
    m_boutonFond->setLigneCouleur (    m_btnLgnCouleurs  ) ;
    m_boutonFond->setLigneEpaisseur ( m_btnLgnepaisseurs  );

    m_slider->setFondCouleur (    m_slideCouleurs ) ;
    m_slider->setLigneCouleur (    m_slideLgnCouleurs  ) ;
    m_slider->setLigneEpaisseur ( m_slideLgnepaisseurs  );

    m_fond->setFondCouleur (    m_fndCouleur ) ;
    m_fond->setLigneCouleur (    m_fndLgnCouleur  ) ;
    m_fond->setLigneEpaisseur ( m_fndLgnepaisseur  );


}


///////////////////////////////////////////////////
//void DnSlider::setSkin( std::shared_ptr<Skin> skin )
//{
//    m_styleFond         = skin->getStyle( Styles::fond ) ;
//    m_styleBtnSlider    = skin->getStyle( Styles::slider ) ;
//    m_styleBtnFond      = skin->getStyle( Styles::bouton ) ;
//}
/*
/////////////////////////////////////////////////
void DnSlider::setTexteStyle( std::shared_ptr<Style> style , Etat etat = Etat::tous )
{
    m_styleFond         = skin->getStyle( Styles::fond ) ;
    m_styleBtnSlider    = skin->getStyle( Styles::slider ) ;
    m_styleBtnFond      = skin->getStyle( Styles::bouton ) ;
}

*/
/*
/////////////////////////////////////////////////
void DnSlider::setTexteStyle ( std::shared_ptr<Style> style , Etat etat ){

    m_styleFond.set( style , etat);
    m_styleBtnSlider    = style->getStyle( Styles::slider ) ;
    m_styleBtnFond      = style->getStyle( Styles::bouton ) ;

    m_styleFond         = style;
    m_styleBtnSlider    = style;
    m_styleBtnFond      = style;
}

*/
/*
/////////////////////////////////////////////////
void DnSlider::actualiser ()
{



}

*/
/////////////////////////////////////////////////
float DnSlider::getValeur(){
    float result, longueurMax,coefPosition, longueurVal;
    if ( m_horizontal ) {
        longueurMax = m_taille.x - 2*m_marge.x - m_slider->getTaille().x;
        coefPosition = ( m_slider->getPosition().x - m_marge.x ) / longueurMax;
        longueurVal = m_valeurMax - m_valeurMin;
        if (longueurMax == 0 )
            result = 0;
        else result =  coefPosition * longueurVal;
    } else {
        longueurMax = m_taille.y - 2*m_marge.y - m_slider->getTaille().y;
        coefPosition = ( m_slider->getPosition().y - m_marge.y ) / longueurMax;
        longueurVal = m_valeurMax - m_valeurMin;
        if (longueurMax == 0 )
            result = 100;
        else result =  m_valeurMax - coefPosition * longueurVal;
    }
//        std::cout << "---> longueurMax : " << longueurMax << "---> coefPosition : " << coefPosition << "\n";
//        std::cout << "---> longueurVal : " << longueurVal << "---> result : " << result  << "\n";
    return result;
};



/*

/////////////////////////////////////////////////
std::shared_ptr<Gadget>  DnSlider::testerSurvol ( sf::Vector2f position )
{
    if ( m_globalBounds.contains( position.x, position.y ) && estActif() )
    {
        auto result = m_slider->testerSurvol ( position );
        if ( result == nullptr )
            result = m_boutonFond->testerSurvol ( position );
        return result;
    } else
        return nullptr;

}
/////////////////////////////////////////////////
void DnSlider::draw (sf::RenderTarget& target, sf::RenderStates states) const
{

    //On applique la transformation
    states.transform *= getTransform();

    // On dessine les éléments
    target.draw(*m_boutonFond, states);
    target.draw(*m_slider, states);

}



*/
/////////////////////////////////////////////////
void DnSlider::corrigerPositionCurseur(){

    if ( m_horizontal ) {
        if ( m_slider->getPosition ( ).x < m_marge.y )
            m_slider->setPosition ( m_marge.y, m_slider->getPosition ( ).y );
        if ( m_slider->getPosition ( ).x > m_taille.x - m_marge.y - m_slider->getTaille().x )
            m_slider->setPosition ( m_taille.x - m_marge.y - m_slider->getTaille().x, m_slider->getPosition ( ).y );
    } else {
        if ( m_slider->getPosition ( ).y < m_marge.y )
            m_slider->setPosition ( m_slider->getPosition ( ).x , m_marge.y  );
        if ( m_slider->getPosition ( ).y > m_taille.y - m_marge.y - m_slider->getTaille().y )
            m_slider->setPosition ( m_slider->getPosition ( ).x,  m_taille.y - m_marge.y - m_slider->getTaille().y );
    }
}




} // fin namespace gui

