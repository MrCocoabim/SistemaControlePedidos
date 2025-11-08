# ====================================================================
# Makefile - Sistema de Controle de Pedidos (SCP)
# Compilação automática para Linux ou Windows (MinGW)
# Linguagem: C
# ====================================================================

# === Detecta o sistema operacional ===
ifeq ($(OS),Windows_NT)
	PLATFORM = Windows
	EXT = .exe
	LIBS = -lpdcurses
	RM = del /Q
	MKDIR = if not exist "$(BUILD_DIR)" mkdir "$(BUILD_DIR)"
	SEP = \\
else
	PLATFORM = Linux
	EXT =
	LIBS = -lncurses
	RM = rm -rf
	MKDIR = mkdir -p
	SEP = /
endif

# === Diretórios ===
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build

# === Compilador e opções ===
CC = gcc
CFLAGS = -Wall -Wextra -I$(INC_DIR)

# === Arquivos fonte e objeto ===
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC_FILES))
EXEC = $(BUILD_DIR)$(SEP)scp$(EXT)

# ====================================================================
# REGRAS PRINCIPAIS
# ====================================================================

# Regra padrão - compila tudo
all: info dirs $(EXEC)
	@echo "Compilação concluída com sucesso para $(PLATFORM) !"

# Mostra informações iniciais
info:
	@echo "=================================================="
	@echo "Compilando Sistema de Controle de Pedidos"
	@echo "Plataforma detectada: $(PLATFORM)"
	@echo "Compilador: $(CC)"
	@echo "=================================================="

# Cria diretório de build se não existir
dirs:
	@$(MKDIR) $(BUILD_DIR)

# Compila cada arquivo .c para .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Gera o executável final
$(EXEC): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $(EXEC) $(LIBS)

# Remove arquivos compilados
clean:
	@$(RM) $(BUILD_DIR)
	@echo "Limpeza concluída."

# Compila e executa o programa (COM A CORREÇÃO)
run: all
	@echo "Executando o Sistema de Controle de Pedidos..."
	@if [ "$(PLATFORM)" = "Windows" ]; then \
		$(EXEC); \
	else \
		./$(EXEC); \
	fi

# Mostra ajuda
help:
	@echo "=================================================="
	@echo "Comandos disponíveis:"
	@echo "  make          -> compila o projeto"
	@echo "  make run      -> compila e executa"
	@echo "  make clean    -> remove arquivos compilados"
	@echo "  make help     -> mostra esta ajuda"
	@echo "=================================================="

.PHONY: all clean run help dirs info
