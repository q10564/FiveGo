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
		dir.mkpath(str); //ֻ����һ����Ŀ¼�������뱣֤�ϼ�Ŀ¼����
	}
	fiveGo w;
	w.show();
	return a.exec();
}
