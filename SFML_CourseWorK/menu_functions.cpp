#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <fstream>
#include<iostream>
#include <string>

#include "structs.h"
#include "enumclasses.h"
#include "prototypes.h"

extern sf::RenderWindow window;

using namespace sf;
int registration_menu(std::vector<Authentication>& authentication, std::vector<Product>& product, bool& isRememberMePressed, bool &Data_Base)
{

    sf::Font font;
    if (!font.loadFromFile("shrift.ttf")) {
        // Обработка ошибки загрузки шрифта
        return EXIT_FAILURE;
    }

    // Создаем прямоугольник размером 70х100
    sf::RectangleShape rectangle1(Vector2f(430.f, 70.f));
    sf::RectangleShape rectangle2(Vector2f(430.f, 70.f));
    sf::RectangleShape rectangle3(Vector2f(50.f, 30.f));
    sf::RectangleShape rectangle4(Vector2f(430.f, 70.f));
    sf::RectangleShape line1(Vector2f(1.f, 70.f));
    sf::RectangleShape line2(Vector2f(1.f, 70.f));
    sf::RectangleShape line3(Vector2f(1.f, 70.f));

    rectangle1.move(35, 80);
    rectangle2.move(35, 160);
    rectangle3.move(188.f, 272.f);
    rectangle4.move(35, 240);
    line1.move(99, 80);
    line2.move(99, 160);
    line3.move(99, 240);

    // Устанавливаем ему цвет
    rectangle1.setFillColor(Color::White);
    rectangle2.setFillColor(Color::White);
    rectangle4.setFillColor(Color::White);
    rectangle3.setFillColor(Color(190, 80, 229));
    line1.setFillColor(Color(59, 60, 54));
    line2.setFillColor(Color(59, 60, 54));
    line3.setFillColor(Color(59, 60, 54));

    rectangle1.setOutlineThickness(1.f); // толщина контура
    rectangle2.setOutlineThickness(1.f); // толщина контура
    rectangle1.setOutlineColor(sf::Color(59, 60, 54)); // цвет контура
    rectangle2.setOutlineColor(sf::Color(59, 60, 54)); // цвет контура
    rectangle4.setOutlineThickness(1.f); // толщина контура
    rectangle4.setOutlineColor(sf::Color(59, 60, 54)); // цвет контура


    sf::Text text(L"Регистрация", font);
    text.setCharacterSize(46); // Установка размера шрифта
    text.setFillColor(sf::Color::White); // Установка цвета текста
    // Установка начального положения текста
    text.setPosition(88.f, 8.f); // Новые координаты (x, y)

    sf::Text authorization(L"Авторизация", font);
    authorization.setCharacterSize(30); // Установка размера шрифта
    authorization.setFillColor(sf::Color(190, 80, 229)); // Установка цвета текста
    authorization.setPosition(45, 340); // Новые координаты (x, y)


    sf::Text login("", font);
    login.setCharacterSize(28); // Установка размера шрифта
    login.setFillColor(sf::Color::Black); // Установка цвета текста
    login.setPosition(110.f, 98.f); // Новые координаты (x, y)

    sf::Text password1("", font);
    password1.setCharacterSize(28); // Установка размера шрифта
    password1.setFillColor(sf::Color::Black); // Установка цвета текста
    password1.setPosition(110.f, 178.f); // Новые координаты (x, y)

    sf::Text password2("", font);
    password2.setCharacterSize(44); // Установка размера шрифта
    password2.setFillColor(sf::Color::Black); // Установка цвета текста
    password2.setPosition(110.f, 178.f); // Новые координаты (x, y)

    sf::Text password3("", font);
    password3.setCharacterSize(28); // Установка размера шрифта
    password3.setFillColor(sf::Color::Black); // Установка цвета текста
    password3.setPosition(110.f, 252.f); // Новые координаты (x, y)

    sf::Text password4("", font);
    password4.setCharacterSize(44); // Установка размера шрифта
    password4.setFillColor(sf::Color::Black); // Установка цвета текста
    password4.setPosition(110.f, 252.f); // Новые координаты (x, y)

    sf::Text error(L"Неверный логин или пароль!", font);
    error.setCharacterSize(16); // Установка размера шрифта
    error.setFillColor(sf::Color::Red); // Установка цвета текста
    error.setPosition(126.f, 380.f); // Новые координаты (x, y)



    // Загрузка изображения в текстуру
    sf::Texture texture1;
    if (!texture1.loadFromFile("user.png")) {
        // Обработка ошибки загрузки изображения
        return EXIT_FAILURE;
    }
    // Загрузка изображения в текстуру
    sf::Texture texture2;
    if (!texture2.loadFromFile("password1.png")) {
        // Обработка ошибки загрузки изображения
        return EXIT_FAILURE;
    }
    sf::Texture texture5;
    if (!texture5.loadFromFile("password1.png")) {
        // Обработка ошибки загрузки изображения
        return EXIT_FAILURE;
    }
    // Загрузка изображения в текстуру
    sf::Texture texture3;
    if (!texture3.loadFromFile("hide_eye.png")) {
        // Обработка ошибки загрузки изображения
        return EXIT_FAILURE;
    }
    sf::Texture texture4;
    if (!texture4.loadFromFile("open_eye.png")) {
        // Обработка ошибки загрузки изображения
        return EXIT_FAILURE;
    }
    sf::Texture galka;
    if (!galka.loadFromFile("galka.png")) {
        // Обработка ошибки загрузки изображения
        return EXIT_FAILURE;
    }
    sf::Texture krest;
    if (!krest.loadFromFile("krest.png")) {
        // Обработка ошибки загрузки изображения
        return EXIT_FAILURE;
    }


    // Создание спрайта и установка текстуры
    sf::Sprite sprite1(texture1);
    sf::Sprite sprite2(texture2);
    sf::Sprite sprite5(texture5);
    sf::Sprite sprite3(texture3);
    sf::Sprite sprite4(texture4);
    sf::Sprite sprite_galka(galka);
    sf::Sprite sprite_krest(krest);

    sprite1.setScale(1.f / 10.f, 1.f / 10.f);
    sprite2.setScale(1.f / 10.f, 1.f / 10.f);
    sprite5.setScale(1.f / 10.f, 1.f / 10.f);
    sprite3.setScale(1.f / 12.f, 1.f / 12.f);
    sprite4.setScale(1.f / 12.f, 1.f / 12.f);
    sprite_galka.setScale(1.f / 19.f, 1.f / 19.f);
    sprite_krest.setScale(1.f / 30.f, 1.f / 30.f);

    // Установка начального положения спрайта
    sprite1.setPosition(43.f, 92.f);
    sprite2.setPosition(43.f, 172.f);
    sprite5.setPosition(43.f, 252.f);
    sprite3.setPosition(416.f, 175.f);
    sprite4.setPosition(416.f, 175.f);
    sprite_galka.setPosition(44.f, 339.f);
    sprite_krest.setPosition(478.f, 6.f);

    // првоерка, какое поле выбрал для ввода
    bool isRectangle1Clicked = false;
    bool isRectangle2Clicked = false;
    bool isRectangle4Clicked = false;
    bool isPasswordOpen = false;
    bool isTextPasswordOpen = false;
    bool isRememberMeOn = false;
    bool isAutorise = false;
    bool isIncorrectData = false;

    // для перемещения окна
    bool isDragging = false;
    sf::Vector2i clickPosition;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {

            // закрытие приложения
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (sprite_krest.getGlobalBounds().contains(mousePos.x, mousePos.y))
                        window.close();
                }
            }
            // для закрытия из панели задач
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();


            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                // Запоминаем позицию, в которой была нажата кнопка мыши
                isDragging = true;
                clickPosition = sf::Mouse::getPosition(window);
            }
            else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
            {
                // Когда кнопка мыши отпущена, заканчиваем перетаскивание
                isDragging = false;
            }
            // проверка на поле для ввода
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (rectangle1.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    {
                        isIncorrectData = false;
                        isRectangle1Clicked = true;
                        isRectangle2Clicked = false;
                        isRectangle4Clicked = false;

                    }
                    else if (rectangle2.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    {
                        isIncorrectData = false;
                        isRectangle1Clicked = false;
                        isRectangle2Clicked = true;
                        isRectangle4Clicked = false;
                    }
                    else if (rectangle4.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    {
                        isIncorrectData = false;
                        isRectangle1Clicked = false;
                        isRectangle2Clicked = false;
                        isRectangle4Clicked = true;
                    }
                }
            }

            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            if (rectangle3.getGlobalBounds().contains(mousePos.x, mousePos.y))
                // Изменение цвета прямоугольника, если курсор находится над ним
                rectangle3.setFillColor(Color(190, 90, 229));
            else
                // Возвращение к исходному цвету, если курсор не находится над прямоугольником
                rectangle3.setFillColor(Color(190, 80, 229));

            // ввод текста в поле логин и пароль
            if (event.type == sf::Event::TextEntered)
            {
                if (event.text.unicode < 128)
                {
                    if (isRectangle1Clicked and login.getString().getSize() < 12)
                    {
                        login.setString(login.getString() + static_cast<char>(event.text.unicode));

                    }
                    if (isRectangle2Clicked and password1.getString().getSize() < 12)
                    {
                        password1.setString(password1.getString() + static_cast<char>(event.text.unicode));
                        password2.setString(password2.getString() + '*');
                    }
                    if (isRectangle4Clicked and password3.getString().getSize() < 12)
                    {
                        password3.setString(password3.getString() + static_cast<char>(event.text.unicode));
                        password4.setString(password4.getString() + '*');
                    }
                }
            }
            // удаление текста
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    if (login.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                    {
                        login.setString("");
                    }
                    if (password2.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                    {
                        password2.setString("");
                        password1.setString("");
                    }
                    if (password4.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                    {
                        password4.setString("");
                        password3.setString("");
                    }

                }
            }
            // проверка на нажатие кнопки видимости пароля
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (sprite3.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isPasswordOpen)
                    {
                        isPasswordOpen = true;
                        isTextPasswordOpen = true;
                    }
                    else if (sprite4.getGlobalBounds().contains(mousePos.x, mousePos.y) and isPasswordOpen)
                    {
                        isPasswordOpen = false;
                        isTextPasswordOpen = false;
                    }
                }
            }
            // проверка на правильность введенных данных
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    if (rectangle3.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                    {
                        std::string login1;
                        std::string password5;
                        std::string password6;
                        login1 = login.getString();
                        password5 = password1.getString();
                        password6 = password3.getString();
                    }

                }
            }
            //проверка на нажатие авторизации
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    if (authorization.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                    {
                        auth_menu(authentication, product,isRememberMePressed, Data_Base);
                    }

                }
            }

            //проверка на запись
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    if (authorization.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                    {
                        std::ofstream data_base;
                        data_base.open("Data_Base.TXT", std::ios::app);
                        std::string data = login.getString();
                        std::string data1 = password1.getString();
                        data_base << data;
                        std::cout << " ";
                        data_base << data1;
                        std::cout << " ";
                    }

                }
            }

        }
        if (isDragging)
        {
            // Вычисляем разницу между текущей позицией мыши и позицией, где была нажата кнопка мыши
            sf::Vector2i delta = sf::Mouse::getPosition(window) - clickPosition;
            // Получаем текущее положение окна и сдвигаем его на delta
            window.setPosition(sf::Vector2i(window.getPosition()) + delta);
            // Обновляем позицию clickPosition
            clickPosition = sf::Mouse::getPosition(window);
        }

        window.clear(sf::Color(10, 10, 10));
        window.draw(rectangle1);
        window.draw(rectangle2);
        window.draw(rectangle3);
        window.draw(rectangle4);
        window.draw(authorization);
        window.draw(line1);
        window.draw(line2);
        window.draw(line3);
        window.draw(text);
        window.draw(login);
        if (isTextPasswordOpen) window.draw(password1);
        else window.draw(password2);
        if (isTextPasswordOpen) window.draw(password3);
        else window.draw(password4);
        window.draw(sprite1);
        window.draw(sprite2);
        window.draw(sprite5);
        window.draw(sprite_krest);
        if (isPasswordOpen)  window.draw(sprite4);
        else  window.draw(sprite3);
        if (isRememberMeOn) window.draw(sprite_galka);
        if (isIncorrectData) window.draw(error);
        window.display();
    }
}

