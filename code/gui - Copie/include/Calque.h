#ifndef CALQUE_H
#define CALQUE_H

#include "Gadget.h"

namespace gui {

class Calque : public Gadget
{
    public:
        Calque();
        virtual ~Calque();


    /////////////////////////////////////////////////
    std::shared_ptr<Gadget>  testerSurvol ( sf::Vector2i position );


    protected:
    private:
};

};


#endif // CALQUE_H
