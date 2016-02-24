#ifndef FABRIQUEBASE_H
#define FABRIQUEBASE_H

#include "SFML/Graphics.hpp"
#include "memory"


#include "Gadget.h"

// AFFICHAGES
#include "gadgets\AffRectangle.h"
#include "gadgets\AffLabel.h"
#include "gadgets\AffImage.h"

// BOUTONS
#include "gadgets\BtnRectangle.h"
#include "gadgets\BtnMenu.h"

// DONNEES
#include "gadgets\DnCaseACocher.h"


namespace gui{


/////////////////////////////////////////////////
/// \brief Fabrique de gadgets de base (cf. GOF: Fabrique)
///
/////////////////////////////////////////////////
class FabriqueBase
{

public:

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// AFFICHAGES
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /////////////////////////////////////////////////
    /// \brief  Cr�ation d'un simple rectangle
    ///
    /// \param ...
    /////////////////////////////////////////////////
    std::shared_ptr<AffRectangle>    rectangle( sf::Vector2i taille = {100,100} );

    /////////////////////////////////////////////////
    /// \brief  Cr�ation d'un simple label
    ///
    /// \param ...
    /////////////////////////////////////////////////
    std::shared_ptr<AffLabel>    label( std::string text = "Label" );

    /////////////////////////////////////////////////
    /// \brief  Cr�ation d'une simple image
    ///
    /// \param ...
    /////////////////////////////////////////////////
    std::shared_ptr<AffImage>    image( std::string fichier = "" );

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// BOUTONS
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /////////////////////////////////////////////////
    /// \brief  Cr�ation d'un simple bouton texte
    ///
    /// \param ...
    /////////////////////////////////////////////////
    std::shared_ptr<BtnRectangle>    bouton( std::string texte = "" );

    /////////////////////////////////////////////////
    /// \brief  Cr�ation d'un simple bouton rectangulaire
    ///
    /// \param ...
    /////////////////////////////////////////////////
    std::shared_ptr<BtnRectangle>    bouton( sf::Vector2i taille );

    /////////////////////////////////////////////////
    /// \brief  Cr�ation d'un simple bouton rectangulaire
    ///
    /// \param ...
    /////////////////////////////////////////////////
    std::shared_ptr<BtnMenu>        menu( );

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// DONNEES
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////
    /// \brief  Cr�ation d'un bouton interrupteur ( bool )
    ///
    /// \param ...
    /////////////////////////////////////////////////
    std::shared_ptr<DnCaseACocher>        btnACocher( bool val = true );

};

}; // fin namespace gui

#endif // FABRIQUEBASE_H
