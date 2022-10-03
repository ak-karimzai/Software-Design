#include "studentdialog.h"

#include <QLabel>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QFormLayout>

StudentDialog::StudentDialog(QWidget *parent) : QDialog(parent)
{
    QFormLayout *lytMain = new QFormLayout(this);

    QLabel *tLabel = new QLabel(QString("Student Full Name:"), this);
    QLineEdit *tLine = new QLineEdit(this);
    lytMain->addRow(tLabel, tLine);

    fields << tLine;

    tLabel = new QLabel(QString("Student Adm No:"), this);
    tLine = new QLineEdit(this);
    lytMain->addRow(tLabel, tLine);
    fields << tLine;

    QDialogButtonBox *buttonBox = new QDialogButtonBox
            ( QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
              Qt::Horizontal, this );
    lytMain->addWidget(buttonBox);

    bool conn = connect(buttonBox, &QDialogButtonBox::accepted,
                   this, &StudentDialog::accept);
    Q_ASSERT(conn);
    conn = connect(buttonBox, &QDialogButtonBox::rejected,
                   this, &StudentDialog::reject);
    Q_ASSERT(conn);

    setLayout(lytMain);
}

QStringList StudentDialog::getStudentDetails(QWidget *parent, bool *ok)
{
    StudentDialog *dialog = new StudentDialog(parent);

    QStringList list;

    const int ret = dialog->exec();
    if (ok)
        *ok = !!ret;

    if (ret) {
        foreach (auto field, dialog->fields) {
            list << field->text();
        }
    }

    dialog->deleteLater();

    return list;
}
