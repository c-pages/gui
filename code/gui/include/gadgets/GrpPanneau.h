#ifndef GRPPANNEAU__H
#define GRPPANNEAU__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Groupement.h"
#include "AffRectangle.h"
#include "AffImage.h"
#include "DnBarreDefilement.h"
#include "Groupement.h"
#include "repartiteurs/Repartiteur.h"
#include "repartiteurs/RepartiteurGrille.h"
#include "repartiteurs/RepartiteurHorizontal.h"
#include "repartiteurs/RepartiteurLibre.h"
#include "repartiteurs/RepartiteurVerticale.h"
#include "Enums.h"
#include <memory>
#include <SFML/Graphics.hpp>



namespace gui {



class GrpPanneau : public gui::Groupement {


/////////////////////////////////////////////////
// Enums & typedefs
/////////////////////////////////////////////////





/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////

public:
    ///< Definir m_repartiteur
    void setRepartiteur( Repartiteur val ){ m_repartiteur = val; };

public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /////////////////////////////////////////////////
    GrpPanneau ();

    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /////////////////////////////////////////////////
    virtual void setTaille(sf::Vector2i taille){
        m_taille = taille;
        m_fond->setTaille(taille);
        actualiser();
    }



    /////////////////////////////////////////////////
    /// \brief Actualise le repartiteur puis les gadgets enfant contenus.
    ///
    /////////////////////////////////////////////////
    virtual void actualiser ();

    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;

    sf::IntRect  boundgingB_enfants();

    /////////////////////////////////////////////////
    /// \brief Dessiner les enfants du gadget.
    ///
    /// \param target
    /// \param states
    /////////////////////////////////////////////////
    void actualiserContenu ()  ;

private:
    sf::Vector2f    deplMaxContenu();


/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:
    std::shared_ptr<AffRectangle>       m_fond;
    std::shared_ptr<DnBarreDefilement>  m_slider_V;
    std::shared_ptr<DnBarreDefilement>  m_slider_H;
//    std::shared_ptr<AffImage>       m_contenant;    ///< Le rectangle sur lequel on applique la texture qui affiche le contenu.

    sf::Texture     m_contenu;    ///< La texture SFML qui affiche le contenu du panneau.
    sf::RenderTexture m_renderTexture;
    /*
    bool            m_afficherSlider_V;
    bool            m_afficherSlider_H;*/

    Repartiteur     m_repartiteur;    ///< cf; GOF Strategie #S
    int             m_posX_texture;

    int             m_posY_texture;
    std::shared_ptr<sf::RectangleShape> m_contenant;

}; // fin class GrpPanneau

} // fin namespace gui

#endif
