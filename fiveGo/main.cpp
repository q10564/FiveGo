#include "fiveGo.h"
#include <QtWidgets/QApplication>
#include <QDir>
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	auto str = QCoreApplication::applicationDirPath() + "/history/";
	QDir dir(str);
	if (!dir.exists())
	{
		dir.mkpath(str); //只创建一级子目录，即必须保证上级目录存在
	}
	fiveGo w;
	w.show();
	return a.exec();
}
