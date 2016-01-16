#ifndef LABEL__H
#define LABEL__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Gadget.h"
#include <memory>



namespace gui {



/////////////////////////////////////////////////
/// \brief Un simple label.
///
/////////////////////////////////////////////////
class Label : public gui::Gadget {


/////////////////////////////////////////////////
// Enums & typedefs
/////////////////////////////////////////////////
    typedef std::shared_ptr<Label> ptr;    ///< Pointeur vers un label.


/////////////////////////////////////////////////
// M�thodes
/////////////////////////////////////////////////

public:
public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par d�faut.
    ///
    /// \param parent		 Le parent du gadget.
    /////////////////////////////////////////////////
    Label (Gadget::ptr parent);

    virtual void setTexte (std::string texte) = 0;

    virtual void setTailleTexte (float taille) = 0;

    void draw (sf::RenderTarget& target, sf::RenderStates states) const;



/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:
    friend class LabelRendu;

}; // fin class Label

} // fin namespace gui

#endif
