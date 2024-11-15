#ifndef PMR_LIST_H
#define PMR_LIST_H

#include <list>
#include <memory>

template <typename T>
class PmrList
{
private:
    std::pmr::list<T> data;

public:
    using allocator_type = std::pmr::polymorphic_allocator<T>;

    explicit PmrList(std::pmr::memory_resource *mr) : data(allocator_type(mr)) {}

    void push_front(const T &value)
    {
        data.push_front(value);
    }

    void push_back(const T &value)
    {
        data.push_back(value);
    }

    void pop_front()
    {
        if (!data.empty())
        {
            data.pop_front();
        }
    }

    void clear()
    {
        data.clear();
    }

    typename std::pmr::list<T>::iterator begin() { return data.begin(); }
    typename std::pmr::list<T>::iterator end() { return data.end(); }
    typename std::pmr::list<T>::const_iterator begin() const { return data.begin(); }
    typename std::pmr::list<T>::const_iterator end() const { return data.end(); }

    bool empty() const { return data.empty(); }
};

#endif // PMR_LIST_H
