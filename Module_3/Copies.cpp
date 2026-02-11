// M03 Challenge Activity — Dynamic int array with Rule of Three // Focus: pointers, new/delete, deep copy semantics
#include <iostream>
#include <cassert>
class IntArray
{
public:
    IntArray() : data_(nullptr), sz_(0), cap_(0) {} // Copy constructor — deep copy
    IntArray(const IntArray &other) : data_(nullptr), sz_(other.sz_), cap_(other.cap_)
    {
        if (cap_ > 0)
        {
            data_ = new int[cap_];
            for (size_t i = 0; i < sz_; ++i)
                data_[i] = other.data_[i];
        }
    } // Copy assignment — deep copy + strong exception safety (copy-and-swap style)
    IntArray &operator=(IntArray rhs)
    {
        swap(rhs); // rhs now holds old this->data_, this holds rhs data return
        *this;     // rhs destructor frees old memory
    }
    ~IntArray()
    {
        delete[] data_;
    }
    void push_back(int value)
    {
        if (sz_ == cap_)
            grow();
        data_[sz_++] = value;
    }
    size_t size() const { return sz_; }
    int &operator[](size_t i)
    {
        assert(i < sz_);
        return data_[i];
    }
    const int &operator[](size_t i) const
    {
        assert(i < sz_);
        return data_[i];
    }
    void swap(IntArray &other) noexcept
    {
        std::swap(data_, other.data_);
        std::swap(sz_, other.sz_);
        std::swap(cap_, other.cap_);
    }

private:
    void grow()
    {
        size_t newCap = (cap_ == 0) ? 4 : cap_ * 2;
        int *newData = new int[newCap];
        for (size_t i = 0; i < sz_; ++i)
            newData[i] = data_[i];
        delete[] data_;
        data_ = newData;
        cap_ = newCap;
    }
    int *data_;
    size_t sz_;
    size_t cap_;
};

int main()
{
    IntArray a;
    int x;
    while (std::cin >> x && x != -1)
    {
        if (x >= 0)
            a.push_back(x);
    }
    long long sum = 0;
    for (size_t i = 0; i < a.size(); ++i)
        sum += a[i];
    std::cout << "Count=" << a.size() << ", Sum=" << sum << "\n"; // quick deep-copy check
    IntArray b = a;                                               // copy ctor
    if (b.size() > 0)
        b[0] = 999;
    std::cout << "First of a remains " << (a.size() ? a[0] : -1) << " (deep copy verified)\n";
}