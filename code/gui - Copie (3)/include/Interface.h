#ifndef TEST_H
#define TEST_H

#include <SFML/Graphics.hpp>
#include <iostream>


namespace gui{

class Interface: public sf::Drawable
{
    public:
        Interface();
        virtual ~Interface();
        void traiter_evenements  ( const sf::Event& event )
        {
            std::cout << "######################## EVENTS ########################\n";
        }

    protected:
    private:

        virtual void draw ( sf::RenderTarget& target, sf::RenderStates states ) const
        {
            std::cout << "Dessiner Test !!\n";
        };
};
};

#endif // TEST_H
