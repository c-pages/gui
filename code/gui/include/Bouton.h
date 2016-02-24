#ifndef BOUTON__H
#define BOUTON__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "ActionSouris.h"
#include "Gadget.h"



namespace gui {



/////////////////////////////////////////////////
/// \brief Un simple bouton
///
/////////////////////////////////////////////////
class Bouton : /* public gui::Gadget,*/ public gui::ActionSouris {



/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////
public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /////////////////////////////////////////////////
    Bouton ();

    virtual std::shared_ptr<Gadget>  testerSurvol ( sf::Vector2i position );

    virtual void actualiser ( ){};

//    virtual void setTexte( std::string val ){ m_texte = val; actualiser(); };
//    std::string getTexte( ) const { return m_texte; };

    void setAutoAjuster (bool val ){ m_autoAjust = val; actualiser ();};

//    void setMarge ( sf::Vector2f marge ){ m_marge = marge;};

/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
protected:
//    sf::Vector2f                m_marge;            ///< La marge à laissé lors l'ajustement automatique du rectangle sur le texte.
//    std::string                 m_texte;            ///< Le texte du bouton
    bool                        m_autoAjust;        ///< Ajuste automatiquement la taille du bouton au texte (en tenant compte de la marge).

}; // fin class Bouton

} // fin namespace gui

#endif
