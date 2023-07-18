#include <iostream>
#include <string>
#include <sstream>
#include <fstream>  
#include <windows.h> 
using namespace std;

	struct compras{
		string proveedor;
		string libras;
		string cantidad;
		string precio;
		string fecha;
	};

	struct ventas{
		string codigo;
		string libras2;
		string precio;
		string unidades;
		string nombre;
		string tipo_cliente;
		string tipoventa;
		string fechapago;
		string puntos;
	};

    char archivo_compras[20] = "compras.txt";
	char archivo_ventas[20]  = "ventas.txt";
     
	void crear_datos(int tipo_archivo);
	void escribir_a_archivo(char *nombre_archivo, compras compras1[], ventas ventas1[], int tipo_archivo  );
	void reporte_compras();
	void reporte_ventas();
	int lectura(char *nombre_archivo, int tipo_archivo, compras compras1[], ventas ventas1[]);
    void descomponer_linea(int posicion,compras compras1[], ventas ventas1[], int tipo_archivo,string linea);
    void ventas_x_codigo();
    void ventas_con_credito();
    void ventas_con_puntos();
    void gotoxy(int x,int y);
    
    
	int main(){
		int opcion;
		int tipo_archivo;
		char *nombre_archivo;
   		Inicio:
    		system("CLS");
        	cout<<"\n\n..........CONTROL EXPENDIO DE GAS.........\n\n" << endl;
        	cout<< "   1. REGISTROS\n\n" << endl;
        	cout<< "   2. REPORTES\n\n" << endl;
        	cout<< "   3. SALIR\n\n"<< endl;
        	cout<< "\nIngrese una opcion: ";
        	cin>> opcion;
		       
    		switch (opcion){
			case 1:
				system("CLS");
				int opcion;
				inicio_subm_a:
			        system("CLS");
    	            cout<< "\n\n ..........REGISTROS.......n\n" << endl;
        	        cout<< "     1. REGISTRAR COMPRA\n\n" << endl;
                	cout<< "     2. REGISTRAR VENTA\n\n" << endl;
	                cout<< "     3. REGRESAR AL MENU PRINCIPAL\n\n"<< endl;
    	            cout<< "\nIngrese una opcion: ";
        	        cin>> opcion;
                
            	    switch (opcion){
                		case 1: 
                		    system("CLS");
                		    cin.ignore();
                		    cout<<"\n....................REGISTRAR COMPRA......................\n\n";
							crear_datos(1);
							system("PAUSE");
							goto inicio_subm_a;
							break;
         	        	case 2: 
         	        	    system("CLS");
                		    cin.ignore();
                		    cout<<"\n....................REGISTRAR VENTA......................\n\n";
							crear_datos(2);
         	        		goto inicio_subm_a;
						 	break;
         	        	case 3: 
						 	goto Inicio;
							break;
                	}
         
        	case 2:
        		system("CLS");
	            inicio_subm_b:	
    	        	system("CLS");
        	        cout<< "\n\n............. REPORTES............" << endl;
            	    cout<< "   1. REPORTE DE COMPRAS\n\n" << endl;
                	cout<< "   2. REPORTE DE VENTAS\n\n" << endl;
	                cout<< "   3. CLIENTES(POR CODIGO)\n\n" << endl;
    	            cout<< "   4. LISTADO DE CLIENTES CON CREDITO\n\n" << endl;
        	        cout<< "   5. LISTADO DE CLIENTES CON PUNTOS ACUMULADOS\n\n" << endl;
            	    cout<< "   0. REGRESAR AL MENU PRINCIPAL\n\n"<< endl;
                	cout<< "  \nIngrese una opcion: ";
                	cin>> opcion;
                
	                switch (opcion){
    	     	        case 1: 
    	     	        system("CLS");
                	    cin.ignore();
                	    cout<<"--------------------------------------REPORTE DE COMPRAS-------------------------------\n"<<endl;
                	    cout<<"No.          CANTIDAD           FECHA           LIBRAS         PRECIO        PROVEEDOR \n";
            	        reporte_compras();
            	        system("PAUSE");
            	        goto inicio_subm_b;
						break;
						
        	 	        case 2: 
        	 	        system("CLS");
        	 	        cin.ignore();
        	 	        cout<<"--------------------------------------REPORTE DE VENTAS-------------------------------\n"<<endl;
                	    cout<<" No.  CODIGO   PESO  PRECIO  UNIDADES  NOMBRE                     TIPO CLIENTE    TIPO VENTA\n";
        	 	        reporte_ventas();
        	 	        system("PAUSE");
        	 	        goto inicio_subm_b;
        	 	        
         		        case 3: 
         		        system("CLS");
        	 	        cin.ignore();
        	 	        ventas_x_codigo();
        	 	        system("PAUSE");
						goto inicio_subm_b;
         	    	    case 4:
         	    	    	
						system("CLS");
        	 	        cin.ignore();
        	 	        cout<<"-----------------------------------LISTADO DE CLIENTES CON CREDITO-----------------------------\n"<<endl;
                        cout<<" No.  CODIGO   PESO   PRECIO  UNIDAD  NOMBRE              TIPO CLIENTE  TIPO VENTA   FECHA DE PAGO\n"<<endl;
        	 	        ventas_con_credito();
        	 	        system("PAUSE");
						goto inicio_subm_b;
         	        	case 5: 
						 system("CLS");
        	 	        cin.ignore();
        	 	        cout<<"--------------------------------LISTADO DE CLIENTES CON PUNTOS ACUMULADOS -------------------------\n"<<endl;
                        cout<<" No.  CODIGO   PESO   PRECIO  UNIDAD  NOMBRE              TIPO CLIENTE  TIPO VENTA   PUNTOS\n"<<endl;
        	 	        ventas_con_puntos();
        	 	        system("PAUSE");
						goto inicio_subm_b;
						 
                		case 0: goto Inicio; 
                	}
    		}
	}

	void crear_datos(int tipo_archivo){
		struct compras compras1[100];	
    	struct ventas ventas1[100];
		
		if (tipo_archivo == 1){
			cout<<"\nFECHA\n";
			getline(cin,compras1[0].fecha);
			cout<<"\nPROVEEDOR\n";
			getline(cin,compras1[0].proveedor);
			cout<<"\nPESO DEL CILINDRO\nlibras.";
			getline(cin,compras1[0].libras);
			cout<<"\nUNIDADES\n";
			getline(cin,compras1[0].cantidad);
			cout<<"\nPRECIO UNITARIO\nQ.";
			getline(cin,compras1[0].precio);
			escribir_a_archivo(archivo_compras,  compras1,ventas1,1);
		}else{
			cout<<"\nCODIGO CLIENTE\n";
			getline(cin,ventas1[0].codigo);
			cout<<"\nNOMBRE CLIENTE\n ";
			getline(cin,ventas1[0].nombre);
			cout<<"\nPESO DEL CILINDRO\nlibras.";
			getline(cin,ventas1[0].libras2);
			cout<<"\nUNIDADES\n ";
			getline(cin,ventas1[0].unidades);
			cout<<"\nPRECIO UITARIO\nQ. ";
			getline(cin,ventas1[0].precio);
			cout<<"\nTIPO CLIENTE--PARTICULAR/NEGOCIO\n";
			getline(cin,ventas1[0].tipo_cliente);
			cout<<"\nTIPO VENTA\n1. credito 2.contado\n";
			cin>>ventas1[0].tipoventa;
			if(ventas1[0].tipoventa=="1"){
				cout<<"\nIngrese fecha de pago (xx/xx/xxxx)\n: ";
				cin>>ventas1[0].fechapago;
		
			}else{
				cout<<"ha acumulado 5 puntos";
				ventas1[0].puntos="5";
			}
			
			escribir_a_archivo(archivo_ventas,  compras1,ventas1,2);
		}
	}

    void escribir_a_archivo(char *nombre_archivo, compras compras1[], ventas ventas1[], int tipo_archivo ){
	    int n=0;
	
		ofstream fichero(nombre_archivo, ios::app);
		string linea;

			if (tipo_archivo == 1)
			{ 
				linea=compras1[0].fecha + "|" + 
				compras1[0].proveedor +"|" +
				compras1[0].libras + "|" + 
				compras1[0].cantidad + "|" + 
				compras1[0].precio;
			}else{
				linea=ventas1[0].codigo + "|" + 
					ventas1[0].libras2 + "|" + 
					ventas1[0].precio + "|" + 
					ventas1[0].unidades + "|" + 
					ventas1[0].nombre + "|" + 
					ventas1[0].tipo_cliente + "|" + 
					ventas1[0].tipoventa + "|" +
					ventas1[0].fechapago + "|" +
					ventas1[0].puntos;
			}		
		
		fichero <<linea<< endl;
		fichero.close();
    	
	}
	
	int lectura(char *nombre_archivo, int tipo_archivo, compras compras1[], ventas ventas1[]){
	
    string linea;
    ifstream fichero(nombre_archivo);
    
    int contador=0;
    while (! fichero.eof()) 
    {
        getline(fichero,linea);
        if (! fichero.eof()) {
        	descomponer_linea(contador,compras1,ventas1,tipo_archivo,linea);
        	contador++;	 
		}
    }
    fichero.close();
    return contador;
}

    void gotoxy(int x,int y){   
      HANDLE hcon;   
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);   
      COORD dwPos;   
      dwPos.X = x;   
      dwPos.Y= y;   
      SetConsoleCursorPosition(hcon,dwPos);   
 } 

    
    void reporte_compras(){
		struct compras v_compras[100];	
    	struct ventas v_ventas[100];
    	int posiciones;
    	int posicionx = 0, posiciony = 2;
    	posiciones = lectura(archivo_compras, 1,v_compras,v_ventas);
    	
		for (int i = 0; i< posiciones; i++){
            posiciony +=2; 
            posicionx = 0;
            gotoxy(2,posiciony); 
    		
			cout<<i + 1;
		
				gotoxy(15, posiciony);
			    cout<<v_compras[i].cantidad;
			
				gotoxy(30,posiciony);
		     	cout<<v_compras[i].fecha;
			
				gotoxy(50,posiciony);
		     	cout<<v_compras[i].libras;
			
				gotoxy(65,posiciony);
		     	cout<<v_compras[i].precio;
			
				gotoxy(80,posiciony);
		     	cout<<v_compras[i].proveedor<< endl;
			
			
		}
    	
	}

	void reporte_ventas(){
		struct compras v_compras[100];	
    	struct ventas v_ventas[100];
    	int posiciones;
    	int posicionx = 0, posiciony = 2;
		posiciones = lectura(archivo_ventas, 2 ,v_compras,v_ventas);
		
		for (int i = 0; i< posiciones; i++){
			posiciony +=2; 
            posicionx = 0;
            
            gotoxy(2,posiciony); 
			cout<<i + 1;
			gotoxy(7,posiciony);
    		cout<<v_ventas[i].codigo;
    		gotoxy(16,posiciony);
    		cout<<v_ventas[i].libras2<<"lib";
    		gotoxy(23,posiciony);
    		cout<<"Q."<<v_ventas[i].precio;
    		gotoxy(32,posiciony);
    		cout<<v_ventas[i].unidades;
    		gotoxy(39,posiciony);
    		cout<<v_ventas[i].nombre<< endl;
    		gotoxy(66,posiciony);
    		cout<<v_ventas[i].tipo_cliente<< endl;
    		gotoxy(84,posiciony);
    		if(v_ventas[i].tipoventa=="1"){
    	        	cout<< "credito"<< endl;
		    	}else{
				    cout<< " Contado"<< endl;	
			    }	
    	}
    }

	
	void descomponer_linea(int posicion,compras compras1[], ventas ventas1[], int tipo_archivo,string linea)
	{
		string linea2 = linea;
        int longitud, fin1;
        string dato;
        //compras
		string proveedor;
		string libras;
		string cantidad;
		string precio;
		string fecha;
		//ventas
		string codigo;
		string libras2;
		string precio2;
		string unidades;
		string nombre;
		string tipo_cliente;
		string tipoventa;
		string fechapago;
		string puntos;

        if (tipo_archivo == 1){
			for (int i = 0; i< 5; i++)
			{
			    longitud =linea2.length();
				fin1 = linea2.find("|");
        		dato= linea2.substr(0,fin1);
        		if (i == 0){
					fecha = dato;
				}else if(i == 1){
					proveedor = dato;
				}else if(i == 2){
					libras = dato;
				}else if(i == 3){
					cantidad = dato;
				}else if(i == 4){
					precio = dato;
				}
				linea2 = linea2.substr((fin1+1), longitud - fin1);
			}
			compras1[posicion].proveedor = proveedor;
			compras1[posicion].libras = libras;
			compras1[posicion].cantidad = cantidad;
			compras1[posicion].precio = precio;
			compras1[posicion].fecha = fecha;
		}else{
			for (int i = 0; i< 9; i++)
			{
			    longitud =linea2.length();
				fin1 = linea2.find("|");
        		dato= linea2.substr(0,fin1);
        		if (i == 0){
					codigo = dato;
				}else if(i == 1){
					libras2 = dato;
				}else if(i == 2){
					precio2 = dato;
				}else if(i == 3){
					unidades = dato;
				}else if(i == 4){
					nombre = dato;
				}else if(i == 5){
					tipo_cliente = dato;
				}else if(i == 6){
					tipoventa = dato;
				}else if(i == 7){
					fechapago = dato;
				}else if(i == 8){
					puntos = dato;
				}
				linea2 = linea2.substr((fin1+1), longitud - fin1);
			}
			ventas1[posicion].codigo = codigo;
			ventas1[posicion].libras2 = libras2;
			ventas1[posicion].precio = precio2;
			ventas1[posicion].unidades = unidades;
			ventas1[posicion].nombre = nombre;
			ventas1[posicion].tipo_cliente = tipo_cliente;
			ventas1[posicion].tipoventa = tipoventa;
			ventas1[posicion].fechapago = fechapago;
			ventas1[posicion].puntos = puntos;
		}
	}
	
	void ventas_x_codigo(){
		struct compras v_compras[100];	
    	struct ventas v_ventas[100];
    	int posiciones;
    	int posicionx = 0, posiciony = 2;
    	string tventa;
    	string codigo2;
		posiciones = lectura(archivo_ventas, 2 ,v_compras,v_ventas);
		cout<<"Ingrese codigo de cliente:";
		cin>>codigo2;
		
	
     	cout<<"-------------------------------------BUSQUEDA POR CODIDO------------------------------\n"<<endl;
        cout<<" No.  CODIGO   PESO   PRECIO   UNIDAD     NOMBRE        TIPO CLIENTE    TIPO VENTA   FECHA PAGO/PUNTOS\n"<<endl;
        
		for ( int i = 0; i< posiciones; i++){ 
			if(codigo2==v_ventas[i].codigo){
				posiciony +=2; 
                posicionx = 0;
                
			    gotoxy(2,posiciony);
			    cout<<i + 1;
			    gotoxy(6,posiciony);	 
			    cout<<v_ventas[i].codigo;
			    gotoxy(15,posiciony);
    		    cout<<v_ventas[i].libras2<<"lib";
    		    gotoxy(22,posiciony);
		    	cout<<"Q."<<v_ventas[i].precio;
			    gotoxy(33,posiciony);
    		    cout<<v_ventas[i].unidades;
    	    	gotoxy(40,posiciony);
    		    cout<<v_ventas[i].nombre<< endl;
    		    gotoxy(56,posiciony);
    		    cout<<v_ventas[i].tipo_cliente<< endl;
    	    	gotoxy(72,posiciony);
    	        if(v_ventas[i].tipoventa=="1"){
    	        	cout<< "credito"<< endl;
    		    	gotoxy(85,posiciony);
    	        	cout<<v_ventas[i].fechapago<< endl;
		    	}else{
				    cout<< " Contado"<< endl;
				    gotoxy(85,posiciony);
			        cout<<v_ventas[i].puntos<< endl;	
			    }	
		    }	
    	}
    }
    
    
    void ventas_con_credito(){
		struct compras v_compras[100];	
    	struct ventas v_ventas[100];
    	int posiciones;
    	int posicionx = 0, posiciony = 2;
		posiciones = lectura(archivo_ventas, 2 ,v_compras,v_ventas);
		
		for (int i = 0; i< posiciones; i++){
			
			if("1"==v_ventas[i].tipoventa){
			posiciony +=2; 
            posicionx = 0;
            
				gotoxy(2,posiciony);
				cout<<i+1;
				gotoxy(7,posiciony);
			    cout<<v_ventas[i].codigo;
			    gotoxy(16,posiciony);
    		    cout<<v_ventas[i].libras2;
    		    gotoxy(23,posiciony);
    		    cout<<v_ventas[i].precio;
    		    gotoxy(32,posiciony);
    		    cout<<v_ventas[i].unidades;
    		    gotoxy(39,posiciony);
    		    cout<<v_ventas[i].nombre<< endl;
    		    gotoxy(59,posiciony);
    		    cout<<v_ventas[i].tipo_cliente<< endl;
    		    gotoxy(73,posiciony);
    		    cout<< "Credito"<< endl;
    		    gotoxy(88,posiciony);
    		    cout<< v_ventas[i].fechapago<< endl;
			}
    		
    	}
    }
    
	void ventas_con_puntos(){
		struct compras v_compras[100];	
    	struct ventas v_ventas[100];
    	int posiciones;
    	int posicionx = 0, posiciony = 2;
		posiciones = lectura(archivo_ventas, 2 ,v_compras,v_ventas);
		
		for (int i = 0; i< posiciones; i++){
			if("2"==v_ventas[i].tipoventa){
				posiciony +=2; 
                posicionx = 0;
                gotoxy(2,posiciony);
				cout<<i+1;
				gotoxy(7,posiciony);
			    cout<<v_ventas[i].codigo;
			    gotoxy(16,posiciony);
    		    cout<<v_ventas[i].libras2<<"lib";
    		    gotoxy(23,posiciony);
    		    cout<<"Q."<<v_ventas[i].precio;
    		    gotoxy(32,posiciony);
    		    cout<<v_ventas[i].unidades;
    		    gotoxy(39,posiciony);
    		    cout<<v_ventas[i].nombre<< endl;
    		    gotoxy(59,posiciony);
    	    	cout<<v_ventas[i].tipo_cliente<< endl;
    	    	gotoxy(73,posiciony);
    		    cout<<"Contado"<< endl;
    		    gotoxy(88,posiciony);
    	    	cout<<v_ventas[i].puntos<< endl;
			}
    		
    	}
    }
