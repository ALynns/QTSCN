#ifndef MGRAPH_H
#define MGRAPH_H

#include<iostream>
#include<cstring>
#include<string.h>
#include <iomanip>
#include <QString>

#define TRUE		1
#define FALSE		0
#define OK		1
#define ERROR		0
#define INFEASIBLE	-1
#define Overflow	-2

typedef int Status;
typedef int VRType;
typedef QString ElemType;

typedef enum { DG, DN, UDG, UDN }GraphKind;

struct ArcCell
{
    VRType adj;
    int vex0, vex1;
    ElemType info;
    ArcCell *next;
    bool flag;
};

struct Vertex
{
    ElemType info;
    bool flag;
    ArcCell *arc;
	int arcNum;
    int i;
};

class MGraph
{
private:
    GraphKind kind;
    Vertex *vex;
    int vexnum, arcnum;
    ArcCell **arc;
public:
    MGraph(GraphKind kind, int vnum);
    ~MGraph();
    Status CreateGraph(ElemType e0, ElemType e1, int adj);
    int LocateVex(ElemType e);
    Status GetVex(int v, ElemType &e);
    Status PutVex(int v, ElemType e);
    Status InsertVex(int v, ElemType e);
	Status CreateArc(ElemType e0, ElemType e1, int adj);
    Status initial();
    Status PutFlagArc(ElemType e0, ElemType e1, int flag);
	friend class SCNMainWindow;
	friend class SCNDisplayWindow;
};

#endif // MGRAPH_H
