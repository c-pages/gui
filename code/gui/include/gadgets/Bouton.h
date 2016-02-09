#ifndef BOUTON__H
#define BOUTON__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Cliquable.h"
#include <memory>



namespace gui {

class AffLabel;
class AffImage;
class AffRectangle;


/////////////////////////////////////////////////
/// \brief Un simple bouton
///
/////////////////////////////////////////////////
class Bouton : public Cliquable {



/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////

public:
    ///< Definir m_texte
    virtual void setTexte( std::string val ) ;


public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /////////////////////////////////////////////////
    Bouton (  );

    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /// \param parent
    /////////////////////////////////////////////////
    Bouton (ptr parent);

    ~Bouton()=default;

    void initialiser_composants ();



    /////////////////////////////////////////////////
    /// \brief Dessiner le gadget => dessiner ses enfants.
    ///
    /// \param target
    /// \param states
    /////////////////////////////////////////////////
//    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;


    virtual void actualiser( sf::Time delta );



    /////////////////////////////////////////////////
    /// \brief Pour ajuster la taille du rectangle au texte.
    ///
    /////////////////////////////////////////////////
    void ajusterRectangleAuTexte ();



/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:

    std::shared_ptr<AffLabel>       m_label;        ///< Le label qui affiche le texte du bouton.
    std::shared_ptr<AffImage>       m_icone;        ///< L'icone du bouton.
    std::shared_ptr<AffRectangle>   m_rectangle;    ///< Le rectangle du bouton.

    sf::Vector2f                    m_marge;        ///< La marge entre le texte et le bord du rectangle.

}; // fin class Bouton

} // fin namespace gui

#endif
