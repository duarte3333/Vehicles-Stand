#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string> 
#include <cstdlib> 
#include <list>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <vector>
#include <unistd.h>

#include <iostream>
#include <string> //para usar strcpy(str1, str2) "string copy" incluir cstring lib, esta funçao copia str2 em str1
#include <cstdlib> //para system("Pause")


#include <time.h>
#include <iterator>
#include <algorithm>


class Vehicle {
    protected:

    std::string brand;
    std::string matricula;
    int price;
    int ano;
    std::string model;
    std::string typeFinal;

    public:
        
    virtual void setBrand(std::string marcaC) {
        
        brand = marcaC;
    }

    virtual void setYear(int anoC)  {
        
        ano = anoC;
    }

    virtual void setMatricula(std::string matriculaC)  {
        
        matricula = matriculaC;
    }

    virtual void setPrice(int precoC) {
        
        price = precoC;
    }

    virtual void setModel(std::string modeloC) {
        
        model = modeloC;
    }

    virtual void setType(std::string typeRef) {
        
        typeFinal = typeRef;
    }


    //getters

    virtual std::string getBrand(){
        
        return brand;
    }

    virtual int getYear(){
        
        return ano;
    }

    virtual std::string getMatricula(){
        
        return matricula;
    }

    virtual int getPrice()  {
        
        return price;
    }

    virtual std::string getModel() {
        
        return model;
    }

    virtual std::string getType() {
        
        return typeFinal;
    }

    
};

class Car : public Vehicle {

    private:

    int rodas= 4;
    //setters
    
    public:
    void setBrand(std::string marcaC) override {
        
        brand = marcaC;
    }

    void setYear(int anoC) override {
        
        ano = anoC;
    }

    void setMatricula(std::string matriculaC) override {
        
        matricula = matriculaC;
    }

    void setPrice(int precoC) override {
        
        price = precoC;
    }

    void setModel(std::string modeloC) override {
        
        model = modeloC;
    }


    //getters

    std::string getBrand() override {
        
        return brand;
    }

    int getYear() override {
        
        return ano;
    }


    std::string getMatricula() override{
        
        return matricula;
    }

    int getPrice() override {
        
        return price;
    }

    std::string getModel() override {
        
        return model;
    }

    int getWheels(){
        return rodas;
    }
    
};

class Motorcycle : public Vehicle {

    private:
    int rodas = 2;

    
    //setters
    public:
    void setBrand(std::string marcaC) override {
        
        brand = marcaC;
    }

    void setYear(int anoC) override {
        
        ano = anoC;
    }

    void setMatricula(std::string matriculaC) override {
        
        matricula = matriculaC;
    }

    void setPrice(int precoC) override {
        
        price = precoC;
    }

    void setModel(std::string modeloC) override {
        
        model = modeloC;
    }


    //getters

    std::string getBrand() override {
        
        return brand;
    }

    int getYear() override {
        
        return ano;
    }

    std::string getMatricula() override{
        
        return matricula;
    }

    int getPrice() override {
        
        return price;
    }

    std::string getModel() override {
        
        return model;
    }

    int getWheels(){
        return rodas;
    }
 
};

class Dealer
{
    private:
        std::list<Motorcycle*> lista_motas;
        std::list<Car*> lista_carros;
        std::list<Motorcycle*>::iterator motaI;
        std::list<Car*>:: iterator carI;
    public:

        void adicionarVeiculo();
        void mostrarVeiculos();
        void removerVeiculo();
        void editarVeiculo();
        void removerTudo();
 

};