int auth_menu(std::vector<Authentication>& authentication, std::vector<Product>& product, bool& isRememberMePressed, bool& Data_Base)
{

    sf::Font font;
    if (!font.loadFromFile("shrift.ttf")) {
        // Обработка ошибки загрузки шрифта
        return EXIT_FAILURE;
    }

    // Создаем прямоугольник размером 70х100
    sf::RectangleShape rectangle1(Vector2f(430.f, 70.f));
    sf::RectangleShape rectangle2(Vector2f(430.f, 70.f));
    sf::RectangleShape rectangle3(Vector2f(430.f, 70.f));
    sf::RectangleShape square(Vector2f(25.f, 25.f));
    sf::RectangleShape line1(Vector2f(1.f, 70.f));
    sf::RectangleShape line2(Vector2f(1.f, 70.f));

    rectangle1.move(35, 80);
    rectangle2.move(35, 160);
    rectangle3.move(35, 255);
    square.move(45, 340);
    line1.move(99, 80);
    line2.move(99, 160);
    // Устанавливаем ему цвет
    rectangle1.setFillColor(Color::White);
    rectangle2.setFillColor(Color::White);
    rectangle3.setFillColor(Color(190, 80, 229));
    square.setFillColor(Color::White);
    line1.setFillColor(Color(59, 60, 54));
    line2.setFillColor(Color(59, 60, 54));

    rectangle1.setOutlineThickness(1.f); // толщина контура
    rectangle2.setOutlineThickness(1.f); // толщина контура
    rectangle1.setOutlineColor(sf::Color(59, 60, 54)); // цвет контура
    rectangle2.setOutlineColor(sf::Color(59, 60, 54)); // цвет контура

    sf::Text text(L"Авторизация", font);
    text.setCharacterSize(46); // Установка размера шрифта
    text.setFillColor(sf::Color::White); // Установка цвета текста
    // Установка начального положения текста
    text.setPosition(88.f, 8.f); // Новые координаты (x, y)


    sf::Text entrance(L"Войти", font);
    entrance.setCharacterSize(30); // Установка размера шрифта
    entrance.setFillColor(sf::Color::White); // Установка цвета текста
    entrance.setPosition(188.f, 272.f); // Новые координаты (x, y)

    sf::Text rememberMe(L"Запомнить меня", font);
    rememberMe.setCharacterSize(14); // Установка размера шрифта
    rememberMe.setFillColor(sf::Color::White); // Установка цвета текста
    rememberMe.setPosition(81.f, 344.f); // Новые координаты (x, y)

    sf::Text autorise(L"Регистрация", font);
    autorise.setCharacterSize(30); // Установка размера шрифта
    autorise.setFillColor(sf::Color(190, 80, 229)); // Установка цвета текста
    autorise.setPosition(250.f, 344.f); // Новые координаты (x, y)

    sf::Text login("", font);
    login.setCharacterSize(28); // Установка размера шрифта
    login.setFillColor(sf::Color::Black); // Установка цвета текста
    login.setPosition(110.f, 98.f); // Новые координаты (x, y)

    sf::Text password1("", font);
    password1.setCharacterSize(28); // Установка размера шрифта
    password1.setFillColor(sf::Color::Black); // Установка цвета текста
    password1.setPosition(110.f, 178.f); // Новые координаты (x, y)

    sf::Text password2("", font);
    password2.setCharacterSize(44); // Установка размера шрифта
    password2.setFillColor(sf::Color::Black); // Установка цвета текста
    password2.setPosition(110.f, 178.f); // Новые координаты (x, y)

    sf::Text error(L"Неверный логин или пароль!", font);
    error.setCharacterSize(16); // Установка размера шрифта
    error.setFillColor(sf::Color::Red); // Установка цвета текста
    error.setPosition(126.f, 380.f); // Новые координаты (x, y)



    // Загрузка изображения в текстуру
    sf::Texture texture1;
    if (!texture1.loadFromFile("user.png")) {
        // Обработка ошибки загрузки изображения
        return EXIT_FAILURE;
    }
    // Загрузка изображения в текстуру
    sf::Texture texture2;
    if (!texture2.loadFromFile("password1.png")) {
        // Обработка ошибки загрузки изображения
        return EXIT_FAILURE;
    }
    // Загрузка изображения в текстуру
    sf::Texture texture3;
    if (!texture3.loadFromFile("hide_eye.png")) {
        // Обработка ошибки загрузки изображения
        return EXIT_FAILURE;
    }
    sf::Texture texture4;
    if (!texture4.loadFromFile("open_eye.png")) {
        // Обработка ошибки загрузки изображения
        return EXIT_FAILURE;
    }
    sf::Texture galka;
    if (!galka.loadFromFile("galka.png")) {
        // Обработка ошибки загрузки изображения
        return EXIT_FAILURE;
    }
    sf::Texture krest;
    if (!krest.loadFromFile("krest.png")) {
        // Обработка ошибки загрузки изображения
        return EXIT_FAILURE;
    }

    // Создание спрайта и установка текстуры
    sf::Sprite sprite1(texture1);
    sf::Sprite sprite2(texture2);
    sf::Sprite sprite3(texture3);
    sf::Sprite sprite4(texture4);
    sf::Sprite sprite_galka(galka);
    sf::Sprite sprite_krest(krest);

    sprite1.setScale(1.f / 10.f, 1.f / 10.f);
    sprite2.setScale(1.f / 10.f, 1.f / 10.f);
    sprite3.setScale(1.f / 12.f, 1.f / 12.f);
    sprite4.setScale(1.f / 12.f, 1.f / 12.f);
    sprite_galka.setScale(1.f / 19.f, 1.f / 19.f);
    sprite_krest.setScale(1.f / 30.f, 1.f / 30.f);

    // Установка начального положения спрайта
    sprite1.setPosition(42.f, 92.f);
    sprite2.setPosition(43.f, 172.f);
    sprite3.setPosition(416.f, 175.f);
    sprite4.setPosition(416.f, 175.f);
    sprite_galka.setPosition(44.f, 339.f);
    sprite_krest.setPosition(478.f, 6.f);

    // првоерка, какое поле выбрал для ввода
    bool isRectangle1Clicked = false;
    bool isRectangle2Clicked = false;
    bool isPasswordOpen = false;
    bool isTextPasswordOpen = false;
    bool isRememberMeOn = false;
    bool isAutorise = false;
    bool isEntrance = false;
    bool isIncorrectData = false;
    // для перемещения окна
    bool isDragging = false;
    sf::Vector2i clickPosition;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {

            // закрытие приложения
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (sprite_krest.getGlobalBounds().contains(mousePos.x, mousePos.y))
                        window.close();
                }
            }
            // для закрытия из панели задач
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();


            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                // Запоминаем позицию, в которой была нажата кнопка мыши
                isDragging = true;
                clickPosition = sf::Mouse::getPosition(window);
            }
            else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
            {
                // Когда кнопка мыши отпущена, заканчиваем перетаскивание
                isDragging = false;
            }
            // проверка на поле для ввода
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (rectangle1.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    {
                        isIncorrectData = false;
                        isRectangle1Clicked = true;
                        isRectangle2Clicked = false;
                    }
                    else if (rectangle2.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    {
                        isIncorrectData = false;
                        isRectangle1Clicked = false;
                        isRectangle2Clicked = true;
                    }
                }
            }

            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            if (rectangle3.getGlobalBounds().contains(mousePos.x, mousePos.y))
                // Изменение цвета прямоугольника, если курсор находится над ним
                rectangle3.setFillColor(Color(186, 109, 214));
            else
                // Возвращение к исходному цвету, если курсор не находится над прямоугольником
                rectangle3.setFillColor(Color(190, 80, 229));

            // проверка на галочку
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (square.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isRememberMeOn)
                    {
                        isRememberMeOn = true;
                        isRememberMePressed = false;
                        writeInFileIsRememberOn(isRememberMePressed);
                    }
                    else if (square.getGlobalBounds().contains(mousePos.x, mousePos.y) and isRememberMeOn)
                    {
                        isRememberMeOn = false;
                        isRememberMePressed = true;
                        writeInFileIsRememberOn(isRememberMePressed);
                    }
                }
            }


            // ввод текста в поле логин и пароль
            if (event.type == sf::Event::TextEntered)
            {
                if (event.text.unicode < 128)
                {
                    if (isRectangle1Clicked and login.getString().getSize() < 12)
                    {
                        login.setString(login.getString() + static_cast<char>(event.text.unicode));

                    }
                    if (isRectangle2Clicked and password1.getString().getSize() < 12)
                    {
                        password1.setString(password1.getString() + static_cast<char>(event.text.unicode));
                        password2.setString(password2.getString() + '*');
                    }
                }
            }
            // удаление текста
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    if (login.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                    {
                        login.setString("");
                    }
                    if (password2.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                    {
                        password2.setString("");
                        password1.setString("");
                    }
                }
            }
            // проверка на нажатие кнопки видимости пароля
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (sprite3.getGlobalBounds().contains(mousePos.x, mousePos.y) and !isPasswordOpen)
                    {
                        isPasswordOpen = true;
                        isTextPasswordOpen = true;
                    }
                    else if (sprite4.getGlobalBounds().contains(mousePos.x, mousePos.y) and isPasswordOpen)
                    {
                        isPasswordOpen = false;
                        isTextPasswordOpen = false;
                    }
                }
            }
            // проверка на правильность введенных данных
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    if (rectangle3.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                    {
                        std::string login1;
                        std::string password5;
                        login1 = login.getString();
                        password5 = password1.getString();
                       
                    
                    }

                }
            }

            // проверка на нажатие кнопки регистрации
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    if (autorise.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                    {
                        registration_menu(authentication, product, isRememberMePressed, Data_Base);
                    }

                }
            }


            // проверка на нажатие кнопки войти
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    if (entrance.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                    {
                        main_menu(authentication,product, isRememberMePressed,Data_Base);
                    }

                }
            }
        }
        if (isDragging)
        {
            // Вычисляем разницу между текущей позицией мыши и позицией, где была нажата кнопка мыши
            sf::Vector2i delta = sf::Mouse::getPosition(window) - clickPosition;
            // Получаем текущее положение окна и сдвигаем его на delta
            window.setPosition(sf::Vector2i(window.getPosition()) + delta);
            // Обновляем позицию clickPosition
            clickPosition = sf::Mouse::getPosition(window);
        }

        window.clear(sf::Color(10, 10, 10));
        window.draw(rectangle1);
        window.draw(rectangle2);
        window.draw(rectangle3);
        window.draw(square);
        window.draw(line1);
        window.draw(line2);
        window.draw(text);
        window.draw(entrance);
        window.draw(autorise);
        window.draw(login);
        window.draw(rememberMe);
        if (isTextPasswordOpen) window.draw(password1);
        else window.draw(password2);
        window.draw(sprite1);
        window.draw(sprite2);
        window.draw(sprite_krest);
        if (isPasswordOpen)  window.draw(sprite4);
        else  window.draw(sprite3);
        if (isRememberMeOn) window.draw(sprite_galka);
        if (isIncorrectData) window.draw(error);
        window.display();
    }
}

