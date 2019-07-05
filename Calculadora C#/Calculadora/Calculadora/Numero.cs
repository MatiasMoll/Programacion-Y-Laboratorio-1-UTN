using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Calculadora
{
    class Numero
    {
        private double numero;

        public void SetNumero(double numero)
        {
            this.numero = numero;
        }
        public double GetNumero()
        {
            return this.numero;
        }
        private static double IsValidNumber(string numero)
        {
            double retorno;
            if(!double.TryParse(numero,out retorno))
            {
                retorno = 0;
            }
            return retorno;
        }
        public Numero(double numero)
        {
            this.numero = numero;
        }
        public Numero (string numero)
        {
            this.numero = IsValidNumber(numero);
        }
        public static double SumarNumeros(Numero numeroUno, Numero numeroDos)
        {
            double retorno;
            retorno = numeroUno.GetNumero() + numeroDos.GetNumero();
            return retorno;
        }
        public static double RestarNumeros(Numero numeroUno, Numero numeroDos)
        {
            double retorno;
            retorno = numeroUno.GetNumero() - numeroDos.GetNumero();
            return retorno;
        }
        public static double MultiplicarNumeros(Numero numeroUno, Numero numeroDos)
        {
            double retorno;
            retorno = numeroUno.GetNumero() * numeroDos.GetNumero();
            return retorno;
        }
        public static double DividirNumeros(Numero numeroUno, Numero numeroDos)
        {
            double retorno;
            if (numeroDos.GetNumero() != 0)
            {
                retorno = numeroUno.GetNumero() / numeroDos.GetNumero();
            }
            else
            {
                retorno = 0;
            }                
            return retorno;
        }
    }
}
