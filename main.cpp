#include <iostream>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include <vector>
#include <conio.h>
#include "ArrayList.cpp"
#include "String.cpp"
#include "BPA.cpp"

void bpa2excel(){
	char filename[3000];
	char aux[1000];
	
	
	bool frst = true;
	do{
		strcpy(filename, ".\\");
		if(!frst){
			printf("Arquivo não encontrado\n");
		}
		
		printf("Digite o nome do arquivo BPA:");
		gets(aux);
		strcat(filename, aux);
		frst = false;
	}while(fopen(filename, "r") == NULL);
	
	
	BPAIList *bpai = new BPAIList();
	BPACList *bpac = new BPACList();
	
	bpai->loadOfFile(filename);
	bpac->loadOfFile(filename);
	
	bpai->dropFormated2Excel("bpai.txt");
	bpac->dropFormated2Excel("bpac.txt");
}

void excel2bpa(){
	char filename[3000];
	char op[100];
	
	BPAIList *bpai = new BPAIList();
	BPACList *bpac = new BPACList();
	
	bpai->loadOfFile("bpai.txt");
	bpac->loadOfFile("bpac.txt");
	
	bool frst = true;
	bool ovw = false;
	
	do{
		if(!frst){
			printf("Já existe um arquivo com esse nome, ao continuar os dados do arquivo existente serão substituidos pelos novos. Continuar mesmo assim(S/N)?");
			do{
				gets(op);
			}while(stricmp(op, "S") != 0 && stricmp(op, "N") != 0);
			
			if(stricmp(op, "S") == 0){
				ovw = true;
			}
		}
		
		if(!ovw){
			printf("Digite o nome do novo arquivo BPA:");
			gets(filename);
		}
		
		frst = false;
	}while(fopen(filename, "r") != NULL && !ovw);
	
	
	
	
	BPABuilder(filename, bpac, bpai, bpai->mainCmpt);
}



int main(int argc, char** argv) {
	setlocale(LC_ALL, "");
	
	char str[1000];
	char op;
	do{
		printf("1-BPA>Excel\n2-Excel>BPA\n");
		op = getch();
		
		if(op == '1'){
			bpa2excel();
		}
		else if(op == '2'){
			excel2bpa();
		}
		else{
			system("cls");
			printf("Opção inválida");
		}
	}while(op != '1' && op != '2');
	
	
	return 0;
}
