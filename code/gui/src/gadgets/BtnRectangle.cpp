/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <BtnRectangle.h>



namespace gui {

/////////////////////////////////////////////////
BtnRectangle::BtnRectangle ()
: m_rectangle   ( std::make_shared<AffRectangle>())
{

    creerNomUnique( "BtnRectangle" );

    m_taille= {25,25};

    // creer l'interface locale
    ajouterComposant( m_rectangle );

    // valeurs par defaut
    m_couleurFond.set   ( sf::Color( 60, 60, 60 )  , Etat::desactive );
    m_couleurFond.set   ( sf::Color( 255,255,255, 20 )  , Etat::repos );
    m_couleurFond.set   ( sf::Color( 255,255,255, 40 ) , Etat::survol );
    m_couleurFond.set   ( sf::Color( 255,255,255, 100 ) , Etat::press );
    m_couleurLignes.set ( sf::Color( 0,255,0, 255 ) );
    m_epaisseur.set     ( 0 );

}


/////////////////////////////////////////////////
void BtnRectangle::actualiserGeometrie ()
{
    // Debuggage
    log ("actualiserGeometrie  ");

    m_rectangle->setTaille ( {m_taille.x, m_taille.y} );

    demanderActuaBounds();
}

/////////////////////////////////////////////////
void BtnRectangle::actualiserStyle ()
{
    // Debuggage
    log ("ActualiserStyle");

    // on applique le style correspondant à l'état
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


//setFondCouleur
//setLigneCouleur
//setLigneEpaisseur
/////////////////////////////////////////////////
void BtnRectangle::setFondCouleur (sf::Color couleur , Etat etat ) {
    m_couleurFond.set ( couleur , etat );
    m_rectangle->setFondCouleur( couleur );
};


/////////////////////////////////////////////////
void BtnRectangle::setLigneCouleur (sf::Color couleur , Etat etat ) {
    m_couleurLignes.set ( couleur , etat );
    m_rectangle->setLigneCouleur( couleur );
};


/////////////////////////////////////////////////
void BtnRectangle::setLigneEpaisseur (float epaisseur , Etat etat ) {
    m_epaisseur.set ( epaisseur , etat );
    m_rectangle->setLigneEpaisseur( epaisseur );
};


/////////////////////////////////////////////////
void BtnRectangle::setFondCouleur ( Valeurs<sf::Color> couleurs  ) {
    m_couleurFond = couleurs;
    demanderActuaStyle();
};


/////////////////////////////////////////////////
void BtnRectangle::setLigneCouleur ( Valeurs<sf::Color> couleurs  ) {
    m_couleurLignes = couleurs;
    demanderActuaStyle();
};


/////////////////////////////////////////////////
void BtnRectangle::setLigneEpaisseur ( Valeurs<float> epaisseur ) {
    m_epaisseur =  epaisseur;
    demanderActuaStyle();
};

} // fin namespace gui

