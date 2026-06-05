#ifndef CALL_TRACKER_H
#define CALL_TRACKER_H

#include <iostream>

class CallTracker {
private:
    char* subscriberName;       
    char* phoneNumber;          
    double maxCallDuration;     
    double minCallDuration;     
    double totalDuration;       
    int totalCalls;             

public:
    CallTracker(const char* name, const char* phone);
    ~CallTracker();

    double getMaxDuration() const;
    double getMinDuration() const;
    double getTotalDuration() const;
    int getTotalCalls() const;
    double getAverageDuration() const;
    bool isFrequentCommunication() const;

    void addCall(double duration);
    void printInfo() const;
};

#endif
