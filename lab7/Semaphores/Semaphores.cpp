#include <iostream>
#include <barrier>
#include <thread>
#include <atomic>
#include <string>
#include <random>
#include <semaphore>

std::binary_semaphore sA(0), sB(0), sC(0);

void A()
{
	for (int i = 0; i < 6; i++)
	{
		std::cout << 'A';
		sC.release();
		sA.acquire();
		sB.release();
		sA.acquire();
		sB.release();
		sA.acquire();
		sC.release();
		sA.acquire();
	}
}
void B()
{
	for (int i = 0; i < 12; i++)
	{
		sB.acquire();
		std::cout << 'B';
		sA.release();
	}
}
void C()
{
	for (int i = 0; i < 12; i++)
	{
		sC.acquire();
		std::cout << 'C';
		sA.release();
	}
}


int buffer[4];

std::counting_semaphore<4> data(0), space(4);

void producer()
{
	int end = 0;
	for (int i = 0; i < 30; i++)
	{
		space.acquire();
		buffer[end] = i;
		data.release();
		end = (end + 1) % 4;
	}
}
void consumer()
{
	int begin = 0;
	for (int i = 0; i < 30; i++)
	{
		data.acquire();
		std::cout << buffer[begin] << ' ';
		space.release();
		begin = (begin + 1) % 4;
	}
}
void philosopher(int i) {
	int left = i;
	int right = (i + 1) % 5;

	while (calories[0] < 10000 || calories[1] < 10000 || calories[2] < 10000 || calories[3] < 10000 || calories[4] < 10000)
	{
		if (fork[left].try_acquire()) {
			if (fork[right].try_acquire()) {
				calories[i] += 1000; //just to speed up a bit
				fork[right].release();
			}
			fork[left].release();
		}
	}
}

std::atomic<int> counter(0);
int used = 0;

void use() noexcept {
	counter -= 10;
	used += 1;
	std::cout << "Substraciting " << used << "\n";
}
std::barrier bar(10, use);

void increment(int x) {
	for (int i = 0; i < x; i++) {
		counter++;
		bar.arrive_and_wait();
	}
}

std::vector<int> vec;
std::barrier bar2(10);
std::binary_semaphore semPushAndPop{ 1 };
std::atomic<int> sum(0);


int RandomNumber()
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist100(1, 100);
	return dist100(rng);
}

void roll() {
	for (int i = 0; i < 10; i++)
	{
		semPushAndPop.acquire();
		int randNumTmp = RandomNumber();

		if (std::find(vec.begin(), vec.end(), randNumTmp) != vec.end()) {
			i--;
		}
		else {
			vec.push_back(randNumTmp);
		}
		semPushAndPop.release();

	}
	bar2.arrive_and_wait();
	for (int i = 0; i < 10; i++)
	{
		semPushAndPop.acquire();
		sum += vec[vec.size() - 1];
		vec.pop_back();
		semPushAndPop.release();
	}
}

int main() {
	std::cout << "================= Task 1 =================\n\n\n";
	std::thread thrA(A);
	std::thread thrB(B);
	std::thread thrC(C);
	thrA.join();
	thrB.join();
	thrC.join();
	std::cout << "\n\n\n";
	std::cout << "================= Task 2 =================\n\n\n";

	std::thread thrPro(producer);
	std::thread thrCon(consumer);
	thrPro.join();
	thrCon.join();
	std::cout << "\n\n\n";
	std::cout << "================= Task 3 =================\n\n\n";

	std::thread philosopher1(philosopher, 0);
	std::thread philosopher2(philosopher, 1);
	std::thread philosopher3(philosopher, 2);
	std::thread philosopher4(philosopher, 3);
	std::thread philosopher5(philosopher, 4);
	philosopher1.join();
	philosopher2.join();
	philosopher3.join();
	philosopher4.join();
	philosopher5.join();

	std::cout << "everyone is happy\n\n\n";

	std::cout << "================= Task 4 =================\n\n\n";
	std::vector<std::thread> threads;

	for (int i = 0; i < 10; i++)
		threads.push_back(std::thread(increment, 25));

	for (auto& th : threads)
		th.join();

	std::cout << "================= Task 5 =================\n\n\n";

	std::vector<std::thread> threads;

	for (int i = 0; i < 10; i++)
		threads.push_back(std::thread(roll));
	for (auto& th : threads)
		th.join();

	std::cout << "the sum is " << sum << "\n";

}