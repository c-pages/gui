#ifndef DNBOUTONFLECHE__H
#define DNBOUTONFLECHE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Donnee.h"
#include <memory>



namespace gui {

class DnZoneTexte;
class BtnRectangle;
class BtnRectangle;


/////////////////////////////////////////////////
/// \brief Un bouton à fleches + entrée clavier pour controler une valeur numerique.
///
/////////////////////////////////////////////////
class DnBoutonFleche : public gui::Donnee {



/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////

public:
    ///< Definir m_minimum
    void setMinimum( float val ){ m_minimum = val; };

    ///< Acceder à m_minimum
    float getMinimum () const { return m_minimum; };

    ///< Definir m_maximum
    void setMaximum( float val ){ m_maximum = val; };

    ///< Acceder à m_maximum
    float getMaximum () const { return m_maximum; };

    ///< Definir m_courant
    void setCourant( float val ){ m_courant = val; };

    ///< Acceder à m_courant
    float getCourant () const { return m_courant; };

public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /////////////////////////////////////////////////
    DnBoutonFleche ();

    virtual void actualiser ();

    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;



/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:
    std::shared_ptr<DnZoneTexte> m_zoneTexte;    
    std::shared_ptr<BtnRectangle> m_btnHaut;    
    std::shared_ptr<BtnRectangle> m_btnBas;    ///<      
    float m_minimum;    ///< #S#G    
    float m_maximum;    ///< #S#G    
    float m_courant;    ///< #G#S    

}; // fin class DnBoutonFleche

} // fin namespace gui

#endif
