#include <thread>
#include <mutex>
#include <iostream>
#include <atomic>
#include <future>
#include <chrono>
#include <vector>

// For task 3:
std::atomic<bool> ready (false);
void count1m(int id) {
    while (!ready) {  // wait until main() sets ready...
        std::this_thread::yield();
    }
    for (int i=0; i<1000000; ++i) {
        std::cout<< i<< ' ';
    }
    std::cout << id << ' ';
}

// For task 4:
std::mutex vectLock;
std::vector<unsigned int> primeVec;

void findPrimes(unsigned int start, unsigned int end) {
    for (unsigned int x = start; x <= end; x += 2) {
        for (unsigned int y = 2; y < x; y++) {
            if ((x % y) == 0) {
                break;
            } else if ((y + 1) == x) {
                std::lock_guard<std::mutex> lock(vectLock);
                primeVec.push_back(x);
            }
        }
    }
}

void findPrimesWithThreads(unsigned int start, unsigned int end,
                           unsigned int numThreads) {
    std::vector<std::jthread> threadVect;
    unsigned int threadSpread = end / numThreads;
    unsigned int newEnd = start + threadSpread - 1;

    for (unsigned int x = 0; x < numThreads; x++) {
        threadVect.emplace_back(findPrimes, start, newEnd);
        start += threadSpread;
        newEnd += threadSpread;
    }
}

int main() {

    // Task 1
    // Create a lambda function which increments an integer by one.
    // Create a pool with 50 threads and let all of them execute this function.
    // Check the consistency in results, explain it.
    auto add_1 = [](std::atomic<int> &i) { i += 1; };
    int i = 1;
    std::cout << i << '\n';
    std::thread threads[49];
    for (auto &e: threads) {
        e = std::thread(add_1, std::ref(i));
    }
    for (auto &th: threads) {
        th.join();
    }
    std::cout << '\n' << i << '\n'; // prints 3

    // Task 2
    // Create a new version of the task 1 using mutex or atomic variables to avoid races.
    // How did the output change?
    auto add_1 = [](std::atomic<int> &i) { i += 1; };
    std::atomic<int> i = 1;
    std::cout << i << '\n';
    std::thread threads[49];
    for (auto &e: threads) {
        e = std::thread(add_1, std::ref(i));
    }
    for (auto &th: threads) {
        th.join();
    }
    std::cout << '\n' << i << '\n'; // prints 3

    // Task 3
    // Create a function which will simply iterate through 1mln times.
    // In the pool of 10 threads execute this function but all threads should wait and start at
    // the same time, when the whole pool is defined.
    std::thread threads[10];
    std::cout << "race of 10 threads that count to 1 million:\n";
    for (int i=0; i<10; ++i) threads[i]=std::thread(count1m,i);
    ready = true; // go!
    for (auto& th : threads) th.join();

    // Task 4
    // Create a function or functions that together fill a vector with prime numbers from a given range
    // (e.g. 1-100000). Do it such that you can specify the number of threads you want to use,
    // measure time, and compare it.
    int startTime = clock();
    // findPrimesWithThreads(1, 1000000, 1);
    int endTime = clock();

    // for (auto &n : primeVec) std::cout << n << std::endl;
    std::cout << "Execution time (one thread): "
              << (endTime - startTime) / double(CLOCKS_PER_SEC) << std::endl;

    primeVec.clear();
    startTime = clock();
    findPrimesWithThreads(1, 1000000, 7);
    endTime = clock();

    std::cout << "Execution time (more threads): "
              << (endTime - startTime) / double(CLOCKS_PER_SEC) << std::endl;
}

