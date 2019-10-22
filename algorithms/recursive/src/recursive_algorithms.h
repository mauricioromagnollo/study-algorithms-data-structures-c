#ifndef RECURSIVE_ALGORITHMS_H_INCLUDED
#define RECURSIVE_ALGORITHMS_H_INCLUDED

typedef int data_t;

#define CHANGE(a,b) { \
  data_t x = *a; \
  *a = *b; \
  *b = x; \
} \

data_t sumTwoNumbers(data_t x, data_t y);
data_t multiplyTwoNumbers(data_t x, data_t y);
data_t sumPositivesPairsMinorEqual(data_t n);
data_t calculatePow(data_t base, data_t exponent);
data_t calculateArraySum(data_t *array, data_t arraySize);
data_t getHighestArrayValue(data_t *array, data_t arraySize);
data_t sumIntegerInterval(data_t startInterval, data_t endInterval);
data_t fibonacci(data_t n);
data_t factorial(data_t n);

#endif