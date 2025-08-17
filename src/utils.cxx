#include "utils.h"

size_t pow_two(size_t n){
  return 1 << n;
}

size_t sum_of_pow_two(size_t n){
  return (pow_two(n+1) -1);
}
