#ifndef GUI__H
#define GUI__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <SFML/Graphics.hpp>

#include "Theme.h"
#include "Gadget.h"
#include "Conteneur.h"
#include "ConteneurGui.h"
#include "FabriqueGadgetBase.h"


namespace gui {

//class Gadget;
////class Theme;
//class Conteneur;
//class Gadget;


/////////////////////////////////////////////////
/// \brief La classe gérant la globalité de l'interface.
///
/////////////////////////////////////////////////
class Gui {



/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////

public:
    ///< Definir m_theme
    void setTheme( Theme::ptr val ){ m_theme = val; };

    ///< Acceder à m_theme
    Theme::ptr getTheme () const { return m_theme; };

    ///< Definir m_fenetre
    void setFenetre( sf::RenderTarget* val ){ m_fenetre = val; };

    ///< Acceder à m_fenetre
    sf::RenderTarget* getFenetre () const { return m_fenetre; };

    ///< Definir m_infoBulleVisible
    void setInfoBulleVisible( Gadget::ptr val ){ m_infoBulleVisible = val; };

    ///< Acceder à m_infoBulleVisible
    Gadget::ptr getInfoBulleVisible () const { return m_infoBulleVisible; };

public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /// \param fenetre		 La fentre SFML dans laquelle afficher l'interface.
    /////////////////////////////////////////////////
    Gui (sf::RenderTarget* fenetre);

    /////////////////////////////////////////////////
    /// \brief Actualiser les gadgets. (à integrer dans la boucle principale.)
    ///
    /////////////////////////////////////////////////
    void actualiser ();

    /////////////////////////////////////////////////
    /// \brief Dessiner toute  l'interface. (à integrer dans la boucle principale.)
    ///
    /// \param target
    /// \param states
    /////////////////////////////////////////////////
    void draw (sf::RenderTarget& target, sf::RenderStates states) const;

    /////////////////////////////////////////////////
    /// \brief Ajouter un gadget à la racine de l'interface.
    ///
    /// \param enfant		 Le gadget à ajouter à la racine de l'interface.
    /////////////////////////////////////////////////
    void ajouter (Gadget::ptr enfant);

    /////////////////////////////////////////////////
    /// \brief Retirer un gadget de la racine de l'interface.
    ///
    /// \param enfant		 Le gadget enfant à retirer de l'interface.
    /////////////////////////////////////////////////
    void retirer (Gadget::ptr enfant);

    /////////////////////////////////////////////////
    /// \brief Vider le Gui de tout ses gadgets.
    ///
    /////////////////////////////////////////////////
    void vider ();



/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:
    FabriqueGadgetBase creer;    ///< Pour creer les gadgets.
    Theme::ptr m_theme;    ///< Le thème gobal de l'interface.#G#S
    sf::RenderTarget* m_fenetre;    ///< La fenetre SFML oÃ¹ s'affiche l'interface. #G#S
    ConteneurGui::ptr m_conteneur;    ///< Le conteneur de tout les gadgets de l'interface.
    sf::Time m_tempsPourAfficherInfoBulle;    ///< Le temps avant de de mander l'infobule du gadget survolé.
    sf::Time m_tempsDoubleClique;    ///< Le temps de l'interval entre deux clique pour demander le double clique.
    Gadget::ptr m_infoBulleVisible;    ///< L'info bulle à afficher.#G#S

}; // fin class Gui

} // fin namespace gui

#endif
