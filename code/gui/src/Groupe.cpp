/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Groupe.h>
#include "repartiteurs/RepartiteurGrille.h"
#include "repartiteurs/RepartiteurHorizontal.h"
#include "repartiteurs/RepartiteurVerticale.h"
#include "repartiteurs/RepartiteurLibre.h"





namespace gui {

/////////////////////////////////////////////////
Groupe::Groupe ()
: m_contenant ( std::make_shared<sf::RectangleShape>() )
, m_posX_texture(0)
, m_posY_texture(0)
, m_fond ( std::make_shared<AffRectangle>() )
, m_repartiteur ( new RepartiteurLibre ( this ) )
{
    m_renderTexture.create( 1920, 1080 );

    m_fndCouleur            = sf::Color( 70,70,70, 255 );
    m_fndLgnCouleur         = sf::Color( 255,255,255, 20 );
    m_fndLgnepaisseur       = 1;

    m_contenantCouleur            = sf::Color( 255,255,255, 255 );
    m_contenantLgnCouleur         = sf::Color( 255,255,255, 20 );
    m_contenantLgnepaisseur       = 1;

    ajouterComposant( m_fond );
}

/////////////////////////////////////////////////
void Groupe::setRepartition ( Repartitions repartition )
{
//    std::cout << " SET REPART |-------------> "<< repartition << "\n";

    switch ( repartition ){
        case Repartitions::Grille:
            m_repartiteur.reset();
            m_repartiteur = std::unique_ptr<Repartiteur> ( new RepartiteurGrille ( this ) );
            break;
        case Repartitions::Horizontale:
            m_repartiteur.reset();
            m_repartiteur = std::unique_ptr<Repartiteur> ( new RepartiteurHorizontal ( this )  );
            break;
        case Repartitions::Libre:
            m_repartiteur.reset();
            m_repartiteur = std::unique_ptr<Repartiteur> ( new RepartiteurLibre ( this ) ) ;
            break;
        case Repartitions::Verticale:
            m_repartiteur.reset();
            m_repartiteur = std::unique_ptr<Repartiteur> ( new RepartiteurVerticale ( this )  );
            break;
    }
}


/////////////////////////////////////////////////
void Groupe::actualiserContenu ()
{
//    std::cout << "Groupe::actualiserContenu\n";
//    sf::Vector2i taille = { boundgingB_enfants().left + boundgingB_enfants().width , boundgingB_enfants().top + boundgingB_enfants().height };
//    m_renderTexture.create( taille.x, taille.y );
    // Render to texture des enfants
    m_renderTexture.clear( sf::Color::Transparent );
//    m_renderTexture.clear( sf::Color::Red );
    for (auto enfant : m_enfants)
        m_renderTexture.draw( *enfant );

    m_renderTexture.display();
//    std::cout << " -> m_posX_texture : " << m_posX_texture << "     m_posY_texture : " << m_posY_texture << "\nm_contenant->getSize().x : " << m_contenant->getSize().x<< "   m_contenant->getSize().y : " << m_contenant->getSize().y << "\n";
    // on applique la texture
    m_contenant->setTexture( &m_renderTexture.getTexture() );
    m_contenant->setTextureRect(    { m_posX_texture
                                    , m_posY_texture
                                    , m_contenant->getSize().x
                                    , m_contenant->getSize().y });

    if ( m_parent != nullptr ) m_parent->actualiserContenu();

};

/////////////////////////////////////////////////
void Groupe::actualiserGeometrie ()
{
//    std::cout << " BAHALORS \n";
    m_fond->setTaille(m_taille);
    m_contenant->setSize( { m_taille.x , m_taille.y } );

    m_posContenant = {0,0};
    m_tailleContenant = m_taille;

    repartirEnfants ();

    actualiserContenu();
    actualiserBounds ();
//    if ( m_parent != nullptr ) m_parent->actualiserContenu();

}

/////////////////////////////////////////////////
void Groupe::actualiserStyle ()
{

    m_fond->setFillColor            ( m_fndCouleur );
    m_fond->setOutlineColor         ( m_fndLgnCouleur  );
    m_fond->setOutlineThickness     ( m_fndLgnepaisseur  );

    m_contenant->setFillColor       ( m_contenantCouleur );
    m_contenant->setOutlineColor    ( m_contenantLgnCouleur );
    m_contenant->setOutlineThickness( m_contenantLgnepaisseur );

}



/////////////////////////////////////////////////
std::shared_ptr<Gadget>  Groupe::testerSurvol ( sf::Vector2i position )
{
    // si on est dans le panneau
    if ( m_globalBounds.contains( position.x, position.y ) && estActif() )
    {
        // si on survol un gadget composant (slider)
        auto testInterfaceLocal = testerSurvolComposants( position );
        if ( testInterfaceLocal != nullptr )
            // on le renvois
            return testInterfaceLocal;
        else {
            // sinon on regarde si on survol un enfant
            auto testEnfants = testerSurvolEnfants( { position.x + m_posX_texture, position.y + m_posY_texture } );
            if ( testEnfants != nullptr )
                return testEnfants;
           else return thisPtr();
        }
    }
    else return nullptr;
}

/////////////////////////////////////////////////
void Groupe::ajouter ( std::shared_ptr<Gadget> enfant, unsigned int index )    {

    // si l'enfant avait un parent on le retire de sa liste des enfants
    auto parentBack = enfant->getParent();
    if ( parentBack != nullptr )
        parentBack->retirer ( enfant );

    m_enfants.insert ( m_enfants.begin() + index, enfant );

    enfant->setParent ( this );

    repartirEnfants();

//    enfant->actualiser();

//    actualiserContenu();
    std::cout <<"Groupe::ajouter reussi\n";
};

/////////////////////////////////////////////////
void Groupe::ajouter ( std::shared_ptr<Gadget> enfant )    {
    Composite::ajouter( enfant );

    repartirEnfants();

//    // si l'enfant avait un parent on le retire de sa liste des enfants
//    auto parentBack = enfant->getParent();
//    if ( parentBack != nullptr )
//        parentBack->retirer ( enfant );
//
//    m_enfants.insert ( m_enfants.begin() + index, enfant );
//
//    auto _this = static_cast<Gadget*>( this );
//    enfant->setParent ( _this );
//
//    enfant->actualiser();
////    _this->actualiser();
//    _this->actualiserContenu();
//    std::cout <<"Composite::ajouter reussi\n";
};
/////////////////////////////////////////////////
sf::Vector2f    Groupe::deplMaxContenu(){

    sf::Vector2f result;

    float longueurContenu       = float( boundgingB_enfants().left + boundgingB_enfants().width ) + 25;  //+  m_slider_V->getTaille().x;
    float longueurContenant     = m_taille.x;
    float longueurDeplacement   = longueurContenu - longueurContenant;
//    std::cout << " longueurContenu : " << longueurContenu << " longueurContenant : " << longueurContenant << "\n";
    result.x =  longueurDeplacement;

    longueurContenu       = float( boundgingB_enfants().top + boundgingB_enfants().height ) + 25; // m_slider_H->getTaille().y;
    longueurContenant     = m_taille.y;
    longueurDeplacement   = longueurContenu - longueurContenant;
//    std::cout << " longueurContenu : " << longueurContenu << " longueurContenant : " << longueurContenant << "\n";

    result.y =  longueurDeplacement;
//    std::cout << " result : " << result.x << ", " << result.y << "\n";

    return result;

}



} // fin namespace gui

