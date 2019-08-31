#include "mgraph.h"

MGraph::MGraph(GraphKind k, int vnum)//ͼ�ĳ�ʼ��
{
    int i, j;
    kind = k;
    vexnum = vnum;
    vex = new Vertex[vexnum];
    for (i = 0; i < vexnum; i++)
    {
        vex[i].arc = nullptr;
        vex[i].flag = 1;
		vex[i].arcNum = 0;
    }
    arc = new ArcCell*[vexnum];
    for (i = 0; i < vexnum; i++)
    {
        arc[i] = new ArcCell[vexnum];
        for (j = 0; j < vexnum; j++)
        {
            arc[i][j].adj = 0;
            arc[i][j].flag = 1;
            arc[i][j].info = nullptr;
            arc[i][j].next = nullptr;
        }
    }
}

MGraph::~MGraph()
{
    int i;
    for (i = 0; i < vexnum; i++)
        delete[]arc[i];
    delete[]arc;
    delete[]vex;
}

Status MGraph::CreateGraph(ElemType e0, ElemType e1, int adj = 1)//ͼ����
{
    switch (kind)
    {
        case DG://����ͼ
        {
            CreateArc(e0, e1, 1);
            break;
        }
        case DN://������
        {
            CreateArc(e0, e1, adj);
            break;
        }
        case UDG://����ͼ
        {
            CreateArc(e0, e1, 1);
            CreateArc(e1, e0, 1);
            break;
        }
        case UDN://������
        {
            CreateArc(e0, e1, adj);
            CreateArc(e1, e0, adj);
            break;
        }
    }


    return OK;
}

int MGraph::LocateVex(ElemType e)//ȷ������λ��
{
    int i;
    for (i = 0; i < vexnum; i++)
        if (vex[i].info == e)
            return i + 1;
    return -1;
}

Status MGraph::GetVex(int v, ElemType &e)//��ö���ֵ
{
    if (v >= vexnum)
        return ERROR;
    else
    {
        e = vex[v - 1].info;
        return OK;
    }
}

Status MGraph::PutVex(int v, ElemType e)//�Զ��㸳ֵ
{
    if (v > vexnum)
        return ERROR;
    vex[v - 1].info = e;
	vex->arcNum = 0;
    return OK;
}

Status MGraph::InsertVex(int v, ElemType e)//���붥��
{
    if (v <= vexnum)
        vex[v - 1].info = e;
    else
        return ERROR;
    return OK;
}

Status MGraph::CreateArc(ElemType e0, ElemType e1, int adj)//�����ڽӱ����ڽӾ���
{
    int v0, v1;
    ArcCell *p;
    v0 = LocateVex(e0);
    v1 = LocateVex(e1);
    if (v0 != -1 && v1 != -1)
    {
        p = new ArcCell;
        p->vex0 = v0;
        p->vex1 = v1;
        p->adj = adj;
        p->flag = 1;
        p->next = vex[v0 - 1].arc;
        vex[v0 - 1].arc = p;
		vex[v0 - 1].arcNum++;
        arc[v0 - 1][v1 - 1].adj = adj;
        return OK;
    }
    else
        return ERROR;
}


Status MGraph::initial()
{
    int i;
    for (i = 0; i < vexnum; i++)
        vex[i].flag = 1;
    return OK;
}



Status MGraph::PutFlagArc(ElemType e0, ElemType e1, int flag)
{
    ArcCell *p;
    p = vex[LocateVex(e0)-1].arc;
    while (p)
    {
        if (p->vex1 == e1)
        {
            p->flag = flag;
            break;
        }
        else
            p = p->next;
    }
    p = vex[LocateVex(e1)-1].arc;
    while (p)
    {
        if (p->vex1 == e0)
        {
            p->flag = flag;
            break;
        }
        else
            p = p->next;
    }
    return 0;
}
