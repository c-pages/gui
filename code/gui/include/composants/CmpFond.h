#ifndef CMPFOND_H
#define CMPFOND_H

#include <Composant.h>

namespace gui {

class CmpFond : public Composant
{
private:
    CmpFond();

public:
    void setFondCouleur         (sf::Color  couleur     );
    void setFondLigneCouleur    (sf::Color  couleur     );
    void setFondLigneEpaisseur  (float      epaisseur   );

protected:
    // les composants de l'interface du gadget
    std::shared_ptr<AffRectangle>    m_fond;

    // les proprietés graphiques
    sf::Color  m_couleurFond;
    sf::Color  m_couleurLignes;
    float      m_epaisseur;

};// fin CmpFond

}; // fin namespace gui

#endif // COMPFOND_H
