#include<iostream>

using namespace std;

long potencia(int numero,int exponente)
{
	long valor=1;
	if(exponente==0)
		return valor;
	for(int i=0;i<exponente;i++){
		valor*=numero;	
	}
	return valor;
}
long convertir_a_base_10(long,int);
long convertir_de_base_10(long,int);
long conversion_de_bases(long,int,int);
int main()
{
	long numero;
	int base1,base2;
	
	cout<<"ingrese el numero y la base correspondiente\n";
	cin>>numero;
	cin>>base1;
	cout<<"ingrese la base a la que desea convertir\n";cin>>base2;
	
	cout<<"el nuevo numero es....\n";
	cout<<conversion_de_bases(numero,base1,base2)<<endl;
	//cout<<potencia(numero,base)<<endl;

	return 0;
}

long convertir_a_base_10(long numero,int base)
{
	int exponente=0;
	int residuo;
	long numeroDecimal=0;

	while(numero!=0){
		int numeroResultante=base;

		numeroDecimal=(numeroDecimal+((numero%10)*potencia(base,exponente)));
		numero=numero/10;
		exponente++;
	}
	return numeroDecimal;
}
long convertir_de_base_10(long numeroDecimal,int base)
{
	long multiplicador1=1,multiplicador2=1;
	int copia=numeroDecimal;
	long valor=0;
	long resultado=0;
	
	while(copia/base!=0){
		multiplicador2=(multiplicador1*=10);
		copia/=base;
	}
	do{
		valor+=((numeroDecimal%base)*multiplicador1);
		numeroDecimal/=base;
		multiplicador1/=10;
	}while(numeroDecimal!=0);
	while(valor!=0){
		resultado+=((valor%10)*multiplicador2);
		valor/=10;
		multiplicador2/=10;
	}

	return resultado;	
}
long conversion_de_bases(long numero,int baseActual,int baseDeseada)
{
	long resultado=numero;

	if(baseActual!=10){
		resultado=convertir_a_base_10(numero,baseActual);	
	}
	return convertir_de_base_10(resultado,baseDeseada);	
}
