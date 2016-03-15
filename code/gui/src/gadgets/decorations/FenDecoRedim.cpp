#include "decorations/FenDecoRedim.h"
#include "Fenetre.h"
#include "BtnRectangle.h"
#include "Interface.h"

namespace gui{

FenDecoRedim::FenDecoRedim( Fenetre* fenetre )
: FenDecoration     ( fenetre )
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
//    std::cout << "Decoration redim : creation\n";
    m_fenetre->setMarge( { 6 , 6 } );

    m_fenetre->ajouterComposant( m_btn_gauche );
    m_fenetre->ajouterComposant( m_btn_droite );
    m_fenetre->ajouterComposant( m_btn_haut );
    m_fenetre->ajouterComposant( m_btn_bas );

    m_fenetre->ajouterComposant( m_btn_hautGauche );
    m_fenetre->ajouterComposant( m_btn_hautDroite );
    m_fenetre->ajouterComposant( m_btn_basGauche );
    m_fenetre->ajouterComposant( m_btn_basDroite );



    m_btn_gauche->setFondCouleur ( sf::Color::Transparent );
    m_btn_droite->setFondCouleur ( sf::Color::Transparent );
    m_btn_haut->setFondCouleur ( sf::Color::Transparent );
    m_btn_bas->setFondCouleur ( sf::Color::Transparent );

    m_btn_hautGauche->setFondCouleur ( sf::Color::Transparent );
    m_btn_hautDroite->setFondCouleur ( sf::Color::Transparent );
    m_btn_basGauche->setFondCouleur ( sf::Color::Transparent );
    m_btn_basDroite->setFondCouleur ( sf::Color::Transparent );

    m_btnDragCouleurs.set       ( sf::Color( 0, 0, 0, 50 )     , Etat::desactive );
    m_btnDragCouleurs.set       ( sf::Color( 255,255,255, 0 )  , Etat::repos );
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






    auto fct_redimStartG = [this](){
            m_fenetre->demander_aEtre_auDessus();
            m_sourisPosOrigin = m_fenetre->getPosSouris();
            m_tailleOrigin = m_fenetre->getTaille();
            m_posOrigin = m_fenetre->getPosition();
            m_redimGauche = true;
        };
    auto fct_redimStartD = [this](){
            m_fenetre->demander_aEtre_auDessus();
            m_sourisPosOrigin = m_fenetre->getPosSouris();
            m_tailleOrigin = m_fenetre->getTaille();
            m_posOrigin = m_fenetre->getPosition();
            m_redimDroite = true;
        };
    auto fct_redimStartH = [this](){
            m_fenetre->demander_aEtre_auDessus();
            m_sourisPosOrigin = m_fenetre->getPosSouris();
            m_tailleOrigin = m_fenetre->getTaille();
            m_posOrigin = m_fenetre->getPosition();
            m_redimHaut = true;
        };
    auto fct_redimStartB = [this](){
            m_fenetre->demander_aEtre_auDessus();
            m_sourisPosOrigin = m_fenetre->getPosSouris();
            m_tailleOrigin = m_fenetre->getTaille();
            m_posOrigin = m_fenetre->getPosition();
            m_redimBas = true;
        };

    auto fct_redimStartHG = [this](){
            m_fenetre->demander_aEtre_auDessus();
            m_sourisPosOrigin = m_fenetre->getPosSouris();
            m_tailleOrigin = m_fenetre->getTaille();
            m_posOrigin = m_fenetre->getPosition();
            m_redimHaut = true;
            m_redimGauche = true;
        };
    auto fct_redimStartHD = [this](){
            m_fenetre->demander_aEtre_auDessus();
            m_sourisPosOrigin = m_fenetre->getPosSouris();
            m_tailleOrigin = m_fenetre->getTaille();
            m_posOrigin = m_fenetre->getPosition();
            m_redimHaut = true;
            m_redimDroite = true;
        };
    auto fct_redimStartBG = [this](){
            m_fenetre->demander_aEtre_auDessus();
            m_sourisPosOrigin = m_fenetre->getPosSouris();
            m_tailleOrigin = m_fenetre->getTaille();
            m_posOrigin = m_fenetre->getPosition();
            m_redimBas = true;
            m_redimGauche = true;
        };
    auto fct_redimStartBD = [this](){
            m_fenetre->demander_aEtre_auDessus();
            m_sourisPosOrigin = m_fenetre->getPosSouris();
            m_tailleOrigin = m_fenetre->getTaille();
            m_posOrigin = m_fenetre->getPosition();
            m_redimBas = true;
            m_redimDroite = true;
        };
    auto fct_redimStop = [this](){
            m_redimHaut = false;
            m_redimGauche = false;
            m_redimBas = false;
            m_redimDroite = false;
            m_fenetre->actualiserBounds();
            Interface::setCurseur ( Curseurs::Defaut );
    };


