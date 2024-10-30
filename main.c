#include "procesador.h"
#include <stdio.h>

int main() {
    Procesador p;
    inicializar_procesador(&p);
    cargar_programa(&p, "programa.txt");
    while (p.PC < MAX_INSTRUCCIONES && p.memoriaPrograma[p.PC].opcode != -1) {
        ejecutar_instruccion(&p);
        imprimir_estado(&p);
    }
    return 0;
}
