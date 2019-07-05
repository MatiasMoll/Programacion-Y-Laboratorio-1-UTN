using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp1
{
    class Orquesta
    {
        public String nombre;
        public String lugar;
        public String tipoOrquesta;

        public Orquesta (string nombre, string lugar, string tipo)
        {
            this.nombre = nombre;
            this.lugar = lugar;
            this.tipoOrquesta = tipo;
        } 
       
        public void printOrquesta()
        {
            Console.Write("Nombre de la Orquesta: " + this.nombre + "\nLugar: " + this.lugar + "\nTipo: " + this.tipoOrquesta+ "\n");
        }
    }
}
