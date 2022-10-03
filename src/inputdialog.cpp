#include "inputdialog.h"

#include <QLabel>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QIntValidator>
#include <QFormLayout>

SubjectDialog::SubjectDialog(QWidget *parent) : QDialog(parent)
{
    QFormLayout *lytMain = new QFormLayout(this);
    std::list<QString> labels = {"Subject Name:", "Marks: "};

    QLabel *tLabel = new QLabel(QString("Subject Name:"), this);
    QLineEdit *tLine = new QLineEdit(this);
    lytMain->addRow(tLabel, tLine);

    fields << tLine;

    tLabel = new QLabel(QString("Marks:"), this);
    tLine = new QLineEdit(this);
    tLine->setValidator(new QIntValidator(0, 100, this));
    lytMain->addRow(tLabel, tLine);
    fields << tLine;

    QDialogButtonBox *buttonBox = new QDialogButtonBox
            ( QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
              Qt::Horizontal, this );
    lytMain->addWidget(buttonBox);

    bool conn = connect(buttonBox, &QDialogButtonBox::accepted,
                   this, &SubjectDialog::accept);
    Q_ASSERT(conn);
    conn = connect(buttonBox, &QDialogButtonBox::rejected,
                   this, &SubjectDialog::reject);
    Q_ASSERT(conn);

    setLayout(lytMain);
}

QStringList SubjectDialog::getSubjectDetails(QWidget *parent, bool *ok)
{
    SubjectDialog *dialog = new SubjectDialog(parent);

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
