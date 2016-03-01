#ifndef REPARTITEUR__H
#define REPARTITEUR__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <SFML/Graphics.hpp>



namespace gui {



class Repartiteur {



/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////

public:
    ///< Definir m_espacement
    void setEspacement( sf::Vector2i val ){ m_espacement = val; };

    ///< Acceder à m_espacement
    sf::Vector2i getEspacement () const { return m_espacement; };

public:
    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /////////////////////////////////////////////////
    Repartiteur ();

    virtual void repartir (std::vector<std::shared_ptr<Gadget>> groupe) = 0;



/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:
    sf::Vector2i m_espacement;    ///< #G#S    

}; // fin class Repartiteur

} // fin namespace gui

#endif
