#ifndef FIXED_BLOCK_MEMORY_RESOURCE_H
#define FIXED_BLOCK_MEMORY_RESOURCE_H

#include <memory_resource>
#include <vector>
#include <cstddef>

class FixedBlockMemoryResource : public std::pmr::memory_resource
{
private:
    std::vector<std::byte *> allocated_blocks;
    size_t block_size;
    size_t capacity;

public:
    explicit FixedBlockMemoryResource(size_t block_size, size_t capacity);
    ~FixedBlockMemoryResource();

protected:
    void *do_allocate(std::size_t bytes, std::size_t alignment) override;
    void do_deallocate(void *p, std::size_t bytes, std::size_t alignment) override;
    bool do_is_equal(const std::pmr::memory_resource &other) const noexcept override;
};

#endif // FIXED_BLOCK_MEMORY_RESOURCE_H
