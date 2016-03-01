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

class Skin;
class Gadget;


/////////////////////////////////////////////////
/// \brief Classe communes à tout les gadgets, gère affichage actualisation, etc...
///
/////////////////////////////////////////////////
class Gadget : public std::enable_shared_from_this, public sf::Drawable, public gui::Geometrie {


/////////////////////////////////////////////////
// Enums & typedefs
/////////////////////////////////////////////////
    typedef std::shared_ptr<Gadget> ptr;    ///< Pointeur vers un gadget.


/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////

public:
    ///< Definir m_visible
    void setVisible( bool val ){ m_visible = val; };

    ///< Definir m_actif
    void setActif( bool val ){ m_actif = val; };

    ///< Definir m_focus
    void setFocus( bool val ){ m_focus = val; };

    ///< Definir m_survol
    void setSurvol( bool val ){ m_survol = val; };

    ///< Definir m_presse
    void setPresse( bool val ){ m_presse = val; };

    ///< Definir m_deplacable
    void setDeplacable( bool val ){ m_deplacable = val; };

    ///< Definir m_skin
    void setSkin( std::shared_ptr<Skin> val ){ m_skin = val; };

    ///< Acceder à m_skin
    std::shared_ptr<Skin> getSkin () const { return m_skin; };

public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /////////////////////////////////////////////////
    Gadget ();

    /////////////////////////////////////////////////
    /// \brief Destructeur
    ///
    /////////////////////////////////////////////////
    virtual ~Gadget ();

    /////////////////////////////////////////////////
    /// \brief Constructeur de recopie (=delete pour empecher la copie).
    ///
    /// \param original		 Le gadget a recopier.
    /////////////////////////////////////////////////
    Gadget (Gadget & original);

    /////////////////////////////////////////////////
    /// \brief Surcharge de l'operateur =(=delete pour empecher la copie).
    ///
    /// \param original		 
    /////////////////////////////////////////////////
    Gadget& operator= (Gadget & original);

    /////////////////////////////////////////////////
    /// \brief Actualiser les géométrie du gadgets, et donc ses bounds.
    ///
    /////////////////////////////////////////////////
    virtual void actualiser ();

    /////////////////////////////////////////////////
    /// \brief Actualiser le gadget pour l'animation.
    ///
    /// \param deltaTemps		 Le temps écoulé depuis la dernière actualisation.
    /////////////////////////////////////////////////
    virtual void actualiser (sf::Time deltaTemps);

    /////////////////////////////////////////////////
    /// \brief  Traitement des évènements  du gadget.
    ///
    /// \param evenement		 L'evenemnt SFML à traiter.
    /////////////////////////////////////////////////
    virtual void traiterEvenements (const sf::Event& evenement);

protected:
    /////////////////////////////////////////////////
    /// \brief Le gadget est-il actif (m_actif)?
    ///
    /////////////////////////////////////////////////
    bool estActif () const;

    /////////////////////////////////////////////////
    /// \brief Le gadget est-il visible (m_visible)?
    ///
    /////////////////////////////////////////////////
    bool estVisible () const;

    /////////////////////////////////////////////////
    /// \brief Le gadget a-t-il le focus (m_focusf)?
    ///
    /////////////////////////////////////////////////
    bool aLeFocus () const;

    /////////////////////////////////////////////////
    /// \brief Le gadget est-il survolé (m_survol)?
    ///
    /////////////////////////////////////////////////
    bool estSurvole () const;

    /////////////////////////////////////////////////
    /// \brief Le gadget est-il pressé (m_presse)?
    ///
    /////////////////////////////////////////////////
    bool estPresse () const;

    /////////////////////////////////////////////////
    /// \brief Le gadget est-il déplacable (m_deplacable)?
    ///
    /////////////////////////////////////////////////
    bool estDeplacable () const;



/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
public:
    bool m_visible;    ///< La visibilité du gadget ( true: visible, false: invisible )#S    
private:
    bool m_actif;    ///< L'activité du gadget ( true: actif, false: inactif )#S    
    bool m_focus;    ///< Le focus du gadget ( true: à le focus, false: sans le focus )#S    
    bool m_survol;    ///< Le survol par la souris (true si le gadget est survolé par la souris).#S    
    bool m_presse;    ///< Le bouton gauche de la souris est pressé (true si le gadget est survolé par la souris).#S    
    bool m_deplacable;    ///< Si le gadget est déplacable (clique and drag)#S    
    std::shared_ptr<Skin> m_skin;    ///< Le skin, model pour les paramètres de rendu.#S#G    

}; // fin class Gadget

} // fin namespace gui

#endif
