#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list, int n) {
    vector<int> answer (num_list.size());
    int cnt = 0;
    for(int i = n; i < num_list.size(); ++i){
        answer[cnt++] = num_list[i];
    }
    for(int i = 0; i < n-1; ++i){
        answer[cnt++] = num_list[i];
    }
    answer[cnt] = num_list[n-1];
    return answer;
}