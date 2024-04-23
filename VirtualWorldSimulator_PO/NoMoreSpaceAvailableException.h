#pragma once
#include <exception>
class NoMoreSpaceAvailableException : public std::exception
{
public:
	const char* what() const override;
};