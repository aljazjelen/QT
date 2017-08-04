#ifndef FORM_H
#define FORM_H

#include <QWidget>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT
private:
    Ui::Form *ui;
    //float *p;
public:
    explicit Form(QWidget *parent = nullptr);
    QString name = "New Form";

signals:
    void passData(Form*);

public slots:

private slots:

    void on_confirmButton_clicked();
};

#endif // FORM_H
