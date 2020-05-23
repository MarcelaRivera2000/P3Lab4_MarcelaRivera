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
		int lla=1+rand()%(15-1);
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
	cout<<"c "<<m<<endl;
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
string descifrado(string cifrado,int llave);
string cifrado(string mensaje,int llave);
int posi_usuario;

int main(){
		cout<<"ADVERTENCIA: no se porque pero si la llave es mas de 10 explota xd"<<endl<<"-----------Fin del comunicado--------"<<endl;
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
			    	string cifradoo;
					cifradoo=cifrado(mensaje,lista[posi].llave());
			    	lista[posi].setVector(cifradoo);
			    	cout<<"dsa: "<<cifradoo<<endl;
			    	cout<<"enviado..."<<endl;
					break;
				}
				case 2:{
					int posii,posi2;
					cout<<"MENSAJES"<<endl;
					for(int i=0;i<lista.size();i++){
						cout<<i<<"."<<lista[i].nombree()<<endl;
			    	}
			    	cout<<"->Seleccione el usuario:";
					cin>>posii;
					for(int j=0; j<lista[posi].getVector().size();j++){
			   			cout<<j<<".mensaje: "<<lista[posii].getVector()[j]<<endl;
					}
					cout<<"->Seleccione el mensaje:";
					cin>>posi2;
					cout<<"Mensaje: "<<descifrado(lista[posii].getVector()[posi2],lista[posi_usuario].llave())<<endl;
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
	if(llave==0){
		return mensaje; 	
	}else{
		bool aux=true;
		char c;
		int valor;
		string aux2="";
		for(int i=0;i<mensaje.size();i++){
			if(i%llave==0){	
				if(aux==true){
					aux=false;		
				}else{
					aux=true;
				}
			}
			c=mensaje[i];
			valor=c;
			if(aux==true){
				valor=valor-llave;
				c=(char)valor;
				aux2+=c;	
			}else{
				valor=valor+llave;
				c=(char)valor;
				aux2+=c;
			}
		}	
		cout<<aux2<<"   "<<llave<<endl;	
		mensaje=aux2;
		cout<<llave<<".cifrado: "<<mensaje<<endl;
		cifrado(aux2,llave-1);
	}
}

string descifrado(string cifrado,int llave){
	if(llave==0){
		return cifrado;	
	}else{
		bool aux=true;
		char c;
		int valor;
		string aux2="";
		for(int i=0;i<cifrado.size();i++){
			if(i%llave==0){	
				if(aux==true){
					aux=false;		
				}else{
					aux=true;
				}
			}
			c=cifrado[i];
			valor=c;
			if(aux==true){
				valor=valor+llave;
				c=(char)valor;
				aux2+=c;
			}else{
				valor=valor-llave;
				c=(char)valor;
				aux2+=c;	
			}
		}	
		cifrado=aux2;
		cout<<llave<<".desifrado: "<<cifrado<<endl;
		descifrado(cifrado,llave-1);	
	}
	
	
	
}





























