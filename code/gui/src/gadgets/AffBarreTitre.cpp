/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <AffBarreTitre.h>
#include <Interface.h>



namespace gui {

/////////////////////////////////////////////////
AffBarreTitre::AffBarreTitre ()
: m_fond ( std::make_shared<AffRectangle>() )
, m_titre ( std::make_shared<AffLabel>() )
, m_icone ( std::make_shared<AffIcone>() )
{
    m_taille = { 200 , 20 };
    m_marge = { 2 , 2 };

    ajouterComposant( m_fond );
    ajouterComposant( m_titre );
    ajouterComposant( m_icone );


    m_textCouleur           = sf::Color( 0,255,0, 255 ) ;
    m_textStyle             = sf::Text::Style::Regular;
    m_textTaille            = 12;
    m_textPolice            = Interface::ms_polices.get ("Defaut" );

    m_fndCouleur            = sf::Color( 0,255,0, 255 ) ;
    m_fndLignesCouleur      = sf::Color( 0,0,255, 255 ) ;
    m_fndLignesEpaisseur    = 1;

    actualiser ();

}


/////////////////////////////////////////////////
void AffBarreTitre::setIconeImage ( sf::Texture* texture  )
{
    m_icone->setImage( texture );
}

/////////////////////////////////////////////////
void AffBarreTitre::setIconeImage ( std::string texture )
{
    m_icone->chargerDepuisFichier( texture );
}


/////////////////////////////////////////////////
void AffBarreTitre::setIconeIndex ( int index )
{
    m_icone->setIndex ( index );
}



/////////////////////////////////////////////////
void AffBarreTitre::actualiserGeometrie ()
{

    m_titre->setTexte ( m_texte );

    m_icone->setTaille      ( { m_taille.y + m_marge.x, m_taille.y + m_marge.y } );
    m_icone->setPosition    ( m_marge.x, m_marge.y );

    m_fond->setTaille  ( { m_taille.x , m_taille.y } );

    m_titre->setPosition    ( m_taille.y + m_marge.x, m_marge.y );

    actualiserBounds ();

}

/////////////////////////////////////////////////
void AffBarreTitre::actualiserStyle ()
{

    m_titre->setTexteTaille     ( m_textTaille );
    m_titre->setTexteCouleur    ( m_textCouleur );
    m_titre->setPolice          ( m_textPolice );
    m_titre->setTexteStyle      ( m_textStyle );

    m_fond->setFillColor        ( m_fndCouleur );
    m_fond->setOutlineColor     ( m_fndLignesCouleur );
    m_fond->setOutlineThickness ( m_fndLignesEpaisseur );

//    m_titre->setStyle       ( m_skin->getStyle ( Styles::fenetre ) );
//    if ( m_parent != nullptr ) m_parent->actualiserContenu();
}
/*
/////////////////////////////////////////////////
void AffBarreTitre::actualiser ()
{


    m_titre->setStyle       ( m_skin->getStyle ( Styles::fenetre ) );
    if ( m_parent != nullptr ) m_parent->actualiserContenu();


}*/

/*
/////////////////////////////////////////////////
void AffBarreTitre::draw (sf::RenderTarget& target, sf::RenderStates states) const
{

}
*/

} // fin namespace gui

