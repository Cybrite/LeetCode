class MyCircularDeque {
public:
    vector<int> data;
    int head, tail, size, count;

    MyCircularDeque(int k) {
        data.resize(k);
        head = 0;
        tail = k-1;
        size = k;
        count = 0;
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;

        head = (head - 1 + size) % size;
        data[head] = value;
        count++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;

        tail = (tail + 1) % size;
        data[tail] = value;
        count++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;

        head = (head + 1) % size;
        count--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;

        tail = (tail - 1 + size) % size;
        count--;
        return true;
    }
    
    int getFront() {
        return isEmpty() ? -1 : data[head];
    }
    
    int getRear() {
        return isEmpty() ? -1 : data[tail];
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == size;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */