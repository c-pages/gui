#ifndef GROUPE_H
#define GROUPE_H

#include <Gadget.h>

namespace gui {

class Groupe : public Gadget
{
    public:
        /** Default constructor */
        Groupe();
        /** Default destructor */
        virtual ~Groupe();
   /* /////////////////////////////////////////////////
    virtual void actualiserGeometrie ()
    {
        actualiserEnfants();
    };*/

//    /////////////////////////////////////////////////
//    virtual void actualiserStyle ()
//    {};

    protected:
    private:


};



}; // fin namespace gui

#endif // GROUPE_H
