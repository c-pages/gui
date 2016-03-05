#ifndef FENSIMPLE__H
#define FENSIMPLE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Fenetre.h"
#include "BtnIcone.h"
#include "BtnRectangle.h"
#include "AffBarreTitre.h"
#include <memory>



namespace gui {



class FenSimple : public gui::Fenetre {



/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////
public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /////////////////////////////////////////////////
    FenSimple ();

    virtual void setTexte( std::string titre ) {
        m_texte = titre;
        m_titre->setTexte( titre );
    };

    void positionnerFenetre ();
    void chargerIcone   (std::string fichier );

//    virtual void actualiser ();

    /////////////////////////////////////////////////
    virtual void actualiserGeometrie ();

    /////////////////////////////////////////////////
    virtual void actualiserStyle ();

//    virtual void actualiser ( sf::Time delta );

    virtual std::shared_ptr<Gadget>  testerSurvol ( sf::Vector2i position );

    /////////////////////////////////////////////////
    void traiterEvenements (const sf::Event& evenement);


//    /////////////////////////////////////////////////
//    /// \brief Ajouter un gadget à la liste de gadgets enfant.
//    ///
//    /// \param enfant		 L'enfant à ajouter.
//    /////////////////////////////////////////////////
//    virtual void ajouter (std::shared_ptr<Gadget> enfant);
//
//    /////////////////////////////////////////////////
//    /// \brief Retirer un enfant de la liste des enfants de ce gadget sans le supprimer.
//    ///
//    /// \param enfant		 L'enfant à retirer de la liste des enfants.
//    /// \return L'enfant supprimer des enfants.
//    /////////////////////////////////////////////////
//    virtual std::shared_ptr<Gadget> retirer (std::shared_ptr<Gadget> enfant);

//    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;

    bool dragEnCours( ) {return m_drag;};

    void setDrag (bool val ){m_drag = val;};

/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:
    bool                            m_fermable;
    bool                            m_draggable;
    bool                            m_drag;
    sf::Vector2i                    m_decalageDragSouris;

    std::shared_ptr<AffBarreTitre>  m_titre;
    std::shared_ptr<BtnIcone>       m_btnFermer;
    std::shared_ptr<BtnRectangle>   m_btnDrag;

    // les proprietés graphiques
    sf::Color               m_titreFondCouleur;
    sf::Color               m_titreFondLgnCouleur;
    float                   m_titreFondLgnepaisseur;
    sf::Color               m_titreTextCouleur;

    sf::Text::Style         m_titreTextStyle;
    float                   m_titreTextTaille;
    sf::Font                m_titreTextPolice;

    sf::Color               m_btnDragCouleurs;
    sf::Color               m_btnDragLgnCouleurs;
    float                   m_btnDragLgnepaisseurs;

    Valeurs<sf::Color>      m_btnFermerCouleurs;
    Valeurs<sf::Color>      m_btnFermerLgnCouleurs;
    Valeurs<float>          m_btnFermerLgnepaisseurs;

}; // fin class FenSimple

} // fin namespace gui

#endif
