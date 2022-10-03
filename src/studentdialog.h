#ifndef STUDENTDIALOG_H
#define STUDENTDIALOG_H


#include <QDialog>

class QLineEdit;
class QLabel;

class StudentDialog : public QDialog
{
    Q_OBJECT
public:
    explicit StudentDialog(QWidget *parent = nullptr);

    static QStringList getStudentDetails(QWidget *parent, bool *ok = nullptr);

private:
    QList<QLineEdit*> fields;
};

#endif // STUDENTDIALOG_H
