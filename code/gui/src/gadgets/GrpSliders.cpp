/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <GrpSliders.h>
#include <Enums.h>



namespace gui {

/////////////////////////////////////////////////
GrpSliders::GrpSliders ()
: Groupe ()
, m_slider_V ( std::make_shared<DnSlider>() )
, m_slider_H ( std::make_shared<DnSlider>() )
{

    ajouterComposant( m_slider_V );
    ajouterComposant( m_slider_H );

    // valeurs par defaut
    m_taille = { 400 , 200 };
    m_largeurSliders = 7;
    m_renderTexture.create( 1200, 900 );

    m_btnBtnCouleurs.set       ( sf::Color( 0, 0, 0, 50 )     , Etat::desactive );
    m_btnBtnCouleurs.set       ( sf::Color( 255,255,255, 0 )  , Etat::repos );
    m_btnBtnCouleurs.set       ( sf::Color( 255,255,255, 20 ) , Etat::survol );
    m_btnBtnCouleurs.set       ( sf::Color( 255,255,255, 25 ) , Etat::press );
    m_btnBtnLgnCouleurs.set    ( sf::Color( 255,255,255, 20 ) );
    m_btnBtnLgnepaisseurs.set  ( 0 );

    m_btnSlideCouleurs.set       ( sf::Color( 0, 0, 0, 50 )     , Etat::desactive );
    m_btnSlideCouleurs.set       ( sf::Color( 255,255,255, 40 ) , Etat::repos );
    m_btnSlideCouleurs.set       ( sf::Color( 255,255,255, 60 ) , Etat::survol );
    m_btnSlideCouleurs.set       ( sf::Color( 255,255,255, 80 ) , Etat::press );
    m_btnSlideLgnCouleurs.set    ( sf::Color( 255,255,255, 20 ) );
    m_btnSlideLgnepaisseurs.set  ( 0 );

    m_btnFndCouleur            = sf::Color::Transparent;
    m_btnFndLgnCouleur         = sf::Color( 255,255,255, 20 );
    m_btnFndLgnepaisseur       = 0;

    m_slider_V->setVertical();
    m_slider_V->setLargeur ( m_largeurSliders );
    m_slider_H->setLargeur ( m_largeurSliders );
    m_slider_V->setMarge({ 0 , 0});
    m_slider_H->setMarge({ 0 , 0});
    m_slider_V->lier ( Evenement::on_valeurChange , [this](){ actualiser (); });
    m_slider_H->lier ( Evenement::on_valeurChange , [this](){ actualiser (); });

    actualiser ();
}


/////////////////////////////////////////////////
void GrpSliders::actualiserGeometrie (){

    m_fond->setTaille(m_taille);

    sf::Vector2f longueurs = deplMaxContenu();

    m_slider_H->setVisible ( longueurs.x > 0 );
    m_slider_V->setVisible ( longueurs.y > 0 );

    m_contenant->setSize({ m_taille.x -  m_slider_V->getTaille().x , m_taille.y -  m_slider_H->getTaille().y});
//    m_contenant->setSize({ m_taille.x , m_taille.y });

    // si le contenu est plus grand que le contenant
    if ( m_slider_H->estVisible() ) {
        m_slider_H->setLongueur( m_taille.x -  m_slider_V->getTaille().x );
        m_slider_H->setPosition( 0 , m_taille.y - m_slider_H->getTaille().y);
        float longueurCursH = m_taille.x/ float( boundgingB_enfants().width )* 100 ;
        m_slider_H->setLongueurCurseur(longueurCursH);
        float coef                  = (  m_slider_H->getValeur() ) / 100;
        m_posX_texture              = coef * longueurs.x;
    // si le contenu est plus petit, on cache le slider
    } else {
        m_posX_texture      = 0;
    }

    // si contenu plus grand, on a le slider vert
    if (  m_slider_V->estVisible() ) {  // si contenu plus grand, on a le slider
        m_slider_V->setLongueur ( m_taille.y - m_slider_H->getTaille().y );
        m_slider_V->setPosition ( m_taille.x - m_slider_V->getTaille().x , 0 );
        float longueurCursV = m_taille.y /float( boundgingB_enfants().height )* 100 ;
        m_slider_V->setLongueurCurseur( longueurCursV );
        float coef                  = ( 100 - m_slider_V->getValeur()  ) / 100;
        m_posY_texture              = coef * longueurs.y;
//        std::cout << "coef : " << coef << "     longueurs.y : " << longueurs.y << "\n";
    // si le contenu est plus petit, on cache le slider
    } else {
        m_posY_texture      = 0;
    }
    actualiserContenu();
    actualiserBounds ();
    if ( m_parent != nullptr ) m_parent->actualiserContenu();

}

/////////////////////////////////////////////////
void GrpSliders::actualiserStyle (){


    m_slider_V->setSliderFillColor          ( m_btnSlideCouleurs  );
    m_slider_V->setSliderOutlineColor       ( m_btnSlideLgnCouleurs   );
    m_slider_V->setSliderOutlineThickness   ( m_btnSlideLgnepaisseurs );
    m_slider_V->setBoutonFillColor          ( m_btnBtnCouleurs  );
    m_slider_V->setBoutonOutlineColor       ( m_btnBtnLgnCouleurs );
    m_slider_V->setBoutonOutlineThickness   ( m_btnBtnLgnepaisseurs );
    m_slider_V->setFillColor                ( m_btnFndCouleur  );
    m_slider_V->setOutlineColor             ( m_btnFndLgnCouleur  );
    m_slider_V->setOutlineThickness         ( m_btnFndLgnepaisseur );

    m_slider_H->setSliderFillColor          ( m_btnSlideCouleurs  );
    m_slider_H->setSliderOutlineColor       ( m_btnSlideLgnCouleurs   );
    m_slider_H->setSliderOutlineThickness   ( m_btnSlideLgnepaisseurs );
    m_slider_H->setBoutonFillColor          ( m_btnBtnCouleurs  );
    m_slider_H->setBoutonOutlineColor       ( m_btnBtnLgnCouleurs );
    m_slider_H->setBoutonOutlineThickness   ( m_btnBtnLgnepaisseurs );
    m_slider_H->setFillColor                ( m_btnFndCouleur  );
    m_slider_H->setOutlineColor             ( m_btnFndLgnCouleur  );
    m_slider_H->setOutlineThickness         ( m_btnFndLgnepaisseur );

    m_fond->setFillColor                    ( m_fndCouleur ) ;
    m_fond->setOutlineColor                 ( m_fndLgnCouleur  ) ;
    m_fond->setOutlineThickness             ( m_fndLgnepaisseur  );

    actualiserContenu();
    actualiserBounds ();

    if ( m_parent != nullptr ) m_parent->actualiserContenu();
}



/*
/////////////////////////////////////////////////
void GrpSliders::actualiser ()
{

    m_fond->setTaille(m_taille);

    sf::Vector2f longueurs = deplMaxContenu();

    m_slider_H->setVisible ( longueurs.x > 0 );
    m_slider_V->setVisible ( longueurs.y > 0 );

    m_contenant->setSize({ m_taille.x -  m_slider_V->getTaille().x , m_taille.y -  m_slider_H->getTaille().y});

    // si le contenu est plus grand que le contenant
    if ( m_slider_H->estVisible() ) {
        float coef                  = (  m_slider_H->getValeur() ) / 100;

        m_posX_texture              = coef * longueurs.x;

        float longueurCursH = m_taille.x/ float( boundgingB_enfants().width )* 100 ;
        m_slider_H->setLongueurCurseur(longueurCursH);
        m_slider_H->setLongueur( m_taille.x -  m_slider_V->getTaille().x );
        m_slider_H->setPosition( 0 , m_taille.y - m_slider_H->getTaille().y);
//        m_slider_H->setStyle       ( m_skin->getStyle (  gui::Styles::bouton ) );

    // si le contenu est plus petit, on cache le slider
    } else {
        m_posX_texture      = 0;
    }

    // si contenu plus grand, on a le slider vert
    if (  m_slider_V->estVisible() ) {  // si contenu plus grand, on a le slider
        float coef                  = ( 100 - m_slider_V->getValeur() ) / 100;
        m_posY_texture              = coef * longueurs.y;


        float longueurCursV = m_taille.y /float( boundgingB_enfants().height )* 100 ;
        m_slider_V->setLongueurCurseur( longueurCursV );
        m_slider_V->setLongueur ( m_taille.y - m_slider_H->getTaille().y );
        m_slider_V->setPosition ( m_taille.x - m_slider_V->getTaille().x , 0 );
//        m_slider_V->setStyle    ( m_skin->getStyle (  gui::Styles::bouton ) );

    // si le contenu est plus petit, on cache le slider
    } else {
        m_posY_texture      = 0;
    }


//    m_fond->setStyle ( m_skin->getStyle ( Styles::fond ) );

    actualiserContenu();

    if ( m_parent != nullptr ) m_parent->actualiserContenu();

    actualiserBounds ();

}
*/



/////////////////////////////////////////////////
void GrpSliders::draw (sf::RenderTarget& target, sf::RenderStates states) const
{

    if ( estVisible() ) {

        //On applique la transformation
        states.transform *= getTransform();

        target.draw( *m_fond , states );
        target.draw( *m_slider_V , states );
        target.draw( *m_slider_H , states );
        target.draw( *m_contenant , states );

    }

}


} // fin namespace gui

