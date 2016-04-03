/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "gadgets_interfaces/Contenant.h"
#include "repartiteurs/RepartiteurGrille.h"
#include "repartiteurs/RepartiteurHorizontal.h"
#include "repartiteurs/RepartiteurVerticale.h"
#include "repartiteurs/RepartiteurLibre.h"





namespace gui {

/////////////////////////////////////////////////
Contenant::Contenant ()
: m_affContenant ( std::make_shared<sf::RectangleShape>() )
, m_posContenant ( {0,0} )

, m_fond ( std::make_shared<AffRectangle>() )
, m_groupe ( std::make_shared<Groupe>() )
, m_repartiteur ( new RepartiteurLibre ( this ) )
{
    m_posContenant = {0,0};

    auto tailleMax = sf::Texture::getMaximumSize();
    if ( tailleMax < 1080 )
        m_renderTexture.create( 300  , tailleMax );
    else
        m_renderTexture.create( 300  , 1080 );

    m_fndCouleur            = sf::Color( 0,0,0, 50 );
    m_fndLgnCouleur         = sf::Color( 255,255,255, 20 );
    m_fndLgnepaisseur       = 1;

    m_contenantCouleur      = sf::Color( 255,255,255, 255 );
    m_contenantLgnCouleur   = sf::Color( 255,255,255, 20 );
    m_contenantLgnepaisseur = 1;

    ajouterComposant( m_fond );
    ajouterComposant( m_groupe );
}


/////////////////////////////////////////////////
void Contenant::replacerContenu () {

     m_affContenant->setTextureRect(   { 0
                                    , 0
                                    , m_affContenant->getSize().x
                                    , m_affContenant->getSize().y });

    if (m_parent != nullptr)
        m_parent->actualiserContenu();

}

/////////////////////////////////////////////////
void Contenant::setRepartition ( Repartitions repartition )
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
void Contenant::actualiserContenu ()
{

    repartirEnfants();

    // Render to texture des enfants
    m_renderTexture.clear( sf::Color::Transparent );
//    m_renderTexture.clear( sf::Color::Red );
    for (auto enfant : m_groupe->getEnfants() )
        m_renderTexture.draw( *enfant );

    m_groupe->setPosition ( -m_posContenant.x , -m_posContenant.y );

    m_renderTexture.display();
//    std::cout << " -> m_posContenant.x : " << m_posContenant.x << "     m_posContenant.y : " << m_posContenant.y << "\nm_contenant->getSize().x : " << m_contenant->getSize().x<< "   m_contenant->getSize().y : " << m_contenant->getSize().y << "\n";
    // on applique la texture
    m_affContenant->setTexture( &m_renderTexture.getTexture() );
    m_affContenant->setTextureRect( { m_posContenant.x
                                    , m_posContenant.y
                                    , m_affContenant->getSize().x
                                    , m_affContenant->getSize().y });

    if ( m_parent != nullptr ) m_parent->actualiserContenu();

};

/////////////////////////////////////////////////
void Contenant::actualiserGeometrie ()
{
//    std::cout << " Contenant::actualiserGeometrie \n";
    m_fond->setTaille(m_taille);
    m_affContenant->setSize( { m_taille.x , m_taille.y } );

    m_tailleContenant = m_taille;

    repartirEnfants ();

}

/////////////////////////////////////////////////
void Contenant::actualiserStyle ()
{

    m_fond->setFondCouleur            ( m_fndCouleur );
    m_fond->setFondLigneCouleur         ( m_fndLgnCouleur  );
    m_fond->setFondLigneEpaisseur     ( m_fndLgnepaisseur  );

    m_affContenant->setFillColor       ( m_contenantCouleur );
    m_affContenant->setOutlineColor    ( m_contenantLgnCouleur );
    m_affContenant->setOutlineThickness( m_contenantLgnepaisseur );

}



/////////////////////////////////////////////////
std::shared_ptr<Gadget>  Contenant::testerSurvol ( sf::Vector2i position )
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
            auto testEnfants = m_groupe->testerSurvolEnfants(  position);
            if ( testEnfants != nullptr )
                return testEnfants;
           else return thisPtr();
        }
    }
    else return nullptr;
}

/////////////////////////////////////////////////
void Contenant::ajouter ( std::shared_ptr<Gadget> enfant, unsigned int index )    {

    // si l'enfant avait un parent on le retire de sa liste des enfants
    auto parentBack = enfant->getParent();
    if ( parentBack != nullptr )
        parentBack->retirer ( enfant );

    //m_enfants.insert ( m_enfants.begin() + index, enfant );
    m_groupe->ajouter ( enfant, index);
    //enfant->setParent ( this );


//    repartirEnfants();
//    actualiserContenu();
    actualiser();

//    actualiserContenu();
    std::cout <<"Contenant::ajouter reussi\n";
};

/////////////////////////////////////////////////
void Contenant::ajouter ( std::shared_ptr<Gadget> enfant )    {
    //Filiation::ajouter( enfant );

    m_groupe->ajouter ( enfant );

//    repartirEnfants();
//    actualiserContenu();
    actualiser();
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
//    std::cout <<"Filiation::ajouter reussi\n";
};
/////////////////////////////////////////////////
sf::Vector2f    Contenant::deplMaxContenu(){

    sf::Vector2f result;

    float longueurContenu       = float( m_groupe->boundgingB_enfants().left + m_groupe->boundgingB_enfants().width ) + 0;  //+  m_slider_V->getTaille().x;
    float longueurContenant     = m_taille.x;
    float longueurDeplacement   = longueurContenu - longueurContenant;
//    std::cout << " longueurContenu : " << longueurContenu << " longueurContenant : " << longueurContenant << "\n";
    result.x =  longueurDeplacement;

    longueurContenu       = float( m_groupe->boundgingB_enfants().top + m_groupe->boundgingB_enfants().height ) + 0; // m_slider_H->getTaille().y;
    longueurContenant     = m_taille.y;
    longueurDeplacement   = longueurContenu - longueurContenant;
//    std::cout << " longueurContenu : " << longueurContenu << " longueurContenant : " << longueurContenant << "\n";

    result.y =  longueurDeplacement;
//    std::cout << " result : " << result.x << ", " << result.y << "\n";

    return result;

}


/////////////////////////////////////////////////
void Contenant::draw (sf::RenderTarget& target, sf::RenderStates states) const
{

    if ( estVisible() ) {

        //On applique la transformation
        states.transform *= getTransform();

        target.draw( *m_fond , states );
        target.draw( *m_affContenant , states );

    }

}

} // fin namespace gui
