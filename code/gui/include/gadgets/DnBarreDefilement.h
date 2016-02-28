#ifndef DNBARREDEFILEMENT__H
#define DNBARREDEFILEMENT__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Donnee.h"
#include "DnSlider.h"
#include "BtnRectangle.h"
#include <memory>



namespace gui {



/////////////////////////////////////////////////
/// \brief Une barre de défilement pour gérer la position de l'interieur des conteneurs.
///
/////////////////////////////////////////////////
class DnBarreDefilement : public gui::Donnee<float> {



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

   // virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;

    void setLongueurCurseur( float pourcentage ) { m_slider->setLongCurseur( pourcentage ); actualiser(); };


/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:
    bool                            m_horizontal;    ///< #G#S
    std::shared_ptr<DnSlider>       m_slider;
    std::shared_ptr<BtnRectangle>   m_btnPlus;
    std::shared_ptr<BtnRectangle>   m_btnMoins;
/*
    std::shared_ptr<AffImage>       m_iconeHaut;
    std::shared_ptr<AffImage>       m_iconeBas;
    std::shared_ptr<AffImage>       m_iconedroite;
    std::shared_ptr<AffImage>       m_iconeGauche;*/

    float                           m_longeur;      ///<
    float                           m_largeur;      ///<

}; // fin class DnBarreDefilement

} // fin namespace gui

#endif
