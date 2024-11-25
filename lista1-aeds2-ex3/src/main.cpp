#include "dictionary.hpp"

#define avl 0

int main() {
    AVLTree avlTree; 
    BinaryTree binaryTree;

    vector<string> words = {
        "abacaxi", "abelha", "abobora", "academia", "acao", "adocao", "agenda", "agente",
        "agulha", "alce", "alegria", "algodao", "alicate", "almoco", "amarelo", "amigo",
        "amor", "amostra", "aniversario", "anjo", "aparelho", "ape", "apito", "aplauso",
        "arame", "aranha", "arara", "arvore", "asa", "atadura", "ate", "atleta",
        "atual", "audiencia", "aula", "aumento", "aureola", "australia", "aviao", "aviso",
        "azul", "bala", "balanço", "baleia", "balinha", "banco", "banheira", "banheiro",
        "banjo", "barra", "barulho", "batata", "bateria", "bebida", "belo", "bengala",
        "bermuda", "bicicleta", "bicho", "bigode", "bilhete", "biscoito", "bispo", "blusa",
        "bola", "bolacha", "bolha", "bolo", "boneca", "boneco", "borboleta", "borda",
        "borracha", "botao", "boteco", "brasil", "bravo", "breno", "briga", "brinquedo",
        "bronze", "bruxa", "bucha", "bufalo", "buraco", "cabana", "cabelo", "cachorro",
        "cadeado", "cadeira", "caderno", "cafe", "caju", "caminho", "camiseta", "campo",
        "canada", "canguru", "canivete", "canoa", "cantor", "capitulo", "carta", "carvao",
        "casa", "casaco", "casamento", "casca", "cavalo", "cebola", "cedro", "celular",
        "cenoura", "cereal", "cimento", "cinto", "cidade", "cinema", "cinza", "circulo",
        "cisne", "clube", "cobra", "coelho", "colher", "colina", "coluna", "comida",
        "concha", "condor", "coqueiro", "coracao", "coral", "coruja", "corvo", "costura",
        "cotovelo", "couve", "covarde", "cozinha", "cravo", "crianca", "cristal", "cruz",
        "cueca", "culpa", "curativo", "curva", "custo", "dado", "danca", "dedo",
        "defeito", "deleite", "dente", "desenho", "deserto", "desfile", "detetive", "dia",
        "diamante", "dinamite", "dinheiro", "diploma", "disco", "diva", "doce", "doente",
        "dogue", "dois", "dominio", "doninha", "dormir", "dourado", "dragao", "drama",
        "dreno", "duelo", "duende", "duque", "eco", "edificio", "editor", "efeito",
        "egito", "eira", "elefante", "elite", "embalagem", "embaixo", "empada", "emprego",
        "encanto", "encontro", "enfermeiro", "engenheiro", "enigma", "enorme", "entrada", "entrega",
        "envelope", "epoca", "equipe", "eremita", "erro", "escada", "escama", "escova",
        "escrita", "escudo", "esfinge", "esfera", "espaco", "espada", "espanha", "esparadrapo",
        "esponja", "esporte", "espuma", "esquilo", "estadio", "estado", "estrela", "estudante",
        "eterno", "exame", "exemplo", "exito", "faca", "fada", "faixa", "falcao",
        "familia", "famoso", "farao", "farinha", "farol", "fazenda", "febre", "fechado",
        "ferida", "ferro", "festival", "figo", "filete", "filtro", "fim", "fita",
        "flauta", "floco", "flor", "floresta", "florista", "fogo", "foice", "folha",
        "fonte", "formiga", "fortaleza", "fosforo", "fossa", "fresco", "frio", "fronteira",
        "fundo", "furacao", "furador", "furto", "fusca", "galo", "galinha", "galpao",
        "gama", "ganso", "garagem", "garfo", "gargalo", "garganta", "garrafa", "gato",
        "gaveta", "geladeira", "geleia", "gemido", "gente", "gesso", "gigante", "ginasio",
        "girafa", "goleiro", "golfinho", "gota", "grade", "grama", "grampeador", "granada",
        "grande", "gravata", "grilo", "grinalda", "guarda", "guitarra", "habitante", "helicoptero",
        "hiena", "historia", "horizonte", "hospede", "hotel", "humano", "idade", "idioma",
        "igreja", "ilha", "imagem", "imovel", "impressora", "inseto", "insulina", "instrumento",
        "invencao", "inverno", "irmao", "isqueiro", "jacare", "jaguatirica", "jardim", "jarra",
        "javali", "jegue", "jiboia", "joaninha", "joelho", "jogador", "jogo", "jornal",
        "juba", "juiz", "julgamento", "julio", "junho", "jurado", "justica", "juventude",
        "labirinto", "lacre", "lago", "lagoa", "lampada", "lance", "lanterna", "lapis",
        "laranja", "larva", "lasanha", "latim", "leao", "legenda", "lembranca", "lenda",
        "lenhador", "lenha", "leque", "letra", "leve", "levar", "livro", "lobo",
        "locomotiva", "locutor", "lombo", "lontra", "loteria", "lua", "luminaria", "lupa",
        "luta", "macaco", "machado", "maçaneta", "madeira", "madrugada", "mae", "mala",
        "manga", "manivela", "manta", "mar", "maracuja", "marcha", "marfim", "marinheiro",
        "marte", "martelo", "mascara", "massa", "mastro", "medalha", "medico", "melancia",
        "meleca", "menino", "menta", "mercado", "mesa", "metal", "meteoro", "microfone",
        "milho", "militar", "minhoca", "minuto", "misterio", "moeda", "moita", "molho",
        "monstro", "montanha", "morango", "morcego", "morte", "motorista", "mundo", "musica",
        "nacao", "nadar", "nariz", "natureza", "navio", "neblina", "neve", "noite",
        "noz", "nublado", "nuvem", "oasis", "obrigado", "oceano", "oculos", "oficina",
        "oi", "olho", "olivia", "omelete", "onca", "ondas", "onibus", "operacao",
        "opiniao", "orquestra", "ovo", "ovulo", "pacu", "padaria", "pagar", "pato",
        "peca", "peixe", "pena", "perfeito", "pirata", "planta", "poeta", "porta",
        "preto", "relogio", "rio", "rosa", "sabado", "sombra", "tesouro", "zebra"
    };
    
    if (avl) {
        loadDictionaryAVL(avlTree, words);
    } else {
        loadDictionaryBinary(binaryTree, words);
    }


    string input;
    cout << "Digite a palavra desejada (aperte ESC para sair):\n";
    while (true) {
        int ch = _getch();

        if (ch == 27) {
            break;
        } else if (ch == 8 || ch == 127) {
            if (!input.empty()) {
                input.pop_back();

                cout << "\b \b";

                cout << "\033[J";
            }
        } else if (isprint(ch)) {
            input += static_cast<char>(ch);
            cout << static_cast<char>(ch);
        } else {
            continue;
        }

        cout << "\033[s";
        cout << "\nSugestoes:\n";

        vector<string> suggestions;
        if (!input.empty()) {
            if (avl) {
                suggestions = avlTree.autocomplete(input);
            } else {
                suggestions = binaryTree.autocomplete(input);
            }
        }

        if (suggestions.empty()) {
            cout << "Nenhuma palavra encontrada.\n";
        } else {
            for (const auto& word : suggestions) {
                cout << word << "\n";
            }
        }

        cout << "\033[J";
        
        cout << "\033[u";
        
        cout.flush();
    }

    return 0;
}