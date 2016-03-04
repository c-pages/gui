/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <BtnMenu.h>
#include <Interface.h>



namespace gui {

/////////////////////////////////////////////////
BtnMenu::BtnMenu ()
: m_elements    ( 0 )
, m_tailleMenu  ( { 150 , 15 } )
, m_ecart       ( 0 )
, m_fond        (std::make_shared<AffRectangle>())
{
    m_marge.x = 0;
    m_marge.y = 0;

    m_btnCouleurs           = sf::Color( 255 , 0 , 0 );
    m_btnLignesCouleurs     = sf::Color( 255 , 100 , 100 );
    m_btnLignesEpaisseurs   = 1;

    m_fndCouleur            = sf::Color( 255 , 0 , 0 );
    m_fndLignesCouleur      = sf::Color( 255 , 100 , 100 );
    m_fndLignesEpaisseur    = 1;

    m_textCouleur           = sf::Color( 255 , 0 , 0 );
    m_textStyle             = sf::Text::Style::Regular;
    m_textTaille            = 10;
    m_textPolice            = Interface::ms_polices.get ( "Defaut" );
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
    bouton->setTaille           ( m_tailleMenu );
    bouton->setParent           ( this );

    bouton->setFillColor        ( m_btnCouleurs );
    bouton->setOutlineColor     ( m_btnLignesCouleurs );
    bouton->setOutlineThickness     ( m_btnLignesEpaisseurs );

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
    m_taille.x = m_tailleMenu.x + 2 * m_marge.x;
    m_taille.y = m_elements.size() *  m_tailleMenu.y + ( m_elements.size()-1) * m_ecart  + 2 * m_marge.y;
    Geometrie::actualiserBounds();

}
void BtnMenu::actualiserGeometrie()
{
    int index = 0;
    for ( auto element : m_elements ) {

        element->bouton->setPosition    ( m_marge.x , index * ( m_tailleMenu.y + m_ecart ) + m_marge.y );
        element->bouton->setTexte       ( element->nom );

        index++;
    }
    actualiserBounds ();
    m_fond->setTaille( m_taille );
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
    //On applique la transformation
    states.transform *= getTransform();

   target.draw ( *m_fond , states ) ;

    // On dessine les éléments
    for ( auto element : m_elements )
        target.draw ( *element->bouton , states ) ;
}


} // fin namespace gui

