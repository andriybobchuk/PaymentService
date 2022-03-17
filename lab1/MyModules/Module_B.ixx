export module Module_B;
export import Module_A; // Task #7.


import <iostream>;

/*
Create another module(Module_B).Create and assign different values for 5 (of each type you used in your
	class Player) inside your module.
*/


export namespace playerData {
	std::string name_1{ "Tom" }, name_2{ "Wes" }, name_3{ "Jack" }, name_4{ "Peter" }, name_5{ "Sally" };
	int age_1{ 18 }, age_2{ 19 }, age_3{ 20 }, age_4{ 21 }, age_5{ 22 };
	float height_1{ 1.82 }, height_2{ 1.83 }, height_3{ 1.84 }, height_4{ 1.85 }, height_5{ 1.86 };
}