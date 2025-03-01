#include <cstdio>
#include <cmath>
#include "lib/core/update.h"
#include <SFML/Graphics.hpp>
int main(){
  Runner tester;double *outer;
  sf::RenderWindow window(sf::VideoMode({800, 600}), "My window");
  sf::CircleShape dot(3.f),pot(3.f);
  dot.setFillColor(sf::Color::Green);
  pot.setFillColor(sf::Color::Red);
  pot.setPosition({400,300});
  window.setVerticalSyncEnabled(1);
  sf::Clock timer;timer.restart();
  window.clear(sf::Color::Black);
  window.draw(pot);
  while (window.isOpen())
  {
    while (const std::optional event = window.pollEvent())
    {
      if (event->is<sf::Event::Closed>())
        window.close();
    }
    outer=tester.update(timer.restart().asSeconds());
    float x=outer[0]*cos(outer[1])*100;
    float y=outer[0]*sin(outer[1])*100;
    dot.setPosition({x+400,y+300});
    window.draw(dot);
    window.display();
  }
  return 0;
}
