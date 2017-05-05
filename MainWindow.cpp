#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "qjsonmodel.h"

#include <QFileDialog>
#include <QInputDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::MainWindow),
    m_model(new QJsonModel)
{
    m_ui->setupUi(this);

    connect(m_ui->actionOpen, &QAction::triggered, this, &MainWindow::slotMenuOpen);
    connect(m_ui->actionSave, &QAction::triggered, this, &MainWindow::slotMenuSave);
    connect(m_ui->actionExit, &QAction::triggered, this, &MainWindow::slotMenuExit);

    m_ui->treeView->setContextMenuPolicy(Qt::ActionsContextMenu);
    QAction *editAction = new QAction("Edit", m_ui->treeView);
    QAction *insertAction = new QAction("Insert child", m_ui->treeView);

    connect(editAction, &QAction::triggered, this, &MainWindow::slotContextEdit);
    connect(insertAction, &QAction::triggered, this, &MainWindow::slotContextInsert);

    m_ui->treeView->addAction(editAction);
    m_ui->treeView->addAction(insertAction);

    m_ui->treeView->setModel(m_model);
}

MainWindow::~MainWindow()
{
    delete m_ui;
    delete m_model;
}

void MainWindow::slotMenuOpen()
{
    QString filename = QFileDialog::getOpenFileName();
    qDebug() << "opening " << filename << " JSON file";

    if (!m_model->load(filename))
    {
        qDebug() << "failed to parse " << filename;
    }
}

void MainWindow::slotMenuSave()
{
    QString filename = QFileDialog::getSaveFileName();
    qDebug() << "saving modified JSON to " << filename;

    QFile saveFile(filename);
    if (!saveFile.open(QIODevice::ReadWrite | QIODevice::Truncate))
    {
        qDebug() << "Cannot save modified json to: " << filename << "reason: " << saveFile.errorString();
        return;
    }
    QJsonObject obj;
//    saveFile.write(QJsonDocument(m_model->dumpTo(obj)).toJson());
    saveFile.close();
}

void MainWindow::slotMenuExit()
{
    close();
}

void MainWindow::slotContextEdit()
{
//    QList<QtreeViewItem*> selected = this->ui->treeView->selectedItems();

//    if(selected.length() < 1) {
//        return;
//    }

//    QtreeViewItem *item = selected.at(0);
//    QString newValue = QInputDialog::getText(this, "New value", "", QLineEdit::Normal, item->text(0));
//    if(newValue != "")
//        item->setText(0, newValue);
}

void MainWindow::slotContextInsert()
{
//    QList<QtreeViewItem*> selected = this->ui->treeView->selectedItems();

//    if(selected.length() < 1) {
//        return;
//    }

//    QtreeViewItem *item = selected.at(0);
//    QtreeViewItem *child = new QtreeViewItem(item);
//    child->setText(0, "new child");
//    item->addChild(child);
}
