/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <DnSlider.h>



namespace gui {

/////////////////////////////////////////////////
DnSlider::DnSlider ()
: m_boutonFond  ( std::make_shared<BtnRectangle>() )
, m_slider      ( std::make_shared<BtnRectangle>() )
, m_valeurMax   ( 100 )
, m_valeurMin   ( 0 )
, m_horizontal  ( true )
, m_drag        ( false )
, m_longueur    ( 180 )
, m_largeur     ( 15 )
{
    m_marge.x = 0;
    m_marge.y = 0;

//    m_boutonFond->setParent  ( this );
    ajouterComposant( m_boutonFond );
    ajouterComposant( m_slider );

    // Action du bouton
    m_boutonFond->lier ( Evenement::onBtnG_presser , [this](){
//        positionnerCurseurSurSouris ();
        if ( m_horizontal ) {
            if ( getLocalPosSouris().x > m_marge.x + m_slider->getTaille().x/2 + m_slider->getPosition().x ){
                incrementer ( 20 );
                if ( m_slider->getPosition().x + ( m_slider->getTaille().x/2  ) > getLocalPosSouris().x )
                    positionnerCurseurSurSouris ();
            } else {
                decrementer ( 20 );
                if ( m_slider->getPosition().x + ( m_slider->getTaille().x/2  ) < getLocalPosSouris().x )
                    positionnerCurseurSurSouris ();
            }
        } else {
            if ( getLocalPosSouris().y > m_marge.y + m_slider->getTaille().y/2 + m_slider->getPosition().y ){
                incrementer ( 20 );
                if ( m_slider->getPosition().y - ( m_slider->getTaille().y/2 + m_marge.y )  > getLocalPosSouris().y )
                    positionnerCurseurSurSouris ();
            } else {
                decrementer ( 20 );
                if ( m_slider->getPosition().y - ( m_slider->getTaille().y/2 + m_marge.y )  < getLocalPosSouris().y )
                    positionnerCurseurSurSouris ();
            }

        }
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
        if ( m_horizontal )
                incrementer();
        else    decrementer();
        actualiser ();
    });
    m_boutonFond->lier ( Evenement::onBtnM_roulerBas , [this](){
        if ( m_horizontal )
                decrementer();
        else    incrementer();
        actualiser ();
    });


    m_slider->setPosition ( m_marge.x, m_marge.y );
    m_slider->setTaille ( { m_largeur - 2*m_marge.x  , m_largeur - 2*m_marge.y });
    m_slider->setStyle ( m_skin->getStyle( Skin::Styles::slider ) );

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
        if ( m_horizontal )
                incrementer();
        else    decrementer();
        actualiser ();
    });
    m_slider->lier ( Evenement::onBtnM_roulerBas , [this](){
        if ( m_horizontal )
                decrementer();
        else    incrementer();
        actualiser ();
    });


    actualiser();
    actualiser_bounds();
    m_boutonFond->actualiser_bounds();
    m_slider->actualiser_bounds();

}

/////////////////////////////////////////////////
void DnSlider::incrementer( float inc )
{
    declencher ( Evenement::on_changerValeur );
    if ( m_horizontal )
        m_slider->setPosition ( m_slider->getPosition ( ).x + inc , m_slider->getPosition ( ).y );
    else
        m_slider->setPosition ( m_slider->getPosition ( ).x  , m_slider->getPosition ( ).y + inc);

    corrigerPositionCurseur();

}

/////////////////////////////////////////////////
void DnSlider::decrementer( float inc )
{
    declencher ( Evenement::on_changerValeur );
    if ( m_horizontal )
        m_slider->setPosition ( m_slider->getPosition ( ).x - inc , m_slider->getPosition ( ).y );
    else
        m_slider->setPosition ( m_slider->getPosition ( ).x , m_slider->getPosition ( ).y - inc );

    corrigerPositionCurseur();
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

    declencher ( Evenement::on_changerValeur );

    // Definir la nouvelle position avec les coords souris
    if ( m_horizontal )
        m_slider->setPosition ( getLocalPosSouris().x - m_marge.x - m_slider->getTaille().x/2, m_marge.y );
    else
        m_slider->setPosition (  m_marge.x , getLocalPosSouris().y - m_marge.y - m_slider->getTaille().y/2);

    // Corriger la position pour la garder dans ses limites
    corrigerPositionCurseur();

    actualiser ();
}



/////////////////////////////////////////////////
void DnSlider::setLongCurseur( float pourcentage )
{

    if ( m_horizontal )
        m_slider->setTailleX( m_longueur * pourcentage/100);
    else
        m_slider->setTailleY( m_longueur * pourcentage/100);

    actualiser();
    actualiser_bounds();
    m_boutonFond->actualiser_bounds();
    m_slider->actualiser_bounds();

}


/////////////////////////////////////////////////
void DnSlider::actualiser ()
{

    if ( m_horizontal ) {
        m_taille.x = m_longueur;
        m_taille.y = m_largeur;
    } else {
        m_taille.x = m_largeur;
        m_taille.y = m_longueur;
    }

    m_boutonFond->setTaille ( m_taille );

    m_slider->setStyle ( m_skin->getStyle( Skin::Styles::slider ) );

    actualiser_bounds();
    m_boutonFond->actualiser_bounds();
    m_slider->actualiser_bounds();


}


/////////////////////////////////////////////////
float DnSlider::getValeur(){
    float result, longueurMax,coefPosition, longueurVal;
    if ( m_horizontal ) {
        longueurMax = m_taille.x - 2*m_marge.x - m_slider->getTaille().x;
        coefPosition = ( m_slider->getPosition().x - m_marge.x ) / longueurMax;
        longueurVal = m_valeurMax - m_valeurMin;
        result =  coefPosition * longueurVal;
    } else {
        longueurMax = m_taille.y - 2*m_marge.y - m_slider->getTaille().y;
        coefPosition = ( m_slider->getPosition().y - m_marge.y ) / longueurMax;
        longueurVal = m_valeurMax - m_valeurMin;
        result =  m_valeurMax - coefPosition * longueurVal;
    }
    return result;
};



/*

/////////////////////////////////////////////////
std::shared_ptr<Gadget>  DnSlider::testerSurvol ( sf::Vector2f position )
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

}



*/
/////////////////////////////////////////////////
void DnSlider::corrigerPositionCurseur(){

    if ( m_horizontal ) {
        if ( m_slider->getPosition ( ).x < m_marge.x )
            m_slider->setPosition ( m_marge.x, m_slider->getPosition ( ).y );
        if ( m_slider->getPosition ( ).x > m_taille.x - m_marge.x - m_slider->getTaille().x )
            m_slider->setPosition ( m_taille.x - m_marge.x - m_slider->getTaille().x, m_slider->getPosition ( ).y );
    } else {
        if ( m_slider->getPosition ( ).y < m_marge.y )
            m_slider->setPosition ( m_slider->getPosition ( ).x , m_marge.y  );
        if ( m_slider->getPosition ( ).y > m_taille.y - m_marge.y - m_slider->getTaille().y )
            m_slider->setPosition ( m_slider->getPosition ( ).x,  m_taille.y - m_marge.y - m_slider->getTaille().y );
    }
}




} // fin namespace gui

