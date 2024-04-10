#include <Windows.h>
#include <string>

#include "structs.h"
#include "enumclasses.h"
#include "prototypes.h"

#include <vector>
#include <iostream>
#include <fstream>

void registration(std::vector <Authentication>& authentication)
{
    std::string login;
    while (true)
    {
        std::cout << " Введите логин: ";
        std::cin >> login;
        if (isLoginAvailable(authentication, login) == 0)
        {
            std::cout << " Логин уже занят.Попробуйте другой";
            continue;
        }
        std::string password;

        while (true)
        {
            std::cin >> password;
            if (isPasswordGood(authentication, password))
            {
                std::cout << " Пароль не соответствует требованиям. Попробуйте ещё раз: ";
            }
            else break;
        }
        std::string password1;

        while (true)
        {
            std::cout << " Подтвердите пароль: ";
            std::cin >> password1;
            if (password1 == password)
            {
                std::cout << " Аккаунт успешно создан! ";
                break;
            }
            else std::cout << " Пароли не совпадают. Попробуйте ещё раз:";
        }
    }
}

int isPasswordGood(std::vector <Authentication>& login, std::string password)
{
    int capitalletter = 0;
    int sizeofpassword = password.size();
    int digits = 0;
    for (int i = 0; i < sizeofpassword; i++)
    {
        if (isupper(password[i]))
        {
            capitalletter++;
            break;
        }
    }
    for (int i = 0; i < sizeofpassword; i++)
    {
        if (isdigit(password[i]))
        {
            digits++;
        }
    }
    if (capitalletter == 1 and digits >= 3 and sizeofpassword >= 5)
    {
        return 0;
    }
    else return 1;

}

void writingToVectorsFromFileAuth(std::vector <Authentication>& authentication, std::string login,std::string password)
{
    std::fstream file("Data_Base.txt");
    Authentication authen;
    while (!file.eof())
    {
        file >> authen.login;
        file >> authen.password;
        authentication.push_back(authen);
    }
    file.close();
}

int isLoginAvailable(std::vector <Authentication>& authentication, std::string login)
{
    for (int i = 0; i < authentication.size(); i++)
    {
        if (login == authentication[i].login)
            return 0;
    }
    return 1;
}

void writingToVectorsFromFileAuth(std::vector<Authentication>& authentication)
{
	std::ifstream auth("Authentication_Data.txt");

	int i = 0;
	while (!auth.eof())
	{
		Authentication authen;
		auth >> authen.login;
		auth >> authen.password;

		authentication.push_back(authen);
		i++;
	}
	auth.close();
}

void writingToVectorsFromFileProduct(std::vector<Product>& product)
{
	std::ifstream prod("Product_Data.txt");
	int j = 0;
	while (!prod.eof())
	{
		Product tov;
		std::string post1;

		prod >> tov.name;
		prod >> tov.colichestvo;
		prod >> tov.information;
		prod >> post1;

		if (post1 == "Very_low")
			tov.reiting = Reiting::VERY_LOW;
		else if (post1 == "Low")
			tov.reiting = Reiting::LOW;
		else if (post1 == "Middle")
			tov.reiting = Reiting::MIDDLE;
		else if (post1 == "High")
			tov.reiting = Reiting::HIGH;
		else if (post1 == "Very_high")
			tov.reiting = Reiting::VERY_HIGH;

		product.push_back(tov);

		j++;
	}
	prod.close();
}

void wrtiteIsRememberMeOn(bool& isRememberMePressed)
{
	std::fstream file("isRememberMePressed.txt");

	file >> isRememberMePressed;

	file.close();
}

void writeInFileIsRememberOn(bool& isRememberMePressed)
{
	std::fstream file("isRememberMePressed.txt");

	file << isRememberMePressed;
	file.close();
}
