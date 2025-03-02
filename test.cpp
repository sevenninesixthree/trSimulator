#include <cstdio>
#include <cmath>
#include "lib/core/update.h"
#include <SFML/Graphics.hpp>
#define speed 1
int main(){
  const double a[]={3.14,1};//,b[]={1.001,0},c[]={1.002,0};
  Runner tester[]={Runner(a)};//,Runner(b),Runner(c)};
  int n=sizeof(tester)/sizeof(Runner);
  double *outer[n];
  sf::RenderWindow window(sf::VideoMode({800, 600}), "tester");
  sf::CircleShape dot(10.f);
  sf::Vector2f offset({-10.f,-10.f});
  sf::Vector2f posGet[255];int head=0;
  window.setVerticalSyncEnabled(1);
  sf::Clock timer;timer.restart();
  double dt;
  float x,y;
  sf::Vector2f a1,a2;
  sf::VertexArray line(sf::PrimitiveType::LineStrip,3);
  for(int i=0;i<3;i++)
    line[i].color=sf::Color::Red;
  line[0].position=sf::Vector2f({400,300});
  while (window.isOpen())
  {
    while (const std::optional event = window.pollEvent())
    {
      if (event->is<sf::Event::Closed>())
        window.close();
    }
    window.clear(sf::Color::Black);
    dt=timer.restart().asSeconds()*speed;
    dot.setFillColor(sf::Color(0,255,0));
    /*printf("%d,",(int)(1.0/dt));*/
    for(int i=0;i<n;i++){
      outer[i]=tester[i].update(dt,20);
      x=outer[i][0]*100.+400.;y=outer[i][1]*100.+300.;a1={x,y};
      x=outer[i][2]*100.+400.;y=outer[i][3]*100.+300.;a2={x,y};
      line[1].position=a1;line[2].position=a2;
      window.draw(line);
      dot.setPosition(a1+offset);
      window.draw(dot);
      dot.setPosition(a2+offset);
      window.draw(dot);
      posGet[(++head)%255]=a2+offset;
    }
    for(int i=head+255,alpha=255;alpha>0;i--,alpha-=10){
      dot.setPosition(posGet[i%255]);
      dot.setFillColor(sf::Color(0,255,0,alpha));
      window.draw(dot);
    }
    window.display();
  }
  return 0;
}
