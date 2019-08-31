#include"scndisplay.h"
#include <QPainter>
#include<stack>
#include<cstdio>
#include<QStack>
#include<QStack>
#include<QPoint>
#include <vector>

Paint::Paint(QWidget *parent) : QWidget(parent)
{
	resize(600, 400);
}

void Paint::setPerson(Vertex *p, Vertex *pL)
{
	person = p;
	personList = pL;
	return;
}


void Paint::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	Vertex *p = person;
	Vertex *pL = personList;
	ArcCell *a = p->arc;

	// 反锯齿
	painter.setRenderHint(QPainter::Antialiasing);
	painter.setRenderHint(QPainter::TextAntialiasing);


	//设置字体
	QFont font;
	font.setPointSize(12);
	font.setBold(true);
	painter.setFont(font);

	//设置画笔
	QPen penLine;
	penLine.setWidth(2); //线宽
	penLine.setColor(Qt::blue); //划线颜色
	penLine.setStyle(Qt::SolidLine);//线的类型，实线、虚线等
	penLine.setCapStyle(Qt::FlatCap);//线端点样式
	penLine.setJoinStyle(Qt::BevelJoin);//线的连接点样式
	painter.setPen(penLine);

	qreal W = this->width();                            // 画布的宽600
    //qreal H = this->height();                           // 画布的高400
    //int treeHeight = 2;               // 树的高度
	qreal R = 25;    // 节点的半径
	

	const int layerHeight = 200;     // 层高，即垂直偏移量

	// 初始化
	// 节点的定义
	QRectF node(QPointF(-R, -R), QPointF(R, R));

    //QPointF point;

	const qreal Hoffset = 275;                  // 水平偏移量
	const qreal Pi = 3.14159;
    //int curLayer = 1;
	int curAngle;                   // 当前角度
	int preCurAngle;
	qreal deg;                      // 当前弧度
	qreal preDeg;
	// 将坐标系统的原点（下文简称原点）移动到初始位置
	painter.translate(W / 2, 2 * R);

	//打印根节点
	painter.drawEllipse(node);
	painter.drawText(node, Qt::AlignCenter, QString(p->info));

	deg = std::atan(Hoffset / layerHeight);
	preDeg = 2 * deg / (p->arcNum - 1);
	curAngle = int(180 / Pi * deg);
	preCurAngle = 2 * curAngle / (p->arcNum - 1);

	

	for (int i = 0; i < p->arcNum; i++)
	{
		painter.rotate(curAngle);
		painter.drawLine(0, int(R), 0, int(layerHeight / std::cos(deg) - R));
		painter.rotate(-curAngle);
		curAngle = curAngle - preCurAngle;
		deg = deg - preDeg;
	}

	deg = std::atan(Hoffset / layerHeight);
	preDeg = 2 * deg / (p->arcNum - 1);
	curAngle = int(180 / Pi * deg);
	preCurAngle = 2 * curAngle / (p->arcNum - 1);
	painter.translate(QPointF(QPointF(0, 0) + QPointF(-Hoffset - Hoffset * 2 / (p->arcNum - 1), layerHeight)));
	for (int i = 0; i < p->arcNum; i++)
	{
		painter.translate(QPointF(QPointF(0, 0) + QPointF(Hoffset * 2 / (p->arcNum - 1), 0)));
		painter.drawEllipse(node);
		painter.drawText(node, Qt::AlignCenter, QString(pL[a->vex1 - 1].info));
		a = a->next;
	}
	
	/*while (1)
	{
		painter.drawEllipse(node);
		painter.drawText(node, Qt::AlignCenter, QString(pList[a->vex1].info));

		// 设置孩子节点相对于父节点的水平偏移量
		Hoffset = std::pow(2, (treeHeight - curLayer)) * R;
		deg = std::atan(Hoffset / layerHeight);             // 返回的是弧度
		curAngle = int(180 / Pi * deg);                          // 将弧度转化为角度

		if (bt->rchild != nullptr)
		{
			// 坐标轴逆时针旋转
			painter.rotate(-curAngle);

			//绘制图形路径
			painter.drawLine(0, int(R), 0, int(layerHeight / std::cos(deg) - R));

			// 旋转复原
			painter.rotate(curAngle);

			// 右孩子节点压栈
			qNode.treeNode = bt->rchild;
			qNode.layer = curLayer + 1;
			stack.push(qNode);

			// 右孩子相对于当前坐标系统原点的位置压栈
			points.push(QPointF(QPointF(0, 0) + QPointF(Hoffset, layerHeight)));
			painter.save();
		}
		if (bt->lchild != nullptr)
		{
			// 坐标轴顺时针旋转
			painter.rotate(curAngle);
			// 绘制边
			painter.drawLine(0, int(R), 0, int(layerHeight / std::cos(deg) - R));
			// 旋转复原
			painter.rotate(-curAngle);
			// 原点移动到左孩子节点的位置
			painter.translate(QPointF(QPointF(0, 0) + QPointF(-Hoffset, layerHeight)));
			bt = bt->lchild;
			// 层次加1
			curLayer++;
		}
		else {
			if (stack.empty())
			{
				painter.resetTransform();
				return;
			}
			qNode = stack.top();
			stack.pop();
			bt = qNode.treeNode;
			curLayer = qNode.layer;

			painter.restore();
			point = points.top();
			points.pop();
			painter.translate(point);
		}*/

	}
