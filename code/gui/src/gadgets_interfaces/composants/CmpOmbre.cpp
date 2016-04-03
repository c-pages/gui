#include "gadgets_interfaces/composants/CmpOmbre.h"



namespace gui {


/////////////////////////////////////////////////
CmpOmbre::CmpOmbre()
: m_ombre       ( std::make_shared<AffRectangle>())
, m_ombreActive ( true )
{

    // valeurs par defaut
    m_couleurOmbre = sf::Color( 0, 0, 0, 50 )  ;

    m_ombre->setFondCouleur         ( m_couleurOmbre ) ;
    m_ombre->setFondLigneCouleur    ( sf::Color::Transparent ) ;
    m_ombre->setFondLigneEpaisseur  ( 0 ) ;

    m_ombre->setPosition (5,5);
}

/////////////////////////////////////////////////
void CmpOmbre::initialiserComposants ( Gadget*     base ){
    m_base = base ;
    m_base->ajouterComposant ( m_ombre );
};



/////////////////////////////////////////////////
void CmpOmbre::setOmbreCouleur ( sf::Color couleur ) {
    m_couleurOmbre= couleur ;
    m_ombre->setFondCouleur( couleur );
};


} // fin namespace gui
