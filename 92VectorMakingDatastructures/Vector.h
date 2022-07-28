#pragma once

// X: Why have we used ::operator delete() instead of simple delete[]?
// And Why have we used ::operator new() instead of simple new?
// whenever we try to add or remove elements and it resizes the vector we call the ReAlloc function
// the ReAlloc function creates a new array and deletes the old one
// whilst deleting the old one it calls the destructor of all the element objects
// If the element objects have heap allocated members, they will be destroyed as in Vector3 class we have m_MemoryBlock
// So...we just lost data members in our element objects simply because we copied them to new allocated memory...only because we added or removed elements from the vector
// SO:-
// We want to not call the destructors we do this shinanigan
// with ::operator delete() it just copies memory and not call the destructor

template <typename T>
class Vector{
    void ReAlloc(size_t newCapacity){
        // 1. allocate a new block of memory
        // 2. copy/move old elements into new block
        // 3. delete

        // 1.
        // no need to use smart pointers in this low level
        T* newBlock = (T*)::operator new(newCapacity * sizeof(T));   // X

        // this check is only for the loop
        // we just use this loop so the loop in 2. works correctly
        if(newCapacity < m_Size)
            m_Size = newCapacity;

        // 2.
        // we dont use memcpy because we want to call the copy constructors of these elements
        // memcpy only does a shallow copy we need a deep copy
        // as you'll see in "94" how even this move caused problems
        for(size_t i = 0; i < m_Size; i++)
            newBlock[i] = std::move(m_Data[i]);

        for(size_t i = 0; i < m_Size; i++)
            m_Data[i].~T();

        // 3.
        ::operator delete(m_Data, m_Capacity * sizeof(T));   // X
        m_Data = newBlock;
        m_Capacity = newCapacity;
    }
private:
    T* m_Data = nullptr;

    // the current element count in the vector
    size_t m_Size = 0;
    // the total capacity to store, so free slots = capacity - size
    // We use this:- because we want to minimize the heap allocations, with more capacity we dont have to reallocate on the heap each time a new element is added, instead we just keep filling the free slots
    // we could keep doubling the capacity each time more is needed
    // but that would also waste space, so we just add the current half capacity
    size_t m_Capacity = 0;
public:
    Vector(){
        // allocate 2 elements
        // this would be allocating memory, and responsible for moving old data in it + managing old memory
        ReAlloc(2);
    }
    ~Vector(){
        // here we call the destructor of all element objects before deleting destroying this Vector
        Clear();
        ::operator delete(m_Data, m_Capacity * sizeof(T));   // X
    }
    void PushBack(const T& value){
        // if our capacity full (size == capacity)
        // allocate new memory
        if(m_Size >= m_Capacity)
            ReAlloc(m_Capacity + m_Capacity /2);

        m_Data[m_Size] = value;
        m_Size++;
    }
    void PushBack(T&& value){
        if(m_Size >= m_Capacity)
            ReAlloc(m_Capacity + m_Capacity /2);

        m_Data[m_Size] = std::move(value);
        m_Size++;
    }

    // the emplace function instead of taking in the constructor for object, it instead takes in its parameters and constructs the Object itself!!!
    // here we use VARIATIC TEMPLATES*
    template<typename ...Args>
    T& EmplaceBack(Args&&... args){
        if(m_Size >= m_Capacity)
            ReAlloc(m_Capacity + m_Capacity /2);

        // here we have forwarded all our parameters to the constructor of the object/class, also unpacked them first with the ... operators
        // this new is called: PLACEMENT NEW*
        new(&m_Data[m_Size]) T(std::forward<Args>(args)...);
        return m_Data[m_Size++];
    }

    void PopBack(){
        if(m_Size > 0){
            m_Size--;
            // calling destructor of element as we remove it from our Vector
            m_Data[m_Size].~T();
        }
    }

    void Clear(){
        // calling destructor of element as we remove it from our Vector
        for(size_t i = 0; i < m_Size; i++)
            m_Data[i].~T();

        m_Size = 0;
    }

    // this is to prevent changing value inside array
    const T& operator[](size_t index) const {
        // if we try to access index greater than our size
        if(index >= m_Size){
            // assert
        }
        return m_Data[index];
    }

    // this will allow us to modify array element
    T& operator[](size_t index){
        if(index >= m_Size){
            // assert
        }
        return m_Data[index];
    }

    size_t Size() const { return m_Size; }
};