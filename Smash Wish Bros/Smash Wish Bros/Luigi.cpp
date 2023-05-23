#include "Luigi.h"
Luigi::Luigi() :Personnage()
{
	rectangle.setSize(sf::Vector2f(50, 50));
	rectangle.setFillColor(sf::Color::Green);
	rectangle.setPosition(1340, 650);
}
void Luigi::up() {
	rectangle.move(0, -speed);
}
void Luigi::left() {
	rectangle.move(-speed, 0);
}
void Luigi::right() {
	rectangle.move(speed, 0);
}
sf::RectangleShape& Luigi::LuigiGetRect() {
	return rectangle;
}
sf::FloatRect Luigi::LuigiglobalPosition()
{
	return rectangle.getGlobalBounds();
}

sf::Vector2f Luigi::LuigiPosition() {
	return rectangle.getPosition();
}
sf::Vector2f Luigi::LuigisetPosition(const sf::Vector2f& newPosition) {
	sf::Vector2f previousPosition = rectangle.getPosition();
	rectangle.setPosition(newPosition);
	return previousPosition;
}