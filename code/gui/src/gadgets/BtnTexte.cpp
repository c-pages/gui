/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <BtnTexte.h>
#include <Interface.h>




namespace gui {

/////////////////////////////////////////////////
BtnTexte::BtnTexte ()
: BtnRectangle ()
, m_label       ( std::make_shared<AffLabel>())
{
    creerNomUnique ( "BtnTexte");


    m_marge = { 5, 5 };
    m_autoAjust = true;
    m_texte = "";

    // valeurs par defaut
    m_textCouleur.set( sf::Color::White );
    m_textCouleur.set( sf::Color( 100,100,100 ) , Etat::desactive );
    m_textTaille.set ( 12 ) ;
    m_textPolice.set ( Interface::ms_polices.get( "Defaut" ) ) ;
    m_textStyle.set  ( sf::Text::Style::Regular ) ;

    ajouterComposant( m_label );

}

/////////////////////////////////////////////////
void BtnTexte::actualiserGeometrie ()
{
    // Debuggage
    log ( "actualiserGeometrie" );

    m_label->setTexte ( m_texte );
    m_label->actualiserBounds();
    m_label->setPosition( int( m_marge.x ) , int ( m_marge.y/3 ) );

    if ( m_autoAjust ){
        m_taille = { m_label->getTaille().x + m_marge.x*2 , m_label->getTaille().y + m_marge.y*2 } ;
    }

    m_rectangle->setTaille ( {m_taille.x, m_taille.y} );

    demanderActuaBounds();
}

/////////////////////////////////////////////////
void BtnTexte::actualiserStyle ()
{
    // Debuggage
    log ("actualiserStyle");

    // on actualise le label
    m_label->setCouleur    ( sf::Color (
                                      m_textCouleur.get( this->etat() ).r
                                    , m_textCouleur.get( this->etat() ).g
                                    , m_textCouleur.get( this->etat() ).b
                                    , m_textCouleur.get( this->etat() ).a * m_opacite ) ) ;
    m_label->setTailleCharac     ( m_textTaille.get( this->etat() ) ) ;
    m_label->setTextePolice          ( m_textPolice.get( this->etat() ) ) ;
    m_label->setTexteStyle      ( m_textStyle.get( this->etat() ) ) ;

    // on actualise le rectangle
    m_rectangle->setFondCouleur    ( sf::Color (
                                      m_couleurFond.get( this->etat() ).r
                                    , m_couleurFond.get( this->etat() ).g
                                    , m_couleurFond.get( this->etat() ).b
                                    , m_couleurFond.get( this->etat() ).a * m_opacite ) ) ;

    m_rectangle->setLigneCouleur     ( sf::Color (
                                      m_couleurLignes.get( this->etat() ).r
                                    , m_couleurLignes.get( this->etat() ).g
                                    , m_couleurLignes.get( this->etat() ).b
                                    , m_couleurLignes.get( this->etat() ).a * m_opacite ) ) ;
    m_rectangle->setLigneEpaisseur ( m_epaisseur.get( this->etat() ) ) ;

}


/////////////////////////////////////////////////
void BtnTexte::setTexte( std::string val ){
    log("setTexte \"" + val + "\"" );
    m_texte = val;
    m_label->setTexte ( val ) ;
    demanderActuaGeom();
};



/////////////////////////////////////////////////
void BtnTexte::setTailleCharac( float val ){
    m_textTaille = val;
    m_label->setTailleCharac ( val ) ;
};



/////////////////////////////////////////////////
void BtnTexte::setTailleCharac( Valeurs<float> val ){
    m_textTaille = val;
    demanderActuaStyle();
};


/////////////////////////////////////////////////
void BtnTexte::setTexteCouleur( sf::Color couleur ){
    m_textCouleur = couleur;
    m_label->setCouleur ( couleur );
};



/////////////////////////////////////////////////
void BtnTexte::setTexteCouleur( Valeurs<sf::Color> couleur ){
    m_textCouleur = couleur;
    demanderActuaStyle();
};



/////////////////////////////////////////////////
void BtnTexte::setTextePolice( sf::Font val ){
    m_textPolice = val;
};



/////////////////////////////////////////////////
void BtnTexte::setTextePolice( Valeurs<sf::Font> val ){
    m_textPolice = val;
    demanderActuaStyle();
};


/////////////////////////////////////////////////
void BtnTexte::setTexteStyle( sf::Text::Style val ){
    m_textStyle = val;
    m_label->setTexteStyle    ( val );
};



/////////////////////////////////////////////////
void BtnTexte::setTexteStyle( Valeurs<sf::Text::Style> val ){
    m_textStyle = val;
    demanderActuaStyle();
};

} // fin namespace gui

