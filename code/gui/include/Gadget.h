#ifndef GADGET__H
#define GADGET__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "SFML/Graphics.hpp"
#include <memory>
#include <Geometrie.h>
#include <Skin.h>
#include <ActionClavier.h>
#include <Enums.h>
/*
#include <ActionSouris.h>*/


namespace gui {


/////////////////////////////////////////////////
/// \brief Classe communes � tout les gadgets, g�re affichage actualisation, etc...
///
/////////////////////////////////////////////////
class Gadget : public std::enable_shared_from_this<Gadget>, public sf::Drawable, public gui::Geometrie, public ActionClavier  {


/////////////////////////////////////////////////
// Enums & typedefs
/////////////////////////////////////////////////
    typedef std::shared_ptr<Gadget> ptr;    ///< Pointeur vers un gadget.


/////////////////////////////////////////////////
// M�thodes
/////////////////////////////////////////////////
public:
    ///< Definir m_visible
    void setVisible( bool val )
        { m_visible = val; };

    ///< Definir m_actif
    void setActif( bool val )
        { m_actif = val; };

    ///< Definir m_focus
    void setFocus( bool val )
        { m_focus = val; actualiser(); };

    ///< Definir m_survol
    void setSurvol( bool val )
        { m_survol = val; actualiser(); };

    ///< Definir m_presse
    void setPresse( bool val )
        { m_presse = val; actualiser(); };

    ///< Definir m_deplacable
    void setDeplacable( bool val )
        { m_deplacable = val; };

    ///< Definir m_skin
    void setSkin( std::shared_ptr<Skin> val )
        { m_skin = val; actualiser ();};

    ///< Acceder � m_skin
    std::shared_ptr<Skin> getSkin () const
        { return m_skin; };


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
    /// \brief Constructeur de recopie (=delete pour empecher la copie).
    ///
    /// \param original		 Le gadget a recopier.
    /////////////////////////////////////////////////
    Gadget (Gadget & original)= delete;

    /////////////////////////////////////////////////
    /// \brief Surcharge de l'operateur =(=delete pour empecher la copie).
    ///
    /// \param original
    /////////////////////////////////////////////////
    Gadget& operator= (Gadget & original)= delete;

    /////////////////////////////////////////////////
    /// \brief Actualiser les g�om�trie du gadgets, et donc ses bounds.
    ///
    /////////////////////////////////////////////////
    virtual void actualiser ();

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
    virtual void traiterEvenements (const sf::Event& evenement);


    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const{};


    /////////////////////////////////////////////////
    /// \brief D�clencher un �venement souris (les �venement claviers sont g�rer.
    ///
    /// \param evenement
    /////////////////////////////////////////////////
    virtual void declencher ( Evenement evenement ){};

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
    /// \brief Le gadget est-il survol� (m_survol)?
    ///
    /////////////////////////////////////////////////
    bool estSurvole () const;

    /////////////////////////////////////////////////
    /// \brief Le gadget est-il press� (m_presse)?
    ///
    /////////////////////////////////////////////////
    bool estPresse () const;

    /////////////////////////////////////////////////
    /// \brief Le gadget est-il d�placable (m_deplacable)?
    ///
    /////////////////////////////////////////////////
    bool estDeplacable () const;


    static Gadget*     getRacineCourante() { return ms_racineCourante; };

/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
protected:
    static  Gadget*      ms_racineCourante;    ///< L'interface courante dans laquelle on cr�� les gadgets.

private:
    bool m_visible;     ///< La visibilit� du gadget ( true: visible, false: invisible )
    bool m_actif;       ///< L'activit� du gadget ( true: actif, false: inactif )
    bool m_focus;       ///< Le focus du gadget ( true: � le focus, false: sans le focus )
    bool m_survol;      ///< Le survol par la souris (true si le gadget est survol� par la souris).
    bool m_presse;      ///< Le bouton gauche de la souris est press� (true si le gadget est survol� par la souris).
    bool m_deplacable;  ///< Si le gadget est d�placable (clique and drag)
protected:
    std::shared_ptr<Skin>   m_skin;    ///< Le skin, model pour les param�tres de rendu.

    friend class FabriqueBase;


}; // fin class Gadget

} // fin namespace gui

#endif
