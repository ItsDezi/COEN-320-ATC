
#ifndef SRC_OPERATINGCONSOLE_H
#define SRC_OPERATINGCONSOLE_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <pthread.h>

using namespace std;

typedef struct {
    int readOrChange;
    int attributes;
    string ID;
    int newValue;
} Command;

class OperatingConsole {
public:
    void run();
    static void *runThread(void *arg);
};
#endif
