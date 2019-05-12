#include "BaseTypes.hpp"
#include <iostream>


namespace ChessCore
{

	MySprite::MySprite()
	{

	}

	MySprite::MySprite(sf::Sprite t_sprite)
		: m_sprite(t_sprite)
	{

	}


	MySprite::~MySprite()
	{

	}

	void MySprite::debugInfo()
	{
		std::cout << "sprite rotation = " << m_sprite.getRotation() << std::endl;
	}

}
