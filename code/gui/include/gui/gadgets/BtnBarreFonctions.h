#ifndef BTNBARREOUTILS__H
#define BTNBARREOUTILS__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
//#include "Donnee.h"
#include "interfaces/gadgets/Bouton.h"
#include "BtnIcone.h"
#include "interfaces/gadgets/Contenant.h"



namespace gui {



/////////////////////////////////////////////////
/// \brief Une barre d'outils, permet de déclencher des fonctions.
///
/////////////////////////////////////////////////
//class BtnBarreFonctions : public Donnee<std::vector<int>> {
class BtnBarreFonctions : public Bouton {


/////////////////////////////////////////////////
// struct
/////////////////////////////////////////////////
struct ElementOutil {
    std::string                 nom;
    FctnAction                  fonction;
    std::shared_ptr<BtnIcone>   bouton;
};



/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////
public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /////////////////////////////////////////////////
    BtnBarreFonctions ();

    void ajouterElement (std::string nom, std::string fichierIcone, FctnAction action);

    void supprimerElement (unsigned int id);

    virtual void actualiserGeometrie ();

    virtual void actualiserStyle ();
    /////////////////////////////////////////////////
    virtual void traiterEvenements (const sf::Event& evenement);

    void setDrag ( bool val ) { m_drag = val;};
    bool dragEnCours(){return m_drag;};
    void positionnerFenetre ();
    virtual std::shared_ptr<Gadget>  testerSurvol ( sf::Vector2i position );

//    virtual void actualiserContenu ();
//    virtual void actualiserBounds ();

//    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;

/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:
//    std::shared_ptr<Contenant>        m_panneau;
    std::shared_ptr<AffRectangle>   m_fond;
    std::shared_ptr<AffRectangle>   m_ombre;



    sf::Vector2i                    m_tailleBouton;   ///< La taille d'un bouton du menu
    std::vector< ElementOutil*>     m_elements;
    float                           m_largeurDrag;
    bool                            m_drag;
    sf::Vector2i                    m_decalageDragSouris;
    bool                            m_modeFenetre;

    sf::Color   m_fndCouleur;
    sf::Color   m_fndLgnCouleur;
    float       m_fndLgnEpaisseur;

    sf::Color               m_ombreCouleur;
    sf::Color               m_ombreLgnCouleur;
    float                   m_ombreLgnepaisseur;


}; // fin class BtnBarreFonctions

} // fin namespace gui

#endif
