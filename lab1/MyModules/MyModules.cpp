/*
1. [DONE]Setup your IDE(MSVC) to be compatible with c++20
2. [DONE]remember to import needed std libraries not #include them(import std.core;)
3. [DONE]Create a basic module(Module_A) and import it in main.cpp.
4. [DONE]in Module_A create a class player with 3 types of member variables and a 3 - arg constructor that sets the 3
member variable to the 3 passed arguments.
5. [DONE]Create another module(Module_B).Create and assign different values for 5 (of each type you used in your
    class Player) inside your module.
6. [DONE]import Module_B in main.cpp and use the variables to instantiate 5 objects of class Player. (hint : you can
        use a namespace containing all variables and export it).
7. [DONE]import Module_A in Module_B
8. [DONE]Create Module_C that imports Module_B only. and import it in Main.cpp.
9. [DONE]In Module_C : Declare and define 3 functions that change the values of variables in Module_B
10.[DONE] in main() : use functions from task 9 to change values of variables in Module_B.create Player objects with
   the newly changed variables.
11.[DONE] Declare some variable in Module_A(just for testing) and export it.
12.[YES] Test, can you access Module_A exported variables\functions\classes in Module_C(without directly.
        importing Module_A inside Module_C) (try creating a Player object) ? can you think of a solution ?
13. [DONE]Display contents of your class objects to the console
14. [DOnE]Try to optimize your code to minimize the number of imports(hint : only 1 import can be used in main.cpp)
*/

import std.core; 


//import Module_A; // TAsk #3
//import Module_B; // Task #6
import Module_C; // Task #8

int main() {

    Player player_1(playerData::name_1, playerData::age_1, playerData::height_1);
    Player player_2(playerData::name_2, playerData::age_2, playerData::height_2);
    Player player_3(playerData::name_3, playerData::age_3, playerData::height_3);
    Player player_4(playerData::name_4, playerData::age_4, playerData::height_4);
    Player player_5(playerData::name_5, playerData::age_5, playerData::height_5);

    changeName();
    changeAge();
    changeHeight();

    Player player_1_updated(playerData::name_1, playerData::age_1, playerData::height_1);


}
