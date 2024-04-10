#include <SFML/Graphics.hpp>
#include <string>
#include "structs.h"
#include "enumclasses.h"
#include "prototypes.h"

sf::RenderWindow window(sf::VideoMode(500, 412), "", sf::Style::None);


int main()
{
    std::vector<Product> product;;
    std::vector<Authentication> authentication;
    
    bool isRememberMePressed;
    bool isRegistrationPressed;
    bool Data_Base;

    // запись данных в векторы из файлов
    writingToVectorsFromFileAuth(authentication);
    writingToVectorsFromFileProduct(product);
    wrtiteIsRememberMeOn(isRememberMePressed);

    if(isRememberMePressed)
        auth_menu(authentication, product, isRememberMePressed, Data_Base);
    else
        main_menu(authentication, product, isRememberMePressed, Data_Base);
    return 0;
}