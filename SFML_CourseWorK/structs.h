#pragma once

#include "enumclasses.h"
#include <string>

// ���������� � ������
struct Product
{
	std::string name;
	std::string colichestvo;
	std::string information;
	Reiting reiting;
};

//������ ��� ��������������
struct Authentication
{
	std::string login;
	std::string password;
};
