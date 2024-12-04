#include <QApplication>
#include <QLabel>
#include <QString>
#include <rclcpp/rclcpp.hpp>
#include <status_interfaces/msg/system_status.hpp>
using SystemStatus = status_interfaces::msg::SystemStatus;
class SysStatusDisplay : public rclcpp::Node
{
private:
    /* data */
    rclcpp::Subscription<SystemStatus>::SharedPtr subscriber;
    QLabel* label;
public:
    SysStatusDisplay(/* args */):Node("sys_status_display")
    {
        label = new QLabel();
        subscriber = this->create_subscription<SystemStatus>("sys_status",10,[&](const SystemStatus::SharedPtr msg)->void{
            label -> setText(get_qstr_from_msg(msg));
        });
        label ->setText(get_qstr_from_msg(std::make_shared<SystemStatus>()));
        label ->show();
    };
    QString get_qstr_from_msg(const SystemStatus::SharedPtr msg)
    {
        std::stringstream show_str;
        show_str <<
        "==========新提供状态可视化显示工具==========\n" 
        <<"数 据 时 间：\t"<< msg->stamp.sec <<"\ts\n" 
        <<"主 机 名 字：\t"<< msg->host_name <<"\t\n" 
        <<"CPU 使用率：\t"<< msg->cpu_percent <<"\t%\n" 
        <<"内存使用率：\t"<< msg->memory_percent <<"\t%\n"
        <<"内存总大小：\t"<< msg->memory_total <<"\tMB\n"
        <<"剩余有效内存：\t"<< msg->memory_available <<"\tMB\n"
        <<"网络发送量\t"<< msg->net_sent <<"\tMB\n"
        <<"网络接收量\t"<< msg->net_recv <<"\tMB\n" 
        <<"=======================================";
        return QString::fromStdString(show_str.str());

    };
};

int main(int argc,char *argv[])
{

    rclcpp::init(argc,argv);
    QApplication app(argc,argv);
    auto node = std::make_shared<SysStatusDisplay>();
    std::thread spin_thread([&]()->void{
            rclcpp::spin(node);
    });
    // QLabel* label = new QLabel();
    // QString message = QString::fromStdString("Hello Qt!");
    // label->setText(message);
    // label->show();
    spin_thread.detach();
    app.exec();//执行应用
    return 0;
}