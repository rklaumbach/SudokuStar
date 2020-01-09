#ifndef SUDOKUENTRY_H
#define SUDOKUENTRY_H

#include <QWidget>
#include <QPlainTextEdit>


class SudokuEntry : public QPlainTextEdit
{
    Q_OBJECT
    int i;
    int j;
public:
    explicit SudokuEntry(QWidget *parent = nullptr);
    int get_i();
    int get_j();

signals:

};

#endif // SUDOKUENTRY_H
