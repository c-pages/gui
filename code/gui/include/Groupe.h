#ifndef PANNEAU__H
#define PANNEAU__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Gadget.h"
#include "gadgets/AffRectangle.h"
#include "repartiteurs/Repartiteur.h"



namespace gui {




class Groupe : public Gadget {


enum class Decorations{
    Sliders
};

/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////
public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /////////////////////////////////////////////////
    Groupe ();


public:
    ///< Definir m_repartiteur
    void setRepartiteur( std::unique_ptr<Repartiteur> val ){ m_repartiteur = std::move(val); };

    void repartirEnfants () {
//        std::cout << " BAH ca c queque chose\n";
        m_repartiteur->repartir( m_enfants );
    };

    /////////////////////////////////////////////////
    virtual void ajouter ( std::shared_ptr<Gadget> enfant, unsigned int index );
    virtual void ajouter ( std::shared_ptr<Gadget> enfant );

    void setRepartition ( Repartitions repartition );

    /////////////////////////////////////////////////
    virtual void actualiserContenu ();

    /////////////////////////////////////////////////
    virtual void actualiserGeometrie ();

    /////////////////////////////////////////////////
    virtual void actualiserStyle ();

    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /////////////////////////////////////////////////
    virtual void setTaille(sf::Vector2i taille){
        m_taille = taille;
        m_fond->setTaille(taille);
        actualiser();
    }

    void setFillColor ( sf::Color couleurs  ) {
            m_fndCouleur = couleurs;
            actualiserStyle();
//            m_rectangle->setFillColor( couleur );
        };
    void setOutlineColor ( sf::Color couleurs  ) {
            m_fndLgnCouleur = couleurs;
            actualiserStyle();
//            m_rectangle->setOutlineColor( couleur );
        };
    void setOutlineThickness ( float epaisseur ) {
            m_fndLgnepaisseur =  epaisseur;
            actualiserStyle();
//            m_rectangle->setOutlineThickness( epaisseur );
        };

    void setContenantFillColor ( sf::Color couleurs  ) {
            m_contenantCouleur = couleurs;
            actualiserStyle();
//            m_rectangle->setFillColor( couleur );
        };
    void setContenantOutlineColor ( sf::Color couleurs  ) {
            m_contenantLgnCouleur = couleurs;
            actualiserStyle();
//            m_rectangle->setOutlineColor( couleur );
        };
    void setContenantOutlineThickness ( float epaisseur ) {
            m_contenantLgnepaisseur =  epaisseur;
            actualiserStyle();
//            m_rectangle->setOutlineThickness( epaisseur );
        };

    /////////////////////////////////////////////////
    sf::Vector2f    deplMaxContenu();

    virtual std::shared_ptr<Gadget>  testerSurvol ( sf::Vector2i position );

    virtual sf::Vector2i getTailleContenant()   { return m_tailleContenant;};
//    virtual sf::Vector2i getPosContenant()      { return m_posContenant;};

/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
protected:

    std::unique_ptr<Repartiteur>        m_repartiteur;      ///< cf; GOF Strategie

    int                                 m_posX_texture;
    int                                 m_posY_texture;
    sf::Texture                         m_contenu;          ///< La texture SFML qui affiche le contenu du panneau.
    sf::RenderTexture                   m_renderTexture;
    sf::Vector2f                        m_largeurSliders;

    sf::Vector2i                        m_tailleContenant;
    sf::Vector2i                        m_posContenant;

    // les composants de l'interface du gadget
    std::shared_ptr<AffRectangle>       m_fond;
    std::shared_ptr<sf::RectangleShape> m_contenant;

    // les proprietés graphiques
    sf::Color               m_fndCouleur;
    sf::Color               m_fndLgnCouleur;
    float                   m_fndLgnepaisseur;

    sf::Color               m_contenantCouleur;
    sf::Color               m_contenantLgnCouleur;
    float                   m_contenantLgnepaisseur;

}; // fin class Groupe

} // fin namespace gui

#endif
