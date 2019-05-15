#include "Behavior.hpp"
#include <iostream>

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
			if ((crd_a.x == crd_b.x)||(crd_a.y == crd_b.y)){
				if (crd_a.y == crd_b.y){
					if(crd_a.x < crd_b.x) {
						mini = crd_a.x+1;
						maxi = crd_b.x;
					}
					else {
						mini = crd_b.x+1;
						maxi = crd_a.x;
					}
					for (int i = mini; i< maxi; i++){
						if(brd.m_board[crd_a.y][i].getType() != EMPTY) {flag = false;}
					}
				}
				else {
					if(crd_a.y < crd_b.y) {
						mini = crd_a.y+1;
						maxi = crd_b.y;
					}
					else {
						mini = crd_b.y+1;
						maxi = crd_a.y;
					}
					for (int i = mini; i< maxi; i++){
						if(brd.m_board[i][crd_a.x].getType() != EMPTY) {flag = false;}
					}
				}
			}
			else {
				return false;
				}
			break;

		case KNIGHT:
			if (((fabs(crd_b.x - crd_a.x) == 2) && (fabs(crd_b.y - crd_a.y) ==1)) || ((fabs(crd_b.y - crd_a.y) == 2) && (fabs(crd_b.x - crd_a.x) ==1))){
				return true;
				}
			else{
				return false;
				}
			break;

		case BISHOP:
			if(fabs(crd_a.x - crd_b.x) == fabs(crd_a.y - crd_b.y)){
				if((crd_a.x - crd_b.x) == (crd_a.y - crd_b.y)){
					if(crd_a.x < crd_b.x) {
						minix = crd_a.x + 1;
						maxix = crd_b.x;
						miniy = crd_a.y + 1;
					}
					else {
						minix = crd_b.x + 1;
						maxix = crd_a.x;
						miniy = crd_b.y + 1;
					}
					j = miniy;
					for (int i = minix; i< maxix; i++){
						if(brd.m_board[j][i].getType() != EMPTY) {
							flag = false;
						}
						j++;
					}
					flag = true;
				}
				else{
					if(crd_a.x < crd_b.x) {
						minix = crd_a.x + 1;
						maxix = crd_b.x;
						maxiy = crd_a.y - 1;
					}
					else {
						minix = crd_b.x + 1;
						maxix = crd_a.x;
						maxiy = crd_b.y - 1;
					}
					j = maxiy;
					for (int i = minix; i< maxix; i++){
						if(brd.m_board[j][i].getType() != EMPTY) {
							flag = false;
						}
						j--;
					}
					flag = true;
				}
			}
			break;

		case QUEEN:
		if ((crd_a.x == crd_b.x)||(crd_a.y == crd_b.y)){
			if (crd_a.y == crd_b.y){
				if(crd_a.x < crd_b.x) {
					mini = crd_a.x+1;
					maxi = crd_b.x;
				}
				else {
					mini = crd_b.x+1;
					maxi = crd_a.x;
				}
				for (int i = mini; i< maxi; i++){
					if(brd.m_board[crd_a.y][i].getType() != EMPTY) {flag = false;}
				}
				flag = true;
				}
			else {
				if(crd_a.y < crd_b.y) {
					mini = crd_a.y+1;
					maxi = crd_b.y;
				}
				else {
					mini = crd_b.y+1;
					maxi = crd_a.y;
				}
				for (int i = mini; i< maxi; i++){
					if(brd.m_board[i][crd_a.x].getType() != EMPTY) {flag = false;}
				}
				flag = true;
			}
		}
		else if(fabs(crd_a.x - crd_b.x) == fabs(crd_a.y - crd_b.y)){
				if((crd_a.x - crd_b.x) == (crd_a.y - crd_b.y)){
					if(crd_a.x < crd_b.x) {
						minix = crd_a.x + 1;
						maxix = crd_b.x;
						miniy = crd_a.y + 1;
					}
					else {
						minix = crd_b.x + 1;
						maxix = crd_a.x;
						miniy = crd_b.y + 1;
					}
					j = miniy;
					for (int i = minix; i< maxix; i++){
						if(brd.m_board[j][i].getType() != EMPTY) {
							flag = false;
						}
						j++;
					}
					flag = true;
				}
				else{
					if(crd_a.x < crd_b.x) {
						minix = crd_a.x + 1;
						maxix = crd_b.x;
						maxiy = crd_a.y - 1;
					}
					else {
						minix = crd_b.x + 1;
						maxix = crd_a.x;
						maxiy = crd_b.y - 1;
					}
					j = maxiy;
					for (int i = minix; i< maxix; i++){
						if(brd.m_board[j][i].getType() != EMPTY) {
							flag = false;
						}
						j--;
					}
					flag = true;
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
		int i, j, maxi, mini, minix, maxix, miniy, maxiy;
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
			if ((crd_a.x == crd_b.x)||(crd_a.y == crd_b.y)){
				if (crd_a.y == crd_b.y){
					if(crd_a.x < crd_b.x) {
						mini = crd_a.x+1;
						maxi = crd_b.x;
					}
					else {
						mini = crd_b.x+1;
						maxi = crd_a.x;
					}
					for (int i = mini; i< maxi; i++){
						if(brd.m_board[crd_a.y][i].getType() != EMPTY) {flag = false;}
					}
					flag = true;
				}
				else {
					if(crd_a.y < crd_b.y) {
						mini = crd_a.y+1;
						maxi = crd_b.y;
					}
					else {
						mini = crd_b.y+1;
						maxi = crd_a.y;
					}
					for (int i = mini; i< maxi; i++){
						if(brd.m_board[i][crd_a.x].getType() != EMPTY) {flag = false;}
					}
					flag = true;
				}
			}
			else {
				return false;
				}
			break;
		case KNIGHT:
			if (((fabs(crd_b.x - crd_a.x) == 2) && (fabs(crd_b.y - crd_a.y) ==1)) || ((fabs(crd_b.y - crd_a.y) == 2) && (fabs(crd_b.x - crd_a.x) ==1))){
				return true;
				}
			else{
				return false;
				}
			break;

		case BISHOP:
			if(fabs(crd_a.x - crd_b.x) == fabs(crd_a.y - crd_b.y)){
				if((crd_a.x - crd_b.x) == (crd_a.y - crd_b.y)){
					if(crd_a.x < crd_b.x) {
						minix = crd_a.x + 1;
						maxix = crd_b.x;
						miniy = crd_a.y + 1;
					}
					else {
						minix = crd_b.x + 1;
						maxix = crd_a.x;
						miniy = crd_b.y + 1;
					}
					j = miniy;
					for (int i = minix; i< maxix; i++){
						if(brd.m_board[j][i].getType() != EMPTY) {
							flag = false;
						}
						j++;
					}
					flag = true;
				}
				else{
					if(crd_a.x < crd_b.x) {
						minix = crd_a.x + 1;
						maxix = crd_b.x;
						maxiy = crd_a.y - 1;
					}
					else {
						minix = crd_b.x + 1;
						maxix = crd_a.x;
						maxiy = crd_b.y - 1;
					}
					j = maxiy;
					for (int i = minix; i< maxix; i++){
						if(brd.m_board[j][i].getType() != EMPTY) {
							flag = false;
						}
						j--;
					}
					flag = true;
				}
			}
			break;

		case QUEEN:
		if ((crd_a.x == crd_b.x)||(crd_a.y == crd_b.y)){
			if (crd_a.y == crd_b.y){
				if(crd_a.x < crd_b.x) {
					mini = crd_a.x+1;
					maxi = crd_b.x;
				}
				else {
					mini = crd_b.x+1;
					maxi = crd_a.x;
				}
				for (int i = mini; i< maxi; i++){
					if(brd.m_board[crd_a.y][i].getType() != EMPTY) {flag = false;}
				}
				flag = true;
				}
			else {
				if(crd_a.y < crd_b.y) {
					mini = crd_a.y+1;
					maxi = crd_b.y;
				}
				else {
					mini = crd_b.y+1;
					maxi = crd_a.y;
				}
				for (int i = mini; i< maxi; i++){
					if(brd.m_board[i][crd_a.x].getType() != EMPTY) {flag = false;}
				}
				flag = true;
			}
		}
		else if(fabs(crd_a.x - crd_b.x) == fabs(crd_a.y - crd_b.y)){
				if((crd_a.x - crd_b.x) == (crd_a.y - crd_b.y)){
					if(crd_a.x < crd_b.x) {
						minix = crd_a.x + 1;
						maxix = crd_b.x;
						miniy = crd_a.y + 1;
					}
					else {
						minix = crd_b.x + 1;
						maxix = crd_a.x;
						miniy = crd_b.y + 1;
					}
					j = miniy;
					for (int i = minix; i< maxix; i++){
						if(brd.m_board[j][i].getType() != EMPTY) {
							flag = false;
						}
						j++;
					}
					flag = true;
				}
				else{
					if(crd_a.x < crd_b.x) {
						minix = crd_a.x + 1;
						maxix = crd_b.x;
						maxiy = crd_a.y - 1;
					}
					else {
						minix = crd_b.x + 1;
						maxix = crd_a.x;
						maxiy = crd_b.y - 1;
					}
					j = maxiy;
					for (int i = minix; i< maxix; i++){
						if(brd.m_board[j][i].getType() != EMPTY) {
							flag = false;
						}
						j--;
					}
					flag = true;
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
