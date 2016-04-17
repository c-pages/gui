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

    // initialiser les composants herit�s
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

    // on applique le style correspondant � l'�tat
    CmpFond::appliquerEtat( this->etat() );


}


} // fin namespace gui

