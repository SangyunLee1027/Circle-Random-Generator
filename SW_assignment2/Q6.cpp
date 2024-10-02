#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> query) {
    
    int front_ptr = 0;
    int back_ptr = arr.size()-1;
    
    for(int i = 0; i < query.size(); ++i){
        int q = query[i];
        if(i & 1){
            front_ptr += q;
            continue;
        }
        
        int back_num = (back_ptr - front_ptr - q); //from (back_ptr - front_ptr + 1- q - 1) 
        back_ptr -= back_num;
    }
    
    vector<int> answer(back_ptr - front_ptr + 1);
    copy(arr.begin()+front_ptr, arr.begin()+back_ptr +1, answer.begin());
    
    return answer;
}