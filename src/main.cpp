#include <SFML/Graphics.hpp>
#include <iostream>

#define DESIGNWIDTH 1920.f
#define DESIGNHEIGHT 1200.f

void updateView(sf::View &view, float windowWidth, float windowHeight) {
    float width = DESIGNWIDTH;
    float height = DESIGNHEIGHT;
    if (windowHeight / DESIGNHEIGHT > windowWidth / DESIGNWIDTH) {
        height = (DESIGNWIDTH / windowWidth) * windowHeight;
    } else if (windowHeight / DESIGNHEIGHT < windowWidth / DESIGNWIDTH) {
        width = (DESIGNHEIGHT / windowHeight) * windowWidth;
    }
    float left = (width - DESIGNWIDTH) / 2;
    float top = (height - DESIGNHEIGHT) / 2;
//    std::cout << "Left: " << left << std::endl << "Top: " << top << std::endl << "Width: " << width << std::endl << "Height: " << height << std::endl;
    sf::FloatRect viewPort(left / width, top / height, DESIGNWIDTH / width, DESIGNHEIGHT / height);
    view.setSize(DESIGNWIDTH, DESIGNHEIGHT);
    view.setCenter(DESIGNWIDTH / 2, DESIGNHEIGHT / 2);
    view.setViewport(viewPort);
}

int main(int argc, char **argv) {
    bool fullscreen = false;
    sf::RenderWindow window(sf::VideoMode((unsigned int)DESIGNWIDTH, (unsigned int)DESIGNHEIGHT), "SFML works!", fullscreen ? sf::Style::Fullscreen : sf::Style::Default);
    window.setFramerateLimit(60);
    sf::View view = window.getView();
    updateView(view, window.getSize().x, window.getSize().y);
    window.setView(view);
    sf::CircleShape leftCircle(DESIGNHEIGHT / 2, 100);
    leftCircle.setPosition(-(DESIGNHEIGHT / 2), 0);
    leftCircle.setFillColor(sf::Color::Red);
    sf::CircleShape rightCircle(DESIGNHEIGHT / 2, 100);
    rightCircle.setPosition(DESIGNWIDTH - (DESIGNHEIGHT / 2), 0);
    rightCircle.setFillColor(sf::Color::Blue);
    sf::CircleShape centerCircle(DESIGNWIDTH / 2, 100);
    centerCircle.setPosition(0, -((DESIGNWIDTH - DESIGNHEIGHT) / 2));
    centerCircle.setFillColor(sf::Color::Green);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::Resized) {
                updateView(view, (float)event.size.width, (float)event.size.height);
                window.setView(view);
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
                else if (event.key.code == sf::Keyboard::Return && event.key.alt) {
                    fullscreen = !fullscreen;
                    window.close();
                    window.create(sf::VideoMode((unsigned int)DESIGNWIDTH, (unsigned int)DESIGNHEIGHT), "SFML works!", fullscreen ? sf::Style::Fullscreen : sf::Style::Default);
                    window.setFramerateLimit(60);
                    updateView(view, window.getSize().x, window.getSize().y);
                    window.setView(view);
                }
            }
        }
        window.clear();
        window.draw(centerCircle);
        window.draw(leftCircle);
        window.draw(rightCircle);
        window.display();
    }

    return 0;
}
