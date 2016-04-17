/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <gadgets/BtnRectangle.h>



namespace gui {

/////////////////////////////////////////////////
BtnRectangle::BtnRectangle ()
{
    creerNomUnique( "BtnRectangle" );

    m_taille= {25,25};

    // initialiser les composants herités
    CmpFond::initialiserComposants ( this );

}


/////////////////////////////////////////////////
void BtnRectangle::actualiserGeometrie ()
{
    log ("actualiserGeometrie  ");

    m_fond->setTaille ( {m_taille.x, m_taille.y} );

    demanderActuaBounds();
}

/////////////////////////////////////////////////
void BtnRectangle::actualiserStyle ()
{
    // Debuggage
    log ("ActualiserStyle");

    // on applique le style correspondant à l'état
    CmpFond::appliquerEtat( this->etat() );


}


} // fin namespace gui

