#pragma once

#include <vector>
#include "structs.h"

// работа с файлами
void writingToVectorsFromFileProduct(std::vector<Product>& product);
void writingToVectorsFromFileAuth(std::vector<Authentication>& authentication);
void wrtiteIsRememberMeOn(bool& isRememberMePressed);
void writeInFileIsRememberOn(bool& isRememberMePressed);
void writingToVectorsFromFileAuth(std::vector <Authentication>& authentication);
int isLoginAvailable(std::vector <Authentication>& authentication, std::string login);
int isPasswordGood(std::vector <Authentication>&authentication,std::string password);
int isPasswordGood(std::vector <Authentication>& login, std::string password);
int isLoginAvailable(std::vector <Authentication>& authentication, std::string login);


// функции меню
int registration_menu(std::vector<Authentication>& authentication, std::vector<Product>& product, bool& isRememberMePressed, bool &Data_Base);
int auth_menu(std::vector<Authentication>& authentication, std::vector<Product>& product, bool& isRememberMePressed, bool &Data_Base);
void main_menu(std::vector<Authentication>& authentication, std::vector<Product>& product, bool& isRememberMePressed, bool& Data_Base);