#ifndef CMPFOND_H
#define CMPFOND_H

#include <SFML/Graphics.hpp>

#include "Composant.h"
#include "Valeurs.h"

#include "gadgets/AffRectangle.h"

namespace gui {

class CmpFond : public Composant
{
private:
public:
    CmpFond();


public:
    void setFondCouleur         ( sf::Color couleur  );
    void setFondCouleur         ( sf::Color couleur , Etat etat );
    void setFondCouleur         ( Valeurs<sf::Color> couleurs  );

    void setFondLigneCouleur    ( sf::Color couleur  );
    void setFondLigneCouleur    ( sf::Color couleur , Etat etat );
    void setFondLigneCouleur    ( Valeurs<sf::Color> couleurs );

    void setFondLigneEpaisseur  ( float epaisseur );
    void setFondLigneEpaisseur  ( float epaisseur , Etat etat );
    void setFondLigneEpaisseur  ( Valeurs<float> epaisseur );

    virtual void appliquerEtat( Etat etat );
protected :
    /////////////////////////////////////////////////
    virtual void initialiserComposants ( Gadget*     base );

////////////////////////////////// ///////////////
// Membres
/////////////////////////////////////////////////
protected:

    // les composants de l'interface du gadget
    std::shared_ptr<AffRectangle>    m_fond;

    // les proprietés graphiques
    Valeurs<sf::Color>      m_couleurFond;
    Valeurs<sf::Color>      m_couleurLignes;
    Valeurs<float>          m_epaisseur;

};// fin CmpFond

}; // fin namespace gui

#endif // COMPFOND_H
