#include <iostream>
#include <thread>
#include <mutex>
#include <functional>

int maxClients = 6;
int clientCounter = 0;

void clientThread() {
    while (clientCounter < maxClients)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        clientCounter++;
        std::cout << "Подошёл клиент. Количество клиентов: " << clientCounter << std::endl;
    }
}

void operatorThread() {
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        if (clientCounter > 0)
        {
            clientCounter--;
            std::cout << "Операционист обслужил клиента. Клиентов осталось: " << clientCounter << std::endl;
        }
        else
        {
            std::cout << "Операционист завершил работу. Число клиентов: " << clientCounter << std::endl;
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
