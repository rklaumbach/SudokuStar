#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include <QTableWidget>
#include <array>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

private slots:
    void validate_input(QTableWidgetItem* item);
/*
    void on_actionReset_triggered();

    void on_actionAbout_triggered();

    void on_actionExit_triggered();
*/
    void on_solveBtn_clicked();

    void on_clearBtn_clicked();

    void on_checkBox_stateChanged(int arg1);

    void on_generateBtn_clicked();

    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    std::vector<int> possible_values(int y, int x);
    std::array<int, 2> next_entry(int i, int j);
    void prepareBoard(std::array<std::array<int,9>,9> &board);
    void display_clues(std::array<std::array<int,9>,9> &board);
    void init_board();
    void updateEntry();
    bool solve(int i, int j);
    std::array<std::array<int, 9>, 9> puzzle;
    std::array<std::array<int, 9>, 9> solution;
    void print_board(std::array<std::array<int, 9>, 9> board);
    void updateEntry(int i, int j, int num);
    bool isSolved(int i, int j);

};
#endif // MAINWINDOW_H
