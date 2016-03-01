#ifndef DNLISTEDEROULANTE__H
#define DNLISTEDEROULANTE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Donnee.h"



namespace gui {



/////////////////////////////////////////////////
/// \brief Une liste pour choisir une entr�e dans un enum.
///
/////////////////////////////////////////////////
class DnListeDeroulante : public gui::Donnee {



/////////////////////////////////////////////////
// M�thodes
/////////////////////////////////////////////////
public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par d�faut.
    ///
    /////////////////////////////////////////////////
    DnListe ();

    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;


}; // fin class DnListeDeroulante

} // fin namespace gui

#endif
