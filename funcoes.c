#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "funcoes.h"

// LIMPA BUFFER
void limpa_buffer(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF); 
}


//VALIDACOES
int validar_opcao(int limite_inferior, int limite_superior) {
    int opcao;

    while (1) {
        printf("-> Escolha sua opção: ");
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada inválida! Por favor, insira um número.\n");
            while (getchar() != '\n'); 
        } else if (opcao < limite_inferior || opcao > limite_superior) {
            printf("Opção fora do intervalo permitido (%d - %d). Tente novamente.\n", limite_inferior, limite_superior);
        } else {
            break;
        }
    }
    return opcao;
}


// Verifica se o nome tem até 50 caracteres e é alfabético
int validar_nome(const char *nome) {
    if (strlen(nome) == 0 || strlen(nome) > 50) return 0;
    for (int i = 0; i < strlen(nome); i++) {
        if (!isalpha(nome[i]) && nome[i] != ' ') return 0;
    }
    return 1;
}

// Validação de CPF feito pelo cahtgpt
int validar_cpf(const char *cpf) {
    if (strlen(cpf) != 11 || strspn(cpf, "0123456789") != 11) return 0;

    if (strcmp(cpf, "00000000000") == 0 || strcmp(cpf, "11111111111") == 0 ||
        strcmp(cpf, "22222222222") == 0 || strcmp(cpf, "33333333333") == 0 ||
        strcmp(cpf, "44444444444") == 0 || strcmp(cpf, "55555555555") == 0 ||
        strcmp(cpf, "66666666666") == 0 || strcmp(cpf, "77777777777") == 0 ||
        strcmp(cpf, "88888888888") == 0 || strcmp(cpf, "99999999999") == 0) {
        return 0;
    }

    int digito1 = 0, digito2 = 0;

    for (int i = 0; i < 9; i++) {
        digito1 += (cpf[i] - '0') * (10 - i);
    }
    digito1 = (digito1 * 10) % 11;
    if (digito1 >= 10) digito1 = 0;

    for (int i = 0; i < 10; i++) {
        digito2 += (cpf[i] - '0') * (11 - i);
    }
    digito2 = (digito2 * 10) % 11;
    if (digito2 >= 10) digito2 = 0;

    return digito1 == (cpf[9] - '0') && digito2 == (cpf[10] - '0');
}

// Validação de Data feito pelo cahtgpt
int validar_data(const char *data) {
    if (strlen(data) != 8 || strspn(data, "0123456789") != 8) return 0;

    int dia = (data[0] - '0') * 10 + (data[1] - '0');
    int mes = (data[2] - '0') * 10 + (data[3] - '0');
    int ano = (data[4] - '0') * 1000 + (data[5] - '0') * 100 + (data[6] - '0') * 10 + (data[7] - '0');

    int dias_mes[] = {31, (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0)) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return mes >= 1 && mes <= 12 && dia >= 1 && dia <= dias_mes[mes - 1];
}

// Verifica se o telefone tem 11 dígitos e apenas números
int validar_telefone(const char *telefone) {
    if (strlen(telefone) != 11) return 0;
    for (int i = 0; i < 11; i++) {
        if (!isdigit(telefone[i])) return 0;
    }
    return 1;
}

// Verifica se o e-mail é válido (simplificado)
int validar_email(const char *email) {
    int len = strlen(email);
    if (len == 0 || len > 25) return 0;
    int has_at = 0;
    for (int i = 0; i < len; i++) {
        if (email[i] == '@') has_at = 1;
    }
    return has_at;
}