//funcoes auxiliares aos metodos de adicionar carros
std::string randomBrand(std::string a,std::string b,std::string c)
{   
    //Esta função recebe três strings e escolhe uma delas de forma aleatória

    srand ( time(NULL) ); //inicializa a semente
    std::vector<std::string> test(5);
    test[0] = a;
    test[1] = b;
    test[2] = c;
  
    int RandIndex = rand() % 3; //gera um número aleatorio entre 0 and 4

    return test.at(RandIndex);
}
int gerarPreco(int max)
{
    
    //esta funcao gera um preço aleatório para o veiculo entre o valor inserido pelo utilizador e esse mesmo valor multiplicado por 1.7
    if (max<0){
        std::cout << "Nao temos nenhuma opção disponível para esse limite de preço";
        std::cout << "Digite 'start.again' para começar outravez: ";
        std::string start;
        std::cin >> start;

    }
    int maxmax = max*1.7;
    srand ( time(NULL) ); //inicializa a semente
    int p = rand()%(maxmax - max + 1) + max;
    std::cout << "O melhor preço que lhe consigo fazer é: " << p << "$" <<std::endl;

    return p;
}
void ClearScreen()

    //Esta função limpa 3 linhas do terminal
    {
    int n;
    for (n = 0; n < 3; n++)
      printf( "\n" );
    }
std::string stock(){

    //esta função gera aleatóriamente respostas para os modelos inseridos pelo utilizador
    //caso seja uma resposta em que o modelo nao está disponível terá que procurar um novo modelo

    srand ( time(NULL) ); //inicializa a semente
    std::vector<std::string> test(5);
    std::cout << "Deixe me ver se temos esse modelo em stock";

    int i = 0;
    char load[30];
    while(i<29) {
       //system("Estou a verificar na minha plataforma digital");
       load[i++] = '|';
       load[i] = '\0';

       printf("\n\nAGUARDE UM POUCO(estou a ver se o temos na oficina)[%-25s]", load);
       std::cout << std::endl;

       usleep(199900);
       ClearScreen();
    }

    std::cout << std::endl;
    std::cout << std::endl;
    test[0] = "Felizmente está com sorte tenho esse modelo em stock";
    test[1] = "Infelizmente não tenho esse modelo em stock";
    test[2] = "Ontem vendi o ultimo modelo desses...desculpe";
    test[3] = "Tenho aqui um último em stock!!";
    test[4] = "Chegou ontem um novo à oficina! Você é um sortudo";
    

    int RandIndex = rand() % 4; //gera um número aleatorio entre 0 and 3
    std::cout << test.at(RandIndex) << std::endl;

    if (test.at(RandIndex)==test[1] || test.at(RandIndex)==test[2]){
        std::cout << "Procure outro modelo sff";
   
    }


    return test.at(RandIndex);

}
void sugestoes(Motorcycle *mota,std::string model1,std::string model2,int year1,int year2, int price1, int price2)
{   
    
    //função que cria sugestões de motas caso o utilizador pressione a tecla 'h' e dê enter

    std::cout << "Os modelos que tenho são:        " << std::endl;
    std::cout << "Opção 1                  |               Opção2 " << std::endl;
    std::cout << "_________________________ ______________________" << std::endl;
    std::cout << "                         |                    " <<std::endl;
    std::cout << model1 << "(" << year1 << ")" << std::setw(29) << model2 << "(" << year2 << ")"<< std::endl;
    std::cout << price1 << "$" << std::setw(18) << "|" << std::setw(18) << price2 << "$" << std::endl;
    std::cout << std::endl;
    std::cout << "_________________________|______________________" << std::endl;
    std::cout << std::endl;

    std::cout << "Digite '1' se desejar a opção 1, ou '2' caso deseje a opção 2: " << std::endl;
    std::string press;

    std::cin >> press;
    if (press == "1"){
        mota->setModel(model1);
        mota->setYear(year1);
        mota->setPrice(price1);
    }
    else if(press == "2"){
        mota->setModel(model2);
        mota->setYear(year2);
        mota->setPrice(price2);
    }
}
void sugestoesC(Car *carro,std::string model1,std::string model2,int year1,int year2, int price1, int price2)
{
    //função que cria sugestões de motas caso o utilizador pressione a tecla 'h' e dê enter

    std::cout << "Os modelos que tenho são:        " << std::endl;
    std::cout << "Opção 1                  |               Opção2 " << std::endl;
    std::cout << "_________________________ ______________________" << std::endl;
    std::cout << "                         |                    " <<std::endl;
    std::cout << model1 << "(" << year1 << ")" << std::setw(29) << model2 << "(" << year2 << ")"<< std::endl;
    std::cout << price1 << "$" << std::setw(18) << "|" << std::setw(18) << price2 << "$" << std::endl;
    std::cout << std::endl;
    std::cout << "_________________________|______________________" << std::endl;
    std::cout << std::endl;

    std::cout << "Digite '1' se desejar a opção 1, ou '2' caso deseje a opção 2: " << std::endl;
    std::string press;

    std::cin >> press;
    if (press == "1"){
        carro->setModel(model1);
        carro->setYear(year1);
        carro->setPrice(price1);
    }
    else if (press == "2"){
        carro->setModel(model2);
        carro->setYear(year2);
        carro->setPrice(price2);
    }
}
std::string gerarMatricula(int n)
{   
    //função que gera uma matricula aleatóriamente
    srand(time(NULL));
    char alphabet[44] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G',
                          'H', 'I', 'J', 'K', 'L', 'M', 'N',
                          'O', 'P', 'Q', 'R', 'S', 'T', 'U',
                          'V', 'W', 'X', 'Y', 'Z', '1', '2',
                          '3', '4', '5', '6', '7', '8', '9',
                          '1', '2', '3', '4', '5', '6', '7',
                          '8', '9'};
 
    std::string res = "";
    for (int i = 0; i < n; i++){
        res = res + alphabet[rand() % 44]; 
    }

    return res;

}



