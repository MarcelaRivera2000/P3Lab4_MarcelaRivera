#include<iostream>
#include<stdlib.h>
#include<time.h>
#include <string> 
#include <vector>

using namespace std; 
using std::cin;
using std::endl;
using std::cout;


class persona{
	private:
		string nombre,apellido,contra;
		vector<string> mensajes;
		string m;
		int lla=0+rand()%(15-0);
	public: 
		persona(string nombre,string apellido,string contra);
		string nombree();
		string apellidoo();
		string contraa();
		vector<string> getVector();
		void setVector(string m);
		string mensajee();
		int llave();
};
persona::persona(string _nombre,string _apellido,string _contra){
	nombre=_nombre;
	apellido=_apellido;
	contra=_contra;
}
string persona::nombree(){
	return nombre;
}
string persona::apellidoo(){
	return apellido;
} 
string persona::contraa(){
	return contra;
} 
vector<string> persona::getVector(){
	return mensajes;
}
void persona::setVector(string m){
	mensajes.push_back(m);	
}
string persona::mensajee(){
	return m;
}
int persona::llave(){
	return lla;
}


vector <persona> lista;
void registrarse();
void ingresar();
string descifrado(string cifrado);
string cifrado(string mensaje,int llave);
int posi_usuario;

int main(){
		while(true){
		int op;
		srand(time(NULL));
		cout<<"***CLI-MESSENGER-SERVICE***"<<endl<<"1#Registrarse"<<endl<<"2#Ingresar"<<endl<<"3#Salir"<<endl;
		cin>>op;
		switch(op){
			case 1:
			    registrarse();
				break;
			case 2:
				ingresar();
			break;
			case 3:
				exit (EXIT_FAILURE);
			break;		
		}
	}
	return 0; 
}
 
void registrarse(){
	string nombre,apellido,contra;
				cout<<"***REGISTRO***"<<endl<<"->Ingrese su nombre: ";
				cin>>nombre;
				cout<<"->Ingrese su apellido: ";
				cin>>apellido;
				cout<<"->Ingrese su contrasena: ";
				cin>>contra;
				persona pe= persona(nombre,apellido,contra);
				lista.push_back(pe);
				cout<<"USUARIO:"<<endl<<"Nombre: "<<pe.nombree()<<endl<<"Apellido: "<<pe.apellidoo()<<endl<<"Contrasena: "<<pe.contraa()<<endl;
}

void ingresar(){
	string n,c;
	bool entro=false;
	int posi;
	cout<<"****LOG IN****"<<endl<<"Ingrese su nombre: ";
	cin>>n;
	cout<<"Ingrese la contrasena: ";
	cin>>c;
	for(int i=0;i<lista.size();i++){
		if(lista[i].nombree()==n&&lista[i].contraa()==c){
			entro=true;	
			posi_usuario=i;		
	 }	
	}
	if(entro){
		while(true){
			int op;
			cout<<"BIENVENIDO"<<endl<<"1#Enviar Mensaje"<<endl<<"2#Ver mensaje"<<endl<<"3#Ver mi llave"<<endl<<"4#Salir"<<endl;
			cin>>op;
			switch(op){
				case 1:{
					int posi;
					string mensaje;
					cout<<"USUARIOS"<<endl;
			    	for(int i=0;i<lista.size();i++){
			   			cout<<i<<"."<<lista[i].nombree()<<endl;
			    	}
			    	cout<<"->Seleccione el destinatario: ";
			    	cin>>posi;
			    	cout<<"->NOTA: No ingrese espacios, en lugar de ello, coloque un '_'"<<endl<<endl<<"->Ingrese el mensaje: ";
			    	cin>>mensaje;
			    	string cifradoo=cifrado(mensaje,lista[posi].llave());
			    	lista[posi].setVector(cifradoo);
			    	cout<<"enviado..."<<endl;
					break;
				}
				case 2:{
					int posi,posi2;
					cout<<"MENSAJES"<<endl;
					for(int i=0;i<lista.size();i++){
						cout<<i<<"."<<lista[i].nombree()<<endl;
			    	}
			    	cout<<"->Seleccione el usuario:";
					cin>>posi;
					for(int j=0; j<lista[posi].getVector().size();j++){
			   			cout<<j<<".mensaje: "<<lista[posi].getVector()[j]<<endl;
					}
					cout<<"->Seleccione el mensaje:";
					cin>>posi2;
					cout<<"Mensaje: "<<descifrado(lista[posi].getVector()[posi2])<<endl;
					break;
				}	
				case 3:{
				cout<<"Su llave es: "<<lista[posi_usuario].llave()<<endl;
					break;
				}
				case 4:{
					main();
					break;
				}
					
					
		}
	  }	
	}else{
		cout<<"Usuario o contrasena invalido"<<endl;
		
	}	
}


string cifrado(string mensaje,int llave){
	string cifrado;
	
	
	
	
	
	
	
	
	
	
	return cifrado; 
}
string descifrado(string cifrado){
	string mensaje;
	
	return mensaje;
	
}





























