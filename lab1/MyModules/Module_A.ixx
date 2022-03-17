export module Module_A;

import <iostream>;

/*
in Module_A create a class player with 3 types of member variables and a 3 - arg constructor that sets the 3
member variable to the 3 passed arguments
*/

export int variable = 1;


export class Player {
	std::string mName;
	int mAge;
	float mHeight;
public:
	Player(std::string name, int age, float height) : mName(name), mAge(age), mHeight(height) { 
		std::cout << "new Player(" << name << ", " << age << ", " << height << ") created; " << std::endl;
	};
};

