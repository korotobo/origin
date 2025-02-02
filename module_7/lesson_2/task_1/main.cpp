#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>

int maxClients = 6;
std::atomic<int> clientCounter(0);

void clientThread() {
    while (clientCounter.load() < maxClients)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        clientCounter++;
        std::cout << "Подошёл клиент. Количество клиентов: " << clientCounter.load() << std::endl;
    }
}

void operatorThread() {
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        int currentClients = clientCounter.load();
        if (currentClients > 0)
        {
            clientCounter--;
            std::cout << "Операционист обслужил клиента. Клиентов осталось: " << clientCounter.load() << std::endl;
        }
        else
        {
            std::cout << "Операционист завершил работу. Число клиентов: " << clientCounter.load() << std::endl;
            break;
        }
    }
}

int main() {
    std::thread clientT(clientThread);
    std::thread operatorT(operatorThread);

    clientT.join();
    operatorT.join();

    return 0;
}
