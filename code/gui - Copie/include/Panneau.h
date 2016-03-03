#ifndef PANNEAU__H
#define PANNEAU__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Gadget.h"
#include "gadgets/AffRectangle.h"
#include "repartiteurs/Repartiteur.h"



namespace gui {



class Panneau : public Gadget {



/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////
public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /////////////////////////////////////////////////
    Panneau ();


public:
    ///< Definir m_repartiteur
    void setRepartiteur( Repartiteur val ){ m_repartiteur = val; };

    /////////////////////////////////////////////////
    virtual void actualiserContenu ();


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
    sf::Vector2f    deplMaxContenu();

    virtual std::shared_ptr<Gadget>  testerSurvol ( sf::Vector2i position );


/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
protected:
    std::shared_ptr<AffRectangle>       m_fond;

    Repartiteur                         m_repartiteur;      ///< cf; GOF Strategie

    int                                 m_posX_texture;
    int                                 m_posY_texture;
    std::shared_ptr<sf::RectangleShape> m_contenant;
    sf::Texture                         m_contenu;          ///< La texture SFML qui affiche le contenu du panneau.
    sf::RenderTexture                   m_renderTexture;

}; // fin class Panneau

} // fin namespace gui

#endif
