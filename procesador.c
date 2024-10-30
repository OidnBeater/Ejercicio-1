#include "procesador.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inicializar_procesador(Procesador *p) {
    p->A = 0;
    p->B = 0;
    p->ZeroFlag = 0;
    p->NegativeFlag = 0;
    p->PC = 0;
    for (int i = 0; i < MAX_INSTRUCCIONES; i++) {
        p->memoriaPrograma[i].opcode = -1;
    }
    for (int i = 0; i < TAM_MEMORIA; i++) {
        p->memoriaDatos[i] = 0;
    }
}

void cargar_programa(Procesador *p, char *archivo) {
    FILE *fp;
    int i, opcode, operando1, operando2;
    fp = fopen(archivo, "r");
    if (fp == NULL) {
        printf("Error al abrir archivo\n");
        exit(1);
    }
    i = 0;
    while (fscanf(fp, "%d %d %d", &opcode, &operando1, &operando2) == 3 && i < MAX_INSTRUCCIONES) {
        p->memoriaPrograma[i].opcode = opcode;
        p->memoriaPrograma[i].operando1 = operando1;
        p->memoriaPrograma[i].operando2 = operando2;
        i++;
    }
    fclose(fp);
}

void ejecutar_instruccion(Procesador *p) {
    int opcode = p->memoriaPrograma[p->PC].opcode;
    int operando1 = p->memoriaPrograma[p->PC].operando1;
    int operando2 = p->memoriaPrograma[p->PC].operando2;
    switch (opcode) {
        case 1: // ADD
            p->A = operando1 + operando2;
            p->ZeroFlag = (p->A == 0);
            p->NegativeFlag = (p->A < 0);
            break;
        case 2: // SUB
            p->A = operando1 - operando2;
            p->ZeroFlag = (p->A == 0);
            p->NegativeFlag = (p->A < 0);
            break;
        case 3: // LOAD
            p->A = p->memoriaDatos[operando1];
            break;
        case 4: // STORE
            p->memoriaDatos[operando1] = p->A;
            break;
        // Agrega más instrucciones según sea necesario
    }
    p->PC++;
}

void imprimir_estado(Procesador *p) {
    printf("Registro A: %d\n", p->A);
    printf("Registro B: %d\n", p->B);
    printf("Zero Flag: %d\n", p->ZeroFlag);
    printf("Negative Flag: %d\n", p->NegativeFlag);
    printf("PC: %d\n", p->PC);
    printf("Memoria Datos:\n");
    for (int i = 0; i < TAM_MEMORIA; i++) {
        printf("%d ", p->memoriaDatos[i]);
    }
    printf("\n");
}