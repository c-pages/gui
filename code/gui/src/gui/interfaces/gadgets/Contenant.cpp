/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "interfaces/gadgets/Contenant.h"
#include "repartiteurs/RepartiteurGrille.h"
#include "repartiteurs/RepartiteurHorizontal.h"
#include "repartiteurs/RepartiteurVerticale.h"
#include "repartiteurs/RepartiteurLibre.h"


#include "gui.h"



namespace gui {

/////////////////////////////////////////////////
Contenant::Contenant ()
: m_affContenant ( std::make_shared<sf::RectangleShape>() )
, m_posContenant ( {0,0} )
, m_groupe ( std::make_shared<Groupe>() )
, m_repartiteur ( new RepartiteurLibre ( this ) )
{

    creerNomUnique("contenant");

    //debug
//    m_mute = false;

    auto tailleMaxCarteVideo = sf::Texture::getMaximumSize();
    int tailleMax = TAILLE_MASK;

    log ("getMaximumSize" , tailleMaxCarteVideo );

    if ( tailleMaxCarteVideo < TAILLE_MASK )
        m_renderTexture.create ( tailleMaxCarteVideo  , tailleMaxCarteVideo );
    else
        m_renderTexture.create ( tailleMax  , tailleMax );


    m_contenantCouleur      = sf::Color( 50,50,50, 255 );
    m_contenantLgnCouleur   = sf::Color( 255,255,255, 20 );
    m_contenantLgnepaisseur = 1;

    m_fndCouleur            = sf::Color( 80,80,80 );

    // Load the shader
//    if (!m_masqueShader.loadFromFile("media/shaders/clippingMask.vert" , sf::Shader::Vertex ))
////    if (!m_masqueShader.loadFromFile("media/shaders/clippingMask.vert" , "media/shaders/clippingMask.frag" ))
//    if (!m_masqueShader.loadFromFile("media/shaders/clippingMask.frag", sf::Shader::Fragment ))
////    if (!m_masqueShader.loadFromFile("media/shaders/flou.frag", sf::Shader::Fragment ))
//        logAlerte("ERREUR Chargement shader");
//    printf(" -------- : %i\n" ,  m_masqueShader.isAvailable() );
//


    ajouterComposant( m_groupe );

    // on active le Masque
    setMasqueActif();

//    m_affContenant->setTexture( &m_renderTexture.getTexture() );
}


/////////////////////////////////////////////////
void Contenant::actualiserMasque ( ) {

//    m_masqueShader.setParameter( "texture"      , sf::Shader::CurrentTexture );
//    m_masqueShader.setParameter( "aTexture"     , true );
//    m_masqueShader.setParameter( "clipPos"      , {getPosAbs().x , Interface::ms_fenetreSFML->getSize().y - getPosAbs().y });
//    m_masqueShader.setParameter( "clipTaille"   , {getTaille().x ,getTaille().y});

//    for ( auto enfant : m_enfants )
//        enfant->setShaderMasque ( m_masqueShader );

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
void Contenant::actualiserBounds ()
{

    setMasqueRect   ( getPosAbs().x
                    , Interface::ms_fenetreSFML->getSize().y - getPosAbs().y
                    , getTaille().x
                    , getTaille().y );

    Geometrie::actualiserBounds ();
}
/////////////////////////////////////////////////
void Contenant::actualiserContenu ()
{

    repartirEnfants();

//    // Render to texture des enfants
//    m_renderTexture.clear( m_fndCouleur );
//    for (auto enfant : m_groupe->getEnfants() )
//        m_renderTexture.draw( *enfant );
//    m_groupe->setPosition ( -m_posContenant.x , -m_posContenant.y );
//    m_renderTexture.display();
//
//
//     // on applique la texture
//    m_affContenant->setTexture( &m_renderTexture.getTexture() );
//    m_affContenant->setTextureRect( { m_posContenant.x
//                                    , m_posContenant.y
//                                    , m_affContenant->getSize().x
//                                    , m_affContenant->getSize().y });

    // on gère la maj des parents
//    if ( m_parent != nullptr ) m_parent->actualiserContenu();

};

/////////////////////////////////////////////////
void Contenant::actualiserGeometrie ()
{
//    std::cout << " CONTENANT::ACTUALISERGEOMETRIE \n";
//    log ("TAILLE", m_taille);
//    logAlerte ("par la");

//    m_affContenant->setSize( { m_taille.x , m_taille.y } );


    repartirEnfants ();

    demanderActuaBounds();

}

/////////////////////////////////////////////////
void Contenant::actualiserStyle ()
{

//    m_fond->setFondCouleur            ( m_fndCouleur );
//    m_fond->setFondLigneCouleur         ( m_fndLgnCouleur  );
//    m_fond->setFondLigneEpaisseur     ( m_fndLgnepaisseur  );

//    m_affContenant->setFillColor       ( m_contenantCouleur );
//    m_affContenant->setOutlineColor    ( m_contenantLgnCouleur );
//    m_affContenant->setOutlineThickness( m_contenantLgnepaisseur );

}



/////////////////////////////////////////////////
std::shared_ptr<Gadget>  Contenant::testerSurvol ( sf::Vector2i position )
{
    //Gadget::testerSurvol (  position );


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
            else return nullptr;
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

    m_groupe->ajouter ( enfant, index);

    enfant->setMasqueActif();

    demanderActualisation();

};

/////////////////////////////////////////////////
void Contenant::ajouter ( std::shared_ptr<Gadget> enfant )    {

    m_groupe->ajouter ( enfant );

    enfant->setMasqueActif();

    demanderActualisation();

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

//        m_masqueShader.setParameter( "aTexture", false );
        //
        states.shader    =  &m_masqueShader;
//        target.draw( *m_affContenant , states );

        target.draw( *m_groupe , states );

    }

}

} // fin namespace gui

