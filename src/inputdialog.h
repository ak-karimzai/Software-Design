#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QDialog>
#include <QInputDialog>

class QLineEdit;
class QLabel;

class SubjectDialog : public QDialog
{
    Q_OBJECT
public:
    explicit SubjectDialog(QWidget *parent = nullptr);

    static QStringList getSubjectDetails(QWidget *parent, bool *ok = nullptr);

private:
    QList<QLineEdit*> fields;
};

#endif // INPUTDIALOG_H
