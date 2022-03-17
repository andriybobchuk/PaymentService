//import Module_B; // Task #8 - import B only

// Task 14 - leave just one import in main:
export import Module_B; // task #14.


export module Module_C;

export void changeName();
export void changeAge();
export void changeHeight();

// accessing the module_A functions
void changeName() {
	playerData::name_1 = "Andrii";

	// accessing the module_A variable
	variable = 0;

	// accessing the module_A class
	Player player();

}

void changeAge() {
	playerData::age_1 = 0;
}

void changeHeight() {
	playerData::height_1 = 1.1;
}