//metodo de adicionar carros
void Dealer::adicionarVeiculo(){

    //variavéis
    std::string typeCar = "CARRO";
    std::string typeMotorcycle = "MOTA";


    std::cout << "O veiculo que deseja comprar tem quantas rodas? ";
    int wheels_number1 = 4;
    std::cin >> wheels_number1; // recolher input do utilizador

    //situação de ser um carro
    if (wheels_number1 == 4){
        
        Car *carro1 = new(Car);
        //carro1 = (Car*)malloc(sizeof(Car));//libertar espaço

        carro1->setType(typeCar);
              std::cout << "Hmm...boa escolha. Bem vi que carros é a sua cara!" << std::endl;
        
        
        //Marca
        std::cout << std:: endl;
        std::cout << "E qual é a marca que prefere para o seu veiculo?(Se tiver mais do que um nome escreva tudo junto)" << std:: endl;
        std::cout << "Caso queira uma sugestão pressione a tecla 'h'. Senão diga-me a sua marca de preferência: ";
        std::string brandU;
        std::cin >> brandU;
       
        //se a tecla da sugestão + enter for pressionada
        if (brandU == "h"){

            std::string brandD;
            std::string dref;
            std::cout << std:: endl;
            brandD = randomBrand("Bugatti","Porsche","Ferrari");
            std::cout << "Eu sugiro que compre um " << brandD << std::endl;
            carro1->setBrand(brandD);

            if(brandD == "Bugatti"){
                sugestoesC(carro1,"Chiron","Centodieci",2019,2018,2495409,1987921);
            }

            else if(brandD == "Porsche"){
                sugestoesC(carro1,"718Cayman S","911 Targa 4S",2019,2018,105409,117921);
            }

            else if(brandD == "Ferrari"){
                sugestoesC(carro1,"LaFerrari","Ferrari 458",2015,2014,1495409,287921);
            }

            std::cout << "O carro que escolheu foi um " 
            << carro1->getBrand() << " " 
            << carro1->getModel() << " de " 
            << carro1->getYear() << " cujo valor é " 
            << carro1->getPrice() << " $ "<< std::endl;

            //Matricula
            std::cout << std::endl; 
            std::cout << std::endl; 
            std::string ma = gerarMatricula(6);
            carro1->setMatricula(ma);
            std::cout << "A matricula do carro é " << carro1->getMatricula() << std::endl; 

            //Adicionar o carro em questão à lista de pointers de carros
            lista_carros.push_back(carro1);  
            std::cout << std::endl;
            std::cout << "O seu carro foi adicionado ao seu histórico de pesquisa" << std::endl;    
            std::cout << "Use o comando 'show.vehicles' para ver o seu histórico";   
            std::cout << std::endl;

        }
        else {

        //caso o utilizador não opte pela sugestão
        carro1->setBrand(brandU);
        std::cout << std::endl;
        std::cout << "Boa escolha a " << brandU << " é uma marca de grande qualidade!"<< std::endl;
        
        std::string respostaStock;
        while (true){

        //Modelo
        std::cout << std::endl;
        std::cout << "Qual o modelo que quer da marca " << brandU << "? "<< std::endl;
        std::string modelU;
        std::cin >> modelU;
        carro1->setModel(modelU);
 

        //Ano
        std::cout << std::endl;
        int yearU;
        std::cout << "Diga que qual o ano que prefere para o seu " << brandU << "? " << std::endl;
        std::cin >> yearU;
        carro1->setBrand(brandU);
        carro1->setYear(yearU);
        respostaStock.clear();
        respostaStock = stock();// recolhe a resposta aleatória dada pela a funcao stock()

        if(respostaStock == "Felizmente está com sorte tenho esse modelo em stock" ||
        respostaStock == "Tenho aqui um último em stock!!" || respostaStock == "Chegou ontem um novo à oficina! Você é um sortudo"){
            break;
        }

        }

        //Preço
        int priceU;
        std::cout << "Como sou um homem de negocios e quero ver se você também o é de forma humilde." << std::endl; 
        std::cout << "Pergunto-lhe, quanto acha que vale o carro que quer?(Em $) ";
        std::cin >> priceU;
        int precoF = gerarPreco(priceU);
        carro1->setPrice(precoF);
        std::cout << std::endl; 



        std::cout << "O carro que escolheu foi um " 
        << carro1->getBrand() << " " 
        << carro1->getModel() << " de " 
        << carro1->getYear() << " cujo valor é " 
        << carro1->getPrice() << " $ "<< std::endl;
        std::cout << "Até que nem foi um mau o seu palpite. Tem o meu respeito. ";


        //matricula
        std::cout << std::endl; 
        std::cout << std::endl; 
        std::string ma = gerarMatricula(6);
        carro1->setMatricula(ma);
        std::cout << "A matricula do carro é " << carro1->getMatricula() << std::endl; 

        lista_carros.push_back(carro1);
        std::cout << std::endl;
        std::cout << "O seu carro foi adicionado ao seu histórico de pesquisa" << std::endl;    
        std::cout << "Use o comando 'show.vehicles' para ver o seu histórico";   
        std::cout << std::endl;

        }

    
    }


    //Agora é o caso da Mota
    else if(wheels_number1 == 2){

        Motorcycle *mota1 = new(Motorcycle);
        //mota1 = (Motorcycle*)malloc(sizeof(Motorcycle));//libertar espaço
        mota1->setType(typeMotorcycle);
        std::cout << "Hmm...boa escolha. Bem vi que motas é a sua cara!" << std::endl;
        
        //Marca
        std::cout << std:: endl;
        std::cout << "E qual é a marca que prefere para o seu veiculo?(Se tiver mais do que um nome escreva tudo junto)  " << std:: endl;
        std::cout << "Caso queira um sugestão pressione a tecla 'h'. Senão diga-me a sua marca de preferência: ";
        std::string brandU;
        std::cin >> brandU;
       
        //se a tecla da sugestão + enter for pressionada
        if (brandU == "h"){

            std::string brandD;
            std::string dref;
            std::cout << std:: endl;
            brandD = randomBrand("Ducati","Honda","MV Agusta");
            std::cout << "Eu sugiro que compre uma " << brandD << std::endl;
            mota1->setBrand(brandD);

            if(brandD == "Ducati"){
                sugestoes(mota1,"Panigale V4 SP","Xdiavel S",2019,2018,45409,17921);
            }

            else if(brandD == "Honda"){
                sugestoes(mota1,"CBR1000RR-R","CBR650 R",2021,2020,26409,9721);
            }

            else if(brandD == "MV Agusta"){
                sugestoes(mota1,"Rush 1000","F3 800RC",2015,2018,35101,19015);
            }

            std::cout << "A mota que escolheu foi uma " 
            << mota1->getBrand() << " " 
            << mota1->getModel() << " de " 
            << mota1->getYear() << " cujo valor é " 
            << mota1->getPrice() << " $ "<< std::endl;

            //matricula
            std::cout << std::endl; 
            std::cout << std::endl; 
            std::string ma = gerarMatricula(6);
            mota1->setMatricula(ma);
            std::cout << "A matricula do carro é " << mota1->getMatricula() << std::endl; 

            lista_motas.push_back(mota1);
            std::cout << std::endl;
            std::cout << "A sua mota foi adicionada ao seu histórico de pesquisa" << std::endl;    
            std::cout << "Use o comando 'show.vehicles' para ver o seu histórico";   
            std::cout << std::endl;

        }

        // se o utilizador não optar por uma sugestão
        else {
        mota1->setBrand(brandU);
        std::cout << std::endl;
        std::cout << "Boa escolha a " << brandU << " é uma marca de grande qualidade!"<< std::endl;
        
        std::string respostaStock;
        while (true){

        //Modelo
        std::cout << std::endl;
        std::cout << "Qual o modelo que quer da marca " << brandU << "? "<< std::endl;
        std::string modelU;
        std::cin >> modelU;
        mota1->setModel(modelU);
 

        //Ano
        std::cout << std::endl;
        int yearU;
        std::cout << "Diga que qual o ano que prefere para o seu " << brandU << "? " << std::endl;
        std::cin >> yearU;
        mota1->setBrand(brandU);
        mota1->setYear(yearU);
        respostaStock.clear();
        respostaStock = stock();// recolhe a resposta aleatória dada pela a funcao stock()

        if(respostaStock == "Felizmente está com sorte tenho esse modelo em stock" ||
        respostaStock == "Tenho aqui um último em stock!!" || respostaStock == "Chegou ontem um novo à oficina! Você é um sortudo"){
            break;
        }

        }
        //Preço
        int priceU;
        std::cout << "Como sou um homem de negocios e quero ver se você também o é de forma humilde." << std::endl; 
        std::cout << "Pergunto-lhe, quanto acha que vale o carro que quer?(Em $) ";
        std::cin >> priceU;
        int precoF = gerarPreco(priceU);
        mota1->setPrice(precoF);
        std::cout << std::endl; 



        std::cout << "O carro que escolheu foi um " 
        << mota1->getBrand() << " " 
        << mota1->getModel() << " de " 
        << mota1->getYear() << " cujo valor é " 
        << mota1->getPrice() << " $ "<< std::endl;
        std::cout << "Até que nem foi um mau o seu palpite. Tem o meu respeito. ";


        //Matricula
        std::cout << std::endl; 
        std::cout << std::endl; 
        std::string ma = gerarMatricula(6);
        mota1->setMatricula(ma);
        std::cout << "A matricula do carro é " << mota1->getMatricula() << std::endl; 

        lista_motas.push_back(mota1);

        std::cout << std::endl;
        std::cout << "A sua mota foi adicionada ao seu histórico de pesquisa" << std::endl;    
        std::cout << "Use o comando 'show.vehicles' para ver o seu histórico";   
        std::cout << std::endl;

        }
    }
        //Caso alguem queira veiculos de muitas rodas
    else{
        std::cout << "Desculpe não tenho nenhum veiculo com esse número de rodas na oficina" << std::endl ;
        std::cout << "Use o comando 'add.vehicle' para tentar de novo :)" << std::endl ;
    }
    
    
    return;

}

