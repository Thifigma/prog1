struct data {
	int dia;
	int mes;
	int ano;
};

/*sabor = M ou C e tem o ultimo /0 */
struct bolo {
	struct data validade;
	char sabor[2];
};

struct torta {
	struct data validade;
};

struct frigobar {
	struct bolo *Pcima[20];
	struct torta *Pbaixo[10];
};

/*Deve criar um frigobar vazio. Recebe como parametro
 * o endereco de uma struct frigobar */
struct frigobar *criaFrigobar ();

/*Faz a leitura de quantidade de pedidos (tortas/bolos)
 *e aloca a quantidade solicitada*/
void pedido (struct frigobar *fb);

/*Faz a leitura dos pedidos alocados no pedido*/
void lePedido (struct frigobar *fb, int nBolo, int nTorta);

/*Lista a quantidade maxima de cada pratileira*/
void ListaQuantidade (struct frigobar *fb);

/*Destroi o produto que passou da sua data de validade
 * Sera usado dentro do laco*/
struct frigobar DestroiVencidos (struct frigobar *fb);

/*Destroi Frigobar*/
void destroiFrigobar (struct frigobar *fb);









//testes