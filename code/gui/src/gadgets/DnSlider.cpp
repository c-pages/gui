/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <DnSlider.h>



namespace gui {

/////////////////////////////////////////////////
DnSlider::DnSlider ()
: m_boutonFond ( std::make_shared<BtnRectangle>() )
, m_slider ( std::make_shared<BtnRectangle>() )
, m_valeurMax ( 100 )
, m_valeurMin ( 0 )
, m_horizontal ( true )
, m_drag ( false )
, m_inc ( 5 )
{
    m_taille.x = 180;
    m_taille.y = 20;

    m_marge.x = 0;
    m_marge.y = 0;

    m_boutonFond->setParent  ( this );
    m_boutonFond->setTaille ( m_taille );

    // Action du bouton
    m_boutonFond->lier ( Evenement::onBtnG_presser , [this](){
        positionnerCurseurSurSouris ();
        setDrag( true );
    });
    m_boutonFond->lier ( Evenement::onBtnG_relacher , [this](){
        setDrag( false );
        actualiser ();
    });
    m_boutonFond->lier ( Evenement::onBtnG_relacherDehors , [this](){
        setDrag( false );
        actualiser ();
    });
    m_boutonFond->lier ( Evenement::onBtnM_roulerHaut , [this](){
        incrementer();
        actualiser ();
    });

    m_boutonFond->lier ( Evenement::onBtnM_roulerBas , [this](){
        decrementer();
        actualiser ();
    });


    m_slider->setParent  ( this );
    m_slider->setTaille ( { 25 , m_taille.y - 2*m_marge.y });
    m_slider->setPosition ( m_marge.x, m_marge.y );

    // Action du slider
    m_slider->lier ( Evenement::onBtnG_presser , [this](){
        setDrag( true );
        actualiser ();
    });
    m_slider->lier ( Evenement::onBtnG_relacher , [this](){
        setDrag( false );
        actualiser ();
    });
    m_slider->lier ( Evenement::onBtnG_relacherDehors , [this](){
        setDrag( false );
        actualiser ();
    });
    m_slider->lier ( Evenement::onBtnM_roulerHaut , [this](){
        incrementer();
        actualiser ();
    });

    m_slider->lier ( Evenement::onBtnM_roulerBas , [this](){
        decrementer();
        actualiser ();
    });

    actualiser();
    actualiser_bounds();
    m_boutonFond->actualiser_bounds();
    m_slider->actualiser_bounds();

}

/////////////////////////////////////////////////
void DnSlider::incrementer()
{
    declencher ( Evenement::on_changerValeur );

    m_slider->setPosition ( m_slider->getPosition ( ).x + m_inc , m_slider->getPosition ( ).y );
    if ( m_slider->getPosition ( ).x > m_taille.x - m_marge.x - m_slider->getTaille().x )
        m_slider->setPosition ( m_taille.x - m_marge.x - m_slider->getTaille().x, m_slider->getPosition ( ).y );
}

/////////////////////////////////////////////////
void DnSlider::decrementer()
{
    declencher ( Evenement::on_changerValeur );

    m_slider->setPosition ( m_slider->getPosition ( ).x - m_inc , m_slider->getPosition ( ).y );
    if ( m_slider->getPosition ( ).x < m_marge.x )
            m_slider->setPosition ( m_marge.x, m_slider->getPosition ( ).y );

}



/////////////////////////////////////////////////
void DnSlider::traiterEvenements (const sf::Event& evenement)
{
    if ( dragEnCours() )
        positionnerCurseurSurSouris ();

}



/////////////////////////////////////////////////
void DnSlider::positionnerCurseurSurSouris ()
{
    // Definir la nouvelle position avec les coords souris
    m_slider->setPosition ( getLocalPosSouris().x - m_marge.x - m_slider->getTaille().x/2, m_marge.y );

    // Corriger la position pour la garder dans ses limites
    if ( m_slider->getPosition ( ).x < m_marge.x )
        m_slider->setPosition ( m_marge.x, m_slider->getPosition ( ).y );
    if ( m_slider->getPosition ( ).x > m_taille.x - m_marge.x - m_slider->getTaille().x )
        m_slider->setPosition ( m_taille.x - m_marge.x - m_slider->getTaille().x, m_slider->getPosition ( ).y );

    declencher ( Evenement::on_changerValeur );

    actualiser ();
}






/////////////////////////////////////////////////
void DnSlider::actualiser ()
{


    actualiser_bounds();
    m_boutonFond->actualiser_bounds();
    m_slider->actualiser_bounds();


}


/////////////////////////////////////////////////
float DnSlider::getValeur(){
    float longueurMax = m_taille.x - 2*m_marge.x - m_slider->getTaille().x;
    float coefPosition = ( m_slider->getPosition().x - m_marge.x ) / longueurMax;

    float longueurVal = m_valeurMax - m_valeurMin;

    float result =  coefPosition * longueurVal;

    return result;
};




/////////////////////////////////////////////////
std::shared_ptr<Gadget>  DnSlider::testerSurvol ( sf::Vector2i position )
{
    if ( m_globalBounds.contains( position.x, position.y ) && estActif() )
    {
        auto result = m_slider->testerSurvol ( position );
        if ( result == nullptr )
            result = m_boutonFond->testerSurvol ( position );
        return result;
    } else
        return nullptr;

}

/////////////////////////////////////////////////
void DnSlider::draw (sf::RenderTarget& target, sf::RenderStates states) const
{

    //On applique la transformation
    states.transform *= getTransform();

    // On dessine les éléments
    target.draw(*m_boutonFond, states);
    target.draw(*m_slider, states);
//    if ( m_valeur )
//        target.draw(*m_coche, states);
}


} // fin namespace gui

