/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <AffBarreTitre.h>



namespace gui {

/////////////////////////////////////////////////
AffBarreTitre::AffBarreTitre ()
: m_rectangle ( std::make_shared<AffRectangle>() )
, m_titre ( std::make_shared<AffLabel>() )
, m_icone ( std::make_shared<AffIcone>() )
{
    m_taille = { 200 , 20 };
    m_marge = { 2 , 2 };

    ajouterComposant( m_rectangle );
    ajouterComposant( m_titre );
    ajouterComposant( m_icone );

    actualiser ();

}


/////////////////////////////////////////////////
void AffBarreTitre::setIconeImage ( const sf::Texture* texture  )
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
void AffBarreTitre::setTexte (std::string texte)
{
    m_texte = texte;
    m_titre->setTexte ( texte );
}

/////////////////////////////////////////////////
void AffBarreTitre::actualiserGeometrie ()
{
    m_icone->setTaille      ( { m_taille.y + m_marge.x, m_taille.y + m_marge.y } );
    m_icone->setPosition    ( m_marge.x, m_marge.y );

    m_rectangle->setTaille  ( { m_taille.x , m_taille.y } );

    m_titre->setPosition    ( m_taille.y + m_marge.x, m_marge.y );

    actualiserBounds ();

}

/////////////////////////////////////////////////
void AffBarreTitre::actualiserStyle ()
{
    m_titre->setStyle       ( m_skin->getStyle ( Styles::fenetre ) );
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

