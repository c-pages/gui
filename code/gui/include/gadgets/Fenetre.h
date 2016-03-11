#ifndef FENETRE__H
#define FENETRE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "ActionEvenement.h"
#include "decorations/FenDecoration.h"
#include "gadgets/AffBarreTitre.h"
#include <memory>
#include <Groupe.h>


namespace gui {


class Fenetre : public ActionEvenement {

public:
    enum class Decorations{
        Drag,
        Retaille,
        Fermer
    };

/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////
public:
    Fenetre();
    /////////////////////////////////////////////////
    /// \brief Bascule entre un panneau simple (false) et un panneau slider (true).
    ///
    /// \param val
    /////////////////////////////////////////////////
    virtual void setDefilementActif (bool val);


    /////////////////////////////////////////////////
    virtual void ajouter (std::shared_ptr<Gadget> enfant);

    /////////////////////////////////////////////////
    virtual std::shared_ptr<Gadget> retirer (std::shared_ptr<Gadget> enfant);

    virtual void traiterEvenements (const sf::Event& evenement);

    /////////////////////////////////////////////////
    virtual std::shared_ptr<Gadget>  testerSurvol ( sf::Vector2i position );

    virtual void setTexte( std::string titre ) {
        m_texte = titre;
        m_titre->setTexte( titre );
    };

//    void positionnerFenetre ();
    void chargerIcone   (std::string fichier );

    /////////////////////////////////////////////////
    virtual void actualiserGeometrie ();

    /////////////////////////////////////////////////
    virtual void actualiserStyle ();

    /////////////////////////////////////////////////
    virtual sf::Vector2i getTailleBouton (){ return m_tailleBoutons; };

    std::shared_ptr<AffRectangle> getOmbre() { return m_ombre;};

    void ajouterDecoration ( Decorations deco  );

    void retirerDecoration ( Decorations deco  )
    {
        m_decorations.erase( deco  );
    };

/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
protected:
    std::shared_ptr<Groupe>         m_panneau;
    std::shared_ptr<AffRectangle>   m_fond;
    std::shared_ptr<AffRectangle>   m_ombre;
    std::shared_ptr<AffBarreTitre>  m_titre;

    std::map<Decorations, std::shared_ptr<FenDecoration>>     m_decorations;

    sf::Vector2i            m_tailleBoutons;


    // les proprietés graphiques
    sf::Color               m_panneauFndCouleur;
    sf::Color               m_panneauFndLgnCouleur;
    float                   m_panneauFndLgnepaisseur;
    sf::Color               m_panneauContenantCouleur;
    sf::Color               m_panneauContenantLgnCouleur;
    float                   m_panneauContenantLgnepaisseur;

    sf::Color               m_titreFondCouleur;
    sf::Color               m_titreFondLgnCouleur;
    float                   m_titreFondLgnepaisseur;
    sf::Color               m_titreTextCouleur;

    sf::Text::Style         m_titreTextStyle;
    float                   m_titreTextTaille;
    sf::Font                m_titreTextPolice;

    sf::Color               m_fondCouleur;
    sf::Color               m_fondLgnCouleur;
    float                   m_fondLgnepaisseur;

    sf::Color               m_ombreCouleur;
    sf::Color               m_ombreLgnCouleur;
    float                   m_ombreLgnepaisseur;

}; // fin class Fenetre


} // fin namespace gui

#endif
