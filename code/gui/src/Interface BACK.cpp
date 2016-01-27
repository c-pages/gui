///////////////////////////////////////////////////
//// Headers
///////////////////////////////////////////////////
//#include <Gui.h>
//#include <ConteneurGui.h>
//#include <Gadget.h>
//
//#include <iostream>
//
//
//namespace gui {
//
//
///////////////////////////////////////////////////
//// Initialisation des statics
///////////////////////////////////////////////////
////Gui  Gui::m_instance;
//
///*
///////////////////////////////////////////////////
//std::shared_ptr<Gui> Gui::instance ()
//{
//
//}
//*/
//
///////////////////////////////////////////////////
//void Gui::actualiser ( sf::Time delta )
//{
//    std::cout << " Gui::actualiser\n";
////    m_conteneur->actualiser (delta);
//}
//
//
///////////////////////////////////////////////////
//void Gui::traiter_evenements (const sf::Event&  evenement)
//{
//    std::cout << " Gui::traiter_evenements\n";
//    Gadget::ptr boutonSurvolBack = m_btnSurvole;
//    m_btnSurvole = chercherSurvol ();
//
//
//
////    m_conteneur->traiter_evenements ( evenement );
//}
//
///*
///////////////////////////////////////////////////
//void Gui::draw (sf::RenderTarget& target, sf::RenderStates states) const
//{
//
//}
//*/
//
///////////////////////////////////////////////////
//Gui::Gui (  )
//: m_fenetreSFML ( 0 )
//, m_skin        ( 0 )
//, creer         ( FabriqueGadget ( this ) )
////, m_conteneur   ( std::shared_ptr<Gadget> ( new ConteneurGui () ) )
//{
//    std::cout << "Creation Gui ()\n";
//
//}
//
///////////////////////////////////////////////////
//Gui::Gui ( sf::RenderWindow* fenetreSFML )
//: m_fenetreSFML ( fenetreSFML )
//, m_skin ( 0 )
//, creer ( FabriqueGadget ( this ) )
////, m_conteneur (  Gadget::ptr ( new ConteneurGui () ) )
//{
//    std::cout << "Creation Gui ( sf::RenderWindow* fenetreSFML )\n";
////    m_conteneur =  Gadget::ptr ( new ConteneurGui () );
//
//}
//
///*
///////////////////////////////////////////////////
//Gui::Gui (const Gui& original)
//: m_fenetreSFML (  )
//, m_skin (  )
//{
//
//}*/
//
//
///////////////////////////////////////////////////
//Gui::~Gui ()
//{
//
//}
//
//
///////////////////////////////////////////////////
//Gadget::ptr Gui::chercherSurvol ()
//{
////    for
//}
//
///*
///////////////////////////////////////////////////
//void Gui::dessiner ( ) const
//{
//    // Dessiner le conteneur
//    m_fenetreSFML->draw( *m_conteneur );
//
//}*/
//
///////////////////////////////////////////////////
//void Gui::draw (sf::RenderTarget& target, sf::RenderStates states) const
//{
//    std::cout << " Gui::draw\n";
//
//    // On dessine chaques composants
//    //m_conteneur->draw ( target , states );
//
//}
//
//
//} // fin namespace gui
//



/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Interface.h>
//#include <ConteneurGui.h>
//#include <Gadget.h>

#include <iostream>


namespace gui {


/////////////////////////////////////////////////
//Gui::Gui (  )
////, m_conteneur   ( std::shared_ptr<Gadget> ( new ConteneurGui () ) )
//{
//    std::cout << "Creation Gui ()\n";
//
//}


///////////////////////////////////////////////////
//void Gui::draw (sf::RenderTarget& target, sf::RenderStates states) const
//{
//    std::cout << " Gui::draw\n";
//
//    // On dessine chaques composants
//    //m_conteneur->draw ( target , states );
//
//}


} // fin namespace gui

