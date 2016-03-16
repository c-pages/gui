/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Composant.h>
#include <Gadget.h>



namespace gui {

/////////////////////////////////////////////////
void Composant::traiterEvenementsComposants (const sf::Event& evenement)
{
    for ( auto composant : m_composants )
        composant->traiterEvenements ( evenement );
}


/////////////////////////////////////////////////
void Composant::ajouterComposant ( std::shared_ptr<Gadget> enfant )
{
    m_composants.push_back( enfant );
    enfant->setParent ( dynamic_cast<Gadget*>(this) );
}


/////////////////////////////////////////////////
void Composant::retirerComposant ( std::shared_ptr<Gadget> enfant )
{
    int i =0;
    for ( auto composant : m_composants )
    {
        if ( composant == enfant )
        {
            composant->setParent ( nullptr );
            m_composants.erase( m_composants.begin() + i );
            return;
        }
        i++;
    }
}


/////////////////////////////////////////////////
void Composant::mettre_composantAuDessus (std::shared_ptr<Gadget> gadget)
{

}

/////////////////////////////////////////////////
void Composant::actualiserComposants ()
{
//    static_cast<Gadget*>(this)->log ("actualiserComposants");
    for ( auto composant : m_composants )
        composant->actualiser();
}



/////////////////////////////////////////////////
std::shared_ptr<Gadget> Composant::testerSurvolComposants (sf::Vector2i position)
{

    for ( int i =0; i< m_composants.size(); i++ )
    {
        int index = m_composants.size() - (i+1);
//        int index = i;
        auto  composant = m_composants[ index ];

        auto testComposant = composant->testerSurvol( position );
        if ( testComposant != nullptr )
            return testComposant;
    }
    return nullptr;
}


/////////////////////////////////////////////////
void Composant::dessinerComposant (sf::RenderTarget& target, sf::RenderStates states) const
{
    for ( auto composant : m_composants )
        target.draw( *composant, states );
}


} // fin namespace gui

