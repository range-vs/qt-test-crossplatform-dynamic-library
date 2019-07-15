#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    srand(time(nullptr));
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QLibrary lib("dynamic_library");
    QMessageBox msgBox;
    /*if(!lib.isLoaded()) // bug? (stack overflow)
    {
        msgBox.setText(lib.errorString());
        msgBox.exec();
        return;
    }*/
    LibraryType creatorLine = reinterpret_cast<LibraryType>(lib.resolve("createLine"));
    if(creatorLine)
    {
        ILine *l = creatorLine();
        if(l)
        {
            msgBox.setText(l->createLine().c_str());
            delete l;
        }
        else
            msgBox.setText("Error create object!");
    }
    else
        msgBox.setText(lib.errorString());
    msgBox.exec();
}
