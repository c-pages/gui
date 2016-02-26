#ifndef BOUTON__H
#define BOUTON__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "ActionEvenement.h"
#include "Gadget.h"



namespace gui {



/////////////////////////////////////////////////
/// \brief Un simple bouton
///
/////////////////////////////////////////////////
class Bouton : /* public gui::Gadget,*/ public gui::ActionEvenement {



/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////
public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /////////////////////////////////////////////////
    Bouton ();
    ~Bouton ();

    virtual std::shared_ptr<Gadget>  testerSurvol ( sf::Vector2i position );

    virtual void actualiser ( ){};

//    virtual void setTexte( std::string val ){ m_texte = val; actualiser(); };
//    std::string getTexte( ) const { return m_texte; };

    void setAutoAjuster (bool val ){ m_autoAjust = val; actualiser ();};

//    void setMarge ( sf::Vector2f marge ){ m_marge = marge;};

//    static  std::vector<std::shared_ptr<Gadget>>  sGetBoutons(){ return ms_boutons ; };
    static  std::vector<Gadget*>  GetBoutons(){ return ms_boutons ; };


/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:
    friend class Interface;
    friend class FabriqueBase;
    static  std::vector<Gadget*>      ms_boutons;

protected:
    bool                    m_autoAjust;        ///< Ajuste automatiquement la taille du bouton au texte (en tenant compte de la marge).

}; // fin class Bouton

} // fin namespace gui

#endif
