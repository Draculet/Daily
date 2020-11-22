#include <vector>
#include <cstdlib>
#include <iostream>
#include <time.h>
using namespace std;

int ToArrPos(int i, int j, int col){
    return i * col + j;
}

bool proper(int i, int j, int row, int col){
    if (i >= 0 && i < row && j >= 0 && j < col){
        //printf("%d %d ok\n", i , j);
        return true;
    }
    return false;
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
            if (proper(i - 1, j - 1, row, col)) 
                total += arr[(i - 1)*col + j - 1];
            if (proper(i - 1, j, row, col)) 
                total += arr[(i - 1)*col + j];
            if (proper(i - 1, j + 1, row, col)) 
                total += arr[(i - 1)*col + j + 1];
            if (proper(i, j - 1, row, col)) 
                total += arr[i*col + j - 1];
            if (proper(i, j + 1, row, col)) 
                total += arr[i*col + j + 1];
            if (proper(i + 1, j - 1, row, col)) 
                total += arr[(i + 1)*col + j - 1];
            if (proper(i + 1, j, row, col)) 
                total += arr[(i + 1)*col + j];
            if (proper(i + 1, j + 1, row, col)) 
                total += arr[(i + 1)*col + j + 1];
            //printf("total: %d\n", total);
            vec[i][j] = total;
        }
    }
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            printf("%d ", arr[i*col + j]);
        }
        printf("\n");
    }

    printf("\n\n");
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            printf("%d ", vec[i][j]);
        }
        printf("\n");
    }
}