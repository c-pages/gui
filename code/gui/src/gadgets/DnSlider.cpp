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
    creerNomUnique( "Slider" );

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

        logEvt ( "CliqueFond" );

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
        logEvt ( "Debut du drag" );
        m_decalageDragSouris = sf::Vector2i ( getLocalPosSouris().x - m_slider->getPosition().x , getLocalPosSouris().y - m_slider->getPosition().y );
        setDrag( true );
//        actualiser ();
    };
    fct_dragStop = [this](){
        logEvt ( "fin du drag" );
        setDrag( false );
//        m_slider->demanderActuaBounds();
//        actualiser ();
    };
    fct_rouletteH  = [this](){
        if ( m_horizontal )
                incrementer();
        else    decrementer();
//        actualiser ();
    };
    fct_rouletteB  = [this](){
        if ( m_horizontal )
                decrementer();
        else    incrementer();
//        actualiser ();
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

}

/////////////////////////////////////////////////
void DnSlider::actualiserGeometrie (){

    log ("actualiserGeometrie");

    if ( m_horizontal )
        m_taille = { m_longueur,  m_largeur};
     else
        m_taille = { m_largeur ,  m_longueur};

    m_fond->setTaille ( m_taille );
    m_boutonFond->setTaille ( m_taille );

    demanderActuaBounds();

}

/////////////////////////////////////////////////
void DnSlider::actualiserStyle ()
{
    log ("actualiserStyle");

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


/////////////////////////////////////////////////
void DnSlider::traiterEvenements (const sf::Event& evenement)
{
    if ( dragEnCours() )
        positionnerCurseurSurSouris ();
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
void DnSlider::positionnerCurseurSurSouris (){

    declencher ( Evenement::on_valeurChange );

    // Definir la nouvelle position avec les coords souris
    if ( m_horizontal )
        m_slider->setPosition ( getLocalPosSouris().x - m_decalageDragSouris.x - m_marge.x , m_marge.y );
    else
        m_slider->setPosition (  m_marge.x , getLocalPosSouris().y - m_marge.y  - m_decalageDragSouris.y );

    // Corriger la position pour la garder dans ses limites
    corrigerPositionCurseur();
    m_slider->demanderActuaBounds();
}

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





/////////////////////////////////////////////////
void DnSlider::setLongueurCurseur( float pourcentage ){

    if ( pourcentage > 100 )    pourcentage = 100;
    if ( pourcentage < 0 )      pourcentage = 0;

    if ( m_horizontal ){
        m_slider->setTailleX( m_longueur * pourcentage/100- 2*m_marge.x );
        m_slider->setTailleY( m_largeur - 2*m_marge.y );

    }else{
        m_slider->setTailleX( m_largeur - 2*m_marge.y);
        m_slider->setTailleY( m_longueur * pourcentage/100- 2*m_marge.x);
    }
}

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
    return result;
};

/////////////////////////////////////////////////
void DnSlider::setValeurMax( float val ){
    m_valeurMax = val;
};

/////////////////////////////////////////////////
float DnSlider::getValeurMax ( ) const {
    return m_valeurMax;
};

/////////////////////////////////////////////////
void DnSlider::setValeurMin( float val ){
    m_valeurMin = val;
};

/////////////////////////////////////////////////
float DnSlider::getValeurMin ( ) const {
    return m_valeurMin;
};

/////////////////////////////////////////////////
void DnSlider::setLongueur( float longueur ){
    m_longueur = longueur;
};

/////////////////////////////////////////////////
void DnSlider::setLargeur( float largeur ){
    m_largeur = largeur;
};

/////////////////////////////////////////////////
void DnSlider::setHorizontal (  ){
    m_horizontal = true;
    demanderActuaGeom ();
};

/////////////////////////////////////////////////
void DnSlider::setVertical (  ){
    m_horizontal = false;
    demanderActuaGeom ();
}

/////////////////////////////////////////////////
bool DnSlider::dragEnCours( ) {
    return m_drag;
};

/////////////////////////////////////////////////
void DnSlider::setDrag (bool val ){
    m_drag = val;
};







/////////////////////////////////////////////////
void DnSlider::setSliderFillColor ( Valeurs<sf::Color> couleurs  ) {
        m_slideCouleurs = couleurs;
        demanderActuaStyle();
    };

/////////////////////////////////////////////////
void DnSlider::setSliderOutlineColor ( Valeurs<sf::Color> couleurs  ) {
        m_slideLgnCouleurs = couleurs;
        demanderActuaStyle();
    };

/////////////////////////////////////////////////
void DnSlider::setSliderOutlineThickness ( Valeurs<float> epaisseur ) {
        m_slideLgnepaisseurs =  epaisseur;
        demanderActuaStyle();
    };

/////////////////////////////////////////////////
void DnSlider::setBoutonFillColor ( Valeurs<sf::Color> couleurs  ) {
        m_btnCouleurs = couleurs;
        demanderActuaStyle();
    };

/////////////////////////////////////////////////
void DnSlider::setBoutonOutlineColor ( Valeurs<sf::Color> couleurs  ) {
        m_btnLgnCouleurs = couleurs;
        demanderActuaStyle();
    };

/////////////////////////////////////////////////
void DnSlider::setBoutonOutlineThickness ( Valeurs<float> epaisseur ) {
        m_btnLgnepaisseurs =  epaisseur;
        demanderActuaStyle();
    };

/////////////////////////////////////////////////
void DnSlider::setFondCouleur ( sf::Color couleurs  ) {
        m_fndCouleur = couleurs;
        demanderActuaStyle();
    };

/////////////////////////////////////////////////
void DnSlider::setLigneCouleur ( sf::Color couleurs  ) {
        m_fndLgnCouleur = couleurs;
        demanderActuaStyle();
    };

/////////////////////////////////////////////////
void DnSlider::setLigneEpaisseur ( float epaisseur ) {
        m_fndLgnepaisseur =  epaisseur;
        demanderActuaStyle();
    };






} // fin namespace gui

































