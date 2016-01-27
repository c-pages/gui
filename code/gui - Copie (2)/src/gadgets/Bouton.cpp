/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Bouton.h>
#include <BoutonRendu.h>
#include <Conteneur.h>
#include <Label.h>
#include <Image.h>


namespace gui {

/////////////////////////////////////////////////
Bouton::Bouton ( )
{
    this
    // Creation du Rendu du bouton
    std::shared_ptr<GadgetRendu> rendu = std::shared_ptr<GadgetRendu> ( new BoutonRendu ( std::static_pointer_cast<Bouton>( shared_from_this() ) ) )
//    m_gadgetRendu = ;

    // Creation de l'icone du bouton.
    setIcone ( std::shared_ptr<Image> ( new Image() ) );

    // Creation du label du bouton.
    setLabel ( std::shared_ptr<Label> ( new Label() ) );

}

/////////////////////////////////////////////////
Bouton::Bouton ( std::shared_ptr<Conteneur>  parent )
{
    // Creation de l'icone du bouton.
    setIcone ( std::shared_ptr<Image> ( new Image() ) );

    // Creation du label du bouton.
    setLabel ( std::shared_ptr<Label> ( new Label() ) );

    // Definition du parent.
    setParent( parent );

}


/////////////////////////////////////////////////
void Bouton::presserBoutonGauche ()
{

}


/////////////////////////////////////////////////
void Bouton::relacherBoutonGauche ()
{

}


/////////////////////////////////////////////////
void Bouton::sourisEntre ()
{

}


/////////////////////////////////////////////////
void Bouton::sourisSort ()
{

}


/////////////////////////////////////////////////
void Bouton::setTexte (std::string texte)
{
    m_label->setTexte ( texte );
}

/////////////////////////////////////////////////
void Bouton::setTaille (Vec2 taille)
{
    m_taille = taille;
}


} // fin namespace gui

