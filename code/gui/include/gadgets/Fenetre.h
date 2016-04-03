#ifndef FENETRE__H
#define FENETRE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <memory>

#include "ActionEvenement.h"

#include "decorations/FenDecoration.h"

#include "gadgets_outils/AffBarreTitre.h"

#include <gadgets_interfaces/Contenant.h>
#include <gadgets_interfaces/composants/CmpOmbre.h>
#include <gadgets_interfaces/composants/CmpFond.h>


namespace gui {


class Fenetre   : public ActionEvenement
                , public CmpFond
                , public CmpOmbre {

public:
    enum class Decorations{
        Drag,
        Retaille,
        RetaillePanneau,
        Fermer
    };

/////////////////////////////////////////////////
// M�thodes
/////////////////////////////////////////////////
public:
    Fenetre();
    virtual ~Fenetre(){};
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

//    /////////////////////////////////////////////////
//    virtual std::shared_ptr<Gadget>  testerSurvol ( sf::Vector2i position );

    virtual bool        estInteractif() { return true; }; ///< \todo voir si on peut faire mieux ...


    void chargerIcone   (std::string fichier );

    /////////////////////////////////////////////////
    virtual void actualiserGeometrie ();

    /////////////////////////////////////////////////
    virtual void actualiserStyle ();

    /////////////////////////////////////////////////
    virtual sf::Vector2i getTailleBouton (){ return m_tailleBoutons; };

    std::shared_ptr<AffRectangle> getOmbre() { return m_ombre; };

    void ajouterDecoration ( Decorations deco  );

    void retirerDecoration ( Decorations deco  )
    {
        if ( m_decorations.find( deco ) != m_decorations.end())        {
                m_decorations.erase( deco  );
        }
    };

    virtual void actualiserEtatDeco ( );

    void viderTableaux()    {
        if ( m_decoASupprimer.size()>0 )
            for ( auto deco : m_decoASupprimer )
                m_decorations.erase( deco  );
    };

/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
protected:

//friend class FenDecoRedimPanneau;

    std::vector<Decorations>        m_decoASupprimer;

    std::shared_ptr<Contenant>      m_contenant;

    std::shared_ptr<AffBarreTitre>  m_titre;

    std::map<Decorations, std::shared_ptr<FenDecoration>>     m_decorations;

    sf::Vector2i            m_tailleBoutons;



    // les propriet�s graphiques
    sf::Color               m_contenantFndCouleur;
    sf::Color               m_contenantFndLgnCouleur;
    float                   m_contenantFndLgnepaisseur;
    sf::Color               m_contenantContenantCouleur;
    sf::Color               m_contenantContenantLgnCouleur;
    float                   m_contenantContenantLgnepaisseur;

    sf::Color               m_titreFondCouleur;
    sf::Color               m_titreFondLgnCouleur;
    float                   m_titreFondLgnepaisseur;
    sf::Color               m_titreTextCouleur;

    sf::Text::Style         m_titreTextStyle;
    float                   m_titreTextTaille;
    sf::Font                m_titreTextPolice;

}; // fin class Fenetre


} // fin namespace gui

#endif