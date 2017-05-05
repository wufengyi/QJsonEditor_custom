#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class QJsonModel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void slotMenuOpen();
    void slotMenuSave();
    void slotMenuExit();
    void slotContextEdit();
    void slotContextInsert();

private:
    Ui::MainWindow *m_ui;
    QJsonModel *m_model;
};

#endif // MAINWINDOW_H
