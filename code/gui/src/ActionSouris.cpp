/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <ActionSouris.h>

#include <iostream>

namespace gui {

/////////////////////////////////////////////////
void ActionSouris::lier  (Evenement evenement, FctnAction fonction)
{
    m_evenementsSouris.insert( { evenement , fonction } );
}


/////////////////////////////////////////////////
void ActionSouris::delier (Evenement evenement)
{

}


/////////////////////////////////////////////////
void ActionSouris::declencher ( Evenement evenement )
{
    for (auto evt : m_evenementsSouris )
        if ( evenement == evt.first )
            evt.second();
}


} // fin namespace gui

