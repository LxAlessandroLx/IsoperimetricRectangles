#include "Program.h"

using sf::Event;
using sf::VideoMode;
using sf::Keyboard;
using sf::Mouse;
using sf::Color;
using sf::Uint8;
using std::cout;
using std::endl;

Program::Program(float a, float P, bool epilepsy)
    : m_a(a), m_P(P), m_currentColor(0), m_epilepsy(epilepsy)
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
            case sf::Event::MouseButtonPressed:
                if (m_rectangle.getGlobalBounds().contains(m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window))) 
                    && m_event.mouseButton.button == Mouse::Left)
                {
                    m_currentColor = (m_currentColor+1) % 3;

                    switch (m_currentColor)
                    {
                        case 0:
                            m_rectangle.setFillColor({0, 255, 0, 150});
                            m_rectangle.setOutlineColor({0, 255, 0, 255});
                            break;
                        case 1:
                            m_rectangle.setFillColor({255, 0, 0, 150});
                            m_rectangle.setOutlineColor({255, 0, 0, 255});
                            break;
                        case 2:
                            m_rectangle.setFillColor({0, 0, 255, 150});
                            m_rectangle.setOutlineColor({0, 0, 255, 255});
                            break;
                    }
                }
            default: break;
        }
    }
}

void Program::updateRectangle()
{
    system(CLEAR);
    cout << "Base lenght : " << m_a << endl;
    cout << "Perimeter lenght : " << m_P << endl;

    m_rectangle.setSize({ m_a, m_P/2 - m_a });
    m_rectangle.setOrigin(m_rectangle.getSize() / 2.f);
}

void Program::update()
{
    updateEvents();

    if (m_epilepsy)
    {
        m_rectangle.setFillColor({ Uint8(rand() % 256),  Uint8(rand() % 256),  Uint8(rand() % 256), 255 });
        m_rectangle.setOutlineColor({ Uint8(rand() % 256),  Uint8(rand() % 256),  Uint8(rand() % 256), 255 });
    }
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
