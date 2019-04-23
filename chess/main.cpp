#include <iostream>
#include <map>

//#include "src/Board.hpp"
#include "src/SpritesLoader.hpp"
#include "src/Behavior.hpp"

using namespace std;
using namespace ChessCore;
using namespace sf;


const int board_size = 800;
const int x_0 = 30, y_0 = 30;

const bool DEBUG = true;



int main(int argc, char const *argv[])
{

	SpritesLoader sl("assets/board.png", "assets/figures.png");
	map<FigureType, map<PlayerType, MySprite> > sprites = sl.m_sprites;

	Sprite s = sl.m_board;

	RenderWindow window(VideoMode(board_size, board_size), "Game");

	Board brd(sprites);

	bool isPressed = false;

	int x_start, y_start, x_end, y_end;

	vector<PlayerType> players {Player_1, Player_2};
	int player_iter = 0;

	while (window.isOpen())
	{


		Vector2i pixelPos = Mouse::getPosition(window);
		Vector2f pos = window.mapPixelToCoords(pixelPos);

		sf::Event event;

		map<FigureType, string> _m = {{ROOK, "ROOK"},
									  {KNIGHT, "KNIGHT"},
									  {BISHOP,"BISHOP"},
									  {KING, "KING"},
									  {QUEEN, "QUEEN"},
									  {EMPTY, "EMPTY"},
									  {PAWN, "PAWN"}};

        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            int countOfKings = 0;
            for(int i = 0; i < 8; ++i)
            {
            	for(int j = 0; j < 8; ++j)
            	{
            		if (brd.m_board[j][i].getType() == KING)
            		{
            			countOfKings ++;
            		}
            	}
            }

            if(countOfKings != 2)
            {
            	cout << "Loose!" << endl;
            	return 0;
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
            	s.getGlobalBounds().contains(pos.x, pos.y) &&
            	((pos.x - 35) >=0 && (pos.y - 35) >= 0))
            {

            	//cout << "is pressed = " << " " << isPressed << endl;
            	if(!isPressed)
            	{
            		isPressed = true;

            		x_start = (int(pos.x - 35) / 90);
            		y_start = (int(pos.y - 35) / 90);
            		if((brd.m_board[y_start][x_start].getType() == EMPTY) ||
            			(brd.m_board[y_start][x_start].getPlayer() != players[player_iter]))
            		{
            			isPressed = false;
            		}
            		//cout << "X_start = " << x_start << " y_start = " << y_start << endl;
            	}
            	else
            	{
            		isPressed = false;
            		player_iter = (player_iter + 1) % 2;
            		x_end = (int(pos.x - 35) / 90);
            		y_end = (int(pos.y - 35) / 90);

            		if(brd.m_board[y_end][x_end].getType() == EMPTY)
            		{
	            		if(Behavior::check(brd.m_board[y_start][x_start], brd.m_board[y_end][x_end], brd))

	            		{
	            			Behavior::mySwap(brd.m_board[y_start][x_start], brd.m_board[y_end][x_end]);
	            			//cout << "X_end = " << x_start << " y_end = " << y_end << endl;
	            		}
	            		else
	            		{
	            			isPressed = true;
	            		}
            		}
            		else
            		{
            			if(Behavior::canEat(brd.m_board[y_start][x_start], brd.m_board[y_end][x_end], brd))
            			{
            				Behavior::deleteFigure(brd.m_board[y_end][x_end], sprites[EMPTY][None_player]);
            				Behavior::mySwap(brd.m_board[y_start][x_start], brd.m_board[y_end][x_end]);
            			}
            			else
            			{
            				isPressed = true;
            			}
            		}
            	}

            	if(DEBUG)
            	{
            		cout << "------------------" << endl;
            		int x, y;
            		if(isPressed) x = x_start, y = y_start; else x = x_end, y = y_end;
            		cout << "pressed : " << " " << x << " " << y << endl;

            		cout << "figure  : " << _m[brd.m_board[y][x].getType()] << endl;
            		cout << "player : " << brd.m_board[y][x].getPlayer() << endl;
            	}
            }

        }


		window.clear();
		window.draw(s);

		for(int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				window.draw(brd.m_board[i][j].m_sprite.m_sprite);
			}
		}
		window.display();

	}

	return 0;
}
