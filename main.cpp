#include "CallTracker.h"
#include <fstream>
#include <clocale>

int main() {
    setlocale(LC_ALL, "Russian");

    std::cout << "--- ТЕСТ 1: Конструктор по умолчанию (только телефон) ---" << std::endl;
    
    CallTracker tracker1("+375-29-111-22-33");
    tracker1.addCall(10.5);
    tracker1.addCall(25.0);
    tracker1.printInfo();

    std::cout << "\n--- ТЕСТ 2: Сохранение данных в файл ---" << std::endl;
   
    CallTracker tracker2("+1-555-777", "Илон Маск");
    tracker2.addCall(45.2);
    tracker2.addCall(18.3);
    
    std::cout << "Данные Илона Маска до сохранения:" << std::endl;
    tracker2.printInfo();

    std::ofstream outFile("calls_database.txt");
    if (outFile.is_open()) {
        outFile << tracker2; 
        outFile.close();
        std::cout << "[Успех] Данные успешно записаны в файл calls_database.txt" << std::endl;
    }

    std::cout << "\n--- ТЕСТ 3: Чтение данных из файла ---" << std::endl;

    CallTracker restoredTracker("000", "Пустой");
    
    std::ifstream inFile("calls_database.txt");
    if (inFile.is_open()) {
        inFile >> restoredTracker; 
        inFile.close();
        std::cout << "[Успех] Данные успешно считаны! Вот восстановленный абонент:" << std::endl;
        restoredTracker.printInfo();
    }

    std::cout << "\n--- ТЕСТ 4: Проверка оператора += (Суммирование минут) ---" << std::endl;
    double totalAllUsersMinutes = 0.0;

    totalAllUsersMinutes += tracker1;
    totalAllUsersMinutes += restoredTracker;

    std::cout << "Общее время разговоров со ВСЕМИ абонентами: " << totalAllUsersMinutes << " мин." << std::endl;

    return 0;
}
