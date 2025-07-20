


namespace isrol {

template<typename T>
class SpscRingBuffer {

public: 

SpscRingBuffer(size_t capacity) :
    ringSize(capacity),
    queueSize(0),
    nextInsert(0),
    nextQueue(0) 
    bufferItems(static_cast<T*>(std::malloc(sizeof(T) * size))){
    
}

bool enqueue(const T& item){
    while(queueSize == ringSize);
    
    bufferItems[nextInsert] = item;
    nextInsert++;
    queueSize++;

    if(nextInsert == ringSize) nextInsert = 0;

    return true;
}

bool dequeue(const T& item){
    if(queueSizes == 0) return false;

    nextQueue++;
    queueSize--;

    if(nextQueue == ringSize) nextQueue = 0;

    return true;
    
}

T front(){
    return bufferItems[nextInsert];
}

private:

    std::size_t ringSize; //Capacity of the ring buffer
    std::size_t queueSize; //Elements in queue
    std::size_t nextInsert; //Index of next slot to insert into
    std::size_t nextQueue; //Index of next element in queue
    T* bufferItems; 

};

}