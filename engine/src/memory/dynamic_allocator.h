/**
 * @file dynamic_allocator.h
 * @author Travis Vroman (travis@kohiengine.com)
 * @brief Contains the implementation of the dynamic allocator.
 * @version 1.0
 * @date 2022-01-25
 * 
 * @copyright Kohi Game Engine is Copyright (c) Travis Vroman 2021-2022
 * 
 */

#pragma once

#include "defines.h"

/** @brief The dynamic allocator structure. */
typedef struct dynamic_allocator {
    /** @brief The allocated memory block for this allocator to use. */
    void* memory;
} dynamic_allocator;

/**
 * @brief Creates a new dynamic allocator. Should be called twice; once to obtain the memory
 * amount required (passing memory=0), and a second time with memory being set to an allocated block.
 * 
 * @param total_size The total size in bytes the allocator should hold. Note this size does _not_ include the size of the internal state.
 * @param memory_requirement A pointer to hold the required memory for the internal state _plus_ total_size.
 * @param memory An allocated block of memory, or 0 if just obtaining the requirement.
 * @param out_allocator A pointer to hold the allocator.
 * @return True on success; otherwise false.
 */
KAPI b8 dynamic_allocator_create(u64 total_size, u64* memory_requirement, void* memory, dynamic_allocator* out_allocator);

/**
 * @brief Destroys the given allocator.
 * 
 * @param allocator A pointer to the allocator to be destroyed.
 * @return True on success; otherwise false.
 */
KAPI b8 dynamic_allocator_destroy(dynamic_allocator* allocator);

/**
 * @brief Allocates the given amount of memory from the provided allocator.
 * 
 * @param allocator A pointer to the allocator to allocate from.
 * @param size The amount in bytes to be allocated.
 * @return The allocated block of memory unless this operation fails, then 0.
 */
KAPI void* dynamic_allocator_allocate(dynamic_allocator* allocator, u64 size);

/**
 * @brief Frees the given block of memory.
 * 
 * @param allocator A pointer to the allocator to free from.
 * @param block The block to be freed. Must have been allocated by the provided allocator.
 * @param size The size of the block.
 * @return True on success; otherwise false.
 */
KAPI b8 dynamic_allocator_free(dynamic_allocator* allocator, void* block, u64 size);

/**
 * @brief Obtains the amount of free space left in the provided allocator.
 * 
 * @param allocator A pointer to the allocator to be examined.
 * @return The amount of free space in bytes.
 */
KAPI u64 dynamic_allocator_free_space(dynamic_allocator* allocator);
