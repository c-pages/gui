#ifndef SUPBANDEAUMENUSDEROULANTS__H
#define SUPBANDEAUMENUSDEROULANTS__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "SupBandeau.h"
#include "BtnTexte.h"
//#include "Interface.h"
#include <SFML/Graphics.hpp>
#include <memory>



namespace gui {

class BtnMenu;
class Interface;

class SupBandeauMenusDeroulants : public gui::SupBandeau {


/////////////////////////////////////////////////
// struct
/////////////////////////////////////////////////

//struct ElementSousMenu {
//    std::string                 nom;
//    FctnAction                  fonction;
//    std::shared_ptr<BtnTexte>   bouton;
//};

struct ElementMenu {
    std::string                 nom;
    std::shared_ptr<BtnTexte>   bouton;
    std::shared_ptr<BtnMenu>    menu;
};


/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////
public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /////////////////////////////////////////////////
    SupBandeauMenusDeroulants ();

    void ajouterMenu (std::string nom);

//    void ajouterElement (std::string nom, FctnAction fonction);
    void ajouterElement ( std::string nom, FctnAction fonction = [](){} , std::string menu = ms_menuBack );

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
//    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;
//    virtual std::shared_ptr<Gadget>  testerSurvol ( sf::Vector2i position );

private:
    static   std::string            ms_menuBack;
    static   bool                   ms_menuActif;
    static   bool                   ms_init;

    std::vector <ElementMenu*>      m_elements;

/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:


}; // fin class SupBandeauMenusDeroulants

} // fin namespace gui

#endif
