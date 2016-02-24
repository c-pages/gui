/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <AffLabel.h>



namespace gui {

/////////////////////////////////////////////////
AffLabel::AffLabel ()
: m_texte       ( "Label" )
, m_texteSFML   ( std::make_shared<sf::Text> () )
//, m_texteTaille ( 0 )
, m_police      ( )
{
    m_texteSFML->setString  ( m_texte );
    m_police.loadFromFile( "media/polices/arial.ttf");
    //m_police = m_skin->txtCourant->txt_police.repos;

    m_texteSFML->setFont    ( m_police );

    //m_texteSFML->setColor ( m_skin->txtCourant->txt_couleur.repos );

    actualiser ();
}

/////////////////////////////////////////////////
void AffLabel::setStyle ( std::shared_ptr<Style> style , Etat etat ){
/*
    m_style = style;

    m_texteSFML->setColor           ( m_style->txt_couleur.get(etat) );

//    m_texteSFML->setStyle           ( m_style->txt_style.get(etat) );

    m_texteSFML->setFont            ( m_style->txt_police.get(etat) );
    if ( m_texteTaille != 0 )
        m_texteSFML->setCharacterSize   ( m_texteTaille );
    else
        m_texteSFML->setCharacterSize   ( style->txt_taille.get(etat) );

        */
        m_style = style;
        m_police = style->txt_police.get(etat);

        m_texteSFML->setColor           ( style->txt_couleur.get(etat) );
        m_texteSFML->setStyle           ( style->txt_style.get(etat) );
        m_texteSFML->setFont            ( style->txt_police.get(etat) );
//        if ( m_texteTaille != 0 )
//            m_texteSFML->setCharacterSize   ( m_texteTaille );
//        else
        m_texteSFML->setCharacterSize   ( style->txt_taille.get(etat) );

        m_texteSFML->setFont    ( m_police );
        m_texteSFML->setString  ( m_texte );
}



/////////////////////////////////////////////////
void AffLabel::actualiser ()
{
    m_texteSFML = std::make_shared<sf::Text> ();

    if( m_style != nullptr)
    {
        m_police = m_style->txt_police.get(Etat::repos);
        m_texteSFML->setColor           ( m_style->txt_couleur.get(Etat::repos) );
        m_texteSFML->setStyle           ( m_style->txt_style.get(Etat::repos) );
        m_texteSFML->setFont            ( m_style->txt_police.get(Etat::repos) );
//        if ( m_texteTaille != 0 )
//            m_texteSFML->setCharacterSize   ( m_texteTaille );
//        else
            m_texteSFML->setCharacterSize   ( m_style->txt_taille.get(Etat::repos) );

    }
/*
    //m_texteTaille

    // On choisi le style
    std::shared_ptr<Style> style = nullptr;

    if ( m_style != nullptr )
    {
//        std::cout << "style Style\n";
//        std::cout << " ->Style 1\n";
        style = m_style;
//        if ( m_texteTaille != 0 )
//            style->txt_taille  = m_texteTaille;




    } else {
//        std::cout << "style Skin\n";
//        std::cout << " ->Style 2\n";
        style = m_skin->txtCourant;

//        if ( m_texteTaille != 0 )
//            style->txt_taille  = m_texteTaille;
    }
    */
    /*else {
        // par defaut
        std::cout << "style DEFAUT\n";
        style = std::make_shared<Style>();
        style->txt_police.loadFromFile           ( "media/polices/consola.ttf" );
        style->txt_couleur =  sf::Color ( 250 , 250 , 250 , 150 ) ;
        style->txt_taille  = 10;
//        if ( m_texteTaille == 0 )
//            style->txt_taille  = 10;
//        else
//            style->txt_taille  = m_texteTaille;
    }*/

//    style->txt_taille  = m_texteTaille;

    // on l'applique
/*
    m_texteSFML->setColor           ( style->txt_couleur.repos );
    m_texteSFML->setStyle           ( style->txt_style.repos );

    if ( m_texteTaille != 0 )
        m_texteSFML->setCharacterSize   ( m_texteTaille );
    else
        m_texteSFML->setCharacterSize   ( style->txt_taille.repos );

*/
    m_texteSFML->setFont    ( m_police );
    m_texteSFML->setString  ( m_texte );
}

/////////////////////////////////////////////////
sf::Vector2i  AffLabel::getTaille() const
{
    return { m_texteSFML->getGlobalBounds().width , m_texteSFML->getGlobalBounds().height};
}




/////////////////////////////////////////////////
void AffLabel::draw (sf::RenderTarget& target, sf::RenderStates states) const
{
//    std::cout << "DEssiner LABEL : " << m_texte << "\n";

    //On applique la transformation
    states.transform *= getTransform();

    // On dessine le texte
    target.draw( *m_texteSFML, states);
}


/////////////////////////////////////////////////
void AffLabel::setPoliceFichier (sf::Font police)
{

}


} // fin namespace gui

