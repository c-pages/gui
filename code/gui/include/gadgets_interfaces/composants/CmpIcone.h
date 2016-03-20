#ifndef CMPICONE_H
#define CMPICONE_H

#include "Composant.h"
#include "gadgets/AffIcone.h"


namespace gui {

class CmpIcone : public Composant
{
public:

    CmpIcone();


    /////////////////////////////////////////////////
    void setIndex ( unsigned int val );

    /////////////////////////////////////////////////
    void setImage ( std::string fichier );

    /////////////////////////////////////////////////
    void setImage ( sf::Texture* texture );

protected :
    /////////////////////////////////////////////////
    virtual void initialiserComposants ( Gadget*     base );


/////////////////////////////////////////////////
// les membres
/////////////////////////////////////////////////
protected:

    // les composants de l'interface du gadget
    std::shared_ptr<AffIcone>    m_icone;

};

};
#endif // CMPICONE_H