//metodo para mostrar todos os veiculos já adicionados até ao momento
void Dealer::mostrarVeiculos(){

    std::cout << "Tipo" << std::setw(7) << "|" <<
    std::setw(7) << "Marca" << std::setw(8) << "|" <<
    std::setw(12) << "Matricula" << std::setw(4) << "|" <<
    std::setw(12) << "Preço($)" << std::setw(6) << "|" << 
    std::setw(8) << "Ano" << std::setw(7) <<"|" <<
    std::setw(8) << "Rodas" << std::setw(7) <<"|" <<
    std::setw(12) << "Modelo" << std::endl;

    Car * carroAtual; //pointer para um carro
    Motorcycle * motaAtual; //pointer para uma mota

    //o carI é o iterador. 
    for (carI = lista_carros.begin(); carI != lista_carros.end() ; carI++){

        carroAtual = *carI;
        std::cout << carroAtual->getType() <<
        std::setw(15) << carroAtual->getBrand() <<
        std::setw(15) << carroAtual->getMatricula() <<
        std::setw(17) << carroAtual->getPrice() <<
        std::setw(15) << carroAtual->getYear() <<
        std::setw(13) << carroAtual->getWheels() <<
        std::setw(23) << carroAtual->getModel() << std::endl;

    }

    for (motaI = lista_motas.begin(); motaI != lista_motas.end() ; motaI++){

        motaAtual = *motaI;
        std::cout << motaAtual->getType() <<
        std::setw(15) << motaAtual->getBrand() <<
        std::setw(16) << motaAtual->getMatricula() <<
        std::setw(17) << motaAtual->getPrice() <<
        std::setw(15) << motaAtual->getYear() <<
        std::setw(13) << motaAtual->getWheels() <<
        std::setw(23) << motaAtual->getModel() << std::endl;

    }
}

