/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "gadgets_interfaces/Contenant.h"
#include "repartiteurs/RepartiteurGrille.h"
#include "repartiteurs/RepartiteurHorizontal.h"
#include "repartiteurs/RepartiteurVerticale.h"
#include "repartiteurs/RepartiteurLibre.h"


#include "Interface.h"



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
    int tailleMax = 1080;

    log ("getMaximumSize" , tailleMaxCarteVideo );

    if ( tailleMaxCarteVideo < 1080 )
        m_renderTexture.create ( tailleMaxCarteVideo  , tailleMaxCarteVideo );
    else
        m_renderTexture.create ( tailleMax  , tailleMax );


    m_contenantCouleur      = sf::Color( 50,50,50, 255 );
    m_contenantLgnCouleur   = sf::Color( 255,255,255, 20 );
    m_contenantLgnepaisseur = 1;

    m_fndCouleur            = sf::Color( 80,80,80 );

    // Load the shader
//    if (!m_clipShader.loadFromFile("media/shaders/clippingMask.frag", sf::Shader::Fragment))
//        logAlerte("ERREUR Chargement shader");

//    m_clipShader.setParameter("texture", sf::Shader::CurrentTexture);

    ajouterComposant( m_groupe );


    m_affContenant->setTexture( &m_renderTexture.getTexture() );
}


/////////////////////////////////////////////////
void Contenant::replacerContenu () {

    m_affContenant->setSize( { m_taille.x , m_taille.y } );

    m_affContenant->setTextureRect( { 0
                                    , 0
                                    , m_affContenant->getSize().x
                                    , m_affContenant->getSize().y });


//    m_clipShader.setParameter("texture", sf::Shader::CurrentTexture);
//    m_clipShader.setParameter("clipPos", {getPosAbs().x , Interface::ms_fenetreSFML->getSize().y - getPosAbs().y });
//    m_clipShader.setParameter("clipTaille", {getTaille().x ,getTaille().y});

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
void Contenant::actualiserBounds ()
{
    replacerContenu ();
    Geometrie::actualiserBounds ();
}
/////////////////////////////////////////////////
void Contenant::actualiserContenu ()
{

    repartirEnfants();

    // Render to texture des enfants
    m_renderTexture.clear( m_fndCouleur );
    for (auto enfant : m_groupe->getEnfants() )
        m_renderTexture.draw( *enfant );
    m_groupe->setPosition ( -m_posContenant.x , -m_posContenant.y );
    m_renderTexture.display();


     // on applique la texture
    m_affContenant->setTexture( &m_renderTexture.getTexture() );
    m_affContenant->setTextureRect( { m_posContenant.x
                                    , m_posContenant.y
                                    , m_affContenant->getSize().x
                                    , m_affContenant->getSize().y });

    // on gère la maj des parents
    if ( m_parent != nullptr ) m_parent->actualiserContenu();

};

/////////////////////////////////////////////////
void Contenant::actualiserGeometrie ()
{
//    std::cout << " CONTENANT::ACTUALISERGEOMETRIE \n";
//    log ("TAILLE", m_taille);
//    logAlerte ("par la");

    m_affContenant->setSize( { m_taille.x , m_taille.y } );

    m_tailleContenant = m_taille;

    repartirEnfants ();

    demanderActuaBounds();

}

/////////////////////////////////////////////////
void Contenant::actualiserStyle ()
{

//    m_fond->setFondCouleur            ( m_fndCouleur );
//    m_fond->setFondLigneCouleur         ( m_fndLgnCouleur  );
//    m_fond->setFondLigneEpaisseur     ( m_fndLgnepaisseur  );

    m_affContenant->setFillColor       ( m_contenantCouleur );
    m_affContenant->setOutlineColor    ( m_contenantLgnCouleur );
    m_affContenant->setOutlineThickness( m_contenantLgnepaisseur );

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
//        states.shader    =  &m_clipShader;
        target.draw( *m_affContenant , states );

//        target.draw( *m_groupe , states );

    }

}

} // fin namespace gui

