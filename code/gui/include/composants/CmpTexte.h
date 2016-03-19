#ifndef CMPTEXTE_H
#define CMPTEXTE_H

#include <Composant.h>

namespace gui {

class CmpTexte : public Composant
{
private:

    CmpTexte();

public:

    virtual void setTexte( std::string val );                           ///< Definir m_texte

    void setTailleCharac( float val , Etat etat = Etat::tous );         ///< Definir m_texteTaille
    void setTailleCharac( Valeurs<float> val );                         ///< Definir m_texteTaille

    void setTexteCouleur( sf::Color couleur , Etat etat = Etat::tous);  ///< Definir m_police
    void setTexteCouleur( Valeurs<sf::Color> couleur  );                ///< Definir m_police

    void setTextePolice( sf::Font val , Etat etat = Etat::tous);        ///< Definir m_police
    void setTextePolice( Valeurs<sf::Font> val  );                      ///< Definir

    void setTexteStyle( sf::Text::Style val , Etat etat = Etat::tous);  ///< Definir
    void setTexteStyle( Valeurs<sf::Text::Style> val  );                ///< Definir

protected:

    std::shared_ptr<AffLabel>       m_label;

    // les proprietés graphiques
    Valeurs<sf::Color>              m_textCouleur;
    Valeurs<sf::Text::Style>        m_textStyle;
    Valeurs<float>                  m_textTaille;
    Valeurs<sf::Font>               m_textPolice;

};

};

#endif // CMPTEXTE_H
