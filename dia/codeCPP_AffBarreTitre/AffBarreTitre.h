#ifndef AFFBARRETITRE__H
#define AFFBARRETITRE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Affiche.h"
#include <memory>



namespace gui {



/////////////////////////////////////////////////
/// \brief Classe concrète d'affichage d'une barre de titre
///
/////////////////////////////////////////////////
class AffBarreTitre : public gui::Affiche {



/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////

public:
public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /////////////////////////////////////////////////
    AffBarreTitre ();

    void setIcone ();

    void setIconeIndex (int index);

    virtual void setTexte (std::string texte);

    virtual void actualiser ();

    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;



/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:
    std::shared_ptr<AffRectangle> m_rectangle;    
    std::shared_ptr<AffLabel> m_titre;    
    std::shared_ptr<AffIcone> m_icone;    

}; // fin class AffBarreTitre

} // fin namespace gui

#endif
