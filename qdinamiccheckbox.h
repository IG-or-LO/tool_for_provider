#ifndef QDINAMICCHECKBOX_H
#define QDINAMICCHECKBOX_H

#include <QObject>
#include <QCheckBox>

class qdinamicCheckBox: public QCheckBox
{
    Q_OBJECT
   public:
       explicit qdinamicCheckBox( QWidget *parent = 0);
       ~qdinamicCheckBox();
       static int ResID;   // Статическая переменная, счетчик номеров кнопок
       int getID();        // Функция для возврата локального номера кнопки


   public slots:

   private:
       int checkBoxID = 0;   // Локальная переменная, номер кнопки
   };

#endif // QDINAMICCHECKBOX_H
