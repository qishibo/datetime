#include <gtk/gtk.h>

// 键盘按下事件处理函数
gboolean deal_key_press(GtkWidget *widget, GdkEventKey  *event, gpointer data)
{
    // 不检测 任意键退出
    gtk_main_quit();

    // esc 退出
    if (event->keyval == GDK_KEY_Escape)
    {
        gtk_main_quit();
    }

    return TRUE;
}

int main(int argc,char *argv[])
{
    // 当前时间
    time_t t;
    char nowTime[19];
    struct tm * lt;
    time (&t);//获取Unix时间戳。
    lt = localtime (&t);//转为时间结构。

    // 星期几
    char* xingqi;
    switch (lt->tm_wday)
    {
        case 0:
            xingqi="星期一";
            break;
        case 1:
            xingqi="星期二";
            break;
        case 2:
            xingqi="星期三";
            break;
        case 3:
            xingqi="星期四";
            break;
        case 4:
            xingqi="星期五";
            break;
        case 5:
            xingqi="星期六";
            break;
        case 6:
            xingqi="星期日";
            break;
    }

    sprintf (nowTime, "%d-%d-%d %s %d:%d:%d\n",lt->tm_year+1900, lt->tm_mon+1, lt->tm_mday, xingqi, lt->tm_hour, lt->tm_min, lt->tm_sec);//输出结果


    GtkWidget *window;
    GtkWidget *label;
    char title[]="当前时间";
    gtk_init(&argc, &argv);
    window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), title);
    // 窗口尺寸
    gtk_window_set_default_size(GTK_WINDOW (window),600,300);
    gtk_window_set_position (GTK_WINDOW (window), GTK_WIN_POS_CENTER);//设置窗口位置
    // gtk_widget_realize (window);//实现上述窗口
    g_signal_connect (window, "destroy", gtk_main_quit, NULL);//窗口信号连接，点击关闭按钮是会关闭窗口。

    label=gtk_label_new(nowTime);

    // 设置label字体样式
    char labelText[100];
    sprintf(labelText, "<span foreground='#6784b2' font_desc='28' underline='none' underline_color='lightgrey'>%s</span>",nowTime);
    gtk_label_set_markup(
        GTK_LABEL(label),
        labelText
    );

    gtk_container_add(GTK_CONTAINER(window), label);
    gtk_widget_show(window);
    gtk_widget_show(label);

    // 处理热键
    g_signal_connect(window, "key-press-event", G_CALLBACK(deal_key_press), NULL);

    gtk_main();
    return 0;
}


