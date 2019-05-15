//Programmed by Albert Nguyen

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct QueueNode { 
    char data; 
    unsigned freq; 
    struct QueueNode *left, *right; 
}; 

struct Queue { 
    int front, rear; 
    int capacity; 
    struct QueueNode **array; 
}; 
  
struct QueueNode* newNode(char data, unsigned freq) { 
    struct QueueNode* temp = (struct QueueNode*) malloc(sizeof(struct QueueNode)); 
    temp->left = temp->right = NULL; 
    temp->data = data; 
    temp->freq = freq; 
    return temp; 
} 
  
struct Queue* createQueue(int capacity) { 
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue)); 
    queue->front = queue->rear = -1; 
    queue->capacity = capacity; 
    queue->array = (struct QueueNode**) malloc(queue->capacity * sizeof(struct QueueNode*)); 
    return queue; 
} 
  
bool isSizeOne(struct Queue* queue) { 
    if(queue->front == queue->rear && queue->front != -1) {
        return true;
    }
    else {
        return false;
    }
} 
  
bool isEmpty(struct Queue* queue) { 
    if(queue->front == -1) {
        return true;
    }
    else {
        return false;
    }
} 
  
bool isFull(struct Queue *queue) { 
    if(queue->rear == queue->capacity - 1) {
        return true;
    }
    else {
        return false;
    }
} 
  
void enQueue(struct Queue *queue, struct QueueNode *item) { 
    if(isFull(queue)) {
        return; 
    }
    queue->array[++queue->rear] = item; 
    if(queue->front == -1) {
        ++queue->front;
    } 
} 
  
struct QueueNode* deQueue(struct Queue *queue) { 
    if(isEmpty(queue)) {
        return NULL; 
    }

    struct QueueNode *temp = queue->array[queue->front]; 
    if(queue->front == queue->rear) {
        queue->front = queue->rear = -1; 
    }
    else {
        ++queue->front; 
    }
    return temp; 
} 
  
struct QueueNode* getFront(struct Queue *queue) {
    if(isEmpty(queue)) {
        return NULL; 
    }
    return queue->array[queue->front]; 
} 
  
struct QueueNode* findMin(struct Queue *firstQueue, struct Queue *secondQueue) { 
    if(isEmpty(firstQueue)) {
        return deQueue(secondQueue); 
    }

    if(isEmpty(secondQueue)) {
        return deQueue(firstQueue); 
    }

    if(getFront(firstQueue)->freq < getFront(secondQueue)->freq) {
        return deQueue(firstQueue); 
    }
  
    return deQueue(secondQueue); 
} 
  
bool isLeaf(struct QueueNode* root) { 
    if(root->left == NULL && root->right == NULL) {
        return true;
    }
    else {
        return false;
    }
} 
  
struct QueueNode* buildHuffmanTree(char data[], int freq[], int size) { 
    struct QueueNode *left, *right, *top; 
  
    struct Queue *firstQueue  = createQueue(size); 
    struct Queue *secondQueue = createQueue(size); 
  
    for (int i = 0; i < size; ++i) {
        enQueue(firstQueue, newNode(data[i], freq[i])); 
    }
  
    while(!(isEmpty(firstQueue) && isSizeOne(secondQueue))) { 
        left = findMin(firstQueue, secondQueue); 
        right = findMin(firstQueue, secondQueue); 
        top = newNode('$', left->freq + right->freq); 
        top->left = left; 
        top->right = right; 
        enQueue(secondQueue, top); 
    } 
    return deQueue(secondQueue); 
} 

void insertionSortString(string *codes, int size) {
    for(int i = 1; i < size; i++) {
        for(int j = i; j > 0; j--) {
            if(codes[j][0] < codes[j - 1][0]) {
                string temp = codes[j - 1];
                codes[j - 1] = codes[j];
                codes[j] = temp;
            } 
        }
    }
}  

void printCodes(struct QueueNode* root, int *code, int top) { 
    static string charAndCode[6];
    static int count = 0;
    if(root->left) { 
        code[top] = 0; 
        printCodes(root->left, code, top + 1); 
    } 
  
    if(root->right) { 
        code[top] = 1; 
        printCodes(root->right, code, top + 1); 
    } 
  
    if(isLeaf(root)) { 
        charAndCode[count] = root->data;
        charAndCode[count] += ":";
        ostringstream os;
        for(int i = 0; i < top; i++) {
            os << code[i];
        }
        string stringCode(os.str()); 
        charAndCode[count] += stringCode;
        count++;
        if(count == 6) {
            insertionSortString(charAndCode, 6);
            for(int i = 0; i < 6; i++) {
                cout << charAndCode[i] << endl;
            }
        }
    } 
} 

void insertionSort(int *freq, char *chars, int size) {
    for(int i = 1; i < size; i++) {
        for(int j = i; j > 0; j--) {
            if(freq[j] < freq[j - 1]) {
                int temp = freq[j - 1];
                freq[j - 1] = freq[j];
                freq[j] = temp;
                char temp2 = chars[j - 1];
                chars[j - 1] = chars[j];
                chars[j] = temp2;
            } 
        }
    }
}
  
void huffmanCode(char *chars, int *freq, int numOfCodes) { 
    insertionSort(freq, chars, numOfCodes);

    struct QueueNode *root = buildHuffmanTree(chars, freq, numOfCodes); 
  
    int code[6];
    printCodes(root, code, 0); 
} 

int main() {
    int numOfCodes = 6;

    int freq[numOfCodes];
    char chars[numOfCodes] = {'A', 'B', 'C', 'D', 'E', 'F'};

    for(int i = 0; i < numOfCodes; i++) {
        cin >> freq[i];
    }

    huffmanCode(chars, freq, numOfCodes);

    return 0;
}
