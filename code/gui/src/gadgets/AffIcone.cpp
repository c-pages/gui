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
    creerNom( "Icone");
//    logTitre("Creation");

}


/////////////////////////////////////////////////
void AffIcone::actualiserGeometrie ()
{

    // Debuggage
    log ("actualiserGeometrie");

    int largeur = m_texture->getSize().y;

    m_taille = { largeur , largeur };
    m_rectangle.setSize ( { largeur , largeur } );



}

/////////////////////////////////////////////////
void AffIcone::actualiserStyle ()
{


    // Debuggage
    log ("actualiserStyle");

    m_rectangle.setTextureRect  ( { ( m_index-1) * m_taille.x
                                    , 0
                                    , m_taille.x
                                    , m_taille.y } );

    m_rectangle.setTexture      ( m_texture );

    AffImage::actualiserStyle   ( );


}

} // fin namespace gui

