#ifndef DNBARREDEFILEMENT__H
#define DNBARREDEFILEMENT__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Donnee.h"
#include <memory>



namespace gui {



/////////////////////////////////////////////////
/// \brief Une barre de défilement pour gérer la position de l'interieur des conteneurs.
///
/////////////////////////////////////////////////
class DnBarreDefilement : public gui::Donnee {



/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////

public:
    ///< Definir m_horizontal
    void setHorizontal( bool val ){ m_horizontal = val; };

    ///< Acceder à m_horizontal
    bool getHorizontal () const { return m_horizontal; };

public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /////////////////////////////////////////////////
    DnBarreDefilement ();

    virtual void actualiser ();

    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;



/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:
    bool m_horizontal;    ///< #G#S    
    std::shared_ptr<DnSlider> m_slider;    
    std::shared_ptr<BtnRectangle> m_btnPlus;    
    std::shared_ptr<BtnRectangle> m_btnMoins;    

}; // fin class DnBarreDefilement

} // fin namespace gui

#endif
