#ifndef GUI__H
#define GUI__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
#include <memory>
#include "Gadget.h"



namespace gui {

class GUI;
class Skin;
class FabriqueGadget;


/////////////////////////////////////////////////
/// \brief Le gestionnaire d'interface (unique : GOF4 : singleton. Attention! : cette version du singleton peut poser probleme avec une utilisation des threads)).
///
/////////////////////////////////////////////////
class GUI {


/////////////////////////////////////////////////
// Enums & typedefs
/////////////////////////////////////////////////
    typedef std::shared_ptr<Gadget> ptr;    ///< Pointeur vers un gadget.


/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////

public:
public:
    /////////////////////////////////////////////////
    /// \brief Initialisation du gestionnaire d'interface (skin, polices, icones...)
    ///
    /////////////////////////////////////////////////
    void init ();

    void traiter_events (const sf::Event&  evenement);

    void draw (sf::RenderTarget& target, sf::RenderStates states) const;

    /////////////////////////////////////////////////
    /// \brief Si m_instance == null_ptr alors on créer m_instance. Puis on renvois. Permet la création à la demande! m_instance
    ///
    /////////////////////////////////////////////////
    std::shared_ptr<GUI> instance ();

private:
    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut en privé (Singleton).
    ///
    /// \param fenetreSFML		 la fenetre SFML dans laquelle on va utiliser l'interface
    /////////////////////////////////////////////////
    GUI (sf::RenderWindow fenetreSFML);

    /////////////////////////////////////////////////
    /// \brief Constructeur par copie  en privé (Singleton).
    ///
    /// \param original
    /////////////////////////////////////////////////
    GUI (const GUI& original);

    /////////////////////////////////////////////////
    /// \brief Destructeur par défaut privé (Singleton).
    ///
    /////////////////////////////////////////////////
    ~GUI ();

    /////////////////////////////////////////////////
    /// \brief Cherche quel gadget est sruvolé, nullptr si rien n'est survolé.
    ///
    /////////////////////////////////////////////////
    ptr chercherSurvol ();



/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
public:
    static GUI m_instance;    ///< L'instance static unique vers le GUI. (GOF4 : singleton.)
     m_gestRessources;    ///< Le gestionnaire des resources propres aux interfaces.
private:
    sf::renderWindow m_fenetreSFML;    ///< La fenêtre SFML dans laquelle on intègre l'interface.
    Skin m_skin;                ///< Le skin global à appliqué aux gadgets de l'interface.
    std::shared_ptr<gui::FabriqueGadget> ;     ///< Fonctions de creation des gadgets.

}; // fin class GUI

} // fin namespace gui

#endif
