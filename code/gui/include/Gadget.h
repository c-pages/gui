#ifndef GADGET__H
#define GADGET__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "SFML/Graphics.hpp"
#include <memory>
#include <Geometrie.h>
#include <Composant.h>
#include <Skin.h>
#include <ActionClavier.h>
#include <Enums.h>
//#include <Interface.h>
/*
#include <ActionEvenement.h>*/


namespace gui {

class Interface;

/////////////////////////////////////////////////
/// \brief Classe communes � tout les gadgets, g�re affichage actualisation, etc...
///
/////////////////////////////////////////////////
class Gadget : public std::enable_shared_from_this<Gadget>, public sf::Drawable, public gui::Geometrie, public Composant, public ActionClavier  {


/////////////////////////////////////////////////
// Enums & typedefs
/////////////////////////////////////////////////
    typedef std::shared_ptr<Gadget> ptr;    ///< Pointeur vers un gadget.


/////////////////////////////////////////////////
// M�thodes
/////////////////////////////////////////////////
public:

    virtual std::shared_ptr<Gadget> thisPtr()  {
//        std::cout << "DEMANDE DE THISPTR\n";
        return shared_from_this();
    };



    ///< Definir m_visible
    void setVisible( bool val )
        { m_visible = val; };

    ///< Definir m_actif
    void setActif( bool val )
        { m_actif = val;  actualiser();};

    ///< Definir m_focus
    void setFocus( bool val )
        { m_focus = val; actualiser(); };

    ///< Definir m_survol
    void setSurvol( bool val )
        { m_survol = val; actualiser(); };

    ///< Definir m_presse
    void setPresse( bool val )
        { m_presse = val;
        actualiser(); };

    ///< Definir m_deplacable
    void setDeplacable( bool val )
        { m_deplacable = val; };

    ///< Definir m_skin
    virtual void setSkin( std::shared_ptr<Skin> skin )
        { m_skin = skin;
        for ( auto composant : m_composants)
            composant->setSkin( skin );
            actualiser ();
        };

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


    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;


    /////////////////////////////////////////////////
    /// \brief D�clencher un �venement souris (les �venement claviers sont g�rer.
    ///
    /// \param evenement
    /////////////////////////////////////////////////
    virtual void declencher ( Evenement evenement ){};

public:
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

    sf::Vector2i getPosSouris ( );
    sf::Vector2i getLocalPosSouris ( );

    static Gadget*     getRacineCourante() { return ms_racineCourante; };

//    virtual     void setStyle ( std::shared_ptr<Style> style , Etat etat );

    virtual     void setStyle ( std::shared_ptr<Style> style , Etat etat = Etat::tous ){
        m_style = style;
        for ( auto composant : m_composants)
            composant->setStyle(style);
        actualiser();
        };

    std::shared_ptr<Style> getStyle ( )const { return m_style; };

    bool aDesEnfants () { return ( m_enfants.size() > 0 ); };

    virtual std::shared_ptr<Gadget>  testerSurvol ( sf::Vector2i position );

    std::string     getNom() const { return m_nom; };

    int getNombreGadgets () const { return ms_CompteurGadgets; };

    virtual void setTexte( std::string val ){ m_texte = val; actualiser(); };

    std::string getTexte( ) const { return m_texte; };

    void setMarge ( sf::Vector2f marge ){ m_marge = marge;};

protected:
    sf::Vector2f                m_marge;            ///< La marge � laiss�
/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
public:
    static  Gadget*     ms_racineCourante;    ///< L'interface courante dans laquelle on cr�� les gadgets.
private:
    static  int         ms_CompteurGadgets;   ///< L'interface courante dans laquelle on cr�� les gadgets.

protected:
    std::string         m_texte;            ///< Le texte du gadget.
protected:
    std::string         m_nom;      ///< Nom unique automatique pour le gadget.

    bool m_visible;     ///< La visibilit� du gadget ( true: visible, false: invisible )
    bool m_actif;       ///< L'activit� du gadget ( true: actif, false: inactif )
    bool m_focus;       ///< Le focus du gadget ( true: � le focus, false: sans le focus )
    bool m_survol;      ///< Le survol par la souris (true si le gadget est survol� par la souris).
    bool m_presse;      ///< Le bouton gauche de la souris est press� (true si le gadget est survol� par la souris).
    bool m_deplacable;  ///< Si le gadget est d�placable (clique and drag)
protected:
    std::shared_ptr<Skin>   m_skin;    ///< Le skin, model pour les param�tres de rendu.
    std::shared_ptr<Style>  m_style;

    friend class FabriqueBase;


}; // fin class Gadget

} // fin namespace gui

#endif
