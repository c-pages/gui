/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <DnCaseACocher.h>
#include <Interface.h>



namespace gui {

/////////////////////////////////////////////////
DnCaseACocher::DnCaseACocher ()
: m_bouton ( std::make_shared<BtnRectangle>() )
, m_coche  ( std::make_shared<AffRectangle>() )
, m_label  ( std::make_shared<AffLabel>() )
{
    // initialiser quelques valeurs
    m_marge.x = m_marge.y = 3;
    m_taille.x = 12;
    m_taille.y = 12;
    m_valeur = true;


    // le bouton
    m_bouton->setTexte ("");

    // valeurs par defaut
    m_btnCouleurs.set       ( sf::Color( 0, 0, 0, 50 )  , Etat::desactive );
    m_btnCouleurs.set       ( sf::Color( 255,255,255, 50 )  , Etat::repos );
    m_btnCouleurs.set       ( sf::Color( 255,255,255, 100 ) , Etat::survol );
    m_btnCouleurs.set       ( sf::Color( 255,255,255, 150 ) , Etat::press );
    m_btnLgnCouleurs.set    ( sf::Color( 255,255,255, 100 ) );
    m_btnLgnepaisseurs.set  ( 0 );

    m_cocheCouleurs          = sf::Color(255,255,255,200) ;
    m_cocheCouleurs.set      ( sf::Color( 70, 70, 70 )  , Etat::desactive );
    m_cocheLgnCouleurs       = sf::Color( 255,255,0, 255 ) ;
    m_cocheLgnepaisseurs     = 0 ;

    m_textCouleur = sf::Color::White ;
    m_textTaille =  12  ;
    m_textPolice = Interface::ms_polices.get( "Defaut" )  ;
    m_textStyle = sf::Text::Style::Regular  ;

    // creer l'interface
    ajouterComposant( m_bouton );
    ajouterComposant( m_coche );
    ajouterComposant( m_label );

    // Declaration des fonctions de fonctionnement de l'interface interne du gadget.
    fn_basculerValeur = [this](){
        // On inverse le boolean valeur
        m_valeur = !m_valeur;

        // Déclechements des evenements
        declencher(Evenement::on_valeurChange);
        if (m_valeur)   declencher(Evenement::onBool_allume);
        else            declencher(Evenement::onBool_eteind);

        actualiser ();
    };

    // Action du bouton
    m_bouton->lier ( Evenement::onBtnG_relacher , fn_basculerValeur );

    actualiser ();

}



/////////////////////////////////////////////////
void DnCaseACocher::actualiserBounds() {
    m_globalBounds.left = getPosAbs().x;
    m_globalBounds.top = getPosAbs().y;
    m_globalBounds.width = m_taille.x + m_label->getTaille().x + 2*m_marge.x;
    m_globalBounds.height = m_taille.y;
};


/////////////////////////////////////////////////
void DnCaseACocher::actualiserGeometrie ()
{
    m_label->setTexte ( m_texte );
    m_label->setPosition ( m_taille.x + 2*m_marge.x , 0 );

    m_bouton->setTaille  ( m_taille );

    m_coche->setTaille   ( { m_taille.x - 2*m_marge.x , m_taille.y - 2*m_marge.y } );
    m_coche->setPosition ( m_marge.x , m_marge.y );

    actualiserBounds();
}


/////////////////////////////////////////////////
void DnCaseACocher::actualiserStyle ()
{

    if ( ! m_valeur ) {
        m_coche->setFillColor ( m_cocheCouleurs.desactive  );
        m_coche->setOutlineColor (  m_cocheLgnCouleurs.desactive );
        m_coche->setOutlineThickness ( m_cocheLgnepaisseurs.desactive  );
    } else {
        m_coche->setFillColor ( m_cocheCouleurs.press );
        m_coche->setOutlineColor (  m_cocheLgnCouleurs.press);
        m_coche->setOutlineThickness ( m_cocheLgnepaisseurs.press );
    }

    m_label->setTexteCouleur    ( sf::Color (   m_textCouleur.r
                                            ,   m_textCouleur.g
                                            ,   m_textCouleur.b
                                            ,   m_textCouleur.a * m_opacite ) ) ;
    m_label->setTexteTaille     ( m_textTaille ) ;
    m_label->setPolice          ( m_textPolice ) ;
    m_label->setTexteStyle      ( m_textStyle ) ;


    m_bouton->setFillColor (    m_btnCouleurs ) ;
    m_bouton->setOutlineColor (    m_btnLgnCouleurs  ) ;
    m_bouton->setOutlineThickness ( m_btnLgnepaisseurs  );

}


/*
/////////////////////////////////////////////////
void DnCaseACocher::actualiser ()
{
    m_label->setTexte ( m_texte );
    m_label->setStyle ( m_skin->getStyle( Styles::btnCoche ) );
    m_label->setPosition ( m_taille.x + 2*m_marge.x , 0 );

    m_bouton->setTaille  ( m_taille );
    m_bouton->setStyle   ( m_skin->getStyle( Styles::bouton ) );

    m_coche->setTaille   ( { m_taille.x - 2*m_marge.x , m_taille.y - 2*m_marge.y } );
    m_coche->setPosition ( m_marge.x , m_marge.y );

    auto style = m_skin->getStyle( Styles::btnCoche );
    m_coche->setStyle    ( style );

    if ( ! m_valeur ) {
        m_coche->setFillColor ( style->getFnd_couleur( Etat::desactive ) );
        m_coche->setOutlineColor (  style->getLgn_couleur( Etat::desactive ));
        m_coche->setOutlineThickness ( style->getLgn_epaisseur( Etat::desactive ) );
    } else {
        m_coche->setFillColor ( style->getFnd_couleur( Etat::press ) );
        m_coche->setOutlineColor (  style->getLgn_couleur( Etat::press ));
        m_coche->setOutlineThickness ( style->getLgn_epaisseur( Etat::press ) );
    }
    actualiserBounds();

    if ( m_parent != nullptr ) m_parent->actualiserContenu();
}
*/

/////////////////////////////////////////////////
std::shared_ptr<Gadget>  DnCaseACocher::testerSurvol ( sf::Vector2i position )
{
    // on test sur le bouton et le texte
    if ( m_globalBounds.contains( { position.x , position.y} ) )
        return m_bouton;

    return nullptr;
}


} // fin namespace gui

