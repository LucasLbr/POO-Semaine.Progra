#pragma once
#pragma once
#ifndef INPUT_H
#define INPUT_H
#include <SFML/Graphics.hpp>
using namespace sf;

class Input
{
	struct  Button { bool left, right, up, down,key1,key2,key3,q,s,z,d,g,h,j; };
public:
	Input();
	Button GetButton(void)const;
	void InputHandler(Event event, RenderWindow& window);
private: Button button;


};
#endif // !INPUT_H

