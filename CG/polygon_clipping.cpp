#include <iostream>
#include <stdio.h>
#include <graphics.h>

struct Vertice {
	int x, y;
	Vertice(int x, int y){
		this->x = x;
		this->y = y;
	}
};

struct Edge {
	Vertice* v1;
	Vertice* v2;
	Edge(Vertice* v1, Vertice* v2){
		this->v1 = v1;
		this->v2 = v2;
	}
};

struct Polygon {
	int vCount;
	Vertice ** vertices;
	Polygon(int vCount){
		this->vCount = vCount;
		vertices = new Vertice*[vCount];
	}
	void setiVertice(int i, Vertice * vertice){
		vertices[i] = vertice;
	}
	Vertice * getiVertice(int i){
		return vertices[i];
	}
	int getvCount(){
		return vCount;
	}
};

Vertice* inputVertice(){
	int x, y;
	std::cout << "X: ";
	std::cin >> x;
	std::cout << "Y: ";
	std::cin >> y;
	return new Vertice(x, y);
}

Vertice inputVMin(){
	std::cout << "Enter top left vertice of clipping window" << std::endl;
	return *inputVertice();
}

Vertice inputVMax(){
	std::cout << "Enter bottom right vertice of clipping window" << std::endl;
	return *inputVertice();
}

Polygon inputPolygon(){
	std::cout << "Enter number of vertices in polygon: ";
	int vCount;
	std::cin >> vCount;
	Polygon polygon(vCount);
	for (int i = 0; i < vCount; i++){
		std::cout << "Enter vertice " << i + 1 << std::endl;
		polygon.setiVertice(i, inputVertice());
	}
	return polygon;
}

void SutherlandHodgmanPolygonClipping(Polygon &polygon, Edge &clipEdge){
	int vCount = polygon.getvCount();
	Vertice* p = polygon.getiVertice(vCount - 1), *q;
	for (int i = 0; i < vCount; i++){
		q = polygon.getiVertice(i);
		if (inside(p, clipEdge)){
			if (inside(q, clipEdge)){

			} else {

			}
		} else {
			if (inside(q, clipEdge)){

			}
		}
		p = q;
	}
}

void doCLipping(Vertice &vmin, Vertice &vmax, Polygon &polygon){
	Edge clipEdge1(new Vertice(vmax.x, vmin.y), new Vertice(vmax.x, vmax.y));
	SutherlandHodgmanPolygonClipping(polygon, clipEdge1);
}

void draw(Vertice &vmin, Vertice &vmax, Polygon &polygon){
	rectangle(vmin.x, vmin.y, vmax.x, vmax.y);
	int vCount = polygon.getvCount();
	for (int i = 0; i < vCount - 1; i++){
		line(polygon.getiVertice(i)->x,
			polygon.getiVertice(i)->y,
			polygon.getiVertice(i+1)->x,
			polygon.getiVertice(i+1)->y);
	}
	line(polygon.getiVertice(vCount - 1)->x,
		polygon.getiVertice(vCount - 1)->y,
		polygon.getiVertice(0)->x,
		polygon.getiVertice(0)->y);
}

int main(){
	Vertice vmin = inputVMin();
	Vertice vmax = inputVMax();
	Polygon polygon = inputPolygon();

	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);

	draw(vmin, vmax, polygon);
	getch();
	doCLipping(vmin, vmax, polygon);

	closegraph();

	return 0;
}
