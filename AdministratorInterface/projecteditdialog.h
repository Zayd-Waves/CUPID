#ifndef PROJECTEDITDIALOG_H
#define PROJECTEDITDIALOG_H
#include "Storage/project.h"
#include <QDialog>


namespace Ui {
class ProjectEditDialog;
}

class AdminInputManager;

class ProjectEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ProjectEditDialog(AdminInputManager* adminInputManager, QWidget *parent = 0);
    ~ProjectEditDialog();
    void show();
    void showEdit(Project* project);
    Project* getProject();

private slots:
    void on_saveButton_clicked();
    void on_cancelButton_clicked();

private:
    Ui::ProjectEditDialog *ui;
    Project* project;
    AdminInputManager* adminInputManager;
};

#endif // PROJECTEDITDIALOG_H
