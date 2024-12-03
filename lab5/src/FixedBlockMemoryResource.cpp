#include "FixedBlockMemoryResource.h"
#include <new>
#include <stdexcept>
#include <algorithm>

FixedBlockMemoryResource::FixedBlockMemoryResource(size_t block_size, size_t capacity)
    : block_size(block_size), capacity(capacity) {}

FixedBlockMemoryResource::~FixedBlockMemoryResource()
{
    for (auto block : allocated_blocks)
    {
        ::operator delete[](block);
    }
    allocated_blocks.clear();
}

void *FixedBlockMemoryResource::do_allocate(std::size_t bytes, std::size_t alignment)
{
    if (bytes > block_size)
    {
        throw std::bad_alloc();
    }
    if (allocated_blocks.size() < capacity)
    {
        void *ptr = ::operator new[](block_size, std::align_val_t(alignment));
        allocated_blocks.push_back(static_cast<std::byte *>(ptr));
        return ptr;
    }
    else
    {
        throw std::bad_alloc();
    }
}

void FixedBlockMemoryResource::do_deallocate(void *p, std::size_t bytes, std::size_t alignment)
{
    auto it = std::find(allocated_blocks.begin(), allocated_blocks.end(), static_cast<std::byte *>(p));
    if (it != allocated_blocks.end())
    {
        ::operator delete[](p, std::align_val_t(alignment));
        allocated_blocks.erase(it);
    }
    else
    {
        throw std::runtime_error("Attempted to deallocate memory not allocated by this resource.");
    }
}

bool FixedBlockMemoryResource::do_is_equal(const std::pmr::memory_resource &other) const noexcept
{
    return this == &other;
}
