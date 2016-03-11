#ifndef COMPOSITE__H
#define COMPOSITE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "SFML/Graphics.hpp"
#include <memory>
#include <vector>
#include <iostream>



namespace gui {

class Gadget;


/////////////////////////////////////////////////
/// \brief Gestion des enfants, parent (GOF4: composite)
///
/////////////////////////////////////////////////
class Composite {



/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////

public:
    ///< Definir m_parent
    void setParent( Gadget* val );

    ///< Acceder à m_parent
    Gadget* getParent () const { return m_parent; };

    virtual void actualiserContenu (){};


    virtual std::shared_ptr<Gadget> thisPtr(){
        std::cout << "DEMANDE DE thisPtr PROBLEMATIQUE\n";
//        return static_cast<std::shared_ptr<Gadget>> shared_from_this();
        return nullptr;
    };

public:
    /////////////////////////////////////////////////
    /// \brief Ajouter un gadget à la liste de gadgets enfant.
    ///
    /// \param enfant		 L'enfant à ajouter.
    /////////////////////////////////////////////////
    virtual void ajouter (std::shared_ptr<Gadget> enfant);

    virtual void ajouter ( std::shared_ptr<Gadget> gadget, sf::Vector2i positionEcran ){};

    /////////////////////////////////////////////////
    /// \brief Retirer un enfant de la liste des enfants de ce gadget sans le supprimer.
    ///
    /// \param enfant		 L'enfant à retirer de la liste des enfants.
    /// \return L'enfant supprimer des enfants.
    /////////////////////////////////////////////////
    virtual std::shared_ptr<Gadget> retirer (std::shared_ptr<Gadget> enfant);

    std::vector<std::shared_ptr<Gadget>>   getEnfants(){ return  m_enfants; } ;


    /////////////////////////////////////////////////
    /// \brief Demander au parent de nous supprimer.
    ///
    /////////////////////////////////////////////////
    virtual void demander_aEtre_supprimer ();

    void demanderASupprimer (std::shared_ptr<Gadget> gadget );

    virtual void actualiserEnfants();


    void actualiserListes ( );

    /////////////////////////////////////////////////
    /// \brief Supprimer un gadget.
    ///
    /// \param enfant		 L'enfant à supprimer.
    /////////////////////////////////////////////////
    virtual void supprimer (std::shared_ptr<Gadget> enfant);

    /////////////////////////////////////////////////
    /// \brief Demander au parent d'être mis au dessus des autres gadgets ( mouvements de la liste des enfants).
    ///
    /////////////////////////////////////////////////
    void demander_aEtre_auDessus ();

    /////////////////////////////////////////////////
    /// \brief Mettre au dessus des autres gadgets ( mouvements de la liste des enfants).
    ///
    /// \param gadget		 le pointeur vers le gadget à mettre au dessus des autres parmis m_enfants.
    /////////////////////////////////////////////////
    virtual void mettre_auDessus ( std::shared_ptr<Gadget> gadget);

    /////////////////////////////////////////////////
    /// \brief Dessiner les enfants du gadget.
    ///
    /// \param target
    /// \param states
    /////////////////////////////////////////////////
    virtual void dessinerEnfants (sf::RenderTarget& target, sf::RenderStates states) const ;

    std::shared_ptr<Gadget> testerSurvolEnfants (sf::Vector2i position);

    sf::IntRect  boundgingB_enfants();



/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
protected:
    std::vector<std::shared_ptr<Gadget>>    m_enfants;          ///< Les enfants du gadget.
    Gadget*                                 m_parent = nullptr; ///< Le gadget parent.

    std::vector<std::shared_ptr<Gadget>>    m_enfantsASupprimer;          ///< Les enfants du gadget.
}; // fin class Composite

} // fin namespace gui

#endif
