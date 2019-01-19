#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

int main()
{
	CircleShape ball;
	
	RectangleShape p1paddle, p2paddle;
	ball.setFillColor(Color::Cyan);
	ball.setPosition(100.0, 100.0);
	ball.setRadius(10.0);
	float ballspd = 0.05;
	Vector2f ballmove = Vector2f(ballspd, ballspd);
	p1paddle.setFillColor(Color::Yellow);
	p1paddle.setPosition(10.0, 100.0);
	p1paddle.setSize(Vector2f(10.0, 100.0));

	p2paddle.setFillColor(Color::Red);
	p2paddle.setPosition(580.0, 100.0);
	p2paddle.setSize(Vector2f(10.0, 100.0));
	Vector2f p1movement(0, 0);
	Vector2f p2movement(0, 0);
	RenderWindow window(VideoMode(600, 480), "Pong");
	Clock clock;
	Time timesincelast = Time::Zero;

	while (window.isOpen())
	{
		Event ev;
		while (window.pollEvent(ev))
		{
			if (ev.type == Event::Closed)
				window.close();

		}
		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			p1paddle.move(0, -0.1);

		}
		if (Keyboard::isKeyPressed(Keyboard::S))
		{
			p1paddle.move(0, 0.1);

		}
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			p2paddle.move(0, -0.1);

		}
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			p2paddle.move(0, 0.1);

		}
		if (ball.getPosition().y < 0 || ball.getPosition().y>480)
			ballmove.y *= -1;
		if (ball.getGlobalBounds().intersects(p1paddle.getGlobalBounds()) || ball.getGlobalBounds().intersects(p2paddle.getGlobalBounds()))
			ballmove.x *= -1;
		if (ball.getPosition().x > 590)
		{
			ball.setPosition(300, 240);
		}

		else if (ball.getPosition().x < 0)
		{
			ball.setPosition(300, 240);

		}

		ball.move(ballmove);

		timesincelast = clock.restart();


		window.clear();
		window.draw(p1paddle);
		window.draw(p2paddle);
		window.draw(ball);
		window.display();

	}





	return 0;
}