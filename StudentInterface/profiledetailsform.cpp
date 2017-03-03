#include "profiledetailsform.h"
#include "ui_profiledetailsform.h"
#include "studentinputmanager.h"

ProfileDetailsForm::ProfileDetailsForm(StudentInputManager* sim, QWidget *parent) :
    QFrame(parent),
    ui(new Ui::ProfileDetailsForm)
{
    ui->setupUi(this);
    studentInputManager = sim;
}

ProfileDetailsForm::~ProfileDetailsForm()
{
    delete ui;
}

void ProfileDetailsForm::display(Student* student)
{
    this->student = student;

    QList<QuestionnaireAnswer*> profileQuestions = student->getProfile()->getAllAnswers();

    ui->rBq1a->setChecked(profileQuestions.at(0)->getOwnAnswer1Selected());
    ui->rBq1b->setChecked(profileQuestions.at(0)->getOwnAnswer2Selected());
    ui->rBq1c->setChecked(profileQuestions.at(0)->getOwnAnswer3Selected());
    ui->rBq1d->setChecked(profileQuestions.at(0)->getOwnAnswer4Selected());

    ui->cBq2a->setChecked(profileQuestions.at(0)->getGroupAnswer1Selected());
    ui->cBq2b->setChecked(profileQuestions.at(0)->getGroupAnswer2Selected());
    ui->cBq2c->setChecked(profileQuestions.at(0)->getGroupAnswer3Selected());
    ui->cBq2d->setChecked(profileQuestions.at(0)->getGroupAnswer4Selected());
    //


    ui->rBq3a->setChecked(profileQuestions.at(1)->getOwnAnswer1Selected());
    ui->rBq3b->setChecked(profileQuestions.at(1)->getOwnAnswer2Selected());
    ui->rBq3c->setChecked(profileQuestions.at(1)->getOwnAnswer3Selected());

    ui->cBq4a->setChecked(profileQuestions.at(1)->getGroupAnswer1Selected());
    ui->cBq4b->setChecked(profileQuestions.at(1)->getGroupAnswer2Selected());
    ui->cBq4c->setChecked(profileQuestions.at(1)->getGroupAnswer3Selected());
    //


    ui->radioButton->setChecked(profileQuestions.at(2)->getOwnAnswer1Selected());
    ui->radioButton_2->setChecked(profileQuestions.at(2)->getOwnAnswer2Selected());
    ui->radioButton_3->setChecked(profileQuestions.at(2)->getOwnAnswer3Selected());
    ui->radioButton_4->setChecked(profileQuestions.at(2)->getOwnAnswer4Selected());

    ui->checkBox->setChecked(profileQuestions.at(2)->getGroupAnswer1Selected());
    ui->checkBox_2->setChecked(profileQuestions.at(2)->getGroupAnswer2Selected());
    ui->checkBox_3->setChecked(profileQuestions.at(2)->getGroupAnswer3Selected());
    ui->checkBox_4->setChecked(profileQuestions.at(2)->getGroupAnswer4Selected());
    //


    ui->checkBox_5->setChecked(profileQuestions.at(3)->getOwnAnswer1Selected());
    ui->checkBox_6->setChecked(profileQuestions.at(3)->getOwnAnswer2Selected());
    ui->checkBox_7->setChecked(profileQuestions.at(3)->getOwnAnswer3Selected());
    ui->checkBox_8->setChecked(profileQuestions.at(3)->getOwnAnswer4Selected());

    ui->checkBox_9->setChecked(profileQuestions.at(3)->getGroupAnswer1Selected());
    ui->checkBox_10->setChecked(profileQuestions.at(3)->getGroupAnswer2Selected());
    ui->checkBox_11->setChecked(profileQuestions.at(3)->getGroupAnswer3Selected());
    ui->checkBox_12->setChecked(profileQuestions.at(3)->getGroupAnswer4Selected());
    //


    ui->checkBox_13->setChecked(profileQuestions.at(4)->getOwnAnswer1Selected());
    ui->checkBox_14->setChecked(profileQuestions.at(4)->getOwnAnswer2Selected());
    ui->checkBox_15->setChecked(profileQuestions.at(4)->getOwnAnswer3Selected());
    ui->checkBox_16->setChecked(profileQuestions.at(4)->getOwnAnswer4Selected());

    ui->checkBox_17->setChecked(profileQuestions.at(4)->getGroupAnswer1Selected());
    ui->checkBox_18->setChecked(profileQuestions.at(4)->getGroupAnswer2Selected());
    ui->checkBox_19->setChecked(profileQuestions.at(4)->getGroupAnswer3Selected());
    ui->checkBox_20->setChecked(profileQuestions.at(4)->getGroupAnswer4Selected());
    //


    ui->radioButton_5->setChecked(profileQuestions.at(5)->getOwnAnswer1Selected());
    ui->radioButton_6->setChecked(profileQuestions.at(5)->getOwnAnswer2Selected());
    ui->radioButton_7->setChecked(profileQuestions.at(5)->getOwnAnswer3Selected());
    ui->radioButton_8->setChecked(profileQuestions.at(5)->getOwnAnswer4Selected());

    ui->radioButton_9->setChecked(profileQuestions.at(5)->getGroupAnswer1Selected());
    ui->radioButton_10->setChecked(profileQuestions.at(5)->getGroupAnswer2Selected());
    ui->radioButton_56->setChecked(profileQuestions.at(5)->getGroupAnswer3Selected());
    ui->radioButton_11->setChecked(profileQuestions.at(5)->getGroupAnswer4Selected());
    //


    ui->radioButton_12->setChecked(profileQuestions.at(6)->getOwnAnswer1Selected());
    ui->radioButton_13->setChecked(profileQuestions.at(6)->getOwnAnswer2Selected());
    ui->radioButton_14->setChecked(profileQuestions.at(6)->getOwnAnswer3Selected());
    ui->radioButton_15->setChecked(profileQuestions.at(6)->getOwnAnswer4Selected());

    ui->checkBox_21->setChecked(profileQuestions.at(6)->getGroupAnswer1Selected());
    ui->checkBox_22->setChecked(profileQuestions.at(6)->getGroupAnswer2Selected());
    ui->checkBox_23->setChecked(profileQuestions.at(6)->getGroupAnswer3Selected());
    ui->checkBox_24->setChecked(profileQuestions.at(6)->getGroupAnswer4Selected());
    //


    ui->radioButton_16->setChecked(profileQuestions.at(7)->getOwnAnswer1Selected());
    ui->radioButton_17->setChecked(profileQuestions.at(7)->getOwnAnswer2Selected());
    ui->radioButton_18->setChecked(profileQuestions.at(7)->getGroupAnswer1Selected());
    ui->radioButton_19->setChecked(profileQuestions.at(7)->getGroupAnswer2Selected());
    //


    ui->radioButton_20->setChecked(profileQuestions.at(8)->getOwnAnswer1Selected());
    ui->radioButton_21->setChecked(profileQuestions.at(8)->getOwnAnswer2Selected());
    ui->radioButton_22->setChecked(profileQuestions.at(8)->getOwnAnswer3Selected());
    ui->radioButton_23->setChecked(profileQuestions.at(8)->getOwnAnswer4Selected());

    ui->checkBox_25->setChecked(profileQuestions.at(8)->getGroupAnswer1Selected());
    ui->checkBox_26->setChecked(profileQuestions.at(8)->getGroupAnswer2Selected());
    ui->checkBox_27->setChecked(profileQuestions.at(8)->getGroupAnswer3Selected());
    ui->checkBox_28->setChecked(profileQuestions.at(8)->getGroupAnswer4Selected());
    //


    ui->radioButton_24->setChecked(profileQuestions.at(9)->getOwnAnswer1Selected());
    ui->radioButton_25->setChecked(profileQuestions.at(9)->getOwnAnswer2Selected());
    ui->radioButton_26->setChecked(profileQuestions.at(9)->getOwnAnswer3Selected());
    ui->radioButton_27->setChecked(profileQuestions.at(9)->getOwnAnswer4Selected());

    ui->checkBox_29->setChecked(profileQuestions.at(9)->getGroupAnswer1Selected());
    ui->checkBox_30->setChecked(profileQuestions.at(9)->getGroupAnswer2Selected());
    ui->checkBox_31->setChecked(profileQuestions.at(9)->getGroupAnswer3Selected());
    ui->checkBox_32->setChecked(profileQuestions.at(9)->getGroupAnswer4Selected());
    //


    ui->checkBox_33->setChecked(profileQuestions.at(10)->getOwnAnswer1Selected());
    ui->checkBox_34->setChecked(profileQuestions.at(10)->getOwnAnswer2Selected());
    ui->checkBox_35->setChecked(profileQuestions.at(10)->getOwnAnswer3Selected());
    ui->checkBox_36->setChecked(profileQuestions.at(10)->getOwnAnswer4Selected());

    ui->checkBox_37->setChecked(profileQuestions.at(10)->getGroupAnswer1Selected());
    ui->checkBox_38->setChecked(profileQuestions.at(10)->getGroupAnswer2Selected());
    ui->checkBox_39->setChecked(profileQuestions.at(10)->getGroupAnswer3Selected());
    ui->checkBox_40->setChecked(profileQuestions.at(10)->getGroupAnswer4Selected());
    //


    ui->radioButton_28->setChecked(profileQuestions.at(11)->getOwnAnswer1Selected());
    ui->radioButton_29->setChecked(profileQuestions.at(11)->getOwnAnswer2Selected());
    ui->radioButton_30->setChecked(profileQuestions.at(11)->getOwnAnswer3Selected());
    ui->radioButton_31->setChecked(profileQuestions.at(11)->getOwnAnswer4Selected());

    ui->checkBox_41->setChecked(profileQuestions.at(11)->getGroupAnswer1Selected());
    ui->checkBox_42->setChecked(profileQuestions.at(11)->getGroupAnswer2Selected());
    ui->checkBox_43->setChecked(profileQuestions.at(11)->getGroupAnswer3Selected());
    ui->checkBox_44->setChecked(profileQuestions.at(11)->getGroupAnswer4Selected());
    //



    ui->checkBox_45->setChecked(profileQuestions.at(12)->getOwnAnswer1Selected());
    ui->checkBox_46->setChecked(profileQuestions.at(12)->getOwnAnswer2Selected());
    ui->checkBox_47->setChecked(profileQuestions.at(12)->getOwnAnswer3Selected());
    ui->checkBox_48->setChecked(profileQuestions.at(12)->getOwnAnswer4Selected());

    ui->checkBox_49->setChecked(profileQuestions.at(12)->getGroupAnswer1Selected());
    ui->checkBox_50->setChecked(profileQuestions.at(12)->getGroupAnswer2Selected());
    ui->checkBox_51->setChecked(profileQuestions.at(12)->getGroupAnswer3Selected());
    ui->checkBox_52->setChecked(profileQuestions.at(12)->getGroupAnswer4Selected());
    //


    ui->radioButton_32->setChecked(profileQuestions.at(13)->getOwnAnswer1Selected());
    ui->radioButton_33->setChecked(profileQuestions.at(13)->getOwnAnswer2Selected());
    ui->radioButton_34->setChecked(profileQuestions.at(13)->getOwnAnswer3Selected());
    ui->radioButton_35->setChecked(profileQuestions.at(13)->getOwnAnswer4Selected());

    ui->radioButton_36->setChecked(profileQuestions.at(13)->getGroupAnswer1Selected());
    ui->radioButton_37->setChecked(profileQuestions.at(13)->getGroupAnswer2Selected());
    ui->radioButton_38->setChecked(profileQuestions.at(13)->getGroupAnswer3Selected());
    ui->radioButton_39->setChecked(profileQuestions.at(13)->getGroupAnswer4Selected());
    //


    ui->radioButton_40->setChecked(profileQuestions.at(14)->getOwnAnswer1Selected());
    ui->radioButton_41->setChecked(profileQuestions.at(14)->getOwnAnswer2Selected());
    ui->radioButton_42->setChecked(profileQuestions.at(14)->getOwnAnswer3Selected());
    ui->radioButton_43->setChecked(profileQuestions.at(14)->getOwnAnswer4Selected());

    ui->radioButton_44->setChecked(profileQuestions.at(14)->getGroupAnswer1Selected());
    ui->radioButton_45->setChecked(profileQuestions.at(14)->getGroupAnswer2Selected());
    ui->radioButton_46->setChecked(profileQuestions.at(14)->getGroupAnswer3Selected());
    ui->radioButton_47->setChecked(profileQuestions.at(14)->getGroupAnswer4Selected());
    //


    ui->radioButton_48->setChecked(profileQuestions.at(15)->getOwnAnswer1Selected());
    ui->radioButton_49->setChecked(profileQuestions.at(15)->getOwnAnswer2Selected());
    ui->radioButton_50->setChecked(profileQuestions.at(15)->getOwnAnswer3Selected());
    ui->radioButton_51->setChecked(profileQuestions.at(15)->getOwnAnswer4Selected());

    ui->checkBox_53->setChecked(profileQuestions.at(15)->getGroupAnswer1Selected());
    ui->checkBox_54->setChecked(profileQuestions.at(15)->getGroupAnswer2Selected());
    ui->checkBox_55->setChecked(profileQuestions.at(15)->getGroupAnswer3Selected());
    ui->checkBox_56->setChecked(profileQuestions.at(15)->getGroupAnswer4Selected());
    //


    ui->radioButton_52->setChecked(profileQuestions.at(16)->getOwnAnswer1Selected());
    ui->radioButton_53->setChecked(profileQuestions.at(16)->getOwnAnswer2Selected());
    ui->radioButton_54->setChecked(profileQuestions.at(16)->getOwnAnswer3Selected());
    ui->radioButton_55->setChecked(profileQuestions.at(16)->getOwnAnswer4Selected());

    ui->checkBox_57->setChecked(profileQuestions.at(16)->getGroupAnswer1Selected());
    ui->checkBox_58->setChecked(profileQuestions.at(16)->getGroupAnswer2Selected());
    ui->checkBox_59->setChecked(profileQuestions.at(16)->getGroupAnswer3Selected());
    ui->checkBox_60->setChecked(profileQuestions.at(16)->getGroupAnswer4Selected());

    this->show();
}