void main_menu(std::vector<Authentication>& authentication, std::vector<Product>& product, bool& isRememberMePressed, bool& Data_Base)
{
    window.create(sf::VideoMode(1920, 1080), "",sf::Style::None);

    sf::Font font;
    if (!font.loadFromFile("shrift.ttf"))
    {
        // Обработка ошибки загрузки шрифта
        return;
    }
    //создание прямоугольников
    sf::RectangleShape rectangle1(Vector2f(300.f, 300.f));
    sf::RectangleShape rectangle2(Vector2f(300.f, 300.f));
    sf::RectangleShape rectangle3(Vector2f(300.f, 300.f));
    sf::RectangleShape rectangle4(Vector2f(300.f, 300.f));
    sf::RectangleShape rectangle5(Vector2f(50.f, 50.f));
    sf::RectangleShape rectangle6(Vector2f(50.f, 50.f));

    //расположение
    rectangle1.move(570, 250);
    rectangle2.move(970, 250);
    rectangle3.move(570, 625);
    rectangle4.move(970, 625);
    rectangle5.move(1550, 250);
    rectangle6.move(1550, 350);

    //цвет прямоугольника
    rectangle1.setFillColor(Color::White);
    rectangle2.setFillColor(Color::White);
    rectangle3.setFillColor(Color::White);
    rectangle4.setFillColor(Color::White);
    rectangle5.setFillColor(Color::White);
    rectangle6.setFillColor(Color::White);

    sf::Text search("", font);
    search.setCharacterSize(28); // Установка размера шрифта
    search.setFillColor(sf::Color::White); // Установка цвета текста
    search.setPosition(110.f, 50.f); // Новые координаты (x, y)

    sf::Text name("Vision", font);
    name.setCharacterSize(64);
    name.setFillColor(sf::Color::White);
    name.setPosition(1675, 35);

    sf::Text shop(L"Пункт самовывоза:", font);
    shop.setCharacterSize(24);
    shop.setFillColor(sf::Color::White);
    shop.setPosition(1550, 200);

    sf::Text text1(L"Цепочки", font);
    text1.setCharacterSize(30);
    text1.setFillColor(sf::Color::Black);
    text1.setPosition(650, 500);

    sf::Text text2(L"Шарфы", font);
    text2.setCharacterSize(30);
    text2.setFillColor(sf::Color::Black);
    text2.setPosition(1060, 500);

    sf::Text text3(L"Голова", font);
    text3.setCharacterSize(30);
    text3.setFillColor(sf::Color::Black);
    text3.setPosition(1060, 875);

    sf::Text text4(L"Очки", font);
    text4.setCharacterSize(30);
    text4.setFillColor(sf::Color::Black);
    text4.setPosition(675, 875);

    sf::Text warning(L"Обязательно выберите пункт самовывоза!", font);
    warning.setCharacterSize(36);
    warning.setFillColor(sf::Color::White);
    warning.setPosition(600, 950);

    sf::Texture logo;
    if (!logo.loadFromFile("logo.png"))
        return;
    sf::Sprite sprite_logo(logo);
    sprite_logo.setScale(0.8, 0.8);
    sprite_logo.setPosition(570, 35);

    sf::Texture kategory_cepi;
    if (!kategory_cepi.loadFromFile("kategory_cepi.png"))
        return;
    sf::Sprite sprite_kategory_cepi(kategory_cepi);
    sprite_kategory_cepi.setScale(0.8, 0.8);
    sprite_kategory_cepi.setPosition(610, 250);
    
    sf::Texture kategory_sharf;
    if (!kategory_sharf.loadFromFile("kategory_sharf.png"))
        return;
    sf::Sprite sprite_kategory_sharf(kategory_sharf);
    sprite_kategory_sharf.setScale(0.8, 0.8);
    sprite_kategory_sharf.setPosition(1000, 225);
    
    sf::Texture kategory_glass;
    if (!kategory_glass.loadFromFile("kategory_glass.png"))
        return;
    sf::Sprite sprite_kategory_glass(kategory_glass);
    sprite_kategory_glass.setScale(0.55, 0.55);
    sprite_kategory_glass.setPosition(475, 570);

    sf::Texture kategory_shapka;
    if (!kategory_shapka.loadFromFile("kategory_shapka.png"))
        return;
    sf::Sprite sprite_kategory_shapka(kategory_shapka);
    sprite_kategory_shapka.setScale(0.8, 0.8);
    sprite_kategory_shapka.setPosition(940, 610);

    sf::Text text_settings(L"Настройки", font);
    text_settings.setCharacterSize(45);
    text_settings.setFillColor(sf::Color::Black);
    text_settings.setPosition(45.f, 525.f);

    sf::Text text_exit(L"Выход", font);
    text_exit.setCharacterSize(45);
    text_exit.setFillColor(sf::Color::Black);
    text_exit.setPosition(45.f, 595.f);

    sf::Vector2i clickPosition;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // закрытие приложения
            // для закрытия из панели задач
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
            // закрытие приложения
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (text_exit.getGlobalBounds().contains(mousePos.x, mousePos.y))
                        window.close();
                }
            }


            // подсвечивание кнопок при наведении на них
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);

            if (text_settings.getGlobalBounds().contains(mousePos.x, mousePos.y))
                // Изменение цвета прямоугольника, если курсор находится над ним
                text_settings.setFillColor(Color(190, 80, 229));
            else
                // Возвращение к исходному цвету, если курсор не находится над прямоугольником
                text_settings.setFillColor(sf::Color::White);
            if (text_exit.getGlobalBounds().contains(mousePos.x, mousePos.y))
                // Изменение цвета прямоугольника, если курсор находится над ним
                text_exit.setFillColor(Color(190, 80, 229));
            else
                // Возвращение к исходному цвету, если курсор не находится над прямоугольником
                text_exit.setFillColor(sf::Color::White);
            if (rectangle1.getGlobalBounds().contains(mousePos.x, mousePos.y))
                // Изменение цвета прямоугольника, если курсор находится над ним
                rectangle1.setFillColor(Color(190, 80, 229));
            else
                // Возвращение к исходному цвету, если курсор не находится над прямоугольником
                rectangle1.setFillColor(sf::Color::White);
            if (rectangle2.getGlobalBounds().contains(mousePos.x, mousePos.y))
                // Изменение цвета прямоугольника, если курсор находится над ним
                rectangle2.setFillColor(Color(190, 80, 229));
            else
                // Возвращение к исходному цвету, если курсор не находится над прямоугольником
                rectangle2.setFillColor(sf::Color::White);
            if (rectangle3.getGlobalBounds().contains(mousePos.x, mousePos.y))
                // Изменение цвета прямоугольника, если курсор находится над ним
                rectangle3.setFillColor(Color(190, 80, 229));
            else
                // Возвращение к исходному цвету, если курсор не находится над прямоугольником
                rectangle3.setFillColor(sf::Color::White);
            if (rectangle4.getGlobalBounds().contains(mousePos.x, mousePos.y))
                // Изменение цвета прямоугольника, если курсор находится над ним
                rectangle4.setFillColor(Color(190, 80, 229));
            else
                // Возвращение к исходному цвету, если курсор не находится над прямоугольником
                rectangle4.setFillColor(sf::Color::White);


            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (rectangle5.getGlobalBounds().contains(mousePos.x,mousePos.y))
                    {
                        rectangle5.setFillColor(Color(190, 80, 229));
                        rectangle6.setFillColor(Color::White);
                    }
                }
            }
            if (event.type == sf::Event::MouseButtonPressed)
                {
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                        if (rectangle6.getGlobalBounds().contains(mousePos.x, mousePos.y))
                        {
                            rectangle6.setFillColor(Color(190, 80, 229));
                            rectangle5.setFillColor(Color::White);
                        }
                    }
                }

        }
        window.clear(sf::Color::Black);
        window.draw(sprite_logo);
        window.draw(rectangle1);
        window.draw(rectangle2);
        window.draw(rectangle3);
        window.draw(rectangle4);
        window.draw(rectangle5);
        window.draw(rectangle6);
        window.draw(sprite_kategory_cepi);
        window.draw(sprite_kategory_glass);
        window.draw(sprite_kategory_sharf);
        window.draw(sprite_kategory_shapka);
        window.draw(text1);
        window.draw(text2);
        window.draw(text3);
        window.draw(text4);
        window.draw(name);
        window.draw(shop);
        window.draw(warning);
        window.draw(text_settings);
        window.draw(text_exit);
        window.display();
        }

}