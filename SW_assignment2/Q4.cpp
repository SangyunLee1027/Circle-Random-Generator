#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {    
    
    int a_copy = a;
    int b_copy = b;
    int factor_a = 1;
    int factor_b = 1;
    
    while(a_copy > 0){
        factor_a *= 10;
        a_copy /= 10;
    }
    
    while(b_copy > 0){
        factor_b *= 10;
        b_copy /= 10;
    }
    
    int a_b = a * factor_b + b;
    int b_a = b * factor_a + a;
    
    
    return max(a_b, b_a);
}