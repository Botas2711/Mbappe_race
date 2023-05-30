#pragma once
#include "Mbappe.h"
#include <vector>
using namespace std;
using namespace System::Windows::Forms;
ref class Game
{
private:
	Mbappe* mbappe;
	Bitmap^ img;
public:
	Game() {
		img = gcnew Bitmap("image/mbappe.png");
		mbappe = new Mbappe(img, 0);
	}
	~Game() {}
	void mostrar(Graphics^ g) {
		mbappe->mostrar(g, img);
	}
	void mover(Graphics^ g) {
		mbappe->mover(g);
	}
	void validacion(Graphics^ g) {
		if (mbappe->getX() < 300) {
			mbappe->direccion = Celebrar;
		}
	}
	Mbappe* getMbappe() {
		return mbappe;
	}
	void iniciar() {
		mbappe->direccion = Correr;
	}
};