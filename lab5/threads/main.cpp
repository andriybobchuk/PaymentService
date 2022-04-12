#include <iostream>
#include <vector>
#include <future>
#include <random>
#include <array>
#include <chrono>

#define ARR_SZ 45


using namespace std::chrono_literals;


int lengthOf(std::string string) {
    int count = 0;
    for(int i = 0; string[i] != '\0'; i++){
        count++;
    }
    return count;
}

int getRandom(int range) {
    std::random_device randomDevice;
    std::mt19937 randomGenerator(randomDevice());
    std::uniform_int_distribution<std::mt19937::result_type> distribution(1, range);
    return distribution(randomGenerator);
}

void alpha() {
    while (true) {
        if (getRandom(100) == 50) {
            std::cout << "alpha: Done!\n";
            break;
        }
    }
}

void bravo() {
    while (true) {
        if (getRandom(100) == 50) {
            std::cout << "bravo: Done!\n";
            break;
        }
    }
}

int fib(int n) {
    if (n <= 1) { return n; }
    return fib(n - 1) + fib(n - 2);
}




/*
 *
1. Create any function and execute it by calling std::async.
2. Create a random integer generator with a specified range [0..100], then create two async functions, which call the generator in a loop until '50' is generated - first one to exit the loop wins
3. Create a recursive fibonacci function and two arrays with std::array<int, ARR_SZ> (include <array> and write #define ARR_SZ 20 below your includes).
 Then create two functions:
 asyncAssign(std::array<int, ARR_SZ> &arr) and seqAssign(std::array<int, ARR_SZ> &arr)
  In these functions try to assign fibonacci value of array's indices to them.
  In asyncAssign split the array into 2 or more parts and let each std::async function handle each part.
  (use lambda-capture to access the array -> '[&]() { arr[i] = fib(i) }' in a for-loop).
4. Compare the time needed for async- and seqAssign
5. Now change '#define ARR_SZ 20' to '#define ARR_SZ 45' -> compare the time results again
6. Modify previous task, so that it uses wait_for() and std::future_status and informs the user, that the function is still running (at ARR_SZ 45 it can take several seconds)
 *
 *
 */
int main(){

    // Task 1
    auto future = std::async(
            std::launch::async,
            lengthOf,
            "programming");
    future.get();

    // Task 2
    auto a = std::async(std::launch::async, alpha);
    auto b = std::async(std::launch::async, bravo);

    // Task 3
    std::array<int, ARR_SZ> arrayAlpha{};
    std::array<int, ARR_SZ> arrayBravo{};

    auto asyncAssign = [&arrayBravo]() {
        std::async(std::launch::async,
                   [&]() { for (int i = 0; i < ARR_SZ / 2; ++i) { arrayBravo[i] = fib(i); }});
        std::async(std::launch::async,
                   [&]() { for (int i = ARR_SZ / 2; i < ARR_SZ; ++i) { arrayBravo[i] = fib(i); }});
    };
    auto seqAssign = [&arrayAlpha](){
            for (int i = 0; i < ARR_SZ; ++i)
                arrayAlpha[i] = fib(i);
    };


    // Task 4
    auto start = std::chrono::system_clock::now();
    auto f3 = std::async(std::launch::async, asyncAssign);
    std::future_status status{};
    int count{};
    do {
        switch (status = f3.wait_for(1s); status) {
            case std::future_status::timeout:
                std::cout << "timeout: " << count << 's\n';
                break;
            case std::future_status::ready:
                std::cout << "ready: " << count << 's\n';
                break;
        }
        count++;
    } while (status != std::future_status::ready);
    auto timeNeeded = std::chrono::system_clock::now() - start;
    std::cout << "Time needed for async-: " << std::chrono::duration<double>(timeNeeded).count() << "\n";


    start = std::chrono::system_clock::now();
    seqAssign();
    timeNeeded = std::chrono::system_clock::now() - start;
    std::cout << "Time needed for seqAssign: " << std::chrono::duration<double>(timeNeeded).count() << "\n";

    /*
     * Time needed for async-: 8.79e-05
     * Time needed for seqAssign: 0.0006108
     */

    // Task 5

    /*
     * Time needed for async-: 15.5755
     * Time needed for seqAssign: 15.514
     */

    // Task 6
    // Improved task 4


    return 0;
}
