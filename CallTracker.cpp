#include "CallTracker.h"
#include <cstring>
#include <stdexcept>

CallTracker::CallTracker(const char* phone, const char* name) {
    if (phone == nullptr) {
        throw std::invalid_argument("Ошибка: Указатель на телефон не может быть nullptr!");
    }
    if (std::strlen(phone) == 0) {
        throw std::logic_error("Ошибка: Номер телефона не может быть пустым!");
    }

    phoneNumber = new char[std::strlen(phone) + 1];
    std::strcpy(phoneNumber, phone);

    if (name == nullptr || std::strlen(name) == 0) {
        subscriberName = new char[std::strlen(phone) + 1];
        std::strcpy(subscriberName, phone);
    } else {
        subscriberName = new char[std::strlen(name) + 1];
        std::strcpy(subscriberName, name);
    }

    maxCallDuration = 0.0;
    minCallDuration = 0.0;
    totalDuration = 0.0;
    totalCalls = 0;
}

CallTracker::~CallTracker() {
    delete[] subscriberName;
    delete[] phoneNumber;
}

double CallTracker::getMaxDuration() const { return maxCallDuration; }
double CallTracker::getMinDuration() const { return minCallDuration; }
double CallTracker::getTotalDuration() const { return totalDuration; }
int CallTracker::getTotalCalls() const { return totalCalls; }

double CallTracker::getAverageDuration() const {
    if (totalCalls == 0) {
        throw std::runtime_error("Ошибка: Нет звонков для расчета среднего времени!");
    }
    return totalDuration / totalCalls;
}

bool CallTracker::isFrequentCommunication() const {
    return totalDuration > 60.0;
}

void CallTracker::addCall(double duration) {
    if (duration <= 0) {
        throw std::out_of_range("Ошибка: Длительность звонка должна быть больше нуля!");
    }
    if (totalCalls == 0) {
        minCallDuration = duration;
        maxCallDuration = duration;
    } else {
        if (duration > maxCallDuration) maxCallDuration = duration;
        if (duration < minCallDuration) minCallDuration = duration;
    }
    totalDuration += duration;
    totalCalls++;
}

void CallTracker::printInfo() const {
    std::cout << "========================================" << std::endl;
    std::cout << "Абонент: " << subscriberName << std::endl;
    std::cout << "Телефон: " << phoneNumber << std::endl;
    std::cout << "Всего звонков: " << totalCalls << std::endl;
    std::cout << "Общая длительность: " << totalDuration << " мин." << std::endl;
    std::cout << "Макс. звонок: " << maxCallDuration << " мин." << std::endl;
    std::cout << "Мин. звонок: " << minCallDuration << " мин." << std::endl;
    std::cout << "========================================" << std::endl;
}

std::ostream& operator << (std::ostream& out, const CallTracker& ourObject) {
    out << ourObject.subscriberName << "\n"
        << ourObject.phoneNumber << "\n"
        << ourObject.maxCallDuration << " "
        << ourObject.minCallDuration << " "
        << ourObject.totalDuration << " "
        << ourObject.totalCalls << "\n";
    return out;
}

std::istream& operator >> (std::istream& in, CallTracker& ourObject) {
    char bufferName[256];
    char bufferPhone[256];

    in.getline(bufferName, 256);
    in.getline(bufferPhone, 256);

    if (std::strlen(bufferName) == 0 || std::strlen(bufferPhone) == 0) {
        return in; 
    }

    delete[] ourObject.subscriberName;
    delete[] ourObject.phoneNumber;

    ourObject.subscriberName = new char[std::strlen(bufferName) + 1];
    std::strcpy(ourObject.subscriberName, bufferName);

    ourObject.phoneNumber = new char[std::strlen(bufferPhone) + 1];
    std::strcpy(ourObject.phoneNumber, bufferPhone);

    in >> ourObject.maxCallDuration 
       >> ourObject.minCallDuration 
       >> ourObject.totalDuration 
       >> ourObject.totalCalls;
    
    in.ignore(); 
    return in;
}

double& operator += (double& sum, const CallTracker& ourObject) {
    sum += ourObject.getTotalDuration();
    return sum;
}