    m_btn_gauche->lier (Evenement::onBtnG_presser , fct_redimStartG );
    m_btn_gauche->lier (Evenement::onBtnG_relacher, fct_redimStop );
    m_btn_gauche->lier (Evenement::onBtnG_relacherDehors, fct_redimStop );

    m_btn_droite->lier (Evenement::onBtnG_presser , fct_redimStartD );
    m_btn_droite->lier (Evenement::onBtnG_relacher, fct_redimStop);
    m_btn_droite->lier (Evenement::onBtnG_relacherDehors, fct_redimStop);

    m_btn_haut->lier (Evenement::onBtnG_presser , fct_redimStartH );
    m_btn_haut->lier (Evenement::onBtnG_relacher, fct_redimStop );
    m_btn_haut->lier (Evenement::onBtnG_relacherDehors, fct_redimStop );

    m_btn_bas->lier (Evenement::onBtnG_presser , fct_redimStartB );
    m_btn_bas->lier (Evenement::onBtnG_relacher, fct_redimStop );
    m_btn_bas->lier (Evenement::onBtnG_relacherDehors, fct_redimStop );

    m_btn_hautGauche->lier (Evenement::onBtnG_presser       , fct_redimStartHG );
    m_btn_hautGauche->lier (Evenement::onBtnG_relacher      , fct_redimStop );
    m_btn_hautGauche->lier (Evenement::onBtnG_relacherDehors, fct_redimStop );

    m_btn_hautDroite->lier (Evenement::onBtnG_presser , fct_redimStartHD);
    m_btn_droite->lier (Evenement::onBtnG_relacher, fct_redimStop );
    m_btn_droite->lier (Evenement::onBtnG_relacherDehors, fct_redimStop );

    m_btn_basGauche->lier (Evenement::onBtnG_presser , fct_redimStartBG);
    m_btn_basGauche->lier (Evenement::onBtnG_relacher, fct_redimStop );
    m_btn_basGauche->lier (Evenement::onBtnG_relacherDehors, fct_redimStop );

    m_btn_basDroite->lier (Evenement::onBtnG_presser , fct_redimStartBD);
    m_btn_basDroite->lier (Evenement::onBtnG_relacher, fct_redimStop );
    m_btn_basDroite->lier (Evenement::onBtnG_relacherDehors, fct_redimStop );


    // le curseur souris de redimension
    m_btn_gauche->lier( Evenement::on_entrer , [this](){ Interface::setCurseur ( Curseurs::Redim_horizontal); });
    m_btn_gauche->lier( Evenement::on_sortir , [this](){ Interface::setCurseur ( Curseurs::Defaut ); });
    m_btn_droite->lier( Evenement::on_entrer , [this](){ Interface::setCurseur ( Curseurs::Redim_horizontal); });
    m_btn_droite->lier( Evenement::on_sortir , [this](){ Interface::setCurseur ( Curseurs::Defaut ); });
    m_btn_haut->lier( Evenement::on_entrer , [this](){ Interface::setCurseur ( Curseurs::Redim_vertical); });
    m_btn_haut->lier( Evenement::on_sortir , [this](){ Interface::setCurseur ( Curseurs::Defaut ); });
    m_btn_bas->lier( Evenement::on_entrer , [this](){ Interface::setCurseur ( Curseurs::Redim_vertical); });
    m_btn_bas->lier( Evenement::on_sortir , [this](){ Interface::setCurseur ( Curseurs::Defaut ); });

