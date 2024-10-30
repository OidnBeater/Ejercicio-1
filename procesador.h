#ifndef PROCESADOR_H
#define PROCESADOR_H

#define TAM_MEMORIA 256
#define MAX_INSTRUCCIONES 100

typedef struct {
    int opcode;
    int operando1;
    int operando2;
} Instruccion;

typedef struct {
    int A;
    int B;
    int ZeroFlag;
    int NegativeFlag;
    int PC;
    Instruccion memoriaPrograma[MAX_INSTRUCCIONES];
    int memoriaDatos[TAM_MEMORIA];
} Procesador;

void inicializar_procesador(Procesador *p);
void cargar_programa(Procesador *p, char *archivo);
void ejecutar_instruccion(Procesador *p);
void imprimir_estado(Procesador *p);

#endif