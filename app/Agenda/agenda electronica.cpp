/*Trabajo Realizado por 
Eduardo Fermin
Elder Alvarado 
06/12/15*/
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#define tamano 100


struct contacto{
	char nombre[40];
	char estado[10];
	char cp[10];
	char edad[5];
	char numero[15];
	char correo[40];
}info_contacto[tamano];




void ingresar(void);
void buscar(void);
void modificar(void);
void guardar(void);
void cargar(void);
void contactos(void);
void eliminar(void);
void init_list(void);




main(){
	
	init_list();
	int opc;
	
	do{
		system("cls");
		
        printf("        **********************************************\n");
        printf("        *                                            *\n");
		printf("        *             *MENU*                         *\n");
		printf("        *       1.Ingresar contacto                  *\n");        
		printf("        *       2.Buscar contacto                    *\n");
		printf("        *       3.Modificar contacto                 *\n");
		printf("        *       4.Guardar en lista de contactos      *\n");
		printf("        *       5.Cargar lista de contactos          *\n");
		printf("        *       6.Ver todos los contactos            *\n");
		printf("        *       7.Eliminar contacto                  *\n");
		printf("        *       8.Salir                              *\n");
		printf("        *                                            *\n");
		printf("        **********************************************\n\n");

		scanf("%d", &opc);

		switch(opc){
		case 1:
			ingresar();
			system("pause");
			break;
			
		case 2:
			buscar();
			system("pause");
			break;
			
		case 3:
			modificar();
			system("pause");
			break;
		
		case 4:
			guardar();
			system("pause");
			break;
			
		case 5:
			cargar();
			system("pause");
			break;
			
		case 6:
			contactos();
			system("pause");
			break;

		case 7:
			eliminar();
			system("pause");
			break;
			
		}
	}while(opc!=8);
	getch();
	return 0;	
}





void init_list(void){
	register int t;
	for(t=0; t<tamano; t++)
		*info_contacto[t].nombre = '\0';
}

void ingresar(void){
	system("CLS");
	register int j;
	for(j=0; j<tamano; j++)
		if(!*info_contacto[j].nombre)
			break;			
	if(j==tamano){
		printf("Base de datos llena\n");
		return;
	}
	fflush(stdin);
	printf("Nombre: ");
	gets(info_contacto[j].nombre);
	
	fflush(stdin);
	printf("Estado: ");
	gets(info_contacto[j].estado);
	
	fflush(stdin);
	printf("Codigo Postal: ");
	gets(info_contacto[j].cp);
	
	fflush(stdin);
	printf("Edad: ");
	gets(info_contacto[j].edad);
	
	fflush(stdin);
	printf("Numero Celular: ");
	gets(info_contacto[j].numero);
	
	fflush(stdin);
	printf("Correo Electronico: ");
	gets(info_contacto[j].correo);
}


void buscar(void){
	char busca[15];
	int i;
	system("cls");

	fflush(stdin);
	printf("\nBuscar contacto\nIngrese el nombre del contacto:  ");
	gets(busca);
	
	for(i=0;i<tamano;i++){
		if(strcmpi(busca,info_contacto[i].nombre)==0){
		
			printf("\nNombre: %s\n", info_contacto[i].nombre);
			printf("Estado: %s\n", info_contacto[i].estado);
			printf("Codigo Postal: %s\n", info_contacto[i].cp);
			printf("Edad: %s\n", info_contacto[i].edad);
			printf("Numero Celular: %s\n", info_contacto[i].numero);
			printf("Correo Electronico: %s\n\n", info_contacto[i].correo);

		}
		
		}
		
	}	



void modificar(void){
char modifica[15];
	int i;
	system("cls");

	fflush(stdin);
	printf("\nBuscar contacto\nIngrese el nombre del contacto a modificar:  ");
	gets(modifica);
	
	for(i=0;i<tamano;i++){
		if(strcmpi(modifica,info_contacto[i].nombre)==0){
		
		fflush(stdin);
		printf("\n\nDame de nuevo nombre: ");
		gets(info_contacto[i].nombre);
		
		fflush(stdin);
		printf("Dame de nuevo estado: ");
		gets(info_contacto[i].estado);
		
		fflush(stdin);
		printf("Dame de nuevo codigo postal: ");
		gets(info_contacto[i].cp);
		
		fflush(stdin);
		printf("Dame de nuevo edad: ");
		gets(info_contacto[i].edad);
		
		fflush(stdin);
		printf("Dame de nuevo numero celular: ");
		gets(info_contacto[i].numero);
		
		fflush(stdin);
		printf("Dame de nuevo correo electronico: ");
		gets(info_contacto[i].correo);

		}
		
		}
		
		system("CLS");
		
		printf("Contacto modificado exitosamente\n\n");
		
}







void guardar(void){
	FILE *busq;
	register int k;
	
	printf("guardado en archivo \n\n");
	
	if((busq=fopen("Contactos-de-agenda.txt","w"))==NULL){
		printf("no se puede abrir el archivo\n");
		return;
	}
	for(k=0; k<tamano; k++)
		if(*info_contacto[k].nombre)
			if(fwrite(&info_contacto[k], sizeof(struct contacto), 1, busq)!=1)
				printf("Error de escritura de archivo\n");
	fclose(busq);
}



void cargar(void){
	FILE *busq;
	register int i;
	
	printf("archivo cargado exitosamente\n\n");
	
	if((busq=fopen("Contactos-de-agenda.txt","r"))==NULL){
		printf("no se puede abrir el archivo\n");
		return;
	}
	init_list();
	for(i=0; i<tamano; i++)
		if(fread(&info_contacto[i], sizeof(struct contacto), 1, busq)!=1){
			if(feof(busq)){
				fclose(busq);
				return;
			}
			printf("Error al leer el archivo\n");			
		}
		
}


void contactos(void){
	system("cls");
	register int t;
	for(t=0; t<tamano; t++){
		if(*info_contacto[t].nombre){
			printf("----------------------------------------");
			printf("\nNombre: %s\n", info_contacto[t].nombre);
			printf("Estado: %s\n", info_contacto[t].estado);
			printf("Codigo Postal: %s\n", info_contacto[t].cp);
			printf("Edad: %s\n", info_contacto[t].edad);
			printf("Numero Celular: %s\n", info_contacto[t].numero);
			printf("Correo Electronico: %s\n\n", info_contacto[t].correo);
		}
	}
}


void eliminar(void){
	char borrar[15];
	int i;
	system("cls");

	fflush(stdin);
	printf("\nBuscar contacto\nIngrese el nombre del contacto a eliminar:  ");
	gets(borrar);
	



	for(i=0;i<tamano;i++){
		if(strcmpi(borrar,info_contacto[i].nombre)==0){
			*info_contacto[i].nombre = '\0';
					system("CLS");
			printf("Registro borrado exitosamente\n\n");
		}
			
		}

	}



