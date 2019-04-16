#include "Behavior.hpp"

namespace ChessCore
{

	Behavior::Behavior()
	{

	}

	Behavior::~Behavior()
	{



	}

	void Behavior::mySwap(Figure &a, Figure &b)
	{
		std::swap(a, b);
		sf::Vector2f _pos1 = a.m_sprite.m_sprite.getPosition();
	    sf::Vector2f _pos2 = b.m_sprite.m_sprite.getPosition();
	    a.m_sprite.m_sprite.setPosition(_pos2);
	    b.m_sprite.m_sprite.setPosition(_pos1);
	    FigureCoordinates f_crd_a = a.getFieldCoords();
	    FigureCoordinates f_crd_b = b.getFieldCoords();
	    a.setFieldCoords(f_crd_b);
	    b.setFieldCoords(f_crd_a);

	    FigureCoordinates crd_a = a.getCoords();
	    FigureCoordinates crd_b = b.getCoords();
	    a.setCoords(crd_b);
	    b.setCoords(crd_a);

	}

	bool Behavior::check(Figure &a, Figure &b, Board &brd)
	{
		int ax, ay, bx,by, i,j, mini, maxi, dx, dy, minix, maxix, miniy, maxiy;
		FigureCoordinates coordsa,coordsb;
		coordsa = a.getCoords();
		coordsb = b.getCoords();
		bx = coordsb.x;
		by = coordsb.y;
		ax = coordsa.x;
		ay = coordsa.y;

		int direction = (a.getPlayer() == Player_1) ? 1 : -1;
		int flag = false;
		FigureType fig = a.getType();
		FigureCoordinates crd_a = a.getCoords();
		FigureCoordinates crd_b = b.getCoords();
		switch(a.getType()){
		case PAWN:
			if((crd_b.x - crd_a.x) == direction &&
				   (crd_b.y - crd_a.y) == 0)
				flag = true;
				break;

		case ROOK:
			if ((ax == bx)||(ay == by)){
				if (ay == by){
					if((ax-bx) < 0) {mini = ax+1; maxi = bx;}
					else {mini = bx+1; maxi = ax;}
					int k = 0;
					for (i = mini; i < maxi; i++){
						if(brd.m_board[ay][mini].getType() == EMPTY) {k++;}
					}
					if (k == (maxi - mini)) {return true;}
					else{return false;}
				}
				else{
					if((ay-by) < 0) {mini = ay+1; maxi = by;}
					else {mini = by+1; maxi = ay;}
					int k = 0;
					for (i = mini; i < maxi; i++){
						if(brd.m_board[mini][ax].getType() == EMPTY) {k++;}
					}
					if (k == (maxi - mini)) {return true;}
					else{return false;}
				}
			}
			else {
				return false;
				}
			break;

		case KNIGHT:
			dx = bx-ax;
			dy = by-ay;
			if (((fabs(dx) == 2) && (fabs(dy) ==1)) || ((fabs(dy) == 2) && (fabs(dx) ==1))){
				return true;
				}
			else{
				return false;
				}
			break;

		case BISHOP:
			if (fabs(ax-bx) == fabs(ay-by)){
				if ((bx-ax) == (by-ay)){
					if((ax-bx) < 0) {minix = ax+1; maxix = bx; miniy = ay+1; maxiy = by;}
					else {minix = bx+1; maxix = ax;miniy = bx+1; maxiy = ax;}
					int k = 0;
					j = ay+1;
					for (i = minix; i< maxix; i++){
						if(brd.m_board[j][mini].getType() == EMPTY) {k++;}
						j++;
					}
					if (k == (maxi - mini)) {return true;}
					else{return false;}
				}
				else{
					if((ax-bx) < 0) {minix = ax+1; maxix = bx; miniy = ay+1; maxiy = by;}
					else {minix = bx+1; maxix = ax;miniy = bx+1; maxiy = ax;}
					int k = 0;
					j = ay+1;
					for (i = minix; i< maxix; i++){
						if(brd.m_board[j][mini].getType() == EMPTY) {k++;}
						j--;
					}
					if (k == (maxi - mini)) {return true;}
					else{return false;}
				}

			}
			else{
				return false;
				}
			break;

		case QUEEN:
		if ((ax == bx)||(ay == by)){
				if (ay == by){
					if((ax-bx) < 0) {mini = ax+1; maxi = bx;}
					else {mini = bx+1; maxi = ax;}
					int k = 0;
					for (i = mini; i < maxi; i++){
						if(brd.m_board[ay][mini].getType() == EMPTY) {k++;}
					}
					if (k == (maxi - mini)) {return true;}
					else{return false;}
				}
				else{
					if((ay-by) < 0) {mini = ay+1; maxi = by;}
					else {mini = by+1; maxi = ay;}
					int k = 0;
					for (i = mini; i < maxi; i++){
						if(brd.m_board[mini][ax].getType() == EMPTY) {k++;}
					}
					if (k == (maxi - mini)) {return true;}
					else{return false;}
				}
			}
			else if (fabs(ax-bx) == fabs(ay-by)){
				if ((bx-ax) == (by-ay)){
					if((ax-bx) < 0) {minix = ax+1; maxix = bx; miniy = ay+1; maxiy = by;}
					else {minix = bx+1; maxix = ax;miniy = bx+1; maxiy = ax;}
					int k = 0;
					j = ay+1;
					for (i = minix; i< maxix; i++){
						if(brd.m_board[j][mini].getType() == EMPTY) {k++;}
						j++;
					}
					if (k == (maxi - mini)) {return true;}
					else{return false;}
				}
				else{
					if((ax-bx) < 0) {minix = ax+1; maxix = bx; miniy = ay+1; maxiy = by;}
					else {minix = bx+1; maxix = ax;miniy = bx+1; maxiy = ax;}
					int k = 0;
					j = ay+1;
					for (i = minix; i< maxix; i++){
						if(brd.m_board[j][mini].getType() == EMPTY) {k++;}
						j--;
					}
					if (k == (maxi - mini)) {return true;}
					else{return false;}
				}

			}
			else{
				return false;
				}
			break;
		}
		return flag;
	}

