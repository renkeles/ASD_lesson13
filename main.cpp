#include <iostream>
#define T size_t

typedef struct Node{
    T dat;
    Node *next;
} Node;

typedef struct {
    Node *head;
    size_t size;
} List;

void initList(List *lst){
    lst->head = nullptr;
    lst->size = 0;
}

bool push(List *stack, T value){
    Node *tmp = new Node;
    if(tmp == nullptr){
        std::cout << "Stack overflow" << std::endl;
        return 0;
    }
    tmp->dat = value;
    tmp->next = stack->head;

    stack->head = tmp;
    stack->size++;
}

T pop(List *stack){
    if(stack->size == 0){
        std::cout << "Stack is empty" << std::endl;
        return -1;
    }
    Node *tmp = stack->head;
    T data = stack->head->dat;
    stack->head = stack->head->next;
    delete tmp;
    stack->size--;
    return data;
}

void printNode(Node* node){
    if(node == nullptr){
        std::cout << "[]";
        return;
    }
    std::cout << "[" << node->dat << "]";
}

void printList(List* lst){
    Node* current = lst->head;
    if(current == nullptr){
        printNode(current);
    }else{
        do{
            printNode(current);
            current = current->next;
        } while (current != nullptr);
    }
    std::cout << " Size: " << lst->size << std::endl;
}

/////////////////////////////////////////////////////////////////////////


const size_t peaks = 7;
int mas[peaks][peaks] = {   { 0, 1, 0, 1, 0, 0, 1 },
                            { 1, 0, 1, 0, 0, 0, 0 },
                            { 0, 1, 0, 0, 0, 0, 0 },
                            { 1, 0, 0, 0, 0, 1, 0 },
                            { 0, 0, 0, 0, 0, 1, 0 },
                            { 0, 0, 0, 1, 1, 0, 1 },
                            { 1, 0, 0, 0, 0, 1, 0 } };
int nodes[peaks] = {0};


void depthTravers(){
    List* stack = new List;
    initList(stack);

    push(stack,0);
    while (stack->size){
        int node = pop(stack);
        if(nodes[node] == 2) continue;
        nodes[node] = 2;
        for(int j = peaks - 1; j >= 0; j--){
            if(mas[node][j] == 1 && nodes[j] != 2){
                push(stack, j);
                nodes[j] = 1;
            }
        }
        //std::cout.width(5);
        //std::cout << node + 1;
        printf("%c\t", node + 65);
    }

}

int adjacencyLinks[peaks] = {0};
void adjacencyCount(){
    for(size_t i = 0; i < peaks; i++){
        for(size_t j = 0; j < peaks; j++){
            if(mas[i][j] == 1){
                if(i != j){
                    adjacencyLinks[i]++;
                }
            }
        }
    }
}
int traversalLinks[peaks] = {0};
int visited[peaks] = {0};
void traversalCount(int st){
    visited[st] = 1;



    for(int i = 0; i < peaks; i++){

        if(mas[st][i] == 1 && !visited[i]){

            traversalCount(i);
            traversalLinks[st]++;
        }
    }


}
void resetArr(){
    for(size_t i = 0; i < peaks; i++){
        visited[i] = 0;
    }
}

void printArr(int arr[], int size){
    for(size_t i = 0; i < size; i++){
        printf("%d\t", arr[i]);
    }
}

int main() {

    depthTravers();

    std::cout << std::endl;

    adjacencyCount();
    printArr(adjacencyLinks, peaks);

    std::cout << std::endl;

    traversalCount(0);
    printArr(adjacencyLinks, peaks);

    return 0;
}
