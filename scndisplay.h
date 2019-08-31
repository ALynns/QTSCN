
#include <QWidget>
#include "mgraph.h"


class Paint : public QWidget
{
	Q_OBJECT

public:
	explicit Paint(QWidget *parent = nullptr);
	void setPerson(Vertex *p, Vertex *pList);
protected:
	void paintEvent(QPaintEvent *);
private:
	
	Vertex *person;
	Vertex *personList;
	const int rootLengt = 160;
	const double PI = 3.1415926;
};