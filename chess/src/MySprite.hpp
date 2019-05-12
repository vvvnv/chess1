#include <SFML/Graphics.hpp>
#include "Object.hpp"

namespace ChessCore
{

	class MySprite : public Object
	{
	public:
		MySprite(sf::Sprite t_sprite);
		MySprite();
		~MySprite();
		
		void debugInfo();

		sf::Sprite m_sprite;
		
	};

}