#include "diff.h"

double calcDiff(double numInt) {
    double percentDiff;
    percentDiff = ((numInt - params.trueVal) / params.trueVal) * 100.0;
    return percentDiff;
}
