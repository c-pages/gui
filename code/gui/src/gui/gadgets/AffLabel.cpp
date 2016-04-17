/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <gadgets/AffLabel.h>
#include <Interface.h>



namespace gui {

/////////////////////////////////////////////////
AffLabel::AffLabel ()
: Affiche ()
, m_texteSFML   (  )
, m_textCouleur ( sf::Color::White )
, m_textStyle   ( sf::Text::Style::Regular )
, m_textTaille  ( 15 )
, m_textPolice  ( Interface::ms_polices.get ( "Defaut" ) )
{
    // Creation du nom unique du gadget
    creerNomUnique( "Label" );
//    m_mute = false;
    actualiserStyle();
}

/////////////////////////////////////////////////
void AffLabel::actualiserGeometrie ()
{
    // Debuggage
    log ("actualiserGeometrie");

//    m_texteSFML.setString ( m_texte );

    demanderActuaBounds();
}

/////////////////////////////////////////////////
void AffLabel::actualiserStyle ()
{
    // Debuggage
    log ("actualiserStyle");

    m_texteSFML.setFont            ( m_textPolice );
    m_texteSFML.setColor           ( m_textCouleur );
    m_texteSFML.setStyle           ( m_textStyle );
    m_texteSFML.setCharacterSize   ( m_textTaille );
}



/////////////////////////////////////////////////
void AffLabel::setTexte( std::string val )
{
    // Debuggage
    log("setTexte");
    log("m_texte",  val  );
//    m_mute = false;

//    m_texte = val;
    m_texteSFML.setString( val );
    demanderActuaBounds();
};


/////////////////////////////////////////////////
void AffLabel::setTexteTaille( float val ){
    m_textTaille = val;
    m_texteSFML.setCharacterSize ( val ) ;
    // la taille du texte a changé alors on doit recalculé les bounds
    demanderActuaBounds();
};


/////////////////////////////////////////////////
void AffLabel::setTexteCouleur( sf::Color couleur ){
    m_textCouleur = couleur;
    m_texteSFML.setColor ( couleur );
};


/////////////////////////////////////////////////
void AffLabel::setTextePolice( sf::Font val ){
    std::string txtTmp =  m_texteSFML.getString( );
    m_textPolice = val;
    m_texteSFML.setString( txtTmp );
    // la taille du texte a changé alors on doit recalculé les bounds
    demanderActuaBounds();
};


/////////////////////////////////////////////////
void AffLabel::setTexteStyle( sf::Text::Style val ){
    m_textStyle = val;
    m_texteSFML.setStyle    ( m_textStyle );
    // la taille du texte a changé alors on doit recalculé les bounds
    demanderActuaBounds();
};


/////////////////////////////////////////////////
sf::Vector2i  AffLabel::getTaille() const{
    return { m_texteSFML.getGlobalBounds().width , m_texteSFML.getGlobalBounds().height };
}




/////////////////////////////////////////////////
void AffLabel::draw (sf::RenderTarget& target, sf::RenderStates states) const
{
    //On applique la transformation
    states.transform *= getTransform();

    // On dessine le texte
    target.draw( m_texteSFML, states);
}




} // fin namespace gui

