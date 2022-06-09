#include <SFML/Graphics.hpp>
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include "choice.h"
#include "win.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600


int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Gra w kolko i krzyzyk");

    sf::Texture texture;
    if (!texture.loadFromFile("graphics/board.jpg"))
        return EXIT_FAILURE;
    sf::Sprite board(texture);

    sf::Texture texture1;
    if (!texture1.loadFromFile("graphics/X.png"))
        return EXIT_FAILURE;
    sf::Sprite X(texture1);

    sf::Texture texture2;
    if (!texture2.loadFromFile("graphics/O.png"))
        return EXIT_FAILURE;
    sf::Sprite O(texture2);

    sf::Texture texture3;
    if (!texture3.loadFromFile("graphics/remis.jpg"))
        return EXIT_FAILURE;
    sf::Sprite remis(texture3);

    sf::Texture texture4;
    if (!texture4.loadFromFile("graphics/Xwin.jpg"))
        return EXIT_FAILURE;
    sf::Sprite Xwin(texture4);

    sf::Texture texture5;
    if (!texture5.loadFromFile("graphics/Owin.jpg"))
        return EXIT_FAILURE;
    sf::Sprite Owin(texture5);

    sf::Texture texture6;
    if (!texture6.loadFromFile("graphics/hor_line.png"))
        return EXIT_FAILURE;
    sf::Sprite hor_line(texture6);

    sf::Texture texture7;
    if (!texture7.loadFromFile("graphics/ver_line.png"))
        return EXIT_FAILURE;
    sf::Sprite ver_line(texture7);

    sf::Texture texture8;
    if (!texture8.loadFromFile("graphics/cross1_line.png"))
        return EXIT_FAILURE;
    sf::Sprite cross1_line(texture8);

    sf::Texture texture9;
    if (!texture9.loadFromFile("graphics/cross2_line.png"))
        return EXIT_FAILURE;
    sf::Sprite cross2_line(texture9);

    sf::Texture texture10;
    if (!texture10.loadFromFile("graphics/statsmenu.jpg"))
        return EXIT_FAILURE;
    sf::Sprite statsmenu(texture10);

    sf::Font font;
    if (!font.loadFromFile("C:/Windows/Fonts/COOPBL.TTF"))
    {
        return EXIT_FAILURE;
    }

    sf::Text moveX;
    moveX.setFont(font);
    moveX.setString("Ruch gracza: X");
    moveX.setCharacterSize(26);
    moveX.setFillColor(sf::Color::Black);

    sf::Text moveO;
    moveO.setFont(font);
    moveO.setString("Ruch gracza: O");
    moveO.setCharacterSize(26);
    moveO.setFillColor(sf::Color::Black);

    sf::Text pause;
    pause.setFont(font);
    pause.setString("P - pauza");
    pause.setCharacterSize(20);
    pause.setFillColor(sf::Color::Black);
    pause.setPosition(700, 575);

    sf::Text Xcount;
    Xcount.setFont(font);
    Xcount.setCharacterSize(60);
    Xcount.setFillColor(sf::Color::Black);
    Xcount.setPosition(650, 250);

    sf::Text Ocount;
    Ocount.setFont(font);
    Ocount.setCharacterSize(60);
    Ocount.setFillColor(sf::Color::Black);
    Ocount.setPosition(250, 250);


    FILE* fout,* fin;
    fout = fopen("stats/results.txt", "at");
    fin = fopen("stats/results.txt", "rt");
    int matrix[3][3] = { {0,0,0}, {0,0,0}, {0,0,0} };
    int clickx = 0, clicky = 0, turnX = 1, turns = 0, stats = 0, counterX = 0, counterO = 0;


    // Start the game loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::MouseMoved)
            {
               clickx = event.mouseMove.x;
               clicky = event.mouseMove.y;
            }
            if (event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left && stats == 0)
            {
                if (turnX == 1)
                {
                    if (choiceX(matrix, clickx, clicky) == 1)
                    {
                        turnX = 0;
                        turns = turns + 1;
                    }
                }
                else if (turnX == 0)
                {
                    if (choiceY(matrix, clickx, clicky) == 1)
                    {
                        turnX = 1;
                        turns = turns + 1;
                    }
                }
            }
            if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::P)
                {
                    if (stats == 0)
                    {
                        stats = 1;
                    }
                    else
                    {
                        stats = 0;
                    }
                }
            }
        }

        // display
        if (stats == 1)
        {
            window.clear();
            window.draw(statsmenu);

            while (!feof(fin))
            {
                char result;
                fscanf(fin, "%c", &result);
                
                if (result == 'X')
                {
                    counterX = counterX + 1;
                }
                if (result == 'O')
                {
                    counterO = counterO + 1;
                }
            }
            Xcount.setString(std::to_string(counterX));
            Ocount.setString(std::to_string(counterO));
            window.draw(Xcount);
            window.draw(Ocount);
            window.display();
        }
        else
        {
            window.clear();
            window.draw(board);
            if (winOfX(matrix) == 0 && winOfO(matrix) == 0 && turns < 9)
            {
                window.draw(pause);
                if (turnX == 0)
                {
                    window.draw(moveO);
                }
                if (turnX == 1)
                {
                    window.draw(moveX);
                }
            }

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (matrix[i][j] == 1)
                    {
                        X.setPosition(j * 263 + 75, i * 200 + 30);
                        window.draw(X);
                    }
                    if (matrix[i][j] == 2)
                    {
                        O.setPosition(j * 263 + 75, i * 200 + 30);
                        window.draw(O);
                    }
                }
            }
            if (winOfX(matrix) == 1 || winOfO(matrix) == 1)
            {
                int win_id = winType(matrix);
                if (win_id == 1 || win_id == 2 || win_id == 3)
                {
                    hor_line.setPosition(40, ((win_id - 1) * 200) + 60);
                    window.draw(hor_line);
                }
                if (win_id == 4 || win_id == 5 || win_id == 6)
                {
                    ver_line.setPosition(((win_id - 4) * 266) + 115, 30);
                    window.draw(ver_line);
                }
                if (win_id == 7)
                {
                    cross1_line.setPosition(0, 0);
                    window.draw(cross1_line);
                }
                if (win_id == 8)
                {
                    cross2_line.setPosition(0, 0);
                    window.draw(cross2_line);
                }
            }
            window.display();
            if (winOfX(matrix) == 1)
            {
                Sleep(3000);
                window.clear();
                window.draw(Xwin);
                window.display();
                if (fout != NULL)
                {
                    fprintf(fout, "X\n");
                }
                Sleep(5000);
                window.close();
            }
            if (winOfO(matrix) == 1)
            {
                Sleep(3000);
                window.clear();
                window.draw(Owin);
                window.display();
                if (fout != NULL)
                {
                    fprintf(fout, "O\n");
                }
                Sleep(5000);
                window.close();
            }
            if (turns == 9 && winOfX(matrix) == 0 && winOfO(matrix) == 0)
            {
                Sleep(3000);
                window.clear();
                window.draw(remis);
                window.display();
                if (fout != NULL)
                {
                    fprintf(fout, "R\n");
                }
                Sleep(5000);
                window.close();
            }
        }

    }
    fclose(fout);
    fclose(fin);
    return 0;
}