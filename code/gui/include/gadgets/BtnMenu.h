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
/// \brief Un menu, permet de d�clencher un action parmis d'autres.
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
// M�thodes
/////////////////////////////////////////////////

public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par d�faut.
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
    void setOmbreActive ( bool val ) { m_ombreActive = val; };

    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;

    virtual std::shared_ptr<Gadget>  testerSurvol ( sf::Vector2i position );

/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
public:

    static  std::shared_ptr<BtnMenu>        ms_menuOuvert;

protected:

    // les propriet�s fonctionnelles
    sf::Vector2i                    m_tailleMenu;   ///< La taille d'un bouton du menu
    float                           m_ecart;
    bool                            m_ombreActive;

    // les composants de l'interface du gadget
    std::vector<ElementMenu*>       m_elements;
    std::shared_ptr<AffRectangle>   m_fond;
    std::shared_ptr<AffRectangle>   m_ombre;

    // les propriet�s graphiques
    sf::Color           m_fndCouleur;
    sf::Color           m_fndLignesCouleur;
    float               m_fndLignesEpaisseur;

    sf::Color           m_ombreCouleur;
    sf::Color           m_ombreLgnCouleur;
    float               m_ombreLgnepaisseur;


    Valeurs<sf::Color>  m_btnCouleurs;
    Valeurs<sf::Color>  m_btnLignesCouleurs;
    Valeurs<float>      m_btnLignesEpaisseurs;

    Valeurs<sf::Color>           m_textCouleur;
    Valeurs<sf::Text::Style>     m_textStyle;
    Valeurs<float>               m_textTaille;
    Valeurs<sf::Font>            m_textPolice;

}; // fin class BtnMenu

} // fin namespace gui

#endif
