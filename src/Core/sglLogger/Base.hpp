#pragma once

#include <memory>
#include <string>
#include <utility>
#include <iostream>


template<typename T>
using UniquePtr = std::unique_ptr<T>;

template<typename T>
using SharedPtr = std::shared_ptr<T>;

using String = std::string;

template<typename T>
UniquePtr<T> createUnique(auto&&... args)
{
  	return std::make_unique<T>(std::forward<decltype(args)>(args)...);
}

