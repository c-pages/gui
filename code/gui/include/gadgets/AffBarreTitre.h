#ifndef AFFBARRETITRE__H
#define AFFBARRETITRE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Affiche.h"
#include "AffRectangle.h"
#include "AffLabel.h"
#include "AffIcone.h"
#include <memory>



namespace gui {


/////////////////////////////////////////////////
/// \brief Classe concrète d'affichage d'une barre de titre
///
/////////////////////////////////////////////////
class AffBarreTitre : public Affiche {


/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////
public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /////////////////////////////////////////////////
    AffBarreTitre ();

    void setIconeImage ( const sf::Texture* texture  );

    void setIconeImage ( std::string texture  );

    void setIconeIndex (int index);

    virtual void setTexte (std::string texte);

    /////////////////////////////////////////////////
    virtual void actualiserGeometrie ();

    /////////////////////////////////////////////////
    virtual void actualiserStyle ();

//    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;


/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:

    // les composants de l'interface du gadget
    std::shared_ptr<AffRectangle>   m_fond;
    std::shared_ptr<AffLabel>       m_titre;
    std::shared_ptr<AffIcone>       m_icone;

    // les proprietés graphiques
    sf::Color           m_textCouleur;
    sf::Text::Style     m_textStyle;
    float               m_textTaille;
    sf::Font            m_textPolice;

    sf::Color           m_fndCouleur;
    sf::Color           m_fndLignesCouleur;
    float               m_fndLignesEpaisseur;

}; // fin class AffBarreTitre

} // fin namespace gui

#endif
