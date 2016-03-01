#ifndef DNZONETEXTE__H
#define DNZONETEXTE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Donnee.h"
#include <memory>



namespace gui {

class BtnRectangle;
class AffLabel;


/////////////////////////////////////////////////
/// \brief Une zone pour entrer du texte.
///
/////////////////////////////////////////////////
class DnZoneTexte : public gui::Donnee {



/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////

public:
    ///< Definir m_ecritureActive
    void setEcritureActive( bool val ){ m_ecritureActive = val; };

    ///< Acceder à m_ecritureActive
    bool getEcritureActive () const { return m_ecritureActive; };

public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /////////////////////////////////////////////////
    DnZoneTexte ();

    virtual void actualiser ();

    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;



/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:
    std::shared_ptr<BtnRectangle> m_bouton;    
    std::shared_ptr<AffLabel> m_label;    
    bool m_ecritureActive;    ///< #G#S    

}; // fin class DnZoneTexte

} // fin namespace gui

#endif
