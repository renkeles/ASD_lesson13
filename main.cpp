#include <iostream>
const int SIZE_ST = 1000;

#define T int
T Stack[SIZE_ST];
int cursor = -1;

bool push(T data){
    if(cursor < SIZE_ST){
        Stack[++cursor] = data;
        return true;
    }else{
        std::cout << "(push) Stack overflow" << std::endl;
        return false;
    }
}

T pop(){
    if(cursor != -1){
        return Stack[cursor--];
    }else{
        std::cout << "(pop) Stack is empty" << std::endl;
        return -1;
    }
}



const size_t peaks = 6;
int matrix[peaks][peaks] = {
        {0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1, 1},
        {0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0}
};

size_t visited[peaks] = {0};

void depthTravers(int st){

    visited[st] = 1;
    for(size_t i = 0; i < peaks; i++){
        if(matrix[st][i] == 1 && !visited[i]){
            depthTravers(i);
        }
    }
    push(st);
}

void resetArr(){
    for(size_t i = 0; i < peaks; i++){
        visited[i] = 0;
    }
}

void printDepthTravers(int n){
    depthTravers(n);
    while(cursor != -1){
        std::cout.width(2);
        std::cout << pop();
    }
    resetArr();
    std::cout << std::endl;
}

void task1(){
    printDepthTravers(2);
    printDepthTravers(0);
    printDepthTravers(1);
}

int main() {

    //task1();


    return 0;
}
