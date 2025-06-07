#include "pocketpy/pocketpy.h"
#include "levenshtein.h"
#include "hamming.h"
#include <stdio.h>
#include <stdlib.h>



bool py_levenshtein(int argc, py_Ref argv){
    PY_CHECK_ARGC(2);

    PY_CHECK_ARG_TYPE(0, tp_str);
    PY_CHECK_ARG_TYPE(1, tp_str);

    const char* string1 = py_tostr(py_arg(0));
    const char* string2 = py_tostr(py_arg(1));

    unsigned int resultado = levenshtein(string1, string2);
    
    py_newint(py_retval(), resultado);

    return true;
}

bool py_hamming(int argc, py_Ref argv){
    PY_CHECK_ARGC(2);

    PY_CHECK_ARG_TYPE(0, tp_str);
    PY_CHECK_ARG_TYPE(1, tp_str);

    const char* string1 = py_tostr(py_arg(0));
    const char* string2 = py_tostr(py_arg(1));

    unsigned int resultado = hamming(string1, string2);
    
    py_newint(py_retval(), resultado);

    return true;
}


char* read_file(const char* filename){

    FILE* arquivo = fopen("script.py", "r");
    if(arquivo == NULL){
        perror("Erro na abertura do arquivo!!");
        return NULL;
    }
    fseek(arquivo, 0, SEEK_END);
    long tamanho = ftell(arquivo);
    fseek(arquivo, 0, SEEK_SET);


    char* buffer = malloc(tamanho + 1);

    if (!buffer) {
        perror("Erro de alocação");
        fclose(arquivo);
        return NULL;
    }
    
    fread(buffer, 1, tamanho, arquivo);
    buffer[tamanho] = '\0';
    fclose(arquivo);

    return buffer;

}


int main(){
    py_initialize();

    py_GlobalRef modulo_main = py_getmodule("__main__");

    py_bindfunc(modulo_main, "levenshtein_em_python", py_levenshtein);
    py_bindfunc(modulo_main, "hamming_em_python", py_hamming);

    char* script = read_file("script.py");
    

    if(!py_exec(script, "print_levenshtein", EXEC_MODE, NULL)){
        printf("Erro de execução");
    }

    py_finalize();

    free(script);
    return 0;

}