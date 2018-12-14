#ifndef OBJECT_H
#define OBJECT_H

class Object{
	public:
		Object(int x_pos, int y_pos);
		int * get_location();
		void move_to(int x_pos, int y_pos);	
		void move_by(int x_pos, int y_pos);
	protected:
		int x,y;

};

#endif
