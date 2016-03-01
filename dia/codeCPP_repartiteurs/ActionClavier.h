#ifndef ACTIONCLAVIER__H
#define ACTIONCLAVIER__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <map>
#include <SFML/Graphics.hpp>
#include <functional>



namespace gui {



/////////////////////////////////////////////////
/// \brief Classe abstraite qui g�re les �venements clavier.
///
/////////////////////////////////////////////////
class ActionClavier {


/////////////////////////////////////////////////
// Enums & typedefs
/////////////////////////////////////////////////
    using FctnAction = std::function<void()>;    ///< le type de fonction associ� aux declenchements des evenements.


/////////////////////////////////////////////////
// M�thodes
/////////////////////////////////////////////////

public:
public:
    /////////////////////////////////////////////////
    /// \brief Cr�er une nouvelle liaison entre un evenement clavier  et une fonction lambda.
    ///
    /// \param touche		 la touche du clavier.
    /// \param fonction		 Le fonction � d�clencher.
    /////////////////////////////////////////////////
    void lier ( sf::Keyboard  touche, FctnAction fonction);

    /////////////////////////////////////////////////
    /// \brief Supprime une liaison entre un evenement clavier  et une fonction lambda.
    ///
    /// \param touche		 
    /////////////////////////////////////////////////
    void delier ( sf::Keyboard  touche);

protected:
    /////////////////////////////////////////////////
    /// \brief D�clencher un �venement souris (les �venement claviers sont g�rer.
    ///
    /// \param touche		 La touche enregistr�e � une action.
    /////////////////////////////////////////////////
    void declencher (sf::Keyboard touche);

    /////////////////////////////////////////////////
    /// \brief V�rifie s'il a des actions a lancer suite � un �venemnt clavier.
    ///
    /// \param evenement		 
    /////////////////////////////////////////////////
    traiterEvenement (sf::Event evenement);



/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:
    std::map < sf::Keyboard  , FctnAction > m_evenementsClavier;    ///<  la liste des evenements claviers enregistr�s.    

}; // fin class ActionClavier

} // fin namespace gui

#endif
