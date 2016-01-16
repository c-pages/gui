#ifndef BOUTON__H
#define BOUTON__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Gadget.h"
#include <memory>



namespace gui {

class Label;
class Image;
class ptr;


/////////////////////////////////////////////////
/// \brief Un bouton
///
/////////////////////////////////////////////////
class Bouton : public gui::Gadget {


/////////////////////////////////////////////////
// Enums & typedefs
/////////////////////////////////////////////////
    typedef std::shared_ptr<Bouton> ptr;    ///< Pointeur vers un bouton.


/////////////////////////////////////////////////
// M�thodes
/////////////////////////////////////////////////

public:
    ///< Definir m_label
    void setLabel( std::shared_ptr<Label> val ){ m_label = val; };

    ///< Acceder � m_label
    std::shared_ptr<Label> getLabel () const { return m_label; };

    ///< Definir m_icone
    void setIcone( std::shared_ptr<Image> val ){ m_icone = val; };

    ///< Acceder � m_icone
    std::shared_ptr<Image> getIcone () const { return m_icone; };

public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par d�faut.
    ///
    /// \param parent		 Le parent du gadget.
    /////////////////////////////////////////////////
    Bouton (Gadget::ptr parent);

    /////////////////////////////////////////////////
    /// \brief A d�clencher quand le bouton gauche de la souris est press� sur le gadget.
    ///
    /////////////////////////////////////////////////
    virtual void presserBoutonGauche ();

    /////////////////////////////////////////////////
    /// \brief A d�clencher quand le bouton gauche de la souris est relach� sur le gadget.
    ///
    /////////////////////////////////////////////////
    virtual void relacherBoutonGauche ();

    /////////////////////////////////////////////////
    /// \brief A d�clencher quand la souris entre sur le gadget.
    ///
    /////////////////////////////////////////////////
    virtual void sourisEntre ();

    /////////////////////////////////////////////////
    /// \brief A d�clencher quand la souris sort du gadget.
    ///
    /////////////////////////////////////////////////
    virtual void sourisSort ();

    virtual void setTexte (std::string texte);

    virtual void setTaille (Vec2 taille) = 0;



/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:
    std::shared_ptr<Label> m_label;    ///< Le texte du bouton.
    std::shared_ptr<Image> m_icone;    ///< L'icone du bouton.
    friend class BoutonRendu;

}; // fin class Bouton

} // fin namespace gui

#endif