    m_btn_hautGauche->lier( Evenement::on_entrer , [this](){ Interface::setCurseur ( Curseurs::Redim_diag1); });
    m_btn_hautGauche->lier( Evenement::on_sortir , [this](){ Interface::setCurseur ( Curseurs::Defaut ); });
    m_btn_hautDroite->lier( Evenement::on_entrer , [this](){ Interface::setCurseur ( Curseurs::Redim_diag2); });
    m_btn_hautDroite->lier( Evenement::on_sortir , [this](){ Interface::setCurseur ( Curseurs::Defaut ); });
    m_btn_basGauche->lier( Evenement::on_entrer , [this](){ Interface::setCurseur ( Curseurs::Redim_diag2); });
    m_btn_basGauche->lier( Evenement::on_sortir , [this](){ Interface::setCurseur ( Curseurs::Defaut ); });
    m_btn_basDroite->lier( Evenement::on_entrer , [this](){ Interface::setCurseur ( Curseurs::Redim_diag1); });
    m_btn_basDroite->lier( Evenement::on_sortir , [this](){ Interface::setCurseur ( Curseurs::Defaut ); });

    m_fenetre->actualiser();

}


/////////////////////////////////////////////////
FenDecoRedim::~FenDecoRedim()
{


    m_fenetre->retirerComposant( m_btn_gauche );
    m_fenetre->retirerComposant( m_btn_droite );
    m_fenetre->retirerComposant( m_btn_haut );
    m_fenetre->retirerComposant( m_btn_bas );

    m_fenetre->retirerComposant( m_btn_hautGauche );
    m_fenetre->retirerComposant( m_btn_hautDroite );
    m_fenetre->retirerComposant( m_btn_basGauche );
    m_fenetre->retirerComposant( m_btn_basDroite );

//    std::cout << " nombre de composants restant : " << m_fenetre->getComposants().size()  << "\n";
}




/*
/////////////////////////////////////////////////
void FenRedim::draw (sf::RenderTarget& target, sf::RenderStates states) const
{

}*/

///////////////////////////////////////////////////
//void FenDecoRedim::sortDuPanneau ()
//{
////    if ( m_redimensionnable )
//
//}
//
//
//
///////////////////////////////////////////////////
//void FenDecoRedim::entreDansPanneau ()
//{
//
//}



/////////////////////////////////////////////////
void FenDecoRedim::actualiserGeometrie ()
{
    //FenSimple::actualiserGeometrie ();

    auto marge = m_fenetre->getMarge();
    auto taille = m_fenetre->getTaille();

    m_btn_gauche->setTaille ( {marge.x , taille.y - 2*marge.y} );
    m_btn_droite->setTaille ( {marge.x , taille.y - 2*marge.y} );
    m_btn_haut->setTaille   ( {taille.x - 2*marge.x , marge.y} );
    m_btn_bas->setTaille    ( {taille.x - 2*marge.x , marge.y} );

    m_btn_hautGauche->setTaille ( {marge.x , marge.y} );
    m_btn_hautDroite->setTaille ( {marge.x , marge.y} );
    m_btn_basGauche->setTaille  ( {marge.x , marge.y} );
    m_btn_basDroite->setTaille  ( {marge.x , marge.y} );


    m_btn_gauche->setPosition ( 0 , marge.y );
    m_btn_droite->setPosition ( taille.x - marge.x , marge.y );
    m_btn_haut->setPosition   ( marge.x , 0  );
    m_btn_bas->setPosition    ( marge.x  , taille.y - marge.y );

    m_btn_hautGauche->setPosition ( 0 , 0 );
    m_btn_hautDroite->setPosition ( taille.x - marge.x , 0 );
    m_btn_basGauche->setPosition  ( 0 , taille.y - marge.y );
    m_btn_basDroite->setPosition  ( taille.x - marge.x , taille.y - marge.y );


}

/////////////////////////////////////////////////
void FenDecoRedim::actualiserStyle ()
{

}

/*
/////////////////////////////////////////////////
void FenRedim::actualiser ()
{

}
*/


