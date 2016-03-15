/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <BtnRectangle.h>



namespace gui {

/////////////////////////////////////////////////
BtnRectangle::BtnRectangle ()
: m_rectangle   ( std::make_shared<AffRectangle>())
//, m_focus       ( std::make_shared<AffRectangle>())
{

//    logTitre("Creation");

    creerNomUnique( "BtnRectangle" );
//    log ("Creation");
    m_taille= {25,25};
    // creer l'interface locale
    ajouterComposant( m_rectangle );
//    ajouterComposant( m_focus );

    // valeurs par defaut
    m_couleurFond.set   ( sf::Color( 60, 60, 60 )  , Etat::desactive );
    m_couleurFond.set   ( sf::Color( 255,255,255, 20 )  , Etat::repos );
    m_couleurFond.set   ( sf::Color( 255,255,255, 40 ) , Etat::survol );
    m_couleurFond.set   ( sf::Color( 255,255,255, 100 ) , Etat::press );
    m_couleurLignes.set ( sf::Color( 0,255,0, 255 ) );
    m_epaisseur.set     ( 0 );

    // le focus
//    m_focus->setVisible ( false );
//    m_couleurFocus      = sf::Color( 200,200,200);
//    m_epaisseurFocus    = 1;

//    m_focus->setFillColor           (sf::Color::Transparent);
//    m_focus->setOutlineColor        (m_couleurFocus);
//    m_focus->setOutlineThickness    (m_epaisseurFocus);
//    actualiser();

    actualiserStyle ();
    actualiserGeometrie ();

}

///////////////////////////////////////////////////
//void BtnRectangle::setStyle ( std::shared_ptr<Style> style , Etat etat )
//{
//    m_couleurFond.set   ( style->fnd_couleur   , etat );
//    m_couleurLignes.set ( style->lgn_couleur   , etat );
//    m_epaisseur.set     ( style->lgn_epaisseur , etat );
//
//    actualiserStyle ();
//    actualiserGeometrie ();
//}


/////////////////////////////////////////////////
void BtnRectangle::actualiserGeometrie ()
{
    // Debuggage
    log ("actualiserGeometrie  ");

    m_rectangle->setTaille ( {m_taille.x, m_taille.y} );
//    m_focus->setTaille ( {m_taille.x, m_taille.y} );

    demanderActuaBounds();
}

/////////////////////////////////////////////////
void BtnRectangle::actualiserStyle ()
{
    // Debuggage
    log ("ActualiserStyle");

    // on applique le style correspondant à l'état
    m_rectangle->setFillColor    ( sf::Color (
                                      m_couleurFond.get( this->etat() ).r
                                    , m_couleurFond.get( this->etat() ).g
                                    , m_couleurFond.get( this->etat() ).b
                                    , m_couleurFond.get( this->etat() ).a * m_opacite ) ) ;

    m_rectangle->setOutlineColor     ( sf::Color (
                                      m_couleurLignes.get( this->etat() ).r
                                    , m_couleurLignes.get( this->etat() ).g
                                    , m_couleurLignes.get( this->etat() ).b
                                    , m_couleurLignes.get( this->etat() ).a * m_opacite ) ) ;
    m_rectangle->setOutlineThickness ( m_epaisseur.get( this->etat() ) ) ;

}


} // fin namespace gui

