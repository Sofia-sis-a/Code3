#include "CallTracker.h"
#include <clocale>

int main() {
    setlocale(LC_ALL, "Russian");

    std::cout << "--- ТЕСТ 1: Нормальная работа класса ---\n" << std::endl;
    try {
        CallTracker tracker("Илон Маск", "+1-234-567-89-00");
        
        tracker.addCall(15.5);
        tracker.addCall(45.0); 
        tracker.addCall(5.2);

        tracker.printInfo();
        std::cout << "Средняя длительность звонка: " << tracker.getAverageDuration() << " мин.\n" << std::endl;

    } catch (const std::exception& e) {
        std::cout << "Перехвачено исключение: " << e.what() << std::endl;
    }

    std::cout << "\n--- ТЕСТ 2: Проверка обработки исключений ---\n" << std::endl;

    try {
        CallTracker testTracker("Тест", "+375291112233");
        testTracker.addCall(-5); 
    } catch (const std::exception& e) {
        std::cout << "Сработало исключение для addCall(): " << e.what() << std::endl;
    }

    try {
        CallTracker badTracker("", "+375291112233");
    } catch (const std::exception& e) {
        std::cout << "Сработало исключение для конструктора: " << e.what() << std::endl;
    }

    try {
        CallTracker emptyTracker("Новый Контакт", "+375290000000");
        std::cout << emptyTracker.getAverageDuration() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Сработало исключение для getAverageDuration(): " << e.what() << std::endl;
    }

    return 0;
}