	bool Behavior::canEat(Figure &a, Figure &b, Board &brd)
	{
		int ax, ay, bx,by, i,j, mini, maxi, dx, dy, minix, maxix, miniy, maxiy;
		FigureCoordinates coordsa,coordsb;
		coordsa = a.getCoords();
		coordsb = b.getCoords();
		bx = coordsb.x;
		by = coordsb.y;
		ax = coordsa.x;
		ay = coordsa.y;


		int direction = (a.getPlayer() == Player_1) ? 1 : -1;
		int flag = false;
		FigureType fig = a.getType();
		FigureCoordinates crd_a = a.getCoords();
		FigureCoordinates crd_b = b.getCoords();
		switch(a.getType()){
		case PAWN:
			if((crd_b.x - crd_a.x) == direction &&
				   std::abs(crd_b.y - crd_a.y) == 1 &&
				   b.getType() != KING)
				flag = true;
				break;
		case ROOK:
			if ((ax == bx)||(ay == by)){
				if (ay == by){
					if((ax-bx) < 0) {mini = ax+1; maxi = bx;}
					else {mini = bx+1; maxi = ax;}
					int k = 0;
					for (i = mini; i < maxi; i++){
						if(brd.m_board[ay][mini].getType() == EMPTY) {k++;}
					}
					if (k == (maxi - mini)) {return true;}
					else{return false;}
				}
				else{
					if((ay-by) < 0) {mini = ay+1; maxi = by;}
					else {mini = by+1; maxi = ay;}
					int k = 0;
					for (i = mini; i < maxi; i++){
						if(brd.m_board[mini][ax].getType() == EMPTY) {k++;}
					}
					if (k == (maxi - mini)) {return true;}
					else{return false;}
				}
			}
			else {
				return false;
				}
			break;

		case KNIGHT:
			dx = bx-ax;
			dy = by-ay;
			if (((fabs(dx) == 2) && (fabs(dy) ==1)) || ((fabs(dy) == 2) && (fabs(dx) ==1))){
				return true;
				}
			else{
				return false;
				}
			break;

		case BISHOP:
			if (fabs(ax-bx) == fabs(ay-by)){
				if ((bx-ax) == (by-ay)){
					if((ax-bx) < 0) {minix = ax+1; maxix = bx; miniy = ay+1; maxiy = by;}
					else {minix = bx+1; maxix = ax;miniy = bx+1; maxiy = ax;}
					int k = 0;
					j = ay+1;
					for (i = minix; i< maxix; i++){
						if(brd.m_board[j][mini].getType() == EMPTY) {k++;}
						j++;
					}
					if (k == (maxi - mini)) {return true;}
					else{return false;}
				}
				else{
					if((ax-bx) < 0) {minix = ax+1; maxix = bx; miniy = ay+1; maxiy = by;}
					else {minix = bx+1; maxix = ax;miniy = bx+1; maxiy = ax;}
					int k = 0;
					j = ay+1;
					for (i = minix; i< maxix; i++){
						if(brd.m_board[j][mini].getType() == EMPTY) {k++;}
						j--;
					}
					if (k == (maxi - mini)) {return true;}
					else{return false;}
				}

			}
			else{
				return false;
				}
			break;

		case QUEEN:
		if ((ax == bx)||(ay == by)){
				if (ay == by){
					if((ax-bx) < 0) {mini = ax+1; maxi = bx;}
					else {mini = bx+1; maxi = ax;}
					int k = 0;
					for (i = mini; i < maxi; i++){
						if(brd.m_board[ay][mini].getType() == EMPTY) {k++;}
					}
					if (k == (maxi - mini)) {return true;}
					else{return false;}
				}
				else{
					if((ay-by) < 0) {mini = ay+1; maxi = by;}
					else {mini = by+1; maxi = ay;}
					int k = 0;
					for (i = mini; i < maxi; i++){
						if(brd.m_board[mini][ax].getType() == EMPTY) {k++;}
					}
					if (k == (maxi - mini)) {return true;}
					else{return false;}
				}
			}
			else if (fabs(ax-bx) == fabs(ay-by)){
				if ((bx-ax) == (by-ay)){
					if((ax-bx) < 0) {minix = ax+1; maxix = bx; miniy = ay+1; maxiy = by;}
					else {minix = bx+1; maxix = ax;miniy = bx+1; maxiy = ax;}
					int k = 0;
					j = ay+1;
					for (i = minix; i< maxix; i++){
						if(brd.m_board[j][mini].getType() == EMPTY) {k++;}
						j++;
					}
					if (k == (maxi - mini)) {return true;}
					else{return false;}
				}
				else{
					if((ax-bx) < 0) {minix = ax+1; maxix = bx; miniy = ay+1; maxiy = by;}
					else {minix = bx+1; maxix = ax;miniy = bx+1; maxiy = ax;}
					int k = 0;
					j = ay+1;
					for (i = minix; i< maxix; i++){
						if(brd.m_board[j][mini].getType() == EMPTY) {k++;}
						j--;
					}
					if (k == (maxi - mini)) {return true;}
					else{return false;}
				}

			}
			else{
				return false;
				}
			break;
		}
		return flag;
	}

