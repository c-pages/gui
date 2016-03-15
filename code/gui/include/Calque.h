#ifndef CALQUE_H
#define CALQUE_H

#include "Gadget.h"

namespace gui {

class Calque : public Gadget
{
public:
    Calque( std::string nom );
    virtual ~Calque();


    /////////////////////////////////////////////////
    std::shared_ptr<Gadget>  testerSurvol ( sf::Vector2i position );

/*    virtual std::string     getHierarchie() const { return ""; };

    virtual std::string     getNom() const {
        std::string nom = m_nom;
        nom.erase(0, 1);
        return nom ;
    };*/

protected:
private:


};

};


#endif // CALQUE_H