//metodo para remover um dos veiculos adicionados até ao momento
void Dealer::removerVeiculo(){


    Car * carroAtual; //pointer para um carro
    Motorcycle * motaAtual; //pointer de uma mota

    std::cout << "Diga qual a marca do veiculo que quer remover da lista de carros pesquisados: ";
    std::string marcaR;
    std::cin >> marcaR;

    std::cout << "Diga qual a matricula do veiculo que quer remover da lista de carros pesquisados: ";
    std::string maR;
    std::cin >> maR;

    //percorrer a lista de pointers de carros para eliminar só o carro que se pretende
    for (carI = lista_carros.begin(); carI != lista_carros.end() ; carI++){

        carroAtual = *carI;//aceder ao carro atual no for
        
        if (carroAtual->getMatricula() == maR ){
            
            lista_carros.remove(carroAtual);//remove apenas o carro nessa iteração
            std::cout << "O " << marcaR << " foi removido com sucesso da sua lista de pesquisa! " << std::endl;
            break;

        }
  

    }

    //percorrer a lista de pointers de motas para eliminar só a mota que se pretende
    for (motaI = lista_motas.begin(); motaI != lista_motas.end() ; motaI++){
        
        motaAtual = *motaI; //aceder à mota atual no for
        
        if (motaAtual->getMatricula() == maR ){
            
            lista_motas.remove(motaAtual);//remove apenas a mota dessa iteração
            std::cout << "A " << marcaR << " foi removida com sucesso da sua lista de pesquisa!! " << std::endl;
            break;
        
        }


    }



}

