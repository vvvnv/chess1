#include "Figure.hpp"
#include <iostream>
#include <map>


namespace ChessCore
{

	Figure::Figure(const FigureCoordinates &t_coords,
			   	   const MySprite &t_sprite,
			   	   const FigureType &t_type,
			       const PlayerType &t_player)
		: m_coords(t_coords), m_sprite(t_sprite), m_type(t_type), m_player(t_player)
		{

		}

	Figure::~Figure()
	{

	}

	FigureCoordinates Figure::getCoords() const
	{
		return m_coords;
	}


	void Figure::setCoords(const FigureCoordinates &t_coords)
	{
		m_coords = t_coords;
	}

	void Figure::setFieldCoords(const FigureCoordinates &t_field_coords)
	{
		m_field_coords = t_field_coords;
	}

	FigureCoordinates Figure::getFieldCoords() const
	{
		return m_field_coords;
	}

	FigureType Figure::getType() const
	{
		return m_type;
	}

	PlayerType Figure::getPlayer() const
	{
		return m_player;
	}

	void Figure::setType(FigureType t)
	{
		m_type = t;
	}

	void Figure::setPlayer(PlayerType p)
	{
		m_player = p;
	}

	void Figure::debugInfo()
	{
		std::cout << "--------------" << std::endl;
		std::cout << "local coords : " << m_coords.x << " " << m_coords.y << std::endl;
		std::cout << "field coords : " << m_field_coords.x << " " << m_field_coords.y << std::endl;
		std::map<FigureType, std::string> _m = {{ROOK, "ROOK"}, {KNIGHT, "KNIGHT"}, {BISHOP,"BISHOP"}, {KING, "KING"}, {QUEEN, "QUEEN"}, {EMPTY, "EMPTY"}, {PAWN, "PAWN"}};
		std::map<PlayerType, std::string> _t = {{Player_1, "Player 1"}, {Player_2, "Player 2"}, {None_player, "None player"}};
		std::cout << "figure type : " << _m[m_type] << std::endl;
		std::cout << "player type : " << _t[m_player	] << std::endl;

	}

}
