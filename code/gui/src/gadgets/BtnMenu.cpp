/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <BtnMenu.h>



namespace gui {

/////////////////////////////////////////////////
BtnMenu::BtnMenu ()
: m_elements    ( 0 )
, m_tailleMenu  ( { 180 , 15 } )
, m_ecart       ( 0 )
{
    m_marge.x = 0;
    m_marge.y = 0;
}


/////////////////////////////////////////////////
void BtnMenu::ajouter (std::string nom, FctnAction fonction)
{
//    std::cout << "Menu: Ajouter '" << nom << "'\n";

    ElementMenu *    nouvelElement = new ElementMenu ();

    nouvelElement->nom      = nom;
    nouvelElement->fonction = fonction;

    std::shared_ptr<Bouton>     bouton = std::make_shared<BtnRectangle>( );
    bouton->setMarge            ( { 5 , 2 } );
    bouton->setTexte            ( nom );
    bouton->setAutoAjuster      ( false );
    bouton->setTaille           ( m_tailleMenu );
    bouton->setParent           ( this );
    bouton->setSkin             ( m_skin );
    bouton->lier                ( Evenement::onBtnG_relacher , fonction );
    nouvelElement->bouton   = bouton;

    m_elements.push_back( nouvelElement );

    actualiser ();
}


/////////////////////////////////////////////////
void BtnMenu::supprimer (unsigned int id)
{

}

/////////////////////////////////////////////////
void BtnMenu::actualiser_bounds ()
{
    m_taille.x = m_tailleMenu.x + 2 * m_marge.x;
    m_taille.y = m_elements.size() *  m_tailleMenu.y + ( m_elements.size()-1) * m_ecart  + 2 * m_marge.y;
    Geometrie::actualiser_bounds();

}


/////////////////////////////////////////////////
void BtnMenu::actualiser ()
{
    int index = 0;
    for ( auto element : m_elements ) {

        element->bouton->setPosition    ( m_marge.x , index * ( m_tailleMenu.y + m_ecart ) + m_marge.y );
        element->bouton->setTexte       ( element->nom );
        element->bouton->setStyle       ( m_skin->menu );

        index++;
    }
    actualiser_bounds ();

    m_fond.setTaille( m_taille );

    m_fond.setFillColor         ( m_skin->fond->fnd_couleur.repos );
    m_fond.setOutlineColor      ( m_skin->fond->lgn_couleur.repos );
    m_fond.setOutlineThickness  ( m_skin->fond->lgn_epaisseur.repos );

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

   target.draw ( m_fond , states ) ;

    // On dessine les éléments
    for ( auto element : m_elements )
        target.draw ( *element->bouton , states ) ;
}


} // fin namespace gui

