#pragma once
using namespace System;
using namespace System::Collections::Generic;

public ref class DatosJugador
{
public:
	static String^ nombrejugador = "";
	static int puntaje = 0;

	static List<String^>^ nombres = gcnew List<String^>();
	static List<int>^ puntajes = gcnew List<int>();
};
