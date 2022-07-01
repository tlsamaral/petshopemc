#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void menu(void);
void registerUser(void);
void registerPet(void);
void viewDados(void);

struct dados{
    char nomeDono[100];
    int idadeDono;
    char enderecoDono[100];
    char telDono[20];
    char emailDono[50];
    char senhaDono[8];
};

int cont = 0;
int sair = 0;

struct dadosPet{
    char nomePet[100];
    char racaPet [100];
    int idadePet;
    char portePet[10];
    float pesoPet;
}numPet[5];
int main(){

while(sair == 0)
{

   menu();
}



}

void menu(void)
{
    int opcao;

    printf("\nBem vindo ao Sistema de registro do seu bichinho");
    printf("\n1- Registrar Usuario");
    printf("\n2- Registrar Bichinho");
    printf("\n3- Visualizar dados");
    printf("\n4- Sair");
    printf("\n");
    printf("\nEscolha uma opcao: ");
    scanf("%d",&opcao);
    fflush(stdin);
    switch(opcao){
    case 1:
    registerUser();
    break;

    case 2:
    registerPet();
    break;

    case 3:
    viewDados();
    break;

    default:
        return sair = 1;
    break;

    }

}

struct dados dono;

int statusDono =0;

struct dadosPet pet;

void registerUser()
{
    char senha2[8];

    printf("\nDigite seu nome: ");
    gets(dono.nomeDono);

    printf("\nDigite sua idade: ");
    scanf("%d",&dono.idadeDono);
    fflush(stdin);

    printf("\nDigite seu endereco: ");
    gets(dono.enderecoDono);

    printf("\nDigite seu telefone: ");
    gets(dono.telDono);

    printf("\nDigite seu email: ");
    gets(dono.emailDono);


    printf("\nDigite sua senha: \n");
    printf("\nDeve conter 8 caracteres!!!\n");
    gets(dono.senhaDono);

    printf("\nRepita sua senha: ");
    gets(senha2);

    printf("senha 1 : %s\nsenha 2: %s",dono.senhaDono,senha2);
    if(strcmp(dono.senhaDono,senha2) == 0){
        printf("\nParabens voce concluiu seu cadastro <3");
            statusDono = 1;

        system("cls");
    }else{
        printf("\nErro senhas nao conferem");
    }


}

void registerPet()
{
    if(statusDono == 1)
    {

    printf("\nQual o nome do seu Pet: ");
    gets(pet.nomePet);

    printf("\nQual a raca dele(a)? ");
    gets(pet.racaPet);
    fflush(stdin);

    printf("\nQual a idade do pet? ");
    scanf("%d",&pet.idadePet);
    fflush(stdin);

    printf("\nQual o porte do pet?(pequeno, grande ou medio) \n");
    gets(pet.portePet);

    printf("\nQual o peso dele(a) \n");
    scanf("%f",&pet.pesoPet);
    fflush(stdin);
    numPet[cont] = pet;
    cont++;
    printf("Parabens Pet registrado com Sucesso!!");
    }else{
        system("cls");
        printf("REGISTRE-SE PRIMEIRO !!!\n \n");
    }
}

void viewDados()
{
    char email[50], senha[8];
    int aux=0,i;
    while(aux == 0){
    printf("LOGIN\n");
    printf("E-mail: \n");
    gets(email);
    printf("Senha: \n");
    gets(senha);


    if(strcmp(email, dono.emailDono) == 0 && strcmp(senha, dono.senhaDono) == 0){
    system("cls");
    printf("\nDados do usuario\n");
    printf("Usuario: %s\n",dono.nomeDono);
    printf("Idade: %d\n",dono.idadeDono);
    printf("Endereco: %s\n",dono.enderecoDono);
    printf("Telefone: %s\n",dono.telDono);
    printf("Email: %s\n",dono.emailDono);
    printf("Senha: Segredo!");
    printf("\n");
    printf("---------------------");
    printf("\n");

    for(i=0;i<cont;i++)
    {
        printf("Pet = %d\n", i+1);

        printf("nome do pet: %s\n",numPet[i].nomePet);
        printf("raca do pet: %s\n",numPet[i].racaPet);
        printf("idade do pet: %d\n",numPet[i].idadePet);
        printf("porte do pet: %s\n",numPet[i].portePet);
        printf("peso do pet: %.2f\n",numPet[i].pesoPet);
    }

    aux= 1;
    }
    else{
        printf("Usuario ou senha errada!!\n");
    }
  }
}
