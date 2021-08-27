typedef struct disco Disco;
typedef struct pino Pino;


struct disco{
    Disco* next;
    char tamDisco;
};

struct pino{
    Disco* topo;
    char numDiscos;
};

Pino* criarPino();
Disco* criarDisco(int n);
Disco* pop(Pino* pino);
void push(Pino* pino, Disco* disco);
void excluirPino(Pino* pino);