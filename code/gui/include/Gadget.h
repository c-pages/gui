#ifndef GADGET__H
#define GADGET__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
//#include "Composite.h"
#include "Interaction.h"
#include "Geometrie.h"

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include <iostream>



namespace gui {



/////////////////////////////////////////////////
/// \brief Classe communes � tout les gadgets, g�re affichage actualisation, etc...
///
/////////////////////////////////////////////////
class Gadget : public std::enable_shared_from_this<Gadget>, public sf::Drawable, public Interaction, public Geometrie {


/////////////////////////////////////////////////
// Enums & typedefs
/////////////////////////////////////////////////
public:
    typedef std::shared_ptr<Gadget> ptr;    ///< Pointeur vers un gadget.


/////////////////////////////////////////////////
// M�thodes
/////////////////////////////////////////////////

public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par d�faut.
    ///
    /////////////////////////////////////////////////
    Gadget ();

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
    /// \brief Initialise les interactions des composant du gadgets.
    ///
    /////////////////////////////////////////////////
    std::shared_ptr<Gadget> thisPtr (){ return  shared_from_this(); };


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
    ///< Definir m_texte
    virtual void setTexte( std::string val ){ m_texte = val; };

    ///< Acceder � m_texte
    virtual std::string getTexte () const { return m_texte; };

    ///< Definir m_taille
    virtual void setTaille ( sf::Vector2f val );

    //////////////////////////////
    // Composite    //////////////
    //////////////////////////////
    ///< Ajouter un �lement dans m_enfants
    void ajouterAEnfants (  ptr nouvelElement ){
        std::cout << "AJOUTER ENFANT\n";
        m_enfants.push_back( nouvelElement );
    };

    ///< retirer l'�lement � la position id dans m_enfants
    void retirerAEnfants ( int id ) { if ( id>=0 || id<m_enfants.size() ) m_enfants.erase( m_enfants.begin() + id ); };

    ///< Vider m_enfants
    void viderEnfants () { m_enfants.clear(); };

    ///< Accesseur � l'�l�ment de m_enfants d�sign� par un id.
    ptr getEnfants ( int id ) const { if ( id>=0 || id<m_enfants.size() )  return m_enfants.at( id ); else return 0; };

    std::vector<ptr>    getEnfants () { return m_enfants; } ;


    ///< Definir m_parent
    void setParent( ptr  val );

    ///< Acceder � m_parent
    ptr  getParent () const { return m_parent; };

    void dessinerEnfants (sf::RenderTarget& target, sf::RenderStates states) const;

// Composants

    ///< Ajouter un �lement dans m_composants
    void ajouterAComposants ( ptr nouvelElement ){ m_composants.push_back( nouvelElement ); };

    ///< retirer l'�lement � la position id dans m_composants
    void retirerAComposants ( int id ) { if ( id>=0 || id<m_composants.size() ) m_composants.erase( m_composants.begin() + id ); };

    ///< Vider m_composants
    void viderComposants () { m_composants.clear(); };

    ///< Accesseur � l'�l�ment de m_composants d�sign� par un id.
    ptr getComposants ( int id ) const { if ( id>=0 || id<m_composants.size() )  return m_composants.at( id ); else return 0; };

    void dessinerComposants (sf::RenderTarget& target, sf::RenderStates states) const;

protected:
    /////////////////////////////////////////////////
    /// \brief Demander au parent de nous supprimer.
    ///
    /////////////////////////////////////////////////
    void demander_aEtre_supprimer ();

    /////////////////////////////////////////////////
    /// \brief Demander au parent d'�tre mis au dessus des autres gadgets ( mouvements de la liste des enfants).
    ///
    /////////////////////////////////////////////////
    void demander_aEtre_auDessus () const;

    /////////////////////////////////////////////////
    /// \brief Mettre au dessus des autres gadgets ( mouvements de la liste des enfants).
    ///
    /// \param gadget		 le pointeur vers le gadget � mettre au dessus des autres parmis m_enfants.
    /////////////////////////////////////////////////
    void mettre_auDessus (std::shared_ptr<Gadget> gadget);


public:
    /////////////////////////////////////////////////
    /// \brief Initialiser les composants, les interactions (GOF4 : Patron de m�thode).
    ///
    /////////////////////////////////////////////////
    void initialiser ();

    /////////////////////////////////////////////////
    /// \brief Initialise les composant du gadgets.
    ///
    /////////////////////////////////////////////////
    virtual void initialiser_composants (){};

    /////////////////////////////////////////////////
    /// \brief Initialise les interactions des composant du gadgets.
    ///
    /////////////////////////////////////////////////
    virtual void initialiser_interactions (){};

    /////////////////////////////////////////////////
    /// \brief Actualiser les g�om�trie du gadgets avec skin, et donc ses bounds.
    ///
    /////////////////////////////////////////////////
    virtual void actualiser (sf::Time delta);

    /////////////////////////////////////////////////
    /// \brief  Traitement des �v�nements  du gadget.
    ///
    /// \param evenement		 L'evenemnt SFML � traiter.
    /////////////////////////////////////////////////
    virtual void traiter_evenements (const sf::Event& evenement){};

    /////////////////////////////////////////////////
    /// \brief Dessiner le gadget => dessiner ses enfants.
    ///
    /// \param target
    /// \param states
    /////////////////////////////////////////////////
    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;



/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
protected:
    bool m_actif;       ///< le gadget est il actif ?
    bool m_visible;     ///< est il visible ? ( si non visible : inactif ?)
    bool m_focus;       ///< Si le gadget � le focus.
    bool m_survol;      ///< Si on survol le gadget.
    bool m_presse;      ///< Si le gadget � �t� press�.
    bool m_deplacable;  ///< Si le gadget est d�placable (clique and drag)

    std::string         m_texte;

    std::vector<ptr>    m_composants;   ///< les differents gadgets qui composent ce gadget.
    std::vector<ptr>    m_enfants;      ///< Les enfants du gadget.
    ptr                 m_parent;       ///<

    friend class Gui ;
    friend class Geometrie ;




}; // fin class Gadget

} // fin namespace gui

#endif
