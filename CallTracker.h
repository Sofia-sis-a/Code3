#ifndef CALL_TRACKER_H
#define CALL_TRACKER_H

#include <iostream>
#include <fstream>

class CallTracker {
private:
    char* subscriberName;
    char* phoneNumber;
    double maxCallDuration = 0.0;
    double minCallDuration = 0.0;
    double totalDuration = 0.0;
    int totalCalls = 0;

    static constexpr double FREQUENT_THRESHOLD = 60.0;

public:
    CallTracker(const char* phone, const char* name = nullptr);
    ~CallTracker();

    const char* getName() const;
    const char* getPhone() const;
    double getMaxDuration() const;
    double getMinDuration() const;
    double getTotalDuration() const;
    int getTotalCalls() const;

    double getAverageDuration() const;
    bool isFrequentCommunication() const;

    void addCall(double duration);
    void printInfo() const;

    // Перегрузка операторов ввода-вывода
    friend std::ostream& operator<<(std::ostream& out, const CallTracker& obj);
    friend std::istream& operator>>(std::istream& in, CallTracker& obj);
};

// Перегрузка оператора += вне класса
double& operator+=(double& sum, const CallTracker& obj);

#endif
