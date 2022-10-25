#ifndef INPUTHYPER_H
#define INPUTHYPER_H

#include <QDialog>

namespace Ui {
class inputhyper;
}

class inputhyper : public QDialog
{
    Q_OBJECT

public:
    explicit inputhyper(QWidget *parent = nullptr);
    ~inputhyper();
    QString name();
    QString hyperlink();
    QString description();
private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::inputhyper *ui;
};

#endif // INPUTHYPER_H