/////////////////////////////////////////////////
void FenDecoRedim::corrigerTailleMinimum ()
{
//    std::cout << "MARGE : " << m_fenetre->getMarge().x << ", " << m_fenetre->getMarge().y << "\n";
    if ( m_tailleFenetre.y < m_fenetre->getTailleBouton().y + m_fenetre->getMarge().y*2 )
        m_tailleFenetre.y =  m_fenetre->getTailleBouton().y + m_fenetre->getMarge().y*2 ;

    if ( m_tailleFenetre.x < 150 + m_fenetre->getMarge().x*2 )
        m_tailleFenetre.x =  150 + m_fenetre->getMarge().x*2;
}



/////////////////////////////////////////////////
void FenDecoRedim::redimmensionner_haut ()
{
    auto posSouris = m_fenetre->getPosSouris();
    //m_fenetre->setTailleY( m_tailleOrigin.y - ( posSouris.y - m_sourisPosOrigin.y  ) );
    m_tailleFenetre = { m_fenetre->getTaille().x , m_tailleOrigin.y - ( posSouris.y - m_sourisPosOrigin.y  ) };
    corrigerTailleMinimum ();

    m_fenetre->setTailleY( m_tailleFenetre.y  );
    m_fenetre->setPosition ( m_fenetre->getPosition().x , m_posOrigin.y + ( posSouris.y - m_sourisPosOrigin.y  ));

//    m_fenetre->actualiserGeometrie();
//    m_fenetre->actualiserBounds();
}


/////////////////////////////////////////////////
void FenDecoRedim::redimmensionner_bas ()
{
    auto posSouris = m_fenetre->getPosSouris();

    m_tailleFenetre = { m_fenetre->getTaille().x , m_tailleOrigin.y + ( posSouris.y - m_sourisPosOrigin.y  ) };
    corrigerTailleMinimum ();
    m_fenetre->setTailleY( m_tailleFenetre.y  );
//
//    Interface::setCurseur ( Curseurs::Redim_vertical);
//    m_fenetre->actualiserGeometrie();
//    m_fenetre->actualiserBounds();
}


/////////////////////////////////////////////////
void FenDecoRedim::redimmensionner_gauche ()
{
    auto posSouris = m_fenetre->getPosSouris();

    m_tailleFenetre = { m_tailleOrigin.x - ( posSouris.x - m_sourisPosOrigin.x ), m_fenetre->getTaille().y   };
    corrigerTailleMinimum ();
    m_fenetre->setTailleX( m_tailleFenetre.x  );

    corrigerTailleMinimum ();

    m_fenetre->setPosition ( m_posOrigin.x + ( posSouris.x - m_sourisPosOrigin.x  ),  m_fenetre->getPosition().y );

}

/////////////////////////////////////////////////
void FenDecoRedim::redimmensionner_droite ()
{
    auto posSouris = m_fenetre->getPosSouris();
//    m_fenetre->setTailleX( m_tailleOrigin.x + ( posSouris.x - m_sourisPosOrigin.x  ) );
    m_tailleFenetre = { m_tailleOrigin.x + ( posSouris.x - m_sourisPosOrigin.x  ) , m_fenetre->getTaille().y   };
    corrigerTailleMinimum ();
    m_fenetre->setTailleX( m_tailleFenetre.x  );
//    demander_aEtre_auDessus();
//    m_fenetre->actualiserGeometrie();
//    m_fenetre->actualiserBounds();
}



/*
/////////////////////////////////////////////////
void FenDecoRedim::actualiser ( sf::Time delta )
{
//    if ( m_redimGauche ){ redimmensionner_gauche (); }
//    if ( m_redimDroite ){ redimmensionner_droite (); }
//    if ( m_redimHaut )  { redimmensionner_haut (); }
//    if ( m_redimBas )   { redimmensionner_bas (); }
}*/


/////////////////////////////////////////////////
void FenDecoRedim::traiterEvenements (const sf::Event& evenement)
{
    if ( m_redimGauche ){ redimmensionner_gauche (); }
    if ( m_redimDroite ){ redimmensionner_droite (); }
    if ( m_redimHaut )  { redimmensionner_haut (); }
    if ( m_redimBas )   { redimmensionner_bas (); }

    if ( redimEnCours () )
        m_fenetre->actualiserGeometrie();

//    FenSimple::traiterEvenements (evenement);

//     if ( redimEnCours () )
//        positionnerFenetre ();

}

}; // fin namesapce gui
