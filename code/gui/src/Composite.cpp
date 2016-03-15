/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Composite.h>
//#include <Contenant.h>

#include <Gadget.h>


namespace gui {

/////////////////////////////////////////////////
void Composite::ajouter (std::shared_ptr<Gadget> enfant)
{

    // si l'enfant avait un parent on le retire de sa liste des enfants
    auto parentBack = enfant->getParent();
    if ( parentBack != nullptr )
        parentBack->retirer ( enfant );

    m_enfants.push_back( enfant );

    auto _this = static_cast<Gadget*>( this );
    enfant->setParent ( _this );

    enfant->demanderActualisation();
    _this->demanderActualisation();

}


/////////////////////////////////////////////////
std::string Composite::getHierarchie() const {
    if (m_parent!=nullptr) {
        if ( m_parent->getNom()[0] == '_' )    {
            return ""  ;
        } else return m_parent->getHierarchie()  + m_parent->getNom() + "/"  ;
    } else return "";
};


/////////////////////////////////////////////////
std::string Composite::getCalqueNom()  {
    std::string nom = static_cast<Gadget*>(this)->getNom();
    if ( nom[0] == '_' )    {
        nom.erase(0, 1);
        return nom ;
    } else if (m_parent!=nullptr)
        return m_parent->getCalqueNom();
    else if ( nom =="GUI" )
        return "";
    else return "-";

};


/////////////////////////////////////////////////
void Composite::actualiserContenu (){
    // on demande juste au parent d'actualiser son contenu ...
    if ( m_parent != nullptr ) m_parent->actualiserContenu();
};

/////////////////////////////////////////////////
void Composite::replacerContenu () {

    // on demande juste au parent d'actualiser son contenu ...
    if ( m_parent != nullptr ) m_parent->replacerContenu();
}

/////////////////////////////////////////////////
void Composite::ajouter ( std::shared_ptr<Gadget> enfant, unsigned int index )    {

    // si l'enfant avait un parent on le retire de sa liste des enfants
    auto parentBack = enfant->getParent();
    if ( parentBack != nullptr )
        parentBack->retirer ( enfant );

    m_enfants.insert ( m_enfants.begin() + index, enfant );

    auto _this = static_cast<Gadget*>( this );
    enfant->setParent ( _this );

    enfant->actualiser();
    _this->actualiser();


//    std::cout <<"Composite::ajouter reussi\n";
};

/////////////////////////////////////////////////
void Composite::setParent( Gadget* val )
{
    m_parent = val;
//    m_parent->actualiser();
};


/////////////////////////////////////////////////
std::shared_ptr<Gadget> Composite::retirer ( std::shared_ptr<Gadget> gadget )
{
//    std::cout << "Composite::retirer\n";
    int i = 0;
    for ( auto enfant : m_enfants ){
        if ( enfant == gadget ) {
            m_enfants.erase( m_enfants.begin()+i );
            return enfant;
        }
        i++;
    }
    static_cast<Gadget*>(this)->actualiser();
}

/////////////////////////////////////////////////
void Composite::demander_aEtre_supprimer (){
    m_parent->demanderASupprimer ( thisPtr() );
}



/////////////////////////////////////////////////
std::shared_ptr<Gadget> Composite::testerSurvolEnfants ( sf::Vector2i position )
{
//    std::cout << "testerSurvolEnfants\n";
    for ( int i =0; i< m_enfants.size(); i++ )
    {
//        std::cout << "..." << i << " : " <<position.x <<", " << position.y <<  "\n";
        int index = m_enfants.size() - (i+1);
        auto  enfant = m_enfants[ index ];

        auto testEnfant = enfant->testerSurvol( position );
        if ( testEnfant != nullptr )
            return testEnfant;
    }
    return nullptr;
}
/////////////////////////////////////////////////
void Composite::demanderASupprimer (std::shared_ptr<Gadget> gadget ){

    m_enfantsASupprimer.push_back( gadget );
//
//    int i = 0;
//    int result = 0;
//    for ( auto enfant : m_enfants ){
//        if ( enfant == gadget ) {
//                result = i;
//        break;
////            m_enfants.erase( m_enfants.begin()+i );
//            //return;
//        }
//        i++;
//    }
//    m_enfants.erase( m_enfants.begin()+result );

}

/////////////////////////////////////////////////
void Composite::supprimer (std::shared_ptr<Gadget> gadget ){

    int i = 0;
    int result = 0;
    for ( auto enfant : m_enfants ){
        if ( enfant == gadget ) {
            result = i;
            break;
        }
        i++;
    }
    m_enfants.erase( m_enfants.begin()+result );

}

/////////////////////////////////////////////////
void Composite::actualiserListes ( ){

    if ( m_enfantsASupprimer.empty() ) return ;

    for ( auto enfant : m_enfantsASupprimer )
        supprimer ( enfant );
    m_enfantsASupprimer.clear();

    static_cast<Gadget*>(this)->actualiser();
}
/////////////////////////////////////////////////
sf::IntRect  Composite::boundgingB_enfants()
{
        sf::IntRect result;
        if ( m_enfants.size() == 0 )
            return result;

        int minX = 90000;
        int minY = 90000;
        int maxX = -90000;
        int maxY = -90000;

        for ( auto enfant : m_enfants )
        {
            sf::FloatRect LB = enfant->getLocalBounds();

            if (LB.left < minX) minX = LB.left;
            if (LB.top  < minY) minY = LB.top;
            if (LB.left + LB.width > maxX ) maxX = LB.left + LB.width;
            if (LB.top  + LB.height> maxY ) maxY = LB.top  + LB.height;

        }

        result.left     = minX;
        result.top      = minY;
        result.width    = maxX - minX;
        result.height   = maxY - minY;

        return result;
}

/////////////////////////////////////////////////
void Composite::actualiserEnfants ()
{
//    static_cast<Gadget*>(this)->log ("actualiserEnfants");

    for ( auto enfant : m_enfants )
        enfant->actualiser();
}


/////////////////////////////////////////////////
void Composite::dessinerEnfants (sf::RenderTarget& target, sf::RenderStates states) const
{

    for ( auto enfant : m_enfants )
        target.draw( *enfant , states);
}

/////////////////////////////////////////////////
void Composite::demander_aEtre_auDessus ()
{
    m_parent->mettre_auDessus ( thisPtr() );
}

/////////////////////////////////////////////////
void Composite::mettre_auDessus ( std::shared_ptr<Gadget> gadget )
{
//    std::cout << "Mettre au dessus\n";
    // on supprime le gadget de sa place dans le tableau
    int i = 0;
    int result = 0;
    for ( auto enfant : m_enfants ){
        if ( enfant == gadget ) {
            result = i;
            break;
        }
        i++;
    }
    m_enfants.erase( m_enfants.begin()+result );

    // puis on le replace � la fin du tableau
    m_enfants.push_back( gadget );

}



} // fin namespace gui



