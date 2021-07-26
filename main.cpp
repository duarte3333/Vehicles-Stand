#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <vector>
#include <unistd.h>
#include <iostream>
#include <string> 
#include <cstdlib> 
#include <time.h>
#include "ClassesT2.cpp"





int main(){

    std::cout << "Bem vindo à loja de carros de luxo do Duarte" << std::endl << "Use o comando 'help' para ver as funcionalidades do programa" << std::endl; 


    Dealer *rapazOficina = new (Dealer);//criar a instância da classe Dealer

    std::string line;

    //chamar o vários comandos do programa
    while(std::getline(std::cin, line)){

        std::istringstream command (line); 
        std::string cmd;
        command >> cmd;
        if(cmd == "help" || cmd == "?")
        {  
            std::cout << std::endl << std::endl;
            std::cout << "Comandos:" << std::endl
                << "help - mostra esta ajuda" << std::endl
                << "credits - mostra quem fez o trabalho" << std::endl
                << "add.vehicle - adiciona um carro ou mota" << std::endl
                << "show.vehicles - dá print de todos os carros e motas falados até agora" << std::endl
                << "remove.vehicle - permite remover um veiculo da lista de veiculos pesquisados " << std::endl
                << "edit.vehicle - permite editar características de algum carro da lista de veiculos " << std::endl
                << "remove.all - permite remover todos os veiculos da lista" << std::endl;
        }
        else if(cmd == "add.vehicle") rapazOficina->adicionarVeiculo();
        else if(cmd == "show.vehicles") rapazOficina->mostrarVeiculos();
        else if(cmd == "remove.vehicle") rapazOficina->removerVeiculo();
        else if(cmd == "edit.vehicle") rapazOficina->editarVeiculo();
        else if(cmd == "remove.all") rapazOficina->removerTudo();
        else if(cmd == "credits"){
            std::cout << std::endl << std::endl << std::endl;
            std::cout << "O autor deste trabalho foi o Duarte Sá Morais" << std::endl;
            std::cout << "Este projeto foi realizado no âmbito de uma tarefa para a FST-Lisboa " << std::endl;
            std::cout << std::endl;;
        }    
        
    }

    return 0;
}
