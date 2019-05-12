#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

#include "MySprite.hpp"


namespace ChessCore
{

	typedef struct
	{

		int x; // x == row
		int y; // y == column

	} FigureCoordinates;

	typedef struct
	{

		int x;
		int y;

	} FieldCoordinates;


	enum FigureType
	{
		PAWN,
		ROOK,
		KNIGHT,
		BISHOP,
		QUEEN,
		KING,
		EMPTY
	};

	enum PlayerType
	{
		Player_1,
		Player_2,
		None_player
	};

}

#endif
