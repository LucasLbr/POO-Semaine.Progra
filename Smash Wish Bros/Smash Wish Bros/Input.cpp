#include "Input.h"

Input::Input() {
	button.left = button.right = button.up = button.down = button.key1 = button.key2 = button.key3 = false;
}
Input::Button Input::GetButton(void)const {
	return button;
}void Input::InputHandler(Event event, RenderWindow& window) {
	if (event.type == Event::Closed) {
		window.close();
	}
	if (event.type == Event::KeyPressed) {
		switch (event.key.code) {
		//_-----------------------J1------------------------
		case Keyboard::Left:button.left = true;//gauche j1
			break;
		case Keyboard::Up:button.up = true;// sauter j1
			break;
		case Keyboard::Right:button.right = true;//droite j1
			break;
		case Keyboard::Down:button.down = true;//bouclier j1
			break;
		case Keyboard::Num1:button.key1 = true;//att base j1
			break;
		case Keyboard::Num2:button.key2 = true;// att uppercut j1
			break;
		case Keyboard::Num3:button.key3 = true;// att spé j1
			break;
		//-------------------------j2-------------------
		case Keyboard::Q:button.q = true;//gauche j2
			break;
		case Keyboard::Z:button.z = true;// sauter j2
			break;
		case Keyboard::D:button.d = true;//droite j2
			break;
		case Keyboard::S:button.s = true;//bouclier j2
			break;
		case Keyboard::G:button.g = true;//att base j2
			break;
		case Keyboard::H:button.h = true;// att uppercut j2
			break;
		case Keyboard::J:button.j = true;// att spé j2
			break;

		}


	}
	if (event.type == Event::KeyReleased) {
		switch (event.key.code) {
		
		case Keyboard::Left:button.left = false;
			break;
		case Keyboard::Up:button.up = false;
			break;
		case Keyboard::Right:button.right = false;
			break;
		case Keyboard::Down:button.down = false;
			break;
		case Keyboard::Num1:button.key1 = false;
			break;
		case Keyboard::Num2:button.key2 = false;
			break;
		case Keyboard::Num3:button.key3 = false;
			break;
		case Keyboard::Q:button.q = false;//gauche j2
			break;
		case Keyboard::Z:button.z = false;// sauter j2
			break;
		case Keyboard::D:button.d = false;//droite j2
			break;
		case Keyboard::S:button.s = false;//bouclier j2
			break;
		case Keyboard::G:button.g = false;//att base j2
			break;
		case Keyboard::H:button.h = false;// att uppercut j2
			break;
		case Keyboard::J:button.j = false;// att spé j2
			break;

		}
	}
}