#ifndef OBJECT_H
#define OBJECT_H


#include<vector>
#include<string>
class Object{
	public:
		Object(int x_pos, int y_pos, std::string name);
		int * get_location();
		void move_to(int x_pos, int y_pos);	
		void move_by(int x_by, int y_by);
		void attach(Object * parent);
		std::string get_name();	
		std::vector <Object*> get_children();

	protected:
		int _x,_y;
		std::vector <Object*> _children;
		Object* _parent;
		std::string _name;	
	private:
		void propagate_movement(int x_by, int y_by);	
};

#endif
