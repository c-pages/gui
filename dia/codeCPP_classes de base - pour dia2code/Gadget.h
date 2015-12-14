#ifndef GADGET__H
#define GADGET__H

/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////



namespace gui {



class Gadget {



/////////////////////////////////////////////////
// Méthodes
/////////////////////////////////////////////////

public:
    ///< Definir m_visible
    void setVisible( bool val ){ m_visible = val; };

    ///< Acceder à m_visible
    bool getVisible () const { return m_visible; };

    ///< Definir m_actif
    void setActif( bool val ){ m_actif = val; };

    ///< Acceder à m_actif
    bool getActif () const { return m_actif; };

protected:
    /////////////////////////////////////////////////
    /// \brief Dessiner le gadget => dessiner ses enfants.
    ///
    /// \param target		 
    /// \param states		 
    /////////////////////////////////////////////////
    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;

    /////////////////////////////////////////////////
    /// \brief  Traitement des évènements  du gadget.
    ///
    /// \param evenement		 L'evenemnt SFML à traiter.
    /////////////////////////////////////////////////
    virtual void traiter_events (const sf::Event& evenement);

    /////////////////////////////////////////////////
    /// \brief Actualiser les géométrie du gadgets avec skin, et donc ses bounds.
    ///
    /////////////////////////////////////////////////
    virtual void actualiser () = 0;

    /////////////////////////////////////////////////
    /// \brief Initialise les interactions des composant du gadgets.
    ///
    /////////////////////////////////////////////////
    virtual void initialiser_interactions () = 0;

    /////////////////////////////////////////////////
    /// \brief Initialise les composant du gadgets.
    ///
    /////////////////////////////////////////////////
    virtual void initialiser_composants () = 0;

    /////////////////////////////////////////////////
    /// \brief Initialiser les composants, les interactions (GOF4 : Patron de méthode).
    ///
    /////////////////////////////////////////////////
    void initialiser ();

public:
    /////////////////////////////////////////////////
    /// \brief Surcharge de l'operateur =.
    ///
    /// \param original		 
    /////////////////////////////////////////////////
    Gadget& operator= (Gadget & original);

    /////////////////////////////////////////////////
    /// \brief Constructeur de recopie (pour gerer les pointeurs).
    ///
    /// \param original		 Le gadget a recopier.
    /////////////////////////////////////////////////
    Gadget (Gadget & original);

    /////////////////////////////////////////////////
    /// \brief Constructeur par défaut.
    ///
    /////////////////////////////////////////////////
    Gadget ();



/////////////////////////////////////////////////
// Membres
/////////////////////////////////////////////////
private:
    bool m_visible;    ///< est il visible ? ( si non visible : inactif ?) (#G#S)    
    bool m_actif;    ///< le gadget est il actif ? (#G#S)    

}; // fin class Gadget

} // fin namespace gui

#endif
