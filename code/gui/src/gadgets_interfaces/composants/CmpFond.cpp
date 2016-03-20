#include "gadgets_interfaces/composants/CmpFond.h"



namespace gui {


/////////////////////////////////////////////////
CmpFond::CmpFond()
: m_fond   ( std::make_shared<AffRectangle>())
{

    // valeurs par defaut
    m_couleurFond.set       ( sf::Color( 0, 0, 0, 50 )  , Etat::desactive );
    m_couleurFond.set       ( sf::Color( 255,255,255, 50 )  , Etat::repos );
    m_couleurFond.set       ( sf::Color( 255,255,255, 100 ) , Etat::survol );
    m_couleurFond.set       ( sf::Color( 255,255,255, 150 ) , Etat::press );
    m_couleurLignes.set     ( sf::Color( 255,255,255, 100 ) );
    m_epaisseur.set         ( 0 );

}

/////////////////////////////////////////////////
void CmpFond::initialiserComposants ( Gadget*     base ){
    m_base = base ;
    m_base->ajouterComposant ( m_fond );
};


/////////////////////////////////////////////////
void CmpFond::setFondCouleur (sf::Color couleur , Etat etat ) {
    m_couleurFond.set ( couleur , etat );
    m_fond->setFondCouleur( couleur );

};


/////////////////////////////////////////////////
void CmpFond::setFondLigneCouleur (sf::Color couleur , Etat etat ) {
    m_couleurLignes.set ( couleur , etat );
    m_fond->setFondLigneCouleur( couleur );
};


/////////////////////////////////////////////////
void CmpFond::setFondLigneEpaisseur (float epaisseur , Etat etat ) {
    m_epaisseur.set ( epaisseur , etat );
    m_fond->setFondLigneEpaisseur( epaisseur );
};


/////////////////////////////////////////////////
void CmpFond::setFondCouleur ( Valeurs<sf::Color> couleurs  ) {
    m_couleurFond = couleurs;
//    demanderActuaStyle();
};


/////////////////////////////////////////////////
void CmpFond::setFondLigneCouleur ( Valeurs<sf::Color> couleurs  ) {
    m_couleurLignes = couleurs;
//    demanderActuaStyle();
};


/////////////////////////////////////////////////
void CmpFond::setFondLigneEpaisseur ( Valeurs<float> epaisseur ) {
    m_epaisseur =  epaisseur;
//    demanderActuaStyle();
};

/////////////////////////////////////////////////
void CmpFond::appliquerEtat( Etat etat ){

    m_fond->setFondCouleur    ( sf::Color (
                                      m_couleurFond.get( etat ).r
                                    , m_couleurFond.get( etat ).g
                                    , m_couleurFond.get( etat ).b
                                    , m_couleurFond.get( etat ).a * m_base->getOpacite() ) ) ;

    m_fond->setFondLigneCouleur     ( sf::Color (
                                      m_couleurLignes.get( etat ).r
                                    , m_couleurLignes.get( etat ).g
                                    , m_couleurLignes.get( etat ).b
                                    , m_couleurLignes.get( etat ).a * m_base->getOpacite() ) ) ;
    m_fond->setFondLigneEpaisseur ( m_epaisseur.get( etat ) ) ;
}



} // fin namespace gui
