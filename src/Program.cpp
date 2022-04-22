#include "Program.h"

using sf::Event;
using sf::VideoMode;
using sf::Keyboard;

Program::Program(float a, float P)
    : m_a(a), m_P(P)
{
    initWindow();

    m_rectangle.setPosition(400, 300);
    m_rectangle.setFillColor({0, 255, 0, 150});
    m_rectangle.setOutlineThickness(2);
    m_rectangle.setOutlineColor({0, 255, 0, 255});
    
    updateRectangle();
}

void Program::initWindow()
{
    m_window.create(VideoMode(800, 600), "Isoperimetric Rectangles", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
    m_window.setFramerateLimit(60);
}

void Program::updateEvents()
{
    while (m_window.pollEvent(m_event))
    {
        switch (m_event.type)
        {
            case Event::Closed: 
                m_window.close(); 
                break;
            case Event::KeyPressed:
                switch (m_event.key.code)
                {
                    case Keyboard::Right:
                        if (m_a < m_P/2)
                        {
                            m_a += 10;
                            updateRectangle();
                        }
                        break;
                    case Keyboard::Left:
                        if (m_a >= 10)
                        {
                            m_a -= 10;
                            updateRectangle();
                        }
                        break;
                    case Keyboard::Down:
                        m_P += 10;
                        updateRectangle();
                        break;
                    case Keyboard::Up:
                        if (m_P > 10 && m_P > m_a*2)
                        {
                            m_P -= 10;
                            updateRectangle();
                        }
                        break;
                    default:
                        break;
                }
            default: break;
        }
    }
}

void Program::updateRectangle()
{
    m_rectangle.setSize({ m_a, m_P/2 - m_a });
    m_rectangle.setOrigin(m_rectangle.getSize() / 2.f);
}

void Program::update()
{
    updateEvents();
}

void Program::render()
{
    m_window.clear();
    m_window.draw(m_rectangle);
    m_window.display();
}

void Program::run()
{
    while (m_window.isOpen())
    {
        update();
        render();
    }
}
