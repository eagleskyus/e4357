#ifndef __CIRCULAR_BUFFER
#define __CIRCULAR_BUFFER

/* Implement a circularbuffer library with the following API interface */

/**< Circular Buffer Types */
typedef unsigned char INT8U;
typedef INT8U KeyType ;
typedef struct {  
    INT8U writePointer ; /**< write pointer */  
    INT8U readPointer ;  /**< read pointer */  
    INT8U size;         /**< size of circular buffer */
    INT8U mask;         /**< bit Mask of circular buffer size*/   
    KeyType keys[0];    /**< Element of ciruclar buffer */
} CircularBuffer ; 


inline int CircularBufferIsFull(CircularBuffer* que)
{
     return ((que->writePointer + 1) % que->size == que->readPointer); 
}
 
inline int CircularBufferIsEmpty(CircularBuffer* que)
{
     return ((que->readPointer + 1) % que->size == que->writePointer); 
}
 
inline int CircularBufferEnque(CircularBuffer* que, KeyType k)
{
        int isFull = CircularBufferIsFull(que);
        que->keys[que->writePointer] = k;
        que->writePointer++;
        que->writePointer %= que->size;
        return isFull;
}
 
inline int CircularBufferDeque(CircularBuffer* que, KeyType* pK)
{
        int isEmpty =  CircularBufferIsEmpty(que);
        *pK = que->keys[que->readPointer];
        que->readPointer++;
        que->readPointer %= que->size;
        return(isEmpty);
}

inline int CircularBufferPrint(CircularBuffer* que)
{
        int i=0;
        int isEmpty =  CircularBufferIsEmpty(que);
        int isFull  =  CircularBufferIsFull(que);
        printf("\n==Q: w:%d r:%d f:%d e:%d\n", 
            que->writePointer, que->readPointer,  isFull, isEmpty);
        for(i=0; i< que->size; i++)
        {
           printf("%d ", que->keys[i]);
        }
        printf("\n");
        return(isEmpty);
}

#endif
