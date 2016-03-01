#ifndef DNBARREDEFILEMENT__H
#define DNBARREDEFILEMENT__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Donnee.h"
#include "DnSlider.h"
#include "BtnIcone.h"
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

    void setHorizontal (  ){ m_horizontal = true;actualiser (); };

    void setVertical (  ){ m_horizontal = false; actualiser ();}

    ///< Acceder à m_horizontal
    bool getHorizontal () const { return m_horizontal; };

    virtual float getValeur(){ return m_slider->getValeur();};

public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /////////////////////////////////////////////////
    DnBarreDefilement ();

    virtual void actualiser ();

    void setLongueurCurseur( float pourcentage ) { m_slider->setLongCurseur( pourcentage ); actualiser(); };

        ///< Definir m_taille
    void setLongueur( float longueur ){
        m_longueur = longueur;
        actualiser();
    };

    void setLargeur( float largeur ){
        m_largeur = largeur;
        actualiser();
    };

/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:
    bool                            m_horizontal;    ///< #G#S
    std::shared_ptr<DnSlider>       m_slider;
    std::shared_ptr<BtnIcone>       m_btnPlus;
    std::shared_ptr<BtnIcone>       m_btnMoins;


    float                           m_longueur;      ///<
    float                           m_largeur;      ///<

}; // fin class DnBarreDefilement

} // fin namespace gui

#endif
