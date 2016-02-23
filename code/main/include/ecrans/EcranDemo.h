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
/// \brief  Ecran de d�monstration
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
    /// \brief La gestion des �v�nements utilisateurs.
    ///
    /// \details  G�re les entr�es claviers, souris, fenetre ...
    /// \return Rien
    ///
    /////////////////////////////////////////////////
    virtual     void traiter_evenements ( const sf::Event& event );

    /////////////////////////////////////////////////
    /// \brief Actualiser les �l�ments.
    ///
    /// \details Actualiser les diff�rents �l�ments du ou des �crans actifs.
    /// \param   deltaT Un \e float qui indique le delta du temps �coul� depuis la derni�re actualisation.
    /// \return  Rien
    ///
    /////////////////////////////////////////////////
    virtual     void actualiser ( float deltaT );

    /////////////////////////////////////////////////
    /// \brief Rendre les �l�ments.
    ///
    /// Dessiner les diff�rents �l�ments du ou des �crans actifs.
    /// \return Rien
    ///
    /////////////////////////////////////////////////
    virtual     void dessiner  ( );

    /////////////////////////////////////////////////
    /// \brief Fonction a supprimer
    ///
    /// juste l� pour tester des machins bidules.
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
    /// Creation des fen�tres, boutons, menus... ...
    /// \return Rien
    ///
    /////////////////////////////////////////////////
    virtual     void initGUI ();

private:

    /////////////////////////////////////////////////
    // Les membres
    /////////////////////////////////////////////////

    sf::RectangleShape                  m_fond;         ///< Le shape SFML du fond de l'�cran.

    // l'interface g�rant le tout
    std::shared_ptr<gui::Interface>     m_interface;    ///< Le groupe de GUI du menu principal.

    // un skin permettant de g�rer le rendu
    std::shared_ptr<gui::Skin>          m_skin;         ///< Un skin.

    // les gadgets
    std::shared_ptr<gui::AffRectangle>  m_rectangle;    ///< Un simple rectangle.

    std::shared_ptr<gui::AffLabel>      m_label;        ///< Un simple label.

    std::shared_ptr<gui::AffImage>      m_image;        ///< Une simple image.


}; // fin EcranDemo
}; // fin app
#endif // ECRANDEMO_H
