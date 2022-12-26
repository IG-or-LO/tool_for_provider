#include "qdinamiccheckbox.h"

qdinamicCheckBox::qdinamicCheckBox( QWidget *parent):
    QCheckBox(parent)
{

    ResID++;            // Увеличение счетчика на единицу
    checkBoxID = ResID;   /* Присвоение кнопке номера, по которому будет производиться
                         * дальнейшая работа с кнопок
                         * */
    setObjectName("dinamicCheckBox");
}

qdinamicCheckBox::~qdinamicCheckBox()
{

}

/* Метод для возврата значения номера кнопки
 * */
int qdinamicCheckBox::getID()
{
    return checkBoxID;
}

/* Инициализация статической переменной класса.
 * Статическая переменная класса должна инициализироваться в обязательном порядке
 * */
int qdinamicCheckBox::ResID = 0;
