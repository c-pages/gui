#ifndef ECRANDEMO_H
#define ECRANDEMO_H

/////////////////////////////////////////////////
//  Headers
/////////////////////////////////////////////////
#include    <SFML/Graphics.hpp>
#include    <memory>
#include    <Ecran.h>
#include    <Application.h>

#include    <gui.h>


namespace app {

/////////////////////////////////////////////////
/// \class  EcranDemo
/// \brief  Ecran de démonstration
///
/////////////////////////////////////////////////
class EcranDemo : public Ecran
{

public:
    /////////////////////////////////////////////////
    /// \brief Constructeur
    ///
    /////////////////////////////////////////////////
    EcranDemo( Application* appli );

private:
    /////////////////////////////////////////////////
    /// \brief La gestion des évènements utilisateurs.
    ///
    /// \details  Gère les entrées claviers, souris, fenetre ...
    /// \return Rien
    ///
    /////////////////////////////////////////////////
    virtual     void traiter_evenements ( const sf::Event& event );

    /////////////////////////////////////////////////
    /// \brief Actualiser les éléments.
    ///
    /// \details Actualiser les différents éléments du ou des écrans actifs.
    /// \param   deltaT Un \e float qui indique le delta du temps écoulé depuis la dernière actualisation.
    /// \return  Rien
    ///
    /////////////////////////////////////////////////
    virtual     void actualiser ( float deltaT );

    /////////////////////////////////////////////////
    /// \brief Rendre les éléments.
    ///
    /// Dessiner les différents éléments du ou des écrans actifs.
    /// \return Rien
    ///
    /////////////////////////////////////////////////
    virtual     void dessiner  ( );

    /////////////////////////////////////////////////
    /// \brief Fonction a supprimer
    ///
    /// juste là pour tester des machins bidules.
    /// \return Rien
    ///
    /////////////////////////////////////////////////
    void test ();

    /////////////////////////////////////////////////
    /// \brief Initialisation de la scene ... le monde du jeu ou tout autre bazard...
    ///
    /// Creation de la scene principale du jeu ...
    /// \return Rien
    ///
    /////////////////////////////////////////////////
    virtual  void   initScene  ();

    /////////////////////////////////////////////////
    /// \brief Initialisation de l'interface graphique.
    ///
    /// Creation des fenêtres, boutons, menus... ...
    /// \return Rien
    ///
    /////////////////////////////////////////////////
    virtual     void initGUI ();

    void initGUI_tests();

    void initGUI_MenuPanneaux ();
    void initGUI_test_Affichages ();
    void initGUI_test_Boutons ();
    void initGUI_test_Donnees ();
    void initGUI_test_Contenantx ();
    void initGUI_test_Fenetres ();

    void lierMachiner ();
    void delierMachiner ();

private:

    /////////////////////////////////////////////////
    // Les membres
    /////////////////////////////////////////////////

    sf::Clock          m_chronoFPS;
    int                m_compteurFrameFPS = 0;
    int                m_FPS = 0;

    sf::RectangleShape                  m_fond;         ///< Le shape SFML du fond de l'écran.

    // l'Interface
    std::shared_ptr<gui::Interface>     m_interface;    ///< Le groupe de GUI du menu principal.
    std::shared_ptr<gui::BtnRectangle>     m_cache;

    // un skin permettant de gérer le rendu
//    std::shared_ptr<gui::Skin>          m_skin;         ///< Un skin.

    // AFFICHAGE
//    std::shared_ptr<gui::Fenetre>  m_fenetre1;    ///< Un simple rectangle.


    std::shared_ptr<gui::Fenetre>   m_fenetreAffichage;
    std::shared_ptr<gui::Fenetre>   m_fenetreDonnees;
    std::shared_ptr<gui::Fenetre>   m_fenetreBoutons;

    sf::Vector2f                   m_posFenetre1;
    sf::Vector2i                   m_tailleFenetre1;


}; // fin EcranDemo
}; // fin app
#endif // ECRANDEMO_H
