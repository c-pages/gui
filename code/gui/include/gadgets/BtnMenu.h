#ifndef BTNMENU__H
#define BTNMENU__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Bouton.h"
#include "AffRectangle.h"
#include "BtnTexte.h"
#include <vector>
#include <memory>



namespace gui {



/////////////////////////////////////////////////
/// \brief Un menu, permet de déclencher un action parmis d'autres.
///
/////////////////////////////////////////////////
class BtnMenu : public gui::Bouton {



/////////////////////////////////////////////////
// struct
/////////////////////////////////////////////////
struct ElementMenu {
    std::string                 nom;
    FctnAction                  fonction;
    std::shared_ptr<BtnTexte>   bouton;
};



/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////

public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /////////////////////////////////////////////////
    BtnMenu ();

    void ajouterElement (std::string nom, FctnAction fonction);

    /////////////////////////////////////////////////
    /// \brief
    ///
    /// \param id
    /////////////////////////////////////////////////
    void supprimerElement (unsigned int id);

//    virtual void actualiser ();
    virtual void actualiserBounds ();

    /////////////////////////////////////////////////
    void actualiserGeometrie();

    /////////////////////////////////////////////////
    void actualiserStyle();


    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;

    virtual std::shared_ptr<Gadget>  testerSurvol ( sf::Vector2i position );

/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
public:

    // les proprietés fonctionnelles
    sf::Vector2i                    m_tailleMenu;   ///< La taille d'un bouton du menu
    float                           m_ecart;

    // les composants de l'interface du gadget
    std::vector <ElementMenu*>      m_elements;
    std::shared_ptr<AffRectangle>   m_fond;

    // les proprietés graphiques
    sf::Color           m_fndCouleur;
    sf::Color           m_fndLignesCouleur;
    float               m_fndLignesEpaisseur;

    Valeurs<sf::Color>  m_btnCouleurs;
    Valeurs<sf::Color>  m_btnLignesCouleurs;
    Valeurs<float>      m_btnLignesEpaisseurs;

    sf::Color           m_textCouleur;
    sf::Text::Style     m_textStyle;
    float               m_textTaille;
    sf::Font            m_textPolice;

}; // fin class BtnMenu

} // fin namespace gui

#endif
