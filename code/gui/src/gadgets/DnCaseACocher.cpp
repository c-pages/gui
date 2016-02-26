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
    m_marge.x = m_marge.y = 3;
    m_taille.x = 15;
    m_taille.y = 15;

    // le bouton
    m_bouton->setTexte ("");
    m_bouton->setParent  (this);

    // Action du bouton
    m_bouton->lier ( Evenement::onBtnG_relacher , [this](){
        m_valeur = !m_valeur;
        // Déclechements
        declencher(Evenement::on_changerValeur);
        if (m_valeur)
            declencher(Evenement::onBool_allume);
        else
            declencher(Evenement::onBool_eteind);
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
void DnCaseACocher::actualiser ()
{
    m_label->setTexte ( m_texte );
    m_label->setStyle ( m_skin->btnCoche );
    m_label->setPosition ( m_taille.x + 2*m_marge.x , 0 );

    m_bouton->setTaille  ( m_taille );
    m_bouton->setStyle   ( m_skin->bouton );

    m_coche->setTaille   ( { m_taille.x - 2*m_marge.x , m_taille.y - 2*m_marge.y } );
    m_coche->setPosition ( m_marge.x , m_marge.y );
    m_coche->setStyle    ( m_skin->btnCoche );

    actualiser_bounds();
}


/////////////////////////////////////////////////
std::shared_ptr<Gadget>  DnCaseACocher::testerSurvol ( sf::Vector2i position )
{
    if ( m_globalBounds.contains( { position.x , position.y} ) )
        return m_bouton;

    return nullptr;
}


/////////////////////////////////////////////////
void DnCaseACocher::draw (sf::RenderTarget& target, sf::RenderStates states) const
{
    //On applique la transformation
    states.transform *= getTransform();

    // On dessine les éléments
    target.draw(*m_bouton, states);
    target.draw(*m_label, states);
    if ( m_valeur )
        target.draw(*m_coche, states);

}


} // fin namespace gui

