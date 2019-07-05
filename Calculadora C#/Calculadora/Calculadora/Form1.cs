using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Calculadora
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string numeroUno = this.textBox1.Text;
            string numeroDos = this.textBox2.Text;
            Numero primerNumero = new Numero(numeroUno);
            Numero segundoNumero = new Numero(numeroDos);
            double resultado = Numero.SumarNumeros(primerNumero, segundoNumero);
            this.textBox3.Text = resultado.ToString();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void button4_Click(object sender, EventArgs e)
        {
            string numeroUno = this.textBox1.Text;
            string numeroDos = this.textBox2.Text;
            Numero primerNumero = new Numero(numeroUno);
            Numero segundoNumero = new Numero(numeroDos);
            double resultado = Numero.DividirNumeros(primerNumero, segundoNumero);
            this.textBox3.Text = resultado.ToString();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            string numeroUno = this.textBox1.Text;
            string numeroDos = this.textBox2.Text;
            Numero primerNumero = new Numero(numeroUno);
            Numero segundoNumero = new Numero(numeroDos);
            double resultado = Numero.RestarNumeros(primerNumero, segundoNumero);
            this.textBox3.Text = resultado.ToString();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            string numeroUno = this.textBox1.Text;
            string numeroDos = this.textBox2.Text;
            Numero primerNumero = new Numero(numeroUno);
            Numero segundoNumero = new Numero(numeroDos);
            double resultado = Numero.MultiplicarNumeros(primerNumero, segundoNumero);
            this.textBox3.Text = resultado.ToString();
        }
    }
}
