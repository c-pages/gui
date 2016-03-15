#ifndef BTNICONE__H
#define BTNICONE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "BtnRectangle.h"
#include "gadgets\AffRectangle.h"
#include "gadgets\AffIcone.h"
#include <SFML/Graphics.hpp>



namespace gui {


/////////////////////////////////////////////////
/// \brief Un simple bouton rectangulaire
///
/////////////////////////////////////////////////
class BtnIcone : public gui::BtnRectangle {



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
//        std::cout << "BtnIcone::nom: " << getNom() <<  "\n";
        m_icone->setIndex( val );
        actualiser ();
    };

//    virtual void actualiser ( );
/*
    virtual void setIndex( unsigned int val ){

    };*/

    void setImage( std::string fichier )
    {
        m_icone->setImage (fichier);
    };

    void setImage ( sf::Texture* texture )
    {

        m_icone->setImage( texture );
    };

    /////////////////////////////////////////////////
    virtual void actualiserGeometrie ();

    /////////////////////////////////////////////////
    virtual void actualiserStyle ();

////////////////////////////////// ///////////////
// Membres
/////////////////////////////////////////////////
public:

    // les proprietés fonctionnelles
    bool                            m_fix;

    // les composants de l'interface du gadget
    std::shared_ptr<AffIcone>       m_icone;


}; // fin class BtnIcone

} // fin namespace gui

#endif // BTNRECTANGLE__H
