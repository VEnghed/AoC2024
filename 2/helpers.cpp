#include "helpers.h"
#include "iostream"
#include "math.h"

// Returns true if the steps are OK
bool checkSteps(int *steps, int len) {
    bool increasing = true;
    bool decreasing = true;
    bool stepsOK = true;

    for (int i = 1; i < len; i++) {
        increasing &= steps[i] > steps[i - 1];
        decreasing &= steps[i] < steps[i - 1];
        stepsOK &= abs(steps[i] - steps[i - 1]) < 4 && steps[i] != steps[i - 1];
    }

    return stepsOK && (increasing || decreasing);
}

// Returns true if the steps
bool checkStepsSkip(int *steps, int len) {
    for (size_t i = 0; i < len; i++) {
        int skippedStepArray[32] = {0};

        for (size_t j = 0; j < i; j++)
            skippedStepArray[j] = steps[j];

        for (size_t j = i + 1; j < len; j++)
            skippedStepArray[j - 1] = steps[j];

        if (checkSteps(skippedStepArray, len - 1))
            return true;
    }
    return false;
}