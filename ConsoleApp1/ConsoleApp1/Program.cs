using System;
using System.Collections;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            Orquesta orquestaUno = new Orquesta("La sinfonica","Varela","Sinfonica");
            Orquesta orquestaDos = new Orquesta("Tocasasa", "Quilmes", "Camara");
            Orquesta orquestaTres = new Orquesta("Beethoven", "Solano", "Filarmonica");
            //orquestaUno.printOrquesta();
            Instrumento instrumentoUno = new Instrumento("Guitarra", "Cuerdas");
            //instrumentoUno.printInstrumento();

            Musico primerMusico = new Musico("Matias", "Moll", 22, orquestaUno, instrumentoUno);
            primerMusico.printMusico();

            ArrayList listaOrquesta = new ArrayList();
            /*listaOrquesta.Add(orquestaUno);
            listaOrquesta.Add(orquestaDos);
            listaOrquesta.Add(orquestaTres);
            foreach(Orquesta elemento in listaOrquesta)
            {
                elemento.printOrquesta();
            }*/
            Console.ReadKey();
            
        }
    }
}
