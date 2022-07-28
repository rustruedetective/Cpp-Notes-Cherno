#pragma once

template <typename Vector>
class VectorIterator{
public:
    using ValueType = typename Vector::ValueType;
    using PointerType = ValueType*;
    using ReferenceType = ValueType&;
private:
    // this pointer is not just the start, but also the current position of the iterator at all times
    PointerType m_Ptr;
public:
    VectorIterator(PointerType ptr)   // base of iterator...where is the iterator pointing to
     : m_Ptr(ptr) {}

    VectorIterator& operator++(){
        // we dont have to worry about incrementing by x bytes as due to PointerType template+using we have gotten the correct type of pointer (m_Ptr)
        m_Ptr++;
        return *this;
    }

    // this is the pre fix increment, denoted by the int in the parameter
    VectorIterator operator++(int){
        // we return a copy, because the pre fix will increment first before returning the current object unlike the postfix increment operator
        VectorIterator iterator = *this;
        ++(*this);
        return iterator;
    }

    VectorIterator& operator--(){
        m_Ptr--;
        return *this;
    }

    VectorIterator operator--(int){
        VectorIterator iterator = *this;
        --(*this);
        return iterator;
    }

    ReferenceType operator[](int index){
        return *(m_Ptr + index);
    }

    PointerType operator->(){
        return m_Ptr;
    }

    ReferenceType operator*(){
        return *m_Ptr;
    }

    bool operator==(const VectorIterator& other) const {
        return m_Ptr == other.m_Ptr;
    }

    bool operator!=(const VectorIterator& other) const {
        return !(*this == other);   // i dont get this
    }
};

template <typename T>
class Vector{
// this is just for simplicity
public:
    using ValueType = T;
    using Iterator = VectorIterator<Vector<T>>;
private:
    void ReAlloc(size_t newCapacity){
        // 1. allocate a new block of memory
        // 2. copy/move old elements into new block
        // 3. delete

        T* newBlock = (T*)::operator new(newCapacity * sizeof(T));

        if(newCapacity < m_Size)
            m_Size = newCapacity;

        for(size_t i = 0; i < m_Size; i++)
            new (&newBlock[i]) T(std::move(m_Data[i]));
            // newBlock[i] = std::move(m_Data[i]);
            // this commented block did not work for dynamically allocated types so we used the new approach above it

        for(size_t i = 0; i < m_Size; i++)
            m_Data[i].~T();

        ::operator delete(m_Data, m_Capacity * sizeof(T));
        m_Data = newBlock;
        m_Capacity = newCapacity;
    }
    T* m_Data = nullptr;

    size_t m_Size = 0;
    size_t m_Capacity = 0;

public:
    Vector(){
        // allocate 2 elements
        ReAlloc(2);
    }
    ~Vector(){
        Clear();
        ::operator delete(m_Data, m_Capacity * sizeof(T));
    }
    void PushBack(const T& value){
        if(m_Size >= m_Capacity)
            ReAlloc(m_Capacity + m_Capacity /2);

        m_Data[m_Size] = value;
        m_Size++;
    }

    template<typename ...Args>
    T& EmplaceBack(Args&&... args){
        if(m_Size >= m_Capacity)
            ReAlloc(m_Capacity + m_Capacity /2);

        new(&m_Data[m_Size]) T(std::forward<Args>(args)...);
        return m_Data[m_Size++];
    }

    void PopBack(){
        if(m_Size > 0){
            m_Size--;
            m_Data[m_Size].~T();
        }
    }

    void Clear(){
        for(size_t i = 0; i < m_Size; i++)
            m_Data[i].~T();

        m_Size = 0;
    }

    const T& operator[](size_t index) const {
        if(index >= m_Size){
            // assert
        }
        return m_Data[index];
    }

    T& operator[](size_t index){
        if(index >= m_Size){
            // assert
        }
        return m_Data[index];
    }

    size_t Size() const { return m_Size; }

    // we return constructors which make and return an iterator object
    // VectorIterator<Vector<T>> begin(){
    Iterator begin(){
        // return VectorIterator<Vector<T>>(m_Data);   // will point to the first element
        return (Iterator(m_Data));
    }

    // VectorIterator<Vector<T>> end(){
    Iterator end(){
        // return VectorIterator<Vector<T>>(m_Data + m_Size);   //m_Data pointer + offset by m_Size will point to last element
        return (Iterator(m_Data + m_Size));
    }
};