/////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////
#include <ActionEvenement.h>

#include <iostream>

namespace gui {
/////////////////////////////////////////////////
ActionEvenement::ActionEvenement  ()
: m_evenementsSouris( )
{
    std::cout << " CREATION ACTION EVENEMENT\n";
}

/////////////////////////////////////////////////
void ActionEvenement::lier  (Evenement evenement, FctnAction fonction)
{
    m_evenementsSouris.insert( { evenement , fonction } );
}


/////////////////////////////////////////////////
void ActionEvenement::delier ( Evenement evenement )
{

    auto cherche = m_evenementsSouris.find( evenement );

    if ( cherche != m_evenementsSouris.end() )
        m_evenementsSouris.erase ( evenement );

}


/////////////////////////////////////////////////
void ActionEvenement::declencher ( Evenement evenement )
{

//    std::cout << "  declencher : m_evenementsSouris.size : " << m_evenementsSouris.size() << "\n";
//    for (auto evt : m_evenementsSouris )
//        if ( evenement == evt.first )
//            evt.second();
    auto cherche = m_evenementsSouris.find( evenement );
    if ( cherche != m_evenementsSouris.end() )
        cherche->second();

}


} // fin namespace gui

