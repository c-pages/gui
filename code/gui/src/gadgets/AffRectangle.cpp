/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <AffRectangle.h>
#include <Skin.h>



namespace gui {

/////////////////////////////////////////////////
AffRectangle::AffRectangle ( sf::Vector2i taille )
: m_rectangle()
{
    m_taille = taille;
    actualiser ();
}


/////////////////////////////////////////////////
void AffRectangle::actualiser ()
{
//    std::cout << "ACTUALISER AFFRECTANGLE_H\n";

    m_rectangle.setSize ( { m_taille.x, m_taille.y } );

    // On choisi le style adéquate ...

    std::shared_ptr<Style> style = nullptr;
    if ( m_style != nullptr )
        style = m_style;
    else
        style = m_skin->getStyle ( Skin::Styles::fond);

//        std::cout << " ->Style 1\n";
//        style = m_style;
    m_rectangle.setFillColor    ( sf::Color (
                                  style->fnd_couleur.repos.r
                                , style->fnd_couleur.repos.g
                                , style->fnd_couleur.repos.b
                                , style->fnd_couleur.repos.a * m_opacite ) ) ;

    m_rectangle.setOutlineColor ( sf::Color (
                                  style->lgn_couleur.repos.r
                                , style->lgn_couleur.repos.g
                                , style->lgn_couleur.repos.b
                                , style->lgn_couleur.repos.a * m_opacite ) ) ;

    m_rectangle.setOutlineThickness ( style->lgn_epaisseur.repos ) ;
        /*
    } else {
        m_rectangle.setFillColor    ( sf::Color (
                                      m_skin->fond->fnd_couleur.repos.r
                                    , m_skin->fond->fnd_couleur.repos.g
                                    , m_skin->fond->fnd_couleur.repos.b
                                    , m_skin->fond->fnd_couleur.repos.a * m_opacite ) ) ;

        m_rectangle.setOutlineColor ( sf::Color (
                                      m_skin->fond->lgn_couleur.repos.r
                                    , m_skin->fond->lgn_couleur.repos.g
                                    , m_skin->fond->lgn_couleur.repos.b
                                    , m_skin->fond->lgn_couleur.repos.a * m_opacite ) ) ;

        m_rectangle.setOutlineThickness ( m_skin->fond->lgn_epaisseur.repos ) ;





    }*/
//    else
//    {
////        std::cout << " ->Style 2\n";
//        style = m_skin->fond;
//
//    }
/*
    if ( m_style != nullptr )
    {
//        std::cout << " ->Style 1\n";
        style = m_style;
    }
    else
    {
//        std::cout << " ->Style 2\n";
        style = m_skin->fond;

    }*/
   /* else {
//        std::cout << " ->Style 3\n";
        // rectangle par defaut
        style = std::make_shared<Style>();

        style->fnd_couleur = sf::Color ( 255, 255,   0, 150 );
        style->lgn_couleur = sf::Color ( 255, 255, 255, 255 );
        style->lgn_epaisseur = 1;
//        std::cout << " -> " << int ( style->fnd_couleur.r ) << " " << int ( style->fnd_couleur.g) << " " << int ( style->fnd_couleur.b) << "\n" ;
    }*/

/*
    // ... et on l'applique
    m_rectangle.setFillColor        ( sf::Color (
                                      style->fnd_couleur.repos.r
                                    , style->fnd_couleur.repos.g
                                    , style->fnd_couleur.repos.b
                                    , style->fnd_couleur.repos.a * m_opacite ) ) ;

    m_rectangle.setOutlineColor     ( sf::Color (
                                      style->lgn_couleur.repos.r
                                    , style->lgn_couleur.repos.g
                                    , style->lgn_couleur.repos.b
                                    , style->lgn_couleur.repos.a * m_opacite ) ) ;

    m_rectangle.setOutlineThickness ( style->lgn_epaisseur.repos ) ;

*/

}

/////////////////////////////////////////////////
void AffRectangle::draw (sf::RenderTarget& target, sf::RenderStates states) const
{
    //On applique la transformation
    states.transform *= getTransform();

    // On dessine le rectangle
    target.draw(m_rectangle, states);
}




} // fin namespace gui

