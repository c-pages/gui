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

    sf::Clock                m_chronoFPS;
    int                m_compteurFrameFPS = 0;
    int                m_FPS = 0;

    sf::RectangleShape                  m_fond;         ///< Le shape SFML du fond de l'écran.

    // l'Interface
    std::shared_ptr<gui::Interface>     m_interface;    ///< Le groupe de GUI du menu principal.

    // un skin permettant de gérer le rendu
//    std::shared_ptr<gui::Skin>          m_skin;         ///< Un skin.

    // AFFICHAGE
    std::shared_ptr<gui::AffRectangle>  m_rectangle;    ///< Un simple rectangle.

    std::shared_ptr<gui::AffLabel>      m_labelRetour;        ///< Un simple label.

    std::shared_ptr<gui::AffLabel>      m_labelTitre_0;        ///< Un simple label.
    std::shared_ptr<gui::AffLabel>      m_labelTitre_1;        ///< Un simple label.
    std::shared_ptr<gui::AffLabel>      m_labelTitre_2;        ///< Un simple label.
    std::shared_ptr<gui::AffLabel>      m_labelTitre_3;        ///< Un simple label.
    std::shared_ptr<gui::AffLabel>      m_labelTitre_4;        ///< Un simple label.

    std::shared_ptr<gui::AffLabel>      m_label;        ///< Un simple label.
    std::shared_ptr<gui::AffLabel>      m_label_2;      ///< Un autre label.
    std::shared_ptr<gui::AffLabel>      m_label_3;      ///< Un autre label.
    std::shared_ptr<gui::AffLabel>      m_label_4;      ///< Un autre label.
    std::shared_ptr<gui::AffLabel>      m_label_5;      ///< Un autre label.
    std::shared_ptr<gui::AffLabel>      m_label_6;      ///< Un autre label.
    std::shared_ptr<gui::AffLabel>      m_label_7;      ///< Un autre label.
    std::shared_ptr<gui::AffLabel>      m_label_8;      ///< Un autre label.
    std::shared_ptr<gui::AffLabel>      m_label_9;      ///< Un autre label.
    std::shared_ptr<gui::AffLabel>      m_label_10;      ///< Un autre label.
    std::shared_ptr<gui::AffLabel>      m_label_11;      ///< Un autre label.
    std::shared_ptr<gui::AffLabel>      m_label_12;      ///< Un autre label.
    std::shared_ptr<gui::AffLabel>      m_label_13;      ///< Un autre label.
    std::shared_ptr<gui::AffLabel>      m_textePourContenant;      ///< Un autre label.

    std::shared_ptr<gui::AffImage>      m_image;        ///< Une simple image.
    std::shared_ptr<gui::AffIcone>      m_icone;        ///< Une simple icone.

    // BOUTON
    std::shared_ptr<gui::BtnIcone>      m_boutonIcone;    ///< Un simple bouton rectangulaire.
    std::shared_ptr<gui::BtnTexte>      m_boutonTexte;    ///< Un simple bouton rectangulaire.
    std::shared_ptr<gui::BtnRectangle>  m_boutonRect;    ///< Un simple bouton rectangulaire.
    std::shared_ptr<gui::BtnMenu>       m_boutonMenu;    ///< Un bouton Menu.

    // DONNEE
    std::shared_ptr<gui::DnCaseACocher>  m_boutonCoche;    ///< Un bouton Menu.
    std::shared_ptr<gui::DnZoneTexte>    m_zoneTexte;    ///< Un champ de texte.
    std::shared_ptr<gui::DnSlider>          m_slider;           ///< Un slider.
//    std::shared_ptr<gui::DnBarreDefilement> m_barreDefil;    ///< Un slider.

}; // fin EcranDemo
}; // fin app
#endif // ECRANDEMO_H
