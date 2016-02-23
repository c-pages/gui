/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <Skin.h>

#include <Style.h>

namespace gui{
/////////////////////////////////////////////////
Skin::Skin ()
: invisible ( std::make_shared<Style> () )
, cadre     ( std::make_shared<Style> () )
, txtLog    ( std::make_shared<Style> () )
, txtCourant( std::make_shared<Style> () )
, txtTitre  ( std::make_shared<Style> () )
, fondPress ( std::make_shared<Style> () )
, fondSurvol( std::make_shared<Style> () )
, fondRepos ( std::make_shared<Style> () )
, imgRepos  ( std::make_shared<Style> () )
, fenetre   ( std::make_shared<Style> () )
, desactive ( std::make_shared<Style> () )
{

}

}; // fin namespace gui

