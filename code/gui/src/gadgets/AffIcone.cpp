/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <AffIcone.h>
#include <cmath>



namespace gui {

/////////////////////////////////////////////////
AffIcone::AffIcone ()
: AffImage ()
, m_index ( 1 )
, m_nbrIcones (0)
{
    creerNomUnique( "Icone");
}


/////////////////////////////////////////////////
void AffIcone::actualiserGeometrie ()
{
    // Debuggage
    log ("actualiserGeometrie");

    //calcul de la largeur d'un cot�
    int largeur = m_texture->getSize().y;

    // c'est toujours un carr�e
    m_taille = { largeur , largeur };
    m_rectangle.setSize ( { largeur , largeur } );

    demanderActuaBounds();
}

/////////////////////////////////////////////////
void AffIcone::actualiserStyle ()
{
    // Debuggage
    log ("actualiserStyle");

    //calcul de la largeur d'un cot�
    int largeur = m_texture->getSize().y;

    // les style du rectangle
    m_rectangle.setFillColor        ( m_couleurFond );
    m_rectangle.setOutlineColor     ( m_couleurLignes );
    m_rectangle.setOutlineThickness ( m_epaisseur );
    m_rectangle.setTextureRect      ( { ( m_index-1) * largeur, 0, largeur, largeur } );
    m_rectangle.setTexture          ( m_texture );

}


/////////////////////////////////////////////////
void AffIcone::setIndex( unsigned int val ){
    m_index = val;
    demanderActuaStyle ();
}


/////////////////////////////////////////////////
unsigned int AffIcone::getIndex () const {
    return m_index;
}


} // fin namespace gui

