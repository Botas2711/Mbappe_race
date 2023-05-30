#pragma once
#include <iostream>
using namespace System::Drawing;
enum Direccion { Listo, Correr, Celebrar };
class Mbappe
{
private:
	int x, y;
	int dx;
	int alto, ancho;
	int fila, columna;
	bool win;
public:
	Direccion direccion;
	Mbappe(Bitmap^ img, int y) {
		this->y = y;
		dx = 0;
		alto = img->Height / 6;
		ancho = img->Width / 7;
		x = 1250 - ancho;
		fila = columna = 0;
		direccion = Listo;
		win = true;
	}
	~Mbappe() {}
	void mostrar(Graphics^ g, Bitmap^ img) {
		Rectangle molde = Rectangle(columna * ancho, fila * alto, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho, alto);
		g->DrawImage(img, zoom, molde, GraphicsUnit::Pixel);
	}
	void mover(Graphics^ g) {
		switch (this->direccion)
		{
		case Direccion::Listo:
			columna = 0;
			fila = 0;
			break;
		case Direccion::Correr:
			dx = 8 + rand() % (20 + 1 - 8);
			fila = 0;
			if (columna < 7) {
				columna++;
			}
			if (columna >=7) {
				columna = 0;
			}
			break;
		case Direccion::Celebrar:
			dx = 9;
			if (fila != 5) {
				if (columna < 6) {
					columna++;
				}
				else {
					fila++;
					columna = 0;
				}
			}
			if (fila == 5) {
				if (columna < 3) {
					columna++;
				}
				if (columna == 3) {
					fila = 5;
					columna = 3;
				}
			}
			break;
		}
		if (x - dx > 0) {
			x -= dx;
		}
	}
	void setWin() { win = false; }
	bool getWin() { return win; }
	int getX() { return x; }
	void setDx() { dx = 0; }
	int getAncho() { return ancho; }
	void setFila(int n) { fila = n; }
	void setColumna(int n) { columna = n; }
};