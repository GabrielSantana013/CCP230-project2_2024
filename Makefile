#Nome do Executável
TARGET = livraria.exe

#Compilador
CC = gcc

#Flags de compilação
CFLAGS = -Wall

#Lista de Arquivos Fonte
C_Source = $(wildcard ./source/*.c)
H_Source = $(wildcard ./source/*.h)

#Variavel para limpeza
RM = rm -f
BINS = ./*.bin

#Regra Para Compilar o Programa

$(TARGET):$(C_Source) $(H_Source)
	$(CC) $(CFLAGS) -o $(TARGET) $(C_Source)

#Regra para limpeza
clean:
	$(RM) $(TARGET) $(BINS)

.PHONY: all clean
