#include "loginwindow.h"
#include "post.h"
#include "user.h"
#include <QApplication>
Comment com;
QHash<Category,QVector<Post>> all_post;//所有帖子
QVector<user_variable> all_users;//所有用户
int max_id;//最大用户id

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginWindow w;//登录界面
    w.show();

    return a.exec();
}
