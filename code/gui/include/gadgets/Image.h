#ifndef IMAGE__H
#define IMAGE__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Gadget.h"



namespace gui {



/////////////////////////////////////////////////
/// \brief Une simple image.
///
/////////////////////////////////////////////////
class Image : public gui::Gadget {



/////////////////////////////////////////////////
// M�thodes
/////////////////////////////////////////////////
public:
    void draw (sf::RenderTarget& target, sf::RenderStates states) const;


}; // fin class Image

} // fin namespace gui

#endif
