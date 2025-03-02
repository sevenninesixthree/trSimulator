#include <cstdio>
#include <cmath>
#include "lib/core/update.h"
#include <SFML/Graphics.hpp>
#include <string>
int main(){
  const double a[]={3.14,1};//,b[]={1.001,0},c[]={1.002,0};
  double speed=1.0;bool isPulsed=0;
  Runner tester[]={Runner(a)};//,Runner(b),Runner(c)};
  int n=sizeof(tester)/sizeof(Runner);
  double *outer[n];
  sf::RenderWindow window(sf::VideoMode({800, 600}), "tester");
  sf::Font font("NotoSansCJK-Regular.ttc");
  sf::Text info(font);info.setFillColor(sf::Color::White);info.setPosition({0,0});
  sf::CircleShape dot(10.f);float lineWidth=3;
  sf::Vector2f offset({-10.f,-10.f}),lineOff;
  sf::Vector2f posGet[255];int head=0;
  window.setVerticalSyncEnabled(1);
  sf::Clock timer;timer.restart();
  double dt;
  float x,y;
  sf::Vector2f a1,a2,a0({400,300}),tmp;
  sf::VertexArray line(sf::PrimitiveType::TriangleStrip,4);
  for(int i=0;i<4;i++)
    line[i].color=sf::Color(0xFF8800FF);
  while (window.isOpen())
  {
    while (const std::optional event = window.pollEvent())
    {
      if (event->is<sf::Event::Closed>())
        window.close();
      else if(const auto *keyPre=event->getIf<sf::Event::KeyPressed>()){
        switch(keyPre->scancode){
          case sf::Keyboard::Scancode::Space:isPulsed^=1;break;
          case sf::Keyboard::Scancode::J:speed-=0.1;break;
          case sf::Keyboard::Scancode::K:speed+=0.1;break;
          default:break;
        }
      }
    }
    window.clear(sf::Color::Black);
    if(speed<=0.1)speed=0.1;if(speed>=1)speed=1;
    dt=timer.restart().asSeconds()*speed;
    info.setString(L"当前速率："+std::to_wstring((int)speed)+L"."+std::to_wstring((int)(speed*10.)%10));
    if(isPulsed)info.setString(L"暂停");
    window.draw(info);
    dot.setFillColor(sf::Color(0,255,0));
    /*printf("%d,",(int)(1.0/dt));*/
    for(int i=0;i<n;i++){
      if(!isPulsed)outer[i]=tester[i].update(dt,20);
      x=outer[i][0]*100.+400.;y=outer[i][1]*100.+300.;a1={x,y};
      x=outer[i][2]*100.+400.;y=outer[i][3]*100.+300.;a2={x,y};
      tmp=a0-a1;lineOff=sf::Vector2f(lineWidth,tmp.angle()+sf::degrees(90));
      line[0].position=a0-lineOff;line[1].position=a0+lineOff;
      line[2].position=a1-lineOff;line[3].position=a1+lineOff;
      window.draw(line);
      tmp=a1-a2;lineOff=sf::Vector2f(lineWidth,tmp.angle()+sf::degrees(90));
      line[0].position=a1-lineOff;line[1].position=a1+lineOff;
      line[2].position=a2-lineOff;line[3].position=a2+lineOff;
      window.draw(line);
      dot.setPosition(a1+offset);
      window.draw(dot);
      dot.setPosition(a2+offset);
      window.draw(dot);
      if(!isPulsed)posGet[(++head)%255]=a2+offset;
    }
    dot.setFillColor(sf::Color::Red);dot.setPosition(a0+offset);
    window.draw(dot);
    for(int i=head+255,alpha=255;alpha>0;i--,alpha-=10){
      dot.setPosition(posGet[i%255]);
      dot.setFillColor(sf::Color(0,255,0,alpha));
      window.draw(dot);
    }
    window.display();
  }
  return 0;
}
