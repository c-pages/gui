#ifndef GADGET__H
#define GADGET__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Cliquable.h"
#include "Transformable.h"
#include "Interaction.h"
#include <memory>
#include <SFML/Graphics.hpp>


namespace gui {

class Theme;
class InfoBulle;
class MenuContextuel;
class Conteneur;
class GadgetRendu;

/////////////////////////////////////////////////
/// \brief Classe de base de tout les gadgets.
///
/////////////////////////////////////////////////
class Gadget : public gui::Cliquable, public std::enable_shared_from_this<Gadget>, public sf::Drawable, public gui::Transformable, public gui::Interaction {


/////////////////////////////////////////////////
// Enums & typedefs
/////////////////////////////////////////////////
public:
    typedef std::shared_ptr<Gadget> ptr;    ///< Pointeur vers un gadget.


/////////////////////////////////////////////////
// M�thodes
/////////////////////////////////////////////////

public:
    ///< Definir m_focused
    void setFocused( bool val ){ m_focused = val; };

    ///< Acceder � m_focused
    bool getFocused () const { return m_focused; };

    ///< Definir m_visible
    void setVisible( bool val ){ m_visible = val; };

    ///< Acceder � m_visible
    bool getVisible () const { return m_visible; };

    ///< Definir m_actif
    void setActif( bool val ){ m_actif = val; };

    ///< Acceder � m_actif
    bool getActif () const { return m_actif; };

    ///< Definir m_draggable
    void setDraggable( bool val ){ m_draggable = val; };

    ///< Acceder � m_draggable
    bool getDraggable () const { return m_draggable; };

    ///< Definir m_survol
    void setSurvol( bool val ){ m_survol = val; };

    ///< Acceder � m_survol
    bool getSurvol () const { return m_survol; };

    ///< Definir m_presse
    void setPresse( bool val ){ m_presse = val; };

    ///< Acceder � m_presse
    bool getPresse () const { return m_presse; };

    ///< Definir m_theme
    void setTheme( std::shared_ptr<Theme> val ){ m_theme = val; };

    ///< Acceder � m_theme
    std::shared_ptr<Theme> getTheme () const { return m_theme; };

    ///< Definir m_infoBulle
    void setInfoBulle( std::shared_ptr<InfoBulle> val ){ m_infoBulle = val; };

    ///< Acceder � m_infoBulle
    std::shared_ptr<InfoBulle> getInfoBulle () const { return m_infoBulle; };

    ///< Definir m_menuContextuel
    void setMenuContextuel( std::shared_ptr<MenuContextuel> val ){ m_menuContextuel = val; };

    ///< Acceder � m_menuContextuel
    std::shared_ptr<MenuContextuel> getMenuContextuel () const { return m_menuContextuel; };

    ///< Definir m_parent
    void setParent( std::shared_ptr<Conteneur> val ){ m_parent = val; };

    ///< Acceder � m_parent
    std::shared_ptr<Conteneur> getParent () const { return m_parent; };

    ///< Definir m_gadgetRendu
    void setGadgetRendu( std::shared_ptr<GadgetRendu> val ){ m_gadgetRendu = val; };

    ///< Acceder � m_gadgetRendu
    std::shared_ptr<GadgetRendu> getGadgetRendu () const { return m_gadgetRendu; };

public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par d�faut.
    ///
    /////////////////////////////////////////////////
    Gadget ();

    /////////////////////////////////////////////////
    /// \brief Constructeur par copie.
    ///
    /// \param copy		 le gadget � copier.
    /////////////////////////////////////////////////
    Gadget (const Gadget& copy);

    /////////////////////////////////////////////////
    /// \brief Surcharge de l'operation d'�galit�.
    ///
    /// \param gadgetACopier		 Le gadget � copier.
    /////////////////////////////////////////////////
    Gadget& operator= (const Gadget& gadgetACopier);

    /////////////////////////////////////////////////
    /// \brief Demande au parent � �tre supprimer.
    ///
    /////////////////////////////////////////////////
    void supprimer ();

    /////////////////////////////////////////////////
    /// \brief Demande au conteneur parent � placer le gadget qu dessus de ses fr�res.
    ///
    /////////////////////////////////////////////////
    void mettreAuDessus ();

    /////////////////////////////////////////////////
    /// \brief Demander l'affichage de l'infobulle du gadget (s'il en a).
    ///
    /////////////////////////////////////////////////
    void demander_infoBulle ();

    /////////////////////////////////////////////////
    /// \brief Demander l'affichage du menu contextuel (s'il en a).
    ///
    /////////////////////////////////////////////////
    void demander_menuContextuel ();

    /////////////////////////////////////////////////
    /// \brief Actualise le gadget (pour animation).
    ///
    /// \param tempsEcoule
    /////////////////////////////////////////////////
    void actualiser (sf::Time tempsEcoule);

    /////////////////////////////////////////////////
    /// \brief Definir le texte de l'info-bulle � afficher.
    ///
    /// \param texte		 Le texte de  l'info bulle.
    /////////////////////////////////////////////////
    void setTexteInfoBulle (std::string texte);



/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
protected:
    bool m_focused;    ///< Si le gadget � le focus. #G#S
    bool m_visible;    ///< Si le gadget est visible ( false: invisible et inactif). #G#S
    bool m_actif;    ///< Si le gadget est actif.#G#S
    bool m_draggable;    ///< Si le gadget est d�placable par la souris.#G#S
    bool m_survol;    ///< Si la souris survol le gadget.#G#S
    bool m_presse;    ///< Si la souris � �t� press�e au dessus du gadget.#G#S
    std::shared_ptr<Theme> m_theme;    ///< Le th�me qui servira de model au gadget.#G#S
    std::shared_ptr<InfoBulle> m_infoBulle;    ///< L'info bulle � afficher en cas de survol prolong� de la souris.#G#S
    std::shared_ptr<MenuContextuel> m_menuContextuel;    ///< Le menu contextuel � afficher en cas de clique droit sur le gadget.#G#S
    std::shared_ptr<Conteneur> m_parent;    ///< Le conteneur dans lequel afficher le gadget.#G#S
    std::shared_ptr<GadgetRendu> m_gadgetRendu;    ///< La classe d'affichage du gadget.#G#S

}; // fin class Gadget

} // fin namespace gui

#endif
