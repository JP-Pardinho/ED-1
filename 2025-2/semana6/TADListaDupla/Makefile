# ==========================================================
# Makefile - TADListaDupla
# =========================================================

# 1️⃣ Variáveis (para facilitar manutenção)
CFLAGS=-O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow 
CLIBS=-lm
EXECUTAVEL=TADListaDupla.exe # nome do executável final

# ==========================================================
# 2️⃣ Alvo principal (primeiro alvo → padrão ao rodar "make")
# ==========================================================

$(EXECUTAVEL): main.o ListaDupla.o
	@echo "🔧 Ligando objetos e gerando executável..."
	@gcc main.o ListaDupla.o $(CLIBS) -o $(EXECUTAVEL)
	@echo "✅ Compilação concluída."
	@echo "🚀 Para executar o programa digite ./$(EXECUTAVEL) no terminal."


# ==========================================================
# 3️⃣ Regras para gerar os arquivos objeto
# ==========================================================

main.o: main.c
	@echo "🧩 Compilando main.c"
	@gcc -c $(CFLAGS) main.c

ListaDupla.o: ListaDupla.c
	@echo "🧩 Compilando ListaDupla.c"
	@gcc -c $(CFLAGS) ListaDupla.c


# ==========================================================
# 4️⃣ Alvos auxiliares (não geram arquivos → PHONY)
# ==========================================================

.PHONY: clean run memcheck

# Executa o programa (compila antes se necessário)
run: $(EXECUTAVEL)
	@echo "🚀 Executando o programa:"
	./$(EXECUTAVEL)

# Executa o programa com o valgrind (compila antes se necessário)
memcheck: $(EXECUTAVEL)
	@echo "👾 Verificando vazamento de memória com o valgrind:"
	valgrind --tool=memcheck --leak-check=full ./$(EXECUTAVEL)

# Limpa os arquivos temporários
clean: 
	@echo "🧹 Limpando arquivos compilados..."
	@rm -rf *.o $(EXECUTAVEL)
	@echo "🧼 Diretório limpo!"
	
