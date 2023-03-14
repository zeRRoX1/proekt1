#pragma once

#include <iostream>

using namespace std;


class MAIN {
    const char* Words[25]{
        "ПРОГРАММА", "ТЕЛЕВИЗОР", "ЭКРАН", "ИЗОБРАЖЕНИЕ", "ВСТРЕЧА", "КРЫЛЬЦО", "ЛИСТОК", "ФИГУРА",
        "ДЕЖУРНЫЙ", "ДЛИНОШЕЕЕ", "ПЯТИКЛАCСНИК", "ЛАМПОЧКА", "ТАБЕЛЬ", "СМЕШАРИК", "ПРИКЛЮЧЕНИЕ", "ЭНЕРГИЯ",
        "QUEUE", "ЭМПАТ", "КОШКА", "СОБАКА", "ХИМИЯ", "ВАСАБИ", "МИЛОСТЬ", "ЗАПОВЕДЬ", "ИСКУШЕНИ"
    };
    string word_;
    int lengthWord{ 0 };
    int rd;
    string guessLetter;
    char find_next;
    std::wstring::size_type pos;
    string nazv;
    int osh = 6;
    string next2;

public:
    MAIN() {

    }
    // выбор слова;
    void choiceWord()
    {
        rd = rand() % 25; // Выбираем случайное слово из массива;
        lengthWord = strlen(Words[rd]); // Записываем длинну слова в переменную;
        for (int i = 0; i < lengthWord; i++)
        {
            guessLetter += '_'; 
            guessLetter += ' ';
            word_ = Words[rd]; // копия слова 
            word_ += ' '; // с пробелами; 
        }
        /*cout << lengthWord << " lenght" << endl;
        cout << guessLetter << " guess" << endl;
        cout << word_ << " word_" << endl;*/
    }
    void printWord()
    {
        cout << "\t" << guessLetter;
    }
    void game() {
        choiceWord();
        printWord();
        cout << endl;
        cout << "Угадайте следующую букву: ";
        cin >> find_next;
        cout << endl;
        find_next = toupper(find_next); // в верхний регистр
        pos = word_.find(find_next); // ищем позицию в слове

        /*cout << find_next << endl;
        cout << pos << endl;*/

        if (pos > 0) // Если буквы в слове нет
        {
            mistake(find_next); // проверка на ошибки;
        }
        else
        {
            guessLetter[pos] = find_next; 
            word_[pos] = '!'; 
            nazv += find_next;
            --lengthWord;
            std::wcout << L"\nВерно! - ";
            if (!lengthWord)
            {
                printWord();
                cout << "\n ПОЗДРАВЛЯЕМ!!! Вы полностью разгадали слово!\n\n";
                osh = 0;
            }
            next2 = " следующую ";
        }
        nazv += find_next;
        printWord();
    }

    const void sentence()
    {
        std::wcout << '\n' << vis[osh] << '\n'; 
        std::wcout << "Вы можете ещё " << osh - 1; 
        if (osh == 2 || osh == 6)
            cout << osh << " раз";
        else cout << osh <<" раза";
        cout << " неверно назвать букву!\n";
    }

    void mistake(char find_next) 
    {
        if (nazv.find(find_next) > 0) 
        {
            --osh; 
            cout << "\nТакой буквы нет.\n";

            switch (--osh) 
            {  
            case 0:
                cout << "\nВы проиграли.\n\n";
                cout << vis[6];
                cout << word_ << "\n"; 
            case 1:
                cout << "Вам больше нельзя ошибаться!\n\n";
                cout << vis[0];
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:  
                sentence(); 
                break;
            default: cout << "Наверно ";
                break;
            }
        }
        else cout << "Вы уже называли эту букву "; 
        cout << "\nСлово - " << word_;
    }

    const char* vis[6]
    { "             \n"
      "             \n"
      "             \n"
      "             \n"
      "             \n"
      "_____________\n",

      "            |\n"
      "            |\n"
      "            |\n"
      "            |\n"
      "            |\n"
      "____________|\n",

      "|           |\n"
      "|           |\n"
      "|           |\n"
      "|           |\n"
      "|           |\n"
      "|___________|\n",

      "|‾‾‾‾‾‾‾‾‾‾‾|\n"
      "|           |\n"
      "|           |\n"
      "|           |\n"
      "|           |\n"
      "|___________|\n",

      "|‾‾‾‾‾|‾‾‾‾‾|\n"
      "|    (@)    |\n"
      "|           |\n"
      "|           |\n"
      "|           |\n"
      "|___________|\n",
        
      "|‾‾‾‾‾|‾‾‾‾‾|\n"
      "|    (@)    |\n"
      "|    /0\    |\n"
      "|    / \    |\n"
      "|           |\n"
      "|___________|\n",
    };
};