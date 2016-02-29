#ifndef BTNICONE__H
#define BTNICONE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Bouton.h"
#include "gadgets\AffRectangle.h"
#include "gadgets\AffIcone.h"
#include <SFML/Graphics.hpp>



namespace gui {


/////////////////////////////////////////////////
/// \brief Un simple bouton rectangulaire
///
/////////////////////////////////////////////////
class BtnIcone : public gui::Bouton {



/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////
public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /////////////////////////////////////////////////
    BtnIcone ();


    void    setFix(bool val ){ m_fix = val; actualiser ();};

    void    setIconeIndex( unsigned int val )
    {
        std::cout << "BtnIcone::nom: " << getNom() <<  "\n";
        m_icone->setIndex( val );
        actualiser ();
    };

    virtual void actualiser ( );
/*
    virtual void setIndex( unsigned int val ){

    };*/

    void chargerDepuisFichier( std::string fichier )
    {
        m_icone->chargerDepuisFichier (fichier);
    };

////////////////////////////////// ///////////////
// Membres
/////////////////////////////////////////////////
public:
    std::shared_ptr<AffRectangle>   m_rectangle;
    std::shared_ptr<AffIcone>       m_icone;
//    unsigned int                    m_index;
    bool                            m_fix;

}; // fin class BtnIcone

} // fin namespace gui

#endif // BTNRECTANGLE__H
