/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Geometrie.h>
#include <Gadget.h>
#include <..\Patch.h>



namespace gui {

/////////////////////////////////////////////////
void Geometrie::setTaille( float x, float y ){
    setTaille( sf::Vector2i ( x, y ) );
};

/////////////////////////////////////////////////
void Geometrie::setTaille( sf::Vector2i val ){
    if ( m_taille == val ) return;

    log ("setTaille" );
    log ("m_taille" , val );

    if ( m_taille == val ) return;
    m_taille = val;
    static_cast<Gadget*>(this)->demanderActuaGeom();
};



/////////////////////////////////////////////////
void Geometrie::setTailleX( float val ){
    if ( m_taille.x == val ) return;

    if ( m_taille.x == val ) return;
    m_taille.x = val;
    static_cast<Gadget*>(this)->demanderActuaGeom();
};



/////////////////////////////////////////////////
void Geometrie::setTailleY( float val ){
    if ( m_taille.y == val ) return;

    if ( m_taille.y == val ) return;
    m_taille.y = val;
    static_cast<Gadget*>(this)->demanderActuaGeom();
};


/////////////////////////////////////////////////
void Geometrie::setPosAbs (sf::Vector2f posAbsDest ){

    sf::Vector2f posAbsParent = {0,0};
    if (m_parent != nullptr)
        posAbsParent = m_parent->getPosAbs();
    setPosition( posAbsDest.x -  posAbsParent.x , posAbsDest.y -  posAbsParent.y  ) ;
}

/////////////////////////////////////////////////
sf::Vector2f Geometrie::getPosAbs () const
{
    if ( m_parent != nullptr)
        return getPosition() + m_parent->getPosAbs();
    else
        return getPosition();
}


/////////////////////////////////////////////////
void Geometrie::setPosition( float x , float y ){
     sf::Transformable::setPosition( int ( x )  , int ( y ) );
     static_cast<Gadget*>(this)->demanderActuaBounds();
};

/////////////////////////////////////////////////
void Geometrie::setPosition( sf::Vector2f pos  ){
     sf::Transformable::setPosition( int ( pos.x )  , int ( pos.y ) );
     static_cast<Gadget*>(this)->demanderActuaBounds();
};

/////////////////////////////////////////////////
void Geometrie::AlignerSur ( std::shared_ptr<Gadget> cible, Alignement alignementThis, Alignement alignementCible)
{
    if ( cible == nullptr ) return;

//    actualiserBounds();
//    cible->actualiserBounds();

    log ("aligner sur", cible);

    sf::Vector2i pt_origine;
    sf::Vector2i pt_cible;
    sf::Vector2f pt_destination;

    // l'origine //////

    // la ligne vert. de gauche du gadget a bouger
    if ( alignementThis == Alignement::GaucheHaut
    ||   alignementThis == Alignement::Gauche
    ||   alignementThis == Alignement::GaucheBas )
        pt_origine.x = getPosAbs().x ;

    // la ligne vert. du milieu du gadget a bouger
    else if ( alignementThis == Alignement::Haut
         ||   alignementThis == Alignement::Centre
         ||   alignementThis == Alignement::Bas )
        pt_origine.x = getPosAbs().x + m_taille.x/2;

    // la ligne vert. de droite du gadget a bouger
    else
        pt_origine.x = getPosAbs().x  + m_taille.x;


    // la ligne horiz. du haut du gadget a bouger
    if ( alignementThis == Alignement::GaucheHaut
    ||   alignementThis == Alignement::Haut
    ||   alignementThis == Alignement::DroiteHaut )
        pt_origine.y = getPosAbs().y;

    // la ligne horiz. du milieu du gadget a bouger
    else if ( alignementThis == Alignement::Gauche
         ||   alignementThis == Alignement::Centre
         ||   alignementThis == Alignement::Droite )
        pt_origine.y = getPosAbs().y + m_taille.y/2;

    // la ligne horiz. du bas du gadget a bouger
    else
        pt_origine.y = getPosAbs().y + m_taille.y;





    // la destination //////

    // la ligne vert. de gauche du gadget a bouger
    if ( alignementThis == Alignement::GaucheHaut
    ||   alignementThis == Alignement::Gauche
    ||   alignementThis == Alignement::GaucheBas )
        pt_cible.x = cible->getPosAbs().x ;

    // la ligne vert. du milieu du gadget a bouger
    else if ( alignementThis == Alignement::Haut
         ||   alignementThis == Alignement::Centre
         ||   alignementThis == Alignement::Bas )
        pt_cible.x = cible->getPosAbs().x + cible->getTaille().x/2;

    // la ligne vert. de droite du gadget a bouger
    else
        pt_cible.x = cible->getPosAbs().x  + cible->getTaille().x;


    // la ligne horiz. du haut du gadget a bouger
    if ( alignementThis == Alignement::GaucheHaut
    ||   alignementThis == Alignement::Haut
    ||   alignementThis == Alignement::DroiteHaut )
        pt_cible.y = cible->getPosAbs().y;

    // la ligne horiz. du milieu du gadget a bouger
    else if ( alignementThis == Alignement::Gauche
         ||   alignementThis == Alignement::Centre
         ||   alignementThis == Alignement::Droite )
        pt_cible.y = cible->getPosAbs().y + cible->getTaille().y/2;

    // la ligne horiz. du bas du gadget a bouger
    else
        pt_cible.y = cible->getPosAbs().y + cible->getTaille().y;


    // et on deplace le gadget sur le point de destination
    pt_destination = { pt_cible.x - pt_origine.x ,  pt_cible.y - pt_origine.y };

    log ("getPosAbs()" , getPosAbs());
    log ("cible->getPosAbs()" , cible->getPosAbs());
    log ("pt_cible" , pt_cible);
    log ("pt_origine" , pt_origine);
    log ("pt_destination" , pt_destination);

    move ( pt_destination );

}


/////////////////////////////////////////////////
void Geometrie::actualiserBounds ()
{
    static_cast<Gadget*>(this)->log ( "ActualiserBounds  ");
    static_cast<Gadget*>(this)->log (  "taille" , getTaille() );

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



} // fin namespace gui

