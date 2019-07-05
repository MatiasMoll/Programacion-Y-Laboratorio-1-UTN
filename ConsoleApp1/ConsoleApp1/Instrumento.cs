using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp1
{
    class Instrumento
    {
        public string nombre;
        public string tipoInstrumento;

        public void printInstrumento()
        {
            Console.Write("Nombre del Instrumento: " + this.nombre +"\nTipo: " + this.tipoInstrumento + "\n");
        }
        public Instrumento(string nombre, string tipo)
        {
            this.nombre = nombre;
            this.tipoInstrumento = tipo;
        }
    }


}