//metodo para editar uma caracteristica de um dos veiculos
void Dealer::editarVeiculo(){


    Car * carroAtual; //pointer para um carro
    Motorcycle * motaAtual; //pointer de uma mota

    std::cout << "Se quiser editar um carro digite '1'. Se quiser editar uma mota digite '2':  ";
    std::string tipo;
    std::cin >> tipo;

    std::cout << "Diga qual a matricula do veiculo que quer editar: ";
    std::string matriculaE;
    std::cin >> matriculaE;


    std::cout << std::endl;
    std::cout << "De entre 'modelo', 'ano', 'marca' , 'matricula' ou 'preço' " << std::endl;
    std::cout << "Diga qual a caracteristica do veiculo que quer editar do veiculo em questão: ";

    std::string change;
    std::cin >> change;

    std::string changeStr;
    int changeInt;


    if (change=="modelo" || change=="marca" || change == "matricula"){

        std::cout << "Quer que essa característica fique como? " << std::endl;
        std::cin >> changeStr;
    }

    else if (change=="ano" || change=="preço"){

        std::cout << "Quer que essa característica fique como? " << std::endl;
        std::cin >> changeInt;
    
        
    }

    //editar apenas a característica pretendida do carro
    if (tipo == "1"){
        for (carI = lista_carros.begin(); carI != lista_carros.end() ; carI++){

            carroAtual = *carI;
            
            if (change == "modelo"){
                
                carroAtual->setModel(changeStr);
                std::cout << std::endl;
                std::cout << "O modelo do seu carro foi editado com sucesso";
                break;

            }

            else if(change == "ano"){

                carroAtual->setYear(changeInt);
                std::cout << std::endl;
                std::cout << "O ano do seu carro foi editado com sucesso";
                break;

            }

            else if(change == "matricula"){
                
                carroAtual->setMatricula(changeStr);
                std::cout << std::endl;
                std::cout << "A matricula do seu carro foi editada com sucesso";
                break;

            }

            else if(change == "preço"){
                
                carroAtual->setPrice(changeInt);
                std::cout << std::endl;
                std::cout << "O preço do seu carro foi editado com sucesso";
                break;

            }

            else if(change == "marca"){
                
                carroAtual->setBrand(changeStr);
                std::cout << std::endl;
                std::cout << "A marca do seu carro foi editada com sucesso";
                break;

            }
    

        }
    }

     //editar apenas a característica pretendida da mota
    else if(tipo == "2"){
        for (motaI = lista_motas.begin(); motaI != lista_motas.end() ; motaI++){
            
            motaAtual = *motaI;
            
            if (change == "modelo"){
                
                motaAtual->setModel(changeStr);
                std::cout << std::endl;
                std::cout << "O modelo da sua mota foi editado com sucesso";
                break;

            }

            else if(change == "ano"){

                motaAtual->setYear(changeInt);
                std::cout << std::endl;
                std::cout << "O ano da sua mota foi editado com sucesso";
                break;

            }

            else if(change == "matricula"){
                
                motaAtual->setMatricula(changeStr);
                std::cout << std::endl;
                std::cout << "A matricula da sua mota foi editada com sucesso";
                break;

            }

            else if(change == "preço"){
                
                carroAtual->setPrice(changeInt);
                std::cout << std::endl;
                std::cout << "O preço da sua mota foi editado com sucesso";
                break;

            }
            
            else if(change == "marca"){
                
                motaAtual->setBrand(changeStr);
                std::cout << std::endl;
                std::cout << "A marca do seu carro foi editada com sucesso";
                break;

            }


        }
    }
}

//metodo para remover todos os veiculos adicionados até ao momento da lista
void Dealer::removerTudo(){
    
    //esvaziar a lista de carro e a lista de motas para não existir nenhum na lista 
    lista_carros.clear();
    lista_motas.clear();

    std::cout << std::endl << std::endl;
    std::cout << "Todos os veiculos foram removidos da lista" << std::endl;
    std::cout << "Use o comando 'show.vehicles' para verificar que a lista está vazia" << std::endl;
    std::cout << std::endl;
}
