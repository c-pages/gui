//#ifndef GUI__H
//#define GUI__H
//
///////////////////////////////////////////////////
//// Headers
///////////////////////////////////////////////////
//#include "Gadget.h"
//#include "FabriqueGadget.h"
//#include "Skin.h"
//#include "ConteneurGui.h"
//
//#include <SFML/Graphics.hpp>
//#include <memory>
//
//
//namespace gui {
//
//
//
///////////////////////////////////////////////////
///// \brief Le gestionnaire d'interface
/////
///////////////////////////////////////////////////
//class Gui : public sf::Drawable {
//
//
//
///////////////////////////////////////////////////
//// M�thodes
///////////////////////////////////////////////////
//
//public:
//    ///< Definir m_fenetreSFML
//    void setFenetreSFML( sf::RenderWindow* val ){ m_fenetreSFML = val; };
//
//    ///< Acceder � m_fenetreSFML
//    sf::RenderWindow* getFenetreSFML () const { return m_fenetreSFML; };
//
//    ///< Definir m_skin
//    void setSkin( std::shared_ptr<Skin> val ){ m_skin = val; };
//
//    ///< Acceder � m_skin
//    std::shared_ptr<Skin> getSkin () const { return m_skin; };
//
//public:
//
//    void actualiser (sf::Time delta);
//
//    void traiter_evenements (const sf::Event&  evenement);
//
////    void dessiner ( ) const;
//
////private:
//    /////////////////////////////////////////////////
//    /// \brief Constructeur par d�faut
//    ///
//    /////////////////////////////////////////////////
//    Gui ();
//
//    /////////////////////////////////////////////////
//    /// \brief Constructeur par d�faut
//    ///
//    /// \param fenetreSFML		 la fenetre SFML dans laquelle on va utiliser l'interface
//    /////////////////////////////////////////////////
//    Gui (sf::RenderWindow* fenetreSFML);
//
//    /////////////////////////////////////////////////
//    /// \brief Constructeur par copie  en priv� (Singleton).
//    ///
//    /// \param original
//    /////////////////////////////////////////////////
//    Gui (const Gui& original) = delete;
//
//    /////////////////////////////////////////////////
//    /// \brief Destructeur par d�faut priv� (Singleton).
//    ///
//    /////////////////////////////////////////////////
//    ~Gui ();
//
//    /////////////////////////////////////////////////
//    /// \brief Cherche quel gadget est sruvol�, nullptr si rien n'est survol�.
//    ///
//    /////////////////////////////////////////////////
//    Gadget::ptr chercherSurvol ();
//
//    /////////////////////////////////////////////////
//    /// \brief Dessiner le gadget => dessiner ses enfants.
//    ///
//    /// \param target
//    /// \param states
//    /////////////////////////////////////////////////
//    virtual void draw (sf::RenderTarget& target, sf::RenderStates states /* = sf::RenderStates::Default */ ) const;
//
///////////////////////////////////////////////////
//// Membres
///////////////////////////////////////////////////
//public:
////    static Gui  m_instance;                             ///< L'instance static unique vers le GUI. (GOF4 : singleton.)
//
//    FabriqueGadget              creer;         ///< Fonctions de creation des gadgets.
//
//private:
//    sf::RenderWindow*           m_fenetreSFML;  ///< La fen�tre SFML dans laquelle on int�gre l'interface.#G#S
//    std::shared_ptr<Skin>       m_skin;         ///< Le skin global � appliqu� aux gadgets de l'interface.#G#S
//
////    Gadget::ptr                 m_conteneur;    ///< Le conteneur de tout les gadgets de l'interface.
//
//private:
//    std::vector<Gadget::ptr>    m_Boutons;         ///< La liste totale des boutons.
//    Gadget::ptr                 m_btnSurvole;      ///< Pointeur vers le bouton qui � le focus du survol.
//    Gadget::ptr                 m_btnPresse;       ///< Pointeur vers le bouton de l'interface qui est en train d'�tre press�.
//
//
//    friend class FabriqueGadget;
//
//
//}; // fin class Gui
//
//} // fin namespace gui
//
//#endif

#ifndef INTERFACE__H
#define INTERFACE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
//#include "Gadget.h"
//#include "FabriqueGadget.h"
//#include "Skin.h"
//#include "ConteneurGui.h"

#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>
namespace gui {

class Interface : public sf::Drawable
{
     public:
        Interface()
        {

            std::cout << "\n    Creation -> Interface <- Creation\n\n";

        };
        virtual ~Interface(){};

        virtual void			draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
            sf::RectangleShape tmp;
            tmp.setFillColor( { 255 , 255, 0 } );
            tmp.setSize( {50,050} );
            target.draw( tmp , states );
            std::cout << "\n    draw -> Interface <- draw\n\n";
        };

    protected:
    private:
};

};
#endif

