#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    printf("#########################################\n");
    printf("# Bem vindo ao nosso jogo de advinhacao #\n");
    printf("#########################################\n");

// declarando variaveis
    int chute;
    int nivel;
    int totalDeTentativas;
    int opcaoValida = 1;

// Quantidade de pontos iniciais
    double pontos = 1000.0;

//Gerador de número aleatório
    srand(time(0));
    int numeroSecreto = rand()%100;
    
//Escolhendo o nível de dificuldade

    while (opcaoValida)
    {

        printf("Escolha o nivel de dificuldade:\n");
        printf("(0)Facil (1)Medio (2)Dificil\n");
        scanf("%d",&nivel);

        switch (nivel)
        {
        case 0:
            totalDeTentativas = 20;
            opcaoValida = 0;
            break;
        case 1:
            totalDeTentativas = 15;
            opcaoValida = 0;
            break;
        case 2:
            totalDeTentativas = 6;
            opcaoValida = 0;
            break;
        default:
            printf("Informe uma opcao valida!\n");
            break;
        }
    }
    for(int i = 1; i <= totalDeTentativas; i++){
        printf("Tentativa %d de %d\n", i, totalDeTentativas);
        printf("Chute um numero: ");
        scanf("%d",&chute);

        if(chute<0){
            printf("Informe um número positivo\n");
            i--;
            continue;
        }

        if(chute == numeroSecreto){
            break;
        }
        else if(chute > numeroSecreto){
            printf("Seu chute foi maior que o numero secreto!\n");
        }
        else{
            printf("Seu chute foi menor que o numero secreto!\n");
        }
        double pontosPerdidos = abs(chute-numeroSecreto)/2.0;
        pontos = pontos-pontosPerdidos;
    } 

    if(chute == numeroSecreto){
        printf("Parabens!\n");
        printf("Pontuacao: %.2f",pontos);
    }
    else{
        printf("Tente novamente!");
    }
}