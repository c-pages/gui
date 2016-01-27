#ifndef GUI_H
#define GUI_H

#include "Gadget.h"
#include "FabriqueGadget.h"
#include "Skin.h"
#include "ConteneurGui.h"

#include <SFML/Graphics.hpp>
#include <memory>

namespace gui {

class Gui : public sf::Drawable, public sf::NonCopyable, public std::enable_shared_from_this<Gui>
{
    public:
        /*
        Gui()
        {

            std::cout << "\n    Creation -> TEST TEST TEST TEST <- Creation\n\n";

        };*/
//        virtual ~Gui();
//        virtual void			draw(sf::RenderTarget& target, sf::RenderStates states) const
//        {
//            std::cout << "\nTEST TEST TEST TEST\n\n";
//        };





/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////

public:
    ///< Definir m_fenetreSFML
    void setFenetreSFML( sf::RenderWindow* val ){ m_fenetreSFML = val; };

    ///< Acceder à m_fenetreSFML
    sf::RenderWindow* getFenetreSFML () const { return m_fenetreSFML; };

    ///< Definir m_skin
    void setSkin( std::shared_ptr<Skin> val ){ m_skin = val; };

    ///< Acceder à m_skin
    std::shared_ptr<Skin> getSkin () const { return m_skin; };

public:

    void actualiser (sf::Time delta);

    void traiter_evenements (const sf::Event&  evenement);

//    void dessiner ( ) const;

//private:
    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut
    ///
    /////////////////////////////////////////////////
    Gui ();

    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut
    ///
    /// \param fenetreSFML		 la fenetre SFML dans laquelle on va utiliser l'interface
    /////////////////////////////////////////////////
    Gui (sf::RenderWindow* fenetreSFML);

//    /////////////////////////////////////////////////
//    /// \brief Constructeur par copie  en privé (Singleton).
//    ///
//    /// \param original
//    /////////////////////////////////////////////////
//    Gui (const Gui& original) = delete;

    /////////////////////////////////////////////////
    /// \brief Destructeur par défaut privé (Singleton).
    ///
    /////////////////////////////////////////////////
    ~Gui ();

    /////////////////////////////////////////////////
    /// \brief Cherche quel gadget est sruvolé, nullptr si rien n'est survolé.
    ///
    /////////////////////////////////////////////////
    Gadget::ptr chercherSurvol ();

    /////////////////////////////////////////////////
    /// \brief Dessiner le gadget => dessiner ses enfants.
    ///
    /// \param target
    /// \param states
    /////////////////////////////////////////////////
    virtual void			draw(sf::RenderTarget& target, sf::RenderStates states) const;

/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
public:
//    static Gui  m_instance;                             ///< L'instance static unique vers le GUI. (GOF4 : singleton.)

    FabriqueGadget              creer;         ///< Fonctions de creation des gadgets.

private:
    sf::RenderWindow*           m_fenetreSFML;  ///< La fenêtre SFML dans laquelle on intègre l'interface.#G#S
    std::shared_ptr<Skin>       m_skin;         ///< Le skin global à appliqué aux gadgets de l'interface.#G#S

//    Gadget::ptr                 m_conteneur;    ///< Le conteneur de tout les gadgets de l'interface.

private:
    std::vector<Gadget::ptr>    m_Boutons;         ///< La liste totale des boutons.
    Gadget::ptr                 m_btnSurvole;      ///< Pointeur vers le bouton qui à le focus du survol.
    Gadget::ptr                 m_btnPresse;       ///< Pointeur vers le bouton de l'interface qui est en train d'être pressé.


    friend class FabriqueGadget;
};

};
#endif // TEST_H
