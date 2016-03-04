#ifndef DNZONETEXTE__H
#define DNZONETEXTE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Donnee.h"
#include "BtnRectangle.h"
#include "AffLabel.h"

#include <memory>



namespace gui {


/////////////////////////////////////////////////
/// \brief Une zone pour entrer du texte.
///
/// \todo Placer le curseur à l'endroit du clique
/// \todo Déplacer le curseur avec les fleches
/// \todo Séléctionner du texte
/// \todo copier-coller
/////////////////////////////////////////////////
class DnZoneTexte : public gui::Donnee<std::string> {



/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////

public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /////////////////////////////////////////////////
    DnZoneTexte ();

//    virtual void actualiser ();
    /////////////////////////////////////////////////
    virtual void actualiserGeometrie ();

    /////////////////////////////////////////////////
    virtual void actualiserStyle ();

    virtual void setTexte( std::string val ){
        m_valeur    = val;
        m_texte     = val;
        m_label->setTexte       ( m_texte ) ;
        actualiserGeometrie();
    };

    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;

    virtual std::shared_ptr<Gadget>  testerSurvol ( sf::Vector2i position );

    virtual void traiterEvenements(const sf::Event& evenement );

public:
    ///< Definir m_ecritureActive
    void setModeEcritureActif( bool val ) { m_ecritureActive = val; actualiser (); };

    ///< Acceder à m_ecritureActive
    bool modeEcritureActif () const { return m_ecritureActive;  };


/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:

    // les proprietés fonctionnelles
    bool                            m_ecritureActive;    ///<

    // les composants de l'interface du gadget
    std::shared_ptr<BtnRectangle>   m_bouton;
    std::shared_ptr<AffRectangle>   m_curseur;
    std::shared_ptr<AffLabel>       m_label;

    // Les actions pour le fonctionnement
    FctnAction                      fn_sortir ;
    FctnAction                      fn_valider ;

    // les proprietés graphiques


}; // fin class DnZoneTexte

} // fin namespace gui

#endif
