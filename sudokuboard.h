#ifndef SUDOKUBOARD_H
#define SUDOKUBOARD_H

#include <QWidget>
#include <QGridLayout>
#include "qgridlayout.h"

class SudokuBoard : public QGridLayout
{
    Q_OBJECT
public:
    explicit SudokuBoard(QWidget *parent = nullptr);


signals:

};

#endif // SUDOKUBOARD_H
