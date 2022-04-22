#ifndef PROGRAM_H
#define PROGRAM_H

#include <SFML/Graphics.hpp>
#include <iostream>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

class Program
{
    private:
        sf::RenderWindow m_window;
        sf::Event m_event;

        float m_a, m_P;
        unsigned int m_currentColor;
        bool m_epilepsy;

        sf::RectangleShape m_rectangle;

        void initWindow();

    public:
        Program(float a, float P, bool epilepsy);

        void updateEvents();
        void updateRectangle();
        void update();
        void render();
        void run();
};

#endif
