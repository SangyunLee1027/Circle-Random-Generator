#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, int k) {
    int answer = 0;
    int max_i = k < board.size()-1 ? k : board.size()-1;
    for(int i = 0; i <= max_i; ++i){
        int j = k-i < board[i].size()-1 ? k-i : board[i].size() - 1;
        for(j ; j >= 0; --j){
            answer += board[i][j];
        }
    }
    return answer;
}