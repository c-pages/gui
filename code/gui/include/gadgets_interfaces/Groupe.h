#ifndef GROUPE_H
#define GROUPE_H

#include <Gadget.h>

namespace gui {


/////////////////////////////////////////////////
/// \brief Permet juste d'assembler de manière invisible des gadgets entre eux
///
/////////////////////////////////////////////////
class Groupe : public Gadget
{
    public:
        /** Default constructor */
        Groupe();
        /** Default destructor */
        virtual ~Groupe();
    /////////////////////////////////////////////////
    virtual void actualiserGeometrie ()    {
        getParent()->actualiserGeometrie();
    };

    /////////////////////////////////////////////////
    virtual sf::Vector2i getTaille () const;
//    /////////////////////////////////////////////////
//    virtual void actualiserStyle ()
//    {};

    protected:
    private:


};



}; // fin namespace gui

#endif // GROUPE_H
