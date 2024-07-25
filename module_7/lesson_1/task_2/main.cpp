#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <iomanip>

static void sumVectors(double& sumOfVectors, const std::vector<int> newVector1, const std::vector<int> newVector2)
{
    for (int i = 0; i < newVector1.size(); ++i)
    {
        sumOfVectors += newVector1.at(i) + newVector2.at(i);
    }
}

int main()
{
    std::cout << "Число аппаратных ядер: " << std::thread::hardware_concurrency() << std::endl;
    std::cout << std::setw(9) << "\t\t1000" << "\t\t10000" << "\t\t100000" << "\t\t1000000" << std::endl;

    std::vector<int> vector1;
    std::vector<int> vector2;
    std::vector<int> numOfThreads{1, 2, 4, 8, 16};
    std::vector<int> sizeOfVector{1000, 10000, 100000, 1000000};

    for (auto& countT : numOfThreads)
    {
        std::cout << countT << " потоков";

       for (auto& countV : sizeOfVector)
        {
            vector1.resize(countV, 2);
            vector2.resize(countV, 5);
            std::vector<std::thread> threads;
            double sumOfVectors = 0;

            int partOfTheSize = static_cast<int> (countV / countT);

            auto thrStart = std::chrono::high_resolution_clock::now();
            for (int i = 0; i < countT; i++)
            {
                std::vector<int> newVector1;
                std::vector<int> newVector2;
                int rightBorder = 0;

                if (i != countT - 1)
                {
                    rightBorder = partOfTheSize * (i + 1);
                }
                else
                {
                    rightBorder = countV;
                }
                for (int j = partOfTheSize * i; j < rightBorder; ++j)
                {
                    newVector1.push_back(vector1.at(j));
                    newVector2.push_back(vector2.at(j));
                }
                threads.push_back(std::thread(sumVectors, std::ref(sumOfVectors), newVector1, newVector2));
            }
            for (auto& it : threads)
            {
                it.join();
            }

            auto thrStop = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::milli> thrTime = thrStop - thrStart;
            std::cout << std::setw(14) << thrTime.count() << "ms";
        }
        std::cout << std::endl;
    }
    return 0;
}
