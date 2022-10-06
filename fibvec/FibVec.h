# include <cstddef>


class FibVec {
    private:
        size_t mCount=0;
        size_t mCapacity=1;
        int* data=new int [1];
    public:
        FibVec();
        ~FibVec();
        size_t capacity() const;
        size_t count() const;
        void insert(int value, size_t index);
        int lookup(size_t index) const;
        int pop();
        void push(int lastValue);
        int remove(size_t index);
        FibVec slice(size_t index, size_t count) const;


};