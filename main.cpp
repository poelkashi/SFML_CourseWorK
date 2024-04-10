#include <SFML/Graphics.hpp>
#include <string>
#include "structs.h"
#include "enumclasses.h"
#include "prototypes.h"

sf::RenderWindow window(sf::VideoMode(500, 412), "", sf::Style::None);

int main()
{

    std::vector<Product> product;
    std::vector<Authentication> authentication;
    std::vector<int> indexes;
    bool isRememberMePressed;

    writingToVectorsFromFileAuth(authentication);
    writingToVectorsFromFileTovar(product);
    wrtiteIsRememberMeOn(isRememberMePressed);

    if (isRememberMePressed)
        auth_menu(authentication, product, isRememberMePressed);
    else
        main_menu(authentication, product, isRememberMePressed);


    return 0;
}