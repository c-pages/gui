#ifndef GADGETRENDU__H
#define GADGETRENDU__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <memory>
#include "Gadget.h"



namespace gui {



/////////////////////////////////////////////////
/// \brief Le rendu du gadget.
///
/////////////////////////////////////////////////
class GadgetRendu {


/////////////////////////////////////////////////
// Enums & typedefs
/////////////////////////////////////////////////
    typedef std::shared_ptr<GadgetRendu> ptr;    ///< Pointeur vers un rendu de gadget.


/////////////////////////////////////////////////
// M�thodes
/////////////////////////////////////////////////

public:
public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par d�faut.
    ///
    /// \param gadgetSource		 Le gadget source.
    /////////////////////////////////////////////////
    GadgetRendu (Gadget::ptr gadgetSource);

    /////////////////////////////////////////////////
    /// \brief Dessine le rendu du gadget.
    ///
    /// \param target
    /// \param states
    /////////////////////////////////////////////////
    void draw (sf::RenderTarget& target, sf::RenderStates states) const;

    virtual void actualiser (sf::Time tempsEcoule);



/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
public:
    Gadget::ptr m_gadget;

}; // fin class GadgetRendu

} // fin namespace gui

#endif
