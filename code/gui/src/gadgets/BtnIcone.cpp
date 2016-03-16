/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <BtnIcone.h>



namespace gui {

/////////////////////////////////////////////////
BtnIcone::BtnIcone ()
: m_icone       ( std::make_shared<AffIcone>())
, m_fix ( false )
{
    creerNomUnique( "BtnIcone" );

    m_marge       = { 1 , 1} ;


    ajouterComposant( m_icone );

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
    m_rectangle->setTaille ( {m_taille.x, m_taille.y} );

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

    m_icone->setLigneEpaisseur ( 0 ) ;

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
    m_rectangle->setFondCouleur       ( sf::Color ( m_couleurFond.get( this->etat() ).r
                                                , m_couleurFond.get( this->etat() ).g
                                                , m_couleurFond.get( this->etat() ).b
                                                , m_couleurFond.get( this->etat() ).a * m_opacite ) ) ;
    m_rectangle->setLigneCouleur    ( sf::Color ( m_couleurLignes.get( this->etat() ).r
                                                , m_couleurLignes.get( this->etat() ).g
                                                , m_couleurLignes.get( this->etat() ).b
                                                , m_couleurLignes.get( this->etat() ).a * m_opacite ) ) ;
    m_rectangle->setLigneEpaisseur ( m_epaisseur.get( this->etat() ) ) ;

}


/////////////////////////////////////////////////
void BtnIcone::setIndex( unsigned int val )    {
    m_icone->setIndex( val );
    demanderActuaStyle ();
};


/////////////////////////////////////////////////
void BtnIcone::setImage( std::string fichier )  {
    m_icone->setImage (fichier);
    demanderActuaGeom ();
};


/////////////////////////////////////////////////
void BtnIcone::setImage ( sf::Texture* texture )  {
    m_icone->setImage( texture );
    demanderActuaGeom ();
};


/////////////////////////////////////////////////
void BtnIcone::setFix (bool val) {
    m_fix = val;
};


} // fin namespace gui