	void Behavior::deleteFigure(Figure &a, MySprite sprite)
	{
		sf::Vector2f _pos1 = a.m_sprite.m_sprite.getPosition();
		a.m_sprite = sprite;
		a.m_sprite.m_sprite.setPosition(_pos1);
		a.setType(EMPTY);
		a.setPlayer(None_player);
	}

}




/*#include "Behavior.hpp"

namespace ChessCore
{

	Behavior::Behavior()
	{

	}

	Behavior::~Behavior()
	{



	}

	void Behavior::mySwap(Figure &a, Figure &b)
	{
		std::swap(a, b);
		sf::Vector2f _pos1 = a.m_sprite.m_sprite.getPosition();
	    sf::Vector2f _pos2 = b.m_sprite.m_sprite.getPosition();
	    a.m_sprite.m_sprite.setPosition(_pos2);
	    b.m_sprite.m_sprite.setPosition(_pos1);
	    FigureCoordinates f_crd_a = a.getFieldCoords();
	    FigureCoordinates f_crd_b = b.getFieldCoords();
	    a.setFieldCoords(f_crd_b);
	    b.setFieldCoords(f_crd_a);

	    FigureCoordinates crd_a = a.getCoords();
	    FigureCoordinates crd_b = b.getCoords();
	    a.setCoords(crd_b);
	    b.setCoords(crd_a);

	}

	bool Behavior::check(Figure &a, Figure &b, Board &brd)
	{
		int ax, ay, bx,by, i,j, mini, maxi, dx, dy, minix, maxix, miniy, maxiy;
		FigureCoordinates coordsa,coordsb;
		coordsa = a.getCoords();
		coordsb = b.getCoords();
		bx = coordsb.x;
		by = coordsb.y;
		ax = coordsa.x;
		ay = coordsa.y;

		int direction = (a.getPlayer() == Player_1) ? 1 : -1;
		int flag = false;
		FigureType fig = a.getType();
		FigureCoordinates crd_a = a.getCoords();
		FigureCoordinates crd_b = b.getCoords();
		switch(a.getType()){
		case PAWN:
			if((crd_b.x - crd_a.x) == direction &&
				   (crd_b.y - crd_a.y) == 0)
				flag = true;
				break;

		case ROOK:
			if ((ax == bx)||(ay == by)){
				if (ay == by){
					if((ax-bx) < 0) {mini = ax+1; maxi = bx;}
					else {mini = bx+1; maxi = ax;}
					int k = 0;
					for (i = mini; i < maxi; i++){
						if(brd.m_board[ay][mini].getType() == EMPTY) {k++;}
					}
					if (k == (maxi - mini)) {return true;}
					else{return false;}
				}
				else{
					if((ay-by) < 0) {mini = ay+1; maxi = by;}
					else {mini = by+1; maxi = ay;}
					int k = 0;
					for (i = mini; i < maxi; i++){
						if(brd.m_board[mini][ax].getType() == EMPTY) {k++;}
					}
					if (k == (maxi - mini)) {return true;}
					else{return false;}
				}
			}
			else {
				return false;
				}
			break;

		case KNIGHT:
			dx = bx-ax;
			dy = by-ay;
			if (((fabs(dx) == 2) && (fabs(dy) ==1)) || ((fabs(dy) == 2) && (fabs(dx) ==1))){
				return true;
				}
			else{
				return false;
				}
			break;

		case BISHOP:
			if (fabs(ax-bx) == fabs(ay-by)){
				if ((bx-ax) == (by-ay)){
					if((ax-bx) < 0) {minix = ax+1; maxix = bx; miniy = ay+1; maxiy = by;}
					else {minix = bx+1; maxix = ax;miniy = bx+1; maxiy = ax;}
					int k = 0;
					j = ay+1;
					for (i = minix; i< maxix; i++){
						if(brd.m_board[j][mini].getType() == EMPTY) {k++;}
						j++;
					}
					if (k == (maxi - mini)) {return true;}
					else{return false;}
				}
				else{
					if((ax-bx) < 0) {minix = ax+1; maxix = bx; miniy = ay+1; maxiy = by;}
					else {minix = bx+1; maxix = ax;miniy = bx+1; maxiy = ax;}
					int k = 0;
					j = ay+1;
					for (i = minix; i< maxix; i++){
						if(brd.m_board[j][mini].getType() == EMPTY) {k++;}
						j--;
					}
					if (k == (maxi - mini)) {return true;}
					else{return false;}
				}

			}
			else{
				return false;
				}
			break;

		case QUEEN:
		if ((ax == bx)||(ay == by)){
				if (ay == by){
					if((ax-bx) < 0) {mini = ax+1; maxi = bx;}
					else {mini = bx+1; maxi = ax;}
					int k = 0;
					for (i = mini; i < maxi; i++){
						if(brd.m_board[ay][mini].getType() == EMPTY) {k++;}
					}
					if (k == (maxi - mini)) {return true;}
					else{return false;}
				}
				else{
					if((ay-by) < 0) {mini = ay+1; maxi = by;}
					else {mini = by+1; maxi = ay;}
					int k = 0;
					for (i = mini; i < maxi; i++){
						if(brd.m_board[mini][ax].getType() == EMPTY) {k++;}
					}
					if (k == (maxi - mini)) {return true;}
					else{return false;}
				}
			}
			else if (fabs(ax-bx) == fabs(ay-by)){
				if ((bx-ax) == (by-ay)){
					if((ax-bx) < 0) {minix = ax+1; maxix = bx; miniy = ay+1; maxiy = by;}
					else {minix = bx+1; maxix = ax;miniy = bx+1; maxiy = ax;}
					int k = 0;
					j = ay+1;
					for (i = minix; i< maxix; i++){
						if(brd.m_board[j][mini].getType() == EMPTY) {k++;}
						j++;
					}
					if (k == (maxi - mini)) {return true;}
					else{return false;}
				}
				else{
					if((ax-bx) < 0) {minix = ax+1; maxix = bx; miniy = ay+1; maxiy = by;}
					else {minix = bx+1; maxix = ax;miniy = bx+1; maxiy = ax;}
					int k = 0;
					j = ay+1;
					for (i = minix; i< maxix; i++){
						if(brd.m_board[j][mini].getType() == EMPTY) {k++;}
						j--;
					}
					if (k == (maxi - mini)) {return true;}
					else{return false;}
				}

			}
			else{
				return false;
				}
			break;
		}
		return flag;
	}

	bool Behavior::canEat(Figure &a, Figure &b, Board &brd)
	{
		int ax, ay, bx,by, i,j, mini, maxi, dx, dy, minix, maxix, miniy, maxiy;
		FigureCoordinates coordsa,coordsb;
		coordsa = a.getCoords();
		coordsb = b.getCoords();
		bx = coordsb.x;
		by = coordsb.y;
		ax = coordsa.x;
		ay = coordsa.y;


		int direction = (a.getPlayer() == Player_1) ? 1 : -1;
		int flag = false;
		FigureType fig = a.getType();
		FigureCoordinates crd_a = a.getCoords();
		FigureCoordinates crd_b = b.getCoords();
		switch(a.getType()){
		case PAWN:
			if((crd_b.x - crd_a.x) == direction &&
				   std::abs(crd_b.y - crd_a.y) == 1 &&
				   b.getType() != KING)
				flag = true;
				break;
		case ROOK:
			if ((ax == bx)||(ay == by)){
				if (ay == by){
					if((ax-bx) < 0) {mini = ax+1; maxi = bx;}
					else {mini = bx+1; maxi = ax;}
					int k = 0;
					for (i = mini; i < maxi; i++){
						if(brd.m_board[ay][mini].getType() == EMPTY) {k++;}
					}
					if (k == (maxi - mini)) {return true;}
					else{return false;}
				}
				else{
					if((ay-by) < 0) {mini = ay+1; maxi = by;}
					else {mini = by+1; maxi = ay;}
					int k = 0;
					for (i = mini; i < maxi; i++){
						if(brd.m_board[mini][ax].getType() == EMPTY) {k++;}
					}
					if (k == (maxi - mini)) {return true;}
					else{return false;}
				}
			}
			else {
				return false;
				}
			break;

		case KNIGHT:
			dx = bx-ax;
			dy = by-ay;
			if (((fabs(dx) == 2) && (fabs(dy) ==1)) || ((fabs(dy) == 2) && (fabs(dx) ==1))){
				return true;
				}
			else{
				return false;
				}
			break;

		case BISHOP:
			if (fabs(ax-bx) == fabs(ay-by)){
				if ((bx-ax) == (by-ay)){
					if((ax-bx) < 0) {minix = ax+1; maxix = bx; miniy = ay+1; maxiy = by;}
					else {minix = bx+1; maxix = ax;miniy = bx+1; maxiy = ax;}
					int k = 0;
					j = ay+1;
					for (i = minix; i< maxix; i++){
						if(brd.m_board[j][mini].getType() == EMPTY) {k++;}
						j++;
					}
					if (k == (maxi - mini)) {return true;}
					else{return false;}
				}
				else{
					if((ax-bx) < 0) {minix = ax+1; maxix = bx; miniy = ay+1; maxiy = by;}
					else {minix = bx+1; maxix = ax;miniy = bx+1; maxiy = ax;}
					int k = 0;
					j = ay+1;
					for (i = minix; i< maxix; i++){
						if(brd.m_board[j][mini].getType() == EMPTY) {k++;}
						j--;
					}
					if (k == (maxi - mini)) {return true;}
					else{return false;}
				}

			}
			else{
				return false;
				}
			break;

		case QUEEN:
		if ((ax == bx)||(ay == by)){
				if (ay == by){
					if((ax-bx) < 0) {mini = ax+1; maxi = bx;}
					else {mini = bx+1; maxi = ax;}
					int k = 0;
					for (i = mini; i < maxi; i++){
						if(brd.m_board[ay][mini].getType() == EMPTY) {k++;}
					}
					if (k == (maxi - mini)) {return true;}
					else{return false;}
				}
				else{
					if((ay-by) < 0) {mini = ay+1; maxi = by;}
					else {mini = by+1; maxi = ay;}
					int k = 0;
					for (i = mini; i < maxi; i++){
						if(brd.m_board[mini][ax].getType() == EMPTY) {k++;}
					}
					if (k == (maxi - mini)) {return true;}
					else{return false;}
				}
			}
			else if (fabs(ax-bx) == fabs(ay-by)){
				if ((bx-ax) == (by-ay)){
					if((ax-bx) < 0) {minix = ax+1; maxix = bx; miniy = ay+1; maxiy = by;}
					else {minix = bx+1; maxix = ax;miniy = bx+1; maxiy = ax;}
					int k = 0;
					j = ay+1;
					for (i = minix; i< maxix; i++){
						if(brd.m_board[j][mini].getType() == EMPTY) {k++;}
						j++;
					}
					if (k == (maxi - mini)) {return true;}
					else{return false;}
				}
				else{
					if((ax-bx) < 0) {minix = ax+1; maxix = bx; miniy = ay+1; maxiy = by;}
					else {minix = bx+1; maxix = ax;miniy = bx+1; maxiy = ax;}
					int k = 0;
					j = ay+1;
					for (i = minix; i< maxix; i++){
						if(brd.m_board[j][mini].getType() == EMPTY) {k++;}
						j--;
					}
					if (k == (maxi - mini)) {return true;}
					else{return false;}
				}

			}
			else{
				return false;
				}
			break;
		}
		return flag;
	}

	void Behavior::deleteFigure(Figure &a, MySprite sprite)
	{
		sf::Vector2f _pos1 = a.m_sprite.m_sprite.getPosition();
		a.m_sprite = sprite;
		a.m_sprite.m_sprite.setPosition(_pos1);
		a.setType(EMPTY);
		a.setPlayer(None_player);
	}

}*/
