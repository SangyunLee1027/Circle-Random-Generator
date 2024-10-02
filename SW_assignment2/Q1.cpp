#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n, int k) {
    int temp_k = k-n/10;
    int fianl_k =  temp_k < 0 ? 0 : temp_k;
    int total_price = 12000 * n + 2000 * fianl_k;
    return total_price;
}