#include <iostream>
#include <mutex>
#include <thread>
#include <utility>

class Data {
public:
    int value;
    mutable std::mutex mtx;

    Data(int v) : value(v) {}
};

void swap_lock(Data& a, Data& b) {
    std::lock(a.mtx, b.mtx);
    std::lock_guard<std::mutex> lockA(a.mtx, std::adopt_lock);
    std::lock_guard<std::mutex> lockB(b.mtx, std::adopt_lock);

    std::swap(a.value, b.value);
}

void swap_scoped_lock(Data& a, Data& b) {
    std::scoped_lock lock(a.mtx, b.mtx);
    std::swap(a.value, b.value);
}

void swap_unique_lock(Data& a, Data& b) {
    std::unique_lock<std::mutex> lockA(a.mtx);
    std::unique_lock<std::mutex> lockB(b.mtx);

    std::swap(a.value, b.value);
}

void thread_lock(Data& a, Data& b) {
    swap_lock(a, b);
    std::cout << "swap_lock: data1 = " << a.value << ", data2 = " << b.value << std::endl;
}

void thread_scoped_lock(Data& a, Data& b) {
    swap_scoped_lock(a, b);
    std::cout << "swap_scoped_lock: data1 = " << a.value << ", data2 = " << b.value << std::endl;
}

void thread_unique_lock(Data& a, Data& b) {
    swap_unique_lock(a, b);
    std::cout << "swap_unique_lock: data1 = " << a.value << ", data2 = " << b.value << std::endl;
}

int main() {
    Data data1(10);
    Data data2(20);

    std::cout << "before swap: data1 = " << data1.value << ", data2 = " << data2.value << std::endl;

    std::thread t1(thread_lock, std::ref(data1), std::ref(data2));
    std::thread t2(thread_scoped_lock, std::ref(data1), std::ref(data2));
    std::thread t3(thread_unique_lock, std::ref(data1), std::ref(data2));

    t1.join();
    t2.join();
    t3.join();

    std::cout << "after swaps: data1 = " << data1.value << ", data2 = " << data2.value << std::endl;

    return 0;
}
