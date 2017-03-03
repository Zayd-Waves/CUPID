#include "teamresultdialog.h"
#include "ui_teamresultdialog.h"
#include <QTextCursor>
#include "Storage/student.h"

TeamResultDialog::TeamResultDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::TeamResultDialog)
{
  ui->setupUi(this);
  ui->resultText->setReadOnly(true);
}

TeamResultDialog::~TeamResultDialog()
{
  delete ui;
}

void TeamResultDialog::show(QList<Team*> teams)
{
  ui->showDetailsCheck->setChecked(false);
  this->teams = teams;
  showResult();
  QDialog::show();
}

void TeamResultDialog::on_closeButton_clicked()
{
  this->close();
}

void TeamResultDialog::on_showDetailsCheck_toggled(bool checked)
{
  if (checked) {
    showDetailedResult();
  } else {
    showResult();
  }
}

void TeamResultDialog::showResult()
{
  QString result = "";
  int teamCount = 1;

  foreach (Team* team, teams) {
    result += QString("Group #%1\n").arg(teamCount++);
    result += "-------------------------\n";

    int studentCount = 1;
    foreach(Student* student, team->getAllStudents()) {
      result += QString("  %1) %2 %3 (%4)\n").arg(studentCount++)
                                             .arg(student->getFirstName())
                                             .arg(student->getLastName())
                                             .arg(student->getStudentNumber());
    }
    result += "\n";
  }

  ui->resultText->document()->setPlainText(result);
  ui->resultText->moveCursor(QTextCursor::Start);
  ui->resultText->ensureCursorVisible();
}

void TeamResultDialog::showDetailedResult()
{
  QString result = "";
  int teamCount = 1;

  foreach (Team* team, teams) {
    result += QString("Group #%1\n").arg(teamCount++);
    result += "-------------------------\n";

    int studentCount = 1;
    foreach(Student* student, team->getAllStudents()) {
      result += QString("  %1) %2 %3 (%4)\n").arg(studentCount++)
                                             .arg(student->getFirstName())
                                             .arg(student->getLastName())
                                             .arg(student->getStudentNumber());
    }

    result += "\n";
    result += QString("Total Group Compatibility: %1\n\n").arg(team->computeTeamCompatibility());

    result += "Student Compatibilities:\n";

    foreach(Student* s1, team->getAllStudents()) {
      foreach(Student* s2, team->getAllStudents()) {
        if (s1 == s2) continue;
        result += QString("  %1 %2 and %3 %4: %5\n")
                                               .arg(s1->getFirstName())
                                               .arg(s1->getLastName())
                                               .arg(s2->getFirstName())
                                               .arg(s2->getLastName())
                                               .arg(team->getStudentCompatibility(s1, s2));
      }
      result += "\n";
    }

    result += "-------------------------\n\n";
  }

  ui->resultText->document()->setPlainText(result);
  ui->resultText->moveCursor(QTextCursor::Start);
  ui->resultText->ensureCursorVisible();
}
