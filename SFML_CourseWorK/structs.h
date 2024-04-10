#pragma once

#include "enumclasses.h"
#include <string>

// Информация о товаре
struct Product
{
	std::string name;
	std::string colichestvo;
	std::string information;
	Reiting reiting;
};

//данные для аутентификации
struct Authentication
{
	std::string login;
	std::string password;
};
