#ifndef FABRIQUEBASE_H
#define FABRIQUEBASE_H

#include "SFML/Graphics.hpp"
#include "memory"


#include "Gadget.h"

// AFFICHAGES
#include "gadgets\AffRectangle.h"
#include "gadgets\AffLabel.h"
#include "gadgets\AffImage.h"
#include "gadgets\AffIcone.h"

// BOUTONS
#include "gadgets\BtnRectangle.h"
#include "gadgets\BtnTexte.h"
#include "gadgets\BtnIcone.h"
#include "gadgets\BtnMenu.h"

// DONNEES
#include "gadgets\DnCaseACocher.h"
#include "gadgets\DnZoneTexte.h"
#include "gadgets\DnSlider.h"
#include "gadgets\DnBarreDefilement.h"


namespace gui{


/////////////////////////////////////////////////
/// \brief Fabrique de gadgets de base (cf. GOF: Fabrique)
///
/////////////////////////////////////////////////
class FabriqueBase
{
private:

template<typename T>
std::shared_ptr<T>  creerGadget ();

public:

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// AFFICHAGES
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /////////////////////////////////////////////////
    /// \brief  Cr�ation d'un simple rectangle
    ///
    /// \param taille
    /// \return Un pointeur vers le nouveau gadget.
    /////////////////////////////////////////////////
    std::shared_ptr<AffRectangle>    rectangle( sf::Vector2i taille = {100,100} );

    /////////////////////////////////////////////////
    /// \brief  Cr�ation d'un simple label
    ///
    /// \param text
    /// \return Un pointeur vers le nouveau gadget.
    /////////////////////////////////////////////////
    std::shared_ptr<AffLabel>    label( std::string text = "Label" );

    /////////////////////////////////////////////////
    /// \brief  Cr�ation d'une simple image
    ///
    /// \param fichier
    /// \return Un pointeur vers le nouveau gadget.
    /////////////////////////////////////////////////
    std::shared_ptr<AffImage>    image( std::string fichier = "" );
/*
    /////////////////////////////////////////////////
    /// \brief  Cr�ation d'une simple image
    ///
    /// \param fichier
    /// \return Un pointeur vers le nouveau gadget.
    /////////////////////////////////////////////////
    std::shared_ptr<AffImage>    image( int id );*/

    /////////////////////////////////////////////////
    /// \brief  Cr�ation d'une simple ic�ne
    ///
    /// \param fichier
    /// \return Un pointeur vers le nouveau gadget.
    /////////////////////////////////////////////////
    std::shared_ptr<AffIcone>    icone( std::string fichier = "" , unsigned int id = 1 );

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// BOUTONS
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



    /////////////////////////////////////////////////
    /// \brief  Cr�ation d'un simple bouton texte
    ///
    /// \param texte
    /// \return Un pointeur vers le nouveau gadget.
    /////////////////////////////////////////////////
    std::shared_ptr<BtnTexte>    boutonTexte( std::string texte = "" );

    /////////////////////////////////////////////////
    /// \brief  Cr�ation d'un simple bouton rectangulaire
    ///
    /// \param taille
    /// \return Un pointeur vers le nouveau gadget.
    /////////////////////////////////////////////////
    std::shared_ptr<BtnRectangle>    boutonRect( sf::Vector2i taille );

    /////////////////////////////////////////////////
    /// \brief  Cr�ation d'un simple bouton rectangulaire
    ///
    /// \param taille
    /// \return Un pointeur vers le nouveau gadget.
    /////////////////////////////////////////////////
    std::shared_ptr<BtnIcone>    boutonIcone( std::string texte = "" );


    /////////////////////////////////////////////////
    /// \brief  Cr�ation d'un Menu
    ///
    /// \return Un pointeur vers le nouveau gadget.
    /////////////////////////////////////////////////
    std::shared_ptr<BtnMenu>        menu( );

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// DONNEES
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /////////////////////////////////////////////////
    /// \brief  Cr�ation d'un bouton interrupteur ( bool )
    ///
    /// \param val
    /// \return Un pointeur vers le nouveau gadget.
    /////////////////////////////////////////////////
    std::shared_ptr<DnCaseACocher>        btnACocher( bool val = true );

    /////////////////////////////////////////////////
    /// \brief  Cr�ation d'une zone de texte
    ///
    /// \param texte
    /// \return Un pointeur vers le nouveau gadget.
    /////////////////////////////////////////////////
    std::shared_ptr<DnZoneTexte>        zoneTexte( std::string texte = "zone de texte" );

    /////////////////////////////////////////////////
    /// \brief  Cr�ation d'un slider
    ///
    /// \return Un pointeur vers le nouveau gadget.
    /////////////////////////////////////////////////
    std::shared_ptr<DnSlider>        slider( );

    /////////////////////////////////////////////////
    /// \brief  Cr�ation d'un slider
    ///
    /// \return Un pointeur vers le nouveau gadget.
    /////////////////////////////////////////////////
    std::shared_ptr<DnBarreDefilement>        barreDefilement( );

};

}; // fin namespace gui

#endif // FABRIQUEBASE_H
