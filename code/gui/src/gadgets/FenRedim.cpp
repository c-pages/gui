/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <FenRedim.h>

#include <FenSimple.h>


namespace gui {

/////////////////////////////////////////////////
FenRedim::FenRedim ()
: FenSimple ()
, m_btn_gauche      ( std::make_shared<BtnRectangle>() )
, m_btn_droite      ( std::make_shared<BtnRectangle>() )
, m_btn_haut        ( std::make_shared<BtnRectangle>() )
, m_btn_bas         ( std::make_shared<BtnRectangle>() )

, m_btn_hautGauche  ( std::make_shared<BtnRectangle>() )
, m_btn_hautDroite  ( std::make_shared<BtnRectangle>() )
, m_btn_basGauche   ( std::make_shared<BtnRectangle>() )
, m_btn_basDroite   ( std::make_shared<BtnRectangle>() )

//, m_fenetre         ( std::make_shared<FenSimple>() )
{
    m_marge = { 6 , 6 };

    ajouterComposant( m_btn_gauche );
    ajouterComposant( m_btn_droite );
    ajouterComposant( m_btn_haut );
    ajouterComposant( m_btn_bas );

    ajouterComposant( m_btn_hautGauche );
    ajouterComposant( m_btn_hautDroite );
    ajouterComposant( m_btn_basGauche );
    ajouterComposant( m_btn_basDroite );




    m_btnDragCouleurs.set       ( sf::Color( 0, 0, 0, 50 )     , Etat::desactive );
    m_btnDragCouleurs.set       ( sf::Color( 0, 0, 0, 50 )     , Etat::desactive );
    m_btnDragCouleurs.set       ( sf::Color( 255,255,255, 0 ) , Etat::repos );
    m_btnDragCouleurs.set       ( sf::Color( 255,255,255, 20 ) , Etat::survol );
    m_btnDragCouleurs.set       ( sf::Color( 255,255,255, 25 ) , Etat::press );
    m_btnDragLgnCouleurs.set    ( sf::Color( 255,255,255, 20 ) );
    m_btnDragLgnepaisseurs.set  ( 0 );

    m_btnDragSlideCouleurs.set       ( sf::Color( 0, 0, 0, 50 )     , Etat::desactive );
    m_btnDragSlideCouleurs.set       ( sf::Color( 255,255,255, 40 ) , Etat::repos );
    m_btnDragSlideCouleurs.set       ( sf::Color( 255,255,255, 60 ) , Etat::survol );
    m_btnDragSlideCouleurs.set       ( sf::Color( 255,255,255, 80 ) , Etat::press );
    m_btnDragSlideLgnCouleurs.set    ( sf::Color( 255,255,255, 20 ) );
    m_btnDragSlideLgnepaisseurs.set  ( 0 );

    m_btnDragFndCouleur            = sf::Color::Transparent;
    m_btnDragFndLgnCouleur         = sf::Color( 255,255,255, 20 );
    m_btnDragFndLgnepaisseur       = 1;






    fct_redimStartG = [this](){
    demander_aEtre_auDessus();
            m_sourisPosOrigin = getPosSouris();
            m_tailleOrigin = m_taille;
            m_posOrigin = getPosition();
            m_redimGauche = true;
        };
    fct_redimStopG = [this](){ m_redimGauche = false; actualiserBounds(); };
    fct_redimStartD = [this](){
    demander_aEtre_auDessus();
            m_sourisPosOrigin = getPosSouris();
            m_tailleOrigin = m_taille;
            m_posOrigin = getPosition();
            m_redimDroite = true;
        };
    fct_redimStopD = [this](){ m_redimDroite = false; actualiserBounds(); };
    fct_redimStartH = [this](){
    demander_aEtre_auDessus();
            m_sourisPosOrigin = getPosSouris();
            m_tailleOrigin = m_taille;
            m_posOrigin = getPosition();
            m_redimHaut = true;
        };
    fct_redimStopH = [this](){ m_redimHaut = false; actualiserBounds(); };
    fct_redimStartB = [this](){
    demander_aEtre_auDessus();
            m_sourisPosOrigin = getPosSouris();
            m_tailleOrigin = m_taille;
            m_posOrigin = getPosition();
            m_redimBas = true;
        };
    fct_redimStopB = [this](){ m_redimBas = false; actualiserBounds(); };



    m_btn_gauche->lier (Evenement::onBtnG_presser , fct_redimStartG );
    m_btn_gauche->lier (Evenement::onBtnG_relacher, fct_redimStopG );
    m_btn_gauche->lier (Evenement::onBtnG_relacherDehors, fct_redimStopG );

    m_btn_droite->lier (Evenement::onBtnG_presser , fct_redimStartD );
    m_btn_droite->lier (Evenement::onBtnG_relacher, fct_redimStopD);
    m_btn_droite->lier (Evenement::onBtnG_relacherDehors, fct_redimStopD);

    m_btn_haut->lier (Evenement::onBtnG_presser , fct_redimStartH );
    m_btn_haut->lier (Evenement::onBtnG_relacher, fct_redimStopH );
    m_btn_haut->lier (Evenement::onBtnG_relacherDehors, fct_redimStopH );

    m_btn_bas->lier (Evenement::onBtnG_presser , fct_redimStartB );
    m_btn_bas->lier (Evenement::onBtnG_relacher, fct_redimStopB );
    m_btn_bas->lier (Evenement::onBtnG_relacherDehors, fct_redimStopB );





    m_btn_hautGauche->lier (Evenement::onBtnG_presser , [this](){
    demander_aEtre_auDessus();
            m_sourisPosOrigin = getPosSouris();
            m_tailleOrigin = m_taille;
            m_posOrigin = getPosition();
            m_redimHaut = true;
            m_redimGauche = true;
        });
    m_btn_hautGauche->lier (Evenement::onBtnG_relacher, [this](){ m_redimGauche = false;  m_redimHaut = false; });
    m_btn_hautGauche->lier (Evenement::onBtnG_relacherDehors, [this](){ m_redimGauche = false;   m_redimHaut = false; });

    m_btn_hautDroite->lier (Evenement::onBtnG_presser , [this](){
    demander_aEtre_auDessus();
            m_sourisPosOrigin = getPosSouris();
            m_tailleOrigin = m_taille;
            m_posOrigin = getPosition();
            m_redimHaut = true;
            m_redimDroite = true;
        });
    m_btn_droite->lier (Evenement::onBtnG_relacher, [this](){ m_redimDroite = false;   m_redimHaut = false; });
    m_btn_droite->lier (Evenement::onBtnG_relacherDehors, [this](){ m_redimDroite = false;   m_redimHaut = false; });

    m_btn_basGauche->lier (Evenement::onBtnG_presser , [this](){
    demander_aEtre_auDessus();
            m_sourisPosOrigin = getPosSouris();
            m_tailleOrigin = m_taille;
            m_posOrigin = getPosition();
            m_redimBas = true;
            m_redimGauche = true;
        });
    m_btn_basGauche->lier (Evenement::onBtnG_relacher, [this](){ m_redimBas = false; m_redimGauche = false; });
    m_btn_basGauche->lier (Evenement::onBtnG_relacherDehors, [this](){ m_redimBas = false; m_redimGauche = false; });

    m_btn_basDroite->lier (Evenement::onBtnG_presser , [this](){
    demander_aEtre_auDessus();
            m_sourisPosOrigin = getPosSouris();
            m_tailleOrigin = m_taille;
            m_posOrigin = getPosition();
            m_redimBas = true;
            m_redimDroite = true;
        });
    m_btn_basDroite->lier (Evenement::onBtnG_relacher, [this](){ m_redimBas = false; m_redimDroite = false; });
    m_btn_basDroite->lier (Evenement::onBtnG_relacherDehors, [this](){ m_redimBas = false; m_redimDroite = false; });






}

/*
/////////////////////////////////////////////////
void FenRedim::draw (sf::RenderTarget& target, sf::RenderStates states) const
{

}*/

/////////////////////////////////////////////////
void FenRedim::actualiserGeometrie ()
{
    FenSimple::actualiserGeometrie ();


    m_btn_gauche->setTaille ( {m_marge.x , m_taille.y - 2*m_marge.y} );
    m_btn_droite->setTaille ( {m_marge.x , m_taille.y - 2*m_marge.y} );
    m_btn_haut->setTaille   ( {m_taille.x - 2*m_marge.x , m_marge.y} );
    m_btn_bas->setTaille    ( {m_taille.x - 2*m_marge.x , m_marge.y} );

    m_btn_hautGauche->setTaille ( {m_marge.x , m_marge.y} );
    m_btn_hautDroite->setTaille ( {m_marge.x , m_marge.y} );
    m_btn_basGauche->setTaille  ( {m_marge.x , m_marge.y} );
    m_btn_basDroite->setTaille  ( {m_marge.x , m_marge.y} );


    m_btn_gauche->setPosition ( 0 , m_marge.y );
    m_btn_droite->setPosition ( m_taille.x - m_marge.x , m_marge.y );
    m_btn_haut->setPosition   ( m_marge.x , 0  );
    m_btn_bas->setPosition    ( m_marge.x  , m_taille.y - m_marge.y );

    m_btn_hautGauche->setPosition ( 0 , 0 );
    m_btn_hautDroite->setPosition ( m_taille.x - m_marge.x , 0 );
    m_btn_basGauche->setPosition  ( 0 , m_taille.y - m_marge.y );
    m_btn_basDroite->setPosition  ( m_taille.x - m_marge.x , m_taille.y - m_marge.y );


}

/////////////////////////////////////////////////
void FenRedim::actualiserStyle ()
{

}

/*
/////////////////////////////////////////////////
void FenRedim::actualiser ()
{

}
*/


/////////////////////////////////////////////////
void FenRedim::corrigerTailleMinimum ()
{
    if ( m_taille.y < m_titre->getTaille().y + m_marge.y*2 )
        m_taille.y = m_titre->getTaille().y + m_marge.y*2;

    if ( m_taille.x < 150 +  m_marge.x*2 )
        m_taille.x = 150 + m_marge.x*2;
}

/////////////////////////////////////////////////
void FenRedim::redimmensionner_haut ()
{
    auto posSouris = getPosSouris();
    m_taille = { m_taille.x , m_tailleOrigin.y - ( posSouris.y - m_sourisPosOrigin.y  ) };
//    demander_aEtre_auDessus();
    corrigerTailleMinimum ();

    setPosition ( getPosition().x , m_posOrigin.y + ( posSouris.y - m_sourisPosOrigin.y  ));
//    move( 0, 0 ( posSouris.y - m_sourisPosOrigin.y  ));
    actualiserGeometrie();
}


/////////////////////////////////////////////////
void FenRedim::redimmensionner_bas ()
{
    auto posSouris = getPosSouris();
    m_taille = { m_taille.x , m_tailleOrigin.y + ( posSouris.y - m_sourisPosOrigin.y  ) };

//    demander_aEtre_auDessus();
    corrigerTailleMinimum ();

    actualiserGeometrie();
}


/////////////////////////////////////////////////
void FenRedim::redimmensionner_gauche ()
{
    auto posSouris = getPosSouris();
    m_taille = { m_tailleOrigin.x - ( posSouris.x - m_sourisPosOrigin.x  ) , m_taille.y };

//    demander_aEtre_auDessus();
    corrigerTailleMinimum ();

    setPosition ( m_posOrigin.x + ( posSouris.x - m_sourisPosOrigin.x  ),  getPosition().y );
    actualiserGeometrie();
}

/////////////////////////////////////////////////
void FenRedim::redimmensionner_droite ()
{
    auto posSouris = getPosSouris();
    m_taille = { m_tailleOrigin.x + ( posSouris.x - m_sourisPosOrigin.x  ) , m_taille.y };
    corrigerTailleMinimum ();
//    demander_aEtre_auDessus();
    actualiserGeometrie();
}




/////////////////////////////////////////////////
void FenRedim::actualiser ( sf::Time delta )
{
//    if ( m_redimGauche ){ redimmensionner_gauche (); }
//    if ( m_redimDroite ){ redimmensionner_droite (); }
//    if ( m_redimHaut )  { redimmensionner_haut (); }
//    if ( m_redimBas )   { redimmensionner_bas (); }
}


/////////////////////////////////////////////////
void FenRedim::traiterEvenements (const sf::Event& evenement)
{


    if ( m_redimGauche ){ redimmensionner_gauche (); }
    if ( m_redimDroite ){ redimmensionner_droite (); }
    if ( m_redimHaut )  { redimmensionner_haut (); }
    if ( m_redimBas )   { redimmensionner_bas (); }

    FenSimple::traiterEvenements (evenement);

//     if ( redimEnCours () )
//        positionnerFenetre ();

}


} // fin namespace gui





















