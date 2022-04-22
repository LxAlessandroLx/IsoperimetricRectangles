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

        sf::RectangleShape m_rectangle;

        void initWindow();

    public:
        Program(float a, float P);

        void updateEvents();
        void updateRectangle();
        void update();
        void render();
        void run();
};

#endif