void ProfileDetailsForm::on_saveButton_clicked()
{
  QList<QuestionnaireAnswer*> profileQuestions = this->student->getProfile()->getAllAnswers();

  // Question 1
  profileQuestions.at(0)->setOwnAnswer1Selected(ui->rBq1a->isChecked());
  profileQuestions.at(0)->setOwnAnswer2Selected(ui->rBq1b->isChecked());
  profileQuestions.at(0)->setOwnAnswer3Selected(ui->rBq1c->isChecked());
  profileQuestions.at(0)->setOwnAnswer4Selected(ui->rBq1d->isChecked());

  profileQuestions.at(0)->setGroupAnswer1Selected(ui->cBq2a->isChecked());
  profileQuestions.at(0)->setGroupAnswer2Selected(ui->cBq2b->isChecked());
  profileQuestions.at(0)->setGroupAnswer3Selected(ui->cBq2c->isChecked());
  profileQuestions.at(0)->setGroupAnswer4Selected(ui->cBq2d->isChecked());

  //

  // Question 2
  profileQuestions.at(1)->setOwnAnswer1Selected(ui->rBq3a->isChecked());
  profileQuestions.at(1)->setOwnAnswer2Selected(ui->rBq3b->isChecked());
  profileQuestions.at(1)->setOwnAnswer3Selected(ui->rBq3c->isChecked());
  profileQuestions.at(1)->setOwnAnswer4Selected(false);

  profileQuestions.at(1)->setGroupAnswer1Selected(ui->cBq4a->isChecked());
  profileQuestions.at(1)->setGroupAnswer2Selected(ui->cBq4b->isChecked());
  profileQuestions.at(1)->setGroupAnswer3Selected(ui->cBq4c->isChecked());
  profileQuestions.at(1)->setGroupAnswer4Selected(false);

  //

  // Question 3
  profileQuestions.at(2)->setOwnAnswer1Selected(ui->radioButton->isChecked());
  profileQuestions.at(2)->setOwnAnswer2Selected(ui->radioButton_2->isChecked());
  profileQuestions.at(2)->setOwnAnswer3Selected(ui->radioButton_3->isChecked());
  profileQuestions.at(2)->setOwnAnswer4Selected(ui->radioButton_4->isChecked());

  profileQuestions.at(2)->setGroupAnswer1Selected(ui->checkBox->isChecked());
  profileQuestions.at(2)->setGroupAnswer2Selected(ui->checkBox_2->isChecked());
  profileQuestions.at(2)->setGroupAnswer3Selected(ui->checkBox_3->isChecked());
  profileQuestions.at(2)->setGroupAnswer4Selected(ui->checkBox_4->isChecked());

  //

  // Question 4
  profileQuestions.at(3)->setOwnAnswer1Selected(ui->checkBox_5->isChecked());
  profileQuestions.at(3)->setOwnAnswer2Selected(ui->checkBox_6->isChecked());
  profileQuestions.at(3)->setOwnAnswer3Selected(ui->checkBox_7->isChecked());
  profileQuestions.at(3)->setOwnAnswer4Selected(ui->checkBox_8->isChecked());

  profileQuestions.at(3)->setGroupAnswer1Selected(ui->checkBox_9->isChecked());
  profileQuestions.at(3)->setGroupAnswer2Selected(ui->checkBox_10->isChecked());
  profileQuestions.at(3)->setGroupAnswer3Selected(ui->checkBox_11->isChecked());
  profileQuestions.at(3)->setGroupAnswer4Selected(ui->checkBox_12->isChecked());

  //

  // Question 5
  profileQuestions.at(4)->setOwnAnswer1Selected(ui->checkBox_13->isChecked());
  profileQuestions.at(4)->setOwnAnswer2Selected(ui->checkBox_14->isChecked());
  profileQuestions.at(4)->setOwnAnswer3Selected(ui->checkBox_15->isChecked());
  profileQuestions.at(4)->setOwnAnswer4Selected(ui->checkBox_16->isChecked());

  profileQuestions.at(4)->setGroupAnswer1Selected(ui->checkBox_17->isChecked());
  profileQuestions.at(4)->setGroupAnswer2Selected(ui->checkBox_18->isChecked());
  profileQuestions.at(4)->setGroupAnswer3Selected(ui->checkBox_19->isChecked());
  profileQuestions.at(4)->setGroupAnswer4Selected(ui->checkBox_20->isChecked());

  //

  // Question 6
  profileQuestions.at(5)->setOwnAnswer1Selected(ui->radioButton_5->isChecked());
  profileQuestions.at(5)->setOwnAnswer2Selected(ui->radioButton_6->isChecked());
  profileQuestions.at(5)->setOwnAnswer3Selected(ui->radioButton_7->isChecked());
  profileQuestions.at(5)->setOwnAnswer4Selected(ui->radioButton_8->isChecked());

  profileQuestions.at(5)->setGroupAnswer1Selected(ui->radioButton_9->isChecked());
  profileQuestions.at(5)->setGroupAnswer2Selected(ui->radioButton_10->isChecked());
  profileQuestions.at(5)->setGroupAnswer3Selected(ui->radioButton_56->isChecked());
  profileQuestions.at(5)->setGroupAnswer4Selected(ui->radioButton_11->isChecked());

  //

  // Question 7
  profileQuestions.at(6)->setOwnAnswer1Selected(ui->radioButton_12->isChecked());
  profileQuestions.at(6)->setOwnAnswer2Selected(ui->radioButton_13->isChecked());
  profileQuestions.at(6)->setOwnAnswer3Selected(ui->radioButton_14->isChecked());
  profileQuestions.at(6)->setOwnAnswer4Selected(ui->radioButton_15->isChecked());

  profileQuestions.at(6)->setGroupAnswer1Selected(ui->checkBox_21->isChecked());
  profileQuestions.at(6)->setGroupAnswer2Selected(ui->checkBox_22->isChecked());
  profileQuestions.at(6)->setGroupAnswer3Selected(ui->checkBox_23->isChecked());
  profileQuestions.at(6)->setGroupAnswer4Selected(ui->checkBox_24->isChecked());

  //

  // Question 8
  profileQuestions.at(7)->setOwnAnswer1Selected(ui->radioButton_16->isChecked());
  profileQuestions.at(7)->setOwnAnswer2Selected(ui->radioButton_17->isChecked());
  profileQuestions.at(7)->setOwnAnswer3Selected(false);
  profileQuestions.at(7)->setOwnAnswer4Selected(false);

  profileQuestions.at(7)->setGroupAnswer1Selected(ui->radioButton_18->isChecked());
  profileQuestions.at(7)->setGroupAnswer2Selected(ui->radioButton_19->isChecked());
  profileQuestions.at(7)->setGroupAnswer3Selected(false);
  profileQuestions.at(7)->setGroupAnswer4Selected(false);

  //

  // Question 9
  profileQuestions.at(8)->setOwnAnswer1Selected(ui->radioButton_20->isChecked());
  profileQuestions.at(8)->setOwnAnswer2Selected(ui->radioButton_21->isChecked());
  profileQuestions.at(8)->setOwnAnswer3Selected(ui->radioButton_22->isChecked());
  profileQuestions.at(8)->setOwnAnswer4Selected(ui->radioButton_23->isChecked());

  profileQuestions.at(8)->setGroupAnswer1Selected(ui->checkBox_25->isChecked());
  profileQuestions.at(8)->setGroupAnswer2Selected(ui->checkBox_26->isChecked());
  profileQuestions.at(8)->setGroupAnswer3Selected(ui->checkBox_27->isChecked());
  profileQuestions.at(8)->setGroupAnswer4Selected(ui->checkBox_28->isChecked());

  //

  // Question 10
  profileQuestions.at(9)->setOwnAnswer1Selected(ui->radioButton_24->isChecked());
  profileQuestions.at(9)->setOwnAnswer2Selected(ui->radioButton_25->isChecked());
  profileQuestions.at(9)->setOwnAnswer3Selected(ui->radioButton_26->isChecked());
  profileQuestions.at(9)->setOwnAnswer4Selected(ui->radioButton_27->isChecked());

  profileQuestions.at(9)->setGroupAnswer1Selected(ui->checkBox_29->isChecked());
  profileQuestions.at(9)->setGroupAnswer2Selected(ui->checkBox_30->isChecked());
  profileQuestions.at(9)->setGroupAnswer3Selected(ui->checkBox_31->isChecked());
  profileQuestions.at(9)->setGroupAnswer4Selected(ui->checkBox_32->isChecked());

  //

  // Question 11
  profileQuestions.at(10)->setOwnAnswer1Selected(ui->checkBox_33->isChecked());
  profileQuestions.at(10)->setOwnAnswer2Selected(ui->checkBox_34->isChecked());
  profileQuestions.at(10)->setOwnAnswer3Selected(ui->checkBox_35->isChecked());
  profileQuestions.at(10)->setOwnAnswer4Selected(ui->checkBox_36->isChecked());

  profileQuestions.at(10)->setGroupAnswer1Selected(ui->checkBox_37->isChecked());
  profileQuestions.at(10)->setGroupAnswer2Selected(ui->checkBox_38->isChecked());
  profileQuestions.at(10)->setGroupAnswer3Selected(ui->checkBox_39->isChecked());
  profileQuestions.at(10)->setGroupAnswer4Selected(ui->checkBox_40->isChecked());

  //

  // Question 12
  profileQuestions.at(11)->setOwnAnswer1Selected(ui->radioButton_28->isChecked());
  profileQuestions.at(11)->setOwnAnswer2Selected(ui->radioButton_29->isChecked());
  profileQuestions.at(11)->setOwnAnswer3Selected(ui->radioButton_30->isChecked());
  profileQuestions.at(11)->setOwnAnswer4Selected(ui->radioButton_31->isChecked());

  profileQuestions.at(11)->setGroupAnswer1Selected(ui->checkBox_41->isChecked());
  profileQuestions.at(11)->setGroupAnswer2Selected(ui->checkBox_42->isChecked());
  profileQuestions.at(11)->setGroupAnswer3Selected(ui->checkBox_43->isChecked());
  profileQuestions.at(11)->setGroupAnswer4Selected(ui->checkBox_44->isChecked());

  //

  // Question 13
  profileQuestions.at(12)->setOwnAnswer1Selected(ui->checkBox_45->isChecked());
  profileQuestions.at(12)->setOwnAnswer2Selected(ui->checkBox_46->isChecked());
  profileQuestions.at(12)->setOwnAnswer3Selected(ui->checkBox_47->isChecked());
  profileQuestions.at(12)->setOwnAnswer4Selected(ui->checkBox_48->isChecked());

  profileQuestions.at(12)->setGroupAnswer1Selected(ui->checkBox_49->isChecked());
  profileQuestions.at(12)->setGroupAnswer2Selected(ui->checkBox_50->isChecked());
  profileQuestions.at(12)->setGroupAnswer3Selected(ui->checkBox_51->isChecked());
  profileQuestions.at(12)->setGroupAnswer4Selected(ui->checkBox_52->isChecked());

  //

  // Question 14
  profileQuestions.at(13)->setOwnAnswer1Selected(ui->radioButton_32->isChecked());
  profileQuestions.at(13)->setOwnAnswer2Selected(ui->radioButton_33->isChecked());
  profileQuestions.at(13)->setOwnAnswer3Selected(ui->radioButton_34->isChecked());
  profileQuestions.at(13)->setOwnAnswer4Selected(ui->radioButton_35->isChecked());

  profileQuestions.at(13)->setGroupAnswer1Selected(ui->radioButton_36->isChecked());
  profileQuestions.at(13)->setGroupAnswer2Selected(ui->radioButton_37->isChecked());
  profileQuestions.at(13)->setGroupAnswer3Selected(ui->radioButton_38->isChecked());
  profileQuestions.at(13)->setGroupAnswer4Selected(ui->radioButton_39->isChecked());

  //

  // Question 15
  profileQuestions.at(14)->setOwnAnswer1Selected(ui->radioButton_40->isChecked());
  profileQuestions.at(14)->setOwnAnswer2Selected(ui->radioButton_41->isChecked());
  profileQuestions.at(14)->setOwnAnswer3Selected(ui->radioButton_42->isChecked());
  profileQuestions.at(14)->setOwnAnswer4Selected(ui->radioButton_43->isChecked());

  profileQuestions.at(14)->setGroupAnswer1Selected(ui->radioButton_44->isChecked());
  profileQuestions.at(14)->setGroupAnswer2Selected(ui->radioButton_45->isChecked());
  profileQuestions.at(14)->setGroupAnswer3Selected(ui->radioButton_46->isChecked());
  profileQuestions.at(14)->setGroupAnswer4Selected(ui->radioButton_47->isChecked());

  //

  // Question 16
  profileQuestions.at(15)->setOwnAnswer1Selected(ui->radioButton_48->isChecked());
  profileQuestions.at(15)->setOwnAnswer2Selected(ui->radioButton_49->isChecked());
  profileQuestions.at(15)->setOwnAnswer3Selected(ui->radioButton_50->isChecked());
  profileQuestions.at(15)->setOwnAnswer4Selected(ui->radioButton_51->isChecked());

  profileQuestions.at(15)->setGroupAnswer1Selected(ui->checkBox_53->isChecked());
  profileQuestions.at(15)->setGroupAnswer2Selected(ui->checkBox_54->isChecked());
  profileQuestions.at(15)->setGroupAnswer3Selected(ui->checkBox_55->isChecked());
  profileQuestions.at(15)->setGroupAnswer4Selected(ui->checkBox_56->isChecked());

  //

  // Question 17
  profileQuestions.at(16)->setOwnAnswer1Selected(ui->radioButton_52->isChecked());
  profileQuestions.at(16)->setOwnAnswer2Selected(ui->radioButton_53->isChecked());
  profileQuestions.at(16)->setOwnAnswer3Selected(ui->radioButton_54->isChecked());
  profileQuestions.at(16)->setOwnAnswer4Selected(ui->radioButton_55->isChecked());

  profileQuestions.at(16)->setGroupAnswer1Selected(ui->checkBox_57->isChecked());
  profileQuestions.at(16)->setGroupAnswer2Selected(ui->checkBox_58->isChecked());
  profileQuestions.at(16)->setGroupAnswer3Selected(ui->checkBox_59->isChecked());
  profileQuestions.at(16)->setGroupAnswer4Selected(ui->checkBox_60->isChecked());

  //

  studentInputManager->notifyOfUpdateProfileEvent();
  this->close();
}

void ProfileDetailsForm::on_cancelButton_clicked()
{
  this->close();
}
