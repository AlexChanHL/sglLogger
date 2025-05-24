#pragma once

#include <memory>


template<typename T>
using UniquePtr = std::unique_ptr<T>;

template<typename T>
using SharedPtr = std::shared_ptr<T>;

template<typename T, typename... Args>
UniquePtr<T> createUnique(Args... args)
{
    return UniquePtr<T>(std::forward(args)...);
}

