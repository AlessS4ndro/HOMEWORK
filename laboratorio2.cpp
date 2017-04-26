#include <iostream>
#include <string>
#include <vector>
#include <map>
///COLOCO VALORES ALEATORIOS GUIADO POR UN RELOJ SUIZO////
#define ARRIBA 12
#define ABAJO 6
#define IZQUIERDA 9
#define DERECHA 3

using namespace std;
//CREAMOS UNA MATRIZ DE 17 FILAS POR 18 COLUMNAS ///////

char M[18][17]= {{'-','-','-','-','-','-','-','-','+','-','-','-','-','-','-','-','-'},
                 {'-','-','-','-','-','-','-','+','-','+','-','-','-','-','-','-','-'},
                 {'-','-','-','-','-','-','+','-','-','-','+','-','-','-','-','-','-'},
                 {'-','-','-','-','-','+','-','-','-','-','-','+','-','-','-','-','-'},
                 {'-','-','-','-','+','-','-','-','-','-','-','-','+','-','-','-','-'},
                 {'-','-','-','+','-','-','-','-','-','-','-','-','-','+','-','-','-'},
                 {'-','-','+','-','-','-','-','-','+','-','-','-','-','-','+','-','-'},
                 {'-','+','-','-','-','-','-','+','-','+','-','-','-','-','-','+','-'},
                 {'+','-','-','-','-','-','+','-','-','-','+','-','-','-','-','-','+'},
                 {'+','-','-','-','-','+','+','+','+','+','+','+','-','-','-','-','+'},
                 {'+','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','+'},
                 {'+','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','+'},
                 {'+','-','-','-','-','+','+','+','+','+','+','+','-','-','-','-','+'},
                 {'+','-','-','-','-','+','-','-','-','-','-','+','-','-','-','-','+'},
                 {'+','-','-','-','-','+','-','-','-','-','-','+','-','-','-','-','+'},
                 {'+','-','-','-','-','+','-','-','-','-','-','+','-','-','-','-','+'},
                 {'+','-','-','-','-','+','-','-','-','-','-','+','-','-','-','-','+'},
                 {'+','-','-','-','-','+','+','+','+','+','+','+','-','-','-','-','+'}};
class Punto
{
public:
  int x,y;
  Punto(int abcisa,int ordenada):x(abcisa),y(ordenada){}
  Punto(){}
  void set_x(int valor){x=valor;}
  void set_y(int valor){y=valor;}
};
class Bacteria
{
  private:
    Punto *P1;
    char identificador,contraidentificador;
    int direccion;

  public:
    Bacteria(int abcisa,int ordenada,char simbolo):identificador(simbolo),direccion(ABAJO),P1(new Punto(abcisa,ordenada))
    {
      cout<<"llamando al constructor de la bacteria........\n";
      if(simbolo=='-')  contraidentificador='+';else contraidentificador='-';
    }
    void reproducir()
    {
      vector<Punto*> plaga;

      plaga.push_back(P1);


      for(int i=0;i<200;i++){
        int xs,ys;

        xs=plaga[plaga.size()-1]->x;
        ys=plaga[plaga.size()-1]->y;
        cout<<"comparando las 4 cordenas puntos de reproduccion...........\n";
        if((xs-1>=0 && xs+1<=17) && (ys-1>=0 && ys+1<=16))
          if(M[xs][ys-1]==identificador){plaga.push_back(new Punto(xs,ys-1));}
          if(M[xs][ys+1]==identificador){plaga.push_back(new Punto(xs,ys+1));}
          if(M[xs-1][ys]==identificador){plaga.push_back(new Punto(xs-1,ys));}
          if(M[xs+1][ys]==identificador){plaga.push_back(new Punto(xs+1,ys));}
        M[xs][ys]=contraidentificador;
        delete plaga[plaga.size()-1];
        plaga[plaga.size()-1]=NULL;
        plaga.pop_back();
      }

    }
};

void grafica()
{


cout<<"iniciando la grafica....\n";

  cout<<"dibujando.......\n\n\n";
  for(int i=0;i<18;i++){
    cout<<"\t";
    for(int j=0;j<17;j++){
      cout<<M[i][j];
    }
    cout<<"\n";
  }
}

void fill_region(int ,int,char);
void histograma();
void pintar_asterisco (int);

int main()
{
  int x,y;
  char val;
/*
  cout<<"indique area donde pintar, x e y respectivamente\n";
  cin>>x>>y;
  val=M[x][y];
  cout<<"se eligio las cordenadas "<<x<<y<<M[x][y]<<" para el ataque\n";
  fill_region(x,y,val);
*/
  histograma();
  return 0;
}
void fill_region(int row ,int col,char simbol)
{
  cout<<"ejecutando fill_regin.........\n";
  grafica();
  cout<<"cultivando bacteria...........\n";
  Bacteria B1(row,col,simbol);
  cout<<"multiplicando bacteria........\n";
  B1.reproducir();
  cout<<"aplicando los cambios\n";
  grafica();
}
void histograma()
{
  map <int,int> numeros;
  map <int,int>:: iterator it;
  vector<int> arreglo;
  vector<int> elementosSinRepeticion;
  int k=0,contador=0,j,valor;
  bool llave=true;

////////INGRESAMOS ELEMENTOS A NUESTRO ARREGLO////////
  cout<<"ingresa tus elementos "<<endl;
  do{
    cin>>valor;
    arreglo.push_back(valor);
  }while(arreglo[k++]!=00);
    ;
  k=0;
  elementosSinRepeticion[k]=arreglo[k];
  //////COMPARAMOS AMBOS VECTORES PARA GENERAR UN VECTOR CON ELEMENTOS SIN REPETICION/////////
  for(int i=0;i<arreglo.size();i++){
      for(j=0;j<elementosSinRepeticion.size();j++){
        if(arreglo[i]==elementosSinRepeticion[j]){
          llave=false;
        }
      }
      if(llave){
        elementosSinRepeticion[j]=arreglo[i];
      }
  }

  ///////////AHORA CONTAMOS CUANTAS VECES SE REPITEN LOS ELEMENTOS////////////
  for(int i=0;i<elementosSinRepeticion.size();i++){
    for(j=0;j<arreglo.size();j++){
      if(elementosSinRepeticion[i]==arreglo[j])
        contador++;
    }


    numeros[elementosSinRepeticion[i]]=contador;
    numeros[elementosSinRepeticion[i]]=contador;

    cout<<"\t\t"<<elementosSinRepeticion[i];
    pintar_asterisco(contador);
    contador=0;

  }



}
void pintar_asterisco(int val)
{
  for(int i=0;i<val;i++)
    cout<<"* ";
}
