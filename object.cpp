#include "object.h"
#include<iostream>

Object::Object(int x_pos, int y_pos){
	x = x_pos;
	y = y_pos;
}

int* Object::get_location(){
	return new int[2] {x,y};
}

void Object::move_to(int x_pos, int y_pos){
	x = x_pos;
	y = y_pos;
}

void Object::move_by(int x_by, int y_by){
	x += x_by;
	y += y_by;
}

/*
int main(){
	Object obj = Object(100,100);

	int x,y;

	int* pos;
	pos = obj.get_location();


	x = pos[0];
	y = pos[1];

	printf("X is %d, Y is %d\n", x, y);

	return 0;
}
*/
