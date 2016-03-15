#ifndef CONTENANT__H
#define CONTENANT__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Gadget.h"
#include "Groupe.h"
#include "gadgets/AffRectangle.h"
#include "repartiteurs/Repartiteur.h"



namespace gui {




class Contenant : public Gadget {


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
    Contenant ();


public:
    ///< Definir m_repartiteur
    void setRepartiteur( std::unique_ptr<Repartiteur> val ){ m_repartiteur = std::move(val); };

    void repartirEnfants () {
//        std::cout << " BAH ca c queque chose\n";
        m_repartiteur->repartir( m_groupe->getEnfants() );
    };

    /////////////////////////////////////////////////
    virtual void ajouter ( std::shared_ptr<Gadget> enfant, unsigned int index );
    virtual void ajouter ( std::shared_ptr<Gadget> enfant );

    void setRepartition ( Repartitions repartition );

    /////////////////////////////////////////////////
    virtual void replacerContenu ();


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

    void setFondCouleur ( sf::Color couleurs  ) {
            m_fndCouleur = couleurs;
            actualiserStyle();
//            m_rectangle->setFondCouleur( couleur );
        };
    void setLigneCouleur ( sf::Color couleurs  ) {
            m_fndLgnCouleur = couleurs;
            actualiserStyle();
//            m_rectangle->setLigneCouleur( couleur );
        };
    void setLigneEpaisseur ( float epaisseur ) {
            m_fndLgnepaisseur =  epaisseur;
            actualiserStyle();
//            m_rectangle->setLigneEpaisseur( epaisseur );
        };

    void setContenantFillColor ( sf::Color couleurs  ) {
            m_contenantCouleur = couleurs;
            actualiserStyle();
//            m_rectangle->setFondCouleur( couleur );
        };
    void setContenantOutlineColor ( sf::Color couleurs  ) {
            m_contenantLgnCouleur = couleurs;
            actualiserStyle();
//            m_rectangle->setLigneCouleur( couleur );
        };
    void setContenantOutlineThickness ( float epaisseur ) {
            m_contenantLgnepaisseur =  epaisseur;
            actualiserStyle();
//            m_rectangle->setLigneEpaisseur( epaisseur );
        };

    /////////////////////////////////////////////////
    sf::Vector2f    deplMaxContenu();

    virtual std::shared_ptr<Gadget>  testerSurvol ( sf::Vector2i position );

    virtual sf::Vector2i getTailleContenant()   { return m_tailleContenant; };
//    virtual sf::Vector2i getPosContenant()      { return m_posContenant;};

    /////////////////////////////////////////////////
    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;


    virtual bool aEnfants() { return m_groupe->aEnfants(); };

    virtual std::vector<std::shared_ptr<Gadget>> getEnfants() const { return m_groupe->getEnfants(); };



/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
protected:

    std::unique_ptr<Repartiteur>        m_repartiteur;      ///< cf; GOF Strategie

//    int                                 m_posContenant.x;
//    int                                 m_posContenant.y;
    sf::Texture                         m_contenu;          ///< La texture SFML qui affiche le contenu du panneau.
    sf::RenderTexture                   m_renderTexture;
    sf::Vector2f                        m_largeurSliders;

    sf::Vector2i                        m_tailleContenant;
    sf::Vector2i                        m_posContenant;

    // les composants de l'interface du gadget
    std::shared_ptr<AffRectangle>       m_fond;
    std::shared_ptr<sf::RectangleShape> m_affContenant;
    std::shared_ptr<Groupe>             m_groupe;

    // les proprietés graphiques
    sf::Color               m_fndCouleur;
    sf::Color               m_fndLgnCouleur;
    float                   m_fndLgnepaisseur;

    sf::Color               m_contenantCouleur;
    sf::Color               m_contenantLgnCouleur;
    float                   m_contenantLgnepaisseur;

}; // fin class Contenant

} // fin namespace gui

#endif
