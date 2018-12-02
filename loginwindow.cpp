#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(QObject::tr("登录"));
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_sign_in_clicked()
{
    QString username_input = ui->username->text();
    QString password_input = ui->password->text();
    bool username_flag = false;
    if(username_input.isEmpty())
    {
        ui->warning->setText("请输入用户名");
        qDebug() << "Please input username!";
        return;
    }
    else if(password_input.isEmpty())
    {
        ui->warning->setText("请输入密码");
        qDebug() << "Please input password!";
        return;
    }
    else
    {
        QString select_sql = "select id, username,password, level, responsible_plate from users";
        if(!sql_query.exec(select_sql))
            qDebug()<<sql_query.lastError();
        else
        {
            int id;
            QString level;
            int responsible_plate;
            u = new User;
            bool judge = u->sign_in(username_input, password_input, username_flag, id, level, responsible_plate);

            if(judge)
            {
                QString select_sql = "select id, username,password, level, responsible_plate from users";
                if(!sql_query.exec(select_sql))
                    qDebug()<<sql_query.lastError();
                else
                {
                    while(sql_query.next())
                    {
                        user_variable uu;
                        uu.id = sql_query.value(0).toInt();
                        uu.username = sql_query.value(1).toString();
                        uu.password = sql_query.value(2).toString();
                        uu.level = sql_query.value(3).toString();
                        uu.responsible_plate = sql_query.value(4).toInt();
                        all_users.push_back(uu);
                    }
                }
                this->close();
                if(id <= 5)
                {
                    administrators = new Administrators;
                    administrators->id = id;
                    administrators->username = username_input;
                    administrators->password = password_input;
                    administrators->level = level;
                    administrators->init_class();
                    connect(administrators->mainview->ui->sign_out,SIGNAL(clicked(bool)),this,SLOT(show_loginwindow()));
                }
                else if(id > 5 && level == "ordinary")
                {
                    ordinary_user = new Ordinary_user;
                    ordinary_user->id = id;
                    ordinary_user->username = username_input;
                    ordinary_user->password = password_input;
                    ordinary_user->level = level;
                    ordinary_user->responsible_plate = responsible_plate;
                    ordinary_user->init_class();
                    connect(ordinary_user->mainview->ui->sign_out,SIGNAL(clicked(bool)),this,SLOT(show_loginwindow()));
                }
                else if(id > 5 && level == "moderator")
                {
                    moderator_user = new Moderator_user;
                    moderator_user->id = id;
                    moderator_user->username = username_input;
                    moderator_user->password = password_input;
                    moderator_user->level = level;
                    moderator_user->responsible_plate = responsible_plate;
                    moderator_user->init_class();
                    connect(moderator_user->mainview->ui->sign_out,SIGNAL(clicked(bool)),this,SLOT(show_loginwindow()));
                }
            }
            else
            {
                if(!username_flag)
                {
                    ui->username->setText(NULL);
                    ui->password->setText(NULL);
                    ui->warning->setText("用户名不存在！");
                    qDebug() << "Username doesn't exist!";
                    return;
                }
                else
                {
                    ui->warning->setText("密码错误！请重试！");
                    qDebug() << "Password is wrong.Please try again.";
                    ui->password->setText(NULL);
                    return;
                }
            }
        }
    }
}

void LoginWindow::on_sign_up_clicked()
{
    view = new signup(this);
    view->setModal(true);
    view->show();
}

void LoginWindow::show_loginwindow()
{
    new_mainview = new LoginWindow;
    new_mainview->show();
}
