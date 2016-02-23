#ifndef FABRIQUEBASE_H
#define FABRIQUEBASE_H

#include "SFML/Graphics.hpp"
#include "memory"

#include "Gadget.h"
#include "gadgets\AffRectangle.h"
#include "gadgets\AffLabel.h"
#include "gadgets\AffImage.h"

namespace gui{


class FabriqueBase
{

public:
    /////////////////////////////////////////////////
    /// \brief  Création d'un simple rectangle
    ///
    /// \param ...
    /////////////////////////////////////////////////
    std::shared_ptr<AffRectangle>    rectangle( sf::Vector2i taille = {100,100} );

    /////////////////////////////////////////////////
    /// \brief  Création d'un simple label
    ///
    /// \param ...
    /////////////////////////////////////////////////
    std::shared_ptr<AffLabel>    label( std::string text = "Label" );

    /////////////////////////////////////////////////
    /// \brief  Création d'une simple image
    ///
    /// \param ...
    /////////////////////////////////////////////////
    std::shared_ptr<AffImage>    image( std::string fichier = "" );



};

}; // fin namespace gui

#endif // FABRIQUEBASE_H
