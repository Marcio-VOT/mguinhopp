#include "../Jogo.h"

Jogo::Jogo() : window(VideoMode(1800, 920), "Jogo"),
               shape(Vector2f(60.f, 85.f))
{
    if (!texture.loadFromFile("Jogadores/Jogador1.png"))
    {
        std::cout << "Error" << std::endl;
    }

    shape.setTexture(&texture);
    Executar();
}

Jogo::~Jogo()
{
}

void Jogo::Executar()
{
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        // sprite.setPosition(sf::Vector2f(10.f, 50.f)); // absolute position
        // sprite.move(sf::Vector2f(5.f, 10.f));         // offset relative to the current position

        // Get the position of the shape
        Vector2f position = shape.getPosition();

        // Get the size of the window
        Vector2u windowSize = window.getSize();

        bool isTouchingLeft = false;
        bool isTouchingRight = false;
        bool isTouchingTop = false;
        bool isTouchingBottom = false;

        // Check if the shape is outside the left boundary
        if (position.x < 0)
        {
            shape.setPosition(0, position.y);
            isTouchingLeft = true;
        }
        else
        {
            isTouchingLeft = false;
        }

        // Check if the shape is outside the right boundary
        if (position.x + shape.getSize().x > windowSize.x)
        {
            shape.setPosition(windowSize.x - shape.getSize().x, position.y);
            isTouchingRight = true;
        }
        else
        {
            isTouchingRight = false;
        }

        // Check if the shape is outside the top boundary
        if (position.y < 0)
        {
            shape.setPosition(position.x, 0);
            isTouchingTop = true;
        }
        else
        {
            isTouchingTop = false;
        }

        // Check if the shape is outside the bottom boundary
        if (position.y + shape.getSize().y > windowSize.y)
        {
            shape.setPosition(position.x, windowSize.y - shape.getSize().y);
            isTouchingBottom = true;
        }
        else
        {
            isTouchingBottom = false;
        }

        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            if (!isTouchingLeft)
            {
                shape.move(-1, 0);
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            if (!isTouchingRight)
            {
                shape.move(1, 0);
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Up))
        {
            if (!isTouchingTop)
            {
                shape.move(0, -1);
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Down))
        {
            if (!isTouchingBottom)
            {
                shape.move(0, 1);
            }
        }

        window.clear(Color(173, 216, 230));
        window.draw(shape);
        window.display();
    }
}