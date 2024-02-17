// Copyright Epic Games, Inc. All Rights Reserved
#pragma once

#ifndef JSON_USE_IMPLICIT_CONVERSIONS
#define JSON_USE_IMPLICIT_CONVERSIONS 0
#endif
// Disable nlohmann::json exception handling
#define JSON_NOEXCEPTION 1
#include <nlohmann/json.hpp>

/**
 * Converts json formated data into FString.
 * The functions signature must follow the nlohmann from_jason function rules.
 * It is automatically called in usage j.get<FString>();
 * @param j an input json formated data
 * @param p FString that will be filled with data from j.
 *  In case data is malformed or not convertible to FString the function will throw.
 */
static void from_json(const nlohmann::json& j, FString& p)
{
	p = FString(UTF8_TO_TCHAR(j.get<std::string>().c_str()));
}

/**
 * Converts FString into json formated data.
 * The functions signature must follow the nlohmann to_json function rules.
 * It is automatically called in usage j = p;
 * @param j a json type data that will be filled with data from p
 * @param p an input from which json data will be filled.
 */
static void to_json(nlohmann::json& j, const FString& value)
{
	j = TCHAR_TO_UTF8(*value);
}

/**
 * Converts json formated data into TArray of T type elements.
 * The T type needs to be either std type or have its from_json function.
 * The functions signature must follow the nlohmann from_jason function rules.
 * It is automatically called in usage j.get<TArray<T>>();
 * @param j an input json formated data
 * @param p FString that will be filled with data from j.
 *  In case data is malformed or not convertible to FString the function will throw.
 */
template <typename T>
void from_json(const nlohmann::json& j, TArray<T>& p)
{
	p.Reset();

	for (const nlohmann::json& element : j)
	{
		p.Push(element.get<T>());
	}
}

/**
 * Converts TArray of T type elements into json formated data.
 * The T type needs to be either std type or have its to_json function.
 * The functions signature must follow the nlohmann to_json function rules.
 * It is automatically called in usage j = p;
 * @param j a json type data that will be filled with data from p
 * @param p an input from which json data will be filled.
 */
template <typename T>
void to_json(nlohmann::json& j, const TArray<T>& p)
{
	j = nlohmann::json::array();

	for (const T& element : p)
	{
		j.push_back(element);
	}
}
