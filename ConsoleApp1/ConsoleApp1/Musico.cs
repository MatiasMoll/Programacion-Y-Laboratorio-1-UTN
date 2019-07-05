using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp1
{
    class Musico
    {
        public string nombre;
        public string apellido;
        public int edad;
        public Orquesta nombreOrquesta;
        public Instrumento nombreInstrumento;
   
        public Musico (string nombre,string apellido, int edad, Orquesta nombreOrquesta, Instrumento instrumento)
        {
            this.nombre = nombre;
            this.apellido = apellido;
            this.edad = edad;
            this.nombreOrquesta = nombreOrquesta;
            this.nombreInstrumento = instrumento;
        }
              
        public void printMusico()
        {
            Console.WriteLine("Nombre del Musico: " + this.nombre + "\nApellido del Musico: " + this.apellido +"\nEdad del musico: "+this.edad+"\nNombre de la Orquesta: "+this.nombreOrquesta.nombre+"\nInstrumento que toca: "+this.nombreInstrumento.nombre+"\n");
        }
    }
}
