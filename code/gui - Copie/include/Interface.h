#ifndef INTERFACE_H
#define INTERFACE_H


#include "SFML/Graphics.hpp"
#include "Gadget.h"
#include "Calque.h"
#include "FabriqueBase.h"
#include "ResourcesMgr.h"

namespace gui {

//enum class Polices {
//    Defaut,
//    Police_1,
//    Fin
//};
static  ResourcesMgr<sf::Font,      std::string >   ms_polices; ///< Manager des polices

//enum class Icones {
//    Fin
//};

//static  ResourcesMgr<sf::Texture,   std::string >   ms_icones;  ///< Manager des icones

//enum class Images {
//    Fin
//};
static  ResourcesMgr<sf::Texture,   std::string >   ms_images;  ///< Manager des images


/////////////////////////////////////////////////
/// \brief Classe communes � tout les gadgets, g�re affichage actualisation, etc...
///
/// \todo mmm c po claire ! Transformer en singleton ? ou transformer en singleton le ressourceMgr ( qui pourra du coup �tre partag� entre plusieurs interfaces...)?
///
/////////////////////////////////////////////////
class Interface : public Gadget{

public:
    Interface( sf::RenderWindow* fenetre );

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    virtual void traiterEvenements( sf::Event evenement );


    /////////////////////////////////////////////////
    /// \brief Actualiser les g�om�trie du gadgets, et donc ses bounds.
    ///
    /////////////////////////////////////////////////
    virtual void actualiser ();
//    void nouvellePolice(std::string fichier);

    /////////////////////////////////////////////////
    virtual void actualiser ( sf::Time deltaTemps ){
        Gadget::actualiser( deltaTemps );
    };


private:
    std::shared_ptr<Gadget> chercherGadgetSurvole ();

    /////////////////////////////////////////////////
    /// \brief D�clenche un �v�nement pour tout les boutons (ms_boutons)
    ///
    /// \param evenement    L'�v�nement � d�clencher.
    /// \param saufGadget   L'�v�nement ne sera pas d�clencher pour ce gadget.    ///
    /////////////////////////////////////////////////
    void declencherToutBoutons ( Evenement evenement , std::shared_ptr<Gadget> saufGadget = nullptr );

public:
/////////////////////////////////////////////////
// membres
/////////////////////////////////////////////////
    static sf::Vector2i getPosSouris() {
        sf::Vector2i result = {-1,-1};
        result = sf::Mouse::getPosition( *ms_fenetreSFML );
        return result;
    };

    static sf::RenderWindow*                    ms_fenetreSFML;      ///< La fenetyre SFML;
//
//    std::vector<std::shared_ptr<Gadget>>        m_bureau;
//    std::vector<std::shared_ptr<Gadget>>        m_fenetres;
//    std::vector<std::shared_ptr<Gadget>>        m_supports;

    std::shared_ptr<Calque>        m_calque_bureau;
    std::shared_ptr<Calque>        m_calque_fenetres;
    std::shared_ptr<Calque>        m_calque_supports;


    FabriqueBase    creer;                              ///< La fabrique de gadget de base (GOF: Fabrique)

public:


    std::shared_ptr<Gadget>     m_boutonSurvole;    ///< Le bouton survol� actuelement par la souris.
private:
    std::shared_ptr<Gadget>     m_boutonPresse;     ///< Le bouton press� actuelement par la souris.
    sf::RenderWindow*           m_fenetre;          ///< La fenetyre SFML;

}; // fin class gui

}; // fin namespace gui

#endif // INTERFACE_H