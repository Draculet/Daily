#include <vector>
#include <cstdlib>
#include <iostream>
#include <time.h>
using namespace std;

int ToArrPos(int i, int j, int col){
    return i * col + j;
}

int main(void){
    int row, col, n;
    cin >> row;
    cin >> col;
    cin >> n;
    srand(time(nullptr));
    vector<int> arr(row * col);
    for (int i = 0; i < n; i++){
        arr[i] = 1;
    }

    for (int i = arr.size() - 1; i >= 0; i--){
        int randnum = rand() % (i + 1);
        int tmp = arr[i];
        arr[i] = arr[randnum];
        arr[randnum] = tmp;
    }
    
    vector<vector<int>> vec(row);
    for (int i = 0;i < row; i++){
        vec[i].resize(col);
    }

    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            int total = 0;
            
        }
    }
    
}