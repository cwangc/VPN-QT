#ifndef LOGINDLG_H
#define LOGINDLG_H
 
#include <QtWidgets>
#include <QDialog>
#include <QRadioButton>
#include <QFutureWatcher>
#include <QIcon>
#include <QCheckBox>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
 
 
class LoginDlg : public QDialog
{
    Q_OBJECT
         
public:
    LoginDlg(QWidget* = 0);
    virtual ~LoginDlg();
    bool getLoginStatus();
    void verifyAccountInfo(QString username, QString password);
    void openDialog();

signals:
    void loginSuccess();
    void addLog(const QString &l);
    void showBalloon(const int &type, const QString &t, const QString &m);

public slots:
    virtual void accept();
    void beginVerify();
    void endVerify();
         
private:
    QLabel      *img;
    QLineEdit   *usrLineEdit;
    QLineEdit   *pwdLineEdit;
    QLabel      *username;
    QLabel      *passwd;
    QPushButton *connectBtn;
    QCheckBox   *remember;
    QIcon       *icon;
    bool        loginStatus;
    QFutureWatcher<void> *watcher;

    char accountInfoFile[255];
};
 
#endif // LOGINDLG_H
