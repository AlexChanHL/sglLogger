#pragma once

#include <memory>
#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <ctime>
#include <stdio.h>


namespace sglLogger
{

using TimeType = std::time_t;
using TmType = std::tm;

template<typename T>
using UniquePtr = std::unique_ptr<T>;

template<typename T>
using SharedPtr = std::shared_ptr<T>;

using String = std::string;
using StringView = std::string_view;

template<typename T>
using Vector = std::vector<T>;

template<typename T>
UniquePtr<T> createUnique(auto&&... args)
{
  	return std::make_unique<T>(std::forward<decltype(args)>(args)...);
}

template<typename T>
SharedPtr<T> createShared(auto&&... args)
{
  	return std::make_shared<T>(std::forward<decltype(args)>(args)...);
}

};

