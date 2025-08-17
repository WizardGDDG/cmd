#include <iostream>
#include "Command.h"
#include "CopyCommand.h"
#include "PasteCommand.h"
#include "DeleteCommand.h"
#include "TextEditor.h"
using namespace std;
void printMenu()
{
    cout << "Доступные команды" << endl;
    cout << "1. Копировать выделенный текст" << endl;
    cout << "2. Вставить скопированный текст" << endl;
    cout << "3. Удалить выделенный текст" << endl;
    cout << "4. Отменить последнее действие" << endl;
    cout << "5. Закончить выполнение программы" << endl;
}
int main()
{
    setlocale(LC_ALL, "rus");
    
    
    TextEditor te = TextEditor();
    string text;
    CopyCommand cc = CopyCommand(text);
    PasteCommand pc = PasteCommand(text);
    DeleteCommand dc = DeleteCommand(text);
    int chance;
    Command* c;
    printMenu();
    do
    {
        
        cin >> chance;
        switch (chance)
        {
        case 1:
            cc.execute();
            te.com.push_back(&cc);
            break;
        case 2:
            pc.execute();
            te.com.push_back(&pc);
            break;
        case 3:
            dc.execute();
            te.com.push_back(&dc);
            break;
        case 4:
            if (!te.com.empty())
            {
                c = te.com.back();
                c->undo();
            }
            break;
        }
        
    } while (chance != 5);
    
}

