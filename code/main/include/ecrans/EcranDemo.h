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

    void initGUI_test_Affichages ();
    void initGUI_test_Boutons ();


private:

    /////////////////////////////////////////////////
    // Les membres
    /////////////////////////////////////////////////

    sf::RectangleShape                  m_fond;         ///< Le shape SFML du fond de l'écran.

    // l'Interface gérant l'interface ^^
    std::shared_ptr<gui::Interface>     m_interface;    ///< Le groupe de GUI du menu principal.

    // un skin permettant de gérer le rendu
    std::shared_ptr<gui::Skin>          m_skin;         ///< Un skin.

    // AFFICHAGE
    std::shared_ptr<gui::AffRectangle>  m_rectangle;    ///< Un simple rectangle.

    std::shared_ptr<gui::AffLabel>      m_labelRetour;        ///< Un simple label.

    std::shared_ptr<gui::AffLabel>      m_label;        ///< Un simple label.
    std::shared_ptr<gui::AffLabel>      m_label_2;      ///< Un autre label.
    std::shared_ptr<gui::AffLabel>      m_label_3;      ///< Un autre label.
    std::shared_ptr<gui::AffLabel>      m_label_4;      ///< Un autre label.
    std::shared_ptr<gui::AffLabel>      m_label_5;      ///< Un autre label.
    std::shared_ptr<gui::AffLabel>      m_label_6;      ///< Un autre label.
    std::shared_ptr<gui::AffLabel>      m_label_7;      ///< Un autre label.
    std::shared_ptr<gui::AffImage>      m_image;        ///< Une simple image.

    // BOUTON
    std::shared_ptr<gui::BtnRectangle>    m_boutonRect;    ///< Un simple bouton rectangulaire.
    std::shared_ptr<gui::BtnMenu>         m_boutonMenu;    ///< Un bouton Menu.

    // DONNEE
    std::shared_ptr<gui::DnCaseACocher>  m_boutonCoche;    ///< Un bouton Menu.


}; // fin EcranDemo
}; // fin app
#endif // ECRANDEMO_H
