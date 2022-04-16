// conditionVariable.cpp

#include <iostream>
#include <condition_variable>
#include <mutex>
#include <thread>

std::mutex m;
std::condition_variable condVar;

// 3. - Processes the data
void doTheWork() {
  std::cout << "Processing shared data." << std::endl;
}

// 1. - Waits until the data is ready for being processed
void waitingForWork() {
    std::cout << "Worker: Waiting for work." << std::endl;
    std::unique_lock<std::mutex> lck(m);
    condVar.wait(lck);
    doTheWork();
    std::cout << "Work done." << std::endl;
}

// 2. - Notifies that the data is ready for being processed
void setDataReady() {
    std::cout << "Sender: Data is ready."  << std::endl;
    condVar.notify_one();
}

int main() {

    // is locked until setDataReady() unlocks it
  std::thread t1(waitingForWork);
    // unlocks waitingForWork() so doTheWork() is started
  std::thread t2(setDataReady);

  t1.join();
  t2.join();
}
