typedef struct viagem Viagem;
//obrigatórias
Viagem *nova_v(int dia, int mes, int ano, char *cidade, char *pais, int perido);
void libera_v(Viagem *viagem);
void acessa_v(Viagem *viagem, int *id, int *dia, int *mes, int *ano, char *cidade, char *pais, int perido);
void atribui_v(Viagem *viagem, int *dia, int *mes, int *ano, char *cidade, char *pais, int perido);
void atribui_direita_v(Viagem *viagem, Viagem *direita);
Viagem *acessa_direita_v(Viagem *viagem);
void atribui_esquerda(Viagem *viagem, Viagem *esquerda);
Viagem *acessa_esquerda_v(Viagem *viagem);
int tamanho_v();
//outras
int verificar_data(int dia, int mes, int ano);
int verificar_destino(char *cidade, char *pais);
acessa_v_data(Viagem *viagem, int *dia, int *mes, int *ano, int periodo);
Viagem *acessa_raiz_v(Viagem *viagem);
Viagem *acessa_pai_v(Viagem *viagem);
void atribui_raiz(Viagem *viagem, Viagem *raiz);
//void transplantar(Viagem *viagem, Viagem *filho);
