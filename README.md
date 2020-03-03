# Read Files - libconfig++

Programa utilizando biblioteca libconfig++ para leitura de arquigos config (.cfg) com parâmetros de câmeras

## Para instalar biblioteca:
```bash
sudo apt-get install libconfig++8-dev
```
alterar caminho para leitura do arquivo em read_cameras_configure.cpp

## Executável
```c++
    [...]
        cfg.readFile("/home/$USER/DIR/cameras.cfg");
   [...]
```

Para adicionar em um repositório existente, deve-se adicionar o pacote ao CMakeText.txt

## CMakeText

```cmake
 find_library(libconfig libconfig++) # Busca biblioteca

add_executable(read_cfg function.cpp) # Arquivo executável que utiliza a biblioteca
target_link_libraries(set_cameras -lconfig++ -lconfig) # Referencia para o executável encontrar a biblioteca
```