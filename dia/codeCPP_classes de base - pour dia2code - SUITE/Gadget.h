#ifndef GADGET__H
#define GADGET__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "enable_shared_from_this.h"
#include "Drawable.h"
#include "Geometrie.h"
#include <memory>



namespace gui {

class Gadget;


/////////////////////////////////////////////////
/// \brief Classe communes � tout les gadgets, g�re affichage actualisation, etc...
///
/////////////////////////////////////////////////
class Gadget : public std::enable_shared_from_this, public sf::Drawable, public gui::Geometrie {


/////////////////////////////////////////////////
// Enums & typedefs
/////////////////////////////////////////////////
    typedef std::shared_ptr<Gadget> ptr;    ///< Pointeur vers un gadget.


/////////////////////////////////////////////////
// M�thodes
/////////////////////////////////////////////////

public:
    ///< Definir m_actif
    void setActif( bool val ){ m_actif = val; };

    ///< Acceder � m_actif
    bool getActif () const { return m_actif; };

    ///< Definir m_visible
    void setVisible( bool val ){ m_visible = val; };

    ///< Acceder � m_visible
    bool getVisible () const { return m_visible; };

    ///< Definir m_focus
    void setFocus( bool val ){ m_focus = val; };

    ///< Acceder � m_focus
    bool getFocus () const { return m_focus; };

    ///< Definir m_survol
    void setSurvol( bool val ){ m_survol = val; };

    ///< Acceder � m_survol
    bool getSurvol () const { return m_survol; };

    ///< Definir m_presse
    void setPresse( bool val ){ m_presse = val; };

    ///< Acceder � m_presse
    bool getPresse () const { return m_presse; };

    ///< Definir m_deplacable
    void setDeplacable( bool val ){ m_deplacable = val; };

    ///< Acceder � m_deplacable
    bool getDeplacable () const { return m_deplacable; };

public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par d�faut.
    ///
    /////////////////////////////////////////////////
    Gadget ();

    /////////////////////////////////////////////////
    /// \brief Destructeur
    ///
    /////////////////////////////////////////////////
    virtual ~Gadget ();

    /////////////////////////////////////////////////
    /// \brief Constructeur de recopie (pour gerer les pointeurs).
    ///
    /// \param original		 Le gadget a recopier.
    /////////////////////////////////////////////////
    Gadget (Gadget & original);

    /////////////////////////////////////////////////
    /// \brief Surcharge de l'operateur =.
    ///
    /// \param original		 
    /////////////////////////////////////////////////
    Gadget& operator= (Gadget & original);

    /////////////////////////////////////////////////
    /// \brief Actualiser le gadget pour l'animation.
    ///
    /// \param deltaTemps		 Le temps �coul� depuis la derni�re actualisation.
    /////////////////////////////////////////////////
    virtual void actualiser (sf::Time deltaTemps);

    /////////////////////////////////////////////////
    /// \brief  Traitement des �v�nements  du gadget.
    ///
    /// \param evenement		 L'evenemnt SFML � traiter.
    /////////////////////////////////////////////////
    virtual void traiter_events (const sf::Event& evenement);

private:
    /////////////////////////////////////////////////
    /// \brief Actualiser les g�om�trie du gadgets, et donc ses bounds.
    ///
    /////////////////////////////////////////////////
    virtual void actualiser ();



/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:
    bool m_actif;    ///< le gadget est il actif ? (#G#S)    
    bool m_visible;    ///< est il visible ? ( si non visible : inactif ?) (#G#S)    
    bool m_focus;    ///< Si le gadget � le focus. #G#S    
    bool m_survol;    ///< Si on survol le gadget.#G#S    
    bool m_presse;    ///< Si le gadget � �t� press�.#G#S    
    bool m_deplacable;    ///< Si le gadget est d�placable (clique and drag)#G#S    
    Gui friend class;    

}; // fin class Gadget

} // fin namespace gui

#endif
