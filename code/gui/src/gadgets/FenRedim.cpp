/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <FenRedim.h>

#include <FenSimple.h>


namespace gui {

/////////////////////////////////////////////////
FenRedim::FenRedim ()
: m_btn_gauche      ( std::make_shared<BtnRectangle>() )
, m_btn_droite      ( std::make_shared<BtnRectangle>() )
, m_btn_haut        ( std::make_shared<BtnRectangle>() )
, m_btn_bas         ( std::make_shared<BtnRectangle>() )

, m_btn_hautGauche  ( std::make_shared<BtnRectangle>() )
, m_btn_hautDroite  ( std::make_shared<BtnRectangle>() )
, m_btn_basGauche   ( std::make_shared<BtnRectangle>() )
, m_btn_basDroite   ( std::make_shared<BtnRectangle>() )

//, m_fenetre         ( std::make_shared<FenSimple>() )
{
    m_marge = { 7 , 7 };

    ajouterComposant( m_btn_gauche );
    ajouterComposant( m_btn_droite );
    ajouterComposant( m_btn_haut );
    ajouterComposant( m_btn_bas );

    ajouterComposant( m_btn_hautGauche );
    ajouterComposant( m_btn_hautDroite );
    ajouterComposant( m_btn_basGauche );
    ajouterComposant( m_btn_basDroite );



    m_btn_gauche->lier (Evenement::onBtnG_presser , [this](){
            m_sourisPosOrigin = getPosSouris();
            m_tailleOrigin = m_taille;
            m_posOrigin = getPosition();
            m_redimGauche = true;
        });
    m_btn_gauche->lier (Evenement::onBtnG_relacher, [this](){ m_redimGauche = false; });
    m_btn_gauche->lier (Evenement::onBtnG_relacherDehors, [this](){ m_redimGauche = false; });

    m_btn_droite->lier (Evenement::onBtnG_presser , [this](){
            m_sourisPosOrigin = getPosSouris();
            m_tailleOrigin = m_taille;
            m_posOrigin = getPosition();
            m_redimDroite = true;
        });
    m_btn_droite->lier (Evenement::onBtnG_relacher, [this](){ m_redimDroite = false; });
    m_btn_droite->lier (Evenement::onBtnG_relacherDehors, [this](){ m_redimDroite = false; });

    m_btn_haut->lier (Evenement::onBtnG_presser , [this](){
            m_sourisPosOrigin = getPosSouris();
            m_tailleOrigin = m_taille;
            m_posOrigin = getPosition();
            m_redimHaut = true;
        });
    m_btn_haut->lier (Evenement::onBtnG_relacher, [this](){ m_redimHaut = false; });
    m_btn_haut->lier (Evenement::onBtnG_relacherDehors, [this](){ m_redimHaut = false; });

    m_btn_bas->lier (Evenement::onBtnG_presser , [this](){
            m_sourisPosOrigin = getPosSouris();
            m_tailleOrigin = m_taille;
            m_posOrigin = getPosition();
            m_redimBas = true;
        });
    m_btn_bas->lier (Evenement::onBtnG_relacher, [this](){ m_redimBas = false; });
    m_btn_bas->lier (Evenement::onBtnG_relacherDehors, [this](){ m_redimBas = false; });





    m_btn_hautGauche->lier (Evenement::onBtnG_presser , [this](){
            m_sourisPosOrigin = getPosSouris();
            m_tailleOrigin = m_taille;
            m_posOrigin = getPosition();
            m_redimHaut = true;
            m_redimGauche = true;
        });
    m_btn_hautGauche->lier (Evenement::onBtnG_relacher, [this](){ m_redimGauche = false;  m_redimHaut = false; });
    m_btn_hautGauche->lier (Evenement::onBtnG_relacherDehors, [this](){ m_redimGauche = false;   m_redimHaut = false; });

    m_btn_hautDroite->lier (Evenement::onBtnG_presser , [this](){
            m_sourisPosOrigin = getPosSouris();
            m_tailleOrigin = m_taille;
            m_posOrigin = getPosition();
            m_redimHaut = true;
            m_redimDroite = true;
        });
    m_btn_droite->lier (Evenement::onBtnG_relacher, [this](){ m_redimDroite = false;   m_redimHaut = false; });
    m_btn_droite->lier (Evenement::onBtnG_relacherDehors, [this](){ m_redimDroite = false;   m_redimHaut = false; });

    m_btn_basGauche->lier (Evenement::onBtnG_presser , [this](){
            m_sourisPosOrigin = getPosSouris();
            m_tailleOrigin = m_taille;
            m_posOrigin = getPosition();
            m_redimBas = true;
            m_redimGauche = true;
        });
    m_btn_basGauche->lier (Evenement::onBtnG_relacher, [this](){ m_redimBas = false; m_redimGauche = false; });
    m_btn_basGauche->lier (Evenement::onBtnG_relacherDehors, [this](){ m_redimBas = false; m_redimGauche = false; });

    m_btn_basDroite->lier (Evenement::onBtnG_presser , [this](){
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
void FenRedim::actualiser ()
{
    FenSimple::actualiser ();


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
void FenRedim::redimmensionner_haut ()
{
    auto posSouris = getPosSouris();
    m_taille = { m_taille.x , m_tailleOrigin.y - ( posSouris.y - m_sourisPosOrigin.y  ) };
    setPosition ( getPosition().x , m_posOrigin.y + ( posSouris.y - m_sourisPosOrigin.y  ));
//    move( 0, 0 ( posSouris.y - m_sourisPosOrigin.y  ));
    actualiser();
}


/////////////////////////////////////////////////
void FenRedim::redimmensionner_bas ()
{
//    std::cout << "Redim BAS\n";

    auto posSouris = getPosSouris();
    m_taille = { m_taille.x , m_tailleOrigin.y + ( posSouris.y - m_sourisPosOrigin.y  ) };
    actualiser();

}


/////////////////////////////////////////////////
void FenRedim::redimmensionner_gauche ()
{
    auto posSouris = getPosSouris();
//    m_taille = { m_taille.x , m_tailleOrigin.y - ( posSouris.y - m_sourisPosOrigin.y  ) };
//    setPosition ( m_posOrigin.x , m_posOrigin.y + ( posSouris.y - m_sourisPosOrigin.y  ));

    m_taille = { m_tailleOrigin.x - ( posSouris.x - m_sourisPosOrigin.x  ) , m_taille.y };
    setPosition ( m_posOrigin.x + ( posSouris.x - m_sourisPosOrigin.x  ),  getPosition().y );

    actualiser();

}


/////////////////////////////////////////////////
void FenRedim::redimmensionner_droite ()
{

    auto posSouris = getPosSouris();
    m_taille = { m_tailleOrigin.x + ( posSouris.x - m_sourisPosOrigin.x  ) , m_taille.y };
    actualiser();
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





















