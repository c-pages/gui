/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <gadgets_outils/SupBandeauMenusDeroulants.h>
#include <gadgets_outils/BtnMenu.h>
#include <Interface.h>


namespace gui {
std::string             SupBandeauMenusDeroulants::ms_menuBack = "";
bool                    SupBandeauMenusDeroulants::ms_menuActif = false;
bool                    SupBandeauMenusDeroulants::ms_init = false;


/////////////////////////////////////////////////
SupBandeauMenusDeroulants::SupBandeauMenusDeroulants ()
{
    m_marge = { 3 , 2 };
    m_taille = { 150 , 20 };
}

void SupBandeauMenusDeroulants::ajouterMenu ( std::string nom )
{

    ElementMenu *    nouvelElement = new ElementMenu ();

    nouvelElement->nom      = nom;

    std::shared_ptr<BtnTexte>     bouton = std::make_shared<BtnTexte>( );

    bouton->setMarge            ( { 5 , 5 } );
    bouton->setTexte            ( nom );
    bouton->setAutoAjuster      ( false );
    bouton->setAutoAjuster      ( true );


    nouvelElement->menu = std::make_shared<BtnMenu>( );
    nouvelElement->menu->setVisible(false);
    nouvelElement->menu->setOmbreActive ( true );

    Interface::ms_calque_menuDeroulants->ajouter ( nouvelElement->menu ) ;



    ajouter (bouton);



    bouton->lier                ( Evenement::onBtnG_presser , [nouvelElement](){
        if ( ms_menuActif )
        {
            if ( nouvelElement->menu->ms_menuOuvert != nullptr )
                nouvelElement->menu->ms_menuOuvert->setVisible( false );
            ms_menuActif = false;
        } else {
    //        std::cout << " declencher ouvrir\n";
    //            nouvelElement->menu
            if ( nouvelElement->menu->ms_menuOuvert != nullptr )
                nouvelElement->menu->ms_menuOuvert->setVisible( false );

            nouvelElement->menu->setVisible(true);
            nouvelElement->menu->ms_menuOuvert = nouvelElement->menu;
            nouvelElement->menu->setPosition ( nouvelElement->bouton->getPosAbs().x
                                             , nouvelElement->bouton->getPosAbs().y + nouvelElement->bouton->getTaille().y
                                             );

            ms_menuActif = true;
            ms_init = true;
        }
    } );



    bouton->lier                ( Evenement::on_entrer , [nouvelElement](){
//        std::cout << " declencher changer menu\n";
//            nouvelElement->menu
        if ( ! ms_menuActif ) return;
//        std::cout << " ... menu ouvert ...\n";

        if ( nouvelElement->menu->ms_menuOuvert != nullptr )
            nouvelElement->menu->ms_menuOuvert->setVisible( false );
        nouvelElement->menu->setVisible(true);
        nouvelElement->menu->ms_menuOuvert = nouvelElement->menu;
        nouvelElement->menu->setPosition ( nouvelElement->bouton->getPosAbs().x
                                         , nouvelElement->bouton->getPosAbs().y + nouvelElement->bouton->getTaille().y
                                         );
    } );



    nouvelElement->menu->lier ( Evenement::onBtnG_relacherDehors , [nouvelElement](){
//            nouvelElement->menu
//        std::cout << " declencher fermeture\n";
        if ( ms_init){
            ms_init = false;
            return;
        }
        if ( ms_menuActif ) {
            if ( nouvelElement->menu->ms_menuOuvert != nullptr )
                nouvelElement->menu->ms_menuOuvert->setVisible( false );
            ms_menuActif= false;
        }

    } );
//
//    fct_ouvrirMenu =

    nouvelElement->bouton   = bouton;

    m_elements.push_back( nouvelElement );

    actualiser ();
    ms_menuBack = nom;
}


void SupBandeauMenusDeroulants::ajouterElement ( std::string nom, FctnAction fonction, std::string menu  )
{

    for ( auto element : m_elements )
        if ( element->nom == menu ) {
            element->menu->ajouterElement ( nom, fonction );

        }
//
//
//
//    ElementMenu *    nouvelElement = new ElementMenu ();
//
//    nouvelElement->nom      = nom;
//    nouvelElement->fonction = fonction;
//
//    std::shared_ptr<BtnTexte>     bouton = std::make_shared<BtnTexte>( );
//
//    bouton->setMarge            ( { 5 , 2 } );
//    bouton->setTexte            ( nom );
////    bouton->setParent           ( this );
//    bouton->setAutoAjuster      ( true );
//    bouton->setTexteTaille      ( 5 );
//    bouton->setAutoAjuster      ( false );
//    bouton->setTailleX          ( 20 );
//
//    ajouter ( bouton );
//
//    bouton->lier                ( Evenement::onBtnG_relacher , fonction );
//    nouvelElement->bouton   = bouton;
//
//    m_elements.push_back( nouvelElement );
//
//    actualiser ();

}

/////////////////////////////////////////////////
/// \brief
///
/// \param id
/////////////////////////////////////////////////
void SupBandeauMenusDeroulants::supprimerElement (unsigned int id)
{

}

//    virtual void actualiser ();
void SupBandeauMenusDeroulants::actualiserBounds ()
{
SupBandeau::actualiserBounds ();
}

/////////////////////////////////////////////////
void SupBandeauMenusDeroulants::actualiserGeometrie()
{
    SupBandeau::actualiserGeometrie ();

    int decallage = m_marge.x;
    for ( auto element : m_elements ) {

        element->bouton->setPosition    ( decallage, m_marge.y );
        element->bouton->setTexte       ( element->nom );
        element->bouton->setTexteTaille ( 10 );

        decallage += element->bouton->getTaille().x;
    }
    actualiserBounds ();
}

/////////////////////////////////////////////////
void SupBandeauMenusDeroulants::actualiserStyle()
{
    SupBandeau::actualiserStyle ();
}

///////////////////////////////////////////////////
//std::shared_ptr<Gadget>  SupBandeauMenusDeroulants::testerSurvol ( sf::Vector2i position )
//{
//
//    std::cout << "  testerSurvol MENU ...\n";
//    if ( m_globalBounds.contains( position.x, position.y ) )
//    {
//        // Si on survol un bouton on le renvois
//        for ( auto element : m_elements )
//            if ( element->bouton->testerSurvol ( position ) != nullptr )
//            {
////                std::cout << "    >>> SURVOL --------- " << element->bouton->getNom() << " <<<\n";
//                std::shared_ptr<Gadget> result = element->bouton;
////                std::cout << "    >>> result --------- " << result->getNom() << " <<<\n";
//                return result;
//                //return nullptr;
//            }
//
//        // Sinon on renvois le menu
////        std::cout << "    >>> SURVOL ######### " << getNom() << " <<<\n";
//        //return thisPtr();
//        return nullptr;
//    }
//
//    return nullptr;
//}
//
//
///////////////////////////////////////////////////
//void SupBandeauMenusDeroulants::draw (sf::RenderTarget& target, sf::RenderStates states) const
//{
//    //On applique la transformation
//    states.transform *= getTransform();
//
//   target.draw ( *m_fond , states ) ;
//
//    // On dessine les éléments
//    for ( auto element : m_elements )
//        target.draw ( *element->bouton , states ) ;
//}


} // fin namespace gui

