#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_prefix) {
    if(is_prefix.length() > my_string.length()){
        return 0;
    }
    
    for(int i = 0; i < is_prefix.length(); ++i){
        if(my_string[i] != is_prefix[i]){
            return 0;
        }
    }
    
    return 1;
}