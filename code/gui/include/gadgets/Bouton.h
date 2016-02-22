#ifndef BOUTON__H
#define BOUTON__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Cliquable.h"
#include <AffLabel.h>
#include <AffImage.h>
#include <AffRectangle.h>

#include <memory>



namespace gui {

//class AffLabel;
//class AffImage;
//class AffRectangle;


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
    virtual void setTexte ( std::string val ) ;


public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /////////////////////////////////////////////////
    Bouton (  );

//    /////////////////////////////////////////////////
//    /// \brief Constructeur par défaut.
//    ///
//    /// \param parent
//    /////////////////////////////////////////////////
//    Bouton (ptr parent);

//    ~Bouton()=default;

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
    void ajusterAuTexte ();



/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:

//    std::shared_ptr<AffLabel>           m_label = std::make_shared<AffLabel>();         ///< Le label qui affiche le texte du bouton.
//    AffImage*       m_icone;        ///< L'icone du bouton.
    std::shared_ptr<AffRectangle>       m_rectangle/* = std::make_shared<AffRectangle>()*/;    ///< Le rectangle du bouton.

    sf::Vector2f    m_marge;            ///< La marge entre le texte et le bord du rectangle.

    sf::Color       m_couleurRepos;     ///<
    sf::Color       m_couleurSurvol;    ///<
    sf::Color       m_couleurFocus;     ///<

}; // fin class Bouton

} // fin namespace gui

#endif
