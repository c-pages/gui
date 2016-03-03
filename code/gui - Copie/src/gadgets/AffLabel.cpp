/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <AffLabel.h>



namespace gui {

/////////////////////////////////////////////////
AffLabel::AffLabel ()
: m_texteSFML   ( std::make_shared<sf::Text> () )
//, m_texteTaille ( 0 )
//, m_police      ( nullptr )
, m_police      (  )
{
    // police par defaut
    ///< \todo voir comment gerer une police par defaut RAII
    m_police.loadFromFile( "media/polices/arial.ttf");

    m_texteSFML->setFont    ( m_police );
    m_texte    = "Label";
    actualiser ();
}

/////////////////////////////////////////////////
void AffLabel::setStyle ( std::shared_ptr<Style> style , Etat etat ){
//Style::
//style->
/*
        // si pas d'état on choisi #REPOS
        if ( etat != Etat::tous )
            m_police = style->txt_police.get(etat);
        else     m_police = style->txt_police.get( Etat::repos );
        */

        Gadget::setStyle( style , etat );

        m_color         = style->txt_couleur.get(etat);
        m_style         = style->txt_style.get(etat);
        m_characterSize = style->txt_taille.get(etat);
        m_police        = style->txt_police.get(etat);

        demander_actualisation();

   //     m_style = style;

/*
        m_texteSFML->setColor           ( style->txt_couleur.get(etat) );
        m_texteSFML->setStyle           ( style->txt_style.get(etat) );
        m_texteSFML->setCharacterSize   ( style->txt_taille.get(etat) );
        m_texteSFML->setFont            ( m_police );*/

//        std::cout << " ----------- " << float (style->txt_taille.get(etat)  ) << "\n";

//        actualiser();
}

/*
/////////////////////////////////////////////////
void AffLabel::actualiser_bounds ()
{

    sf::Vector2f pos = getPosAbs ();

    m_globalBounds.left     = pos.x;
    m_globalBounds.top      = pos.y;
    m_globalBounds.width    = getTaille().x;
    m_globalBounds.height   = getTaille().y;

    m_localBounds.left      = getPosition().x;
    m_localBounds.top       = getPosition().y;
    m_localBounds.width     = getTaille().x;
    m_localBounds.height    = getTaille().y;

}
*/

/////////////////////////////////////////////////
void AffLabel::actualiser_geometrie ()
{
    m_texteSFML->setString  ( m_texte );
}

/////////////////////////////////////////////////
void AffLabel::actualiser_style ()
{
    m_texteSFML->setColor           ( m_color );
    m_texteSFML->setStyle           ( m_style );
    m_texteSFML->setCharacterSize   ( m_characterSize );
    m_texteSFML->setFont            ( m_police );
}
/*
/////////////////////////////////////////////////
void AffLabel::actualiser ()
{
    if ( ! m_necessiteActualisation )
        return;

    m_texteSFML->setString  ( m_texte );

    auto style = m_skin->getStyle ( Styles::defaut );
    if( m_style !=  nullptr )
        style = m_style;

    m_police = style->txt_police.get(Etat::repos);
    m_texteSFML->setColor           ( style->txt_couleur.get(Etat::repos) );
    m_texteSFML->setStyle           ( style->txt_style.get(Etat::repos) );
    m_texteSFML->setFont            ( style->txt_police.get(Etat::repos) );
    m_texteSFML->setCharacterSize   ( style->txt_taille.get(Etat::repos) );
    m_texteSFML->setFont    ( m_police );


    //m_texteSFML->getGlobalBounds().width , m_texteSFML->getGlobalBounds().height

//    m_texteSFML = std::make_shared<sf::Text> ();

//    if( m_style != nullptr)
//    {
//        m_police = m_style->txt_police.get(Etat::repos);
//        m_texteSFML->setColor           ( m_style->txt_couleur.get(Etat::repos) );
//        m_texteSFML->setStyle           ( m_style->txt_style.get(Etat::repos) );
//        m_texteSFML->setFont            ( m_style->txt_police.get(Etat::repos) );
//
//        m_texteSFML->setCharacterSize   ( m_style->txt_taille.get(Etat::repos) );
//
//    }
//
//    m_texteSFML->setFont    ( m_police );
    m_necessiteActualisation = false;
}
*/
/////////////////////////////////////////////////
sf::Vector2i  AffLabel::getTaille() const
{
    return { m_texteSFML->getGlobalBounds().width , m_texteSFML->getGlobalBounds().height };
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

