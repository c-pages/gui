/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Gadget.h>

#include <iostream>


namespace gui {

/////////////////////////////////////////////////
Gadget::Gadget ()
: m_actif       ( true )
, m_visible     ( true )
, m_focus       ( false )
, m_survol      ( false )
, m_presse      ( false )
, m_deplacable  ( false )

, m_composants  ( std::vector<ptr> () )
, m_enfants     ( std::vector<ptr> () )
, m_parent      ( )


{
//    std::cout << "Creation du Gadget ()\n";

    // parametre par défaut.
    m_taille = { 43 , 52 };
   // actualiser( sf::seconds(0));
//    setPosition ( { 0 , 0 }) ;

}


//void Gadget::setTaille( sf::Vector2f val )
//{
//    m_taille = val;
//    actualiser_bounds ();
//    actualiser( sf::seconds( 0 ));
//}

/////////////////////////////////////////////////
Gadget::Gadget (Gadget & original)
: m_actif ( true )
, m_visible ( true )
, m_focus ( false )
, m_survol ( false )
, m_presse ( false )
, m_deplacable ( false )
{

}


/////////////////////////////////////////////////
Gadget& Gadget::operator= (Gadget & original)
{

}


/////////////////////////////////////////////////
void Gadget::initialiser ()
{

}

/////////////////////////////////////////////////
void Gadget::actualiser( sf::Time delta )
{

    std::cout << "Gadget::actualiser()\n";

    // On actualise les composants
    for (auto composant : m_composants )
        composant->actualiser ( delta );

    // On actualise les enfants
    for (auto enfant : m_enfants )
        enfant->actualiser ( delta );

}


/////////////////////////////////////////////////
void Gadget::dessinerEnfants (sf::RenderTarget& target, sf::RenderStates states) const
{
    // On applique la transformation du gadget.
    states.transform *= getTransform();

    // pour chaque enfants
    for (auto enfant : m_enfants )
        enfant->draw ( target , states );
}


/////////////////////////////////////////////////
void Gadget::demander_aEtre_supprimer ()
{

}


/////////////////////////////////////////////////
void Gadget::demander_aEtre_auDessus () const
{

}


/////////////////////////////////////////////////
void Gadget::mettre_auDessus (std::shared_ptr<Gadget> gadget)
{

}

/*
/////////////////////////////////////////////////
void Gadget::setParent( ptr  val )
{

    std::cout <<"Set parent!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
//
    m_parent = val;

    //m_parent->ajouterAEnfants ( thisPtr() );

    std::cout <<"   Set parent Fin\n";

}*/


void Gadget::draw (sf::RenderTarget& target, sf::RenderStates states) const
{

    // On applique la transformation du gadget.
    states.transform *= getTransform();

    //dessiner les composants
    dessinerComposants( target, states );

    //dessiner les enfants
    dessinerEnfants( target, states );

}

/////////////////////////////////////////////////
sf::Vector2f Gadget::getPosAbs () const
{

    sf::Vector2f position;

    if ( getParent() != nullptr ) {
        position = getPosition() + getParent()->getPosAbs();
//        std::cout << " Il a un parent -> " ;
    } else {
        position = getPosition();
//        std::cout << " Il a PAAAAAS de parent\n";
    }

//    std::cout << " position : " << position.x << " , " << position.y << "\n";

    return position;

}

void Gadget::traiter_evenements ( const sf::Event& evenement )
{
    // on gère les evenements claviers du gadget
    traiter_evenements_clavier ( evenement );

    // On diffuse le traitement des evenements aux enfants
    for ( auto enfant : m_enfants )
        enfant->traiter_evenements ( evenement );

}

/////////////////////////////////////////////////
void Gadget::dessinerComposants (sf::RenderTarget& target, sf::RenderStates states) const
{

    // On dessine chaques composants
    for ( auto composant : m_composants )
        composant->draw ( target , states );

}

/////////////////////////////////////////////////
void Gadget::Aligner (std::shared_ptr<Gadget> cible)
{

}


/////////////////////////////////////////////////
bool Gadget::testerSurvol (float x, float y) const
{

}


/////////////////////////////////////////////////
void Gadget::actualiser_bounds ()
{

    std::cout << "Gadget::actualiser_bounds() : ... \n";

    // les bounds en local
    m_localBounds.width     = m_taille.x;
    m_localBounds.height    = m_taille.y;
    m_localBounds.left      = getPosition().x;
    m_localBounds.top       = getPosition().y;

    // les bounds en Global
    m_globalBounds.width    = m_taille.x;
    m_globalBounds.height   = m_taille.y;
    m_globalBounds.left     = getPosAbs().x;
    m_globalBounds.top      = getPosAbs().y;

    std::cout << " Bounds  OK\n";
  //  std::cout << "m_globalBounds : " << m_globalBounds.width << " , " << m_globalBounds.height << " / " << m_globalBounds.left << " , " << m_globalBounds.top << "\n" ;

}

} // fin namespace gui

