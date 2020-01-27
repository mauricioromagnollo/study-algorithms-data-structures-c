#include <stdio.h>
#include <stdlib.h>
#include "recursive_algorithms.h"

data_t sumTwoNumbers(data_t x, data_t y) {
  if(y == 0) return x;
  else return (sumTwoNumbers(x, y - 1) + 1);
}

data_t multiplyTwoNumbers(data_t x, data_t y) {
  if(x == 0 || y == 0) return 0;
  else if(x == 1 || y == 1) return x;
  else return (multiplyTwoNumbers(x, y-1) + x);
}

data_t sumPositivesPairsMinorEqual(data_t n) {
  if(n <= 1) return 0;
  else if(n % 2 != 0) return sumPositivesPairsMinorEqual(n - 1);
  else if(n % 2 == 0) return (sumPositivesPairsMinorEqual(n - 2) + n);
}

data_t calculatePow(data_t base, data_t exponent) {
  if(exponent == 0 || base == 0) return 0;
  else if(exponent == 1 || base == 1) return base;
  else return (calculatePow(base, exponent - 1) * base);
}

data_t calculateArraySum(data_t *array, data_t arraySize) {
  if(arraySize == 0) {
    return 0;
  } else {
    data_t sum = calculateArraySum(array, arraySize - 1);
    if(array[arraySize - 1] > 0) {
      sum += array[arraySize - 1];
    }
    return sum;
  }
}

data_t getHighestArrayValue(data_t *array, data_t arraySize) {
  if(arraySize == 1) {
    return array[0];
  } else {
    data_t highestValue = getHighestArrayValue(array, arraySize - 1);
    if(highestValue > array[arraySize - 1]) {
      return highestValue;
    } else {
      return (array[arraySize - 1]);
    }
  }
}

data_t sumIntegerInterval(data_t startInterval, data_t endInterval) {
  if(endInterval < startInterval) {
    CHANGE(&startInterval, &endInterval);
  } else if(endInterval == (startInterval + 1)) {
    return (startInterval + endInterval);
  } else {
    return (startInterval + sumIntegerInterval( startInterval + 1, endInterval));
  }
}

data_t fibonacci(data_t n) {
  if(n == 0 || n == 1) {
    return n;
  } else {
    return fibonacci(n - 1) + fibonacci(n - 2);
  }
}

data_t factorial(data_t n) {
  if(n == 0) {
    return 1;
  } else {
    return (n * factorial(n - 1));
  }
}