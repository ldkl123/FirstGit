#include<iostream>
#include<math.h>
#include<ctime>
#include<cstdlib>

using namespace std;
/*
int s[100] = {0};
int pivot = 0;
int count = 0;

void partition(int low, int high, int* pivot){
    //cout << "partition in\n";

    int pivotitem = s[low];
    int j = low;
    int temp = 0;

    for(int i = low+1; i<=high; i++){
        if(s[i] < pivotitem){
            j++;
            temp = s[j];
            s[j] = s[i];
            s[i] = temp;
            count++;
        }
    }
    *pivot = j;
    temp = s[low];
    s[low] = s[*pivot];
    s[*pivot] = temp;
    count++;
}

void quicksort(int low, int high){
    //cout << "quicksort in\n";
    if(high>low){
        partition(low, high, &pivot);
        quicksort(low, pivot-1);
        quicksort(pivot+1, high);
    }
}

void random_num_insert(int a[]){
    srand((unsigned int)time(NULL));
    for(int i=0; i<100; i++){
        a[i] = rand()%100;
    }
}

int main(){

    random_num_insert(s);
    
    clock_t begin, end;
    begin = clock();  


    for(int i=0; i<99; i++){
        cout<< s[i] << " ";
    }
    cout << "\n";
    
    quicksort(0, 99);   

    for(int i=0; i<99; i++){
        cout<< s[i] << " ";
    }
    cout << "\n";

    end = clock();          // 시간설정
    cout<<"수행시간 : "<<((end-begin)/CLOCKS_PER_SEC)<<endl;
    cout << "Exchange : "<< count << "\n";
    return 0;

}

class Node{
    public:
    int data;
    Node* next;

    Node();

};

Node::Node(){
    next = NULL;
}

class LinkedList{

    public:
    LinkedList();

    void AddLink(int data, int idx);
    int Search(int item);
    

    Node* head;
    
};

LinkedList::LinkedList(){
    head = NULL;
}

int LinkedList::Search(int item){
    Node* temp;
    int index=0;
    temp = head; 
    if(temp == NULL){
        cout << "Empty List\n";
        return -1;
    }
    while(temp!=NULL){
        index++;
        if(temp->data == item){
            cout << "Index is " << index;
            return index; 
        }
        temp = temp->next;
    }

    cout << "No item in List\n";
    return -1;
}

void LinkedList::AddLink(int data, int idx){
    Node* node = new Node;
    
    node->data = data;

    Node* temp = head;
    Node* temp2 = NULL;
    int index=0;
    
    if(temp==NULL){
        head->next = node;
        cout << "not error\n";
    }
    else{
        index++;
        while(index != idx){
            temp = temp->next;
        }
        temp2 = temp->next;
        temp->next = node;
        node->next = temp2;
    }
}

int main(){

    LinkedList List;
    
    List.AddLink(10, 10);

}*/

struct heap{
    int S[10];
    int heapsize;
};

void siftdown(heap* H, int i){
    int parent, largerchild;
    int siftkey;
    bool spotfound;
    
    siftkey = H->S[i];
    parent = i;
    spotfound = false;

    while(2*parent <= H->heapsize && !spotfound){
        if(2*parent < H->heapsize && H->S[2*parent]){
            largerchild = 2*parent + 1;
        }
        else{
            largerchild = 2*parent;
        }
        if(siftkey < H->S[largerchild]){
            H->S[parent] = H->S[largerchild];
            parent = largerchild;
        }
        else{
            spotfound = true;
        }
        H->S[parent] = siftkey;
    }
}

void makeheap(int n, heap* H){
    int i;
    H->heapsize = n;
    for(int i = int(n/2); i>=1; i--){
        siftdown(H, i);
    }
}

int root(heap* H){
    int keyout;

    keyout = H->S[0];
    H->S[0] = H->S[(H->heapsize)-1];
    H->heapsize = H->heapsize-1;
    siftdown(H, 0);
    return keyout;
}

void removekeys(int n, heap* H, int S[]){
    int i;

    for(i=n-1; i>=0; i--){
        S[i] = root(H);
    }
}

void heapsort(int n, heap* H){
    makeheap(n, H);
    removekeys(n, H, H->S);
}

int main(){
    //struct heap H1;
    int s[10] = {12 ,19, 16, 14, 11, 20, 25, 30, 18, 17};
    
    for(int i=0; i>10; i++){
        cout << s[i] << " ";
        //H1.S[i] = s[i];
        
    }
    cout << "\n";
    //heapsort(10, &H1);

    //for(int i=0; i>10; i++){
    //    cout << H1.S[i] << " ";
    //}
    cout << "\n";
}
