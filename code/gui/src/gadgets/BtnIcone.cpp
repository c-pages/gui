/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <BtnIcone.h>



namespace gui {

/////////////////////////////////////////////////
BtnIcone::BtnIcone ()
: m_fix ( false )
{
    creerNomUnique( "BtnIcone" );
    m_marge       = { 1 , 1} ;


    // initialiser les composants herités
    CmpIcone::initialiserComposants ( this );

    m_icone->setIndex ( 1 );

}


/////////////////////////////////////////////////
void BtnIcone::actualiserGeometrie ()
{
    log ("actualiserGeometrie");

    if ( m_autoAjust ){
        m_icone->actualiserGeometrie();
        m_taille = { m_icone->getTaille().x + m_marge.x*2 , m_icone->getTaille().y + m_marge.y*2 } ;
    }

    m_icone->setPosition( m_marge.x  , m_marge.y );
    m_fond->setTaille ( {m_taille.x, m_taille.y} );

    demanderActuaBounds();
}

/////////////////////////////////////////////////
void BtnIcone::actualiserStyle ()
{
    log ("actualiserStyle");

    m_icone->setFondCouleur    ( sf::Color (
                                      255
                                    , 255
                                    , 255
                                    , 255 * m_opacite ) ) ;

    m_icone->setFondLigneEpaisseur ( 0 ) ;

    if ( ! m_fix )    {
        switch ( this->etat() ){
            case Etat::repos:       m_icone->setIndex ( 1 );    break;
            case Etat::survol:      m_icone->setIndex ( 2 );    break;
            case Etat::press:       m_icone->setIndex ( 3 );    break;
            case Etat::desactive:   m_icone->setIndex ( 4 );    break;
            default: break;
        }
    }

    // on applique le style correspondant à l'état au rectangle
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



/////////////////////////////////////////////////
void BtnIcone::setFix (bool val) {
    m_fix = val;
};


} // fin namespace gui























