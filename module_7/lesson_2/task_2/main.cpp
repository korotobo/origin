#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <vector>

const int num_threads = 5;

const int calculation_length = 10;

const char fill_symbol = '#';

std::mutex mtx;

void calculate_and_print_progress(int thread_id, int thread_number) {

    auto start_time = std::chrono::high_resolution_clock::now();

    const int progress_bar_length = 20;

    const int num_iterations = progress_bar_length;

    int iteration = 0;

    while (iteration < num_iterations) {
        {
            std::lock_guard<std::mutex> lock(mtx);
            std::cout << "\033[" << thread_number + 1 << ";1H"; // перемещение курсора в начало строки
            std::cout << "thread " << thread_number << " (id: " << thread_id << "): ";
            for (int i = 0; i < progress_bar_length; ++i) {
                if (i < iteration) {
                    std::cout << fill_symbol;
                } else {
                    std::cout << " ";
                }
            }
            std::cout << " " << (iteration / (float)progress_bar_length * 100) << "%";
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        iteration++;
    }

    auto end_time = std::chrono::high_resolution_clock::now();

    {
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << "\033[" << thread_number + 1 << ";1H"; // перемещение курсора в начало строки
        std::cout << "thread " << thread_number << " (id: " << thread_id << "): ";
        for (int i = 0; i < progress_bar_length; ++i) {
            std::cout << fill_symbol;
        }
        std::cout << " 100% (time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count() << " ms)";
        std::cout << std::endl;
    }
}

int main() {
    std::cout << "\033[2J"; // очистка консоли
    std::cout << "\033[H"; // перемещение курсора в начало консоли

    std::vector<std::thread> threads;
    for (int i = 0; i < num_threads; ++i) {
        threads.emplace_back(calculate_and_print_progress, i, i + 1);
    }

    for (auto& thread : threads) {
        thread.join();
    }

    return 0;
}
