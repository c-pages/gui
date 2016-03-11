/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <BtnMenu.h>
#include <Interface.h>



namespace gui {
std::shared_ptr<BtnMenu>        BtnMenu::ms_menuOuvert = nullptr;

/////////////////////////////////////////////////
BtnMenu::BtnMenu ()
: m_elements    ( 0 )
, m_tailleMenu  ( { 150 , 15 } )
, m_ecart       ( 0 )
, m_fond        (std::make_shared<AffRectangle>())
, m_ombre        (std::make_shared<AffRectangle>())
, m_ombreActive ( false )
{
    m_marge.x = 0;
    m_marge.y = 0;

    m_ombre->setPosition (5,5);

/*
    m_couleurLignes.set ( sf::Color( 0,255,0, 255 ) );
    m_epaisseur.set     ( 0 );*/
    m_btnCouleurs.set   ( sf::Color( 0, 0, 0, 0 )  , Etat::desactive );
    m_btnCouleurs.set   ( sf::Color( 0,0,0, 0 )  , Etat::repos );
    m_btnCouleurs.set   ( sf::Color( 0,0,0, 120 ) , Etat::survol );
    m_btnCouleurs.set   ( sf::Color( 0,0,0, 150 ) , Etat::press );

    m_ombreCouleur                  = sf::Color( 0,0,0, 100 );
    m_ombreLgnCouleur               = sf::Color( 255,255,255, 255 );

    m_btnLignesCouleurs.set   ( sf::Color( 0, 0, 0, 0 )  , Etat::desactive );
    m_btnLignesCouleurs.set   ( sf::Color( 0,0,0, 50 )  , Etat::repos );
    m_btnLignesCouleurs.set   ( sf::Color( 0,0,0, 200 ) , Etat::survol );
    m_btnLignesCouleurs.set   ( sf::Color( 0,0,0, 200 ) , Etat::press );



    m_ombreLgnepaisseur             = 0;

//    m_btnLignesCouleurs     = sf::Color( 255 , 100 , 100 );
    m_btnLignesEpaisseurs   = 0;

    m_fndCouleur            = sf::Color( 255 , 255 , 255 );
    m_fndLignesCouleur      = sf::Color( 50 , 50 , 50);
    m_fndLignesEpaisseur    = 1;

    m_textCouleur           = sf::Color( 50 , 50 , 50 );

    m_textCouleur.set   ( sf::Color( 0, 0, 0, 0 )  , Etat::desactive );
    m_textCouleur.set   ( sf::Color( 0,0,0, 255 )  , Etat::repos );
    m_textCouleur.set   ( sf::Color( 255,255,255, 255 ) , Etat::survol );
    m_textCouleur.set   ( sf::Color( 255,255,255, 255 ) , Etat::press );


    m_textStyle             = sf::Text::Style::Regular;
    m_textTaille            = 10;
    m_textPolice            = Interface::ms_polices.get ( "Defaut" );

    actualiser();
}


/////////////////////////////////////////////////
void BtnMenu::ajouterElement (std::string nom, FctnAction fonction)
{

    ElementMenu *    nouvelElement = new ElementMenu ();

    nouvelElement->nom      = nom;
    nouvelElement->fonction = fonction;

    std::shared_ptr<BtnTexte>     bouton = std::make_shared<BtnTexte>( );

    bouton->setMarge            ( { 5 , 2 } );
    bouton->setTexte            ( nom );
    bouton->setAutoAjuster      ( false );
    bouton->setParent           ( this );

    if ( nom == "" ){
        bouton->setActif(false);
        bouton->setTaille           ( { m_tailleMenu.x , m_tailleMenu.y/3 } );
    } else {
        bouton->setTaille           ( m_tailleMenu );
    }

    bouton->lier                ( Evenement::onBtnG_relacher , fonction );
    nouvelElement->bouton   = bouton;

    m_elements.push_back( nouvelElement );

    actualiser ();

}


/////////////////////////////////////////////////
void BtnMenu::supprimerElement (unsigned int id)
{

}

/////////////////////////////////////////////////
void BtnMenu::actualiserBounds ()
{
    int decallage = m_marge.y ;
    for ( auto element : m_elements ) {
        decallage += element->bouton->getTaille().y + m_ecart;
    }
    m_taille.x = m_tailleMenu.x + 2 * m_marge.x;
    m_taille.y = decallage + m_marge.y;
    Geometrie::actualiserBounds();

}
void BtnMenu::actualiserGeometrie()
{
    int decallage = m_marge.y ;
    for ( auto element : m_elements ) {

        element->bouton->setPosition    ( m_marge.x , decallage );
        element->bouton->setTexte       ( element->nom );
        decallage += element->bouton->getTaille().y + m_ecart;
    }
    m_taille.y = decallage + m_marge.y;
    actualiserBounds ();
    m_fond->setTaille( m_taille );
    m_ombre->setTaille( m_taille );
}

/////////////////////////////////////////////////
void BtnMenu::actualiserStyle()
{
    for ( auto element : m_elements ) {

        auto btn = element->bouton;

        btn->setFillColor       ( m_btnCouleurs );
        btn->setOutlineColor    ( m_btnLignesCouleurs );
        btn->setOutlineThickness( m_btnLignesEpaisseurs );

        btn->setTexteTaille     ( m_textTaille );
        btn->setTexteCouleur    ( m_textCouleur );
        btn->setPolice          ( m_textPolice );
        btn->setTexteStyle      ( m_textStyle );
    }

    m_fond->setFillColor         ( m_fndCouleur );
    m_fond->setOutlineColor      ( m_fndLignesCouleur );
    m_fond->setOutlineThickness  ( m_fndLignesEpaisseur );

    m_ombre->setFillColor            ( m_ombreCouleur ) ;
    m_ombre->setOutlineColor         ( m_ombreLgnCouleur  ) ;
    m_ombre->setOutlineThickness     ( m_ombreLgnepaisseur  );
}

/////////////////////////////////////////////////
std::shared_ptr<Gadget>  BtnMenu::testerSurvol ( sf::Vector2i position )
{

//    std::cout << "  testerSurvol MENU ...\n";
    if ( m_globalBounds.contains( position.x, position.y ) )
    {
        // Si on survol un bouton on le renvois
        for ( auto element : m_elements )
            if ( element->bouton->testerSurvol ( position ) != nullptr )
            {
//                std::cout << "    >>> SURVOL --------- " << element->bouton->getNom() << " <<<\n";
                std::shared_ptr<Gadget> result = element->bouton;
//                std::cout << "    >>> result --------- " << result->getNom() << " <<<\n";
                return result;
                //return nullptr;
            }

        // Sinon on renvois le menu
//        std::cout << "    >>> SURVOL ######### " << getNom() << " <<<\n";
        //return thisPtr();
        return nullptr;
    }

    return nullptr;
}
/*
/////////////////////////////////////////////////
std::shared_ptr<Gadget> BtnMenu::chercherEnfantSurvole ( sf::Vector2i pos )
{
    for ( auto element : m_elements )
        if ( element->bouton->testerSurvol ( pos ) )
            return element->bouton;

    return nullptr;
}*/




/////////////////////////////////////////////////
void BtnMenu::draw (sf::RenderTarget& target, sf::RenderStates states) const
{
    if ( ! estVisible() )
        return;

    //On applique la transformation
    states.transform *= getTransform();

    if ( m_ombreActive )
        target.draw ( *m_ombre , states ) ;

    target.draw ( *m_fond , states ) ;

    // On dessine les éléments
    for ( auto element : m_elements )
        target.draw ( *element->bouton , states ) ;
}


} // fin namespace gui

