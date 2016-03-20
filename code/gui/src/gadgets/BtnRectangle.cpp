/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <BtnRectangle.h>



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
    m_fond->setFondCouleur       ( sf::Color ( m_couleurFond.get( this->etat() ).r
                                                , m_couleurFond.get( this->etat() ).g
                                                , m_couleurFond.get( this->etat() ).b
                                                , m_couleurFond.get( this->etat() ).a * m_opacite ) ) ;
    m_fond->setFondLigneCouleur    ( sf::Color ( m_couleurLignes.get( this->etat() ).r
                                                , m_couleurLignes.get( this->etat() ).g
                                                , m_couleurLignes.get( this->etat() ).b
                                                , m_couleurLignes.get( this->etat() ).a * m_opacite ) ) ;
    m_fond->setFondLigneEpaisseur ( m_epaisseur.get( this->etat() ) ) ;

}


} // fin namespace gui

