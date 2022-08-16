// Copyright Epic Games, Inc. All Rights Reserved
#pragma once

#ifndef JSON_USE_IMPLICIT_CONVERSIONS
#define JSON_USE_IMPLICIT_CONVERSIONS 0
#endif
// Disable nlohmann::json exception handling
#define JSON_NOEXCEPTION 1
#include <nlohmann/json.hpp>

static void from_json(const nlohmann::json& j, FString& p) {
    p = FString(UTF8_TO_TCHAR(j.get<std::string>().c_str()));
}

static void to_json(nlohmann::json& j, const FString& value) {
	j = TCHAR_TO_UTF8(*value);
}

template<typename T> 
void from_json(const nlohmann::json& j, TArray<T>& p) {
    p.Reset();

    for(const nlohmann::json& element: j)
    {
        p.Push(element.get<T>());
    }
}

template<typename T> 
void to_json(nlohmann::json& j, const TArray<T>& p) {
    j = nlohmann::json::array();

    for(const T& element: p)
    {
        j.push_back(element);
    }
}
