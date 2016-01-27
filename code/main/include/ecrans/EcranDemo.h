#ifndef ECRANDEMO_H
#define ECRANDEMO_H

/////////////////////////////////////////////////
//  Headers
/////////////////////////////////////////////////
#include    <SFML/Graphics.hpp>
#include    <Ecran.h>
#include    <Application.h>
#include    <GUI.h>
#include    <Interface.h>

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

    sf::RectangleShape                  m_fond;     ///< Le shape SFML du fond de l'�cran.

    std::shared_ptr<gui::Interface>     m_interface;      ///< Le groupe de GUI du menu principal.
    /*std::shared_ptr<gui::Label >        labelTest;
    std::shared_ptr<gui::Bouton >       bouton1;
    std::shared_ptr<gui::Bouton >       bouton2;*/

//std::shared_ptr<gui::ChampTexte>  m_champ ;
    //std::shared_ptr<Gadget>

}; // fin EcranDemo
}; // fin app
#endif // ECRANDEMO_H
