#include "../include/bitstring.h"

BitString::BitString() : _size{0}, _data{nullptr} {}

BitString::BitString(const size_t &n, unsigned char t)
{
    validateBit(t);
    _size = n;
    _data = new unsigned char[n];
    for (int i = 0; i < n; ++i)
    {
        _data[i] = t;
    }
}

BitString::BitString(const std::initializer_list<unsigned char> &t)
{
    _size = t.size();
    _data = new unsigned char[_size];

    size_t i = 0;
    for (unsigned char digit : t)
    {
        validateBit(digit);
        _data[i++] = digit;
    }
}

BitString::BitString(const std::string &t)
{
    _size = t.size();
    _data = new unsigned char[_size];

    for (size_t i = 0; i < _size; i++)
    {
        validateBit(t[i]);
        _data[i] = t[i];
    }
}

BitString::BitString(const BitString &other)
{
    _size = other._size;
    _data = new unsigned char[_size];

    for (size_t i = 0; i < _size; ++i)
    {
        _data[i] = other._data[i];
    }
}

BitString::BitString(BitString &&other) noexcept
{
    _size = other._size;
    _data = other._data;
    other._data = nullptr;
    other._size = 0;
}

BitString &BitString::operator=(const BitString &other)
{
    if (this == &other)
    {
        return *this;
    }

    delete[] _data;
    _size = other._size;
    _data = new unsigned char[_size];

    for (size_t i = 0; i < _size; ++i)
    {
        _data[i] = other._data[i];
    }

    return *this;
}

BitString &BitString::operator&=(const BitString &other)
{
    if (_size != other._size)
    {
        throw std::invalid_argument("Размеры битовых строк должны совпадать");
    }

    for (size_t i = 0; i < _size; ++i)
    {
        _data[i] &= other._data[i];
    }

    return *this;
}

BitString &BitString::operator|=(const BitString &other)
{
    if (_size != other._size)
    {
        throw std::invalid_argument("Размеры битовых строк должны совпадать");
    }

    for (size_t i = 0; i < _size; ++i)
    {
        _data[i] |= other._data[i];
    }

    return *this;
}

BitString &BitString::operator^=(const BitString &other)
{
    if (_size != other._size)
    {
        throw std::invalid_argument("Размеры битовых строк должны совпадать");
    }

    for (size_t i = 0; i < _size; ++i)
    {
        _data[i] ^= other._data[i];
    }

    return *this;
}

BitString BitString::operator~() const
{
    BitString result = *this;
    for (size_t i = 0; i < this->getSize(); ++i)
    {
        if (result._data[i] != 0 && result._data[i] != 1)
        {
            throw std::invalid_argument("Invalid bit value");
        }
        result._data[i] = (_data[i] == 0) ? 1 : 0;
    }
    return result;
}

bool BitString::operator==(const BitString &other) const
{
    if (_size != other._size)
    {
        return false;
    }

    for (size_t i = 0; i < _size; i++)
    {
        if (_data[i] != other._data[i])
        {
            return false;
        }
    }
    return true;
}

bool BitString::operator<(const BitString &other) const
{
    return std::lexicographical_compare(_data, _data + _size, other._data, other._data + _size);
}

bool BitString::operator>(const BitString &other) const
{
    return other < *this;
}

size_t BitString::getSize() const
{
    return _size;
}

unsigned char *BitString::getData() const
{
    return _data;
}

BitString::~BitString() noexcept
{
    delete[] _data;
    _data = nullptr;
    _size = 0;
}

void BitString::validateBit(unsigned char digit)
{
    if (digit != '0' && digit != '1')
    {
        throw std::invalid_argument("Invalid bit value");
    }
}
