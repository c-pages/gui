#ifndef DNSLIDER__H
#define DNSLIDER__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Donnee.h"



namespace gui {



/////////////////////////////////////////////////
/// \brief Un slider permet de controler une valeur numerique.
///
/////////////////////////////////////////////////
template <T Template>
class DnSlider : public gui::Donnee {



/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////

public:
    ///< Definir m_valeurMax
    void setValeurMax( T val ){ m_valeurMax = val; };

    ///< Acceder à m_valeurMax
    T getValeurMax () const { return m_valeurMax; };

    ///< Definir m_valeurMin
    void setValeurMin( T val ){ m_valeurMin = val; };

    ///< Acceder à m_valeurMin
    T getValeurMin () const { return m_valeurMin; };

public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /////////////////////////////////////////////////
    DnSlider ();

    void actualiser ();

    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;



/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:
    BtnRectangle m_boutonFond;    
    BtnRectangle m_slider;    
    T m_valeurMax;    ///< #G#S    
    T m_valeurMin;    ///< #G#S    

}; // fin class DnSlider

} // fin namespace gui

#endif
