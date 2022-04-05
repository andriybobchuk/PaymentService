#include <ranges>
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>


/*

Using ranges create a vector with only prime numbers from another vector (i.e. [1,2,3,4,5,6,7,8]  -> [2,3,5,7])
Try to use range factory as input (iota)
Display this vector in reverse order
Display all found prime numbers which are greater than 10 (don't use filter view)
Display three first prime numbers
Display every but three first prime numbers
Calculate and display squares of numbers 2-4 from task 5
Read contents of points.csv file into a string, split it by commas, and display in triples, as points in space 
(there are 20 points)



*/

bool isPrime(int i) {
    if (i <= 2) return false;
    for (int j = 2; j * j <= i; ++j) 
        if (i % j == 0) return false;
    
    return true;
}

bool lowerEqualThan10(int a) { return a <= 10; }

bool square(int a) { return a * a; }


int main() {


    auto to_int = [](auto word) {
        std::string w;
        for (auto c : word)
            w += c;
        return std::stoi(w);
    };


    /* TASK 1 */
#if 1 // Using ranges create a vector with only prime numbers from another vector (i.e. [1,2,3,4,5,6,7,8]  -> [2,3,5,7])
    std::vector<int> initialVector = { 1,2,3,4,5,6,7,8 };
    std::vector<int> primeVector;

    auto iotaView = std::views::iota(1, 20);    // Range factory
    auto range = iotaView | std::views::filter(isPrime);
    primeVector.insert(primeVector.begin(), range.begin(), range.end());
    for (auto element : primeVector) std::cout << element << " ";
    std::cout << "\n";

#endif

    /* TASK 2 */
#if 1 // Display this vector in reverse order
    for (auto element : primeVector | std::views::reverse) std::cout << element << " ";
    std::cout << "\n";
   
#endif


    /* TASK 3 */
#if 1 // Display all found prime numbers which are greater than 10 (don't use filter view)
    for (auto element : primeVector | std::views::drop_while(lowerEqualThan10)) std::cout << element << " ";
    std::cout << "\n";

#endif

    /* TASK 4 */
#if 1 // Display three first prime numbers
    for (auto element : primeVector | std::views::take(3)) std::cout << element << " ";
    std::cout << "\n";

#endif

    /* TASK 5 */
#if 1 // Display every but three first prime numbers
    for (auto element : primeVector | std::views::drop(3)) std::cout << element << " ";
    std::cout << "\n";

#endif

    /* TASK 6 */
#if 1 // Calculate and display squares of numbers 2-4 from task 5
    for (auto element : std::views::counted(primeVector.begin() + 5, 3) | std::views::transform(square)) 
        std::cout << element << " ";
    std::cout << "\n";

#endif

    /* TASK 7 */
#if 1 // Read contents of points.csv file into a string, split it by commas, and display in triples, as points in space 
    std::ifstream inputFileStream("points.csv");
    std::string separator = ",";
    std::string line;
    std::string word;
    inputFileStream >> line;

    int itr = 0;
    for (const auto& word : std::views::split(line, separator)) {
 
        if (itr % 3 == 0) 
            std::cout << "(";
        else 
            std::cout << ", ";

        for (const auto& character : word) std::cout << character;

        if (itr % 3 == 2) 
            std::cout << ")" << "\n";
        itr ++;
    }

#endif


    return 0;
}