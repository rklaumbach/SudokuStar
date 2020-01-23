#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <array>
#include <QDebug>
#include <string>
#include <time.h>
#include <chrono>
#include <thread>
#include <QTime>
#include <vector>
#include <fstream>
#include <iostream>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QDir>


bool visualize = true;
int visualization_speed = 25;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowTitleHint|Qt::WindowCloseButtonHint|Qt::WindowMinimizeButtonHint);


    connect(ui->sudokuBoard,SIGNAL(itemChanged(QTableWidgetItem*)),this,SLOT(validate_input(QTableWidgetItem*)));
    init_board();
}

void MainWindow::validate_input(QTableWidgetItem* item)
{
    QString itemStr=item->text();

    if(itemStr.toInt()<=0 || itemStr.toInt()>9)
    {
        item->setText("");
        item=new QTableWidgetItem();
    }
}

void MainWindow::init_board()
{
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
        {
            QTableWidgetItem *item=new QTableWidgetItem();
            ui->sudokuBoard->setItem(i,j,item);
        }
}

void MainWindow::display_clues(std::array<std::array<int,9>,9> &board)
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            int num=board[i][j];

            QTableWidgetItem *item= ui->sudokuBoard->item(i,j);
            item->setText(QString::number(num));
            item->setTextAlignment(Qt::AlignCenter);
            item->setForeground(QBrush(QColor(0, 0, 255)));
        }
    }
}

void MainWindow::prepareBoard(std::array<std::array<int,9>,9> &board)
{
    qDebug() << "I got to prepareBoard!";
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            QTableWidgetItem *item= ui->sudokuBoard->item(i,j);

            QString itemStr=item->text();
            int num;
            std::string utf8_text = itemStr.toUtf8().constData();
            qDebug() << itemStr.isEmpty();

            if(itemStr.isEmpty()){
                num = 0;
            }else{
                num=itemStr.toInt();
            }

            board[i][j]=num;
        }
    }
}

std::vector<int> MainWindow::possible_values(int y, int x)
{
    std::array<bool, 10> bools = {false, true, true, true, true, true, true, true, true, true};

    for (int i = 0; i < solution[0].size(); i++)
    {
        if (bools[solution[y][i]])
        {
            bools[solution[y][i]] = false;
        }
    }

    for (int i = 0; i < solution.size(); i++)
    {
        if (bools[solution[i][x]])
        {
            bools[solution[i][x]] = false;
        }
    }

    for (int i = (y / 3) * 3; i < (y / 3) * 3 + 3; i++)
    {
        for (int j = (x / 3) * 3; j < (x / 3) * 3 + 3; j++)
        {
            if (bools[solution[i][j]])
            {
                bools[solution[i][j]] = false;
            }
        }
    }

    std::vector<int> possibilities;

    for (int i = 1; i < bools.size(); i++)
    {
        if (bools[i])
        {
            possibilities.push_back(i);
        }
    }

    return possibilities;
}

std::array<int, 2> MainWindow::next_entry(int i, int j)
{
    do
    {
        if (i < puzzle.size())
        {
            i++;
        }
        else
        {
            j++;
            i = 0;
        }
    } while (puzzle[i][j] != 0);

    return {i, j};
}

void MainWindow::updateEntry(int i, int j, int num){
    QTableWidgetItem *item= ui->sudokuBoard->item(i,j);
    item->setText(QString::number(num));
    item->setTextAlignment(Qt::AlignCenter);
    item->setForeground(QBrush(QColor(0, 0, 0)));

}

void delay()
{
    QTime dieTime = QTime::currentTime().addMSecs(visualization_speed);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

std::vector<std::string> MainWindow::read_puzzles(){

    QString workingDir = QDir::currentPath();
    QString path = workingDir + "/puzzles.txt";

    qDebug() << path;

    std::vector<std::string> puzzles;
    QFile file(":/puzzles/puzzles.txt");
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream in(&file);

    while(!in.atEnd()) {
        QString line = in.readLine();
        std::string realString = line.toStdString();
        puzzles.push_back(realString);

    }

    file.close();
    return puzzles;

    /*
    std::string filename = "C:\\Users\\KingRobert\\Documents\\C++ Projects\\SudokuStar\\puzzles.txt";

    std::ifstream file_(filename.c_str());
    std::vector<std::string> puzzles;
    std::string puzzle;
    if(file_.is_open()){
        while(std::getline(file_, puzzle))
        {
            puzzles.push_back(puzzle);
        }
        file_.close();
    }else{
        qDebug() << "file not open";
    }

    return puzzles;
    */
}

std::array<std::array<int,9>,9> MainWindow::select_board(){
    std::vector<std::string> puzzles= read_puzzles();
    srand(time(NULL));
    std::string puzzle_code = puzzles[rand() % puzzles.size()];
    std::array<std::array<int,9>,9> board;
    for(int i = 0; i<9;i++){
        for(int j = 0; j<9;j++){
            board[i][j] = (int) puzzle_code[i*9+j]-48;//because of c++ converting char to ascii value silliness
            qDebug() << board[i][j];
        }
    }
    return board;
}

bool MainWindow::isSolved(int i, int j){
    int r = i;
    int c = j;
    while (r<9){
        while(c<9){
            if(solution[r][c] == 0){
                return false;
            }
            c++;
        }
        r++;
    }
    return true;
}



bool MainWindow::solve(int i, int j)
{
    if(isSolved(i,j)){
        return true;
    }
    qDebug() << "I got to the solver!";
    if (puzzle[i][j] != 0)
    {
        int next_i = next_entry(i, j)[0];
        int next_j = next_entry(i, j)[1];
        return solve(next_i, next_j);
    }
    std::vector<int> possibilities = possible_values(i, j);

    /*if (i == 8 && j == 8)
    {
        if(visualize){
            delay();
        }
        if(solution[8][8]==0){
            solution[8][8] = possibilities[0];
            updateEntry(8,8,solution[8][8]);
        }
        return true;
    }*/

    if (possibilities.size() == 0)
    {
        return false;
    }

    int count = 0;
    while (count < possibilities.size())
    {
        if(visualize){
            delay();
        }
        solution[i][j] = possibilities[count];
        updateEntry(i,j,solution[i][j]);
        int next_i = next_entry(i, j)[0];
        int next_j = next_entry(i, j)[1];
        if (!solve(next_i, next_j))
        {
            if(visualize){
                delay();
            }
            solution[i][j] = 0;
            updateEntry(i,j,solution[i][j]);
        }
        else
        {
            return true;
        }
        count++;
    }
    return false;
}

void MainWindow::on_solveBtn_clicked()
{
    std::array<std::array<int,9>,9> board;
    prepareBoard(board);
    init_board();
    display_clues(board);
    puzzle = board;
    solution = board;

    for(int i = 0; i<9;i++){
        for(int j = 0; j<9; j++){
            qDebug() << puzzle[i][j];
        }
    }
    bool success=solve(0,0);

    qDebug() << "I finished solving.";

    ui->clearBtn->show();
    ui->generateBtn->show();

}


MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_clearBtn_clicked()
{
    init_board();

}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    visualize = !visualize;
}

void MainWindow::on_generateBtn_clicked()
{
    init_board();
    std::array<std::array<int,9>,9> board = select_board();

    display_clues(board);
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    visualization_speed = (100-value)+25;
}
