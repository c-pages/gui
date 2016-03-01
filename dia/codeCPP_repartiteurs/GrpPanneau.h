#ifndef GRPPANNEAU__H
#define GRPPANNEAU__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include "Groupement.h"
#include <memory>
#include <SFML/Graphics.hpp>



namespace gui {

class AffRectangle;
class AffRectangle;
class Repartiteur;


class GrpPanneau : public gui::Groupement {


/////////////////////////////////////////////////
// Enums & typedefs
/////////////////////////////////////////////////
    /////////////////////////////////////////////////
    /// \brief 
    /////////////////////////////////////////////////
    enum Repartitions {
        Libre,
        Verticale,
        Horizontale,
        Grille
    };



/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////

public:
    ///< Definir m_repartiteur
    void setRepartiteur( Repartiteur val ){ m_repartiteur = val; };

public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /////////////////////////////////////////////////
    GrpPanneau ();

    /////////////////////////////////////////////////
    /// \brief  
    ///
    /// \param repartition		 
    /////////////////////////////////////////////////
    setRepart (Repartition repartition);

    /////////////////////////////////////////////////
    /// \brief Actualise le repartiteur puis les gadgets enfant contenus.
    ///
    /////////////////////////////////////////////////
    virtual void actualiser ();

    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;



/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:
    std::shared_ptr<AffRectangle> m_fond;    
    std::shared_ptr<BtnBarreDefilement> m_slider_V;    
    std::shared_ptr<BtnBarreDefilement> m_slider_H;    
    std::shared_ptr<AffRectangle> m_contenant;    ///< Le rectangle sur lequel on applique la texture qui affiche le contenu.    
    sf::Texture m_contenu;    ///< La texture SFML qui affiche le contenu du panneau.    
    Repartiteur m_repartiteur;    ///< cf; GOF Strategie #S    
    bool m_afficherSlider_V;    
    bool m_afficherSlider_H;    

}; // fin class GrpPanneau

} // fin namespace gui

#endif
