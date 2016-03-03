/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <DnCaseACocher.h>



namespace gui {

/////////////////////////////////////////////////
DnCaseACocher::DnCaseACocher ()
: m_bouton ( std::make_shared<BtnRectangle>() )
, m_coche  ( std::make_shared<AffRectangle>() )
, m_label  ( std::make_shared<AffLabel>() )
{
    // initialiser quelques valeurs
    m_marge.x = m_marge.y = 4;
    m_taille.x = 15;
    m_taille.y = 15;

    // le bouton
    m_bouton->setTexte ("");

    ajouterComposant( m_bouton );
    ajouterComposant( m_coche );
    ajouterComposant( m_label );

    // Action du bouton
    m_bouton->lier ( Evenement::onBtnG_relacher , [this](){

        // On inverse le boolean valeur
        m_valeur = !m_valeur;

        // Déclechements des evenements
        declencher(Evenement::on_changerValeur);
        if (m_valeur)
            declencher(Evenement::onBool_allume);
        else
            declencher(Evenement::onBool_eteind);


        actualiser ();
    });

    actualiser ();
}



/////////////////////////////////////////////////
void DnCaseACocher::actualiser_bounds() {
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

    actualiser_bounds();
}


/////////////////////////////////////////////////
void DnCaseACocher::actualiserStyle ()
{

    m_label->setStyle ( m_skin->getStyle( Styles::btnCoche ) );

    m_bouton->setStyle   ( m_skin->getStyle( Styles::bouton ) );

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
    actualiser_bounds();

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

