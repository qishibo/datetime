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

    // 拼接显示字段
    const char *week[] = {"日", "一", "二", "三", "四", "五", "六"};
    sprintf (nowTime, "%d-%d-%d  星期%s %d:%d:%d\n",lt->tm_year+1900, lt->tm_mon+1, lt->tm_mday, week[lt->tm_wday], lt->tm_hour, lt->tm_min, lt->tm_sec);//输出结果

    // 初始化GUI
    GtkWidget *window;
    GtkWidget *label;

    gtk_init(&argc, &argv);

    // 主窗口
    window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "当前时间");

    // 窗口尺寸
    gtk_window_set_default_size(GTK_WINDOW (window),600,300);
    gtk_window_set_position (GTK_WINDOW (window), GTK_WIN_POS_CENTER);//设置窗口位置

    // 显示时间的label控件
    label=gtk_label_new(nowTime);

    // 设置label字体样式
    char labelText[100];
    sprintf(labelText, "<span foreground='#6784b2' font_desc='28' underline='none' underline_color='lightgrey'>%s</span>",nowTime);
    gtk_label_set_markup(GTK_LABEL(label), labelText);

    // 窗口信号连接，点击关闭按钮时会关闭窗口
    g_signal_connect (window, "destroy", gtk_main_quit, NULL);
    // 处理热键
    g_signal_connect(window, "key-press-event", G_CALLBACK(deal_key_press), NULL);

    // 主窗口添加label
    gtk_container_add(GTK_CONTAINER(window), label);
    gtk_widget_show(window);
    gtk_widget_show(label);
    gtk_main();

    return 0;
}
