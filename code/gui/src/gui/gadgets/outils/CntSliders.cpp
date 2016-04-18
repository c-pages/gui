/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "gadgets/outils/CntSliders.h"
#include "Enums.h"



namespace gui {

/////////////////////////////////////////////////
CntSliders::CntSliders ()
: Contenant ()
, m_slider_V ( std::make_shared<DnGlissere>() )
, m_slider_H ( std::make_shared<DnGlissere>() )
{

    ajouterComposant( m_slider_V );
    ajouterComposant( m_slider_H );

    // valeurs par defaut
    m_taille = { 400 , 200 };
    m_largeurSliders = 7;


    auto tailleMax = sf::Texture::getMaximumSize();
    if ( tailleMax < 1080 )
        m_renderTexture.create( 300  , tailleMax );
    else
        m_renderTexture.create( 300  , 1080 );

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

    m_slider_V->lier ( Evenement::on_valeurChange , [this](){ actualiserMasque (); });
    m_slider_H->lier ( Evenement::on_valeurChange , [this](){ actualiserMasque (); });

    actualiser ();
}

/////////////////////////////////////////////////
void CntSliders::actualiserGeometrie (){
//    std::cout << "CntSliders::actualiserGeometrie () : " << getNom() << "\n";
//    Contenant::actualiserGeometrie ();


//    m_fond->setTaille(m_taille);
    m_affContenant->setSize( { m_taille.x , m_taille.y } );


//   m_fond->setTaille(m_taille);

    sf::Vector2f deplPossibleMax = deplMaxContenu();

    m_slider_H->setVisible ( deplPossibleMax.x > 1 );
    m_slider_V->setVisible ( deplPossibleMax.y > 1 );


//    m_posContenant = {0,0};
    m_tailleContenant = { m_taille.x -  m_slider_V->getTaille().x , m_taille.y -  m_slider_H->getTaille().y };


    m_affContenant->setSize( { m_tailleContenant.x, m_tailleContenant.y } );
//    m_fond->setTaille(m_taille);


    // si le contenu est plus grand que le contenant
    if ( m_slider_H->estVisible() ) {
        m_slider_H->setLongueur( m_tailleContenant.x );
        m_slider_H->setPosition( 0 , m_tailleContenant.y );
        float longueurCursH = m_taille.x/ float( m_groupe->boundgingB_enfants().width )* 100;
        m_slider_H->setLongueurCurseur(longueurCursH);
//        m_slider_H->actualiserGeometrie();
        float coef                  = (  m_slider_H->getValeur() ) / 100;
        m_posContenant.x              = coef * deplPossibleMax.x;
    // si le contenu est plus petit, on cache le slider
    } else {
        m_posContenant.x      = 0;
    }

    // si contenu plus grand, on a le slider vert
    if (  m_slider_V->estVisible() ) {  // si contenu plus grand, on a le slider
        m_slider_V->setLongueur ( m_tailleContenant.y );
        m_slider_V->setPosition ( m_tailleContenant.x , 0 );
        float longueurCursV = m_taille.y /float( m_groupe->boundgingB_enfants().height )* 100 ;
        m_slider_V->setLongueurCurseur( longueurCursV );
//        m_slider_V->actualiserGeometrie();
        float coef                  = ( 100 - m_slider_V->getValeur()  ) / 100;
        m_posContenant.y              = coef * deplPossibleMax.y;
//        std::cout << "coef : " << coef << "     deplPossibleMax.y : " << deplPossibleMax.y << "\n";
    // si le contenu est plus petit, on cache le slider
    } else {
        m_posContenant.y      = 0;
    }



    m_groupe->setPosition ( -m_posContenant.x , -m_posContenant.y );



//    repartirEnfants ();

//    actualiserContenu();
//    actualiserBounds ();
//    if ( m_parent != nullptr ) m_parent->actualiserContenu();

}

/////////////////////////////////////////////////
void CntSliders::actualiserStyle (){


    m_slider_V->setSliderCouleur          ( m_btnSlideCouleurs  );
    m_slider_V->setSliderLigneCouleur       ( m_btnSlideLgnCouleurs   );
    m_slider_V->setSliderLigneEpaisseur   ( m_btnSlideLgnepaisseurs );
    m_slider_V->setBoutonCouleur          ( m_btnBtnCouleurs  );
    m_slider_V->setBoutonLigneCouleur       ( m_btnBtnLgnCouleurs );
    m_slider_V->setBoutonLigneEpaisseur   ( m_btnBtnLgnepaisseurs );
    m_slider_V->setFondCouleur                ( m_btnFndCouleur  );
    m_slider_V->setFondLigneCouleur             ( m_btnFndLgnCouleur  );
    m_slider_V->setFondLigneEpaisseur         ( m_btnFndLgnepaisseur );

    m_slider_H->setSliderCouleur          ( m_btnSlideCouleurs  );
    m_slider_H->setSliderLigneCouleur       ( m_btnSlideLgnCouleurs   );
    m_slider_H->setSliderLigneEpaisseur   ( m_btnSlideLgnepaisseurs );
    m_slider_H->setBoutonCouleur          ( m_btnBtnCouleurs  );
    m_slider_H->setBoutonLigneCouleur       ( m_btnBtnLgnCouleurs );
    m_slider_H->setBoutonLigneEpaisseur   ( m_btnBtnLgnepaisseurs );
    m_slider_H->setFondCouleur                ( m_btnFndCouleur  );
    m_slider_H->setFondLigneCouleur             ( m_btnFndLgnCouleur  );
    m_slider_H->setFondLigneEpaisseur         ( m_btnFndLgnepaisseur );

//    m_fond->setFondCouleur                    ( m_fndCouleur ) ;
//    m_fond->setFondLigneCouleur                 ( m_fndLgnCouleur  ) ;
//    m_fond->setFondLigneEpaisseur             ( m_fndLgnepaisseur  );

//    actualiserContenu();
//    actualiserBounds ();

//    if ( m_parent != nullptr ) m_parent->actualiserContenu();
}



/*
/////////////////////////////////////////////////
void CntSliders::actualiser ()
{

    m_fond->setTaille(m_taille);

    sf::Vector2f deplPossibleMax = deplMaxContenu();

    m_slider_H->setVisible ( deplPossibleMax.x > 0 );
    m_slider_V->setVisible ( deplPossibleMax.y > 0 );

    m_contenant->setSize({ m_taille.x -  m_slider_V->getTaille().x , m_taille.y -  m_slider_H->getTaille().y});

    // si le contenu est plus grand que le contenant
    if ( m_slider_H->estVisible() ) {
        float coef                  = (  m_slider_H->getValeur() ) / 100;

        m_posContenant.x              = coef * deplPossibleMax.x;

        float longueurCursH = m_taille.x/ float( boundgingB_enfants().width )* 100 ;
        m_slider_H->setLongueurCurseur(longueurCursH);
        m_slider_H->setLongueur( m_taille.x -  m_slider_V->getTaille().x );
        m_slider_H->setPosition( 0 , m_taille.y - m_slider_H->getTaille().y);
//        m_slider_H->setTexteStyle       ( m_skin->getStyle (  gui::Styles::bouton ) );

    // si le contenu est plus petit, on cache le slider
    } else {
        m_posContenant.x      = 0;
    }

    // si contenu plus grand, on a le slider vert
    if (  m_slider_V->estVisible() ) {  // si contenu plus grand, on a le slider
        float coef                  = ( 100 - m_slider_V->getValeur() ) / 100;
        m_posContenant.y              = coef * deplPossibleMax.y;


        float longueurCursV = m_taille.y /float( boundgingB_enfants().height )* 100 ;
        m_slider_V->setLongueurCurseur( longueurCursV );
        m_slider_V->setLongueur ( m_taille.y - m_slider_H->getTaille().y );
        m_slider_V->setPosition ( m_taille.x - m_slider_V->getTaille().x , 0 );
//        m_slider_V->setTexteStyle    ( m_skin->getStyle (  gui::Styles::bouton ) );

    // si le contenu est plus petit, on cache le slider
    } else {
        m_posContenant.y      = 0;
    }


//    m_fond->setTexteStyle ( m_skin->getStyle ( Styles::fond ) );

    actualiserContenu();

    if ( m_parent != nullptr ) m_parent->actualiserContenu();

    actualiserBounds ();

}
*/



/////////////////////////////////////////////////
void CntSliders::actualiserMasque () {

    sf::Vector2f deplPossibleMax = deplMaxContenu();


    // si le contenu est plus grand que le contenant
    if ( m_slider_H->estVisible() ) {
        float coef                  = (  m_slider_H->getValeur() ) / 100;
        m_posContenant.x              = coef * deplPossibleMax.x;
    } else {
        m_posContenant.x      = 0;
    }

    // si contenu plus grand, on a le slider vert
    if (  m_slider_V->estVisible() ) {  // si contenu plus grand, on a le slider
        float coef                  = ( 100 - m_slider_V->getValeur()  ) / 100;
        m_posContenant.y              = coef * deplPossibleMax.y;
    } else {
        m_posContenant.y      = 0;
    }


    m_groupe->setPosition ( -m_posContenant.x , -m_posContenant.y );

     m_affContenant->setTextureRect(   { m_posContenant.x
                                    , m_posContenant.y
                                    , m_affContenant->getSize().x
                                    , m_affContenant->getSize().y });

    if (m_parent != nullptr)
        m_parent->actualiserContenu();

}


/////////////////////////////////////////////////
void CntSliders::draw (sf::RenderTarget& target, sf::RenderStates states) const
{

    if ( estVisible() ) {

        //On applique la transformation
        states.transform *= getTransform();

//        target.draw( *m_fond , states );
        target.draw( *m_affContenant , states );
        target.draw( *m_slider_V , states );
        target.draw( *m_slider_H , states );

    }

}


} // fin namespace gui

